#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>

namespace Utils {

	sf::FloatRect centerRect(const sf::FloatRect& a, const sf::FloatRect& b);
	sf::FloatRect mul(const sf::FloatRect& a, float scalar);
	sf::FloatRect mul(const sf::FloatRect& a, const sf::FloatRect& b);
	sf::FloatRect add(const sf::FloatRect& a, float scalar);
	sf::FloatRect add(const sf::FloatRect& a, const sf::FloatRect& b);
	sf::FloatRect sub(const sf::FloatRect& a, float scalar);
	sf::FloatRect sub(const sf::FloatRect& a, const sf::FloatRect& b);



}

#endif
