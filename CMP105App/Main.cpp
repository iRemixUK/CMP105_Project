// Main
// Entry point of the application.
// Handles window creation and window events.
// Contains the game loop, updates input class and contains the level objects.
// @author Paul Robertson

#include <iostream>
#include "Level.h"
#include "Menu.h"
#include "Options.h"
#include "Pause.h"
#include "Score.h"
#include "Splash.h"
#include "Framework/GameState.h"


using namespace std;


int main()
{
	//Create the window
	sf::RenderWindow window(sf::VideoMode(1200, 675), "CMP105");

	// Initialise input and level objects.
	Input input;
	Level level(&window, &input);
	Menu menu(&window, &input);
	Options option(&window, &input);
	Pause pause(&window, &input);
	Score score(&window, &input);
	Splash splash(&window, &input);




	// Game State Object
	GameState gameState;
	State s = SPLASH;
	gameState.setCurrentState(s);


	// Initialise objects for delta time
	sf::Clock clock;
	float deltaTime;
	float elapsedTime;

	// Game Loop
	while (window.isOpen())
	{
		// Handle window events.
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				window.setView(sf::View(sf::FloatRect(0.f, 0.f, (float)event.size.width, (float)event.size.height)));
				break;
			case sf::Event::KeyPressed:
				// update input class
				input.setKeyDown(event.key.code);
				break;
			case sf::Event::KeyReleased:
				//update input class
				input.setKeyUp(event.key.code);
				break;
			case sf::Event::MouseMoved:
				//update input class
				input.setMousePosition(event.mouseMove.x, event.mouseMove.y);
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//update input class
					input.setMouseLDown(true);
				}
				else if (event.mouseButton.button == sf::Mouse::Right)
				{
					input.setMouseRDown(true);
				}
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//update input class
					input.setMouseLDown(false);
				}
				else if (event.mouseButton.button == sf::Mouse::Right)
				{
					input.setMouseRDown(false);
				}
				break;
			default:
				// don't handle other events
				break;
			}
		}

		// Calculate delta time. How much time has passed 
		// since it was last calculated (in seconds) and restart the clock.
		deltaTime = clock.restart().asSeconds();

		// Call standard game loop functions (input, update and render)
		
		switch (gameState.getCurrentState())
		{
		case(State::SPLASH):
			splash.handleInput(deltaTime);
			splash.update(deltaTime);
			splash.render();

			if (splash.state == 1)
			{
				gameState.setCurrentState(MENU);
			}
			break;

		case(State::MENU):
			menu.handleInput(deltaTime);
			menu.update(deltaTime);
			menu.render();
			
			if (menu.state == 1)
			{
				gameState.setCurrentState(LEVEL);
				menu.state = 0;


			}
			
			if (menu.state == 2)
			{
				gameState.setCurrentState(OPTIONS);
				menu.state = 0;
			}

			

			break;

		case(State::LEVEL):

			level.handleInput(deltaTime);
			level.update(deltaTime);
			level.render();


			if (level.state == 1)
			{
				gameState.setCurrentState(LEVEL);
			}

			if (level.state == 3)
			{
				gameState.setCurrentState(PAUSE);
				level.state = 0;
			}

			if (level.state == 4)
			{
				gameState.setCurrentState(END);
				level.state = 0;
			}
			
			break;

		case (State::OPTIONS):
			option.handleInput(deltaTime);
			option.update(deltaTime);
			option.render();

			if (option.state == 0)
			{
				gameState.setCurrentState(MENU);
				option.state = 1;
				
			}

			if (option.state == 2)
			{
				gameState.setCurrentState(OPTIONS);
			}

			break;

		case (State::PAUSE):
			pause.handleInput(deltaTime);
			pause.update(deltaTime);
			pause.render();

			if (pause.state == 1)
			{
				gameState.setCurrentState(LEVEL);
				pause.state = 0;
			}

			break;

		case (State::END):
			score.handleInput(deltaTime);
			score.update(deltaTime, level.return_score());
			score.render();

			if (score.state == 1)
			{
				level.reset();
				gameState.setCurrentState(LEVEL);
				score.state = 0;
			}
		}
	}

}

