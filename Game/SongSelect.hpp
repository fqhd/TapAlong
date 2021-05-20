#ifndef SONG_SELECT_H
#define SONG_SELECT_H

#include "SharedMemory.hpp"
#include "Engine/InputManager.hpp"
#include "Engine/Button.hpp"
#include "Song.hpp"
#include <vector>

struct SongSelect {

     void init(const SharedMemory& memory);
     void update(InputManager& manager, SharedMemory& memory, float deltaTime);
     void render(sf::RenderWindow& window);
     void cleanUp();
	void loadSongs();

	Button playButton;
	Button backButton;
	std::vector<Song*> songs;



};

#endif
