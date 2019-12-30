#pragma once
#include <SFML/Graphics.hpp>
#include "pacman.h"
#include "Enemy.h"
#include "Ball.h"
#include "Rectangle.h"

class Game {
	private:
		sf::RenderWindow *window;
	public:
		Game();
		void playGame();
		~Game();
};