/**********************************************************
*
* 	- Pontificia Universidad Javeriana -
*
* Autor: J.Corredor
* Materia: Sistemas Operativos
* Tema: Sistema de Ficheros
*
* Descripción:
* Este programa realiza la apertura y lectura de un archivo de texto
* llamado "readme.txt". Utiliza las funciones estándar de manejo
* de archivos en C para abrir el fichero en modo lectura ("r"),
* verificar si se abrió correctamente, y mostrar su contenido línea
* por línea en pantalla.
*
**********************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){

	//Nombre del fichero a leer
	char *nombrefichero = "readme.txt";

	//Lectura de archivo en modo lectura
	FILE *fp = fopen(nombrefichero, "r");

	//Si el archivo no existe arroja el error
	if (fp == NULL){
		printf("Error: no se puede abrir el fichero\n");
		return 1;
	}

	//Se imprime mensaje de lectura de fichero
	printf("\n ==============================\n");
	printf("\n LECTURA DE FICHERO readme.txt\n");
	printf("\n ==============================\n");

	//Lectura de fichero, maximo 256 bytes por línea
	//Lectura de línea por línea (buscar\n)
	const unsigned LARGO_MAX_LINEA = 256;
	char buffer[LARGO_MAX_LINEA];

	// fgets() lee hasta encontrar un salto de línea o el fin del archivo
	while(fgets(buffer, LARGO_MAX_LINEA, fp))
		printf("%s", buffer);

	//cerrar el fichero
	fclose(fp);
	return 0;
}

/**********************************************************
* Conclusion:
* Este programa demuestra el uso básico de las funciones
* de entrada/salida de archivos en lenguaje C. Es una base
* para entender cómo los procesos interactúan
* con el sistema de ficheros en Sistemas Operativos.
**********************************************************/
