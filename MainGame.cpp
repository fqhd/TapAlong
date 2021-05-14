#include "MainGame.hpp"
#include <iostream>

void MainGame::start(){
     init();
     gameloop();
     cleanUp();
}

void MainGame::init(){
     window.create(sf::VideoMode(1280, 720), "TapAlong", sf::Style::Default);
     window.setVerticalSyncEnabled(true);
     game.init();
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
                    game.update();
                    game.render();
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
