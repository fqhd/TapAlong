#include "SongSelect.hpp"

void SongSelect::init(const SharedMemory& memory){
	playButton.init(memory.windowWidth - 144, memory.windowHeight - 64, 128, 48, "PLAY", memory.font);
	backButton.init(16, memory.windowHeight - 64, 128, 48, "BACK", memory.font);

	songs.push_back(new Song(memory, "The Final Countdown", 0));
	songs.push_back(new Song(memory, "The Final Countdown", 1));
	songs.push_back(new Song(memory, "The Final Countdown", 2));
	songs.push_back(new Song(memory, "The Final Countdown", 3));

	songs.push_back(new Song(memory, "The Final Countdown", 4));
	songs.push_back(new Song(memory, "The Final Countdown", 5));
	songs.push_back(new Song(memory, "The Final Countdown", 6));
	songs.push_back(new Song(memory, "The Final Countdown", 7));

	songs.push_back(new Song(memory, "The Final Countdown", 8));
	songs.push_back(new Song(memory, "The Final Countdown", 9));
	songs.push_back(new Song(memory, "The Final Countdown", 10));
	songs.push_back(new Song(memory, "The Final Countdown", 11));

}

void SongSelect::update(InputManager& manager, SharedMemory& memory, float deltaTime){
	playButton.update(manager, deltaTime);
	backButton.update(manager, deltaTime);
	if(backButton.isPressed){
		memory.targetAlpha = 1.0f;
		memory.targetState = GameState::MENU;
	}
	if(playButton.isPressed){
		memory.targetAlpha = 1.0f;
		memory.targetState = GameState::GAME;
	}

	// Update songs
	for(auto& i : songs){
		i->button.update(manager, deltaTime);
	}

}

void SongSelect::render(sf::RenderWindow& window){
	playButton.render(window);
	backButton.render(window);
	for(auto& i : songs){
		i->button.render(window);
	}
}

void SongSelect::cleanUp(){
	for(auto& i : songs){
		//delete i;
	}
}

void SongSelect::loadSongs(){
	// Load songs

}
