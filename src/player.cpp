#include "player.hpp"

#include <cmath>

#include "app.hpp"
#include "map.hpp"
#include "texmanager.hpp"
#include "mine.hpp"
#include "soundmanager.hpp"

static const float PlayerSize = 3.5f;
static const float SensorsSize = 0.7f;
static constexpr float JumpVelocity0 = -90.5;
static constexpr float MaxWalkVelocity = 37.0f;
static constexpr float AccelGround = 100.0f;
static constexpr float AccelAir = 17.0f;
static constexpr float DeaccelAir = 1.0f;
static constexpr float Pi = 3.141592f;

Player::Player(Map &map, App &app) : MyMap(&map), MyApp(&app)
{
	Sprite.setTexture(&app.textures().get("player"));
	Sprite.setSize({ PlayerSize, PlayerSize });

	Box::Predefinitions def;
	def.MainFix.filter.categoryBits = Filter::Player;
	def.MainFix.filter.maskBits = Filter::All;
	def.MainFix.friction = 1.0f;
	def.MainFix.density = 1.0f;
	def.LeftSensor = def.RightSensor = def.TopSensor = def.BottomSensor = def.MainFix;

	b2CircleShape circle;
	circle.m_p = { PlayerSize / 2, PlayerSize / 2 };
	circle.m_radius = PlayerSize / 2;
	def.MainFix.shape = &circle;

	def.Body.fixedRotation = true;
	def.Body.type = b2_dynamicBody;
	def.Body.userData = static_cast<IEntity*>(this);

	Body = std::make_unique<Box>(map.physics(), sf::Vector2f(PlayerSize, PlayerSize), SensorsSize, def);
}

sf::Vector2f Player::getPosition() const
{
	auto pos = Body->body().GetPosition();
	return{ pos.x, pos.y };
}

void Player::setPosition(const sf::Vector2f &pos)
{
	Body->body().SetTransform({ pos.x, pos.y }, 0.0f);
}

void Player::takeDamage(unsigned int lives)
{
	if(lives > Lives)
		Lives = 0;
	else
		Lives -= lives;
}

void Player::tick(float seconds)
{
	bool wallLeft = Body->getNumTouches(Box::Direction::Left) > 0;
	bool wallRight = Body->getNumTouches(Box::Direction::Right) > 0;
	bool ground = Body->getNumTouches(Box::Direction::Bottom) > 0;

	if((DestWalkVelocity < 0.0f && !wallLeft) || (DestWalkVelocity > 0.0f && !wallRight) || DestWalkVelocity == 0.0f)
	{
		auto currvel = Body->body().GetLinearVelocity();
		auto newvelx = currvel.x + (DestWalkVelocity - currvel.x) * (ground ? AccelGround : (DestWalkVelocity == 0.0f ? DeaccelAir : AccelAir)) * seconds;

		Body->body().SetLinearVelocity({ newvelx, currvel.y });
	}

	//make the player slightly move up and down while moving
	if(Walking)
	{
		WalkAnimation += Pi * seconds * 5.0f;
		if(WalkAnimation >= Pi)
			WalkAnimation -= Pi;
	}

	MineCooldown -= seconds;

	auto pos = Body->body().GetPosition();
	Sprite.setPosition({ pos.x, pos.y + std::sin(WalkAnimation) * 0.5f });
}

void Player::render(sf::RenderTarget &target) const
{
	target.draw(Sprite);
}

void Player::walk(Walk dir)
{
	if(dir == Walk::None)
	{
		DestWalkVelocity = 0.0f;
		Walking = false;
	}
	else
	{
		DestWalkVelocity = dir == Walk::Left ? -MaxWalkVelocity : MaxWalkVelocity;

		auto oldface = FaceDirection;
		FaceDirection = dir == Walk::Left ? Face::Left : Face::Right;

		if(oldface != FaceDirection) //flip player texture if face direction changed
		{
			auto texrect = Sprite.getTextureRect();
			Sprite.setTextureRect(sf::IntRect(texrect.left == 0 ? texrect.width : 0, 0, -texrect.width, texrect.height));
		}

		Walking = true;
	}
}

void Player::jump()
{
	if(Body->getNumTouches(Box::Direction::Bottom) > 0)
	{
		Body->body().ApplyLinearImpulse({ 0.0f, JumpVelocity0 * Body->body().GetMass() }, { PlayerSize / 2, PlayerSize / 2 }, true);
		MyApp->sound().playSound("jump");
	}
}

void Player::action()
{
	if(MineCooldown <= 0.0f)
	{
		auto &mine = MyMap->addEntity<Mine>(*MyMap, *MyApp);
		mine.setPosition(getPosition() + sf::Vector2f(PlayerSize / 2, 0.0f));

		if(FaceDirection == Face::Left)
			mine.toss({ -1.0f, -1.0f });
		else
			mine.toss({ 1.0f, -1.0f });

		MineCooldown = 1.0f;

		MyApp->sound().playSound("toss");
	}
}

sf::Vector2f Player::getSize() const
{
	return { PlayerSize, PlayerSize };
}
