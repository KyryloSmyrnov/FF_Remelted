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
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "GUI/Button.h"
#include "States/BaseState.h"
#include "States/StateData.h"

class MainMenuState : public BaseState
{
public:
	MainMenuState(StateData* stateData);
	virtual ~MainMenuState();

	void UpdateInput(const float& dt) override;
	void UpdateButtons();
	void UpdateParticles(const float dt);
	void Update(const float& dt) override;

	void RenderButtons(sf::RenderTarget& target);
	void Render(sf::RenderTarget* target = nullptr) override;

private:
	sf::Texture backgroundTexture;
	sf::Texture backgroundParticlesTexture;
	sf::RectangleShape background;
	sf::RectangleShape backgroundParticles;
	sf::Font font;

	sf::RectangleShape buttonBackground;
	std::map<std::string, Button*> buttons;

	void InitVariables();
	void InitKeyBinds() override { };
	void InitFont();
	void ResetGUI();
	void InitGUI();
};
