//
// Created by Vít Če on 07.05.2023.
//

#ifndef ZOOLS2023_XEFANOVA_ENEMY_H
#define ZOOLS2023_XEFANOVA_ENEMY_H


class Enemy {

public:
    virtual int getDamage()=0;
    static Enemy* getRandomEnemy(int type);
    virtual ~Enemy(){};

protected:
    Enemy(){};

};


#endif //ZOOLS2023_XEFANOVA_ENEMY_H
