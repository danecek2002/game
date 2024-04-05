//
// Created by xefanova on 03.05.2023.
//

#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Map.h"
#include "GameStorage.h"
#include "DungeonMapBuilder.h"
#include "MapDirector.h"


Game::Game(std::string gameName){
    m_gameName = gameName;
}

// The beginning of the game: choosing the size of the map, creating map, a player, calling functions to start the game
void Game::startGame(){
    int size = 0;
    std::cout << "Please, choose the map size from 2 to 7: " << std::endl;
    while (!(std::cin >> size) || size > 7 || size < 2) {
        std::cerr << "Error: Incorrect number. Please enter a valid number:" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if ((size >= 2) and (size<=7)){
        m_size=size;
        Player* player = new Player(size);
        m_player = player;
        Map* map = new Map(size, player);
        m_map = map;
        MapDirector* director = new MapDirector(new DungeonMapBuilder(map));
        m_director=director;
        m_director->createMap();
        printPlayerInfo();
        showMenu(true);
    } else {
        std::cerr << "Incorrect map size!" << std::endl;
    }
}

//Function to launch a saved game
void Game::loadGame(){
    m_director->createMap();
    showMenu(true);
}

//Function for displaying info about weapon in the map cell where the player is located
std::string Game::getTileWeapon(){
    if (m_map->getWeapons()[m_player->getY()][m_player->getX()] != nullptr){
        return "(w) - " + m_map->getWeapons()[m_player->getY()][m_player->getX()]->getName() + " (damage: " +
               std::to_string(m_map->getWeapons()[m_player->getY()][m_player->getX()]->getDamage()) + ")";
    } else {
        return "- there are no weapons here.";
    }
}

//Function for displaying info about item in the map cell where the player is located
std::string Game::getTileItem(){
    if (m_map->getItems()[m_player->getY()][m_player->getX()] != nullptr){
        return "(" + m_map->getItems()[m_player->getY()][m_player->getX()]->getLetter() + ") - "
               + m_map->getItems()[m_player->getY()][m_player->getX()]->getName() + " (bonus: " +
               std::to_string(m_map->getItems()[m_player->getY()][m_player->getX()]->getBonus()) + ")";
    } else {
        return "- there are no items here.";
    }
}

//Function for displaying menu text
void Game::printMenu(){
    std::cout << "Select and enter the number of actions you want to perform: " << std::endl;
    std::cout << "w - Go up" << std::endl;
    std::cout << "a - Go left" << std::endl;
    std::cout << "d - Go right" << std::endl;
    std::cout << "s - Go down" << std::endl;
    std::cout << "1 - Take an item " << getTileItem() << std::endl;
    std::cout << "2 - Take a weapon " << getTileWeapon() << std::endl;
    std::cout << "3 - Go back to the Game Menu" << std::endl;
}

//The main function of the game menu. Performs player selection in the menu during the game
void Game::showMenu(bool print){
    bool endGame = false;

    if (print) {
        printMenu();
    } else {
        std::cerr << "Select another choice: " << std::endl;
    }

    std::string choose;

    while (!(std::cin >> choose) || choose.length() != 1 || (choose != "w" && choose != "a" &&
                                                                 choose != "s" && choose != "d" && choose != "1" && choose != "2" && choose != "3")) {
        std::cerr << "Error: Incorrect number. Please enter a valid number:" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    char chooseChar = choose.at(0);
    switch(chooseChar){
        case 'a':
            if(m_player->getX() != 0){
                m_player->moveToX(-1);}
            else {
                std::cerr << "There is no exit to the left!" << std::endl;
                showMenu(false);
            }
            break;
        case 'd':
            if (m_player->getY() == 0 and (m_player->getX() + 1) == m_size ){
                printWin();
                endGame = true;
                deleteGameByName(m_gameName);
            } else {
                if((m_player->getX() + 1) == m_size){
                    std::cerr << "There is no exit to the right!" << std::endl;
                    showMenu(false);;
                } else {
                    m_player->moveToX(1);
                }
            }
            break;
        case 'w':
            if (m_player->getY() != 0){
                m_player->moveToY(-1);}
            else {std::cerr << "There is no exit to the up!" << std::endl;
                showMenu(false);
            }
            break;
        case 's':
            if((m_player->getY() + 1) == m_size){
                std::cerr << "There is no exit to the down!" << std::endl;
                showMenu(false);
            } else {
                m_player->moveToY(1);}
            break;
        case '3':
            GameStorage::menuGame();
            break;
        case '2':
            if (m_map->getWeapons()[m_player->getY()][m_player->getX()] != nullptr){
                Weapon* weap = m_player->takeWeapon(m_map->getWeapons()[m_player->getY()][m_player->getX()]);
                m_map->getWeapons()[m_player->getY()][m_player->getX()] = weap;
            } else {
                std::cerr << "There are no weapons here!" << std::endl;
                showMenu(false);
            }
            break;
        case '1':
            if (m_map->getItems()[m_player->getY()][m_player->getX()] != nullptr){
                m_player->takeItem(m_map->getItems()[m_player->getY()][m_player->getX()]);
                m_map->getItems()[m_player->getY()][m_player->getX()] = nullptr;
            } else {
                std::cerr << "There are no items here!" << std::endl;
                showMenu(false);
            }
            break;
        default:
            std::cerr << "Error: Incorrect choice." << std::endl;
            break;
    }

    if (endGame != true){
        m_director->createMap();
        printPlayerInfo();
        showMenu(true);} else {
        GameStorage::menuGame();
    }
}

//Function for deleting a saved game. Called after winning the game.
void Game::deleteGameByName(std::string gameName){
    for (int i = 0; i < GameStorage::getGames().size(); i++){
        if (GameStorage::getGames()[i]->getGameName() == gameName) {
            GameStorage::getGames().erase(GameStorage::getGames().begin() + i);
        }
    }
}

//Function for displaying actual info about the player
void Game::printPlayerInfo(){
    std::cout << "*************************************************" << std::endl;
    std::cout << "              Player information: " << std::endl;
    std::cout << "Health: " << m_player->getHealth();
    std::cout << "     Magic Power: " << m_player->getMagicPower();
    std::cout << "     Strength: " << m_player->getStrength()<<std::endl;
    std::cout << "Weapons(max. 2): " << std::endl;
    std::string str="";
    for (int i = 0; i < m_player->getWeapons().size(); i++) {
        if (m_player->getWeapons()[i] != nullptr) {
            str += "     " + m_player->getWeapons()[i]->getName() + " (damage: " + std::to_string(m_player->getWeapons()[i]->getDamage()) + ")" ;
        }
    }
    if (m_player->getWeapons()[0] == nullptr && m_player->getWeapons()[1] == nullptr ){
        std::cout << "-- empty --" << std::endl;
    } else {
        std::cout << str << std::endl;
    }
    std::cout << "*************************************************" << std::endl;
}

//Function for displaying text "YOU WIN". Called after winning the game.
void Game::printWin(){
    std::cout << "\n"
                 " __     ______  _    _  __          _______ _   _ _ \n"
                 " \\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | | |\n"
                 "  \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| | |\n"
                 "   \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` | |\n"
                 "    | | | |__| | |__| |    \\  /\\  /   _| |_| |\\  |_|\n"
                 "    |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_(_)\n"
                 "                                                    \n"
                 "                                                    " << std::endl;
}
