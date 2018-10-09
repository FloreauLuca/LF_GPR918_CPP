
#include "Map.h"
#include "GameObject.h"
#include "Simulation.h"
#include "Egg.h"

struct Vector2D;

class Simulation;
class GameObject;

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
