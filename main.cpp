#include "Player.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <filesystem>
#include <iostream>

int main()
{
	try
	{
		sf::RenderWindow window(sf::VideoMode(1280, 720), "Mini Game");

		std::filesystem::path playerAtlas = "playerAtlas.png";
		std::filesystem::path bulletTexture = "bullet.png";

		Player player;

		player.loadFiled(playerAtlas, bulletTexture);

		player.setup(sf::Vector2f(0, 600), 3, 0.1f);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
				if (event.type == sf::Event::Closed)
					window.close();

			window.clear(sf::Color::White);

			player.control(window);
			player.draw(window);

			window.display();
		}
	}
	catch (std::runtime_error error)
	{
		std::cout << "--------------------------" << std::endl;
		std::cout << error.what() << std::endl;
		std::cout << "--------------------------" << std::endl;
	}
	return 0;
}