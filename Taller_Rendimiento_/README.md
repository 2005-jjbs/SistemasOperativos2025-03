# Taller de Rendimiento  
Curso: **Sistemas Operativos – 2025-03**  
Autor: **Juan José Ballesteros**  

## Descripción  
Este taller tiene como objetivo analizar el rendimiento de distintos programas mediante la ejecución repetida de procesos y mediciones de tiempo.  
El propósito es observar variaciones en el tiempo de ejecución, carga del sistema y comportamiento del programa al ejecutarse múltiples veces, dependiendo de la configuración establecida.

El repositorio contiene el código fuente en C, así como un lanzador en Perl que automatiza las ejecuciones y recopila los resultados.

---
## 🧠 Introducción

Este proyecto tiene como objetivo **evaluar el rendimiento** de distintos enfoques de **programación paralela en C** aplicados a la **multiplicación de matrices cuadradas**. Se comparan tres técnicas:

- `OpenMP`
- `FilasOpenMP`
- `fork()` (procesos)
- `POSIX threads (pthread)`

Los algoritmos se ejecutan en **múltiples entornos de cómputo** y se analizan en función del número de hilos, la arquitectura del sistema y el tamaño de las matrices. Esta evaluación permite comprender el impacto del paralelismo en el rendimiento y eficiencia de aplicaciones intensivas en cómputo.

---

## 🎯 Objetivos

- Comparar el rendimiento entre algoritmos secuenciales y paralelos.
- Medir los tiempos de ejecución en diferentes arquitecturas (WSL, Ubuntu VM, Replit).
- Analizar el comportamiento de cada técnica respecto a:
  - Tamaños de matriz: `50, 100, 500, 1000, 1500`
  - Cantidad de hilos: `1, 2, 4, 8, 10`

---

## 🛠️ Implementación

Se desarrollaron tres programas en **lenguaje C**:

| Algoritmo        | Descripción                                                                 |
|------------------|-----------------------------------------------------------------------------|
| `ClasicaFork`  | Usa `fork()` para crear procesos hijos, cada uno procesa una parte de la matriz y comunica resultados por `pipe`. |
| `ClasicaPosix` | Usa `pthread_create()` para distribuir filas entre hilos POSIX.             |
| `ClasicaOpenMP`| Usa directivas `#pragma` de OpenMP para paralelizar el trabajo.             |
| `FilasOpenMP`| Usa directivas `#pragma` de OpenMP para paralelizar mediante filas el trabajo.             |

Cada programa realiza:

1. Reserva dinámica de memoria
2. Inicialización de matrices
3. Multiplicación de matrices
4. Medición de tiempo con `gettimeofday()`
5. Liberación de memoria

---

## 🧪 Método de Prueba

Para automatizar las pruebas:

- Se desarrolló el script `lanzador.pl` que:
  - Ejecuta las combinaciones posibles de algoritmos, tamaños de matrices y número de hilos.
  - Repite cada combinación **30 veces**.
  - Guarda los tiempos de ejecución en archivos `.dat`.

---

## 📊 Resultados esperados

Para cada ejecución se obtiene:

- Un archivo con los **tiempos de ejecución** por combinación (algoritmo + tamaño de matriz + número de hilos + sistema).
- Datos listos para análisis comparativo.

---

## 🧳 Cómo Ejecutar

```bash
make

/usr/bin/perl ./lanzador.pl
