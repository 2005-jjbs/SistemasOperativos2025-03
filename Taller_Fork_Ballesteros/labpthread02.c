/****************************************************
 * Pontificia Universidad Javeriana
 * Docente: J. Corredor
 * Autor: Juan José Ballesteros
 * Fecha: 23/10/2025
 * Materia: Sistemas Operativos
 * Objetivo: Crear 10 hilos y ver que su ejecucción es
 *           independiente uno del otro, se crean sin
 *	    un orden especifico.
 ****************************************************/

#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Se definen la cantidad de hilos a crear en este caso 10
#define NTHREADS 10
// Se inicializa el mutex para sincronizacion entre hilos
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

// Funcion que ejecuta cada hilo
void *thread_function(void *arg) {
  int i = *(int *)(arg);
  // Imprime el numero del hilo y su ID
  printf("Thread number: %d | Thread ID %ld\n", i, pthread_self());
  // Se bloquea el mutex para garantizar que solo un hilo acceda al contador a
  // la vez
  pthread_mutex_lock(&mutex1);
  counter++;
  // Se libera el mutex para que otros hilos puedan acceder al contador
  pthread_mutex_unlock(&mutex1);
}

void main() {

  // Arreglo para almacenar los identificadores de los hilos
  pthread_t thread_id[NTHREADS];
  int i, j;
  // Ciclo que crea 10 hilos, no hay un orden pero es mutuamente excluyente
  for (i = 0; i < NTHREADS; i++) {
    pthread_create(&thread_id[i], NULL, thread_function, &i);
  }

  // Ciclo para esperar que todos los hilos terminen
  for (j = 0; j < NTHREADS; j++) {
    pthread_join(thread_id[j], NULL);
  }

  // Imprime el valor final del contador
  printf("Final counter value: %d\n", counter);
    exit(0);
}
