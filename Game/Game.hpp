#ifndef GAME_H
#define GAME_H

#include "Engine/Button.hpp"
#include "SharedMemory.hpp"

struct Game {

     void init(const SharedMemory& memory);
     void update(InputManager& manager, float deltaTime);
     void render(sf::RenderWindow& window);
     void cleanUp();
	void initBackground(const SharedMemory& memory);

	sf::RectangleShape background;

};

#endif
