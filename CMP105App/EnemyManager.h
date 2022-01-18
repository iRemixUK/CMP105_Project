#pragma once
#include "Enemy.h"
#include "Bullet.h"
#include <math.h>
#include <vector>
#include <iostream>
#include "Framework/Vector.h"
#include "Framework/Input.h"
#include "Framework/GameObject.h"

class EnemyManager :
	public GameObject
{
public:
	EnemyManager();
	~EnemyManager();
	void spawn(float dt);
	void handleInput(int posx, int posy);
	void update(float dt, int d);
	void deathCheck();
	void render(sf::RenderWindow* window);
	std::vector<Enemy> enemy;
	std::vector<Bullet> bullet;
	
	// Set the window component
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
	//Window Component
	sf::RenderWindow* window;

private:
	sf::Vector2f target;
	sf::Vector2f direction;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	sf::Texture texture2;

};