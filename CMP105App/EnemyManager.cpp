#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	texture.loadFromFile("gfx/enemy.png");
	texture2.loadFromFile("gfx/Enemy_Bullet.png");
	
	srand(time(0)); // Setting this here so the rand function will work properly when the object is initialised

	for (int i = 0; i < 4; i++)
	{
		enemy.push_back(Enemy());
		enemy[i].setAlive(false);
		enemy[i].setTexture(&texture);
		enemy[i].setSize(sf::Vector2f(100, 100));
		enemy[i].setCollisionBox(sf::FloatRect(0, 0, 100, 100));
		bullet.push_back(Bullet());
		bullet[i].setAlive(false);
		bullet[i].setTexture(&texture2);
		bullet[i].setSize(sf::Vector2f(50, 50));
		bullet[i].setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	}
}


EnemyManager::~EnemyManager()
{

}
void EnemyManager::handleInput(int posx, int posy)
{
	target = sf::Vector2f(posx, posy);
}
void EnemyManager::update(float dt, int d)
{
	// call update on all ALIVE enemies
	for (int i = 0; i < 4; i++)
	{
		if (enemy[i].isAlive())
		{
			bullet[i].update(dt);
			enemy[i].update(dt, enemy[i].getPosition().x, d);
		}
	}
	deathCheck();
}

void EnemyManager::spawn(float dt)
{
// Spawn new ball
// Find a dead enemy, make alive and move to spawn point

	sf::Vector2u WinSize = window->getSize();

	for (int i = 0; i < 4; i++)
	{
		if (!enemy[i].isAlive())
		{
			sf::Vector2f ObjectSize = enemy[i].getSize();
			spawnPoint = sf::Vector2f(rand() % WinSize.x + 1, rand() % WinSize.y + 1);
			enemy[i].setAlive(true);
			enemy[i].setPosition(spawnPoint);

			if (enemy[i].getPosition().y > WinSize.y - ObjectSize.y)
			{
				enemy[i].setPosition(getPosition().x, WinSize.y - ObjectSize.y);
			}

			if (enemy[i].getPosition().x > WinSize.y - ObjectSize.y)
			{
				setPosition(WinSize.x - ObjectSize.x, enemy[i].getPosition().y);
			}

			if (enemy[i].getPosition().y < 0)
			{
				setPosition(getPosition().x, 0);
			}

			if (enemy[i].getPosition().x < 0)
			{
				setPosition(0, getPosition().y);
			}
			
			enemy[i].Set_Health();
		}

		if (!bullet[i].isAlive())
		{
			
			bullet[i].setAlive(true);
			bullet[i].setPosition(enemy[i].getPosition().x, enemy[i].getPosition().y);
			direction = target - spawnPoint;
			direction = Vector::normalise(direction);
			bullet[i].setVelocity(200 * direction.x, 200 * direction.y);
		}
	}
}
void EnemyManager::deathCheck()
{
	for (int i = 0; i < 4; i++)
	{
		if (enemy[i].isAlive())
		{
			if (enemy[i].Get_Health() == 0)
			{
				enemy[i].setAlive(false);
			}
		}
		
		if (bullet[i].isAlive())
		{
			if (bullet[i].getPosition().x < 0 - bullet[i].getSize().x)
			{
				bullet[i].setAlive(false);
			}
			if (bullet[i].getPosition().x > 1200)
			{
				bullet[i].setAlive(false);
			}
			if (bullet[i].getPosition().y < 0 - bullet[i].getSize().y)
			{
				bullet[i].setAlive(false);
			}
			if (bullet[i].getPosition().y > 675)
			{
				bullet[i].setAlive(false);
			}
		}
		
	}
}

void EnemyManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < 4; i++)
	{
		if (enemy[i].isAlive())
		{
			window->draw(bullet[i]);
			window->draw(enemy[i]);
		}
	}
}