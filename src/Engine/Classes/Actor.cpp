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

#include "Engine/Classes/Actor.h"

Actor::Actor()
{
	this->InitVariables();
}

Actor::~Actor()
{
	delete this->hitboxComponent;
	delete this->movementComponent;
	delete this->animationComponent;
}

void Actor::SetTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Actor::CreateHitboxComponent(sf::Sprite& sprite, float xOffset, float yOffset, float width, float height)
{
	this->hitboxComponent = new HitboxComponent(sprite, xOffset, yOffset, width, height);
}

void Actor::CreateMovementComponent(const float maxVelocity, const float acceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration);
}

void Actor::CreateAnimationComponent(sf::Texture& animetionSheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, animetionSheet);
}

HitboxComponent* Actor::GetHitboxComponent()
{
	return this->hitboxComponent;
}

MovementComponent* Actor::GetMovementComponent()
{
	return this->movementComponent;
}

AnimationComponent* Actor::GetAnimationComponent()
{
	return this->animationComponent;
}

const sf::Vector2f& Actor::GetPosition() const
{
	if(this->hitboxComponent)
		return this->hitboxComponent->GetPosition();

	return this->sprite.getPosition();
}

const sf::Vector2f& Actor::GetSpritePosition() const
{
	return this->sprite.getPosition();
}

const sf::Vector2f Actor::GetCenter() const
{
	if(this->hitboxComponent)
		return this->hitboxComponent->GetPosition() + sf::Vector2f
			(
				this->hitboxComponent->GetGlobalBounds().width / 2,
				this->hitboxComponent->GetGlobalBounds().height / 2
			);

	return this->sprite.getPosition() + sf::Vector2f
		(
			this->sprite.getGlobalBounds().width / 2,
			this->sprite.getGlobalBounds().height / 2
		);
}

const sf::Vector2f Actor::GetSpriteCenter() const
{
	return this->sprite.getPosition() + sf::Vector2f
		(
			this->sprite.getGlobalBounds().width / 2,
			this->sprite.getGlobalBounds().height / 2
		);
}

const sf::Vector2i Actor::GetGridPosition(const int gridSize) const
{
	if(this->hitboxComponent)
		return sf::Vector2i
			(
				static_cast<int>(this->hitboxComponent->GetPosition().x) / gridSize,
				static_cast<int>(this->hitboxComponent->GetPosition().y) / gridSize
			);

	return sf::Vector2i
		(
			static_cast<int>(this->sprite.getPosition().x) / gridSize,
			static_cast<int>(this->sprite.getPosition().y) / gridSize
		);
}

const sf::FloatRect Actor::GetGlobalBounds() const
{
	if(this->hitboxComponent)
		return this->hitboxComponent->GetGlobalBounds();

	return this->sprite.getGlobalBounds();
}

void Actor::SetPosition(const float x, const float y)
{
	if(this->hitboxComponent)
		hitboxComponent->SetPosition(sf::Vector2f(x, y));
	else
		sprite.setPosition(sf::Vector2f(x, y));
}

void Actor::Movement(const float x, const float y, const float& dt)
{
	if(this->movementComponent)
		this->movementComponent->Movement(x, y , dt);
}

void Actor::StopMovement()
{
	if(this->movementComponent)
		movementComponent->StopMovement();
}

void Actor::StopMovementX()
{
	if(this->movementComponent)
		movementComponent->StopMovementX();
}

void Actor::StopMovementY()
{
	if(this->movementComponent)
		movementComponent->StopMovementY();
}

const float Actor::GetDistance(const Actor& actor) const
{
	return sqrt(pow(this->GetCenter().x - actor.GetCenter().x, 2) +
				pow(this->GetCenter().y - actor.GetCenter().y, 2));
}

const float Actor::GetSpriteDistance(const Actor& actor) const
{
	return sqrt(pow(this->GetSpriteCenter().x - actor.GetSpriteCenter().x, 2) +
				pow(this->GetSpriteCenter().y - actor.GetSpriteCenter().y, 2));
}