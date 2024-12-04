#ifndef MODE_CONSOLE_H
#define MODE_CONSOLE_H

#include "Mode.h"
#include "Game.h"

class ModeConsole : public Mode {
private:
    Game& jeu;

public:
    ModeConsole(Game& gameRef);
    void executer(int iterations) override;
    void afficherGrille() const;
};

#endif