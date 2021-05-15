#include "Button.hpp"
#include "Utils.hpp"
#include <iostream>


void Button::init(unsigned int x, unsigned int y, unsigned int w, unsigned int h, const std::string& string, const sf::Font& font){

	body.setSize(sf::Vector2f(w, h));
	body.setPosition(x - 16, y - 16);
	body.setFillColor(sf::Color(156, 236, 91));

     shadow.setSize(sf::Vector2f(w, h));
     shadow.setPosition(x, y);
     shadow.setFillColor(sf::Color(23 * 0.8, 23 * 0.8, 56 * 0.8));

	// Text
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setString(string);
	text.setPosition(0, 0);
	text.setOrigin(text.getLocalBounds().left, text.getLocalBounds().top);

	sf::FloatRect centeredRect = Utils::centerRect(text.getLocalBounds(), body.getGlobalBounds());
	text.setPosition(centeredRect.left, centeredRect.top);


}

void Button::update(InputManager& manager){

}

void Button::render(sf::RenderWindow& window){
     window.draw(shadow);
	window.draw(body);
	window.draw(text);
}
