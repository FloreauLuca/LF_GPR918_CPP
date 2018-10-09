
#include "pch.h"
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>

#ifndef CREATURE_H
#define CREATURE_H

#include "GameObject.h"

struct Vector2D;

class Map;
class Simulation;
class Creature;
class Food;
class GameObject;
class GameObjectBuilder;

class Creature : public GameObject
{
public:
	Creature(Simulation * simulation, int hungerSpeedIncrement);

	void update();

	char getImage();

private:

	int hungerPourcent;
	int hungerSpeedIncrement;

	//Return position. If food is not find, we return the value (-1,-1)
	Vector2D findnearbyFoodPosition();

	//Return position. If creature is not find, we return the value (-1,-1)
	Vector2D findnearbyCreaturePosition();

	//Return null position. If any null position is found, we return the value (-1,-1)
	Vector2D findNullPosition();

	bool gameObjectNotParent(GameObject * gameObject);

	void randomMove();
	
	void die();

	void incrementHunger();

};

#endif
