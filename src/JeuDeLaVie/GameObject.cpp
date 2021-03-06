
#include "JeuDeLaVie/Map.h"
#include "JeuDeLaVie/GameObject.h"
#include "JeuDeLaVie/Simulation.h"
#include "JeuDeLaVie/Vector2D.h"

struct Vector2D;

class Simulation;
class GameObject;

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
