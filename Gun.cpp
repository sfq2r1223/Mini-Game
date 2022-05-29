#include "Gun.h"

void Gun::setup(const std::string& name, size_t delay) noexcept
{
	this->name = name;
	this->delay = delay;
}

void Gun::shot(sf::Vector2f positionMouse, sf::Vector2f position)
{
	if (clock() - lastShot >= delay)
	{
		Bullet bullet;
		bullet.setup(position, positionMouse, 0.1f);
		magazine.push_back(bullet);

		lastShot = clock();
	}
}
void Gun::loadFiled(std::filesystem::path bulletTexture)
{
	Bullet::loadFiled(bulletTexture);
}
void Gun::update() noexcept
{
	for (size_t i = 0; i < magazine.size(); ++i)
		magazine.at(i).update();
}
void Gun::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < magazine.size(); ++i)
		magazine.at(i).draw(window);
}