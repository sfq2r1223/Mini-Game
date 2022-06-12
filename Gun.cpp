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
	for (auto i = chamber.begin(); i != chamber.end(); )
	{
		i->update();
		if (i->isDelete())
			i = chamber.erase(i);
		if (i != chamber.end())
			++i;
	}
}
void Gun::draw(sf::RenderWindow& window)
{
	for (auto i : chamber)
		i.draw(window);
}