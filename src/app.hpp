#pragma once

#include <memory>

class Ticker;
class GameWindow;
class TexManager;
class SoundManager;
class StateManager;

class App
{
public:
	App();
	~App();

	auto &ticker() { return *MyTicker; }
	auto &window() { return *MyWindow; }
	auto &textures() { return *MyTexManager; }
	auto &sound() { return *MySoundManager; }
	auto &states() { return *MyStateManager; }

private:
	std::unique_ptr<Ticker> MyTicker;
	std::unique_ptr<GameWindow> MyWindow;
	std::unique_ptr<TexManager> MyTexManager;
	std::unique_ptr<SoundManager> MySoundManager;
	std::unique_ptr<StateManager> MyStateManager;
};