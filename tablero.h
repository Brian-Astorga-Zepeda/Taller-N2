//
// Created by Brian Astorga on 08-12-2024.
//

#ifndef TABLERO_H
#define TABLERO_H

#include <vector>

using namespace std;

class tablero {
    vector<vector<char>> tab;

public:

    tablero();

    void print();
    bool empate();
    char ganador();
    bool movimiento(int x, int y, char jugador);
    void deshacerMov(int x, int y);
    char getCell(int x, int y);
    ~tablero();
};





#endif //TABLERO_H
