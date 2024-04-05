//
// Created by Daniel klíma on 03.05.2023.
//

#include "Player.h"
int Player::getX(){
    for (int y = 0; y < m_playerPosition.size(); ++y) {
        for (int x = 0; x < m_playerPosition[y].size(); ++x) {
            if (m_playerPosition[y][x]) {
                return x;
            }
        }
    }
    return -1;
}

int Player::getY(){
    for (int y = 0; y < m_playerPosition.size(); ++y) {
        for (int x = 0; x < m_playerPosition[y].size(); ++x) {
            if (m_playerPosition[y][x]) {
                return y;
            }
        }
    }
    return -1;
}

void Player::moveToX(int where){
    int last = getX();
    m_playerPosition[getY()][getX() + where] = true;
    m_playerPosition[getY()][last] = false;
}

void Player::moveToY(int where){
    int last = getY();
    m_playerPosition[getY() + where][getX()] = true;
    m_playerPosition[last][getX()] = false;
}

Weapon* Player::takeWeapon(Weapon* newWeapon){
    Weapon* replacedWeapon = nullptr;

    if (m_playerWeapons[0] == nullptr) {
        m_playerWeapons[0] = newWeapon;
    } else if (m_playerWeapons[1] == nullptr) {
        m_playerWeapons[1] = newWeapon;
    } else if (m_playerWeapons[0]->getDamage() > m_playerWeapons[1]->getDamage()) {
        replacedWeapon = m_playerWeapons[1];
        m_playerWeapons[1] = newWeapon;
    } else if (m_playerWeapons[0]->getDamage() < m_playerWeapons[1]->getDamage()) {
        replacedWeapon = m_playerWeapons[0];
        m_playerWeapons[0] = newWeapon;
    } else {
        replacedWeapon = m_playerWeapons[0];
        m_playerWeapons[0] = newWeapon;
    }
    return replacedWeapon;
}

int Player::getStrength(){
    int weaponBonus = 40;
    for (auto weap : m_playerWeapons){
        if (weap != nullptr){
            weaponBonus+=weap->getDamage();}
    }
    m_strength=weaponBonus;
    return m_strength;
}

void Player::takeItem(Item* item){
    if (item->getType() == ItemType::HealthItem){
        m_health+=item->getBonus();
    } else if (item->getType() == ItemType::MagicItem){
        m_magicPower+=item->getBonus();
    }
}

