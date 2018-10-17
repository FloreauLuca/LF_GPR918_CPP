//
//  SUPER HERO VERSUS HORDE OF MONSTERS
//
//  Created by Elias Farhan on 14/12/16.
//  Copyright © 2016 Elias Farhan. All rights reserved.
//

#include <iostream>
#include <list>
#include "DebugBlancEx3/Characters.h"

class Hero;
class Monster;

int main()
{
    std::unique_ptr<Hero> hero = std::make_unique<Hero>(10, 10, 10, 10);
    std::list<Monster> monsters = {Monster(10, 1,1,5), Monster(20,5, 5, 5), Monster(30, 10,10,5)};
    
    for(std::list<Monster>::iterator monsterIt = monsters.begin(); monsterIt != monsters.end(); monsterIt++)
    {
        while (hero->isAlive() && monsterIt->isAlive())
        {
            hero->fight(&(*monsterIt));
            monsterIt->fight(hero.get());
        }
        //If the monster is dead, meaning not alive, he dies!
        if(!monsterIt->isAlive()){
            monsterIt->death();
        }
        //Windows specific
        if(!hero->isAlive())
		{
            hero->death();
            break;
        }
    }
    
    system("Pause");
    return 0;
}
