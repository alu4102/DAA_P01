#include <stdio.h>		// Cabecera que contendr� el procedimiento sprintf
#include <iostream>		// Cabecera que tendr� la E/S mediante flujo
#include <cmath>		// Cabecera que contendr� las funcioens matem�ticas
#include <fstream>		// Cabecera que tendr� la E/S por ficheros
#include <string>		// Cabecera para manejar cadenas
#include <dos.h>        // necesario para _argc y argv
#include <vector>		// Cabecera para manejar un vector
# include <conio.h>
#include "RAM.h"		// Clase RAM donde almacena el ensamblado y desamblado del c�digo del programa RAM


//========================================================================================
// Definici�n de tipos
//========================================================================================

typedef int item;						/** Tipo de dato que almacenar� cada elemento de la matriz. */
typedef unsigned short int index;		/** Tipo de dato para �ndices de la matriz. */

using namespace std;