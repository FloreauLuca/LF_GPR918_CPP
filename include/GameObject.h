
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Vector2D.h"

struct Vector2D;

class Map;
class Simulation;
class Creature;
class Food;
class GameObject;


class GameObject {

public:
	GameObject(Simulation * simulation, Vector2D position);

	GameObject(Simulation * simulation);

	
	virtual void update();

	virtual void start();

	virtual char getImage();

	Vector2D getPosition();

	void setPosition(Vector2D position);

	bool isObjectDestroyed();

	void destroy();


protected:
	Vector2D position;
	Simulation * simulation;
	bool isDestroyed;
	std::string debug;

};

#endif
