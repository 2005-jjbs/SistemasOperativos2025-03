/*******************************************************
*
*	- Pontificia Universidad Javeriana -
*
* Materia: Sistemas Operativos
* Autor: Juan José Ballesteros
* Profesor: J.Corredor
* Descripción: Realizar un programa que reciba un nombre
*	       un directorio y muestre en pantalla los nombres de ficheros
*	       y directorios que contiene, su modo, si tienen o no permiso
*	       de lectura para el propietario, si son directorios
********************************************************/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(){
	int er;
	char nomdir[1001], nomfich[100], resp[30];
	struct stat atr;
	DIR *d;
	struct dirent *rd1;
	time_t fecha;

	printf ("Nombre directorio\n");
	fgets (nomdir, sizeof(nomdir), stdin); //Se solicita al usuario el nombre del directorio

	//Hay que quitar el \n del nombre del directorio
	nomdir[strlen(nomdir)-1]= '\0';

	//Se guarda la hora y fecha actual del sistema
	fecha = time (&fecha);

	//Condición en caso de que el directorio no existe arroja el mensaje y se salga de la ejecución
	if((d=opendir(nomdir)) == NULL){
		printf("No existe ese directorio\n");
		return -1;
	}

	//Si existe el directorio entra al ciclo While
	else{

	//Ciclo que recorre todas las entradas del directorio mediante readdir()
	while((rd1 = readdir(d)) != NULL){
	//Se ignora la entrada de . y .. 
	if( (strcmp(rd1 -> d_name, ".") !=0) && (strcmp(rd1->d_name, "..") !=0)){
		//Construimos la ruta completa del archivo o subdirectorio
		strcpy(nomfich, nomdir);
		strcat(nomfich,"/");
		strcat(nomfich, rd1->d_name);

		//Mostramos el nombre del archivo con su ruta
		printf("fichero: %s:", nomfich);

		//Se obtienen los atributos del archivo con stat()
		er = stat (nomfich,&atr);

		//Se muestra el modo del archivo en formato octal
		printf("modo: %#o:", atr.st_mode);

//Se verifica si el propietario tiene permisos de lectura (bit 0400)
	if((atr.st_mode & 0400) != 0)
		printf("Permiso R para propietario \n");
	else
		printf("No permiso R para propietario\n");

	//Se hace la comprobación si es un directorio
	if(S_ISDIR(atr.st_mode)) printf("Es un directorio \n");

	//Se comprueba si es un archivo regular
	if (S_ISREG(atr.st_mode))
	//ficheros modificados en los últimos 10 días
		if( (fecha - atr.st_mtime) < 10 * 24 * 60 * 60){
			printf("Fichero:%s: fecha acceso %s, en sgdos %ld\n", rd1->d_name, ctime(&atr.st_mtime), atr.st_mtime);
		}
	}
	}//fin del while
}

closedir(d);
}

/******************************************************************
* Nota Final
* Este programa recorre un directorio ingresado por el usuario
* y muestra información detallada de sus archivos y subdirectorios.
* Entre los datos que presenta se incluyen:
* - El modo o permisos del archivo.
* - Si el propietario tiene permiso de lectura.
* - Si el elemento es un directorio o un archivo regular.
* - Si fue modificado recientemente (últimos 10 días).
******************************************************************/





