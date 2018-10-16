
#ifndef FOOD_H
#define FOOD_H

#include "GameObject.h"

class Map;
class Simulation;
class GameObject;


class Food : public GameObject {
public:
	Food(Simulation * simulation);

	char getImage(); // image F

};

#endif
