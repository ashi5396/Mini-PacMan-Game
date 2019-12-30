#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::string;

class PacMan: public sf::Sprite {
	public:
		PacMan(string &fileName , float a, float b) {
			pac.loadFromFile(fileName);
			this->setTexture(pac);
			this->setPosition(a, b);
		}

	private :
		sf::Texture pac;
};