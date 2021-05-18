#ifndef MENU_H
#define MENU_H

#include "SharedMemory.hpp"
#include "Engine/Button.hpp"

struct Menu {

     void init(const SharedMemory& memory);
     void update(InputManager& manager, SharedMemory& memory, float deltaTime);
     void render(sf::RenderWindow& window);
     void cleanUp();

	// Engine Objects
	Button play;
	Button settings;
	Button instructions;
	Button exit;


};

#endif
