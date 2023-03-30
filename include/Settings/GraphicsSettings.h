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

#include <string>
#include <vector>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/VideoMode.hpp>

class GraphicsSettings
{
public:
	GraphicsSettings();
	~GraphicsSettings() { };

	void LoadFromFile(const std::string filePath);
	void SaveToFile(const std::string filePath);

	std::string title;
	sf::VideoMode resolution;
	sf::ContextSettings contextSettings;
	std::vector<sf::VideoMode> videoModes;

	bool fullscreen;
	bool vSync;
	unsigned int frameRateLimit;
};
