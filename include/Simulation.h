
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>

#ifndef SIMULATION_H
#define SIMULATION_H

#include "Vector2D.h"

struct Vector2D;

class Map;
class Simulation;
class Creature;
class Food;
class GameObject;
class GameObjectBuilder;

class Simulation {
public:
	Map map;
	
	Simulation(int seed);

	void init(); 

	void star();

	int getValueRandom(int min, int max);

	std::vector<GameObject*> parent;

private:

	int nbrCreatures;
	int nbrHunters;
	int nbrFoodStuff;

	std::default_random_engine random;

	void update();

	bool isEndSimulation();
	
};

#endif //SIMULATION_H