/*
*******************************************************************
 *	______ ______                               _  _             _ 
 *	|  ___||  ___|                             | || |           | |
 *	| |_   | |_     _ __  ___  _ __ ___    ___ | || |_  ___   __| |
 *	|  _|  |  _|   | '__|/ _ \| '_ ` _ \  / _ \| || __|/ _ \ / _` |
 *	| |    | |     | |  |  __/| | | | | ||  __/| || |_|  __/| (_| |
 *	\_|    \_|     |_|   \___||_| |_| |_| \___||_| \__|\___| \__,_|
 *															   
*******************************************************************
 */

#pragma once

#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Settings/GraphicsSettings.h"
#include "States/BaseState.h"
#include "States/MainMenuState.h"

class Game
{
public:
	Game();
	~Game() { };

	void Run();

private:
	void InitGraphicsSettings();
	void InitVariables();
	void InitStateData();
	void InitStates();
	void InitWindow();
	void InitButtons();

	void UpdateEvents();
	void UpdateDeltaTime();

	void Update();
	void Render();

	StateData stateData;
	std::stack<BaseState*> states;
	std::map<std::string, int>* availableKeys;
	GraphicsSettings graphicsSettings;
	sf::RenderWindow* window;

	float dt;
	sf::Clock dtClock;

	float gridSize;
};
