/****************************************************
* Pontificia Universidad Javeriana
* Docente: J. Corredor
* Autor: Juan José Ballesteros
* Fecha: 30/10/2025
* Materia: Sistemas Operativos
* Objetivo: Implementar el uso de hilos (pthread) para realizar
*            cálculos en paralelo. En este caso, cada hilo calcula
*            el cuadrado de un número y lo suma a una variable
*            compartida que acumula el total.
* 
* Nota importante: El código no es 100 % correcto porque no utiliza
*                  mecanismos de sincronización (como mutex) para
*                  proteger el acceso a la variable global 'acumulado'.
*                  Esto puede generar condiciones de carrera. ( RACE CONDITION)
****************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Variable global compartida entre hilos
int acumulado = 0;

// Función ejecutada por cada hilo: calcula el cuadrado y lo suma
void* cuadrados(void *x) {
    int xi = (intptr_t)x;  // Se castea el argumento a entero
    acumulado += xi * xi;  // Se modifica la variable global (no seguro)
    return NULL;
}

int main() {
    pthread_t WorkersTh[20]; // Arreglo de identificadores de hilos

    // Creación de los 20 hilos
    for (int i = 0; i < 20; i++)
        pthread_create(&WorkersTh[i], NULL, &cuadrados, (void *)(intptr_t)(i + 1));

    // Espera a que todos los hilos terminen su ejecución
    for (int i = 0; i < 20; i++) {
        void *retval;
        pthread_join(WorkersTh[i], &retval);
    }

    printf("Valor suma cuadrados = %d \n", acumulado);
    return 0;
}