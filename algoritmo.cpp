//
// Created by Brian Astorga on 08-12-2024.
//

#include "algoritmo.h"
#include "tablero.h"

algoritmo::algoritmo() {
}

int algoritmo::alfabeta(tablero tab, int profundidad, bool maximo, int alfa, int beta) {
    char result = tab.ganador();
    if (result == 'X') { return -10 + profundidad; }
    if (result == 'O') { return 10 - profundidad; }
    if (maximo) {
        int mejorPuntaje = -9999;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tab.getCell(i, j) == '.') {
                    tab.movimiento(i, j, 'O');
                    int puntaje = alfabeta(tab, profundidad + 1, false, alfa, beta);
                    tab.deshacerMov(i, j);
                    mejorPuntaje = max(mejorPuntaje, puntaje);
                    alfa = max(alfa, mejorPuntaje);
                    if (alfa >= beta) {
                        return mejorPuntaje;
                    }
                }
            }
        }
        return mejorPuntaje;
    } else {
        int mejorPuntaje = 9999;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tab.getCell(i, j) == '.') {
                    tab.movimiento(i, j, 'X');
                    int puntaje = alfabeta(tab, profundidad + 1, true, alfa, beta);
                    tab.deshacerMov(i, j);
                    mejorPuntaje = min(mejorPuntaje, puntaje);
                    beta = min(beta, mejorPuntaje);
                    if (alfa >= beta) {
                        return mejorPuntaje;
                    }
                }
            }
        }
        return mejorPuntaje;
    }
    return 0 + profundidad;
}

int algoritmo::minimax(tablero tab, int profundidad, bool maximo) {
    char result = tab.ganador();
    if (result == 'X') { return -10; }
    if (result == 'O') { return 10; }

    if (maximo) {
        int mejorPuntaje = -9999;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tab.getCell(i, j) == '.') {
                    tab.movimiento(i, j, 'O');
                    int puntaje = minimax(tab, profundidad + 1, false);
                    tab.deshacerMov(i, j);
                    mejorPuntaje = max(mejorPuntaje, puntaje);
                }
            }
        }
        return mejorPuntaje;
    } else {
        int mejorPuntaje = 9999;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tab.getCell(i, j) == '.') {
                    tab.movimiento(i, j, 'X');
                    int puntaje = minimax(tab, profundidad + 1, true);
                    tab.deshacerMov(i, j);
                    mejorPuntaje = min(mejorPuntaje, puntaje);
                }
            }
        }
        return mejorPuntaje;
    }
}

std::pair<int, int> algoritmo::mejorMov(tablero tab, bool pruning) {
    int mejorPunt = -999;
    pair<int, int> mejorMov = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tab.getCell(i, j) == '.') {
                if (pruning) {
                    tab.movimiento(i, j, 'O');
                    int puntaje = alfabeta(tab, 0, false, -999, 999);
                    tab.deshacerMov(i, j);
                    if (puntaje > mejorPunt) {
                        mejorPunt = puntaje;
                        mejorMov = {i, j};
                    }
                } else {
                    tab.movimiento(i, j, 'O');
                    int puntaje = minimax(tab, 0, false);
                    tab.deshacerMov(i, j);
                    if (puntaje > mejorPunt) {
                        mejorPunt = puntaje;
                        mejorMov = {i, j};
                    }
                }
            }
        }
    }
    return mejorMov;
}
