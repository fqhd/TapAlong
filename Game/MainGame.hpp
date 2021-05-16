#ifndef MAIN_GAME
#define MAIN_GAME

#include "Engine/InputManager.hpp"
#include "SharedMemory.hpp"
#include "Game.hpp"
#include "MainMenu.hpp"
#include "SongSelect.hpp"
#include "GameState.hpp"


struct MainGame {

     void start();

     void init();
     void gameloop();
     void cleanUp();
     void initSharedMemory();

     // SFML Objects
     sf::RenderWindow window;
	sf::Clock mainClock;

     // Engine Objects
     GameState state = GameState::GAME;
     InputManager manager;
     Game game;
     MainMenu menu;
     SongSelect select;
     SharedMemory memory;

};

#endif
