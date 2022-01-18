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
class Options
{
public:
	Options(sf::RenderWindow* hwnd, Input* in);
	~Options();

	void handleInput(float dt);
	void update(float dt);
	void render();
	int state;
private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	sf::RenderWindow* window;
	sf::Texture Arrow;
	sf::Texture background;
	Background Background;
	Button arrow;
	Input* input;
	State s;
	AudioManager* audio;
};

