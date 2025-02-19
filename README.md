# Philosophers - 42 School Project

**Philosophers** es un proyecto de la escuela 42 que simula el famoso problema de los filósofos comensales, un clásico problema de sincronización en sistemas operativos. El objetivo es implementar una solución que evite el deadlock y garantice que todos los filósofos puedan "comer" sin bloquearse indefinidamente, utilizando hilos (`threads`) o procesos (`processes`) y mecanismos de sincronización como mutexes.

## Características Principales

- **Simulación del problema**: Cada filósofo es representado como un hilo o proceso que alterna entre pensar, comer y dormir.
- **Sincronización**: Uso de mutexes para controlar el acceso a los tenedores (recursos compartidos) y evitar condiciones de carrera.
- **Manejo de tiempo**: Cada acción (comer, pensar, dormir) tiene un tiempo específico, y el programa debe respetar estos tiempos.
- **Gestión de deadlocks**: Implementación de una solución que evite que los filósofos entren en un estado de deadlock.
- **Modos de ejecución**: El programa puede ejecutarse en dos versiones:
  - **Versión con hilos (`philo`)**: Usa threads y mutexes.
  - **Versión con procesos (`philo_bonus`)**: Usa procesos y semáforos.

## Tecnologías Utilizadas

- **Lenguaje**: C
- **Hilos y procesos**: Uso de `pthread_create`, `pthread_join`, `fork`, `waitpid`, etc.
- **Sincronización**: Uso de `mutex` para la versión con hilos y `semáforos` para la versión con procesos.
- **Manejo de tiempo**: Uso de funciones como `gettimeofday` o `usleep` para gestionar los tiempos de ejecución.

## Aprendizaje y Desafíos

- **Concurrencia**: Aprendizaje profundo sobre la programación concurrente y los problemas asociados.
- **Sincronización**: Implementación de mecanismos para evitar condiciones de carrera y deadlocks.
- **Optimización**: Mejora del rendimiento y eficiencia en la gestión de recursos compartidos.
- **Depuración**: Uso de herramientas como `valgrind` para detectar fugas de memoria y errores de sincronización.

## Instalación y Uso

1. Clona el repositorio:
   ```bash
   git clone https://github.com/tu-usuario/philosophers.git
   ```
2. Compila el proyecto:
    ```bash
   make
   ```
3. Ejecuta el proyecto:
   ```bash
   ./philo <número_de_filósofos> <tiempo_para_morir> <tiempo_para_comer> <tiempo_para_dormir> [número_de_veces_que_cada_filósofo_debe_comer]
   ```
