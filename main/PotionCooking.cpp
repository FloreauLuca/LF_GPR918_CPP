#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <vector>
#include <iostream>

enum class WindowType {
	HOME,
	INGREDIENT,
	BAKING,
	PRESENTATION,
};

int main()
{
	b2World world(b2Vec2(0.0f, 0.0f));

	sf::RenderWindow window(sf::VideoMode(750.0f, 500.0f), "Potion Cooking");
	sf::Clock clock;
	sf::View view1;
	view1.setCenter(sf::Vector2f(375, 250));
	view1.setSize(sf::Vector2f(750, 500));
	sf::Sprite spriteBackGround;
	sf::Texture textureBackGround;
	sf::Sprite spriteBones;
	sf::Texture textureBones;
	sf::Sprite spriteCauldron;
	sf::Texture textureCauldron;
	if (!textureBackGround.loadFromFile("data/PotionCooking/Fond.jpg") || !textureBones.loadFromFile("data/PotionCooking/Os.png") || !textureCauldron.loadFromFile("data/PotionCooking/Chaudron.png"))
	{
		return EXIT_FAILURE;
	}
	spriteBackGround.setTexture(textureBackGround);
	spriteBones.setTexture(textureBones);
	spriteCauldron.setTexture(textureCauldron);
	spriteBones.setPosition(900, 100);
	spriteCauldron.setPosition(1125, 400);
	WindowType currentWindow = WindowType::HOME;



	bool mouseClicked = false;
	bool mouseInsideRect = false;
	bool dragging = false;

	int mouseX = 0;
	int mouseY = 0;

	float viewX = 0;

	sf::Vector2f mouseRectOffset;

	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{

					std::cout << "space" << std::endl;

					switch (currentWindow)
					{
					case WindowType::HOME:
					{
						currentWindow = WindowType::INGREDIENT;
						std::cout << "INGRE" << std::endl;
						viewX = 750;
						break;
					}
					case WindowType::INGREDIENT:
					{
						currentWindow = WindowType::BAKING;
						std::cout << "BAKE" << std::endl;
						viewX = 1500;
						break;
					}
					case WindowType::BAKING:
					{
						currentWindow = WindowType::PRESENTATION;
						std::cout << "PRE" << std::endl;
						viewX = 2250;
						break;
					}
					case WindowType::PRESENTATION:
					{
						currentWindow = WindowType::HOME;
						std::cout << "HOME" << std::endl;
						viewX = 0;
						break;
					}
					}
				}
				
				
			}


			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				mouseClicked = true;

				if (spriteBones.getGlobalBounds().contains(event.mouseButton.x+viewX, event.mouseButton.y))
				{
					dragging = true;
					mouseRectOffset.x = event.mouseButton.x + viewX - spriteBones.getGlobalBounds().left - spriteBones.getOrigin().x;
					mouseRectOffset.y = event.mouseButton.y + viewX - spriteBones.getGlobalBounds().top - spriteBones.getOrigin().y;
				}
			}

			//LMB released
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				mouseClicked = false;
				dragging = false;
			}

			//Mouse Moved in window
			if (event.type == sf::Event::MouseMoved)
			{
				mouseX = event.mouseMove.x + viewX;
				mouseY = event.mouseMove.y + viewX;
				std::cout << mouseX << std::endl;
			}

		

			if (event.type == sf::Event::Closed)
				window.close();
		}

		//LOGIC

		if (dragging == true)
		{
			spriteBones.setPosition(mouseX - mouseRectOffset.x, mouseY - mouseRectOffset.y);
		}


		view1.setCenter(sf::Vector2f((viewX+375), 250));
		window.setView(view1);
		//std::cout << view1.getCenter().x << std::endl;
		window.draw(spriteBackGround);
		window.draw(spriteBones);
		window.draw(spriteCauldron);
		window.display();
	}
}
