#include "MainGame.hpp"
#include <iostream>

void MainGame::start(){
     init();
     gameloop();
     cleanUp();
}

void MainGame::init(){
	initSharedMemory();
     window.create(sf::VideoMode(memory.windowWidth, memory.windowHeight), "TapAlong", sf::Style::Titlebar | sf::Style::Close);
     window.setVerticalSyncEnabled(true);
	window.setPosition(sf::Vector2i(0, 0));
     game.init(memory);
     menu.init();
     select.init();
	mainClock.restart();
}

void MainGame::gameloop(){
     while(window.isOpen()){
          window.clear();
          manager.processInput(window);
		float deltaTime = mainClock.restart().asSeconds();

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
                    game.update(manager, deltaTime);
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
