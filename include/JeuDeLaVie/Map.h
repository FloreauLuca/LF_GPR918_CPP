
#include <array>
#include <memory>
#include <list>

#ifndef MAP_H
#define MAP_H

#include "Constant.h"

struct Vector2D;

class Simulation;
class Creature;
class GameObject;

class Map {
public:
	Map(); // Remplit la map créée de nullptr

	bool AddGameObjectAt(std::shared_ptr<GameObject> gameObject); //Mets la position au gameobject

	bool AddGameObjectAt(std::shared_ptr<GameObject> gameObject, int positionX, int positionY); //Mets le gameobject dans la map et dans la liste des gameObjects (gameObjectForUpdate)

	GameObject & getContentAtPosition(Vector2D position); // reupere l'adresse du gameobject à la position

	bool RemoveObjectAt(Vector2D position, Simulation * simulation); // crée un enfant à partir d'u oeuf et detruit le gameobject à position

	bool MoveCreatureTo(Creature & gameObject, int positionX, int positionY); // deplace creature en positionX et positionY
	
	void update(Simulation & simulation); // update chaque gameobject de gameobjectforupdate

	void DisplayMap(); // affiche la map

	int countCreaturesInMap(); // compte le nombre de creature sur la carte

	template<typename T> bool gameObjectOfTypeExistAt(Vector2D position) // verifie si l'objet de class template existe à la position
	{
		if (map[position.x][position.y] == nullptr) {
			return false;
		}
		std::shared_ptr<T> gameObject = std::dynamic_pointer_cast<T>(map[position.x][position.y]);
		return gameObject != nullptr;
	}

	bool gameObjectExistAt(Vector2D position); // verifie si un game object existe à la position

private:

	std::array<std::array<std::shared_ptr<GameObject>, MAP_SIZE>, MAP_SIZE> map;

	std::list<std::shared_ptr<GameObject>> gameObjectsForUpdate; // objet à update

};
#endif