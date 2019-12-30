#include "Test.h"
#include <SFML/Graphics.hpp>

void Test::instructions() {
	cout << "This is test function to test the virtual function" << endl;
}

void Test::testPacMan() {
	sf::RenderWindow window(sf::VideoMode(150, 150), "Test PacMan");
	PacMan testPac(string("pacman.png"), 0.f, 0.f);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(testPac);
		window.display();
	}
}

void Test::testEnemy() {
	sf::RenderWindow window(sf::VideoMode(150, 150), "Test PacMan");
	Enemy testEne(string("third.png"), 0.f, 0.f);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(testEne);
		window.display();
	}
}