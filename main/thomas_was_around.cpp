#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

int main()
{
	b2World world(b2Vec2(0.0f, 9.81f)); // initialise gravité
	sf::RenderWindow window(sf::VideoMode(800.0f, 600.0f), "Thomas_was_around");
}