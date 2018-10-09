
#ifndef OEUF_H
#define OEUF_H

#include "GameObject.h"

class Map;
class Simulation;
class GameObject;

class Egg : public GameObject
{
public:
	Egg(Simulation * simulation); // initialise l'oeuf avec un pourcentage d'eclosion null

	void update(); // verifie si il est detruit, eclos si hunger > 3 sinon augmente pourcentage eclosion

	char getImage(); // image O

private:

	int hatchingPourcent; // pourcentage d'eclosion
	
	void hatching(); // eclosion

	void incrementHatching(); // augmente le pourcentage d'eclosion

};

#endif
