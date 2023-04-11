#pragma once
#include<iostream>
#include <cstdio>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include <cmath>
#include <vector>

/* 
*  Class that act as the game engine
*  Wrapper class
*/

class Game
{
private:
	// variables
	//window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	// game objects
	// - table elements
	 
	// main part of table
	sf::RectangleShape table;
	// holes
	sf::CircleShape hole1;
	sf::CircleShape hole2;
	sf::CircleShape hole3;
	sf::CircleShape hole4;
	sf::CircleShape hole5;
	sf::CircleShape hole6;

	// private functions
	void initVariables();
	void initWindow();
	void initTable();

public:
	// constructors / destructors
	Game();
	virtual ~Game();
	// accessors
	const bool running() const;
	// functions
	void pollEvents();
	void update();
	void render();
};

