/*******************************************************************************
 *			 Pontificia Universidad Javeriana *
 *    =======================================================================  *
 *                                                                             *
 * Autor: Juan Ballesteros S                                                   *
 * Fecha: 21-08-2025                                                           *
 * Materia: Sistemas Operativos                                                *
 * Docente J.Corredor, PhD                                                     *
 * Objetivo: Reto 05 documentado                                               *
 *                                                                             *
 * Descripción: Memoria Dinamica                                               *
 *                                                                             *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  //Declaracion de puntero de tipo entero y variables a usar
  int *ptr, i, n1, n2;

  //Mensaje de solicitud al usuario para que ingrese el tamaño de la memoria a reservar
  printf("Enter size:");
  //Se solicita el dato al usuario 
  scanf("%d", &n1);
  //Se reserva la memoria dependiendo el tamaño que el usuario haya ingreado 
  ptr = (int*) malloc(n1 * sizeof(int));
  
  printf("Addresses of previously allocated memory:\n");

  //Ciclo para imprimir las direcciones de memoria de la cantidad de valores que el usuario haya puesto
  for ( i = 0; i < n1; i++){
    
    //Se imprime la direccion de memoria en cada posicion 
    printf("\n\np = %p\n", ptr + i);
  }
    //Se solicita un nuevo tamaño de memoria 
    printf("\nEnter the new size: ");
    scanf("%d", &n2);
    //rellocating the memory
    
    //Se reasigna la memoria con REALLOC dependiendo del nuevo tamaño que el usuario haya puesto
    ptr = realloc(ptr, n2 * sizeof(int));
    
    //Mensaje para mostrar las nuevas direcciones de memoria asginadas
    printf("Addresses of newly allocated memory:\n");
    
    //Ciclo para mostrar las nuevas direcciones, usando el nuevo tamaño que el usuario ingreso
    for ( i = 0; i < n2; i++){
      printf("\n\np = %p\n", ptr + i);
    }
  
  //Se libera la memoria que se habia reservado
  free(ptr);
  return 0;
}
