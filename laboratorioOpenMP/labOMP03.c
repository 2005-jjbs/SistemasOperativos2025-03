/********************************************************************************************
* Pontificia Universidad Javeriana
*
* Autor: Juan José Ballesteros
* Materia: Sistemas Operativos
* Docente: J. Corredor
* Tema: Introducción a OpenMP
* Descripción: Ejemplo del uso de la directiva "parallel for" con OpenMP.
*
* El programa demuestra el uso de  `private`, que permiten que cada hilo trabaje con su propia copia de las
*              variables indicadas, evitando interferencias entre ellos.
*              Se hace un bucle de 1000 veces, y se observa cómo
*              las variables privadas afectan el resultado final fuera de
*              la región paralela.
********************************************************************************************/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


//Programa Principal
int main() {

//Declaración de variables
    int i;
    const int N = 1000;
    int a = 50;
    int b = 0;

    // Región paralela: cada hilo tiene su propia copia de i y a
    #pragma omp parallel for private(i) private(a)
    for (i = 0; i < N; i++) {
        b = a + i;  // Cada hilo calcula de forma independiente
    }

    // Valor esperado fuera del bucle
    printf("a = %d  b = %d (Se espera a = 50, b = 1049)\n", a, b);

    return 0;
}
