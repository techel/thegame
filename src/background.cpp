#include "background.hpp"

#include "app.hpp"
#include "texmanager.hpp"

static constexpr float ViewSize = 10.0f;
static constexpr unsigned int ViewExtent = 5;

Background::Background(App &app)
{
    Shape.setTexture(&app.textures().get("background"));
 
    View.setSize({ ViewSize, ViewSize });
    View.setCenter({ ViewSize / 2.0f, ViewSize / 2.0f });
    Shape.setSize({ ViewSize, ViewSize * ViewExtent });

    setScroll(0.0f);
}

void Background::render(sf::RenderTarget &target) const
{
    auto view = View;
    view.setViewport(target.getView().getViewport());
    target.setView(view);

    target.draw(Shape);
}

void Background::setScroll(float amount)
{
    if(amount < 0.0f)
        amount = 0.0f;
    else if(amount > 1.0f)
        amount = 1.0f;

    auto viewpos = View.getCenter();
    auto y = ViewSize / 2.0f + (Shape.getSize().y - ViewSize) * (1.0f - amount);
    View.setCenter({ viewpos.x, y });
}
