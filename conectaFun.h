//
// Created by isaac on 11/11/2021.
//

#ifndef CONECTA4_CONECTAFUN_H
#define CONECTA4_CONECTAFUN_H

// Librerias
#include <time.h>
#include <stdlib.h>
#include <windows.h>

// Prototipos
void textcolor(int fondo, int texto);
void tiempo();
int guardarPartida(int fil, int col, char matriz[fil][col], int jugadas, int ultimo);
int terminarPartida();
int validar(int dato, int mini, int maxi);
int validarCaracter(char caracter[]);
void mensajes(int msj, int valor);
void impriMat(int fil, int col, char matriz[fil][col]);
int conectar(int fil, int col, char matriz[fil][col]);
int horizontal(int fil, int col, char matriz[fil][col]);
int vertical(int fil, int col, char matriz[fil][col]);
int diagonalDer(int fil, int col, char matriz[fil][col]);
int diagonalIzq(int fil, int col, char matriz[fil][col]);

/**
 * Función jugar
 *
 * Es la función con la que podremos jugar.
 *
 * Se basa en un sistema de turnos que, se creo con un bucle, cuando pasa el turno del primer jugador se le suma 1,
 *  cuando pasa el jugar 2, se le resta.
 *
 * Adicional a esto, se cuenta con un contador del total de turnos disponibles, al cual se le va restando despues
 *  de que un jugador haya puesto su ficha.
 * Este contador se muestra debajo del tablero.
 *
 * Las fichas ya estan declaradas para cada jugador, sin embargo se pueden cambiar por el caracter que se desee.
 *
 * La función cuenta con un detector de columnas llenas, el cual, al ser "activado" evitara la resta a los turnos totales.
 *
 * Cada ves que el jugador haya colocado de forma exitosa su ficha, se imprime la matriz y se valida si ya a conectado
 *  sus 4 fichas, en caso de que se haya logrado, se imprimiran mensajes de victoria y fin de juego, rompiendo el bucle,
 *  regresando al menú principal.
 *
 * En un futuro..
 * El bucle de los turnos, se puede romper, usando el comando -3312- el cual guardara la partida en curso.
 * Por mientras, el comando esta activo, y solo se muestra un mensaje de partida guarda, pero aun no funciona.
 *
 * @param fil       filas del tableero
 * @param col       columnas del tablero
 * @param tablero   tablero del juego
 * @param jugadas   número de jugadas de la partida guardada
 * @param turno     turno del jugador de la partida guardada
 */
void jugar(int fil, int col, char tablero[fil][col], int jugadas, int turno) {

    // Variables
    int posicion, victoria, error = 0, fin = 0, guardado = 0, conti;
    char pos[4];

    // Solo entran cuando se carga una partida
    if (turno == 0) turno = 1;
    if (jugadas == 0) jugadas = fil * col;

    // Ciclo para tirar las fichas
    while (turno != 0) {

        mensajes(0, jugadas);

        // Ciclo para tirar y validad fichas
        do {
            printf("\nJugador %d, en que columna pondras tu ficha? ", turno);
            //scanf("%d", &posicion);
            scanf("%s", pos);

            // Se ingresa codigo de guardado
            if (pos[0] == '3' && pos[1] == '3' && pos[2] == '1' && pos[3] == '2') {
                guardado = guardarPartida(fil, col, tablero, jugadas, turno);
                if (guardado == 1) {
                    break;
                }
            }

            // Se ingresa codigo de salida forzada
            if (pos[0] == '9' && pos[1] == '1' && pos[2] == '1') {
                guardado = terminarPartida();
                break;
            }

            // Se valida la posicion
            posicion = validarCaracter(pos);
            conti = validar(posicion, 1, col);

            // Si hubo error, se repite la impresion de la matriz y las jugadas
            if (conti == 0) {
                system("Pause");
                impriMat(fil, col, tablero);
                mensajes(0, jugadas);
            }

        } while (conti != 1);

        // Si se guarda la partida rompe el ciclo
        if (guardado == 1 || guardado == 2) break;

        // Se imprime la matriz con la ficha colocada
        for (int i = 0; i < fil; ++i) {
            if (tablero[i][posicion - 1] == '\0') {
                if (turno == 1) {
                    tablero[i][posicion - 1] = 'X';
                } else {
                    tablero[i][posicion - 1] = 'O';
                }
                break;
            } else if (i == fil - 1) {
                mensajes(1, 0);
                error = 1;
                system("Pause");
                impriMat(fil, col, tablero);
            }
        }

        // Contador de turnos
        if (error == 0 && jugadas != 0) {
            impriMat(fil, col, tablero);
            if (turno == 1) {
                turno++;
            } else {
                turno--;
            }
        } else {
            jugadas++;
            error = 0;
        }

        // Validacion de conecta4
        victoria = conectar(fil, col, tablero);

        // Imprimir si hubo ganador
        if (victoria == 1 && jugadas != 0) {
            mensajes(2, 0);
            fin = 1;
        } else {
            jugadas--;
        }

        // Mensaje de tablero lleno
        if (jugadas == 0) {
            mensajes(3, 0);
            fin = 1;
        }

        // Mensaje final del tablero al ganar
        if (fin == 1) {
            mensajes(4, 0);
            break;
        }
    }
    system("Pause");
}

/**
 * Funcion validar
 *
 * Valida que una variable o dato, se encuentre dentro de un rango establecido
 *
 * @param dato  valor a validar
 * @param mini  valor minimo del dato
 * @param maxi  valor maximo del dato
 * @return      regresa una bandera para saber que el valor esta dentro del rango o no
 */
int validar(int dato, int mini, int maxi) {
    if (dato < mini || dato > maxi) {
        puts("\nValor no valido\n");
        dato = 0;
    } else {
        dato = 1;
    }
    return dato;
}

/**
 * Función validaCaracter
 *
 * Como el programa trabaja con puros enteros, se implemento esta función para validar lo antes mencionado
 * Leyendo el caracter de ingreso, para pasarlo a entero, y determinar si es valido o no.
 *
 * @param caracter Caracter a validar
 * @return el entero valido, o 0 si es invalido
 */
int validarCaracter(char caracter[]) {
    char letter;
    int n, bandera = 0;

    // Lectura de la cadena de caracteres, strlen, para determinar el tamaño de la misma
    for (int i = 0; i < strlen(caracter); i++) {
        letter = caracter[i];
        if (i > 0 && bandera == 1 && n == 1) {
            int m = letter - '0';
            if (m == 0) {
                n = 10;
            }
        } else {
            n = -1;
        }
        if (bandera == 0) n = letter - '0';
        if (i == 2) n = -1;
        bandera++;
    }

    // Se regresa el valor válido o inválido
    if (n < 0 || n > 10 ) {
        return 0;
    } else {
        return n;
    }
}

/**
 * Funcion tiempo
 *
 * Muestra la fehca y el tiempo actual en pantalla.
 *
 * Se crea una vairable de tipo time_t, donde se almacenara el tiempo.
 *
 * Para inicializar nuestro "reloj", se manda a llamar con la funcion time(); en la cual, dentro del parantesis ponemos
 *  la variable de tipo time_h que se creo al principio.
 *
 * Para poder darle formato a este tiempo, se manda a llamar una estructura llamada tm que ya viene establecida en la
 *  libreria time.h; y un apuntador llamado "formato", el cual, sera el valor que vamos a mostrar.
 *
 * La fecha y la hora, la mostramos, asignando a "formato", el valor de la estructura que queremos tomar o mostrar.
 *
 * Cabe destacar que, la libreria time.h no muestra la fecha de forma correcta, y para poder corregirla, tenemos que agregar
 *  +1 a los meses, y +1900 a los años.
 */
void tiempo() {

    // Variables
    time_t tiempoahora;
    time(&tiempoahora);
    struct tm *formato = localtime(&tiempoahora);

    // Impresion de la fecha
    printf("\nFecha: %02d/%02d/%04d\t", formato->tm_mday, formato->tm_mon + 1, formato->tm_year + 1900);
    printf("\t\tTiempoLocal: %02d:%02d\n", formato->tm_hour, formato->tm_min);
}

/**
 * Funcion impriMat
 *
 * Imprime la matriz del tamaño especificado
 *
 * @param fil       filas de la matriz
 * @param col       columnas de la matriz
 * @param matriz    matriz a imprimir
 */
void impriMat(int fil, int col, char matriz[fil][col]) {
    system("cls");
    tiempo();
    textcolor(7, 0);
    printf("\n------------------------------------------------------------\n");
    for (int i = fil - 1; i >= 0; i--) {
        for (int j = 0; j < col; j++) {
            if (matriz[i][j] == '\0') {
                textcolor(7, 0);
                printf("| %c   |", matriz[i][j]);
            } else if (matriz[i][j] == 'X') {
                textcolor(9, 15);
                printf("| %c%c |", matriz[i][j], matriz[i][j]);
            } else if (matriz[i][j] == 'O') {
                textcolor(12, 15);
                printf("| %c%c |", matriz[i][j], matriz[i][j]);
            }
        }
        textcolor(7, 0);
        printf("\n------------------------------------------------------------\n");
    }
    textcolor(0, 15);
    printf("\n------------------------------------------------------------\n");
    for (int i = 0; i < col; i++) {
        printf("| %2d |", i + 1);
    }
    printf("\n------------------------------------------------------------\n");

}

/**
 * Funcion textcolor
 *
 * Modifica el color del texto que se muestra en pantalla, sin embargo, está nos permite aplicar la modificación de
 *  colores en ciertos puntos y no en toda la ventana de cmd, como lo hace si aplicamos -system("color")-
 *
 * El color del fondo se encuentra en los 4 bits altos (16 - 255), y el del texto en los 4 bits bajos (0 - 15)
 * Para convertir los colores a un valor adecuado, se realiza el siguiente cálculo: valortexto + (valorfondo * 16).
 * Y se guarda en una variable de tipo int, la cual nos dara el color que deseemos.
 *
 * @param fondo color de fondo del texto
 * @param texto color del texto
 */
void textcolor(int fondo, int texto) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = texto + (fondo * 16);
    SetConsoleTextAttribute(h, color);
}

/**
 * Funcion conectar
 *
 * Valida cada una de las combinaciones del conecta 4, llamando a cada una de sus respectivas funciones
 * Para ello haremos uso de la matriz principal
 *
 * @param fil       filas
 * @param col       columnas
 * @param matriz    matriz
 * @return          regresamos una bandera para saber si alguna validacion es correcta o no
 */
int conectar(int fil, int col, char matriz[fil][col]) {
    int exito, comprueba = 0;

    exito = horizontal(fil, col, matriz);
    comprueba++;

    if (exito == 0 && comprueba == 1) {
        exito = vertical(fil, col, matriz);
        comprueba++;
    }
    if (exito == 0 && comprueba == 2) {
        exito = diagonalDer(fil, col, matriz);
        comprueba++;
    }
    if (exito == 0 && comprueba == 3) {
        exito = diagonalIzq(fil, col, matriz);
    }
    return exito;
}

/**
 * Funcion horizontal
 *
 * Valida cada una de las combinaciones del conecta 4, de manera horizontal
 * Para ello haremos uso de la matriz principal
 *
 * @param fil       filas
 * @param col       columnas
 * @param matriz    matriz
 * @return          regresamos una bandera para saber si alguna combinacion fue correcta o no
 */
int horizontal(int fil, int col, char matriz[fil][col]) {
    int conta = 0, bandera;

    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            if (matriz[i][j] != '\0') {
                if (matriz[i][j] == matriz[i][j + 1]) {
                    conta++;
                } else {
                    conta = 0;
                }
            }
            if (conta == 3) {
                break;
            }
        }
        if (conta == 3) {
            break;
        }
    }

    if (conta == 3) {
        bandera = 1;
    } else {
        bandera = 0;
    }

    return bandera;
}

/**
 * Funcion vertical
 *
 * Valida cada una de las combinaciones del conecta 4, de manera vertical
 * Para ello haremos uso de la matriz principal
 *
 * @param fil       filas
 * @param col       columnas
 * @param matriz    matriz
 * @return          regresamos una bandera para saber si alguna combinacion fue correcta o no
 */
int vertical(int fil, int col, char matriz[fil][col]) {
    int conta = 0, bandera;

    for (int j = 0; j < col; j++) {
        for (int i = 0; i < fil; i++) {
            if (matriz[i][j] != '\0') {
                if (matriz[i][j] == matriz[i + 1][j]) {
                    conta++;
                } else {
                    conta = 0;
                }
            }
            if (conta == 3) {
                break;
            }
        }
        if (conta == 3) {
            break;
        }
    }

    if (conta == 3) {
        bandera = 1;
    } else {
        bandera = 0;
    }

    return bandera;
}

/**
 * Funcion diagonalDer
 *
 * Valida cada una de las combinaciones del conecta 4, de forma diagonal, derecha
 * Comenzando de la posion 0, teniendo en cuenta que al llegar a la columna 7, ya no se cumple la diagonal de 4 seguidos
 * Para ello haremos uso de la matriz principal
 *
 * @param fil       filas
 * @param col       columnas
 * @param matriz    matriz
 * @return          regresamos una bandera para saber si alguna combinacion fue correcta o no
 */
int diagonalDer(int fil, int col, char matriz[fil][col]) {
    int bandera = 0, horizontal = fil - 3, vertical = col - 3;

    for (int i = 0; i < horizontal; i++) {
        for (int j = 0; j < vertical; j++) {
            if (matriz[i][j] != '\0') {
                if (matriz[i][j] == matriz[i + 1][j + 1]) {
                    if (matriz[i + 1][j + 1] == matriz[i + 2][j + 2]) {
                        if (matriz[i + 2][j + 2] == matriz[i + 3][j + 3]) {
                            bandera = 1;
                            break;
                        }
                    }
                }
            }
        }
        if (bandera == 1) {
            break;
        }
    }

    return bandera;
}

/**
 * Funcion diagonalIzq
 *
 * Valida cada una de las combinaciones del conecta 4, de forma diagonal, izquierda
 * Comenzando de la posion 3, ya que, desde la posicion 2 no se cumple la diagonal de 4 seguidos
 * Para ello haremos uso de la matriz principal
 *
 * @param fil       filas
 * @param col       columnas
 * @param matriz    matriz
 * @return          regresamos una bandera para saber si alguna combinacion fue correcta o no
 */
int diagonalIzq(int fil, int col, char matriz[fil][col]) {
    int bandera = 0, horizontal = fil - 3, vertical = col;

    for (int i = 0; i < horizontal; i++) {
        for (int j = 3; j < vertical; j++) {
            if (matriz[i][j] != '\0') {
                if (matriz[i][j] == matriz[i + 1][j - 1]) {
                    if (matriz[i + 1][j - 1] == matriz[i + 2][j - 2]) {
                        if (matriz[i + 2][j - 2] == matriz[i + 3][j - 3]) {
                            bandera = 1;
                            break;
                        }
                    }
                }
            }
        }
        if (bandera == 1) {
            break;
        }
    }

    return bandera;
}

/**
 * Función guardarPartida
 *
 * Guarda los datos de la partida actual
 *
 * @param fil       filas
 * @param col       columnas
 * @param matriz    matriz
 * @param jugadas   las jugadas al momento
 * @param ultimo    el turno del jugador actual
 * @return result   regresa un valor de confirmación
 */
int guardarPartida(int fil, int col, char matriz[fil][col], int jugadas, int ultimo) {

    // Variables
    int result;
    char fNombre[27];
    time_t tiempoahora; time(&tiempoahora);
    struct tm *formato = localtime(&tiempoahora);

    sprintf(fNombre, "../saves/%02d%02d%04d_%02d%02d.jgo", formato->tm_mday, formato->tm_mon + 1, formato->tm_year + 1900, formato->tm_hour, formato->tm_min);

    FILE *fp;
    char *fileName = fNombre;

    // Verificar que se haya creado el archivo para escribir sobre el mismo
    if ((fp = fopen(fileName, "w")) == NULL) {

        mensajes(5, 0);
        result = 0;

    } else {

        // Se guarda la matriz
        for (int i = 0; i < fil; ++i) {
            char fila[10];
            for (int j = 0; j < col; ++j) {
                if (matriz[i][j] == '\0') {
                    matriz[i][j] = '-';
                }
                fila[j] = matriz[i][j];
            }
            fprintf(fp, "%s\n", fila);
        }

        // Se guarda las jugadas y el turno al momento
        fprintf(fp, "%d\n", jugadas);
        fprintf(fp, "%d\n", ultimo);

        mensajes(5, 1);
        result = 1;
    }

    // Se cierra el archivo
    fclose(fp);
    return result;
}

/**
 * Funcion cargarPartida
 *
 * Mediante comando de la consola, muestra los archivos de la carpeta "saves"
 * Usando el comando los siguientes comandos:
 *
 * dir  Muestra la lista de subdirectorios y archivos de un directorio.
 * /B   Usa el formato simple (sin encabezados ni resúmenes), es decir nos deja solo el nombre de los archivos
 * /O:  Muestra los archivos según el orden indicado, seguido de la forma de ordenarlos.
 * -    Para invertir el orden usamos el prefijo
 * D    Se uso la "D", por fecha y hora (el más antiguo primero, con el prefijo, queda el más reciente primero.)
 *
 * Basta con copiar el nombre del archivo y dar enter para jugar
 *
 * Almacena los datos guardados en el archivo .jgo en una matriz
 *
 * @param fil       filas
 * @param col       columnas
 * @param matriz    matriz
 */
void cargarPartida(int fil, int col, char matriz[fil][col]) {

    // Variables
    int jugadas, ulTurno, opc, sig, salir;
    char partida[17], fNombre[27], directorio[100], letra[1];

//......................................................................................................................
//..... Modifica aqui .................................................................................................

    char rutaAbs[100] = "..\\saves";

//......................................................................................................................

    // Forma de mostrar los archivos del directorio
    sprintf(directorio, "dir %s /B /O:-D", rutaAbs);
    system(directorio);

    printf("\n\n%cQu%c partida vas a cargar? ", 168, 130);
    scanf("%s", partida);

    sprintf(fNombre, "../saves/%s", partida);

    FILE *fp;
    char *fileName = fNombre;

    // Verificar que exista el archivo para leerlo
    if ((fp = fopen(fileName, "r")) == NULL) {

        mensajes(6, 0);
        system("Pause");

    } else {

        // Lectura de la matriz guardada, que será almacenada en la matriz principal
        for (int i = 0; i < fil; ++i) {
            char fila[10];
            fscanf(fp, "%s", fila);
            for (int j = 0; j < col; ++j) {
                if (fila[j] == '-') {
                    fila[j] = '\0';
                }
                matriz[i][j] = fila[j];
            }
        }

        // Se extraen los valores de las jugadas guardadas y el último turno
        fscanf(fp, "%d", &jugadas);
        fscanf(fp, "%d", &ulTurno);

        // Se cierra el archivo
        fclose(fp);

        mensajes(6, 1);
        system("Pause");

        // Borrar o no la partida cargada
        do {

            // Evitar el borrado de los archivos de ejemplo
            if (fNombre[16] == '.' && fNombre[17] == 'e' &&fNombre[18] == 'j' && fNombre[19]  == 'g' && fNombre[20] == 'o')
               salir = 1;
            if (salir == 1) break;

            sig = 1;
            system("cls");
            mensajes(11,0);
            printf("\t1.Si, borrar\t2.No, conservar\t\tOpci%cm: ", 162);
            scanf("%s", letra);

            opc = validarCaracter(letra);

            if (sig == validar(opc, 1, 2)) {
                if (opc == 2) {
                    mensajes(7, 1);
                } else if (opc == 1) {
                    mensajes(7, 0);
                    remove(fNombre);
                    system("Pause");
                }
            } else {
                sig = 0;
            }

        } while (sig != 1);

        // Se reanuda la partida cargada
        impriMat(fil, col, matriz);
        jugar(fil, col, matriz, jugadas, ulTurno);
    }
}

/**
 * Funcion terminar
 *
 * Muestra un mensaje y termina la partida
 *
 * @return 2 para confirmar la acción
 */
int terminarPartida() {
    mensajes(8, 0);
    return 2;
}

/**
 * Funcion mensajes
 *
 * Mostramos los mensajes en pantalla, mediante un switch
 *
 * @param msj el numero de mensaje que mostraremos
 */
void mensajes(int msj, int valor) {
    int colortext;
    puts("");
    switch (msj) {
        case 0:
            if (valor > 75 && valor <= 100) { colortext = 10; }
            else if (valor > 25 && valor <= 75) { colortext = 14; }
            else { colortext = 4; }
            textcolor(0, colortext);
            printf("----------------- Jugadas restantes: %03d -------------------", valor);
            textcolor(0, 15);
            break;
        case 1:
            textcolor(4, 15);
            puts("---------------- Esta columna ya esta llena ----------------");
            textcolor(0, 15);
            break;
        case 2:
            textcolor(2, 0);
            puts("---------------------- Tenemos ganador ---------------------");
            textcolor(0, 15);
            break;
        case 3:
            textcolor(4, 15);
            puts("----------------- El tablero ya esta lleno -----------------");
            textcolor(0, 15);
            break;
        case 4:
            textcolor(4, 15);
            puts("--------------------- El juego termino ---------------------");
            textcolor(0, 15);
            break;
        case 5:
            if (valor != 1) {
                textcolor(4, 15);
                printf("------- C%cdigo 3312: No se pudo guardar la partida ---------\n", 162);
                textcolor(0, 15);
            } else {
                textcolor(0, 14);
                printf("------ C%cdigo 3312: El tablero actual se ha guardado -------\n", 162);
                textcolor(0, 15);
            }
            break;
        case 6:
            textcolor(0, 14);
            puts("--------------------------------------------------------------\n"
                 "---------------------- Buscando partida ----------------------\n"
                 "--------------------------------------------------------------\n");
            textcolor(0, 15);
            if (valor != 1) {
                textcolor(4, 15);
                printf("---------- No se encontr%c ninguna partida guardada -----------\n", 162);
                textcolor(0, 15);
            } else {
                textcolor(0, 10);
                printf("------------ La partida se carg%c de manera exitosa -----------\n", 162);
                textcolor(0, 15);
            }
            break;
        case 7:
            if (valor != 1) {
                textcolor(4, 15);
                printf("\n---------------- La partida ser%c eliminada -----------------\n\n", 160);
                textcolor(0, 15);
            } else {
                textcolor(0, 14);
                printf("\n--------------- La partida seguir%c guardada ----------------\n\n", 160);
                textcolor(0, 15);
            }
            break;
        case 8:
            textcolor(4, 15);
            printf("----------- C%cdigo 911: Cierre forzado del juego -----------\n", 162);
            textcolor(0, 15);
            break;
        case 9:
            textcolor(0, 14);
            puts("--------------------------------------------------------------\n"
                 "--------------------------------------------------------------\n"
                 "----------------                              ----------------\n"
                 "----------------    BIENVENIDO A CONECTA 4    ----------------\n"
                 "----------------                              ----------------\n"
                 "--------------------------------------------------------------\n"
                 "--------------------------------------------------------------\n");
            textcolor(0, 15);
            break;
        case 10:
            system("cls");
            textcolor(0, 14);
            puts("\n--------------------------------------------------------------\n"
                 "--------------------------------------------------------------\n"
                 "----------------                              ----------------\n"
                 "----------------       GRACIAS POR JUGAR      ----------------\n"
                 "----------------                              ----------------\n"
                 "--------------------------------------------------------------\n"
                 "--------------------------------------------------------------\n");
            textcolor(0, 15);
            break;
        case 11:
            system("cls");
            textcolor(0, 14);
              puts("\n---------------------------------------------------------------\n"
                   "---------------------------------------------------------------\n"
                   "----------                                            ---------");
            printf("----------  %cDesea borrar la partida o conservarla?   ---------\n", 168);
              puts("----------                                            ---------\n"
                   "---------------------------------------------------------------\n"
                   "---------------------------------------------------------------\n\n");
            textcolor(0, 15);
            break;
        case 12:
            system("cls");
            textcolor(0, 14);
            puts("\n---------------------------------------------------------------\n"
                 "---------------------------------------------------------------\n"
                 "--------------------                        -------------------\n"
                 "--------------------    Partida Guardadas   -------------------\n"
                 "--------------------                        -------------------\n"
                 "---------------------------------------------------------------\n"
                 "---------------------------------------------------------------\n");
            textcolor(0, 15);
            break;

    }
    puts("");
}

#endif //CONECTA4_CONECTAFUN_H
