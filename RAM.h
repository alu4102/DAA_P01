#pragma once
#include "header.h"

//enum type_opc { LOAD, STORE, ADD, SUB, MULT, DIV, READ, WRITE, JUMP, JGTZ, JZERO, HALT };

class RAM
{
private:
		// Atributos
	vector<string> P_;							/* Programa a cargar en la Máquina RAM */
	vector<string> CE_;							/* Cinta de Entrada */
	vector<string> CS_;							/* Cinta de Salida */
	index m_;									/* Número de filas. */
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
	vector<string> get_I();						/* Devuelve el vector que almacena el código del programa codificado. */
	string get_I(index, index);					/* Devuelve el valor de la matriz I en la posición (i, j). */
	index get_m();								/* Devuelve el nº de filas. */
	index get_n();								/* Devuelve el nº de columnas. */
	vector<string> get_CE();					/* Devuelve el vector que almacena la cinta de entrada. */
	string get_CE(index);						/* Devuelve el valor del vector CE en la posición (i, j). */
	vector<string> get_CS();					/* Devuelve el vector que almacena la cinta de salida. */
	string get_CS(index);						/* Devuelve el valor del vector CS en la posición (i, j). */

	void set_m(index);							/* Establece el valor del nº de filas. */
	void set_n(index);							/* Establece el valor del nº de columnas. */
	void set_P(index, index, string);			/* Establece el valor del programa de la posición (i, j) por el valor item. */
	void set_CE(index, string);					/* Establece el valor de la cinta de Entrada de la posición i por el valor item. */
	void set_CS(index, string);					/* Establece el valor de la cinta de Salida de la posición i por el valor item. */
		// Métodos: E/S por fichero/consola
	istream& read_I(istream& in);				/* Lee el fichero del programa a cargar en la Máquina RAM */
	void printCod();							/* Imprime la estructura codificada, que es tal como está la estructura. */
	void printDesc();							/* Imprime la estructura descodificada. */
		// Destructor
	virtual ~RAM();
};

