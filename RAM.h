#pragma once
#include "header.h"

//enum type_opc { LOAD, STORE, ADD, SUB, MULT, DIV, READ, WRITE, JUMP, JGTZ, JZERO, HALT };

class RAM
{
private:
		// Atributos
	vector<string> I_;							/* Estructura que almacena las instrucciones del programa RAM codificadas*/
	index m_;									/* Número de filas.   */
	index n_;									/* Número de columnas.*/
		//Métodos
	index position(index m, index n);			/* Transforma los índices de matriz en vector */
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
		// Métodos: Obtener y Establecer
	vector<string> get_I();						/* Devuelve el vector que almacena el código codificado. */
	index get_m();								/* Devuelve el nº de filas. */
	index get_n();								/* Devuelve el nº de columnas. */
	string get_item(index, index);				/* Devuelve el valor de la matriz en la posición (i, j). */
	void set_m(index);							/* Establece el valor del nº de filas. */
	void set_n(index);							/* Establece el valor del nº de columnas. */
	void set_item(index, index, string);		/* Establece el valor de la matriz en la posición (i, j) por item. */
		// Métodos: E/S por fichero/consola
	istream& readFile(istream& in);				/* Lee el fichero de la práctica y lo almacena en la matriz. */
	void printCod();							/* Imprime la estructura codificada, que es tal como está la estructura. */
	void printDesc();							/* Imprime la estructura descodificada. */
		// Destructor
	virtual ~RAM();
};

