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

#include <SFML/Graphics/Sprite.hpp>

enum MOVEMENTSTATES
{
	MOVEMENTIDLE = 0,
	MOVEMENTMOVING = 1,
	MOVEMENTMOVINGFORWARD = 2,
	MOVEMENTMOVINGBACKWARD = 3,
	MOVEMENTMOVINGLEFT = 4,
	MOVEMENTMOVINGRIGHT = 5
};

class MovementComponent
{
public:
	MovementComponent(sf::Sprite sprite, float maxVelocity, float acceleration);
	virtual ~MovementComponent() { };

	void StopMovement();
	void StopMovementX();
	void StopMovementY();

	float& GetMaxVelocity();
	sf::Vector2f& GetVelocity();
	
	void Movement(const float X, const float Y, const float& dt);
	void Update(const float& dt);

private:
	sf::Sprite& sprite;

	sf::Vector2f velocity;

	float maxVelocity;
	float acceleration;
};