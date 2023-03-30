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

#include <GUI/Button.h>

Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, unsigned int characterSize,
	sf::Color textIdleColor, sf::Color textHoverColor,
	sf::Color idleColor, sf::Color hoverColor)
{
	this->currentState = BUTTONIDLE;

	this->buttonShape.setPosition(sf::Vector2f(x, y));
	this->buttonShape.setSize(sf::Vector2f(width, height));

	this->buttonIcon = buttonIcon;
	this->buttonBackgroud = buttonBackgroud;

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(textIdleColor);
	this->text.setCharacterSize(characterSize);

	CenterText();

	this->textIdleColor = textIdleColor;
	this->textHoverColor = textHoverColor;

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
}

Button::~Button() {}

void Button::Update(const sf::Vector2i& mousePosition)
{
	this->currentState = BUTTONIDLE;
	if (this->buttonShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
	{
		this->currentState = BUTTONHOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !this->isClicked)
		{
			this->currentState = BUTTONCLICKED;
			this->isClicked = true;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->isClicked)
		{
			this->isClicked = false;
		}
	}

	switch (currentState)
	{
		case BUTTONIDLE:
			this->buttonShape.setFillColor(this->idleColor);
			this->text.setFillColor(this->textIdleColor);
			break;

		case BUTTONHOVER:
			this->buttonShape.setFillColor(this->hoverColor);
			this->text.setFillColor(this->textHoverColor);
			break;
		case BUTTONCLICKED:
			/*
			 *    BUTTON CLICKED
			*/

		default:
			break;
	}
}

void Button::Render(sf::RenderTarget& target)
{
	target.draw(this->buttonShape);
	target.draw(this->text);
}

const bool Button::IsPressed() const
{
	return (this->currentState == BUTTONCLICKED);
}

void Button::CenterText()
{
	this->text.setPosition(
		this->buttonShape.getPosition().x + this->buttonShape.getSize().x * 0.5f - this->text.getGlobalBounds().width * 0.5f,
		this->buttonShape.getPosition().y + this->buttonShape.getSize().y * 0.5f - this->text.getGlobalBounds().height * 0.5f
		);
}

const std::string Button::GetStringText() const
{
	return this->text.getString();
}

const int Button::GetId() const
{
	return this->buttonId;
}

void Button::SetText(std::string string)
{
	this->text.setString(string);
}

void Button::SetId(int id)
{
	this->buttonId = id;
}
