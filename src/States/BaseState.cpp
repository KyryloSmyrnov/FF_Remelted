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

#include "States/BaseState.h"

BaseState::BaseState(StateData* stateData)
{
	this->stateData = stateData;
	this->window = stateData->window;
	this->availableKeys = stateData->availableKeys;
	this->states = stateData->states;
	this->gridSize = stateData->gridSize;

	this->quit = false;
	this->paused = false;
}

const bool& BaseState::GetQuit() const
{
	return this->quit;
}

void BaseState::EndState()
{
	this->quit = true;
}

void BaseState::PauseState()
{
	this->paused = true;
}

void BaseState::UnpauseState()
{
	this->paused = false;
}

void BaseState::UpdateMousePositions(sf::View* view)
{
	this->screenMousePosition = sf::Mouse::getPosition();
	this->windowMousePosition = sf::Mouse::getPosition(*this->window);

	if (view)
		this->window->setView(*view);

	this->viewMousePosition = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
	this->gridMousePosition = sf::Vector2i(
		static_cast<int>(this->viewMousePosition.x) / static_cast<int>(this->gridSize),
		static_cast<int>(this->viewMousePosition.y) / static_cast<int>(this->gridSize));

	this->window->setView(this->window->getDefaultView());
}

sf::Vector2f BaseState::AdaptPositionToResolution(float xPrc, float yPrc)
{
	return sf::Vector2f(std::floor(static_cast<float>(stateData->graphicsSettings->resolution.width * (xPrc / 100.0f))),
						std::floor(static_cast<float>(stateData->graphicsSettings->resolution.height) * (yPrc / 100.0f)));
}

sf::Vector2f BaseState::AdaptButtonSizeToResolution()
{
	return sf::Vector2f(stateData->graphicsSettings->resolution.width * 0.23f,
						stateData->graphicsSettings->resolution.height * 0.05f);
}

int BaseState::AdaptFontSize()
{
	float scaleFactorX = static_cast<float>(stateData->graphicsSettings->resolution.width) / 2560.0f;
	float scaleFactorY = static_cast<float>(stateData->graphicsSettings->resolution.height) / 1440.0f;
	float scaleFactor = std::min(scaleFactorX, scaleFactorY);
	
	int fontSize = static_cast<int>(baseFontSize * scaleFactor);

	return fontSize;
}
