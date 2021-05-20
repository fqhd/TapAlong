#ifndef SONG_H
#define SONG_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Engine/Button.hpp"
#include "SharedMemory.hpp"

struct Song {

	Song(const SharedMemory& memory, const std::string& n, unsigned int songIndex);
	void loadSong(const SharedMemory& memory, const std::string& n, unsigned int songIndex);

	sf::Texture texture;
	Button button;
	std::string name;

};

#endif
