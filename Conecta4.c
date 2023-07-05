#include <stdio.h>          // Libreria principal para lenguaje C
#include <stdlib.h>         // Libreria para usar comandos de la consola
#include "conectaFun.h"     // Libreria personal
#include "aboutMe.h"        // Libreria de la documentación

// Se define las dimensiones de la matriz
#define filas 10
#define columnas 10

// Prototipos
void aboutGame();
void impriMat (int fil, int col, char matriz[fil][col]);
void jugar (int fil, int col, char tablero[fil][col], int jugadas, int turno);
void cargarPartida(int fil, int col, char matriz[fil][col]);
int validar (int dato, int mini, int maxi);
void mensajes (int msj,int valor);
int validarCaracter(char caracter[]);

// Declaramos el programa principal
int main() {

    int opc, continuar = 0;
    char letra[3];

    do {

    // Inicializacion de la matriz principal
    char tablero[filas][columnas] = {'\0', '\0','\0', '\0','\0', '\0','\0', '\0','\0', '\0',
                                     '\0', '\0','\0', '\0','\0', '\0','\0', '\0','\0', '\0',
                                     '\0', '\0','\0', '\0','\0', '\0','\0', '\0','\0', '\0',
                                     '\0', '\0','\0', '\0','\0', '\0','\0', '\0','\0', '\0',
                                     '\0', '\0','\0', '\0','\0', '\0','\0', '\0','\0', '\0',
                                     '\0', '\0','\0', '\0','\0', '\0','\0', '\0','\0', '\0',
                                     '\0', '\0','\0', '\0','\0', '\0','\0', '\0','\0', '\0',
                                     '\0', '\0','\0', '\0','\0', '\0','\0', '\0','\0', '\0',
                                     '\0', '\0','\0', '\0','\0', '\0','\0', '\0','\0', '\0',
                                     '\0', '\0','\0', '\0','\0', '\0','\0', '\0','\0', '\0'};

        // Menu
        do {
            system("cls");
            mensajes(9,0);
            printf("1) Vamos a jugar\t\t\t3) Veamos m%cs..\n", 160);
            puts("\n2) Cargar una partida guardada\t\t4) Salimos\n");
            printf("%cQu%c haremos? ", 168, 130);
            scanf("%s", letra);

            opc = validarCaracter(letra);

            if (continuar == validar(opc, 1, 4)) {
                system("Pause");
            } else {
                continuar = 1;
            }

        } while (continuar != 1);

        continuar = 0;

        // Direccionamiento de las opciones
        switch (opc) {
            case 1:
                impriMat(filas, columnas, tablero);
                jugar(filas,columnas, tablero, 0 , 0);
                break;
            case 2:
                system("cls");
                mensajes(12,0);
                cargarPartida(filas, columnas, tablero);
                break;
            case 3:
                aboutGame();
                break;
            default:
                opc = -1;
                break;
        }
    } while (opc != -1);

    // Fin del programa
    mensajes(10,0);
    system("Pause");
    system("cls");  // Limpia pantalla
    return 0;       // Retorna 0
}