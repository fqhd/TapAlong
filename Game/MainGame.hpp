#ifndef MAIN_GAME
#define MAIN_GAME

#include "Engine/InputManager.hpp"
#include "SharedMemory.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include "SongSelect.hpp"
#include "GameState.hpp"


struct MainGame {

     void start();

     void init();
     void gameloop();
     void cleanUp();
     void initSharedMemory();
	void initFade();

     // SFML Objects
     sf::RenderWindow window;
	sf::Clock mainClock;
	sf::RectangleShape fade;

     // Engine Objects
     GameState state = GameState::MENU;
     InputManager manager;
     Game game;
     Menu menu;
     SongSelect select;
     SharedMemory memory;

};

#endif
