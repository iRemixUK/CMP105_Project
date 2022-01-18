#include "Splash.h"

Splash::Splash(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;

	// Background
	background.loadFromFile("gfx/Splash.png");
	Background.setTexture(&background);
	Background.setWindow(window);

	state = 0;
}

void Splash::handleInput(float dt)
{
}

void Splash::update(float dt)
{
	elapsedTime += dt;
	if (elapsedTime >= 3)
	{
		state = 1;
	}
}

void Splash::render()
{
	beginDraw();
	window->draw(Background);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Splash::beginDraw()
{
	window->clear(sf::Color(255, 255, 255));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Splash::endDraw()
{
	window->display();
}