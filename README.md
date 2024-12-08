# Taller-N2

## Integrantes:
-Brian Astorga *21.862.127-9*

-Matías Gutiérrez *21.733.537-k*
### Metodo De Inicio:
> g++ -g -o exec main.cpp algoritmo.cpp tablero.cpp
>
> ./exec

### Introducción al algoritmo Minimax
El algoritmo Minimax es una estrategia usada en juegos de dos jugadores donde ambos tienen información completa del estado del juego, como el clásico tic-tac-toe o “Gato”. Este algoritmo funciona generando un árbol de decisiones que representa todas las posibles jugadas y los resultados de cada una. Los jugadores se alternan en el árbol, donde uno busca maximizar su puntuación (MAX) y el otro intenta minimizarla (MIN).
#### Funcionamiento basico

1.	MAX y MIN:
o	MAX busca las jugadas que le den la mayor puntuación posible.
o	MIN intenta reducir la puntuación de MAX al mínimo.
2.	Evaluación de Estados:
Se asigna un valor a cada estado del juego, que indica si es favorable o no. Por ejemplo, en tic-tac-toe:
o	+10: Si gana MAX.
o	-10: Si gana MIN.
o	0: Si empatan.
3.	Cálculo Recursivo:
El algoritmo analiza todas las posibles jugadas desde el final hacia el inicio, seleccionando las opciones más convenientes para MAX o MIN, según corresponda.
4.	Ejemplo Práctico
Si tenemos este tablero:

|   |   |   |
|---|---|---|
| X | O | X |
| O | X | O |
| _ | X | O |


Es el turno de MAX (X), y su única opción es jugar en la casilla vacía. Aquí, el algoritmo Minimax simula todas las posibles respuestas de MIN después de ese movimiento y asigna puntuaciones a cada estado para decidir qué hacer. En este caso, MAX gana al completar tres "X" en la última fila, así que el movimiento se considera óptimo.

Poda Alfa-Beta
La poda alfa-beta es una mejora del algoritmo Minimax que hace el proceso más eficiente al reducir el número de nodos que se necesitan analizar. Básicamente, permite "podar" ramas del árbol que no cambiarían la decisión final.


Cómo Funciona:

1.	Alfa y Beta:
o	Alfa: El mejor resultado que MAX puede garantizar hasta ese punto.
o	Beta: El mejor resultado que MIN puede asegurar hasta ese punto.
2.	Poda:
Si MAX encuentra una opción mejor que el valor de Beta actual, ya no tiene sentido explorar otras opciones porque MIN no permitirá que ocurra. Lo mismo ocurre al revés con Alfa.
Ejemplo en Tic-Tac-Toe
Volviendo al ejemplo del tablero:
|   |   |   |
|---|---|---|
| X | O | X |
| O | X | O |
| _ | X | O |

Si MAX ya encontró un movimiento que le asegura ganar (+10), no es necesario que el algoritmo siga analizando otras jugadas posibles, ya que el resultado no cambiará. Esto ahorra tiempo y hace el cálculo más rápido.
Con la poda alfa-beta, el algoritmo se enfoca solo en las opciones que realmente tienen impacto en el resultado final, optimizando su rendimiento y reduciendo el tiempo de ejecución.



