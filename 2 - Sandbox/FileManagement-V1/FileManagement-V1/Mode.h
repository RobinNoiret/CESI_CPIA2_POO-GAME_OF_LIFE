#ifndef MODE_H
#define MODE_H

// Méthode abstraite
class Mode {
public:
    virtual ~Mode() = default;
    virtual void executer(int iterations) = 0;
};

#endif