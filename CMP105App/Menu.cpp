#include "Menu.h"
using namespace std;
Menu::Menu(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// Start button
	Start.loadFromFile("gfx/start.png");
	start.setTexture(&Start);
	start.setPosition(500, 315);
	start.setSize(sf::Vector2f(150, 100));
	
	// Option button
	Options.loadFromFile("gfx/options.png");
	options.setTexture(&Options);
	options.setPosition(490, 400);
	options.setSize(sf::Vector2f(175, 200));
	
	// Exit button
	Exit.loadFromFile("gfx/exit.png");
	exit.setTexture(&Exit);
	exit.setPosition(500, 575);
	exit.setSize(sf::Vector2f(150, 100));

	// Background
	background.loadFromFile("gfx/Main_Menu.png");
	Background.setTexture(&background);
	Background.setWindow(window);

	// Arrow
	Arrow.loadFromFile("gfx/Arrow.png");
	arrow.setTexture(&Arrow);
	arrow.setPosition(325, 250);
	arrow.setSize(sf::Vector2f(300, 300));
	
	state = 0;
	choice = 0;
}

Menu::~Menu()
{

}

void Menu::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up)) // Up
	{
		choice = choice - 1;
		input->setKeyUp(sf::Keyboard::Up);
	}

	if (input->isKeyDown(sf::Keyboard::Down)) // Down
	{
		choice = choice + 1;
		input->setKeyUp(sf::Keyboard::Down);
	}

	if (choice < 0)
	{
		choice = 0;
	}

	if (choice > 2)
	{
		choice = 2;
	}

	if (choice == 0)
	{
		arrow.setPosition(325, 250);
	}

	if (choice == 1)
	{
		arrow.setPosition(325, 375);
	}

	if (choice == 2)
	{
		arrow.setPosition(325, 510);
	}
}

void Menu::update(float dt)
{
	if (choice == 0 && input->isKeyDown(sf::Keyboard::Enter))
	{
		state = 1;
		input->setKeyUp(sf::Keyboard::Enter);
	}

	if (choice == 1 && input->isKeyDown(sf::Keyboard::Enter))
	{
		state = 2;
		input->setKeyUp(sf::Keyboard::Enter);
	
	}

	if (choice == 2 && input->isKeyDown(sf::Keyboard::Enter))
	{
		input->setKeyUp(sf::Keyboard::Enter);
		_Exit(1);
	}
}



void Menu::render()
{
	beginDraw();
	window->draw(Background);
	window->draw(start);
	window->draw(options);
	window->draw(exit);
	window->draw(arrow);
	endDraw();
}



// Begins rendering to the back buffer. Background colour set to white.
void Menu::beginDraw()
{
	window->clear(sf::Color(255, 255, 255));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Menu::endDraw()
{
	window->display();
}