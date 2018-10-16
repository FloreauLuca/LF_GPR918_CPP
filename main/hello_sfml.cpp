#include <SFML/Main.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include  <cmath>
#include <list>
class Obstacle;

std::list<Obstacle> listObstacle;

enum class Color {
	WHITE,
	BLACK,
	RED,
	BLUE,
	GREEN,
};
enum class AnimPerso {
	PERSOFACE1,
	PERSOFACE2,
	PERSOBACK1,
	PERSOBACK2,
};



class Obstacle
{
public:
	sf::FloatRect boundingBox;
	sf::RectangleShape obstacle;
	Obstacle(int xstart, int ystart, int xend,int yend)
	{
		
		
		obstacle.setFillColor(sf::Color(255, 0, 100));
		obstacle.setPosition(xstart, ystart);
		obstacle.setSize(sf::Vector2f(abs(xstart-xend), abs(ystart - yend)));
		boundingBox = obstacle.getGlobalBounds();
	}
	

private:
	



};

bool isCollisionWithObstacle (sf::FloatRect playerHitBox)
{
	for (auto & obstacle : listObstacle)
	{
		if (playerHitBox.intersects(obstacle.boundingBox))
		{
			return true;
		}
	}
	return false;
}



int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "WT Window");
	sf::Sprite spriteTest;
	sf::Texture texturePersoFace1;
	sf::Texture texturePersoFace2;
	sf::Texture texturePersoBack1;
	sf::Texture texturePersoBack2;


	if ((!texturePersoFace1.loadFromFile("data/PersoFace1.png")) || (!texturePersoFace2.loadFromFile("data/PersoFace2.png")) || (!texturePersoBack1.loadFromFile("data/PersoBack1.png")) || (!texturePersoBack2.loadFromFile("data/PersoBack2.png")))
	{
		return EXIT_FAILURE;
	}
	spriteTest.setTexture(texturePersoFace1);
	spriteTest.scale(5, 5);
	Obstacle block = Obstacle(100, 100, 200, 200);
	listObstacle.push_back(block);
	Obstacle borderUp = Obstacle(0, -10, 500, 0);
	listObstacle.push_back(borderUp);
	Obstacle borderDown = Obstacle(0, 500, 500, 510);
	listObstacle.push_back(borderDown);
	Obstacle borderRight = Obstacle(-10, 0, 0, 500);
	listObstacle.push_back(borderRight);
	Obstacle borderLeft = Obstacle(500, 0, 510, 500);
	listObstacle.push_back(borderLeft);

	sf::FloatRect playerHitBox = spriteTest.getGlobalBounds();
	Color currentColor = Color::WHITE;
	AnimPerso currentAnim = AnimPerso::PERSOFACE1;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
		while (window.pollEvent(event))
		{
			//std::cout << "y " << spriteTest.getPosition().y << std::endl;
			//std::cout << "x " << spriteTest.getPosition().x << std::endl;
			// "close requested" event: we close the window
			
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
			{
				spriteTest.move(sf::Vector2f(-10, 0));
				playerHitBox = spriteTest.getGlobalBounds();
				if (isCollisionWithObstacle(playerHitBox))
				{
					spriteTest.move(sf::Vector2f(10, 0));
				}
				switch (currentAnim)
				{
				case AnimPerso::PERSOFACE1:
				{
					currentAnim = AnimPerso::PERSOFACE2;
					spriteTest.setTexture(texturePersoFace2);
					break;
				}
				case AnimPerso::PERSOFACE2:
				{
					currentAnim = AnimPerso::PERSOFACE1;
					spriteTest.setTexture(texturePersoFace1);
					break;
				}
				}
			}
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
			{
				spriteTest.move(sf::Vector2f(10, 0));
				playerHitBox = spriteTest.getGlobalBounds();
				if (isCollisionWithObstacle(playerHitBox))
				{
					spriteTest.move(sf::Vector2f(-10, 0));
				}
				switch (currentAnim)
				{
				case AnimPerso::PERSOFACE1:
				{
					currentAnim = AnimPerso::PERSOFACE2;
					spriteTest.setTexture(texturePersoFace2);
					break;
				}
				case AnimPerso::PERSOFACE2:
				{
					currentAnim = AnimPerso::PERSOFACE1;
					spriteTest.setTexture(texturePersoFace1);
					break;
				}
				}
			}
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
			{
				spriteTest.move(sf::Vector2f(0, 10));
				playerHitBox = spriteTest.getGlobalBounds();
				if (isCollisionWithObstacle(playerHitBox))
				{
					spriteTest.move(sf::Vector2f(0, -10));
				}
				switch (currentAnim)
				{
				case AnimPerso::PERSOFACE1:
				{
					currentAnim = AnimPerso::PERSOFACE2;
					spriteTest.setTexture(texturePersoFace2);
					break;
				}
				case AnimPerso::PERSOFACE2:
				{
					currentAnim = AnimPerso::PERSOFACE1;
					spriteTest.setTexture(texturePersoFace1);
					break;
				}
				default:
					{
					currentAnim = AnimPerso::PERSOFACE1;
					spriteTest.setTexture(texturePersoFace1);
					break;
					}
				}
			}
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
			{
				spriteTest.move(sf::Vector2f(0, -10));
				playerHitBox = spriteTest.getGlobalBounds();
				if (isCollisionWithObstacle(playerHitBox))
				{
					spriteTest.move(sf::Vector2f(0, 10));
				}
				switch (currentAnim)
				{
				case AnimPerso::PERSOBACK1:
				{
					currentAnim = AnimPerso::PERSOBACK2;
					spriteTest.setTexture(texturePersoBack2);
					break;
				}
				case AnimPerso::PERSOBACK2:
				{
					currentAnim = AnimPerso::PERSOBACK1;
					spriteTest.setTexture(texturePersoBack1);
					break;
				}
				default :
					{
					currentAnim = AnimPerso::PERSOBACK1;
					spriteTest.setTexture(texturePersoBack1);
					break;
					}
				}
			}



			
			if (isCollisionWithObstacle(playerHitBox))
			{
				spriteTest.setColor(sf::Color(255, 0, 100));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				switch (currentColor)
				{
				case Color::WHITE:
				{
					currentColor = Color::BLACK;
					spriteTest.setColor(sf::Color(255, 255, 255));
					break;
				}
				case Color::BLACK:
				{
					currentColor = Color::BLUE;
					spriteTest.setColor(sf::Color(0, 0, 255));
					break;
				}
				case Color::BLUE:
				{
					currentColor = Color::GREEN;
					spriteTest.setColor(sf::Color(0, 255, 0));
					break;
				}
				case Color::GREEN:
				{
					currentColor = Color::RED;
					spriteTest.setColor(sf::Color(255, 0, 0));
					break;
				}
				case Color::RED:
				{
					currentColor = Color::WHITE;
					spriteTest.setColor(sf::Color(0, 0, 0));
					break;
				}
				}
			}

			

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		/*
		if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
		{
			spriteTest.move(sf::Vector2f(0, 2));
			playerHitBox = spriteTest.getGlobalBounds();
			if (isCollisionWithObstacle(playerHitBox))
			{
				spriteTest.move(sf::Vector2f(0, -2));
			}
		}
		*/

		window.clear(sf::Color::Blue);
		window.draw(spriteTest);
		for (auto & obstacle : listObstacle)
		{
			window.draw(obstacle.obstacle);
		}
		window.display();
        

		
    }


    return EXIT_SUCCESS;


}
