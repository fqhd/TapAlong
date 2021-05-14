#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>

struct InputManager {

     void processInput(sf::RenderWindow& window);

     bool isKeyPressed(unsigned int keyID);
     bool isKeyReleased(unsigned int keyID);
     bool isKeyDown(unsigned int keyID);

     bool wasKeyDown(unsigned int keyID);
     void keyPressed(unsigned int keyID);
     void keyReleased(unsigned int keyID);

     sf::Event e;
     std::unordered_map<unsigned int, bool> keymap;
     std::unordered_map<unsigned int, bool> previousKeymap;

};


#endif
