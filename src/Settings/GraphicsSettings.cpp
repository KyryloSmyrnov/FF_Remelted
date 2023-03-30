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

#include <fstream>
#include <Settings/GraphicsSettings.h>

GraphicsSettings::GraphicsSettings()
{
	this->title = "FF_Remelted";
	this->resolution = sf::VideoMode::getDesktopMode();
	this->contextSettings.antialiasingLevel = 0;
	this->videoModes = sf::VideoMode::getFullscreenModes();
	this->fullscreen = true;
	this->vSync = false;
	this->frameRateLimit = 360;
}

void GraphicsSettings::SaveToFile(const std::string filePath)
{
	std::ofstream outfile(filePath);

	if (outfile.is_open())
	{
		outfile << this->title << "\n";
		outfile << this->resolution.width << " " << this->resolution.height << "\n";
		outfile << this->contextSettings.antialiasingLevel << "\n";
		outfile << this->fullscreen << "\n";
		outfile << this->frameRateLimit << "\n";
	}

	outfile.close();
}

void GraphicsSettings::LoadFromFile(const std::string filePath)
{
	std::ifstream infile(filePath);

	if (infile.is_open())
	{
		std::getline(infile, this->title);
		infile >> this->resolution.width >> this->resolution.height;
		infile >> this->contextSettings.antialiasingLevel;
		infile >> this->fullscreen;
		infile >> this->frameRateLimit;
	}

	infile.close();
}
