#include "Player.h"

Player::Player()
{
	speedx = 0.f;
	speedy = 0.f;
	score = 0;

	// Setup idle animation
	idle.addFrame(sf::IntRect(0, 0, 100, 100));

	// Setup walk animation
	walk.addFrame(sf::IntRect(240, 367, 100, 100));
	walk.addFrame(sf::IntRect(325, 367, 100, 100));
	walk.addFrame(sf::IntRect(410, 367, 100, 100));
	walk.addFrame(sf::IntRect(495, 367, 100, 100));
	walk.addFrame(sf::IntRect(580, 367, 100, 100));
	walk.addFrame(sf::IntRect(665, 367, 100, 100));
	walk.setFrameSpeed(1.f / 3.f);

	currentAnimation = &idle;
	setTextureRect(currentAnimation->getCurrentFrame());
}

Player::~Player()
{

}

void Player::update(float dt)
{
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
	sf::Vector2u WinSize = window->getSize();
	sf::Vector2f ObjectSize = getSize();

	if (getPosition().y > WinSize.y - ObjectSize.y)
	{
		speedy = 0;
		setPosition(getPosition().x, WinSize.y - ObjectSize.y);
	}

	if (getPosition().x > WinSize.x - ObjectSize.x)
	{
		speedx = 0;
		setPosition(WinSize.x - ObjectSize.x, getPosition().y);
	}

	if (getPosition().y < 0 )
	{
		speedy = 0;
		setPosition(getPosition().x, 0);
	}

	if (getPosition().x < 0)
	{
		speedy = 0;
		setPosition(0, getPosition().y);
	}

}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W)) // Up
	{
		speedy = -200.f;
	}
	else if (input->isKeyDown(sf::Keyboard::S)) // Down
	{
		speedy = 200.f;
	}
	else
	{
		speedy = 0;
	}

	if (input->isKeyDown(sf::Keyboard::A)) // Left
	{
		speedx = -200.f;
		walk.setFlipped(true);
		currentAnimation = &walk;
		setTextureRect(currentAnimation->getCurrentFrame());
	}
	else if (input->isKeyDown(sf::Keyboard::D)) // Right
	{
		speedx = 200.f;
		walk.setFlipped(false);
		currentAnimation = &walk;
		setTextureRect(currentAnimation->getCurrentFrame());
	}
	else
	{
		speedx = 0;
		currentAnimation = &idle;
		setTextureRect(currentAnimation->getCurrentFrame());
	}

}

void Player::CollisionResponse()
{
	health = health - 25;
}


int Player::Get_Score()
{
	return score;
}

void Player::Set_Score()
{
	score = score + 100;
}

void Player::Restart_Score()
{
	score = 0;
}

int Player::Get_Health()
{
	return health;
}

void Player::Set_Health(int a)
{
	health = a;
}
float Player::getSpeedX()
{
	return speedx;
}

float Player::getSpeedY()
{
	return speedy;
}