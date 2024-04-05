//
// Created by Vít Čevelík on 07.05.2023.
//

#include "Monster.h"

Monster::Monster(int level) {
    m_damage=(level * 5);
    m_health=(level * 10);
}

int Monster::getDamage() {
    return m_damage;
}

int Monster::getHealth() {
    return m_health;
}