/***************************************************************************************************
 * @file    main.c
 * @author  Ezio I Jogna Prat
 * @date    Mayo 2023
 * @brief
 **************************************************************************************************/

/************************************* INCLUDES ***************************************************/
#include <stdio.h>
#include "calculadora.h"

/************************************* MACROS AND DEFINES *****************************************/

/************************************* VARIABLES **************************************************/

/************************************* TYPEDEFS & STRUCTS *****************************************/

/************************************* FUNCTION DECLARATIONS **************************************/
int suma(int a, int b);
int resta(int a, int b);
int producto(int a, int b);

/************************************* FUNCTION DEFINES *******************************************/
/// @brief suma a + b
/// @param a
/// @param b
/// @return
int suma(int a, int b){
    return a + b;
}

/// @brief resta a - b
/// @param a
/// @param b
/// @return
int resta(int a, int b){
    return a - b;
}

/// @brief producto a * b
/// @param a
/// @param b
/// @return
int producto(int a, int b){
    return a * b;
}

/// @brief cociente entre a y b
/// @param a
/// @param b
/// @return
int cociente(int a, int b){
    return a / b;
}

int main(void){
    int resultado;
    calculadora_t calculadora;
    calculadora = CrearCalculadora();

    AgregarOperacion(calculadora, '+', suma);
    AgregarOperacion(calculadora, '-', resta);
    AgregarOperacion(calculadora, '*', producto);
    AgregarOperacion(calculadora, '/', cociente);

    resultado = Calcular(calculadora, "2*4");
    printf("Resultado %i\r\n", resultado);


    resultado = Calcular(calculadora, "2-4");
    printf("Resultado %i\r\n", resultado);


    resultado = Calcular(calculadora, "2+4");
    printf("Resultado %i\r\n", resultado);
    
    
    resultado = Calcular(calculadora, "8/4");
    printf("Resultado %i\r\n", resultado);

    return 0;
}
