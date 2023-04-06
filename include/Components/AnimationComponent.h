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

#include <map>
#include <string>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class AnimationComponent
{
public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& animetionSheet);
	virtual ~AnimationComponent();

	const bool& IsDone(const std::string key);
	void AddAnimation(const std::string key, float animationTimer, int startFrameX, int startFrameY, int framesX, int framesY, int width, int height);
	
	const bool& Play(const std::string key, const float& dt, const bool priority = false);
	const bool& Play(const std::string key, const float& dt, const float& modifier, const float& modifierMax, const bool priority = false);
	
private:
	class Animation
	{
	public:
		Animation(sf::Sprite& sprite, sf::Texture& animationSheet,
			float animationTimer, int startFrameX, int startFrameY, int framesX,int framesY, int width, int height);
		~Animation() { };

		const bool& IsDone() const;
		const bool& Play(const float dt);
		void Reset();

		sf::Sprite& sprite;
		sf::Texture& animationSheet;

		float animationTimer;
		float timer;

		bool isDone;

		int width;
		int height;

		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;
	};
	
	sf::Sprite& sprite;
	sf::Texture& animationSheet;

	std::map<std::string, Animation*> animations;
	Animation* lastAnimation;
	Animation* priorityAnimation;
};
