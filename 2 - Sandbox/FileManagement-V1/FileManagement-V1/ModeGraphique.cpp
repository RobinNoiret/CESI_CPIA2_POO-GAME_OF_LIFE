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
    std::cout << "Debut execution mode graphique" << std::endl;

    int generationActuelle = 0;
    sf::Clock clock;

    // Sauvegarde de l'état initial
    jeu.sauvegarderEtat(0);

    while (fenetre.isOpen() && generationActuelle <= iterations) {
        sf::Event event;
        while (fenetre.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                fenetre.close();
        }

        // Mise à jour de la génération toutes les secondes
        if (clock.getElapsedTime().asSeconds() >= 1.0f && generationActuelle < iterations) {
            std::cout << "Generation " << generationActuelle + 1 << std::endl;
            jeu.nextGeneration();
            generationActuelle++;
            // Sauvegarde de l'état après chaque génération
            jeu.sauvegarderEtat(generationActuelle);
            clock.restart();
        }

        // Affichage
        fenetre.clear(sf::Color::White);
        dessinerGrille();
        fenetre.display();

        // Fermer la fenêtre si on a fini toutes les générations
        if (generationActuelle >= iterations) {
            std::cout << "Simulation terminee" << std::endl;
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

            // Debug : utiliser des couleurs plus visibles
            if (grille.getCellule(i, j).getEtat()) {
                cellule.setFillColor(sf::Color::Red);  // Cellules vivantes en rouge
            }
            else {
                cellule.setFillColor(sf::Color::Green);  // Cellules mortes en vert
            }

            cellule.setOutlineThickness(1);
            cellule.setOutlineColor(sf::Color::Black);
            fenetre.draw(cellule);
        }
    }
}