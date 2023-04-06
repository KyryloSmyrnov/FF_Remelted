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

#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>

enum BUTTONSTATES
{
	BUTTONIDLE = 0,
	BUTTONHOVER = 1,
	BUTTONCLICKED = 2
};

class Button
{
public:
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, unsigned int characterSize,
		sf::Color textIdleColor, sf::Color textHoverColor,
		std::string texturePath, std::string hoverTexturePath);
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
	BUTTONSTATES currentState;

	sf::Texture buttonTexture;
	sf::Texture buttonHoverTexture;
	sf::RectangleShape buttonShape;

	sf::Font* font;
	sf::Text text;

	sf::Color textIdleColor;
	sf::Color textHoverColor;
	
	unsigned short int buttonId;
	bool isClicked = false;
};
