//
// Created by Vít Čevelík on 07.05.2023.
//

#include "Enemy.h"
#include "Monster.h"
#include "Guard.h"
#include <random>

Enemy* Enemy::getRandomEnemy(int type) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1,10);
    int randNum = dis(gen);

    switch(type){
        case 1:
            return new Monster(randNum);
        case 2:
            return new Guard(randNum);
    }
}