#ifndef MAIN_GAME
#define MAIN_GAME

#include "Engine/InputManager.hpp"
#include "Game/Game.hpp"
#include "Game/MainMenu.hpp"
#include "Game/SongSelect.hpp"
#include "Game/GameState.hpp"


struct MainGame {

     void start();

     void init();
     void gameloop();
     void cleanUp();

     // SFML Objects
     sf::RenderWindow window;

     // Engine Objects
     GameState state = GameState::MENU;
     InputManager manager;
     Game game;
     MainMenu menu;
     SongSelect select;

};

#endif
