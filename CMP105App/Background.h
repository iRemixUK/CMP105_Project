#pragma once
#include "Framework/GameObject.h"
class Background :
	public GameObject
{
public:
	Background();
	~Background();

	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }

private:
	sf::RenderWindow* window;
};

