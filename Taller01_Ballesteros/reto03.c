/*******************************************************************************
 *			 Pontificia Universidad Javeriana *
 *    =======================================================================  *
 *                                                                             *
 * Autor: Juan Ballesteros S                                                   *
 * Fecha: 21-08-2025                                                           *
 * Materia: Sistemas Operativos                                                *
 * Docente J.Corredor, PhD                                                     *
 * Objetivo: Reto 03 documentado                                               *
 *                                                                             *
 * Descripción: Memoria Dinamica                                               *
 *                                                                             *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  //declaracion de puntero ptr de tipo entero
  int *ptr;
  ptr = malloc(15*sizeof(*ptr)); //Se reserva espacio en memoria para 15 enteros

  //Verifica que la asignacion de memoria este disponible
  if( ptr !=NULL){
    *(ptr + 5) = 480; //Se asigna el valor 480 a la posición 5 del arreglo
    *(ptr + 10) = 333; //Se asigna el valor 333 a la posición 10 del arreglo

    //Se imprime el valor de la posición 5 del arreglo
    printf("El valor de la posición 5 es: %d\n", *(ptr + 5));
    //Se imprime el valor de la posición 10 del arreglo
    printf("El valor de la posición 10 es: %d\n", *(ptr + 10));
  }

  //Se libera la memoria reservada
  free(ptr);
  return 0;
}

