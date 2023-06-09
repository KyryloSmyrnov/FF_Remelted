﻿/*
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

#include "StateData.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Mouse.hpp>

class BaseState
{
public:
	BaseState(StateData* stateData);
	virtual ~BaseState() { };

	const bool& GetQuit() const;

	void EndState();
	void PauseState();
	void UnpauseState();

	virtual void UpdateMousePositions(sf::View* view = nullptr);
	virtual void UpdateInput(const float& dt) = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target = nullptr) = 0;

protected:
	StateData* stateData;
	std::stack<BaseState*>* states;
	sf::RenderWindow* window;

	std::map<std::string, int>* availableKeys;
	std::map<std::string, int> keyBinds;

	bool quit;
	bool paused;

	float gridSize;

	int baseFontSize = 28;

	sf::Vector2i screenMousePosition;
	sf::Vector2i windowMousePosition;
	sf::Vector2f viewMousePosition;
	sf::Vector2i gridMousePosition;

	std::map<std::string, sf::Texture> textures;

	sf::Vector2f AdaptPositionToResolution(float xPrc, float yPrc);
	sf::Vector2f AdaptButtonSizeToResolution();
	int AdaptFontSize();
	
	virtual void InitKeyBinds() = 0;
};