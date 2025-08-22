/*******************************************************************************
 *			 Pontificia Universidad Javeriana *
 *    =======================================================================  *
 *                                                                             *
 * Autor: Juan Ballesteros S                                                   *
 * Fecha: 21-08-2025                                                           *
 * Materia: Sistemas Operativos                                                *
 * Docente J.Corredor, PhD                                                     *
 * Objetivo: Reto 01 documentado                                               *
 *                                                                             *
 * Descripción: Modelo de plantilla                                            *
 *                                                                             *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declaración de punteros
  char *p;
  char *q = NULL;
  // Asignación de memoria
  p = (char *)malloc(100 * sizeof(char));
  q = (char *)malloc(100 * sizeof(char));

  // Verificación de la asignación de memoria
  printf("Adress of p = %s\n", p);

  // Copia de cadenas, se aloja en la variable p el mensaje que se encuentra entre ""
  strcpy(p, "Hello I'm the best in Operating Systems");
  // Se imprime lo que se alojo en la variable p
  printf("%s\n", p);

  //Se copia la palabra Goodye en la variable q
  printf("About to copy \"Goodbye\" to q\n");
  strcpy(q, "Goodbye");
  //Se imprime lo que se alojo en la variable q (Goodbye)
  printf("%s\n", q);

  // Liberación de memoria
  free(p);
  free(q);

  return 0;
}