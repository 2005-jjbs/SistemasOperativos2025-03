/* *******************************************
* Pontificia Universidad Javeriana
* Autor: Juan José Ballesteros
* Fecha: 09/10/2025
* Materia: Sistemas operativos
* Temas: Comunicacion entre procesos con tuberias (PIPES)
- Comunicacion entre un proceso padre e hijo a traves de una tuberia
********************************************* */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t hijo_PID;

// Crear la tubería de comunicación
if (pipe(pipefd) == -1) {
    perror("Error al crear la tubería");
    exit(EXIT_FAILURE);
}

// Crear el proceso hijo
hijo_PID = fork();  // fork() duplica el proceso actual

if (hijo_PID == -1) {
    perror("Error en fork");
    exit(EXIT_FAILURE);
}

// ---- PROCESO HIJO ----
if (hijo_PID == 0) {
    printf("\n[HIJO] Mi PID es %d, el PID de mi padre es %d\n", getpid(), getppid());

    close(pipefd[1]); // El hijo no escribe, solo lee

    // Leer mensaje desde el pipe
    char mensaje[100];
    ssize_t lecturaB = read(pipefd[0], mensaje, sizeof(mensaje));

    if (lecturaB == -1) {
        perror("Error al leer del pipe");
        exit(EXIT_FAILURE);
    }

    printf("[HIJO] Leí %zd bytes: \"%s\"\n", lecturaB, mensaje);

    close(pipefd[0]); // Cerrar extremo de lectura
} 

// ---- PROCESO PADRE ----
else {
    printf("\n[PADRE] Mi PID es %d, el PID de mi hijo es %d\n", getpid(), hijo_PID);

    close(pipefd[0]); // El padre no lee, solo escribe

    // Mensaje que el padre enviará al hijo
    char mensaje[] = "Hijo, voy a darte plata y gaseosas";

    // Enviar mensaje a través del pipe
    ssize_t escrituraB = write(pipefd[1], mensaje, strlen(mensaje) + 1);

    if (escrituraB == -1) {
        perror("Error al escribir en el pipe");
        exit(EXIT_FAILURE);
    }

    printf("[PADRE] Escribí %zd bytes en el pipe.\n", escrituraB);

    close(pipefd[1]); // Cerrar extremo de escritura

    wait(NULL); // Espera a que el hijo termine
}

// Ambos procesos terminan aquí
printf("\n[FIN] Proceso con PID %d finalizado.\n", getpid());

return 0;