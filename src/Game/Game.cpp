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

#include "Game/Game.h"

Game::Game()
{
	this->InitVariables();
	this->InitGraphicsSettings();
	this->InitWindow();
	this->InitStateData();
	this->InitStates();
}

void Game::Run()
{
	while (this->window->isOpen())
	{
		this->UpdateDeltaTime();
		this->Update();
		this->Render();
	}
}

void Game::InitGraphicsSettings()
{
	this->graphicsSettings.LoadFromFile("Config/graphics.ini");
}

void Game::InitVariables()
{
	this->dt = 0.0f;
	this->window = NULL;
	this->gridSize = 32.0f;
}

void Game::InitStateData()
{
	this->stateData.window = this->window;
	this->stateData.graphicsSettings = &this->graphicsSettings;
	this->stateData.availableKeys = this->availableKeys;
	this->stateData.states = &this->states;
	this->stateData.gridSize = this->gridSize;
}

void Game::InitStates()
{
	this->states.push(new MainMenuState(&this->stateData));
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

void Game::UpdateDeltaTime()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::Update()
{
	this->UpdateEvents();

	if (!this->states.empty())
		this->states.top()->Update(this->dt);
}

void Game::Render()
{
	this->window->clear();

	if (!this->states.empty())
	{
		this->states.top()->Render();
	}

	this->window->display();
}
