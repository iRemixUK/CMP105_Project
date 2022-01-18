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
using namespace std;
class Score
{
public:
	Score(sf::RenderWindow* hwnd, Input* in);
	~Score();
	void handleInput(float dt);
	void update(float dt, int score);
	void render();
	int state;

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();
	
	sf::Font font;
	sf::Text text;
	sf::Text text2;
	sf::Text s;
	sf::RenderWindow* window;
	sf::Texture background;
	Background Background;
	Input* input;
};

