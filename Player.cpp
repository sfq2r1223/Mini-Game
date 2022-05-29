#include "Player.h"

void Player::setup(sf::Vector2f positionPlayer, size_t hp, float speed)
{
	this->positionPlayer = positionPlayer;
	this->hp = hp;
	this->speed = speed;
	
	gun.setup("pistol", 100);
	playerSprite.setPosition(positionPlayer.x, positionPlayer.y);
}
void Player::control(sf::RenderWindow& window) noexcept
{
	const auto mouse = (sf::Vector2f)sf::Mouse::getPosition(window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		playerSprite.move(speed, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		playerSprite.move(-speed, 0.f);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		gun.shot(mouse, getCenterPosition());
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
sf::Vector2f Player::getCenterPosition() noexcept
{
	auto bounds = playerSprite.getLocalBounds();
	sf::Vector2f centerPos;
	centerPos.x = positionPlayer.x + bounds.width / 2;
	centerPos.y = positionPlayer.y + bounds.height / 2;

	return centerPos;
}
void Player::loadFiled(std::filesystem::path playerAtlas, std::filesystem::path bulletTexture)
{
	if (!playerTexture.loadFromFile(playerAtlas.string()))
		throw std::runtime_error("Player::Error: failed loading file " + playerAtlas.string());

	gun.loadFiled(bulletTexture);

	runRight.setup(100, 6, sf::Vector2f(80, 94), sf::Vector2f(80, 94));
	runLeft.setup(100, 6, sf::Vector2f(80, 94), sf::Vector2f(80, 94));
	stay.setup(100, 6, sf::Vector2f(0, 0), sf::Vector2f(80, 94));

	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(0, 0, 80, 94));
}