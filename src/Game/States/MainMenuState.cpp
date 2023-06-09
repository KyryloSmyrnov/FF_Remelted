﻿/*
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

#include "Game/States/MainMenuState.h"

MainMenuState::MainMenuState(StateData* stateData)
	: BaseState(stateData)
{
	this->InitFont();
	this->InitGUI();
}

MainMenuState::~MainMenuState()
{
	for (auto it = this->buttons.begin(); it != buttons.end(); ++it)
		delete it->second;
}

void MainMenuState::UpdateButtons()
{
	for (auto& it : this->buttons)
		it.second->Update(static_cast<sf::Vector2i>(this->viewMousePosition));

	//if(this->buttons["NEWGAME"]->IsPressed())
		
	if(this->buttons["EXIT"]->IsPressed())
		this->window->close();
}

void MainMenuState::UpdateParticles(const float dt)
{
	float radius = 30.0f;
	static float angle = 0.0f;

	angle -= dt * 20.0f;
	if (angle > 360.0f)
		angle += 360.0f;

	float x = radius * std::cos(angle * 3.14f / 180.0f);
	float y = radius * std::sin(angle * 3.14f / 180.0f);

	backgroundParticles.setPosition(x, y);
}

void MainMenuState::Update(const float& dt)
{
	this->UpdateMousePositions();
	this->UpdateParticles(dt);
	this->UpdateButtons();
}

void MainMenuState::RenderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
		it.second->Render(target);
}

void MainMenuState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	target->draw(this->backgroundParticles);

	this->RenderButtons(*target);
}

void MainMenuState::InitFont()
{
	if (!this->font.loadFromFile("Resources/Fonts/optima.ttf"))
		throw("[ERROR] MAINMENUSTATE: UNABLE TO LOAD FONT (Resources/Fonts/optima.ttf)");
}

void MainMenuState::ResetGUI()
{
	for (auto it = this->buttons.begin(); it != buttons.end(); ++it)
		delete it->second;

	InitGUI();
}

void MainMenuState::InitGUI()
{
	const sf::VideoMode& videoMode = this->stateData->graphicsSettings->resolution;

	this->background.setSize(sf::Vector2f(
		static_cast<float>(videoMode.width),
		static_cast<float>(videoMode.height)));

	this->backgroundParticles.setSize(sf::Vector2f(
		static_cast<float>(videoMode.width),
		static_cast<float>(videoMode.height)));

	if (!this->backgroundTexture.loadFromFile("Resources/Images/MainMenu/Background.png"))
		throw("[ERROR] MAINMENUSTATE: UNABLE TO LOAD IMAGE (Resources/Images/MainMenu/Background.png)");

	if (!this->backgroundParticlesTexture.loadFromFile("Resources/Images/MainMenu/BackgroundParticles.png"))
		throw("[ERROR] MAINMENUSTATE: UNABLE TO LOAD IMAGE (Resources/Images/MainMenu/BackgroundParticles.png)");

	this->background.setTexture(&this->backgroundTexture);

	this->backgroundParticles.setTexture(&this->backgroundParticlesTexture);
	
	this->buttons["NEWGAME"] = new Button(
		AdaptPositionToResolution(5.0f, 65.0f).x, AdaptPositionToResolution(5.0f, 65.0f).y,
		AdaptButtonSizeToResolution().x, AdaptButtonSizeToResolution().y,
		&font, "New Game", AdaptFontSize(),
		sf::Color(160, 160, 160), sf::Color::White,
		"Resources/Images/MainMenu/Button.png", "Resources/Images/MainMenu/ButtonH.png");
	
	this->buttons["EXIT"] = new Button(
		AdaptPositionToResolution(5.0f, 70.0f).x, AdaptPositionToResolution(5.0f, 70.0f).y,
		AdaptButtonSizeToResolution().x, AdaptButtonSizeToResolution().y,
		&font, "Exit", AdaptFontSize(),
		sf::Color(160, 160, 160), sf::Color::White,
		"Resources/Images/MainMenu/Button.png", "Resources/Images/MainMenu/ButtonH.png");
}