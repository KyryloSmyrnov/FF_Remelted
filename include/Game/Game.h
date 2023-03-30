/*
*******************************************************************
 *	______ ______                               _  _             _ 
 *	|  ___||  ___|                             | || |           | |
 *	| |_   | |_     _ __  ___  _ __ ___    ___ | || |_  ___   __| |
 *	|  _|  |  _|   | '__|/ _ \| '_ ` _ \  / _ \| || __|/ _ \ / _` |
 *	| |    | |     | |  |  __/| | | | | ||  __/| || |_|  __/| (_| |
 *	\_|    \_|     |_|   \___||_| |_| |_| \___||_| \__|\___| \__,_|
 *															   
 * Copyright (C) 2023 Kyrylo Smyrnov
 * 
 * @KyryloSmyrnov
*******************************************************************
 */

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "Settings/GraphicsSettings.h"

class Game
{
public:
	Game();
	~Game() { };

	void Run();

private:
	void InitGraphicsSettings();
	void InitWindow();
	void InitButtons();

	void UpdateEvents();

	void Update();
	void Render();

	GraphicsSettings graphicsSettings;
	sf::RenderWindow* window;
};
