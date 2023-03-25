#pragma once
#include "SFML/Graphics.hpp"

enum buttonState
{
	BUTTONIDLE =	0,
	BUTTONHOVER =	1
};

namespace GUI
{
	class Button
	{
	public:
		Button(float x, float y, float width, float height,
			   sf::Font* font, std::string text, unsigned int characterSize,
			   sf::Color textIdleColor, sf::Color textHoverColor,
			   sf::Color idleColor, sf::Color hoverColor);
		~Button();

		void Update(const sf::Vector2i& mousePosition);
		void Render(sf::RenderTarget& target);

	private:
		buttonState			currentState;

		sf::RectangleShape	buttonShape;

		sf::Sprite			buttonIcon;
		sf::Sprite			buttonBackgroud;

		sf::Font*			font;
		sf::Text			text;

		sf::Color			textIdleColor;
		sf::Color			textHoverColor;

		sf::Color			idleColor;
		sf::Color			hoverColor;
	};
}


