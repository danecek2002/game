//
// Created by xefanova on 03.05.2023.
//

#include "GameStorage.h"

//Function for displaying text "Game Menu". Called in the main menu of program
void GameStorage::printStartMenu(){
    std::cout << "\n"
                 "  __  __  __ __ ___   __ __ ___ __  _ _  _  \n"
                 " / _]/  \\|  V  | __| |  V  | __|  \\| | || | \n"
                 "| [/\\ /\\ | \\_/ | _|  | \\_/ | _|| | ' | \\/ | \n"
                 " \\__/_||_|_| |_|___| |_| |_|___|_|\\__|\\__/  \n" << std::endl;
}

//Vector of saved games
std::vector<Game*> GameStorage::s_games;

//Function for displaying main menu of program. The static public function that called by the user in main.cpp
void GameStorage::menuGame(){
    printStartMenu();
    int choose;
    std::cout << "Welcome to console game Witcher!" << std::endl;
    std::cout << "Select and enter the number: " << std::endl;
    std::cout << "1 - Start new game" << std::endl;
    std::cout << "2 - Load a saved game" << std::endl;
    std::cout << "3 - Exit" << std::endl;
    while (!(std::cin >> choose) || choose < 1 || choose > 3) {
        std::cerr << "Error: Incorrect number. Please enter a valid number:" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    switch (choose) {
        case 1:
            createGame();
            exit(0);
            break;
        case 2:
            showSavedGames();
            int whichGame;
            std::cout << "Enter the number of saved game to run:" << std::endl;
            while (!(std::cin >> whichGame) || whichGame < 0 || whichGame >= s_games.size()) {
                std::cerr << "Error: Incorrect number. Please enter a valid number:" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            s_games[whichGame]->loadGame();
            exit(0);
            break;
        case 3:
            exit(0);
            break;
    }
}

//Function creates a game, adds it to the vector of saved games and starts this game.
void GameStorage::createGame(){
    std::string gameName;
    std::cout << "Enter a name for the saved game: " << std::endl;
    std::cin >> gameName;
    Game* game = new Game(gameName);
    s_games.push_back(game);
    game->startGame();
}

//Function for displaying saved games
void GameStorage::showSavedGames(){
    if (s_games.empty()){
        std::cerr << "You don't have any saved games." << std::endl;
        GameStorage::menuGame();
    } else {
        std::cout << "All saved games: " << std::endl;
        for (int i = 0; i < s_games.size(); i++) {
            std::cout << i << " - " << s_games[i]->getGameName() << std::endl;
        }
    }
}

std::vector<Game*>& GameStorage::getGames(){
    return s_games;
}

GameStorage::~GameStorage(){
    for (int i = 0; i < s_games.size(); i++){
        s_games.erase(s_games.begin() + i);
    }
}
