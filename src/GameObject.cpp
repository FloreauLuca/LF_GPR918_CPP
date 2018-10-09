
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

GameObject::GameObject(Simulation * simulation, Vector2D position) :simulation(simulation), position(position) {

}

GameObject::GameObject(Simulation * simulation) :simulation(simulation) {
	isDestroyed = false;
}

void GameObject::update() {

}

void GameObject::start() {

}

char GameObject::getImage() {
	return '?';
}

Vector2D GameObject::getPosition() {
	return position;
}

void GameObject::setPosition(Vector2D position) {
	this->position = position;
}

bool GameObject::isObjectDestroyed() {
	return isDestroyed;
}

void GameObject::destroy() {
	isDestroyed = true;
}
