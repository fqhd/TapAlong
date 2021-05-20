#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include "InputManager.hpp"

struct Button {

     void init(unsigned int x, unsigned int y, unsigned int w, unsigned int h, const std::string& string, const sf::Font& font, bool textured = false);
     void update(InputManager& manager, float deltaTime);
     void render(sf::RenderWindow& window);

	bool isTextured = false;
	bool isPressed = false;
     sf::FloatRect targetSize;
	sf::FloatRect originalSize;
     sf::RectangleShape body;
     sf::RectangleShape shadow;
	sf::Text text;

};

#endif
