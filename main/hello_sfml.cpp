#include <SFML/Main.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "WT Window");
	sf::Sprite spriteTest;
	sf::Texture textureTest;

	if (!textureTest.loadFromFile("data/pokemon.png"))
	{
		return EXIT_FAILURE;
	}
	spriteTest.setTexture(textureTest);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if ((event.type == sf::Event::KeyPressed) || (event.type == sf::Event::Closed))
                window.close();
        }

		window.clear(sf::Color::Blue);
		window.draw(spriteTest);
		window.display();
    }
    return EXIT_SUCCESS;
}