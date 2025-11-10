/********************************************************************************************
* Pontificia Universidad Javeriana
*
* Autor: Juan José Ballesteros
* Materia: Sistemas Operativos
* Docente: J. Corredor
* Tema: Introducción a OpenMP
* Descripción: Ejemplo del uso de la directiva "parallel for" con las cláusulas `private`en OpenMP.
*	Este programa muestra cómo al declarar las variables i, a y b como privadas,
*	cada hilo obtiene su propia copia independiente de estas variables dentro de la región paralela,
*	evitando condiciones de carrera.
*
*       Pero, dado que b es privada, su valor no se acumula fuera de la región
*       paralela, por lo que el resultado final impreso no refleja el valor esperado
*       de la ejecución secuencial.
********************************************************************************************/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    const int N = 1000;
    int a = 50;
    int b = 0;

    // Región paralela con bucle for distribuido entre hilos
    // Cada hilo tiene su propia copia de i, a y b
    #pragma omp parallel for private(i) private(a) private(b)
    for (i = 0; i < N; i++) {
        b = a + i;  // Cada hilo trabaja con sus propias copias de las variables
    }

    // Impresión de resultados fuera de la región paralela
    printf("a = %d  b = %d (Se espera a = 50, b = 1049)\n", a, b);

    return 0;
}
