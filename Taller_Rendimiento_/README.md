# Taller de Rendimiento  
Curso: **Sistemas Operativos – 2025-03**  
Autor: **Juan José Ballesteros**  

## Descripción  
Este taller tiene como objetivo analizar el rendimiento de distintos programas mediante la ejecución repetida de procesos y mediciones de tiempo.  
El propósito es observar variaciones en el tiempo de ejecución, carga del sistema y comportamiento del programa al ejecutarse múltiples veces, dependiendo de la configuración establecida.

El repositorio contiene el código fuente en C, así como un lanzador en Perl que automatiza las ejecuciones y recopila los resultados.

---

## Estructura del repositorio  
- **`Makefile`** – Compila el programa principal del taller.  
- **`lanzador.pl`** – Script en Perl encargado de ejecutar múltiples pruebas consecutivas.  
- **Código fuente (`.c`)** – Contiene la lógica que será medida en cuanto a rendimiento.  
- **`README.md`** – Documento de guía del taller.

---

## Requisitos  
Asegúrate de tener instalados:

- **GCC** – compilador para C  
- **Make**  
- **Perl** – necesario para ejecutar `lanzador.pl`  

En sistemas basados en Debian/Ubuntu puedes instalarlos con:

```bash
sudo apt install build-essential perl


