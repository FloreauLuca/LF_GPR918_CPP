
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>

#ifndef MAP_H
#define MAP_H

#include "Const.h"
#include "Vector2D.h"

struct Vector2D;

class Map;
class Simulation;
class Creature;
class Food;
class GameObject;
class GameObjectBuilder;

class Map {
public:
	Map(); // Remplit la map créée de nullptr

	bool AddGameObjectAt(std::shared_ptr<GameObject> gameObject); //Mets la position au gameobject

	bool AddGameObjectAt(std::shared_ptr<GameObject> gameObject, int positionX, int positionY); //Mets le gameobject dans la map et dans la liste des gameObjects (gameObjectForUpdate)

	GameObject & getContentAtPosition(Vector2D position);

	bool RemoveObjectAt(Vector2D position, Simulation * simulation);

	bool MoveCreatureTo(Creature & gameObject, int positionX, int positionY);
	
	void update(Simulation & simulation);

	void DisplayMap();

	int countCreaturesInMap();

	template<typename T> bool gameObjectOfTypeExistAt(Vector2D position) {
		if (map[position.x][position.y] == nullptr) {
			return false;
		}
		std::shared_ptr<T> gameObject = std::dynamic_pointer_cast<T>(map[position.x][position.y]);
		return gameObject != nullptr;
	}

	bool gameObjectExistAt(Vector2D position);

private:

	std::array<std::array<std::shared_ptr<GameObject>, MAP_SIZE>, MAP_SIZE> map;
	std::list<std::shared_ptr<GameObject>> gameObjectsForUpdate;

};
#endif