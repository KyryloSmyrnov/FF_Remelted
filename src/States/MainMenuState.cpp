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

#include "States/MainMenuState.h"

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

void MainMenuState::UpdateInput(const float& dt) {}

void MainMenuState::UpdateButtons()
{
	for (auto& it : this->buttons)
		it.second->Update(static_cast<sf::Vector2i>(this->viewMousePosition));
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

	this->buttons["TESTBUTTON1"] = new Button(
		100, window->getSize().y * 0.6, 350, 100,
		&font, "Test Button 1", 32,
		sf::Color(208, 208, 208, 255), sf::Color(255, 255, 255, 255),
		sf::Color(29, 44, 104, 255), sf::Color(87, 110, 199, 255));

	this->buttons["TESTBUTTON2"] = new Button(
		100, window->getSize().y * 0.7, 350, 100,
		&font, "Test Button 2", 32,
		sf::Color(208, 208, 208, 255), sf::Color(255, 255, 255, 255),
		sf::Color(29, 44, 104, 255), sf::Color(87, 110, 199, 255));

	this->buttons["TESTBUTTON3"] = new Button(
		100, window->getSize().y * 0.8, 350, 100,
		&font, "Test Button 3", 32,
		sf::Color(208, 208, 208, 255), sf::Color(255, 255, 255, 255),
		sf::Color(29, 44, 104, 255), sf::Color(87, 110, 199, 255));
}
