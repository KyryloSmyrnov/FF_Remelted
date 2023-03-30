﻿/*
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

#include <Game/Game.h>

Game::Game()
{
	this->InitGraphicsSettings();
	this->InitWindow();
}

void Game::Run()
{
	while (this->window->isOpen())
	{
		this->Update();
		this->Render();
	}
}

void Game::InitGraphicsSettings()
{
	this->graphicsSettings.LoadFromFile("Config/graphics.ini");
}

void Game::InitWindow()
{
	if (this->graphicsSettings.fullscreen)
		this->window = new sf::RenderWindow(
			this->graphicsSettings.resolution,
			this->graphicsSettings.title,
			sf::Style::Fullscreen,
			this->graphicsSettings.contextSettings);
	else
		this->window = new sf::RenderWindow(
			this->graphicsSettings.resolution,
			this->graphicsSettings.title,
			sf::Style::Titlebar | sf::Style::Close,
			this->graphicsSettings.contextSettings);
}

void Game::UpdateEvents()
{
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::Update()
{
	this->UpdateEvents();
}

void Game::Render()
{
	this->window->clear();
	this->window->display();
}