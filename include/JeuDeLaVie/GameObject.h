
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Vector2D.h"

struct Vector2D;

class Simulation;



class GameObject {

public:
	GameObject(Simulation * simulation, Vector2D position);

	GameObject(Simulation * simulation);

	
	virtual void update();

	virtual void start();

	virtual char getImage();

	Vector2D getPosition(); // renvoie position objet

	void setPosition(Vector2D position); // mets la position à l'objet

	bool isObjectDestroyed(); // verifie si l'objet est détruit

	void destroy(); // statut detruit de l'objet


protected:
	Vector2D position; //position de l'objet
	Simulation * simulation; // simulation, controle le jeu
	bool isDestroyed; // statut de l'objet
	

};

#endif
