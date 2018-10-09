
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>

#include "GameObjectBuilder.h"
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

Egg::Egg(Simulation * simulation) :GameObject(simulation){
	hatchingPourcent = 0;
}

void Egg::update() {
	if (isDestroyed) {
		return;
	}
	

	if (hatchingPourcent >= 3) {
		hatching();
		return;
	}
	else {
		incrementHatching();
	}

}

char Egg::getImage() //int
{
	return 'O';
}


void Egg::hatching() {
	isDestroyed = true;
	
}

void Egg::incrementHatching() {
	hatchingPourcent++;
}
