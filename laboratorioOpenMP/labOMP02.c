/***********************************************************************+
* Pontificia Universidad Javeriana
*
* Autor: Juan José Ballesteros
* Materia: Sistemas Operativos
* Docente: J. Corredor
* Tema: Introducción a OpenMP
* Descripcion: Programa que muestra el uso básico de la biblioteca OpenMP para la creación
*              de regiones paralelas mediante directivas (pragmas) de compilación.
*              El usuario especifica por línea de comandos el número de hilos (threads)
*              que desea crear. El programa muestra el número máximo de núcleos disponibles
*              en el sistema, fija el número de hilos deseado, y ejecuta una región paralela
*              donde cada hilo imprime su identificador.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc, char *argv[]){

//validación para que se reciban solo dos argumentos
	if( argc != 2){
		printf("Error: \n\t$./ejecutable numHilos\n");
		exit(0);
	}

//Castea el caracter recibido por consola a un entero
	int numHilos = (int) atoi(argv[1]);

//Función para obtener el número máximo de hilos que soporta el sistema operativo
	int maxCores = omp_get_max_threads();
	printf("Número maximo de cores del SO: %d \n", maxCores);

//Se fijan el número de hilos deseado: numHilos
	omp_set_num_threads(numHilos);
	printf("Número hilos fijados: %d \n", numHilos);

//Región paralela por OMP
#pragma omp parallel
	{

 // Cada hilo imprime su identificador dentro de la región paralela
	 printf("Hilo ID en Región paralela: %d \n", omp_get_thread_num());

	}

	return 0;
}
