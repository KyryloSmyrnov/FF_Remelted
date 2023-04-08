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
#include <SFML/Graphics/Glsl.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "SFML/Graphics/RenderTarget.hpp"

#include "Engine/Components/AnimationComponent.h"
#include "Engine/Components/HitboxComponent.h"
#include "Engine/Components/MovementComponent.h"

class Actor
{
public:
	Actor();
	virtual ~Actor();

	void SetTexture(sf::Texture& texture);

	void CreateHitboxComponent(sf::Sprite& sprite, float xOffset, float yOffset, float width, float height);
	void CreateMovementComponent(const float maxVelocity, const float acceleration);
	void CreateAnimationComponent(sf::Texture& animetionSheet);

	virtual HitboxComponent* GetHitboxComponent();
	virtual MovementComponent* GetMovementComponent();
	virtual AnimationComponent* GetAnimationComponent();

	virtual const sf::Vector2f& GetPosition() const;
	virtual const sf::Vector2f& GetSpritePosition() const;
	virtual const sf::Vector2f GetCenter() const;
	virtual const sf::Vector2f GetSpriteCenter() const;
	virtual const sf::Vector2i GetGridPosition(const int gridSize) const;
	virtual const sf::FloatRect GetGlobalBounds() const;

	virtual void SetPosition(const float x, const float y);

	virtual void Movement(const float x, const float y, const float& dt);
	virtual void StopMovement();
	virtual void StopMovementX();
	virtual void StopMovementY();

	virtual const float GetDistance(const Actor& actor) const;
	virtual const float GetSpriteDistance(const Actor& actor) const;

	virtual void Update(const float& dt, sf::Vector2f viewMousePosition, const sf::View& view) = 0;
	virtual void Render(sf::RenderTarget& target, sf::Shader* shader, const sf::Vector2f lightPosition, const bool showHitbox) = 0;

protected:
	sf::Sprite sprite;

	HitboxComponent* hitboxComponent;
	AnimationComponent* animationComponent;
	MovementComponent* movementComponent;

private:
	void InitVariables();
};