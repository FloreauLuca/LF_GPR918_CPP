
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
#include "Const.h"
#include "Egg.h"

struct Vector2D;

class Map;
class Simulation;
class Creature;
class Food;
class GameObject;
class GameObjectBuilder;

Creature::Creature(Simulation * simulation, int hungerSpeedIncrement) :GameObject(simulation), hungerSpeedIncrement(hungerSpeedIncrement) {
	hungerPourcent = 0;
}

void Creature::update() {
	if (isDestroyed) {
		return;
	}
	randomMove();

	if (hungerPourcent >= 100) {
		die();
		return;
	}
	else {
		incrementHunger();
	}

	Vector2D foodPosition = findnearbyFoodPosition(); //*
	if (foodPosition.x >= 0) {
		GameObject & gameObject = simulation->map.getContentAtPosition(foodPosition); //.
		if (!gameObject.isObjectDestroyed()) //()
		{
			gameObject.destroy();
			hungerPourcent = 0;
		}
	}

	//Reproduction method
	
	Vector2D creaturePosition = findnearbyCreaturePosition();
	if (creaturePosition.x >= 0) {
		GameObject & gameObject = simulation->map.getContentAtPosition(creaturePosition); //.
		if (!gameObject.isObjectDestroyed() && gameObjectNotParent(&gameObject)) //()
		{
			simulation->map.AddGameObjectAt(std::shared_ptr<GameObject>(std::static_pointer_cast<GameObject>(GameObjectBuilder::buildEgg(*simulation))));
			simulation->parent.push_back(&gameObject);
			simulation->parent.push_back(this);
		}
	}
}

char Creature::getImage() //int
{
	return 'C';
}


//Return position. If food is not find, we return the value (-1,-1)
Vector2D Creature::findnearbyFoodPosition() {
	Vector2D positionCentral = position;
	for (int x = positionCentral.x - 1; x < positionCentral.x + 2; x++) {
		if (x < 0 || x >= MAP_SIZE) {
		continue;
		}
		for (int y = positionCentral.y - 1; y < positionCentral.y + 2; y++) {
			if (y < 0 || y >= MAP_SIZE) {
				continue;
			}
			Vector2D currentPosition(x, y);
			if (simulation->map.gameObjectOfTypeExistAt<Food>(currentPosition)) {
				return currentPosition;
			}
		}
	}
	return Vector2D(-1, -1);
}

//Return position. If creature is not find, we return the value (-1,-1)
Vector2D Creature::findnearbyCreaturePosition() {
	Vector2D positionCentral = position;
	for (int x = positionCentral.x - 1; x < positionCentral.x + 2; x++) {
		if (x < 0 || x >= MAP_SIZE) {
			continue;
		}
		for (int y = positionCentral.y - 1; y < positionCentral.y + 2; y++) {
			if (y < 0 || y >= MAP_SIZE) {
				continue;
			}
			Vector2D currentPosition(x, y);
			if (currentPosition.x != position.x && currentPosition.y != position.y)
			{
				if (simulation->map.gameObjectOfTypeExistAt<Creature>(currentPosition)) {
					return currentPosition;
				}
			}
		}
	}
	return Vector2D(-1, -1);
}

Vector2D Creature::findNullPosition() {
	Vector2D positionCentral = position;
	for (int x = positionCentral.x - 1; x < positionCentral.x + 2; x++) {
		if (x < 0 || x >= MAP_SIZE) {
			continue;
		}
		for (int y = positionCentral.y - 1; y < positionCentral.y + 2; y++) {
			if (y < 0 || y >= MAP_SIZE) {
				continue;
			}
			Vector2D currentPosition(x, y);
			if (!simulation->map.gameObjectExistAt(currentPosition)) {
					return currentPosition;
			}
		}
	}
	return Vector2D(-1, -1);
}

bool Creature::gameObjectNotParent(GameObject * gameObject)
{
	for (auto & parent : simulation->parent)
	{
		if (gameObject == parent)
		{
			return false;
		}
	}
	return true;
}

void Creature::randomMove() {
	int positionXMin = position.x - 1;
	if (positionXMin < 0) {
		positionXMin = 0;
	}
	int positionXMax = position.x + 1;
	if (positionXMax >= MAP_SIZE) {
		positionXMax = MAP_SIZE - 1;
	}
	int positionYMin = position.y - 1;
	if (positionYMin < 0) {
		positionYMin = 0;
	}
	int positionYMax = position.y + 1;
	if (positionYMax >= MAP_SIZE) {
		positionYMax = MAP_SIZE - 1;
	}
	int newX = simulation->getValueRandom(positionXMin, positionXMax);
	int newY = simulation->getValueRandom(positionYMin, positionYMax);
	simulation->map.MoveCreatureTo(*this, newX, newY);
}

void Creature::die() {
	isDestroyed = true;
}

void Creature::incrementHunger() {
	hungerPourcent += hungerSpeedIncrement;
}
