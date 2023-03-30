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

#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>

enum buttonState
{
	BUTTONIDLE = 0,
	BUTTONHOVER = 1,
	BUTTONCLICKED = 2
};

class Button
{
public:
	Button() { }
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, unsigned int characterSize,
		sf::Color textIdleColor, sf::Color textHoverColor,
		sf::Color idleColor, sf::Color hoverColor);
	~Button();

	void Update(const sf::Vector2i& mousePosition);
	void Render(sf::RenderTarget& target);

	const bool IsPressed() const;

	void CenterText();

	const std::string GetStringText() const;
	const int GetId() const;

	void SetText(std::string string);
	void SetId(int id);

private:
	buttonState currentState;

	sf::RectangleShape buttonShape;

	sf::Sprite buttonIcon;
	sf::Sprite buttonBackgroud;

	sf::Font* font;
	sf::Text text;

	sf::Color textIdleColor;
	sf::Color textHoverColor;

	sf::Color idleColor;
	sf::Color hoverColor;

	unsigned short int buttonId;

	bool isClicked = false;
};