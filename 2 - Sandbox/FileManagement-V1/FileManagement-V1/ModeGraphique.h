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
    float delai;

    const int UI_HEIGHT = 30;
    sf::Font font;
    bool pause;
    void afficherInformations(int generation, int totalGenerations);

public:
    ModeGraphique(Game& gameRef, float delaiIterations);
    void executer(int iterations) override;
    void dessinerGrille();
};

#endif