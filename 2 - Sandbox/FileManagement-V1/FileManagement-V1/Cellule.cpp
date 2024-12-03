#include "Cellule.h"

Cellule::Cellule(bool etatInitial, int posX, int posY)
    : etat(etatInitial), x(posX), y(posY) {
}

bool Cellule::getEtat() const {
    return etat;
}

int Cellule::getX() const {
    return x;
}

int Cellule::getY() const {
    return y;
}

void Cellule::changeEtat() {
    etat = !etat;
}

void Cellule::setPosition(int posX, int posY) {
    x = posX;
    y = posY;
}