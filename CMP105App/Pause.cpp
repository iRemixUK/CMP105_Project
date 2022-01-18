#include "Pause.h"
Pause::Pause(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;


	// Background
	background.loadFromFile("gfx/Pause.png");
	Background.setTexture(&background);
	Background.setWindow(window);

	state = 0;
}

Pause::~Pause()
{

}

void Pause::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		_Exit(1);
	}
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		state = 1;
	}
}

void Pause::update(float dt)
{

}

void Pause::render()
{
	beginDraw();
	window->draw(Background);
	window->draw(arrow);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Pause::beginDraw()
{
	window->clear(sf::Color(255, 255, 255));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Pause::endDraw()
{
	window->display();
}