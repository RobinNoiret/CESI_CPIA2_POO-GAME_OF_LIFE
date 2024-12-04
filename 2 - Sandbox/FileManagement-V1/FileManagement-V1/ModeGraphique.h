#ifndef MODE_GRAPHIQUE_H
#define MODE_GRAPHIQUE_H

#include "Mode.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

class ModeGraphique : public Mode {
private:
    Game& jeu;
    sf::RenderWindow fenetre;
    const int TAILLE_CELLULE = 20;

public:
    ModeGraphique(Game& gameRef);
    void executer(int iterations) override;
    void dessinerGrille();
};

#endif