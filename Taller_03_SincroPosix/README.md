# 🧵 Taller 03 – Sincronización con Semáforos POSIX

## 📋 Descripción
Este taller implementa mecanismos de sincronización y comunicación entre **procesos** e **hilos** utilizando **semáforos POSIX**, **mutex** y **variables de condición**. Se abordan problemas clásicos de concurrencia como el **productor–consumidor** y la **búsqueda paralela del valor máximo** en un vector.

---

## 🎯 Objetivos
- Implementar un sistema **productor–consumidor** usando semáforos POSIX con nombre y memoria compartida.  
- Desarrollar un sistema **multihilo** para realizar la búsqueda concurrente del valor máximo en un vector.  
- Aplicar **mutex** y **variables de condición** para garantizar exclusión mutua y coordinación entre hilos.  
- Analizar las diferencias entre la **sincronización en procesos** y la **sincronización en hilos**.

---

## 👥 Autores
- **Juan José Ballesteros Suarez**  
- **Juan Diego Rojas Osorio**

---

## 🎓 Curso
**Sistemas Operativos** – Pontificia Universidad Javeriana  
**Profesor:** John Corredor, PhD.

---

## 🛠️ Compilación y Ejecución

### 🔹 Compilar todos los programas
```bash
make
