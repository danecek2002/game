//
// Created by Daniel klíma on 03.05.2023.
//

#ifndef ZOOLS2023_XEFANOVA_PLAYER_H
#define ZOOLS2023_XEFANOVA_PLAYER_H

#include <vector>
#include <iostream>
#include <array>
#include "Weapon.h"
#include "Item.h"

class Player {
    std::vector<std::vector<bool>> m_playerPosition;
    std::array<Weapon*,2> m_playerWeapons = {nullptr, nullptr};
    int m_health;
    int m_strength;
    int m_magicPower;

public:
    Player(int size) : m_playerPosition(size, std::vector<bool>(size, false)) {
        m_playerPosition[size - 1][0] = true;
        m_health=100;
        m_magicPower=40;
        m_strength=40;
    }

    int getX();

    int getY();

    void moveToX(int where);

    void moveToY(int where);

    Weapon* takeWeapon(Weapon* newWeapon);

    void takeItem(Item* item);

    int getHealth(){return m_health;};

    int getMagicPower(){return m_magicPower;};

    int getStrength();

    std::array<Weapon*,2>& getWeapons(){ return m_playerWeapons;}


};


#endif //ZOOLS2023_XEFANOVA_PLAYER_H
