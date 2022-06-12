#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>

class Bullet
{
public:
	Bullet() = default;
	~Bullet() = default;

	void setup(sf::Vector2f from, sf::Vector2f to, float speed);
	void update();

	void draw(sf::RenderWindow& window);
	static void loadFiles(std::filesystem::path pathTexture);

	bool isDelete() const noexcept ;
private:
	sf::Vector2f from;
	sf::Vector2f diraction;

	size_t lastLiveBullet = 0;
	size_t timeLiveBullet = 1000;

	static sf::Sprite bulletSprite;
	static sf::Texture bulletTexture;

	float speed = 0;
};