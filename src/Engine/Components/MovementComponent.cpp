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

#include "Engine/Components/MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite sprite, float maxVelocity, float acceleration) : sprite(sprite)
{
	this->maxVelocity = maxVelocity;
	this->acceleration = acceleration;
}

void MovementComponent::StopMovement()
{
	this->velocity.x = 0.0f;
	this->velocity.y = 0.0f;
}

void MovementComponent::StopMovementX()
{
	this->velocity.x = 0.0f;
}

void MovementComponent::StopMovementY()
{
	this->velocity.y = 0.0f;
}

float& MovementComponent::GetMaxVelocity()
{
	return this->maxVelocity;
}

sf::Vector2f& MovementComponent::GetVelocity()
{
	return this->velocity;
}

void MovementComponent::Movement(const float X, const float Y, const float& dt)
{
	this->velocity.x += this->acceleration * X * dt;
	this->velocity.y += this->acceleration * Y * dt;
}

void MovementComponent::Update(const float& dt)
{
	//TBD...
}
