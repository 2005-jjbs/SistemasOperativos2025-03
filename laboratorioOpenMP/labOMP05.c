/***********************************************************************+
* Pontificia Universidad Javeriana
*
* Autor: Juan José Ballesteros
* Materia: Sistemas Operativos
* Docente: J. Corredor
* Tema: Introducción a OpenMP
* Descripcion: Uso de la directiva
* 	Paralelismo para la funcion Seno
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#define MIN(x,y) ((x) < (y)) ? (x) : (y))


//Se implementa la función de sumatoria
double fsum(int i){
	int j, start = i * (i+1)/2, finish = start + i;
	double return_val = 0;
	for(j = start; j < finish; j++)
		return_val += sin(j);

	return return_val;

}


int main (int argc, char *argv[]){
	double sum = 0;
	int rep = 30000;
	if( argc != 2){
		printf("Error: \n\t$./ejecutable numHilos\n");
		exit(0);
	}
	int numHilos = (int) atoi(argv[1]);

#pragma omp parallel
	{
	int threads = omp_get_num_threads();
#pragma omp master
	printf("Numero de Hilos: %d \n", threads);

#pragma omp for reduction(+ : sum)
	for ( int i = 0; i <= rep; i++){
		sum += fsum(i);
	}
	}

	printf("La sumatoria de la función SENO: %.2f\n", sum);
	return 0;
}
