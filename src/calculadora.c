/***************************************************************************************************
 * @file    calculadora.c
 * @author  Ezio I Jogna Prat
 * @date    Mayo 2023
 * @brief
 **************************************************************************************************/

/************************************* INCLUDES ***************************************************/
#include "calculadora.h"
#include <stdlib.h>
#include <string.h>

/************************************* MACROS AND DEFINES *****************************************/

/************************************* VARIABLES **************************************************/

/************************************* TYPEDEFS & STRUCTS *****************************************/
struct operacion_s {
    char operador;
    funcion_t funcion;
    operacion_t siguiente;
};

struct calculadora_s {
    operacion_t operaciones;
};

/************************************* FUNCTION DECLARATIONS **************************************/
operacion_t BuscarOperacion(calculadora_t calculadora, char operador);

/************************************* FUNCTION DEFINES *******************************************/
operacion_t BuscarOperacion(calculadora_t calculadora, char operador) {
    operacion_t result = NULL;
    for(operacion_t actual = calculadora->operaciones; actual != NULL; actual = actual->siguiente){
        if(actual->operador == operador){
            result = actual;
            break;
        }
    }
    return result;
}

calculadora_t CrearCalculadora(void) {
    calculadora_t result;
    result = malloc(sizeof(struct calculadora_s));

    if (result) {
        memset(result, 0, sizeof(struct calculadora_s));
    }
    return result;
}

bool AgregarOperacion(calculadora_t calculadora, char operador, funcion_t funcion) {
    
    operacion_t operacion = NULL;

    if (!BuscarOperacion(calculadora, operador)) {
        operacion = malloc(sizeof(struct operacion_s));
    }
    if (operacion) {
        operacion->operador = operador;
        operacion->funcion = funcion;
        operacion->siguiente = calculadora->operaciones;
        calculadora->operaciones = operacion;
    }
    return (operacion != NULL);
}

int Calcular(calculadora_t calculadora, char * cadena) {
    int a, b;
    char operador;
    int result = 0;

    for(int indice = 0; indice < strlen(cadena); indice++){
        if(cadena[indice] < '0'){
            operador = cadena[indice];
            a = atoi(cadena);
            b = atoi(cadena + indice + 1);
            break;
        }
    }
    operacion_t operacion = NULL;
    operacion = BuscarOperacion(calculadora, operador);
    if (operacion) {
        result = operacion->funcion(a, b);
    }

    return result;
}

