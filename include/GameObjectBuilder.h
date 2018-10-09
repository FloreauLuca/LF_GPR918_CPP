#include "pch.h"
#include "Egg.h"

#ifndef GAMEOBJECTBUILDER_H
#define GAMEOBJECTBUILDER_H

struct Vector2D;

class Map;
class Simulation;
class Creature;
class Food;
class GameObject;


class  GameObjectBuilder {
public:
	static std::shared_ptr <Creature> buildCreature(Simulation & simulation); //cr�e une creature
	static std::shared_ptr <Creature> buildChild(Simulation & simulation, Vector2D position); //Cr�e une cr�ature avec un emplacement pr�d�fini
	static std::shared_ptr <Egg> buildEgg(Simulation & simulation); //Cr�e un Oeuf
	static std::shared_ptr <Food> buildFood(Simulation & simulation); //cr�e de la nourriture
};
#endif
