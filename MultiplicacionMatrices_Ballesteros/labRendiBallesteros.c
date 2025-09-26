/**************************************************************************************
 * Fecha: 25/09/2025
 * Autor: Juan José Ballesteros
 * Materia: Sistemas Operativos
 * Docente: J. Corredor
 * Tema: Concurrencia
 * Objetivo: Hacer una metodología para la impementación de la multiplicación de matrices.
*************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "modulo.h"


int main(int argc, char *argv[]) {
    if(argc<=2){
        printf("Numero argumentos incorrectos\n");
        printf("\n\t $ejecutable.exe DIM \n");
        return -1;
    }

    int N = (int) atof(argv[1]);
    if(N<=0){
        printf("\n Valores deben ser mayor que cero\n");
        return -1;
    };

//Bloque para reservar memoria de matrices las dos primeras en NULL y la tercera en 0 para asegurar que se alojan los valores
    mA = (double *) malloc(N*N*sizeof(double));
    mB = (double *) malloc(N*N*sizeof(double));
    mC = (double *) calloc(N*N,sizeof(double));

	/** Se inicializan las 2 matrices **/
	iniMatriz(N, mA, mB);

	imprMatrices(N, mA);
	imprMatrices(N, mB);

	InicioMuestra();
	multiMatrizClasica(mA, mB, N);
	FinMuestra();

	imprMatrices(N,mC);
        printf("\n\tFin del programa.............!\n");
	free(mA);
        free(mB);
        free(mC);
        return 0;

}
