/****************************************************
* Pontificia Universidad Javeriana
* Docente: J. Corredor
* Autor: Juan José Ballesteros
* Fecha: 30/10/2025
* Materia: Sistemas Operativos
* Objetivo: Implementar el uso de hilos (pthread) y mecanismos
*           de sincronización (mutex) para realizar operaciones
*           concurrentes de forma segura. Cada hilo calcula el
*           cuadrado de un número y lo suma a una variable global acumulado.  
****************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Variable global compartida entre los hilos
int acumulado = 0;

// Mutex para evitar condición de carrera
pthread_mutex_t bloqueoCC = PTHREAD_MUTEX_INITIALIZER;


// Calcula el cuadrado del número recibido y lo suma a la variable global protegida por el mutex
void* cuadrados(void *x) {
    int xi = (intptr_t)x;  // Convertir el argumento a entero

    //  acceso a la variable compartida
    pthread_mutex_lock(&bloqueoCC);
    acumulado += xi * xi;
    pthread_mutex_unlock(&bloqueoCC);

    return NULL;
}


// MAIN
int main() {
    pthread_t WorkersTh[20]; // Arreglo de hilos

    // Creación de 20 hilos que ejecutan la función cuadrados()
    for (int i = 0; i < 20; i++)
        pthread_create(&WorkersTh[i], NULL, &cuadrados, (void *)(intptr_t)(i + 1));

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < 20; i++) {
        void *retval;
        pthread_join(WorkersTh[i], &retval);
    }

    // Mostrar resultado final
    printf("Valor suma cuadrados = %d\n", acumulado);

    // Liberar el mutex
    pthread_mutex_destroy(&bloqueoCC);

    return 0;
}
