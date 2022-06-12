#include "Bullet.h"

#include <cmath>

sf::Sprite Bullet::bulletSprite;
sf::Texture Bullet::bulletTexture;

void Bullet::setup(sf::Vector2f from, sf::Vector2f to, float speed)
{
	this->from = from;
	this->speed = speed;

	lastLiveBullet = clock();

	diraction = to - from;
	const float length = sqrtf(diraction.x * diraction.x + diraction.y * diraction.y);
	diraction /= length;

	bulletSprite.setPosition(from);
}
void Bullet::update()
{
	from += diraction / 10.f;
	bulletSprite.setPosition(from);	
}
bool Bullet::isDelete() const noexcept
{
	if (clock() - lastLiveBullet >= timeLiveBullet)
		return true;
	return false;
}
void Bullet::draw(sf::RenderWindow& window)
{
	bulletSprite.setPosition(from);
	window.draw(bulletSprite);
}
void Bullet::loadFiles(std::filesystem::path pathTexture)
{
	if (!bulletTexture.loadFromFile(pathTexture.string()))
		throw std::runtime_error("Bullet::Error: failed loading file: " + pathTexture.string());

	bulletSprite.setTexture(bulletTexture);

	const auto bounds = bulletSprite.getLocalBounds();
	bulletSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}