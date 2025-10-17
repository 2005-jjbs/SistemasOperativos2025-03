/**********************************************
* Pontificia Universidad Javeriana
* Docente: J.Corredor, PhD
* Autor: Juan Ballesteros Suarez
* Fecha: Octubre 16 2025
* Materia: Sistemas Operativos
* Tema: Implementacion de Productor Consumidor a partir de pipe named
* - Cliente - 
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

// Función principal
int main() {
   int fd;
   int end_process;
   int stringlen;
   int read_bytes;
   char readbuf[80];
   char end_str[5];

   // Mensaje de bienvenida
   printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");

   // Abrir FIFO existente (creada por el servidor) 
   fd = open(FIFO_FILE, O_RDWR);
   if (fd == -1) {
      perror("Error al abrir FIFO");
      exit(EXIT_FAILURE);
   }

   // Cadena para finalizar el proceso
   strcpy(end_str, "end");

   // Bucle principal

   while (1) {
      printf("Enter string: ");
      // Leer entrada del usuario
      if (fgets(readbuf, sizeof(readbuf), stdin) == NULL) {
         printf("Error leyendo entrada\n");
         break;
      }
      
      stringlen = strlen(readbuf);

      // Eliminar salto de línea si existe
      if (stringlen > 0 && readbuf[stringlen - 1] == '\n') {
         readbuf[stringlen - 1] = '\0';
      }
      // Comparar con la cadena de fin
      end_process = strcmp(readbuf, end_str);

      if (end_process != 0) {
         // Enviar cadena al servidor
         if (write(fd, readbuf, strlen(readbuf)) == -1) {
            perror("Error al escribir en FIFO");
            break;
         }

         // Imprimir información del mensaje enviado
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n",
                readbuf, (int)strlen(readbuf));

         // Leer respuesta del servidor
         read_bytes = read(fd, readbuf, sizeof(readbuf));
         if (read_bytes <= 0) {
            perror("Error o cierre al leer FIFO");
            break;
         }

         readbuf[read_bytes] = '\0';
         // Imprimir la cadena recibida
         printf("FIFOCLIENT: Received string: \"%s\" and length is %d\n",
                readbuf, (int)strlen(readbuf));

      } else {
         // Enviar 'end' y finalizar
         write(fd, readbuf, strlen(readbuf));
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
         close(fd);
         break;
      }
   }

   return 0;
}
