#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Player :
	public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt);
	void update(float dt);
	void CollisionResponse();
	int Get_Score();
	void Set_Score();
	void Restart_Score();
	int Get_Health();
	void Set_Health(int a);
	float getSpeedX();
	float getSpeedY();
	
	// Set the window component
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
	//Window Component
	sf::RenderWindow* window;

private:
	Animation walk;
	Animation idle;
	Animation death;
	Animation* currentAnimation;
	float speedx;
	float speedy;
	int health;
	int score;
};

