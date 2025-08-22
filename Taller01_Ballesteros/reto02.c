/*******************************************************************************
 *			 Pontificia Universidad Javeriana *
 *    =======================================================================  *
 *                                                                             *
 * Autor: Juan Ballesteros S                                                   *
 * Fecha: 21-08-2025                                                           *
 * Materia: Sistemas Operativos                                                *
 * Docente J.Corredor, PhD                                                     *
 * Objetivo: Reto 02 documentado                                               *
 *                                                                             *
 * Descripción: Modelo de plantilla                                            *
 *                                                                             *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
  //declaracion de puntero q
  char *q = NULL;

  //mensaje de solicitud de espacio para la palabra Goodbye
  printf("Requesting space for \"Goodbye\"\n");

  //reserva de espacio en memoria de tamaño del string "Goodbye"
  q = (char *)malloc(strlen("Goodbye") + 1);

  //verificacion de la reserva del espacio para la palabra
  if (!q){
    perror("failed to allocate space because");
    exit(1);
  }

  //mensaje qu copia la palabra Goodbye en el espacio reservado en la variable q
  printf("About to copy \"Goodbye\" to q at Address %s\n",q);

  //Se copia la palbra Goodbye en la variable q
  strcpy(q, "Goodbye");

  //Mensaje en el que se confirma que la palabra Goodbye fue copiada en la variable q
  printf("String copied to q\n");

  //Se imprime lo que hay en la variable q, que seria la palabra Goodbye
  printf("%s\n", q);

  //Se libera la memoria reservada 
  free(q);
  return(0);

  
}
