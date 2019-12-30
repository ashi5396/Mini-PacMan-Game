#include "Game.h"
#include "SFML\Audio.hpp"

Game::Game() {
	window = new sf::RenderWindow(sf::VideoMode(680, 680), "Pacman Game",sf::Style::Close);
}

Game::~Game() {
	delete window;
}

void Game::playGame() {

	//Calling constructor show images
	PacMan pac(string("pacman.png"), 0.f, 0.f);
	Enemy firstEne(string("enemy.png"), 100.f, 250.f);
	Enemy secondEne(string("secondEnemy.png"), 450.f, 450.f);
	Enemy thirdEne(string("third.png"), 350.f, 150.f);

	//create different ball objects with a specific position
	Ball sphere(10.f, sf::Color::Red, sf::Vector2f(250, 250));
	Ball secondSphere(10.f, sf::Color::Red, sf::Vector2f(250, 300));
	Ball thirdSphere(10.f, sf::Color::Red, sf::Vector2f(250, 350));
	Ball fourthSphere(10.f, sf::Color::Red, sf::Vector2f(250, 400));
	Ball fifthSphere(10.f, sf::Color::Red, sf::Vector2f(150, 350));
	Ball sixthSphere(10.f, sf::Color::Red, sf::Vector2f(100, 350));
	Ball seventhSphere(10.f, sf::Color::Red, sf::Vector2f(250, 450));
	Ball eightSphere(10.f, sf::Color::Red, sf::Vector2f(250, 500));
	Ball ninthSphere(10.f, sf::Color::Red, sf::Vector2f(350, 350));
	Ball tenthSphere(10.f, sf::Color::Red, sf::Vector2f(400, 350));

	//create rectangle objects with a specific position
	Rectangle firstRec(sf::Vector2f(25.f,25.f), sf::Color::Green, sf::Vector2f(600, 50));
	Rectangle secondRec(sf::Vector2f(25.f, 25.f), sf::Color::Green, sf::Vector2f(100,600));
	
	//variables to keep track of foods and scores
	int food = 0, score = 0;
	
	//play the music 
	sf::Music music;
	if (!music.openFromFile("song.wav")) {
		cout << "Song couldn't be found" << endl;
	}
	music.play();

	while (window->isOpen())
	{
		sf::Event eve;
		while (window->pollEvent(eve))
		{
			if (eve.type == sf::Event::Closed)
				window->close();
		}
		window->clear();
		
		//draw different objests on the window
		window->draw(pac);
		window->draw(firstEne);
		window->draw(secondEne);
		window->draw(thirdEne);

		window->draw(sphere);
		window->draw(secondSphere);
		window->draw(thirdSphere);
		window->draw(fourthSphere);
		window->draw(fifthSphere);
		window->draw(sixthSphere);
		window->draw(seventhSphere);
		window->draw(eightSphere);
		window->draw(ninthSphere);
		window->draw(tenthSphere);
		window->draw(firstRec);
		window->draw(secondRec);

		//display the window with drawn objects
		window->display();

		//if the pacman eats every food, 
		if (food == 12) {
			cout << "You Won the Game and Your Score is " << score<< endl;
			cout << endl;
			break;
		}
		   //If the pacman gets eaten by a ghost, the game will end
			if (firstEne.getGlobalBounds().intersects(pac.getGlobalBounds())) {
				cout << "Sorry the Ghost Just Ate You, So the Game is Over !!" << endl;
				cout << endl;
				pac.setColor(sf::Color::Transparent);
				break;
			}
			else if (secondEne.getGlobalBounds().intersects(pac.getGlobalBounds())) {
				cout << "Sorry the Ghost Just Ate You, So the Game is Over !!" << endl;
				cout << endl;
				pac.setColor(sf::Color::Transparent);
				break;
			}
			else if (thirdEne.getGlobalBounds().intersects(pac.getGlobalBounds())) {
				cout << "Sorry the Ghost Just Ate You, So the Game is Over !!" << endl;
				cout << endl;
				pac.setColor(sf::Color::Transparent);
				break;
			}
			else {
				//While the pacman is moving, ghosts will be moving as well
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					pac.move(sf::Vector2f(0, -1));
					firstEne.move(sf::Vector2f(0.1f, 0));
					secondEne.move(sf::Vector2f(-1,0));
					thirdEne.move(sf::Vector2f(0, -1));
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					pac.move(sf::Vector2f(0, 1));
					firstEne.move(sf::Vector2f(0.1f, 0));
					secondEne.move(sf::Vector2f(-1, 0));
					thirdEne.move(sf::Vector2f(0, -1));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					pac.move(sf::Vector2f(1, 0));
					firstEne.move(sf::Vector2f(0.1f, 0));
					secondEne.move(sf::Vector2f(-1, 0));
					thirdEne.move(sf::Vector2f(0, -1));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					pac.move(sf::Vector2f(-1, 0));
					firstEne.move(sf::Vector2f(0.1f, 0));
					secondEne.move(sf::Vector2f(-1, 0));
					thirdEne.move(sf::Vector2f(0, -1));
				}
				//Keep track of the packman's food and give scores 
				if (pac.getGlobalBounds().intersects(sphere.getGlobalBounds())) {
					sphere.setFillColor(sf::Color::Transparent);
					sphere.setPosition(0, 0);
					food++;
					score++;
				}
				else if (pac.getGlobalBounds().intersects(secondSphere.getGlobalBounds())) {
					secondSphere.setFillColor(sf::Color::Transparent);
					secondSphere.setPosition(0, 0);
					food++;
					score++;
				}
				else if (pac.getGlobalBounds().intersects(thirdSphere.getGlobalBounds())) {
					thirdSphere.setFillColor(sf::Color::Transparent);
					thirdSphere.setPosition(0, 0);
					food++;
					score++;
				}
				else if (pac.getGlobalBounds().intersects(fourthSphere.getGlobalBounds())) {
					fourthSphere.setFillColor(sf::Color::Transparent);
					fourthSphere.setPosition(0, 0);
					food++;
					score++;
				}
				else if (pac.getGlobalBounds().intersects(fifthSphere.getGlobalBounds())) {
					fifthSphere.setFillColor(sf::Color::Transparent);
					fifthSphere.setPosition(0, 0);
					food++;
					score++;
				}
				else if (pac.getGlobalBounds().intersects(sixthSphere.getGlobalBounds())) {
					sixthSphere.setFillColor(sf::Color::Transparent);
					sixthSphere.setPosition(0, 0);
					food++;
					score++;
				}
				else if (pac.getGlobalBounds().intersects(seventhSphere.getGlobalBounds())) {
					seventhSphere.setFillColor(sf::Color::Transparent);
					seventhSphere.setPosition(0, 0);
					food++;
					score++;
				}
				else if (pac.getGlobalBounds().intersects(eightSphere.getGlobalBounds())) {
					eightSphere.setFillColor(sf::Color::Transparent);
					eightSphere.setPosition(0, 0);
					food++;
					score++;
				}
				else if (pac.getGlobalBounds().intersects(ninthSphere.getGlobalBounds())) {
					ninthSphere.setFillColor(sf::Color::Transparent);
					ninthSphere.setPosition(0, 0);
					food++;
					score++;
				}
				else if (pac.getGlobalBounds().intersects(tenthSphere.getGlobalBounds())) {
					tenthSphere.setFillColor(sf::Color::Transparent);
					tenthSphere.setPosition(0, 0);
					food++;
					score++;
				}
				else if (pac.getGlobalBounds().intersects(firstRec.getGlobalBounds())) {
					firstRec.setFillColor(sf::Color::Transparent);
					firstRec.setPosition(0,0);
					food++;
					score+=5;
				}
				else if (pac.getGlobalBounds().intersects(secondRec.getGlobalBounds())) {
					secondRec.setFillColor(sf::Color::Transparent);
					secondRec.setPosition(0,0);
					food++;
					score += 5;
				}
			}
	}
}