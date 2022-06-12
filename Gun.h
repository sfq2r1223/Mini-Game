#pragma once
#include "Bullet.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Gun
{
public:
	Gun() = default;
	~Gun() = default;

	void setup(const std::string& name, size_t delay, size_t timeLiveBullet) noexcept;
	void update();

	void loadFiles(std::filesystem::path);
	void draw(sf::RenderWindow& window);

	void shot(sf::Vector2f positionMouse, sf::Vector2f position);
private:
	std::string name;
	size_t delay = 0;
	size_t lastShot = 0;
	size_t timeLiveBullet = 0;
	size_t lastLiveBullet = 0;

	std::vector<Bullet> chamber;
};