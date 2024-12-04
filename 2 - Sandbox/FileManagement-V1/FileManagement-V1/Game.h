#ifndef GAME_H
#define GAME_H

#include "Grille.h"
#include <string>
#include <memory>

class Game {
private:
    Grille grille;
    int iterations;

public:
    Game(const std::string& file);
    void GameModeConsole();
    void GameModeGraphique();
    void nextGeneration();
    const Grille& getGrille() const;
};

#endif