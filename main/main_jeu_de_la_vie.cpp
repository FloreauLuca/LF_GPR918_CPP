/// CreatureSimulationBadCode.cpp : Defines the entry point for the console application.
//

// Jeu de la vie debugger avec reproduction et pointeur brute

#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>

#include"GameObjectBuilder.h"
#include "Map.h"
#include "Creature.h"
#include "Food.h"
#include "GameObject.h"
#include "Simulation.h"
#include "Vector2D.h"
#include "Constant.h"
#include "Egg.h"

struct Vector2D;

class Map;
class Simulation;
class Creature;
class Food;
class GameObject;
class GameObjectBuilder;

void simulate() {
	Simulation simulation(445); // Crée la simulaion
	simulation.init(); // Initialise la simulation
	simulation.star(); // Lance la simulation

	std::cout << "Simulation ended" << std::endl;//" >>
}


int main()
{

	simulate();

	return 0;
}


