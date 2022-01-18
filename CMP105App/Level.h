#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/Collision.h"
#include "Background.h"
#include "Player.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include <string>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();
	int return_score();
	void reset();
	int state;

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	AudioManager* audio;
	Player player;
	BulletManager bullets;
	EnemyManager enemy;
	Background Background;
	sf::Font font;
	sf::Text health;
	sf::Text h;
	sf::Text score;
	sf::Text s;
	sf::Texture texture;
	sf::Texture background;
	sf::Vector2f direction;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Sound background_audio;
	sf::SoundBuffer Audio;
};