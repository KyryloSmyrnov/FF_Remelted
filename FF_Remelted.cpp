/*
****************************************
 * FF_REMELTED
 * 
 * Copyright (C) 2023 Kyrylo Smyrnov
 * 
 * @KyryloSmyrnov
 ****************************************
 */

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(2560, 1440), "FF_REMELTED", sf::Style::Fullscreen);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.display();
		window.clear();
	}

	return 0;
}