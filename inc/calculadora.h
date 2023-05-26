/***************************************************************************************************
 * @file    calculadora.h
 * @author  Ezio I Jogna Prat
 * @date    Mayo 2023
 * @brief   
 **************************************************************************************************/

/************************************* GUARDA C++ - INICIO ****************************************/
#ifdef __cplusplus
extern "C" {
#endif

/************************************* INCLUDES ***************************************************/
#include <stdbool.h>

/************************************* MACROS AND DEFINES *****************************************/

/************************************* TYPEDEFS & STRUCTIS ****************************************/
typedef int (*funcion_t)(int, int);

typedef struct operacion_s * operacion_t;

typedef struct calculadora_s * calculadora_t;



/************************************* EXPORTED VARIABLES *****************************************/

/************************************* GLOBAL FUNCTION PROTOTYPES *********************************/
calculadora_t CrearCalculadora(void);

bool AgregarOperacion(calculadora_t calculadora, char operador, funcion_t funcion);

int Calcular(calculadora_t calculadora, char * cadena);


/************************************* GUARDA C++ - FIN *******************************************/
#ifdef __cplusplus
}
#endif