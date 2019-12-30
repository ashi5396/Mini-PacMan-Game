#pragma once
#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape
{
public:
	Ball(float radius, const sf::Color &c,
		sf::Vector2f &pos) : sf::CircleShape(radius)
	{
		this->setFillColor(c);
		this->setPosition(pos);
	}
};