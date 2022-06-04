#include "Animation.h"

namespace
{
	void requireValid(const sf::Sprite& sprite, Animation& animation)
	{
		const auto bounds = sprite.getLocalBounds();
		float inMaxFrame;
		sf::Vector2f inPositionOnAtlas;
		inPositionOnAtlas.x = bounds.width;
		inPositionOnAtlas.y = bounds.height;
	}
	//namespace
}

void Animation::setup(size_t delay, size_t maxFrame,
	sf::Vector2f positionOnAtlas, sf::Vector2f size) noexcept
{
	this->delay = delay;
	this->maxFrame = maxFrame;
	this->positionOnAtlas = positionOnAtlas;
	this->size = size;
}
void Animation::play(sf::Sprite& sprite)
{
	requireValid(sprite, *this);

	if (clock() >= endTime + delay)
	{
		sprite.setTextureRect(sf::IntRect(positionOnAtlas.x * frame, positionOnAtlas.y, size.x, size.y));
		frame++;
		if (frame >= maxFrame)
			frame = 0;

		endTime = clock();
	}
}
sf::Vector2f Animation::getPositionOnAtlas() const noexcept
{
	return positionOnAtlas;
}
sf::Vector2f Animation::getSize() const noexcept
{
	return size;
}
size_t Animation::getMaxFrame() const noexcept
{
	return maxFrame;
}

