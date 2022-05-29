#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>

class Animation
{
public:
	Animation() = default;
	~Animation() = default;

	void setup(size_t delay, size_t maxFrame, 
		sf::Vector2f positionOnAtlas, sf::Vector2f size) noexcept;
	void play(sf::Sprite& sprite);

	sf::Vector2f getPositionOnAtlas() const noexcept;
	sf::Vector2f getSize() const noexcept;
	size_t getMaxFrame() const noexcept;
private:
	size_t delay = 0;
	size_t endTime = 0;
	size_t maxFrame = 0;
	size_t frame = 0;
	sf::Vector2f positionOnAtlas;
	sf::Vector2f size;

};