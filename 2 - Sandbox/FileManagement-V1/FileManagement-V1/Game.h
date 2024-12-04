#ifndef GAME_H
#define GAME_H

#include "Grille.h"
#include "LogsManagement.h"

// Includes bibliothèques
#include <string>           // Fournit la classe string pour manipuler les chaînes de caractères

class Game {
private:
    Grille grille;          // Grille du jeu
    int iterations;         // Nombre d'itérations à simuler
    std::string nomFichier; // Nom du fichier d'entrée
    LogsManagement logs;    // gestionnaire de logs

public:
    // Constructeur
    Game(const std::string& file);

    // Méthodes des modes
    void GameModeConsole();
    void GameModeGraphique();

    // Méthodes métiers
    void nextGeneration();
    const Grille& getGrille() const;
    void sauvegarderEtat(int numeroGeneration);
};

#endif