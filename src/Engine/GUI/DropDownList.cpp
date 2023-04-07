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

#include <Engine/GUI/DropDownList.h>

DropDownList::DropDownList(float x, float y, float width, float height,
	sf::Font& font, std::vector<std::string> list, unsigned characterSize,
	sf::Color textIdleColor, sf::Color textHoverColor,
	std::string texturePath, std::string hoverTexturePath,
	unsigned defaultId)
	: font(font)
	, activeList(false)
{
	this->activeButton = new Button(x, y, width, height, &font, list[defaultId],
		characterSize, textIdleColor, textHoverColor,
		texturePath, hoverTexturePath);
	this->activeButton->SetId(0);

	for (int i = 0; i < list.capacity() - 1; ++i)
	{
		buttons.push_back
			(
				new Button(x, (y + (i + 1) * height), width, height, &font, list[i + 1],
					characterSize, textIdleColor, textHoverColor,
					texturePath, hoverTexturePath)
				);
		buttons[i]->SetId(i + 1);
	}
}

DropDownList::~DropDownList()
{
	delete this->activeButton;

	for (int i = 0; i < this->buttons.size(); ++i)
		delete this->buttons[i];
}

void DropDownList::Update(const sf::Vector2i& mousePosition)
{
	this->activeButton->Update(mousePosition);

	if (this->activeButton->IsPressed())
		activeList = !activeList;

	if (this->activeList)
		for (auto& it : buttons)
		{
			it->Update(mousePosition);
			if (it->IsPressed())
			{
				std::string tempText = activeButton->GetStringText();
				unsigned short int tempId = activeButton->GetId();

				this->activeList = false;

				this->activeButton->SetText(it->GetStringText());
				this->activeButton->SetId(it->GetId());

				it->SetText(tempText);
				it->SetId(tempId);

				this->activeButton->CenterText();
				it->CenterText();
			}
		}
}

void DropDownList::Render(sf::RenderTarget& target)
{
	this->activeButton->Render(target);

	if (activeList)
		for (auto& it : buttons)
			it->Render(target);
}
