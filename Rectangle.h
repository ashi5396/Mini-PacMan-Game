#pragma once
#include <SFML/Graphics.hpp>

class Rectangle : public sf::RectangleShape
{
public:
	Rectangle(sf::Vector2f &size, const sf::Color &myColor,
		sf::Vector2f &pos) : sf::RectangleShape(size)
	{
		this->setFillColor(myColor);
		this->setPosition(pos);
	}
};