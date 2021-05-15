#include "Utils.hpp"
#include <cmath>

sf::FloatRect Utils::centerRect(const sf::FloatRect& a, const sf::FloatRect& b){
	sf::FloatRect result;

	float deltaW = b.width - a.width;
	float deltaH = b.height - a.height;

	result.width = a.width;
	result.height = a.height;
	result.left = b.left + deltaW/2;
	result.top = b.top + deltaH/2;

	return result;
}
