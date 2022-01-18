#include "Options.h"
using namespace std;

Options::Options(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;


	// Background
	background.loadFromFile("gfx/Option_Screen.png");
	Background.setTexture(&background);
	Background.setWindow(window);

	// Arrow
	Arrow.loadFromFile("gfx/Arrow.png");
	arrow.setTexture(&Arrow);
	arrow.setPosition(325, 545);
	arrow.setSize(sf::Vector2f(250, 250));
	
	state = 1;
}

Options::~Options()
{

}

void Options::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		input->setKeyUp(sf::Keyboard::Enter);
		state = 0;
	}
}

void Options::update(float dt)
{
	
}

void Options::render()
{
	beginDraw();
	window->draw(Background);
	window->draw(arrow);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Options::beginDraw()
{
	window->clear(sf::Color(255, 255, 255));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Options::endDraw()
{
	window->display();
}