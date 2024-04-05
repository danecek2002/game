//
// Created by xefanova on 03.05.2023.
//

#ifndef ZOOLS2023_XEFANOVA_GAME_H
#define ZOOLS2023_XEFANOVA_GAME_H


#include <string>
#include "Player.h"
#include "Map.h"
#include "MapDirector.h"

class Game {
    int m_size;
    std::string m_gameName;
    Player* m_player;
    Map* m_map;
    MapDirector* m_director;

private:
    void showMenu(bool print);
    void printPlayerInfo();
    void printWin();
    std::string getTileWeapon();
    std::string getTileItem();
    static void deleteGameByName(std::string gameName);
    void printMenu();

public:
    Game(std::string gameName);

    void startGame();

    void loadGame();

    std::string getGameName(){return m_gameName;};
};


#endif //ZOOLS2023_XEFANOVA_GAME_H
