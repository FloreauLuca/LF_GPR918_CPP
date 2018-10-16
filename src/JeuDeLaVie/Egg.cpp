
#include "JeuDeLaVie/Map.h"
#include "JeuDeLaVie/GameObject.h"
#include "JeuDeLaVie/Simulation.h"
#include "JeuDeLaVie/Egg.h"

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
