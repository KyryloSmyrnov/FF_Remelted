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
#include "Button.h"


class DropDownList
{
public:
	DropDownList() { }
	DropDownList(float x, float y, float width, float height,
		sf::Font& font, std::vector<std::string> list, unsigned int characterSize,
		sf::Color textIdleColor, sf::Color textHoverColor,
		std::string texturePath, std::string hoverTexturePath,
		unsigned int defaultId = 0);
	~DropDownList();

	void Update(const sf::Vector2i& mousePosition);
	void Render(sf::RenderTarget& target);

private:
	sf::Font font;

	Button* activeButton;
	std::vector<Button*> buttons;

	bool activeList;
};
