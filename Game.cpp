#include "Game.h"
// private functions

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 1000;

	this->window = new sf::RenderWindow(this->videoMode, "Bilard", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initTable()
{
	// draw main part of table
	this->table.setPosition(200.f, 100.f);
	this->table.setSize(sf::Vector2f(570.f, 285.f));
	this->table.setScale(sf::Vector2f(1.0f, 1.0f));
	this->table.setFillColor(sf::Color(0,153,3));
	this->table.setOutlineColor(sf::Color(102,51,0));
	this->table.setOutlineThickness(20.f);

	// draw holes
	this->hole1.setPosition(187.f, 87.f);
	this->hole1.setRadius(15.f);
	this->hole1.setFillColor(sf::Color::Black);

	this->hole2.setPosition(471.f, 87.f);
	this->hole2.setRadius(15.f);
	this->hole2.setFillColor(sf::Color::Black);

	this->hole3.setPosition(755.f, 87.f);
	this->hole3.setRadius(15.f);
	this->hole3.setFillColor(sf::Color::Black);

	this->hole4.setPosition(187.f, 366.f);
	this->hole4.setRadius(15.f);
	this->hole4.setFillColor(sf::Color::Black);
	
	this->hole5.setPosition(471.f, 366.f);
	this->hole5.setRadius(15.f);
	this->hole5.setFillColor(sf::Color::Black);

	this->hole6.setPosition(755.f, 366.f);
	this->hole6.setRadius(15.f);
	this->hole6.setFillColor(sf::Color::Black);
}

// constructors / destructors

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initTable();
}

Game::~Game()
{
	delete this->window;
}


// accessors

const bool Game::running() const
{
	return this->window->isOpen();
}

// functions

void Game::pollEvents()
{
	// event polling
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type) {
		case sf::Event::Closed:
			this->window->close();
			std::cout << "\nGame is ended by X pressing" << std::endl;
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape) {
				this->window->close();
				std::cout << "\nGame is ended by ESC pressing" << std::endl;
			}
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	/*
	    @return void 

		-clear old frame
		-render new objects
		-display frame in the window 
		renders the game objects
	*/
	this->window->clear(sf::Color::White);

	//draw game objects
	// main part of the table drawing
	this->window->draw(this->table);

	// holes drawing
	this->window->draw(this->hole1);
	this->window->draw(this->hole2);
	this->window->draw(this->hole3);
	this->window->draw(this->hole4);
	this->window->draw(this->hole5);
	this->window->draw(this->hole6);

	this->window->display();
}
