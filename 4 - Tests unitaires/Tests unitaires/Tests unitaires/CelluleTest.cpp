#include <gtest/gtest.h>
#include "Cellule.h"

// Test du constructeur par défaut
TEST(CelluleTest, ConstructeurParDefaut) {
    Cellule cellule;
    EXPECT_FALSE(cellule.getEtat());
}

// Test du constructeur avec paramètres
TEST(CelluleTest, ConstructeurAvecParametres) {
    Cellule cellule(true, 1, 2);
    EXPECT_TRUE(cellule.getEtat());
}

// Test de changeEtat
TEST(CelluleTest, ChangeEtat) {
    Cellule cellule(false, 0, 0);
    EXPECT_FALSE(cellule.getEtat());
    cellule.changeEtat();
    EXPECT_TRUE(cellule.getEtat());
    cellule.changeEtat();
    EXPECT_FALSE(cellule.getEtat());
}