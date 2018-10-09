
#include "pch.h"
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>
#include <typeinfo>

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


Map::Map() {
	for (auto & row : map) {
		row.fill(nullptr);
	}
}

bool Map::AddGameObjectAt(std::shared_ptr<GameObject> gameObject) {
	Vector2D position = gameObject->getPosition();
	return AddGameObjectAt(gameObject, position.x, position.y);
}

bool Map::AddGameObjectAt(std::shared_ptr<GameObject> gameObject, int positionX, int positionY) {
	std::shared_ptr<GameObject> mapPosition = map[positionX][positionY];  // s'adapte à la map
	if (mapPosition == nullptr) {

		map[positionX][positionY] = std::static_pointer_cast<GameObject>(gameObject);

		//std::cout << "gameObject : " << typeid(gameObject).name() << std::endl;
		//std::cout << "gameObject* : " << typeid(*gameObject).name() << std::endl;
		//std::cout << "map : " << typeid(map[positionX][positionY]).name() << std::endl;
		//std::cout << "map* : " << typeid(*map[positionX][positionY]).name() << std::endl;

		gameObjectsForUpdate.push_back(std::static_pointer_cast<GameObject>(gameObject));
		return true;
	}
	return false;
}

GameObject & Map::getContentAtPosition(Vector2D position) {
	return *map[position.x][position.y];
}

bool Map::gameObjectExistAt(Vector2D position) {
	return map[position.x][position.y] != nullptr;
}

bool Map::RemoveObjectAt(Vector2D position, Simulation * simulation) {
	std::string str = typeid(*map[position.x][position.y]).name();
	if (str == "class Egg")
	{
		map[position.x][position.y] = nullptr;
		AddGameObjectAt(std::shared_ptr<GameObject>(std::static_pointer_cast<GameObject>(GameObjectBuilder::buildChild(*simulation, position))));
		return true;
		
	} else
	{
		if (map[position.x][position.y] != nullptr) {
			map[position.x][position.y] = nullptr;
			return true;
		}
	}
	return false;
}

bool Map::MoveCreatureTo(Creature & creatureObject, int positionX, int positionY) {
	if (positionX >= map.size() || positionY >= map[0].size()) {
		return false;
	}
	if (map[positionX][positionY] != nullptr) {
		return false;
	}
	Vector2D currentPosition = creatureObject.getPosition(); //->
	map[currentPosition.x][currentPosition.y] = nullptr;
	map[positionX][positionY] = std::static_pointer_cast<GameObject>(std::make_shared<Creature>(creatureObject));
	creatureObject.setPosition(Vector2D(positionX, positionY));
	return true;
}

void Map::update(Simulation & simulation) {
	for (auto & gameObject : gameObjectsForUpdate) {
	gameObject->update();
	//std::cout << gameObject->getPosition().x << std::endl;
	}
	//Destroy map elements 
	for (auto & gameObject : gameObjectsForUpdate) {
		if (gameObject->isObjectDestroyed()) {
			RemoveObjectAt(gameObject->getPosition(), &simulation);
		}
	}

	//Destroy updates elements 
	gameObjectsForUpdate.remove_if([](std::shared_ptr<GameObject> gameObject) {return gameObject->isObjectDestroyed(); });
}

void Map::DisplayMap() {
	system("cls");
	std::cout << "-------------------------" << std::endl;//"
	for (int x = 0; x < map.size(); x++) {
		std::cout << "|";
		for (int y = 0; y < map[x].size(); y++) {
			if (gameObjectExistAt(Vector2D(x, y))) {
				std::cout << map[x][y]->getImage();
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	system("Pause");
}

int Map::countCreaturesInMap() {
	int counter = 0;
	for (int x = 0; x < map.size(); x++) {
		for (int y = 0; y < map[x].size(); y++) {
			if (gameObjectOfTypeExistAt<Creature>(Vector2D(x, y))) {
				counter++;
			}
		}
	}
	return counter;
}
