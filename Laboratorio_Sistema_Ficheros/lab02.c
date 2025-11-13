/*******************************************************
*
*	- Pontificia Universidad Javeriana -
*
* Materia: Sistemas Operativos
* Autor: Juan José Ballesteros
* Profesor: J.Corredor
* Descripción: Realizar un programa en C que lea de teclado el nombre de
*	       un directorio y muestre en pantalla el nombre
*	       y el tamaño de los ficheros que contiene
********************************************************/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
	DIR *d;                    // Puntero al directorio
	char nomdir[90];           // Almacena el nombre del directorio ingresado
	char nomfich[90];          // Ruta completa del archivo actual
	struct stat datos;         // Estructura con los atributos del archivo
	struct dirent *direc;      // Puntero a cada entrada dentro del directorio

	//Solicitar al usuario ingresar el nombre del directorio a analizar
	printf("Introduzca el nombre de un directorio:");
	fgets (nomdir, sizeof(nomdir), stdin);

	//Eliminamos el \n del nombre del fichero
	nomdir[strlen(nomdir)-1] = '\0';

	//Se intenta abrir el directorio
	if ((d = opendir(nomdir)) == NULL){
		return -1;
	}

	//Se lee cada entrada del directorio
	while ((direc = readdir(d)) != NULL){

		//Se construye la ruta completa del archivo
		strcpy(nomfich, nomdir);
		strcat(nomfich, "/");
		strcat(nomfich, direc->d_name);

		//Se obtiene la informaciòn del arhivo
		stat (nomfich, &datos);

		if ( S_ISREG(datos.st_mode))
			printf ("Nombre: %s\t1 | Tamaño: %ld\n", direc->d_name,datos.st_size);

	} //Fin del While

	//Se cierra el directorio despues de recorrerlo
	closedir(d);

}
/*******************************************************
* Nota :
* Este programa muestra un ejemplo sobre el uso de la API POSIX para
* acceder y recorrer directorios en sistemas operativos.
* Permite entender cómo se estructuran los
* archivos en el sistema y cómo obtener sus atributos
* utilizando la función stat().

*******************************************************/

