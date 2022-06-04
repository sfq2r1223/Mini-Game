#include "Gun.h"

void Gun::setup(const std::string& name, size_t delay, size_t timeLiveBullet) noexcept
{
	this->name = name;
	this->delay = delay;
	this->timeLiveBullet = timeLiveBullet;
}

void Gun::shot(sf::Vector2f positionMouse, sf::Vector2f position)
{
	if (clock() - lastShot >= delay)
	{
		Bullet bullet;
		bullet.setup(position, positionMouse, 0.1f);
		chamber.push_back(bullet);

		lastShot = clock();
	}
	//chamber.erase();
}
void Gun::loadFiles(std::filesystem::path pathTexture)
{
	Bullet::loadFiles(pathTexture);
}
void Gun::update()
{
	for (size_t i = 0; i < chamber.size(); ++i)
		chamber.at(i).update(timeLiveBullet, chamber);
}
void Gun::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < chamber.size(); ++i)
		chamber.at(i).draw(window);
}