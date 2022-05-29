#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>

class Bullet
{
public:
	Bullet() = default;

	void setup(sf::Vector2f position, sf::Vector2f positionTarget, float speed) noexcept;
	void update();

	void draw(sf::RenderWindow& window) noexcept;
	static void loadFiled(std::filesystem::path texture);

private:
	sf::Vector2f position;
	sf::Vector2f diraction;

	static sf::Sprite bulletSprite;
	static sf::Texture bulletTexture;

	size_t speed = 0;
};