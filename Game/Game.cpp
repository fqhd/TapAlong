#include "Game.hpp"

void Game::init(const SharedMemory& memory){


	initBackground(memory);
}

void Game::update(InputManager& manager, float deltaTime){
	
}

void Game::render(sf::RenderWindow& window){
	window.draw(background); // Background

	// Entities/Particles

	// UI

}

void Game::cleanUp(){

}

void Game::initBackground(const SharedMemory& memory){
	background.setFillColor(sf::Color(23, 23, 56));
	background.setSize(sf::Vector2f(memory.windowWidth, memory.windowHeight));
	background.setPosition(0, 0);
}
