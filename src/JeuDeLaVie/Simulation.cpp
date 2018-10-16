
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>

#include "JeuDeLaVie/GameObjectBuilder.h"
#include "JeuDeLaVie/Map.h"
#include "JeuDeLaVie/Creature.h"
#include "JeuDeLaVie/Food.h"
#include "JeuDeLaVie/GameObject.h"
#include "JeuDeLaVie/Simulation.h"
#include "JeuDeLaVie/Constant.h"

class Map;
class Simulation;
class GameObject;
class GameObjectBuilder;

Simulation::Simulation(int seed) :random(seed) {

}

void Simulation::init() {
	//Create 5 creatures
	for (int i = 0; i < NB_CREATURE; i++) {
		map.AddGameObjectAt(std::shared_ptr<GameObject>(std::static_pointer_cast<GameObject>((GameObjectBuilder::buildCreature(*this)))));
	}

	//Create 6 foods 
	for (int i = 0; i < NB_FOOD; i++) {
		map.AddGameObjectAt(std::shared_ptr<GameObject>(std::static_pointer_cast<GameObject>((GameObjectBuilder::buildFood(*this)))));
	}
}

void Simulation::star() {
	while (!isEndSimulation()) //()
	{
		update();
		map.DisplayMap();
		parentThisTurn.clear();
	}
	std::cout << std::endl << "------ END OF SIMULATION -------------" << std::endl;
	system("Pause");
}

int Simulation::getValueRandom(int min, int max) {
	std::uniform_int_distribution<int> distribution(min, max);
	int randomValue = distribution(random);
	return randomValue;
}


void Simulation::update() {
	map.update(*this);
}

bool Simulation::isEndSimulation() {
	return map.countCreaturesInMap() <= 0;
}
