
#include "pch.h"
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

std::shared_ptr <Creature> GameObjectBuilder::buildCreature(Simulation & simulation) {
	std::unique_ptr<Creature> creature(std::make_unique<Creature>(&simulation, 20));
	int x = simulation.getValueRandom(0, MAP_SIZE - 1);
	int y = simulation.getValueRandom(0, MAP_SIZE - 1);

	creature->setPosition(Vector2D(x, y));
	return creature;
}

std::shared_ptr <Creature>  GameObjectBuilder::buildChild(Simulation & simulation, Vector2D position) {
	std::unique_ptr<Creature> creature(std::make_unique<Creature>(&simulation, 20));
	creature->setPosition(position);
	return creature;
}

std::shared_ptr <Egg>  GameObjectBuilder::buildEgg(Simulation & simulation) {
	std::unique_ptr<Egg> egg(std::make_unique<Egg>(&simulation));
	int x = simulation.getValueRandom(0, MAP_SIZE - 1);
	int y = simulation.getValueRandom(0, MAP_SIZE - 1);
	egg->setPosition(Vector2D(x, y));
	return egg;
}


std::shared_ptr <Food> GameObjectBuilder::buildFood(Simulation & simulation) {
	std::unique_ptr <Food> food(std::make_unique<Food>(&simulation));
	int x = simulation.getValueRandom(0, MAP_SIZE - 1);
	int y = simulation.getValueRandom(0, MAP_SIZE - 1);
	food->setPosition(Vector2D(x, y));
	return food;
}
