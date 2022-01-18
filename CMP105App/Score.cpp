#include "Score.h"

Score::Score(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;


	// Background
	background.loadFromFile("gfx/End.png");
	Background.setTexture(&background);
	Background.setWindow(window);

	state = 0;

	if (!font.loadFromFile("font/Pixeled.ttf"))
	{
		cout << "Error loading text from file\n";
	}

	text.setFont(font);
	text.setCharacterSize(24);
	text.setPosition(400, 450);
	text.setFillColor(sf::Color::Red);
	text.setString("Your score was ");

	text2.setFont(font);
	text2.setCharacterSize(24);
	text2.setPosition(350, 480);
	text2.setFillColor(sf::Color::Red);
	text2.setString("Press enter to play again");

	s.setFont(font);
	s.setCharacterSize(24);
	s.setPosition(735, 450);
	s.setFillColor(sf::Color::Red);
}

Score::~Score()
{

}

void Score::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		_Exit(1);
	}
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		input->setKeyUp(sf::Keyboard::Enter);
		state = 1;
	}
}

void Score::update(float dt, int score)
{
	string str = to_string(score);
	s.setString(str);
}

void Score::render()
{
	beginDraw();
	window->draw(Background);
	window->draw(text);
	window->draw(text2);
	window->draw(s);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Score::beginDraw()
{
	window->clear(sf::Color(255, 255, 255));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Score::endDraw()
{
	window->display();
}