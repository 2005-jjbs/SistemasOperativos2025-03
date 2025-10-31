/****************************************************
 * Pontificia Universidad Javeriana
 * Docente: J. Corredor
 * Autor: Juan José Ballesteros
 * Fecha: 30/10/2025
 * Materia: Sistemas Operativos
 * Objetivo: Uso de mutex y variables de condición para 
 *           sincronizar la ejecución de hilos en orden,
 *           evitando el acceso simultáneo y el desorden
 *           en la ejecución (sin deadlock).
 ****************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variables globales
pthread_t tid[3];
int turno = 1;  // Indica qué hilo debe ejecutarse
pthread_mutex_t bloqueo = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condicion = PTHREAD_COND_INITIALIZER;


void *compute(void *arg) {
    int id = *(int *)arg;

    pthread_mutex_lock(&bloqueo);

    // Esperar hasta que sea el turno de este hilo
    while (turno != id) {
        pthread_cond_wait(&condicion, &bloqueo);
    }

    printf("Job %d has started\n", id);
    pthread_mutex_unlock(&bloqueo);

    // Simula trabajo (no se bloquea el mutex)
    for (unsigned long i = 0; i < 0xFFFFFFF; i++);

    pthread_mutex_lock(&bloqueo);
    printf("Job %d has finished\n", id);

    turno++;  // Permitir que el siguiente hilo se ejecute
    pthread_cond_broadcast(&condicion); // Despierta al siguiente
    pthread_mutex_unlock(&bloqueo);

    return NULL;
}


// Proceso principal
int main() {
    int ids[3] = {1, 2, 3};
    int error;

    // Crear los hilos
    for (int i = 0; i < 3; i++) {
        error = pthread_create(&tid[i], NULL, &compute, &ids[i]);
        if (error != 0)
            printf("\nError: Hilo no creado: %s\n", strerror(error));
    }

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < 3; i++) {
        pthread_join(tid[i], NULL);
    }

    // Liberar recursos
    pthread_mutex_destroy(&bloqueo);
    pthread_cond_destroy(&condicion);

    return 0;
}
