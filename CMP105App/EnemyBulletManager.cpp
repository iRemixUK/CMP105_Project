#include "EnemyBulletManager.h"
#include <iostream>
using namespace std;

EnemyBulletManager::EnemyBulletManager()
{
	texture.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 40; i++)
	{
		bullets.push_back(Bullet());
		bullets[i].setAlive(false);
		bullets[i].setTexture(&texture);
		bullets[i].setSize(sf::Vector2f(100, 100));
		bullets[i].setCollisionBox(sf::FloatRect(0, 0, 100, 100));
	}
}

EnemyBulletManager::~EnemyBulletManager()
{
}

void EnemyBulletManager::handleInput(int posx, int posy)
{
	target = sf::Vector2f(posx, posy);
}

void EnemyBulletManager::spawn(float posx, float posy)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (!bullets[i].isAlive())
		{

			spawnPoint = sf::Vector2f(posx, posy);
			bullets[i].setAlive(true);
			bullets[i].setPosition(spawnPoint);
			direction = target - spawnPoint;
			direction = Vector::normalise(direction);
			bullets[i].setVelocity(200 * direction.x, 200 * direction.y);
			return;
		}
	}
}

void EnemyBulletManager::deathCheck()
{

	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			if (bullets[i].getPosition().x < -0)
			{
				bullets[i].setAlive(false);
			}
			if (bullets[i].getPosition().x > 1200)
			{
				bullets[i].setAlive(false);
			}
			if (bullets[i].getPosition().y < 0)
			{
				bullets[i].setAlive(false);
			}
			if (bullets[i].getPosition().y > 675)
			{
				bullets[i].setAlive(false);
			}
			if (bullets[i].bullet_alive() == 0)
			{
				bullets[i].setAlive(false);
			}
		}
	}
}

void EnemyBulletManager::update(float dt)
{
	// call update on all ALIVE balls
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{

			bullets[i].update(dt);
		}
	}
	deathCheck();
}

void EnemyBulletManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			window->draw(bullets[i]);
		}
	}
}