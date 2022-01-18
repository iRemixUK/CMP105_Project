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
class Menu
{
public:
	Menu(sf::RenderWindow* hwnd, Input* in);
	~Menu();

	void handleInput(float dt);
	void update(float dt);
	void render();
	int state;

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for menu class.
	int choice;
	int s;
	sf::RenderWindow* window;
	sf::Texture Start;
	sf::Texture Options;
	sf::Texture Exit;
	sf::Texture background;
	sf::Texture Arrow;
	Background Background;
	Button start;
	Button options;
	Button exit;
	Button arrow;
	Input* input;
	AudioManager* audio;
};

