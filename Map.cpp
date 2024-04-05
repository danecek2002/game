//
// Created by xefanova on 05.05.2023.
//

#include "Map.h"
#include <random>

Map::Map(int size, Player* player) : m_size(size){
    m_weapons.resize(m_size, std::vector<Weapon*>(m_size));
    m_items.resize(m_size, std::vector<Item*>(m_size));
    initRandomVectors();
    m_player=player;
}

void Map::initRandomVectors(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dis(0.5);

    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            m_weapons[i][j] = dis(gen) ? new Weapon() : nullptr;
            m_items[i][j] = dis(gen) ? new Item() : nullptr;
        }
    }
}

std::vector<std::vector<Weapon*>>& Map::getWeapons(){
    return m_weapons;
}

std::vector<std::vector<Item*>>& Map::getItems(){
    return m_items;
}

int Map::getSize(){
    return m_size;
}

Player* Map::getPlayer(){
    return m_player;
}

Map::~Map() {
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            delete m_weapons[i][j];
            delete m_items[i][j];
        }
    }
}
