#include <iostream>
#include <SFML/Graphics.hpp>


int main(){

     sf::RenderWindow window(sf::VideoMode(1280, 720), "TapAlong", sf::Style::Default);
     sf::Event e;

     while(window.isOpen()){
          window.clear();
          if(window.pollEvent(e)){
               if(e.type == sf::Event::Closed){
                    window.close();
               }
          }


          window.display();
     }

     window.close();


     return 0;
}
