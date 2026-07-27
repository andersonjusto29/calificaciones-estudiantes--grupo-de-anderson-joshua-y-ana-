# calificaciones-estudiantes--grupo-de-anderson-joshua-y-ana-
## Descripción del proyecto
Programa en C++ que permite registrar las calificaciones finales de un grupo de estudiantes de la asignatura de Cálculo Diferencial, usando arreglos unidimensionales paralelos. El programa permite ingresar nombres y notas, visualizar la lista completa, identificar la nota más alta y más baja, calcular el promedio general del grupo, y contar cuántos estudiantes aprobaron o reprobaron.

## Integrantes del grupo
- [Anderson Justo] - [2025-0373]
- [Joshua Alexander] - [2025-0375]
- [Ana Franieska Adames] - [2025-3295]

## Instrucciones de compilación y ejecución

Compilar con g++:
bash
g++ -o calificaciones calificaciones.cpp


Ejecutar:
bash
./calificaciones

(En Windows: calificaciones.exe)

## Capturas de pantalla
![entrada de datos] (tarea%201.png)
![Resultados] (tarea%202.png)

## Explicación de los arreglos utilizados

El programa usa dos arreglos unidimensionales que trabajan en *paralelo*:
- string nombres[] — almacena el nombre de cada estudiante.
- float notas[] — almacena la calificación correspondiente.

Ambos arreglos comparten el mismo tamaño y el mismo índice: la posición i de nombres siempre corresponde a la posición i de notas. Por ejemplo, nombres[3] y notas[3] pertenecen al mismo estudiante. Esta relación por índice es lo que se conoce como *paralelismo de arreglos*, y es la técnica que permite recorrer ambos arreglos con un mismo ciclo for para llenar, mostrar, comparar y calcular estadísticas sin perder la relación entre nombre y nota.
