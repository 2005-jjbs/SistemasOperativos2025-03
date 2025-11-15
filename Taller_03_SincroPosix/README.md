# Taller 03 - Sincronización con Semáforos POSIX

## 📋 Descripción
Este taller implementa mecanismos de sincronización y comunicación entre procesos e hilos utilizando semáforos POSIX, mutex y variables de condición. El proyecto aborda problemas clásicos de concurrencia como el problema productor-consumidor y la búsqueda paralela del valor máximo en un vector.

## 🎯 Objetivos
- Implementar un sistema productor-consumidor usando semáforos POSIX con nombre y memoria compartida
- Desarrollar un sistema multihilo para búsqueda concurrente del valor máximo en un vector
- Aplicar mutex y variables de condición para garantizar exclusión mutua y coordinación entre hilos
- Analizar las diferencias entre sincronización de procesos e hilos

##👥 Autores
Juan José Ballesteros Suarez

Juan Diego Rojas Osorio

##🎓 Curso
Sistemas Operativos - Pontificia Universidad Javeriana
Profesor: John Corredor, PhD.



## 🛠️ Compilación y Ejecución

### Actividad 1: Productor-Consumidor entre Procesos
```bash
make
# Terminal 1:
./producer
# Terminal 2:
./consumer

##Para este es necesario crear un archivo con extension .txt que contenga varios numeros ej.
2
4
5
7
8
9
para despues ejecutarlo y ver el mayor numero de estos mediante concurrencia
make
./concurrenciaPosix datos.txt 4

make
./posixSincro


make clean    # Elimina archivos objeto y ejecutables
