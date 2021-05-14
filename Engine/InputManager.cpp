#include "InputManager.hpp"

void InputManager::processInput(sf::RenderWindow& window){
     previousKeymap = keymap;
     while(window.pollEvent(e)) {
          if(e.type == sf::Event::Closed) {
               window.close();
          } else if (e.type == sf::Event::KeyPressed) {
               keyPressed(e.key.code);
          } else if (e.type == sf::Event::KeyReleased) {
               keyReleased(e.key.code);
          }
     }
}

void InputManager::keyPressed(unsigned int keyID){
     keymap[keyID] = true;
}

void InputManager::keyReleased(unsigned int keyID){
     keymap[keyID] = false;
}

bool InputManager::isKeyDown(unsigned int keyID){
     auto it = keymap.find(keyID);
     if(it != keymap.end()){
          return it->second;
     }
     return false;
}

bool InputManager::wasKeyDown(unsigned int keyID){
     auto it = previousKeymap.find(keyID);
     if(it != previousKeymap.end()){
          return it->second;
     }
     return false;
}

bool InputManager::isKeyPressed(unsigned int keyID){
     return (isKeyDown(keyID) && !wasKeyDown(keyID));
}

bool InputManager::isKeyReleased(unsigned int keyID){
     return (!isKeyDown(keyID) && wasKeyDown(keyID));
}
