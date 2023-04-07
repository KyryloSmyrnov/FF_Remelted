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

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

class HitboxComponent
{
public:
	HitboxComponent(sf::Sprite& sprite, float xOffset, float yOffset, float width, float height);
	virtual ~HitboxComponent() { };

	const sf::Vector2f& GetPosition() const;
	const sf::FloatRect GetGlobalBounds() const;

	void SetPosition(const sf::Vector2f& position);

	bool CollisionWith(const sf::FloatRect& floatRect);

	void Update();
	void Render(sf::RenderTarget& target);

private:
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;

	float xOffset;
	float yOffset;
};

