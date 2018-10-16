
#include "JeuDeLaVie/Map.h"
#include "JeuDeLaVie/Food.h"
#include "JeuDeLaVie/GameObject.h"
#include "JeuDeLaVie/Simulation.h"

struct Vector2D;

class Simulation;
class Food;
class GameObject;

Food::Food(Simulation * simulation) :GameObject(simulation) {

}

char Food::getImage() {
	return 'F';
}
