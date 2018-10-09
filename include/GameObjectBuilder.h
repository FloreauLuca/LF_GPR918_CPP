

#ifndef GAMEOBJECTBUILDER_H
#define GAMEOBJECTBUILDER_H

#include "Egg.h"

struct Vector2D;

class Simulation;
class Creature;
class Food;
class GameObject;
class Egg;


class  GameObjectBuilder {
public:
	static std::shared_ptr <Creature> buildCreature(Simulation & simulation); //crée une creature
	static std::shared_ptr <Creature> buildChild(Simulation & simulation, Vector2D position); //Crée une créature avec un emplacement prédéfini
	static std::shared_ptr <Egg> buildEgg(Simulation & simulation); //Crée un Oeuf
	static std::shared_ptr <Food> buildFood(Simulation & simulation); //crée de la nourriture
};
#endif
