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

MainMenuState::MainMenuState(StateData* stateData) : BaseState(stateData)
{
	this->InitFont();
	this->InitGUI();
}

MainMenuState::~MainMenuState()
{
	for(auto it = this->buttons.begin(); it != buttons.end(); ++it)
		delete it->second;
}

void MainMenuState::UpdateInput(const float& dt) {}

void MainMenuState::UpdateButtons()
{
	for(auto &it : this->buttons)
		it.second->Update(static_cast<sf::Vector2i>(this->viewMousePosition));
}

void MainMenuState::Update(const float& dt)
{
	this->UpdateMousePositions();
	this->UpdateButtons();
}

void MainMenuState::RenderButtons(sf::RenderTarget& target)
{
	for(auto &it : this->buttons)
		it.second->Render(target);
}

void MainMenuState::Render(sf::RenderTarget* target)
{
	if(!target) target = this->window;

	target->draw(this->background);
	this->RenderButtons(*target);
}

void MainMenuState::InitFont()
{
	if(!this->font.loadFromFile("Resources/Fonts/OPTIMA.TTF"))
		throw("[ERROR] MAINMENUSTATE: UNABLE TO LOAD FONT (Resources/Fonts/OPTIMA.TTF)");
}

void MainMenuState::ResetGUI()
{
	for(auto it = this->buttons.begin(); it != buttons.end(); ++it)
		delete it->second;

	InitGUI();
}

void MainMenuState::InitGUI()
{
	const sf::VideoMode& videoMode = this->stateData->graphicsSettings->resolution;

	this->background.setSize(sf::Vector2f(
		static_cast<float>(videoMode.width),
		static_cast<float>(videoMode.height)));

	if(!this->backgroundTexture.loadFromFile("Resources/Images/MainMenu/MainMenuBackground.png"))
		throw("[ERROR] MAINMENUSTATE: UNABLE TO LOAD IMAGE (Resources/Images/MainMenu/MainMenuBackground.png)");

	this->background.setTexture(&this->backgroundTexture);
	
	this->buttons["NEWGAMESTATE"] = new Button(
		100, 1500, 350, 50,
		&font, "New Game", 20,
		sf::Color(208, 208, 208, 255), sf::Color(255, 255, 255, 255),
		sf::Color(29,44,104,255), sf::Color(87, 110, 199, 255));

	
}
