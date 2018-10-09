
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
#include "Egg.h"

struct Vector2D;

class Map;
class Simulation;
class Creature;
class Food;
class GameObject;
class GameObjectBuilder;

Food::Food(Simulation * simulation) :GameObject(simulation) {

}

char Food::getImage() {
	return 'F';
}
