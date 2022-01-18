#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/Collision.h"
#include "Background.h"
#include "Button.h"
#include <string>
#include <iostream>
#include <cstdlib>
class Pause
{
public:
	Pause(sf::RenderWindow* hwnd, Input* in);
	~Pause();
	void handleInput(float dt);
	void update(float dt);
	void render();
	int state;

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();
	
	sf::RenderWindow* window;
	sf::Texture background;
	Background Background;
	Button arrow;
	Input* input;
	AudioManager* audio;
};

