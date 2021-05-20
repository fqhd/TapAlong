#include "Button.hpp"
#include "Utils.hpp"
#include <iostream>


void Button::init(unsigned int x, unsigned int y, unsigned int w, unsigned int h, const std::string& string, const sf::Font& font, bool textured){

	isTextured = textured;
	body.setSize(sf::Vector2f(w, h));
	body.setPosition(x, y);
	body.setFillColor(sf::Color(156, 236, 91));

     shadow.setSize(sf::Vector2f(w, h));
     shadow.setPosition(x + 16, y + 16);
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

	originalSize = body.getGlobalBounds();
	targetSize = body.getGlobalBounds();

}

void Button::update(InputManager& manager, float deltaTime){
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	if(isTextured){
		body.setFillColor(sf::Color::White);
	}else{
		body.setFillColor(sf::Color(156, 236, 91));
	}

	// Calculating target sizes
	if(body.getGlobalBounds().contains(mousePos.x, mousePos.y)){
		targetSize = sf::FloatRect(originalSize.left - 10, originalSize.top - 10, originalSize.width + 20, originalSize.height + 20);
		if(isTextured){
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				body.setFillColor(Utils::mul(sf::Color::White, 0.8f));
			}
		}else{
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				body.setFillColor(sf::Color(126, 206, 61));
			}
		}
		if(manager.isKeyPressed(sf::Mouse::Left)){
			isPressed = true;
		}else{
			isPressed = false;
		}
	}else{
		targetSize = originalSize;
	}

	// Calculating animation delta
	sf::FloatRect currentPosition = body.getGlobalBounds();
	sf::FloatRect deltaPosition = Utils::sub(targetSize, currentPosition);
	sf::FloatRect smoothMovePos = Utils::add(currentPosition, Utils::mul(deltaPosition, 16.0f * deltaTime));

	// Positioning body based on calculated delta
	body.setPosition(smoothMovePos.left, smoothMovePos.top);
	body.setSize(sf::Vector2f(smoothMovePos.width, smoothMovePos.height));

	// Positioning Shadow if the button hasn't been pressed
	shadow.setPosition(smoothMovePos.left + 16, smoothMovePos.top + 16);
	shadow.setSize(sf::Vector2f(smoothMovePos.width, smoothMovePos.height));


}

void Button::render(sf::RenderWindow& window){
     window.draw(shadow);
	window.draw(body);
	window.draw(text);
}
