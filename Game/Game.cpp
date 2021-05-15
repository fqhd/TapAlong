#include "Game.hpp"

void Game::init(const SharedMemory& memory){
     button.init(100, 100, 200, 40, "BHAAAAIIIE", memory.font);
	initBackground(memory);
}

void Game::update(InputManager& manager){
     button.update(manager);
}

void Game::render(sf::RenderWindow& window){
	window.draw(background); // Background

	// Entities/Particles

	// UI
	button.render(window);
}

void Game::cleanUp(){

}

void Game::initBackground(const SharedMemory& memory){
	background.setFillColor(sf::Color(23, 23, 56));
	background.setSize(sf::Vector2f(memory.windowWidth, memory.windowHeight));
	background.setPosition(0, 0);
}
