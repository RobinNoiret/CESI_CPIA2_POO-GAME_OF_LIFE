#ifndef MODE_GRAPHIQUE_H
#define MODE_GRAPHIQUE_H

#include "Mode.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

class ModeGraphique : public Mode {
private:
    Game& jeu;
    sf::RenderWindow fenetre;
    const int TAILLE_CELLULE = 10;
    float delai;

public:
    ModeGraphique(Game& gameRef, float delaiIterations);
    void executer(int iterations) override;
    void dessinerGrille();
};

#endif