//
// Created by Vít Čevelík on 07.05.2023.
//

#ifndef ZOOLS2023_XEFANOVA_MONSTER_H
#define ZOOLS2023_XEFANOVA_MONSTER_H

#include "Enemy.h"

class Monster:public Enemy {

protected:
    int m_damage;
    int m_health;

public:
    Monster(int level);
    int getDamage();
    int getHealth();
};


#endif //ZOOLS2023_XEFANOVA_MONSTER_H
