#include "ModeGraphique.h"
#include <iostream>

ModeGraphique::ModeGraphique(Game& gameRef) : jeu(gameRef) {
    const Grille& grille = jeu.getGrille();

    // Afficher les dimensions pour debug
    std::cout << "Creation fenetre : " << grille.getColonnes() * TAILLE_CELLULE
        << "x" << grille.getLignes() * TAILLE_CELLULE << std::endl;

    fenetre.create(
        sf::VideoMode(grille.getColonnes() * TAILLE_CELLULE,
            grille.getLignes() * TAILLE_CELLULE),
        "Jeu de la Vie"
    );
}

void ModeGraphique::executer(int iterations) {
    int generationActuelle = 0;
    sf::Clock clock;
    jeu.sauvegarderEtat(0);

    while (fenetre.isOpen() && generationActuelle <= iterations) {
        sf::Event event;
        while (fenetre.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                fenetre.close();
        }

        if (clock.getElapsedTime().asSeconds() >= 1.0f && generationActuelle < iterations) {
            jeu.nextGeneration();
            generationActuelle++;
            jeu.sauvegarderEtat(generationActuelle);
            clock.restart();
        }

        fenetre.clear(sf::Color::White);  // Fond blanc
        dessinerGrille();
        fenetre.display();

        if (generationActuelle >= iterations) {
            sf::sleep(sf::seconds(2));
            fenetre.close();
        }
    }
}

void ModeGraphique::dessinerGrille() {
    const Grille& grille = jeu.getGrille();

    sf::RectangleShape cellule(sf::Vector2f(static_cast<float>(TAILLE_CELLULE - 1),
        static_cast<float>(TAILLE_CELLULE - 1)));

    for (int i = 0; i < grille.getLignes(); i++) {
        for (int j = 0; j < grille.getColonnes(); j++) {
            cellule.setPosition(static_cast<float>(j * TAILLE_CELLULE),
                static_cast<float>(i * TAILLE_CELLULE));

            // Cellules noires pour les vivantes, blanches pour les mortes
            cellule.setFillColor(grille.getCellule(i, j).getEtat() ?
                sf::Color::Black : sf::Color::White);

            // Fine bordure grise pour la grille
            cellule.setOutlineThickness(1);
            cellule.setOutlineColor(sf::Color(200, 200, 200));

            fenetre.draw(cellule);
        }
    }
}