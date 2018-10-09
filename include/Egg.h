
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>

#ifndef OEUF_H
#define OEUF_H

#include "GameObject.h"

struct Vector2D;

class Map;
class Simulation;
class Creature;
class Food;
class GameObject;
class GameObjectBuilder;

class Egg : public GameObject
{
public:
	Egg(Simulation * simulation);

	void update();

	char getImage();

private:

	int hatchingPourcent;
	
	void hatching();

	void incrementHatching();

};

#endif
