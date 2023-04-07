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

#include "Engine/Components/HitboxComponent.h"

HitboxComponent::HitboxComponent(sf::Sprite& sprite, float xOffset, float yOffset, float width, float height) : sprite(sprite), xOffset(xOffset), yOffset(yOffset)
{
	this->hitbox.setPosition(this->sprite.getPosition().x + xOffset, this->sprite.getPosition().y + yOffset);
	this->hitbox.setSize(sf::Vector2f(width, height));
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(-1);
	this->hitbox.setOutlineColor(sf::Color::Red);
}

const sf::Vector2f& HitboxComponent::GetPosition() const
{
	return this->hitbox.getPosition();
}

const sf::FloatRect HitboxComponent::GetGlobalBounds() const
{
	return this->hitbox.getGlobalBounds();
}

void HitboxComponent::SetPosition(const sf::Vector2f& position)
{
	this->hitbox.setPosition(position);
	this->sprite.setPosition(position.x - this->xOffset, position.y - this->yOffset);
}

bool HitboxComponent::CollisionWith(const sf::FloatRect& floatRect)
{
	return this->hitbox.getGlobalBounds().intersects(floatRect);
}

void HitboxComponent::Update()
{
	this->hitbox.setPosition(this->sprite.getPosition().x + xOffset, this->sprite.getPosition().y + yOffset);
}

void HitboxComponent::Render(sf::RenderTarget& target)
{
	target.draw(this->hitbox);
}



