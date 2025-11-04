/****************************************************
* Pontificia Universidad Javeriana
* Docente: J. Corredor
* Autor: Juan José Ballesteros
* Fecha: 30/10/2025
* Materia: Sistemas Operativos
* Objetivo: Mostrar el uso de hilos, mutex y variables de
*           condición (pthread_cond_t). Se tienen dos funciones:
*           una para asignar un valor y otra para reportarlo.
*           El hilo que reporta espera hasta ser notificado
*           por el hilo que asigna

*           El laboratorio presenta CC (condicion de carrera), ya que cada 100 veces que se ejecuta
*           el hilo reportar no se ejecuta el hilo asignar, por lo que no se notifica al hilo reportar.
****************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Variables globales
int valor = 100;
bool notificar = false;

//BloqueoCC: condicion de carrera
//condiCC: condicion de inicializacion
pthread_mutex_t bloqueoCC = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condiCC = PTHREAD_COND_INITIALIZER;

// Función REPORTAR
void *reportar(void *nousada) {

    //pthread_mutex_lock(&bloqueoCC);
    // Espera a ser notificado por el hilo que asigna el valor
    //while(!notificar){
    //    pthread_cond_wait(&condiCC, &bloqueoCC);
    //}

    // Imprime el valor asignado por el otro hilo
    printf("\n\tEl valor es: %d\n", valor);
    //pthread_mutex_unlock(&bloqueoCC);
    return NULL;
}

// Función ASIGNAR
void *asignar(void *nousada){
    valor = 20;
    
    return NULL;
}

// Proceso principal
int main() {
    //Declaracion y creacion 
    pthread_t reporte, asigne;
    pthread_create(&reporte, NULL, &reportar, NULL);
    pthread_create(&asigne, NULL, &asignar, NULL);

    //creo variable para recojer valor al esperar
    void *nousada;
    pthread_join(reporte, &nousada);
    pthread_join(asigne, &nousada);

    // Liberar recursos
    pthread_mutex_destroy(&bloqueoCC);
    pthread_cond_destroy(&condiCC);
    
    return 0;
}
