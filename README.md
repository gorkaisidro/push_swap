# Push_swap

## Descripción

**push_swap** es un proyecto de algoritmia cuyo objetivo es ordenar un conjunto de números enteros en una pila (*stack*), utilizando un conjunto limitado de instrucciones y minimizando el número total de operaciones ejecutadas.

El programa recibe como argumentos una lista de números enteros desordenados y calcula la secuencia más corta de instrucciones del juego de operaciones de `push_swap` para ordenar el *stack a* de forma ascendente con la ayuda de un *stack b* auxiliar.

### Características principales

- **Optimización algorítmica y complejidad:** Selección e implementación de algoritmos eficientes para ordenar conjuntos pequeños (2, 3 y 5 números) y grandes (100 y 500 números) respetando los umbrales de evaluación.
- **Manejo de dos pilas (*Stack A* y *Stack B*):** Manipulación de estructuras dinámicas mediante un conjunto de 11 operaciones autorizadas (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).
- **Validación rigurosa de entradas:** Detección y gestión de errores frente a parámetros no numéricos, valores que exceden el rango de un entero (`int`) y elementos duplicados.
- **Programa Checker (Bonus):** Verificador personalizado que lee una secuencia de operaciones por la entrada estándar (`stdin`) y comprueba si el *stack a* queda ordenado y el *stack b* vacío, imprimiendo `OK` o `KO`.

## Instrucciones

### Requisitos

Linux (Debian/Ubuntu) / macOS:
- Compilador `cc` (`gcc` o `clang`)
- GNU `make`

### Compilación

Compilar el programa principal:
```sh
make
```

Reglas adicionales del `Makefile`:
- `make clean`: Elimina los archivos objeto (`.o`).
- `make fclean`: Elimina los archivos objeto y los ejecutables (`push_swap` y `checker`).
- `make re`: Recompila el proyecto desde cero.

### Ejecución

El programa principal `push_swap` recibe la lista de números enteros por argumento:

```sh
./push_swap 2 1 3 6 5 8
```

### Ejemplos de uso

```sh
# Ordenación simple de valores
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa

# Contar el número de operaciones generadas
$ ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Comprobar la validez de la ordenación con el checker oficial de 42
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK

# Ejecución del verificador propio (Bonus)
$ ARG="3 2 1 0"; ./push_swap $ARG | ./checker $ARG
OK

# Manejo de errores (argumentos inválidos o duplicados)
$ ./push_swap 0 uno 2 3
Error
```

### Comandos integrados

El conjunto de instrucciones válidas para manipular los stacks se compone de las siguientes operaciones:

| Operación | Nombre | Descripción |
|---|---|---|
| `sa` | *swap a* | Intercambia los dos primeros elementos en la cima del *stack a*. |
| `sb` | *swap b* | Intercambia los dos primeros elementos en la cima del *stack b*. |
| `ss` | *swap a + swap b* | Ejecuta `sa` y `sb` de forma simultánea. |
| `pa` | *push a* | Toma el primer elemento de la cima de `b` y lo coloca encima de `a`. |
| `pb` | *push b* | Toma el primer elemento de la cima de `a` y lo coloca encima de `b`. |
| `ra` | *rotate a* | Desplaza todos los elementos de `a` una posición hacia arriba (el primero pasa a ser el último). |
| `rb` | *rotate b* | Desplaza todos los elementos de `b` una posición hacia arriba (el primero pasa a ser el último). |
| `rr` | *rotate a + rotate b* | Ejecuta `ra` y `rb` de forma simultánea. |
| `rra` | *reverse rotate a* | Desplaza todos los elementos de `a` una posición hacia abajo (el último pasa a ser el primero). |
| `rrb` | *reverse rotate b* | Desplaza todos los elementos de `b` una posición hacia abajo (el último pasa a ser el primero). |
| `rrr` | *reverse rotate a + b* | Ejecuta `rra` y `rrb` de forma simultánea. |
