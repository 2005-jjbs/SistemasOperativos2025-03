/**********************************************
* Pontificia Universidad Javeriana
* Docente: J.Corredor, PhD
* Autor: Juan Ballesteros Suarez
* Fecha: Octubre 16 2025
* Materia: Sistemas Operativos
* Tema: Implementacion de Productor Consumidor a partir de pipe named
*  
* **********************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Definir el nombre del archivo FIFO
#define FIFO_FILE "/tmp/fifo_twoway"

// Función para invertir una cadena
void reverse_string(char *);

int main() {
   int fd;
   char readbuf[80];
   char end[10];
   int to_end;
   int read_bytes;

   /* Crear la FIFO si no existe */
   if (mkfifo(FIFO_FILE, 0640) == -1) {
       // No aborta si ya existe
       perror("Aviso o error al crear FIFO (puede existir)");
   }

   strcpy(end, "end");
   // Abrir FIFO existente (creada por el servidor)   
   fd = open(FIFO_FILE, O_RDWR);
   if (fd == -1) {
       perror("Error al abrir FIFO");
       exit(EXIT_FAILURE);
   }

// Bucle principal
   while (1) {
      read_bytes = read(fd, readbuf, sizeof(readbuf));
      if (read_bytes <= 0) {
         perror("Error al leer del FIFO o conexión cerrada");
         break;
      }

      readbuf[read_bytes] = '\0';
      printf("FIFOSERVER: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));

      to_end = strcmp(readbuf, end);

      if (to_end == 0) {
         close(fd);
         break;
      }

      reverse_string(readbuf);
      printf("FIFOSERVER: Sending Reversed String: \"%s\" and length is %d\n", readbuf, (int) strlen(readbuf));
      write(fd, readbuf, strlen(readbuf));

      /* Espera breve para permitir que el otro proceso lea antes de continuar */
      sleep(2);
   }

   return 0;
}

// Función para invertir una cadena
void reverse_string(char *str) {
   int last, limit, first;
   char temp;
   last = strlen(str) - 1;
   limit = last / 2;
   first = 0;

   while (first < last) {
      temp = str[first];
      str[first] = str[last];
      str[last] = temp;
      first++;
      last--;
   }
   return;
}
