#include "Level.h"
using namespace std;
Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	// Player object
	texture.loadFromFile("gfx/Player.png");
	player.setTexture(&texture);
	player.setSize(sf::Vector2f(100, 100));
	player.setPosition(100, 310);
	player.setInput(input);
	player.setWindow(window);
	player.setCollisionBox(sf::FloatRect(0, 0, 100, 100));
	player.Set_Health(200);

	// Sound Object
	buffer.loadFromFile("sfx/Gunshot.wav");
	sound.setBuffer(buffer);

	Audio.loadFromFile("sfx/Background.wav");
	background_audio.setBuffer(Audio);
	background_audio.play();

	// Background Object 
	background.loadFromFile("gfx/Background.png");
	Background.setTexture(&background);
	Background.setWindow(window);

	// Enemy Object 
	enemy.setWindow(window);

	//Text Object
	if (!font.loadFromFile("font/Pixeled.ttf"))
	{
		cout << "Error loading text from file\n";
	}

	health.setFont(font);
	health.setCharacterSize(24);
	health.setPosition(0, 10);
	health.setFillColor(sf::Color::White);
	health.setString("Your health is:");

	score.setFont(font);
	score.setCharacterSize(24);
	score.setPosition(0, 50);
	score.setFillColor(sf::Color::White);
	score.setString("Your score is:");

	s.setFont(font);
	s.setCharacterSize(24);
	s.setPosition(300, 50);
	s.setFillColor(sf::Color::White);

	h.setFont(font);
	h.setCharacterSize(24);
	h.setPosition(300, 10);
	h.setFillColor(sf::Color::White);

	state = 1;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

	player.handleInput(dt);
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		bullets.handleInput(input->getMouseX(), input->getMouseY());
		bullets.spawn(player.getPosition().x, player.getPosition().y);
		input->setKeyUp(sf::Keyboard::Space);
		sound.play();
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		state = 3;
	}

}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
	player.move(player.getSpeedX() * dt, player.getSpeedY() * dt);
	bullets.update(dt);
	enemy.handleInput(player.getPosition().x, player.getPosition().y);
	enemy.spawn(dt);
	enemy.update(dt, player.getPosition().x);
	cout << player.Get_Health() << endl;
	for (int j = 0; j < enemy.enemy.size(); j++)
	{
		for (int i = 0; i < bullets.bullets.size(); i++)
		{
			if (bullets.bullets[i].isAlive())
			{
				if (Collision::checkBoundingBox(&enemy.enemy[j], &bullets.bullets[i]))
				{
					bullets.bullets[i].setAlive(false);
					enemy.enemy[j].CollisionResponse();
					player.Set_Score();
				}
			}

		}
	}

	for (int i = 0; i < enemy.bullet.size(); i++)
	{
		if (enemy.bullet[i].isAlive())
		{
			if (Collision::checkBoundingBox(&enemy.bullet[i], &player))
			{
				enemy.bullet[i].setAlive(false);
				player.CollisionResponse();
			}
		}
	}

	if (player.Get_Health() <= 0)
	{
		state = 4;
	}

	string health = to_string(player.Get_Health());
	h.setString(health);

	string score = to_string(player.Get_Score());
	s.setString(score);


}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(Background);
	window->draw(player);
	enemy.render(window);
	bullets.render(window);
	window->draw(health);
	window->draw(score);
	window->draw(h);
	window->draw(s);
	endDraw();
}

int Level::return_score()
{
	return player.Get_Score();
}

void Level::reset()
{
	for (int i = 0; i < 4; i++)
	{
		enemy.enemy[i].setAlive(false);
	}
	player.Restart_Score();
	player.Set_Health(200);
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(255, 255, 255));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}