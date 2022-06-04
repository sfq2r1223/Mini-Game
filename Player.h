#pragma once

#include "Animation.h"
#include "Gun.h"

#include <SFML/Graphics.hpp>
#include <filesystem>

class Player
{
public:
	Player() = default;
	~Player() = default;

	void setup(sf::Vector2f positionPlayer, size_t hp, float speed);
	void loadFiles(std::filesystem::path playerAtlas, std::filesystem::path bulletTexture);

	void control(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

	sf::Vector2f getCenterPosition();
private:
	sf::Vector2f positionPlayer;
	size_t hp = 0;
	float speed = 0;

	Animation runRight;
	Animation runLeft;
	Animation stay;


	sf::Sprite playerSprite;
	sf::Texture playerTexture;

	Gun gun;
};