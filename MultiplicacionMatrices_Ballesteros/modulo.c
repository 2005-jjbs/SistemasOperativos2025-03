/**************************************************************************************
 * Fecha: 25/09/2025
 * Autor: Juan José Ballesteros
 * Materia: Sistemas Operativos
 * Docente: J. Corredor
 * Tema: Concurrencia
 * Objetivo: Hacer una metodología para la implementación de la multiplicación de matrices.
*************************************************************************************/


#include "modulo.h"

double *mA, *mB, *mC;

struct timeval ini,fin;

//Funcion para tomar tiempo inicial
void InicioMuestra(){
	gettimeofday(&ini, (void *)0);
}

//Funcion para tomar tiempo final y presenta el resultado en ms 
void FinMuestra(){
	gettimeofday(&fin, (void *)0);
	fin.tv_usec -= ini.tv_usec;
	fin.tv_sec  -= ini.tv_sec;
	double tiempo = (double) (fin.tv_sec*1000000 +fin.tv_usec);
	printf("%9.0f \n", tiempo);
}

//Funcion que recibe un tamaño de la matriz y la inicializa
void iniMatriz(int n, double *m1, double *m2){
   	for(int i=0; i<n*n; i++){
	        m1[i] = i*2.3 + 1.3;
	        m2[i] = i*2.3;
	}
};
//Funcion para imprimir la matriz
void imprMatrices(int n, double *matriz){
    if(n<9){
        printf("\n#######################################################\n");
   	for(int i=0; i<n*n; i++){
                if(i%n==0) printf("\n");
	        printf(" %f ", matriz[i]);
   }
    } else {
        printf("\n#######################################################\n");
    }
};

//Funcion para multiplicar matrices de manera clasica, filasxcolumnas
void multiMatrizClasica( double *m1, double *m2, int n){
        for(int i=0; i<n; i++){ /*Se recorre la matriz A*/
        for(int j=0; j<n; j++){ /*Se recorre la matriz B*/
            double sumaTemp, *pA, *pB;
            sumaTemp = 0.0;
            pA = mA + i*n; /*Se apunta al inicio de la fila*/
            pB = mB + j; /*Se apunta al inicio de la columna*/
            for(int k=0; k<n; k++, pA++, pB+=n){ /*Se recorre la fila y la columna*/
                sumaTemp += *pA * *pB; /*Se multiplican los elementos y se suman*/
            }
            mC[j+i*n] = sumaTemp; /*Se guarda el resultado en la matriz C*/
        }
    }
};

