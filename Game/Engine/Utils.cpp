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

sf::Color Utils::mul(const sf::Color& color, float scalar){
	sf::Color result;

	result.r = color.r * scalar;
	result.g = color.g * scalar;
	result.b = color.b * scalar;

	return result;
}


sf::FloatRect Utils::mul(const sf::FloatRect& a, float scalar){
	sf::FloatRect result;

	result.left = a.left * scalar;
	result.top = a.top * scalar;
	result.width = a.width * scalar;
	result.height = a.height * scalar;

	return result;
}

sf::FloatRect Utils::mul(const sf::FloatRect& a, const sf::FloatRect& b){
	sf::FloatRect result;

	result.left = a.left * b.left;
	result.top = a.top * b.top;
	result.width = a.width * b.width;
	result.height = a.height * b.height;

	return result;
}

sf::FloatRect Utils::add(const sf::FloatRect& a, float scalar){
	sf::FloatRect result;

	result.left = a.left + scalar;
	result.top = a.top + scalar;
	result.left = a.width + scalar;
	result.height = a.height + scalar;

	return result;
}

sf::FloatRect Utils::add(const sf::FloatRect& a, const sf::FloatRect& b){
	sf::FloatRect result;

	result.left = a.left + b.left;
	result.top = a.top + b.top;
	result.width = a.width + b.width;
	result.height = a.height + b.height;

	return result;
}

sf::FloatRect Utils::sub(const sf::FloatRect& a, float scalar){
	sf::FloatRect result;

	result.left = a.left - scalar;
	result.top = a.top - scalar;
	result.left = a.width - scalar;
	result.height = a.height - scalar;

	return result;
}

sf::FloatRect Utils::sub(const sf::FloatRect& a, const sf::FloatRect& b){
	sf::FloatRect result;

	result.left = a.left - b.left;
	result.top = a.top - b.top;
	result.width = a.width - b.width;
	result.height = a.height - b.height;

	return result;
}
