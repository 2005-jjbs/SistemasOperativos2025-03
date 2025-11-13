# Laboratorio: Sistema de Ficheros  
**Materia:** Sistemas Operativos  
**Autor:** Juan José Ballesteros  
**Profesor:** J. Corredor  
**Facultad:** Ingeniería de Sistemas (Pontificia Universidad Javeriana)  
**Periodo:** 2025-03  

---

## Descripción  
Este proyecto corresponde al laboratorio sobre **sistema de ficheros**. Su objetivo principal es implementar programas en lenguaje C que permitan interactuar con el sistema de archivos de un sistema Unix-like (Linux), explorando conceptos fundamentales de la materia como:

- apertura y lectura de directorios (`opendir`, `readdir`, `closedir`)  
- obtención de metadatos de archivos (`stat`, `st_mode`, `st_size`, `st_mtime`)  
- identificación de archivos regulares vs. directorios  
- manejo básico de rutas y cadenas en C  
- verificación de permisos y formato de salida  

En concreto, este repositorio incluye varios ejercicios:  
1. Programa que solicita al usuario un directorio e imprime para cada fichero y subdirectorio su nombre, modo de acceso y si el propietario tiene permiso de lectura.  
2. Programa que solicita al usuario un directorio y muestra para cada fichero regular su nombre y tamaño en bytes.  
3. Otros ejercicios complementarios diseñados para afianzar la comprensión del sistema de ficheros y su API POSIX.

---

## Ejecucion 
Se descargan todos los ficheros en una carpeta (los .c, .txt y el Makefile )y mediante el comando
- make lab01
- make lab02
- make lab03

Este corre los codigos y genera el ejecutable. Para ejecutarlos y ver su resultado se usan los siguientes comandos
- ./lab01
- ./lab02
- ./lab03
