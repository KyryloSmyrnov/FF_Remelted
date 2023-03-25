#include "GUI/GUI.h"

GUI::Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, unsigned int characterSize,
	sf::Color textIdleColor, sf::Color textHoverColor,
	sf::Color idleColor, sf::Color hoverColor)
{
	this->currentState = BUTTONIDLE;

	this->buttonShape.setPosition(sf::Vector2f(x, y));
	this->buttonShape.setSize(sf::Vector2f(width, height));

	this->buttonIcon =		buttonIcon;
	this->buttonBackgroud = buttonBackgroud;

	this->font =			font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(textIdleColor);
	this->text.setCharacterSize(characterSize);
	
	this->text.setPosition(x + width * 0.5 - this->text.getGlobalBounds().width * 0.5,
						   y + height * 0.5 - this->text.getGlobalBounds().height * 0.5);

	this->textIdleColor =	textIdleColor;
	this->textHoverColor =	textHoverColor;

	this->idleColor =		idleColor;
	this->hoverColor =		hoverColor;
}

GUI::Button::~Button() {}

void GUI::Button::Update(const sf::Vector2i& mousePosition)
{
	this->currentState = BUTTONIDLE;
	if (this->buttonShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
		this->currentState = BUTTONHOVER;

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
	
	default:
		break;
	}
}

void GUI::Button::Render(sf::RenderTarget& target)
{
	target.draw(this->buttonShape);
	target.draw(this->text);
}