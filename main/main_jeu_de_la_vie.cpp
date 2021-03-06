/// CreatureSimulationBadCode.cpp : Defines the entry point for the console application.
//

// Jeu de la vie debugger avec reproduction et pointeur brute

#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>

#include "JeuDeLaVie/GameObjectBuilder.h"
#include "JeuDeLaVie/Map.h"
#include "JeuDeLaVie/Creature.h"
#include "JeuDeLaVie/Food.h"
#include "JeuDeLaVie/GameObject.h"
#include "JeuDeLaVie/Simulation.h"
#include "JeuDeLaVie/Vector2D.h"
#include "JeuDeLaVie/Constant.h"
#include "JeuDeLaVie/Egg.h"

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


