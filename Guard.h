//
// Created by Vít Čevelík on 07.05.2023.
//

#ifndef ZOOLS2023_XEFANOVA_GUARD_H
#define ZOOLS2023_XEFANOVA_GUARD_H
#include "Enemy.h"

class Guard:public Enemy {
protected:
    int m_damage;
    int m_health;
public:
    Guard(int level);
    int getDamage();
    int getHealth();
};


#endif //ZOOLS2023_XEFANOVA_GUARD_H
