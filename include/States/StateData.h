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

#include <map>
#include <stack>
#include <SFML/Graphics/RenderWindow.hpp>
#include "BaseState.h"
#include "Settings/GraphicsSettings.h"

class BaseState;

struct StateData
{
	StateData() { };

	float gridSize;
	sf::RenderWindow* window;
	GraphicsSettings* graphicsSettings;
	std::map<std::string, int>* availableKeys;
	std::stack<BaseState*>* states;
};
