/*******************************************************************************
 *			 Pontificia Universidad Javeriana *
 *    =======================================================================  *
 *                                                                             *
 * Autor: Juan Ballesteros S                                                   *
 * Fecha: 21-08-2025                                                           *
 * Materia: Sistemas Operativos                                                *
 * Docente J.Corredor, PhD                                                     *
 * Objetivo: Reto 04 documentado                                               *
 *                                                                             *
 * Descripción: Memoria Dinamica                                               *
 *                                                                             *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  //declaracion de variables y de puntero ptr de tipo enter
  int n, i, *ptr, sum = 0;

  //Mensaje de solicitud al usuario para que ingrese la cantidad de elementos
  printf("Ingrese el numero de elementos: ");
  //Se lee la cantidad de elementos ingresados por el usuario 
  scanf("%d", &n);
  //Se reserva espacio en memoria para la cantidad de elementos que el usuario ingreso
  ptr = (int*) malloc(n * sizeof(int));

  //Verifica que la asignacion de memoria si este disponible, si no muestra error
  if ( ptr == NULL){
    printf("Error! memoria no ubicada.");
    exit(0);
  }

  //Ciclo para que el usuario ingrese los elementos en cada posicion 
  for ( i = 0; i < n; i ++ ){
    printf("Ingrese los elementos :");
    scanf("%d", ptr + i);
    //Suma de los elementos ingresados por el usuario 
    sum += *(ptr + i);
  }
  //Se imprime la suma de los elementos ingresados por el usuario
  printf("Suma = %d", sum);
  printf("\n");

  //Se libera la memoria reservada
  free(ptr);
  return 0;
    
}