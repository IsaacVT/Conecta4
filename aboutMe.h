//
// Created by isaac on 13/11/2021.
//

#ifndef CONECTA4_C_ABOUTME_H
#define CONECTA4_C_ABOUTME_H

#include "conectaFun.h"

void textcolor (int fondo, int texto);

void aboutGame() {
    system("cls");
    textcolor(0, 12);

    puts("\n----------------------------------------------------------\n"
         "---------------------                ---------------------\n"
         "-----------------                        -----------------\n"
         "---------------       PROYECTO FINAL       ---------------\n"
         "-------------                                -------------\n"
         "------------            CONECTA 4             ------------\n"
         "-----------                                    -----------\n"
         "----------    X O X O X O X O X O X O X O X     ----------\n"
         "---------                                        ---------\n"
         "---------        CREADO Y DESARROLLADO POR       ---------\n"
         "---------                                        ---------\n"
         "---------          ISAAC VEGA TELESFORO          ---------\n"
         "----------                                      ----------\n"
         "-----------                PARA                -----------\n"
         "------------                                  ------------\n"
         "-------------   UNIVERSIDAD IBEROAMERICANA   -------------\n"
         "--------------                              --------------\n"
         "----------------                          ----------------\n"
         "------------------        v.1.15        ------------------\n"
         "--------------------                  --------------------\n"
         "----------------------------------------------------------\n");

    textcolor(0, 15);

    puts("\n   --- Como jugar ---\n\n"
         "El proposito del juego, es colocar fichas en las columnas\n"
         "del tablero, de modo, que logres conectar cuatro de tus \n"
         "fichas, ya sea, de manera horizontal vertical o diagonal.\n\n"
         "El programa te pedira el numero de columna en el que deseas\n"
         "colocar la ficha.\n\n"
         "Una ves ingresado, preciona enter en tu teclado, para dejarla\n"
         "caer en dicha columna.\n\n"
         "Ganara el primer jugar que logre -conectar 4-\n\n"
         "Disfruten del juego.\n");

    puts("\n   --- Datos y extras del juego ---\n\n"
         "El juego fue creado con un tablero de dimensiones 10x10, sin\n"
         "embargo, si deseas crear un tablero diferente, bastara con\n"
         "realizar algunas pocas modificaciones en el codigo del programa.\n\n"
         "Para poder guardar la partida en progreso, solo coloca el\n"
         "comando -3312- en el turno que desees guardar.\n\n"
         "Para hacer un cierre forzado de la partida, coloca el comando\n"
         "-911- en el turno que desees terminar, no guardara la partida,\n"
         "ten cuidado.\n\n"
         "Dentro de la parte de guardar, cargar y borrar partida, estan\n"
         "marcadas las partes donde debes modificar la ruta, en caso de\n"
         "marcar errores.\n\n");

    puts("\n   --- Historial de versiones ---\n\n"
         "\tv.1.4\n"
         "El juego en general ya esta listo para jugar, pero aun no cuenta\n"
         "con las validaciones para ganar.\n"
         "Falta crear una libreria para colocar las funciones.\n\n"
         "\tv.1.7\n"
         "El juego ya hace las validaciones horizontales y verticales,\n"
         "faltan las diagonales.\n"
         "Ya se ha creado la libreria conectaFun.h donde se empezaran\n"
         "a colocar las funciones futuras.\n\n"
         "\tv.1.10\n"
         "El juego esta listo, junto con sus respectivas validaciones y\n"
         "funciones.\n"
         "Falta crear la pantalla de inicio de juego.\n\n"
         "\tv.1.13\n"
         "Ya esta creada la pantalla inicial junto con, parte del\n"
         "direccionamiento de las opciones mostradas.\n"
         "Falta agregar algunas funciones.\n\n"
         "\tv.1.15\n"
         "Se realizaron cambios visuales, al igual que se agregaron algunas\n"
         "funciones, como la del tiempo.\n\n"
         "\tv.1.16\n"
         "Se comenzaron con las pruebas para los archivos.\n\n"
         "A quedado implementada la funcion de guardar partida. Falta cargar\n"
         "la misma.\n\n"
         "\tv.1.17\n"
         "A quedado implementada la funcion de leer la partida guardada.\n"
         "Al igual que el borrado de la misma, si asi se desea.\n\n"
         "\tv.1.18\n"
         "Se hicieron mejoras visuales, y se hizo el cambio de lectura de\n"
         "entero a caracter, con el fin de evitar errores entre numeros y\n"
         "letras.\n\n"
         "\tv.1.19\n"
         "Siendo las 23:15 del dia 25/11/2021\n"
         "Se han concluido las modificaciones de las funciones faltantes.\n\n"
         "Eh de decir que es un gran logro para mi el haber llegado a este punto.\n"
         "Mucho esfuerzo, dedicacion y mucha investigacion.\n\n"
         "Pero al final, se logro.\n\n"
         "Puede ser que haya detalles en el codigo, no es perfecto, aunque intente\n"
         "dejar la menor cantidad.\n\n"
         "Atte. Isaac Vega Telesforo.\n\n");


    system("Pause");
}

#endif //CONECTA4_C_ABOUTME_H
