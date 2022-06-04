#include "Player.h"

void Player::setup(sf::Vector2f positionPlayer, size_t hp, float speed,
	std::filesystem::path pathPlayerAtlas, std::filesystem::path pathBulletTexture)
{
	this->positionPlayer = positionPlayer;
	this->hp = hp;
	this->speed = speed;
	
	loadFiles(pathPlayerAtlas, pathBulletTexture);

	gun.setup("pistol", 170, 2500);
	playerSprite.setPosition(positionPlayer.x, positionPlayer.y);


}

void Player::control(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		playerSprite.move(speed, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		playerSprite.move(-speed, 0.f);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		const auto mouse = (sf::Vector2f)sf::Mouse::getPosition(window);
		gun.shot(mouse, getCenterPosition());
	}
}

void Player::draw(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		runRight.play(playerSprite);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		runLeft.play(playerSprite);
	else stay.play(playerSprite);

	window.draw(playerSprite);

	gun.update();
	gun.draw(window);
}


sf::Vector2f Player::getCenterPosition()
{  
	const auto playerPos = playerSprite.getPosition();
	const auto bounds = playerSprite.getLocalBounds();
	sf::Vector2f centerPos;
	centerPos.x = playerPos.x + bounds.width / 2;
	centerPos.y = playerPos.y + bounds.height / 2;

	return centerPos;
}

void Player::loadFiles(std::filesystem::path pathPlayerAtlas, std::filesystem::path pathBulletTexture)
{
	if (!playerTexture.loadFromFile(pathPlayerAtlas.string()))
		throw std::runtime_error("Player::Error: failed loading file " + pathPlayerAtlas.string());

	gun.loadFiles(pathBulletTexture);

	runRight.setup(100, 6, sf::Vector2f(80, 94), sf::Vector2f(80, 94));
	runLeft.setup(100, 6, sf::Vector2f(80, 94), sf::Vector2f(80, 94));
	stay.setup(100, 6, sf::Vector2f(0, 0), sf::Vector2f(80, 94));

	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(0, 0, 80, 94));
}