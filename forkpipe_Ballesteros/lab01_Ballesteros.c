/**************************************************
 * Pontificia Universidad Javeriana
 * Autor: Juan José Ballesteros	
 * Fecha: 09/10/2025
 * Materia: Sistemas Operativos
 * Tema: Creación de procesos con fork()
 * Descripción: Identificación del proceso padre e hijo
 * 
 **************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {

    // fork() crea un nuevo proceso duplicando el actual.
    int procesoID = fork();
    // Si el valor devuelto es mayor que 0, estamos en el proceso padre
    if (procesoID > 0) {
        printf("Este es el proceso PADRE con ID: %d\n", getpid());
    }
    // Si el valor es exactamente 0, estamos dentro del proceso hijo
    else if (procesoID == 0) {
        printf("Este es el proceso HIJO recién creado con ID: %d\n", getpid());
        printf("El proceso padre de este proceso hijo tiene el ID: %d\n", getppid());
    }
    // Si el valor es negativo, hubo un error al intentar crear el proceso
    else {
        printf("fork() devolvió un valor negativo. No se pudo crear el proceso hijo.\n");
        exit(1); // Terminamos el programa con error
    }

    // Este bloque se ejecuta tanto en el padre como en el hijo
    // (porque ambos continúan la ejecución después del fork)
    printf("\n\nEsta en una unica impresion. Si la llamada l sistema fork() ha tenido exito \n");
  printf("tanto el proceso padre como el proceso hijo se ejecutan simultaneamente, \n");
  printf("y esta impresion aparecera dos veces \n");

    return 0;
}