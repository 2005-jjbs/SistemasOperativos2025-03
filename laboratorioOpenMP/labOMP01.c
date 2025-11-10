/***********************************************************************+
* Pontificia Universidad Javeriana
*
* Autor: Juan José Ballesteros
* Materia: Sistemas Operativos
* Docente: J. Corredor
* Tema: Introducción a OpenMP
* Descripcion: Uso de la directiva y función para hacer uso de OpenMP
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc, char *argv[]){

//Funcion que retorna el maximo número de cores dentro del sistema operativo
	int maxCores = omp_get_max_threads();
	printf("Número maximo de cores del SO: %d \n", maxCores);

	//Región paralela por OMP
#pragma omp parallel
	{
	 printf("Hilo ID en Región paralela: %d \n", omp_get_thread_num());

	}

	return 0;
}
