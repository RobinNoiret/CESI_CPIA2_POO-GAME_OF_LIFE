#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
private:
    bool etat;
    int x;
    int y;

public:
    // Constructeur
    Cellule(bool etatInitial = false, int posX = 0, int posY = 0);

    // Getters
    bool getEtat() const;
    int getX() const;
    int getY() const;

    // Setters
    void changeEtat();
    void setPosition(int posX, int posY);
};

#endif // CELLULE_H