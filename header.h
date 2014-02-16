#include <stdio.h>		// Cabecera que contendrá el procedimiento sprintf
#include <iostream>		// Cabecera que tendrá la E/S mediante flujo
#include <cmath>		// Cabecera que contendrá las funcioens matemáticas
#include <fstream>		// Cabecera que tendrá la E/S por ficheros
#include <string>		// Cabecera para manejar cadenas
#include <dos.h>        // necesario para _argc y argv
#include <vector>		// Cabecera para manejar un vector
# include <conio.h>
#include "RAM.h"		// Clase RAM donde almacena el ensamblado y desamblado del código del programa RAM


//========================================================================================
// Definición de tipos
//========================================================================================

typedef int item;						/** Tipo de dato que almacenará cada elemento de la matriz. */
typedef unsigned short int index;		/** Tipo de dato para índices de la matriz. */

using namespace std;