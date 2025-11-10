/***********************************************************************+
* Pontificia Universidad Javeriana
*
* Autor: Juan José Ballesteros
* Materia: Sistemas Operativos
* Docente: J. Corredor
* Tema: Introducción a OpenMP
* Descripcion: Uso de la directiva
* 	Paralelismo para la funcion Seno
* se le agrega el tiempo de ejecución
* ahora tambien se ejecuta con datos del ingresados por el usuario
* ingresa el numero de hilos y de ejecuciones
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <sys/time.h>
#define MIN(x,y) ((x) < (y)) ? (x) : (y))



static struct timeval inicio,fin;


//Inicio muestra de tiempo
void InicioMuestra(){
	gettimeofday(&inicio,NULL);
}


//Fin muestra de tiempo
void FinMuestra(){
	gettimeofday(&fin,NULL);
	fin.tv_usec -= inicio.tv_usec;
	fin.tv_sec -= inicio.tv_sec;
	double tiempo = (double) (fin.tv_sec * 1000000 + fin.tv_usec);
	printf("%9.0f \n", tiempo);


}

//Se implementa la función de sumatoria de seno
double fsum(int i){
	int j;
	int start = i * (i+1)/2;
	int finish = start + i;
	double return_val = 0;

	for(j = start; j < finish; j++)
		return_val += sin(j);

	return return_val;

}

//Funcion principal
int main (int argc, char *argv[]){
	double sum = 0;

//Se deben ingresar los argumentos de numHilos y numRep para que continue la ejecucción
	if( argc != 3){
		printf("Error: \n\t$./ejecutable numHilos numRep\n");
		exit(0);
	}
//Se hace el casteo con los valores que ingreso el usuario por consola
	int numHilos = (int) atoi(argv[1]);
	int numRep = (int) atoi(argv[2]);

//Se incia la medición del tiempo
	InicioMuestra();

//Se define el pragma para que el procesador ejecute varios hilos en simultaneo
#pragma omp parallel
	{
//Devuelve el numero de hilos activos
	int threads = omp_get_num_threads();

//Solo el hilo maestro ejecuta esta línea para mostrar el número de hilos
#pragma omp master
	printf("Numero de Hilos: %d \n", threads);

//Se paraleliza el bucle for entre los hilos declarados, cada hilo ejecuta una parte del rango de iteraciones
#pragma omp for reduction(+ : sum)
	for ( int i = 0; i <= numRep; i++){
		sum += fsum(i);
	}
	}

//Se detiene la medición del tiempo y se imprime el resultado
	FinMuestra();
	printf("La sumatoria de la función SENO: %.2f\n",sum);
	return 0;
}
