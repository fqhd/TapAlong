#ifndef SONG_SELECT_H
#define SONG_SELECT_H

#include "SharedMemory.hpp"
#include "Engine/InputManager.hpp"

struct SongSelect {

     void init(const SharedMemory& memory);
     void update(InputManager& manager, float deltaTime);
     void render(sf::RenderWindow& window);
     void cleanUp();
	void loadSongs();

	std::vector<sf::Texture> textures;
	std::vector<Button> buttons;


};

#endif
