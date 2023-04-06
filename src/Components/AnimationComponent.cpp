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

#include "Components/AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& animetionSheet)
{
	this->sprite = sprite;
	this->animationSheet = animationSheet;
}

AnimationComponent::~AnimationComponent()
{
	for(auto &it : this->animations)
		delete it.second;
}

const bool& AnimationComponent::IsDone(const std::string key)
{
	return this->animations[key]->isDone();
}

void AnimationComponent::AddAnimation(const std::string key, float animationTimer, int startFrameX, int startFrameY, int framesX, int framesY, int width, int height)
{
	this->animations[key] = new Animation(this->sprite, this->animationSheet, animationTimer, startFrameX, startFrameY, framesX, framesY, width, height);
}

const bool& AnimationComponent::Play(const std::string key, const float& dt, const bool priority)
{
	//TBD...
}

const bool& AnimationComponent::Play(const std::string key, const float& dt, const float& modifier, const float& modifierMax, const bool priority)
{
	//TBD...
}

AnimationComponent::Animation::Animation(sf::Sprite& sprite, sf::Texture& animationSheet,
	float animationTimer, int startFrameX, int startFrameY, int framesX, int framesY, int width, int height)
{
	this->sprite = sprite;
	this->animationSheet = animationSheet;
	this->animationTimer = animationTimer;
	this->width = width;
	this->height = height;

	this->startRect = sf::IntRect(startFrameX * width, startFrameY * height, width, height);
	this->currentRect = this->startRect;
	this->endRect = sf::IntRect(framesX * width, framesY * height, width, height);
}

const bool& AnimationComponent::Animation::IsDone() const
{
	return this->isDone;
}

const bool& AnimationComponent::Animation::Play(const float dt)
{
	//TBD...
}

void AnimationComponent::Animation::Reset()
{
	this->timer = this->animationTimer;
	this->currentRect = this->startRect;
}

