//
// Created by Brian Astorga on 08-12-2024.
//

#include "tablero.h"

#include <iostream>

tablero::tablero() : tab(3,vector<char>(3,'.')){ }

void tablero::print() {
    for(const auto& fila : tab) {
        for(const auto& cell : fila) {
            std::cout << "|" << cell << "|";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool tablero::empate() {
    for(const auto& fila : tab) {
        for(const auto& cell : fila) {
            if(cell == '.'){ return false; }
        }
    }
    return true;
}

bool tablero::movimiento(int x, int y, char jugador) {
    if(x < 0 || x >= 3 || y < 0 || y >= 3 || tab[x][y] != '.') {
        std:cout << "movimiento invalido \n";
        return false;
    }
    tab[x][y] = jugador;
    return true;
}

char tablero::ganador() {
    for(int i = 0; i < 3; i++) {
        if(tab[i][0] != '.' && tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2]) {
            return tab[i][0];
        }
        if(tab[0][i] != '.' && tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i]) {
            return tab[0][i];
        }
    }
    if(tab[0][0] != '.' && tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]) {

        return tab[0][0];
    }
    if(tab[0][2] != '.' && tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]) {

        return tab[0][2];
    }
    return 'E';
}
void tablero::deshacerMov(int x, int y) {
    tab[x][y] = '.';
}
char tablero::getCell(int x, int y) {
    return tab[x][y];
}

tablero::~tablero() {

}

