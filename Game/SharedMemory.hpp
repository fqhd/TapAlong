#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <SFML/Graphics.hpp>
#include "GameState.hpp"

struct SharedMemory {

	unsigned int windowWidth = 1280;
	unsigned int windowHeight = 720;
     sf::Font font;
	GameState targetState = GameState::MENU;
	float fadeAlpha = 1.0f;
	float targetAlpha = 0.0f;

};

#endif
