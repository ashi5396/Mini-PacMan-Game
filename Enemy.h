#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::string;

class Enemy :public sf:: Sprite{
	public:
		Enemy(string &fileName, float a, float b) {
			enemy.loadFromFile(fileName);
			this->setTexture(enemy);
			this->setPosition(a, b);
		}
    private:
		sf::Texture enemy;
};