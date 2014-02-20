#pragma once
#include "header.h"

//enum type_opc { LOAD, STORE, ADD, SUB, MULT, DIV, READ, WRITE, JUMP, JGTZ, JZERO, HALT };
enum Tcomment { SIN, CON };		/** Tipo de dato que almacenará si queremos comentario o no. */

class RAM
{
private:
	// Atributos
	vector<string> P_;							/* Programa a cargar en la Máquina RAM */
	vector<string> CE_;							/* Cinta de Entrada */
	vector<string> CS_;							/* Cinta de Salida */
	vector<string> R_;							/* Registros */
	index m_;									/* Número de filas. */
	index n_;									/* Número de columnas.*/
	//Métodos Privados
		// Transforma los índices de matriz en vector
	index position(index m, index n);
		// Quita espacios a ambos lados, a izquierda, a derecha, ...
	string Trim(string::const_iterator, string::const_iterator);
	string LTrim(string::const_iterator, string::const_iterator);
	string TrimFirst(string::const_iterator, string::const_iterator);
	string TrimSecond(string::const_iterator, string::const_iterator);
		// Codifica o decodifica los OPCODE
	string codOpcode(string);
	string desOpcode(string);	
		// Ejecución de los OPCODE
	void LOAD(string dir, string oper, Tcomment comment);			/* dir = direccionamiento, oper = operando*/
	void STORE(string dir, string oper, Tcomment comment);
	bool ADD(string dir, string oper, Tcomment comment);
	bool SUB(string dir, string oper, Tcomment comment);
	bool MULT(string dir, string oper, Tcomment comment);
	bool DIV(string dir, string oper, Tcomment comment);
	void READ(string dir, string oper, index i, Tcomment comment);
	void WRITE(string dir, string oper, Tcomment comment);
	index JUMP(string tag, index i, Tcomment comment);
	index JGTZ(string tag, index i, Tcomment comment);
	index JZERO(string tag, index i, Tcomment comment);
	bool HALT(Tcomment comment, bool error);
		// 
	void addR(index);												/* Este método crea espacio, si se intenta acceder a un índice no creado*/
	bool ejecuta(index &i, index &j, Tcomment comment);				/* Línea i de P, y registro j de R*/
	
public:
	// Cronstructores
	RAM();
	RAM(index, index);
	
	// Métodos: Obtener y Establecer
	vector<string> get_P() { return P_; };							/* Devuelve el vector que almacena el código del programa codificado. */
	string get_P(index i, index j) { return P_[position(i, j)]; };	/* Devuelve el valor de la matriz I en la posición (i, j). */
	index get_m() { return m_; };									/* Devuelve el nº de filas. */
	index get_n() { return n_; };									/* Devuelve el nº de columnas. */
	vector<string> get_CE() { return CE_; };						/* Devuelve el vector que almacena la cinta de entrada. */
	string get_CE(index);											/* Devuelve el valor del vector CE en la posición (i, j). */
	vector<string> get_CS() { return CS_; };						/* Devuelve el vector que almacena la cinta de salida. */
	string get_CS(index);											/* Devuelve el valor del vector CS en la posición (i, j). */
	vector<string> get_R() { return R_; };							/* Devuelve el vector que almacena los registros. */
	string get_R(index);											/* Devuelve el valor del Registro en la posición (i, j). */

	void set_m(index m) { m_ = m; };								/* Establece el valor del nº de filas. */
	void set_n(index n) { n_ = n; };								/* Establece el valor del nº de columnas. */
	void set_P(index i, index j, string item){P_[position(i, j)] = item;};			/* Establece el valor del programa de la posición (i, j) por el valor item. */
	void set_P(string item) { P_.push_back(item); };				/* Establece al final del vector del código P el valor del item. */
	void set_P(string, string);										/* Establece al final del vector del código P los valores opcode y operando. */
	void set_CE(index, string);										/* Establece el valor de la cinta de Entrada de la posición i por el valor item. */
	void set_CE(string item) { CE_.push_back(item); };				/* Establece al final del vector de la CE el valor item. */
	void set_CS(index, string);										/* Establece el valor de la cinta de Salida de la posición i por el valor item. */
	void set_CS(string item) { CS_.push_back(item); };				/* Establece al final del vector de la CS el valor item. */
	void set_R(index, string);										/* Establece el valor del registro de la posición i por el valor item. */
	void set_R(string item) { R_.push_back(item); };				/* Establece al final del vector del registro el valor item. */

		// Otros Métodos
	void traza();
	void go();
		// Métodos: E/S por fichero/consola
	istream& read_P(istream& in);				/* Lee por fichero el programa a cargar en la Máquina RAM. */
	istream& read_CE(istream& in);				/* Lee por fichero la cinta de entrada. */
	ofstream& write_CS(ofstream& out);			/* Escribe por fichero la cinta de salida. */
	void print_P_Cod();							/* Imprime la estructura codificada, que es tal como está la estructura. */
	void print_P_Desc();						/* Imprime la estructura descodificada, DESENSAMBLADA. */
	void print_CE();							/* Imprime la cinta de entrada. */
	void print_CS();							/* Imprime la cinta de entrada. */
	void print_R();								/* Imprime los registros. */
	void print_OPCODE();						/* Imprime la codificación del OPCODE*/

		// Destructor
	virtual ~RAM();
};

