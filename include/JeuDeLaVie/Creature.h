
#ifndef CREATURE_H
#define CREATURE_H

struct Vector2D;

class GameObject;


class Creature : public GameObject
{
public:
	Creature(Simulation * simulation, int hungerSpeedIncrement); //initialse hunger = 0 à la creation

	void update(); // verifie si il est detruit, move, meurs si hunger > 100 sinon augmente, cherche nourritur à manger, cherche creature avec se reproduire

	char getImage(); // image C

private:

	int hungerPourcent; // pourcentage de fin
	int hungerSpeedIncrement; // pourcentage d'augmentation par jour

	//Return position. If food is not find, we return the value (-1,-1)
	Vector2D findnearbyFoodPosition(); // trouve de la nourriture autour gameObject

	//Return position. If creature is not find, we return the value (-1,-1)
	Vector2D findnearbyCreaturePosition(); // trouve une creature autour gameObject

	//Return null position. If any null position is found, we return the value (-1,-1)
	Vector2D findNullPosition(); // trouve une place vide autour gameObject INUTILISEE

	bool gameObjectNotParent(GameObject * gameObject); // verifie si la creature à deja eu un oeuf ce tour

	void randomMove(); // mouvement choisis aléatoirement
	
	void die(); // déclare la créture à detruire

	void incrementHunger(); // augmente le pourcentage de faim

};

#endif
