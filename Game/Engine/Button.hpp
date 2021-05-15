#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include "InputManager.hpp"

struct Button {

     void init(unsigned int x, unsigned int y, unsigned int w, unsigned int h, const std::string& string, const sf::Font& font);
     void update(InputManager& manager);
     void render(sf::RenderWindow& window);


     sf::FloatRect targetSize;
     sf::RectangleShape body;
     sf::RectangleShape shadow;
	sf::Text text;

};

#endif