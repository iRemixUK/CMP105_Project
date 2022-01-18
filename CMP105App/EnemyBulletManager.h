#pragma once
#include "Bullet.h"
#include <math.h>
#include <vector>
#include <iostream>
#include "Framework/Vector.h"
#include "Framework/Input.h"
#include "Framework/GameObject.h"
class EnemyBulletManager :
	public GameObject
{
public:
	EnemyBulletManager();
	~EnemyBulletManager();
	void spawn(float posx, float posy);
	void handleInput(int posx, int posy);
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

private:
	std::vector<Bullet> bullets;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	sf::Vector2f target;
	sf::Vector2f direction;
};


