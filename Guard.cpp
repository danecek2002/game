//
// Created by Vít Čevelík on 07.05.2023.
//

#include "Guard.h"

Guard::Guard(int level) {
    m_damage=(level * 5);
    m_health=(level * 10);
}

int Guard::getDamage() {
    return m_damage;
}

int Guard::getHealth() {
    return m_health;
}