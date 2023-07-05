# METODOLOGÍA DE LA PROGRAMCACIÓN - TSU DESARROLLO DE SOFTWARE

## PROYECTO - Conecta 4

### Profesor: Alfonso Gregorio Rivero Duarte

### Alumno: Isaac Vega Telésforo

---

## CONECTA 4

### **Descripción del sistema**

-   Se debe realizar un programa que simule el juego de Conecta 4 para poder jugar entre dos personas.

### **Posibles errores y puntos a tener en cuenta**

1. El jugador correspondiente ingresa un número del 1 al 10 para que la ficha caiga en esa “casilla”.
    - Para que el usuario pueda ingresar un valor del 1 al 10, siendo que estamos trabajando con una matriz 10x10, donde los valores admitidos son del 0 al 9, basta con restar 1 a la posición que se ingrese.
2. Que no meta una columna invalida.

    - Para esto, cree una función llamada “validar”, la cual, no solo puede usarse en este programa, igual puede implementarse en otros, donde se necesite validar un dato dentro de cierto rango.

        ```C
        int validar (int dato, int minimo, int maximo) {
            if (dato < minimo || dato > maximo) {
                puts("\nValor no valido\n");
                dato = 0;
            } else {
                dato = 1;
            }

            return dato;
        }
        ```

    - Donde: `dato` a evaluar, `minimo` valor mínimo, `maximo` valor máximo.
    - Si el dato esta fuera del rango mandará un mensaje en pantalla y regresa un resultado. En el proyecto, esté último, se usó en conjunto con otra variable y el ciclo “while”.

3. Opciones durante la partida

    - Preferí hacerlo un poco más minimalista y quitar las opciones en pantalla, mostrando solo el ingreso de la columna donde caerá la ficha. Ya que las funciones de guardado de la partida y carga de una partida guardada, aún no han sido implementadas (aun no entiendo bien los temas, asique no quise complicarme más, pero tengo pensado implementarlas en un futuro).

    - De igual manera, para tener en cuenta las acciones faltantes, se sustituyeron con algunas funciones:

        - Para guardar la partida, bastará con ingresar como `columna` el código `3312`, y para terminar la partida, el código `911`.

---

## Diseño de la matriz.

```C
    9 |  |  |  |  |  |  |  |  |  |  |
    8 |  |  |  |  |  |  |  |  |  |  |
    7 |  |  |  |  |  |  |  |  |  |  |
    6 |  |  |  |  |  |  |  |  |  |  |
    5 |  |  |  |  |  |  |  |  |  |  |
    4 |  |  |  |  |  |  |  |  |  |  |
    3 |  |  |  |  |  |  |  |  |  |  |
    2 |  |  |  |  |  |  |  |  |  |  |
    1 |  |  |  |  |  |  |  |  |  |  |
    0 |  |  |  |  |  |  |  |  |  |  |
        0  1  2  3  4  5  6  7  8  9
```

Esta debe de ser impresa comenzando por la última fila, para ello se usan dos ciclos “for”, en el cual, el primero (correspondiente a las filas) se configura de la siguiente manera:

```C
    for (int i = fil-1; i >= 0 ; i--) 5
```

El segundo “for” (correspondiente a las columnas) se plasma “normal”:

```C
    for (int j = 0; j < col ; j++)
```

Al termino del segundo `for`, colocamos un `puts(“ ”);` para ir generando la tabla.

---

## Sobreponer una ficha en otra.

Teniendo en cuenta que tenemos un eje horizontal `x`, un eje vertical `y` y un punto `cero`, ubicamos la columna deseada, y validamos, que la coordenada `cero`, no tenga _`ficha`_, caso contrario subimos una línea, y repetimos el proceso.

Algo como la siguiente tabla:

| col(x), fil(y) |
| :------------: |
|    x , y+9     |
|    x , y+8     |
|    x , y+7     |
|    x , y+6     |
|    x , y+5     |
|    x , y+4     |
|    x , y+3     |
|    x , y+2     |
|    x , y+1     |
|     x , y      |

-   _Cabe mencionar, que en el programa se tomó en cuenta, cuando ya no quedan espacios libres en la columna, por lo cual, al presentarse dicho evento, se alerta al jugador con un mensaje en pantalla._

---

## Validaciones

Para que el juego cumpla su cometido, debemos tener en cuenta sus posibles formas de ganar.

### Las formas horizontales y verticales.

-   **_Izquierda_**
    |||||
    | ----- | ----- | ----- | --- |
    | x-3 , y | x-2 , y | x-1 , y | x , y |
    |||||
-   **_Derecha_**
    |||||
    | --- | ----- | ----- | ----- |
    | x , y | x+1 , y | x+2 , y | x+3 , y |
    |||||
-   **_Abajo_**
    ||
    | --- |
    | x , y |
    | x , y-1 |
    | x , y-2 |
    | x , y-3 |
    ||
-   **_Arriba_**
    ||
    | --- |
    | x , y-3 |
    | x , y-2 |
    | x , y-1 |
    | x , y |
    ||

-   **_De igual manera, las diagonales._**

    -   **_Ascendente Izquierda_**

    |           |           |           |       |
    | --------- | --------- | --------- | ----- |
    | x-3 , y+3 |           |           |       |
    |           | x-2 , y+2 |           |       |
    |           |           | x-1 , y+1 |       |
    |           |           |           | x , y |
    |           |           |           |       |

    -   **_Ascendente Derecha_**

    |       |           |           |           |
    | ----- | --------- | --------- | --------- |
    |       |           |           | x+3 , y+3 |
    |       |           | x+2 , y+2 |           |
    |       | x+1 , y+1 |           |           |
    | x , y |           |           |           |
    |       |           |           |           |

    -   **_Descendente Izquierda_**

    |           |           |           |       |
    | --------- | --------- | --------- | ----- |
    |           |           |           | x , y |
    |           |           | x-1 , y-1 |       |
    |           | x-2 , y-2 |           |       |
    | x-3 , y-3 |           |           |       |
    |           |           |           |       |

    -   **_Descendente Derecha_**

    |       |           |           |           |
    | ----- | --------- | --------- | --------- |
    | x , y |           |           |           |
    |       | x+1 , y-1 |           |           |
    |       |           | x+2 , y-2 |           |
    |       |           |           | x+3 , y-3 |
    |       |           |           |           |

_Para más información, no dudes en explorar el código fuente._
