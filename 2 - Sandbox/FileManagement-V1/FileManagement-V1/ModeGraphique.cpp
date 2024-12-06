#include "ModeGraphique.h"
#include <iostream>

using namespace std;

ModeGraphique::ModeGraphique(Game& gameRef, float delaiIterations)
    : jeu(gameRef)
{
    delai = delaiIterations;
    pause = false;

    const Grille& grille = jeu.getGrille();

    fenetre.create(
        sf::VideoMode(grille.getColonnes() * TAILLE_CELLULE,
            grille.getLignes() * TAILLE_CELLULE),
        "Jeu de la Vie"
    );
    if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
        cout << "Erreur chargement police" << endl;
    }
}

void ModeGraphique::executer(int iterations) {
    int generationActuelle = 0;
    sf::Clock clock;
    jeu.sauvegarderEtat(0);

    while (fenetre.isOpen() && generationActuelle < iterations) {
        sf::Event event;
        while (fenetre.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                fenetre.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space)
                    pause = !pause;
            }
        }

        if (!pause && clock.getElapsedTime().asSeconds() >= delai) {
            jeu.nextGeneration();
            generationActuelle++;
            clock.restart();
        }

        fenetre.clear(sf::Color::White);
        dessinerGrille();
        afficherInformations(generationActuelle, iterations);
        fenetre.display();
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

void ModeGraphique::afficherInformations(int generation, int totalGenerations) {
    // Rectangle de fond pour la zone UI
    sf::RectangleShape fond;
    fond.setSize(sf::Vector2f(fenetre.getSize().x, UI_HEIGHT));
    fond.setPosition(0, fenetre.getSize().y - UI_HEIGHT);
    fond.setFillColor(sf::Color(240, 240, 240));
    fenetre.draw(fond);

    // Texte des informations
    sf::Text informations;
    informations.setFont(font);
    informations.setCharacterSize(15);
    informations.setFillColor(sf::Color::Black);
    informations.setPosition(10, fenetre.getSize().y - 25);

    std::string texte = "Generation: " + std::to_string(generation) + "/" + std::to_string(totalGenerations);
    texte += " | Grille: " + std::string(jeu.getGrille().getTorique() ? "Torique" : "Non-torique");
    texte += "                                                      " + std::string(pause ? "PAUSE" : "EN COURS");
    informations.setString(texte);

    fenetre.draw(informations);
}