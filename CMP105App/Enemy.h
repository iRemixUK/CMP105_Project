#pragma once
#include "Framework/GameObject.h"
#include "Player.h"
#include "Framework/Animation.h"

class Enemy :
	public GameObject
{
public:
	Enemy();
	~Enemy();
	int Get_Health();
	void Set_Health();
	void update(float dt, int p, int d);
	void CollisionResponse();
	void render(sf::RenderWindow* window);

private:
	int health;
	int distance;
	Animation idle;
	Animation hit1;
	Animation hit2;
	Animation* currentAnimation;
};

