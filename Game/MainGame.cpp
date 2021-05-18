#include "MainGame.hpp"
#include <iostream>

void MainGame::start(){
     init();
     gameloop();
     cleanUp();
}

void MainGame::init(){
	initSharedMemory();
	initFade();
     window.create(sf::VideoMode(memory.windowWidth, memory.windowHeight), "TapAlong", sf::Style::Titlebar | sf::Style::Close);
     window.setVerticalSyncEnabled(true);
	window.setPosition(sf::Vector2i(0, 0));
     game.init(memory);
     menu.init(memory);
     select.init(memory);
	mainClock.restart();
}

void MainGame::initFade(){
	fade.setPosition(0, 0);
	fade.setSize(sf::Vector2f(memory.windowWidth, memory.windowHeight));
	fade.setFillColor(sf::Color(0, 0, 0, 255 * memory.fadeAlpha));
}

void MainGame::gameloop(){
     while(window.isOpen()){
          window.clear(sf::Color(23, 23, 56));
          manager.processInput(window);
		float deltaTime = mainClock.restart().asSeconds();

          switch(state){
               case GameState::MENU:
                    menu.update(manager, memory, deltaTime);
                    menu.render(window);
               break;
               case GameState::SONG_SELECT:
                    select.update(manager, deltaTime);
                    select.render(window);
               break;
               case GameState::GAME:
                    game.update(manager, deltaTime);
                    game.render(window);
               break;
          }

		// Update fade
		memory.fadeAlpha += (memory.targetAlpha - memory.fadeAlpha) * 5.0f * deltaTime;
		fade.setFillColor(sf::Color(0, 0, 0, 255 * memory.fadeAlpha));
		if(memory.fadeAlpha >= 0.99f){
			state = memory.targetState;
			memory.targetAlpha = 0.0f;
		}
		window.draw(fade);
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
