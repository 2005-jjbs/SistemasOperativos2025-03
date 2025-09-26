/**************************************************************************************
 * Fecha: 25/09/2025
 * Autor: Juan José Ballesteros
 * Materia: Sistemas Operativos
 * Docente: J.Corredor
 * Tema: Concurrencia
 * Objetivo: Hacer una metodología para la implementación de la multiplicación de matrices.
*************************************************************************************/


#ifndef MODULO_H
#define MODULO_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

extern double *mA, *mB, *mC;

extern struct timeval ini,fin;

//Funcion para tomar tiempo inicial
void InicioMuestra();

//Funcion para tomar tiempo final y presenta el resultado en ms 
void FinMuestra();

//Funcion que recibe un tamaño de la matriz y la inicializa
void iniMatriz(int n, double *m1, double *m2);

//Funcion para imprimir la matriz
void imprMatrices(int n, double *matriz);

//Funcion para multiplicar matrices de manera clasica, filasxcolumnas
void multiMatrizClasica( double *m1, double *m2, int n);

#endif

