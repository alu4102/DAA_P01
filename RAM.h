#pragma once
#include "header.h"

//enum type_opc { LOAD, STORE, ADD, SUB, MULT, DIV, READ, WRITE, JUMP, JGTZ, JZERO, HALT };

class RAM
{
private:
		// Atributos
	vector<string> I_;							/* Estructura que almacena las instrucciones del programa RAM codificadas*/
	index m_;									/* N�mero de filas.   */
	index n_;									/* N�mero de columnas.*/
		//M�todos
	index position(index m, index n);			/* Transforma los �ndices de matriz en vector */
	string Trim(string::const_iterator, string::const_iterator);
	string LTrim(string::const_iterator, string::const_iterator);
	string TrimFirst(string::const_iterator, string::const_iterator);
	string TrimSecond(string::const_iterator, string::const_iterator);
	string codOpcode(string);
	string desOpcode(string);
public:
		// Cronstructores
	RAM();
	RAM(index, index);
		// M�todos: Obtener y Establecer
	vector<string> get_I();						/* Devuelve el vector que almacena el c�digo codificado. */
	index get_m();								/* Devuelve el n� de filas. */
	index get_n();								/* Devuelve el n� de columnas. */
	string get_item(index, index);				/* Devuelve el valor de la matriz en la posici�n (i, j). */
	void set_m(index);							/* Establece el valor del n� de filas. */
	void set_n(index);							/* Establece el valor del n� de columnas. */
	void set_item(index, index, string);		/* Establece el valor de la matriz en la posici�n (i, j) por item. */
		// M�todos: E/S por fichero/consola
	istream& readFile(istream& in);				/* Lee el fichero de la pr�ctica y lo almacena en la matriz. */
	void printCod();							/* Imprime la estructura codificada, que es tal como est� la estructura. */
	void printDesc();							/* Imprime la estructura descodificada. */
		// Destructor
	virtual ~RAM();
};

