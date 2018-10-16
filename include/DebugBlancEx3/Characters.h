//
//  Characters.hpp
//  Test
//
//  Created by Elias Farhan on 14/12/16.
//  Copyright © 2016 Elias Farhan. All rights reserved.
//

#ifndef Characters_hpp
#define Characters_hpp

#include <iostream>
class Character
{
public:
	Character(int, int, int, int);
	void takeDamage(int damage);
	bool isAlive();
	virtual void death();
	int getAttack();
	int getHealth();
	int getDefense();
protected:
	int health;
	int attack;
	int defense;
	int strength;
};

class Hero;

class Monster : public Character
{
public:
    Monster(int,int,int,int);
    //void takeDamage(int damage);
    void fight(Hero*);
    void death();
};

class Hero : public Character
{
public:
    Hero(int,int,int,int);
	//void takeDamage(int damage);
    void fight(Monster*);
    void death();
};





#endif /* Characters_hpp */
