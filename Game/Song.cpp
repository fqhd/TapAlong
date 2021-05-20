#include "Song.hpp"

Song::Song(const SharedMemory& memory, const std::string& n, unsigned int songIndex){
	loadSong(memory, n, songIndex);
}

void Song::loadSong(const SharedMemory& memory, const std::string& n, unsigned int songIndex) {
	name = n;
	texture.loadFromFile("res/songs/" + name + "/thumbnail.jpg");

	unsigned int yIndex = songIndex / 4;
	unsigned int xIndex = songIndex % 4;

	float xPosition = 56 + xIndex * 300;
	float yPosition = 64 + yIndex * 192;

	button.init(xPosition, yPosition, 256, 128, name, memory.font, true);
	button.body.setTexture(&texture);
	button.body.setFillColor(sf::Color::White);

}
