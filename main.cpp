#include <iostream>
// Brian Astorga 21.862.127-9
// Matias Gutierrez 21.733.537-K

#include <chrono>

#include "algoritmo.h"
#include "tablero.h"

int main()
{
    tablero board;
    algoritmo ia;

    while(true) {
        board.print();
        int x;
        int y;
        cout << "Ingrese movimiento";
        cin >> x >> y;

        if(!board.movimiento(x,y,'X')) {
            continue;
        }

        board.print();
        auto start = std::chrono::high_resolution_clock::now();
        ia.mejorMov(board, false);
        auto stop = std::chrono::high_resolution_clock::now();
        auto mininmax = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        auto inicio = std::chrono::high_resolution_clock::now();
        pair<int,int> mov = ia.mejorMov(board, true);
        auto final = std::chrono::high_resolution_clock::now();
        auto alfanbeta = std::chrono::duration_cast<std::chrono::milliseconds>(final - inicio);
        board.movimiento(mov.first, mov.second, 'O');
        cout << "El algoritmo sin alfabeta pruning se demoro: " << mininmax.count() << endl;
        cout << "Con alfabeta pruning se demoro: " << alfanbeta.count() << endl;
        cout << "tuvo entonces una diferencia de: " << mininmax.count() - alfanbeta.count() << endl;
        char win = board.ganador();
        if(win != 'D') {
            board.print();
            if(win == 'X') {
                cout << "Ganaste!" << endl;
                break;
            }
            else if(win == 'O') {
                cout << "Perdiste!" << endl;
                break;
            }
        }
        cout << win << endl;

    }
}
