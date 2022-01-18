#pragma once
#include <iostream>
#include "Framework/GameObject.h"
class Bullet :
	public GameObject
{
public:
	Bullet();
	~Bullet();
	int Get_Damage();
	void update(float dt) override;
	int damage;
};

