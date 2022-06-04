#include "Bullet.h"

#include <cmath>

sf::Sprite Bullet::bulletSprite;
sf::Texture Bullet::bulletTexture;

void Bullet::setup(sf::Vector2f from, sf::Vector2f to, float speed)
{
	this->from = from;
	this->speed = speed;

	diraction = to - from;
	const float length = sqrtf(diraction.x * diraction.x + diraction.y * diraction.y);
	diraction /= length;

	bulletSprite.setPosition(from);
}
void Bullet::update(size_t timeLiveBullet, std::vector<Bullet>& chamber) 
{
	from += diraction;
	bulletSprite.setPosition(from);

	//if (clock() - lastLiveBullet >= timeLiveBullet)
	//	for (size_t i = 0; i < chamber.size() - sizeof(chamber.begin()); ++i)
	//	{
	//		chamber.erase(chamber.begin());
	//	}
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