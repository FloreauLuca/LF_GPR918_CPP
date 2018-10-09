
#include "Map.h"
#include "Food.h"
#include "GameObject.h"
#include "Simulation.h"

struct Vector2D;

class Simulation;
class Food;
class GameObject;

Food::Food(Simulation * simulation) :GameObject(simulation) {

}

char Food::getImage() {
	return 'F';
}
