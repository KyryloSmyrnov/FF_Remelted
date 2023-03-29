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

#include "GUI/GUI.h"

GUI::Button::Button(float x, float y, float width, float height,
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

GUI::Button::~Button() {}

void GUI::Button::Update(const sf::Vector2i& mousePosition)
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

void GUI::Button::Render(sf::RenderTarget& target)
{
	target.draw(this->buttonShape);
	target.draw(this->text);
}

const bool GUI::Button::IsPressed() const
{
	return (this->currentState == BUTTONCLICKED);
}

void GUI::Button::CenterText()
{
	this->text.setPosition(
		this->buttonShape.getPosition().x + this->buttonShape.getSize().x * 0.5f - this->text.getGlobalBounds().width * 0.5f,
		this->buttonShape.getPosition().y + this->buttonShape.getSize().y * 0.5f - this->text.getGlobalBounds().height * 0.5f
	);
}

const std::string GUI::Button::GetStringText() const
{
	return this->text.getString();
}

const int GUI::Button::GetId() const
{
	return this->buttonId;
}

void GUI::Button::SetText(std::string string)
{
	this->text.setString(string);
}

void GUI::Button::SetId(int id)
{
	this->buttonId = id;
}

GUI::DropDownList::DropDownList(float x, float y, float width, float height,
	sf::Font& font, std::vector<std::string> list, unsigned characterSize,
	sf::Color textIdleColor, sf::Color textHoverColor,
	sf::Color idleColor, sf::Color hoverColor,
	unsigned defaultId)
	: font(font)
	, activeList(false)
{
	this->activeButton = new GUI::Button(x, y, width, height, &font, list[defaultId],
		characterSize, textIdleColor, textHoverColor,
		idleColor, hoverColor);
	this->activeButton->SetId(0);

	for (int i = 0; i < list.capacity() - 1; ++i)
	{
		buttons.push_back
			(
				new GUI::Button(x, (y + (i + 1) * height), width, height, &font, list[i + 1],
					characterSize, textIdleColor, textHoverColor,
					idleColor, hoverColor)
				);
		buttons[i]->SetId(i + 1);
	}
}

GUI::DropDownList::~DropDownList()
{
	delete this->activeButton;

	for (int i = 0; i < this->buttons.size(); ++i)
		delete this->buttons[i];
}

void GUI::DropDownList::Update(const sf::Vector2i& mousePosition)
{
	this->activeButton->Update(mousePosition);
	
	if (this->activeButton->IsPressed())
		activeList = !activeList;

	if (this->activeList)
		for (auto& it : buttons)
		{
			it->Update(mousePosition);
			if (it->IsPressed())
			{
				std::string tempText = activeButton->GetStringText();
				unsigned short int tempId = activeButton->GetId();

				this->activeList = false;

				this->activeButton->SetText(it->GetStringText());
				this->activeButton->SetId(it->GetId());

				it->SetText(tempText);
				it->SetId(tempId);

				this->activeButton->CenterText();
				it->CenterText();
			}
		}
}

void GUI::DropDownList::Render(sf::RenderTarget& target)
{
	this->activeButton->Render(target);

	if (activeList)
		for (auto& it : buttons)
			it->Render(target);
}