
#include <random>

#ifndef SIMULATION_H
#define SIMULATION_H

struct Vector2D;

class Map;
class GameObject;

class Simulation {
public:
	Map map;
	
	Simulation(int seed);

	void init();  //initialise (creation 5 creature, 6 food)

	void star(); // demarrage, check fin update, display, parent ce tour null

	int getValueRandom(int min, int max); // random entre min et max

	std::vector<GameObject*> parentThisTurn; // list des parents aillant eu un oeuf ce tour

private:

	std::default_random_engine random;

	void update(); // map update

	bool isEndSimulation(); // verifie si c'est la fin (0 creature)
	
};

#endif //SIMULATION_H