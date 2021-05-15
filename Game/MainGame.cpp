#include "MainGame.hpp"
#include <iostream>

void MainGame::start(){
     init();
     gameloop();
     cleanUp();
}

void MainGame::init(){
	initSharedMemory();
     window.create(sf::VideoMode(memory.windowWidth, memory.windowHeight), "TapAlong", sf::Style::Default);
     window.setVerticalSyncEnabled(true);
     game.init(memory);
     menu.init();
     select.init();
}

void MainGame::gameloop(){
     while(window.isOpen()){
          window.clear();
          manager.processInput(window);

          switch(state){
               case GameState::MENU:
                    menu.update();
                    menu.render();
               break;
               case GameState::SONG_SELECT:
                    select.update();
                    select.render();
               break;
               case GameState::GAME:
                    game.update(manager);
                    game.render(window);
               break;
          }

          window.display();
     }
}

void MainGame::cleanUp(){
     game.cleanUp();
     menu.cleanUp();
     select.cleanUp();
}

void MainGame::initSharedMemory(){
     memory.font.loadFromFile("res/fonts/berlin.ttf");
}
