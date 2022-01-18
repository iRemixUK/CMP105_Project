#include "Enemy.h"
Enemy::Enemy()
{
	health = 75;

	// Setup idle animation
	idle.addFrame(sf::IntRect(0, 0, 100, 100));

	// Setup death animation

	hit1.addFrame(sf::IntRect(-10, 180, 100, 100));
	hit2.addFrame(sf::IntRect(75, 180, 100, 100));

	currentAnimation = &idle;
	setTextureRect(currentAnimation->getCurrentFrame());
}

Enemy::~Enemy()
{

}
int Enemy::Get_Health()
{
	return health;
}

void Enemy::Set_Health()
{
	health = 75;
}

void Enemy::update(float dt, int p, int d)
{
	currentAnimation->animate(dt);
	distance = p - d;
	if (distance >= 0)
	{
		idle.setFlipped(true);
		currentAnimation = &idle;
		setTextureRect(currentAnimation->getCurrentFrame());

		if (health == 50)
		{
			hit1.setFlipped(true);
			currentAnimation = &hit1;
			setTextureRect(currentAnimation->getCurrentFrame());
		}

		if (health == 25)
		{
			hit2.setFlipped(true);
			currentAnimation = &hit2;
			setTextureRect(currentAnimation->getCurrentFrame());
		}
	}
	else
	{
		idle.setFlipped(false);
		currentAnimation = &idle;
		setTextureRect(currentAnimation->getCurrentFrame());

		if (health == 50)
		{
			hit1.setFlipped(false);
			currentAnimation = &hit1;
			setTextureRect(currentAnimation->getCurrentFrame());
		}

		if (health == 25)
		{
			hit2.setFlipped(false);
			currentAnimation = &hit2;
			setTextureRect(currentAnimation->getCurrentFrame());
		}
	}
	move(velocity * dt);
}

void Enemy::CollisionResponse()
{
	health = health - 25;
}

void Enemy::render(sf::RenderWindow* window)
{
}