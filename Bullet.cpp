#include "Bullet.h"

#include <cmath>

sf::Sprite Bullet::bulletSprite;
sf::Texture Bullet::bulletTexture;

void Bullet::setup(sf::Vector2f position, sf::Vector2f positionTarget, float speed) noexcept
{
	this->position = position;
	this->speed = speed;

	diraction = positionTarget - position;
	float length = sqrt(diraction.x * diraction.x + diraction.y * diraction.y);
	diraction /= length;

	bulletSprite.setPosition(position);
}
void Bullet::update() 
{
	position += diraction;
	bulletSprite.setPosition(position);
}
void Bullet::draw(sf::RenderWindow& window) noexcept
{
	bulletSprite.setPosition(position);
	window.draw(bulletSprite);
}
void Bullet::loadFiled(std::filesystem::path texture)
{
	if (!bulletTexture.loadFromFile(texture.string()))
		throw std::runtime_error("Bullet::Error: failed loading file: " + texture.string());

	bulletSprite.setTexture(bulletTexture);

	const auto bounds = bulletSprite.getLocalBounds();
	bulletSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}