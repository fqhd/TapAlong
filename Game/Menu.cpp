#include "Menu.hpp"
#include <iostream>

void Menu::init(const SharedMemory& memory){
	play.init(512, 200 + 80, 256, 52, "PLAY", memory.font);
	settings.init(512, 200 + 80*2, 256, 52, "SETTINGS", memory.font);
	instructions.init(512, 200 + 80*3, 256, 52, "INSTRUCTIONS", memory.font);
	exit.init(512, 200 + 80*4, 256, 52, "EXIT", memory.font);
}

void Menu::update(InputManager& manager, SharedMemory& memory, float deltaTime){
	play.update(manager, deltaTime);
	settings.update(manager, deltaTime);
	instructions.update(manager, deltaTime);
	exit.update(manager, deltaTime);

	if(play.isPressed){
		memory.targetState = GameState::SONG_SELECT;
		memory.targetAlpha = 1.0f;
	}
	if(settings.isPressed){
		memory.targetState = GameState::SONG_SELECT;
		memory.targetAlpha = 1.0f;
	}
	if(instructions.isPressed){
		memory.targetState = GameState::SONG_SELECT;
		memory.targetAlpha = 1.0f;
	}
	if(exit.isPressed){
		memory.targetState = GameState::EXIT;
		memory.targetAlpha = 1.0f;
	}


}

void Menu::render(sf::RenderWindow& window){
	play.render(window);
	settings.render(window);
	instructions.render(window);
	exit.render(window);
}

void Menu::cleanUp(){

}
