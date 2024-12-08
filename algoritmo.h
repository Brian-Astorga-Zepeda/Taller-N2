//
// Created by Brian Astorga on 08-12-2024.
//

#ifndef MINMAX_H
#define MINMAX_H
#include <utility>

#include "tablero.h"


class algoritmo {
public:
    algoritmo();

    std::pair<int,int> mejorMov(tablero tab, bool alfabeta);

    int minimax(tablero tab, int profundidad, bool max);

    int alfabeta(tablero tab, int profundidad, bool max, int alfa, int beta);


};



#endif //MINMAX_H
