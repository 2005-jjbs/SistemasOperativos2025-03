/****************************************************
* Pontificia Universidad Javeriana
* Docente: J. Corredor
* Autor: Juan José Ballesteros
* Fecha: 23/10/2025
* Materia: Sistemas Operativos
* Objetivo: Crear dos hilos y ver que su ejecucción es
*           independiente uno del otro, se crean sin
*	    un orden especifico.
****************************************************/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

//Funcion que imprime un mensaje
void *print_message_function( void *ptr ) {
    char *message;
    message = (char *) ptr;
    printf("%s \n", message);
}

void main() {
    //Se crean dos hilos
    pthread_t thread1, thread2;
    //Se crean dos mensajes de tipo char
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1, iret2;

    /* Create independent threads each of which will execute function */
    iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
    iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);
    //Retorna de manera independiente lo que hay en cada hilo
    printf("Thread 1 returns: %d\n", iret1);
    printf("Thread 2 returns: %d\n", iret2);
    exit(0);
}
