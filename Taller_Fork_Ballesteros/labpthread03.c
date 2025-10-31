/****************************************************
* Pontificia Universidad Javeriana
* Docente: J. Corredor
* Autor: Juan José Ballesteros
* Fecha: 30/10/2025
* Materia: Sistemas Operativos
* Objetivo: Uso de mutex para sincronizar procesos
*           mediante señal de inicializacion y de espera
*           evitando el Deadlock.
****************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//Se declara el contador de mutex, la condicion mutex y condition de inicializacion
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;

int count = 0;

#define COUNT_DONE 15
#define COUNT_HALTI 4
#define COUNT_HALT2 11

void *count01() {
    for (;;) {
        // Bloquea el mutex de condición
        pthread_mutex_lock(&condition_mutex);
        // Espera si el contador está entre COUNT_HALTI y COUNT_HALT2
        while (count >= COUNT_HALTI && count <= COUNT_HALT2) {
            pthread_cond_wait(&condition_cond, &condition_mutex);
        }
        pthread_mutex_unlock(&condition_mutex);

        // Bloquea el mutex del contador
        pthread_mutex_lock(&count_mutex);
        count++;
        printf("Counter value functionCount => 01 <=: %d\n", count);
        pthread_mutex_unlock(&count_mutex);

        // Si el contador alcanza el valor definido en COUNT_DONE, termina
        if (count >= COUNT_DONE) return (NULL);
    }
}

void *count02() {
    for (;;) {
        pthread_mutex_lock(&condition_mutex);
        // Envía una señal si el contador está entre los límites definidos
        if (count < COUNT_HALTI || count > COUNT_HALT2) {
            pthread_cond_signal(&condition_cond);
        }
        pthread_mutex_unlock(&condition_mutex);

        // Bloquea el mutex del contador
        pthread_mutex_lock(&count_mutex);
        count++;
        printf("Counter value functionCount => 02 <=: %d\n", count);
        pthread_mutex_unlock(&count_mutex);

        // Si el contador alcanza el valor definido en COUNT_DONE, termina
        if (count >= COUNT_DONE) return (NULL);
    }
}

void main() {
    pthread_t thread1, thread2;

    // Crea los dos hilos
    pthread_create(&thread1, NULL, &count01, NULL);
    pthread_create(&thread2, NULL, &count02, NULL);

    // Espera que ambos hilos terminen su ejecución
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Termina el programa
    exit(0);
}
