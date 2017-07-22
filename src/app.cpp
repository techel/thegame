#include "app.hpp"

#include "ticker.hpp"
#include "gamewindow.hpp"
#include "texmanager.hpp"
#include "soundmanager.hpp"
#include "states.hpp"

#include "playstate.hpp"

#include <sfml/Graphics.hpp>

App::App()
{
	MyTicker = std::make_unique<Ticker>();
	MyWindow = std::make_unique<GameWindow>();
	MyTexManager = std::make_unique<TexManager>();
	MySoundManager = std::make_unique<SoundManager>();
	MyStateManager = std::make_unique<StateManager>();

	MyStateManager->setNextState<PlayState>(*this);

	while(MyWindow->tick())
	{
		MyTicker->tick([this](float time)
		{
			MyStateManager->tick(time, MyWindow->target());
		});
	}
}

App::~App()
{
}
