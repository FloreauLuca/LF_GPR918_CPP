
#include "pch.h"
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>

#ifndef FOOD_H
#define FOOD_H

#include "GameObject.h"

struct Vector2D;

class Map;
class Simulation;
class Creature;
class Food;
class GameObject;
class GameObjectBuilder;

class Food : public GameObject {
public:
	Food(Simulation * simulation);

	char getImage();

};

#endif
