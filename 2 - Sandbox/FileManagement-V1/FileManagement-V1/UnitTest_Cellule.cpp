#include <cassert>
#include "Cellule.h"
#include <iostream>

using namespace std;

/*
void testConstructeur() {
    cout << "===============================" << endl;
    cout << "Test du constructeur de Cellule" << endl;
    cout << "===============================" << endl;

    cout << "On cree une cellule avec les attributs suivants :" << endl;
    cout << "- etat = false, x = 0, y = 0" << endl;
    Cellule c1;
    cout << "Le resultat du get est :" << endl;
    cout << "- Etat : " << c1.getEtat() << endl;
    cout << "- X : " << c1.getX() << endl;
    cout << "- Y : " << c1.getY() << endl;
    assert(c1.getEtat() == false);
    assert(c1.getX() == 0);
    assert(c1.getY() == 0);
    cout << "Le test est valide" << endl;

    cout << "On cree une cellule avec les attributs suivants :" << endl;
    cout << "- etat = true, x = 5, y = 10" << endl;
    Cellule c2(true, 5, 10);
    cout << "Le resultat du get position est :" << endl;
    cout << "- Etat : " << c2.getEtat() << endl;
    cout << "- X : " << c2.getX() << endl;
    cout << "- Y : " << c2.getY() << endl;
    assert(c2.getEtat() == true);
    assert(c2.getX() == 5);
    assert(c2.getY() == 10);
    cout << "Le test est valide" << endl;
}

void testGettersSetters() {
    cout << "===============================" << endl;
    cout << "Test des accesseurs de Cellule" << endl;
    cout << "===============================" << endl;

    cout << "On cree une cellule avec l'etat initial a false" << endl;
    Cellule c;
    cout << "Le resultat du get de l'etat est : " << c.getEtat() << endl;
    assert(c.getEtat() == false);
    cout << "Le test est valide" << endl;

    cout << "On change l'etat de la cellule" << endl;
    c.changeEtat();
    cout << "Le nouveau resultat du get de l'etat est : " << c.getEtat() << endl;
    assert(c.getEtat() == true);
    cout << "Le test est valide" << endl;

    cout << "On modifie la position de la cellule a (10, 20)" << endl;
    c.setPosition(10, 20);
    cout << "Le resultat des get position est :" << endl;
    cout << "- X : " << c.getX() << endl;
    cout << "- Y : " << c.getY() << endl;
    assert(c.getX() == 10);
    assert(c.getY() == 20);
    cout << "Le test est valide" << endl;
}


int main() {
    testConstructeur();
    testGettersSetters();
    cout << " " << endl;
    cout << "===============================" << endl;
    cout << "Tous les tests ont reussi !" << endl;
    cout << " " << endl;
    return 0;
}
*/