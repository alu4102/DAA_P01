#include "RAM.h"

							// ************* M�TODOS PRIVADOS

//========================================================================================
// DEVUELVE EL �NDICE DEL VECTOR CORRESPONDIENTE DE LA MATRIZ P, INDEXADO EN (1,1)
//========================================================================================

index RAM::position(index i, index j)
{
	if ((i<1) || (i>get_m()) || (j<1) || (j>get_n()))
	{
		cerr << "Error en los �ndices de la matriz." << endl;
		return 0;
	}

	return (i - 1)*get_n() + (j - 1);
}

//========================================================================================
// DEVUELVE EL STRING PERO ELIMIN�NDOLE TODOS LOS ESPACIOS EN BLANCO
//========================================================================================

string RAM::Trim(string::const_iterator i, string::const_iterator f)
{
	string::const_iterator it;
	string buff;

	for (it = i; it != f; ++it)					// Recorre todo el string
		if (*it != ' ') buff += *it;			// S�lo almacena en buff un caracter que no sea espacio en blanco

	return buff;
}

//========================================================================================
// DEVUELVE EL STRING PERO ELIMIN�NDOLE LOS ESPACIOS DEL LADO IZQUIERDO
//========================================================================================

string RAM::LTrim(string::const_iterator i, string::const_iterator f)
{
	string::const_iterator it;
	string buff;

	while (*i == ' ') i++;						// Recorre los espacios en blanco hasta encontrar un caracter
	for (it = i; it != f; ++it) buff += *it;	// Almacena el resto del string

	return buff;
}

//========================================================================================
// DEVUELVE EL STRING QUE SE ENCUENTRA EN SEGUNDA POSICI�N
//========================================================================================

string RAM::TrimSecond(string::const_iterator i, string::const_iterator f)
{
	string::const_iterator it;
	string buff;

	while (*i == ' ') i++;				// Recorre los espacios en blanco hasta encontrar un caracter
	while (*i != ' ') i++;				// Recorre hasta que se encuentre el primer espacio
	while (*i == ' ') i++;				// Recorre los espacios en blanco hasta encontrar un caracter
	for (it = i; it != f; ++it)			// Recorre hasta el final
		if (*it != ' ') buff += *it;	// Si no tiene espacio en blanco lo almacena en buff

	return buff;
}

//========================================================================================
// DEVUELVE EL STRING QUE SE ENCUENTRA EN PRIMERA POSICI�N
//========================================================================================

string RAM::TrimFirst(string::const_iterator i, string::const_iterator f)
{
	string::const_iterator it;
	string buff;

	while (*i == ' ') i++;		// Recorre los espacios en blanco hasta encontrar un caracter
	while (*i != ' ') {			// Recorre hasta que se encuentre el primer espacio
		buff += *i;				// Almacena en buff la palabra encontrada
		i++;
	}

	return buff;
}

//========================================================================================
// DEVUELVE EL STRING CODIFICADO DEL OPCODE
//========================================================================================

string RAM::codOpcode(string str) {

	string out;								// Devuelve el string con su respectivo c�digo

	if (str == "LOAD") out = "1";
	else if (str == "STORE") out = "2";
	else if (str == "ADD") out = "3";
	else if (str == "SUB") out = "4";
	else if (str == "MULT") out = "5";
	else if (str == "DIV") out = "6";
	else if (str == "READ") out = "7";
	else if (str == "WRITE") out = "8";
	else if (str == "JUMP") out = "9";
	else if (str == "JGTZ") out = "10";
	else if (str == "JZERO") out = "11";
	else if (str == "HALT") out = "12";

	return out;
}

//========================================================================================
// EJECUTA EL OPCODE LOAD
//========================================================================================

void RAM::LOAD(string dir, string oper) {
	if (dir == "")
		R_[0] = R_[atoi(oper.c_str())];
	else if (dir == "=")
		R_[0] = oper;
	else if (dir == "*")
		R_[0] = R_[atoi(R_[atoi(oper.c_str())].c_str())];
	else
		cout << "\t\t Error en el direccionamiento";
}

//========================================================================================
// EJECUTA EL OPCODE STORE
//========================================================================================

void RAM::STORE(string dir, string oper) {


}

//========================================================================================
// EJECUTA EL OPCODE ADD
//========================================================================================

void RAM::ADD(string dir, string oper) {


}

//========================================================================================
// EJECUTA EL OPCODE SUB
//========================================================================================

void RAM::SUB(string dir, string oper) {


}

//========================================================================================
// EJECUTA EL OPCODE MULT
//========================================================================================

void RAM::MULT(string dir, string oper) {


}

//========================================================================================
// EJECUTA EL OPCODE DIV
//========================================================================================

void RAM::DIV(string dir, string oper) {


}

//========================================================================================
// EJECUTA EL OPCODE READ
//========================================================================================

void RAM::READ(string dir, string oper) {


}

//========================================================================================
// EJECUTA EL OPCODE WRITE
//========================================================================================

void RAM::WRITE(string dir, string oper) {


}

//========================================================================================
// EJECUTA EL OPCODE JUMP
//========================================================================================

void RAM::JUMP(string tag) {


}

//========================================================================================
// EJECUTA EL OPCODE JGTZ
//========================================================================================

void RAM::JGTZ(string tag) {


}

//========================================================================================
// EJECUTA EL OPCODE JZERO
//========================================================================================

void RAM::JZERO(string tag) {


}

//========================================================================================
// EJECUTA EL OPCODE HALT
//========================================================================================

void RAM::HALT() {


}

//========================================================================================
// DEVUELVE EL STRING DESCODIFICADO DEL OPCODE
//========================================================================================

string RAM::desOpcode(string str) {

	string out;								// Devuelve el string con su respectivo OPCODE

	if (str == "1") out = "LOAD";
	else if (str == "2") out = "STORE";
	else if (str == "3") out = "ADD";
	else if (str == "4") out = "SUB";
	else if (str == "5") out = "MULT";
	else if (str == "6") out = "DIV";
	else if (str == "7") out = "READ";
	else if (str == "8") out = "WRITE";
	else if (str == "9") out = "JUMP";
	else if (str == "10") out = "JGTZ";
	else if (str == "11") out = "JZERO";
	else if (str == "12") out = "HALT";

	return out;
}

							// ************* CONSTRUCTORES

//========================================================================================
// CONSTRUCTOR POR DEFECTO
// El n� de columnas ser� 2 � 3, 1� almacena comando, 2� operando o etiqueta, 3� comentario
//========================================================================================

RAM::RAM():
	m_(0),
	n_(2)
{
	R_.push_back("0");			// Creamos el acumulador
}

//========================================================================================
// CONSTRUCTOR QUE ESTABLECE EL N� DE FILAS Y COLUMNAS
//========================================================================================

RAM::RAM(index m, index n) :
m_(m),
n_(n)
{
}

							// ************* M�TODOS: GETs y SETs

//========================================================================================
// DEVUELVE LA POSICI�N I DE LA CINTA DE ENTRADA INDEXADO EN 1
//========================================================================================

string RAM::get_CE(index i)
{
	if ((i<1) || (i>CE_.size()))
	{
		cerr << "Error en los �ndices del vector." << endl;
		return 0;
	}

	return CE_[i - 1];
}

//========================================================================================
// DEVUELVE LA POSICI�N I DE LA CINTA DE SALIDA INDEXADO EN 1
//========================================================================================

string RAM::get_CS(index i)
{
	if ((i<1) || (i>CS_.size()))
	{
		cerr << "Error en los �ndices del vector." << endl;
		return 0;
	}
	return CS_[i - 1];
}

//========================================================================================
// DEVUELVE LA POSICI�N I DEL REGISTRO INDEXADO EN 0
//========================================================================================

string RAM::get_R(index i)
{
	if ((i<0) || (i>=R_.size()))
	{
		cerr << "Error en los �ndices del vector." << endl;
		return 0;
	}
	return R_[i];
}

//========================================================================================
// ESTABLECER EL VALOR DE LA POSICI�N i DEL VECTOR CE INDEXADO DESDE 1
//========================================================================================

void RAM::set_CE(index i, string item)
{
	if ( (i<1) || (i>CE_.size()) )
	{
		cerr << "Error en los �ndices del vector." << endl;
	}

	CE_[i-1] = item;
}

//========================================================================================
// ESTABLECER EL VALOR DE LA POSICI�N i DEL VECTOR CS INDEXADO DESDE 1
//========================================================================================

void RAM::set_CS(index i, string item)
{
	if ((i<1) || (i>CS_.size()))
	{
		cerr << "Error en los �ndices del vector." << endl;
	}

	CS_[i-1] = item;
}

//========================================================================================
// ESTABLECER EL VALOR DE LA POSICI�N i DEL VECTOR R INDEXADO DESDE 0
//========================================================================================

void RAM::set_R(index i, string item)
{
	if ((i<0) || (i>=CS_.size()))
	{
		cerr << "Error en los �ndices del vector." << endl;
	}

	R_[i] = item;
}


							// ************* M�TODOS PRIVADOS

void RAM::traza() 
{
	int paso = 0;
	for (int i = 1; i <= get_m(); i++) {	// Lee todas las instrucciones del c�digo

	}
}

//========================================================================================
// LECTURA DEL FICHERO QUE CARGA EL PROGRAMA A CARGAR EN LA M�QUINA RAM
// ---------------------------------------------------------------------------------------
// Aunque lo dej� preparado para guardar los comentarios, en principio no se almacenan
// ya que no se ped�a. Cuando se profundice en la pr�ctica sabr� si lo necesitar� o no.
// Para ello, lo que tengo pensado es hacer un enum de entrada, y dependiendo la opci�n
// que soliciten (WITHTAG, WITHCOMMTAG, WITHOUT) se habilitar� una zona. Y con ello, la
// n ser� 2, 3 � 4 depediendo las columnas a guardar.
//========================================================================================

istream& RAM::read_P(istream& file)
{
	vector<string> vTag;						// Vector que almacenar� las etiquetas
	get_P().clear();
	set_n(2);									// En esta opci�n s�lo se almacena el opcode y su operando

	string line, tag, comm, instruc, oper;		// Cada l�nea, etiqueta, comentario, opcode, operando/etiqueta
	size_t indexC, indexT;						// �ndice de Comentario, Etiqueta y Et Fin
	int nLine = 1;								// N� de l�neas con c�digo sin comentario. �til para saber donde van las etiquetas

	while (getline(file, line)) {
		// ****** ETIQUETA
		indexT = line.find(":");				// �ndice que guarda el lugar donde termina la etiqueta
		if (indexT < 1000) {					// Si existe etiqueta (el �ndice no puede ser el npos).
			tag = line.substr(0, indexT);		// Substring que contiene desde el inicio hasta el :, almacena el nombre de la etiqueta
			tag = Trim(tag.begin(), tag.end());	// Eliminamos los espacios en blanco
			vTag.push_back(to_string(nLine));	// Se a�ade a un vector el n� de l�nea donde aparece
			vTag.push_back(tag);				// Se a�ade el nombre de la etiqueta
			indexT++;							// Se a�ade uno al �ndice de la etiqueta para no coger el caracter : en las instrucciones
		}
		else {
			indexT = 0;							// Sino se encuentra etiqueta coloco el �ndice en 0, para iniciar desde ah� la b�squeda de la instrucci�n
			tag = "";							// Si me hiciera almacenar m�s adelante el nombre de la etiqueta, saber que aqu� no ten�a
		}
		// ****** COMENTARIO
		indexC = line.find(";");				// Almacena el �ndice donde empieza el comentario
		if (indexC < 1000) {					// Si existe comentario su �ndice es distinto del npos (un n� muy grande)
			comm = line.substr(indexC + 1);		// Almacena el comentario, es un substring desde ; hasta el final (se le a�ade +1 para eliminar ;
		}
		else {
			indexC = line.size();				// Sino se encuentra comentario es hasta el final de la l�nea la instrucci�n
			comm = "";							// Sino existe comentario es ""
		}
		// ****** INSTRUCCIONES = OPCODE + OPERANDO/ETIQUETA/NADA
		if (indexT != indexC) {										// Cuando existe c�digo 
			instruc = line.substr(indexT, indexC - indexT);			// Substring que contiene la instrucci�n y el operando/tag juntos
			instruc.append(" ");									// A�ado un espacio al final para no exista fallo con el �ltimo comando
			instruc = TrimFirst(instruc.begin(), instruc.end());	// Captura la primera palabra
			instruc = codOpcode(instruc);							// Codifico el opcode
			if (instruc != "12") {									// 12 = HALT, entra salvo que sea 12, que no tiene ni tag ni operando
				oper = line.substr(indexT, indexC - indexT);		// Substring que contiene la instrucci�n y el operando/tag juntos
				//oper.append(" ");									
				oper = TrimSecond(oper.begin(), oper.end());		// Se toma la segunda palabra que corresponde con el operando/etiqueta
			}
			else
				oper = "";											// Halt no tiene nada
			set_P(instruc);											// Se a�ade el opcode a la estructura
			set_P(oper);											// Se a�ade el operando/etiqueta a la estructura
			nLine++;												// Se incrementa el n� de l�neas con c�digo, para identificar la etiqueta
		}
	}

	set_m(nLine - 1);												// Al querer s�lo contar las l�neas con c�digo, y estar el tag primero que instrucc
																	// se me hace necesario incrementarlo dentro de �ste, por lo que, al final me sobra uno

	for (int i = 0; i < vTag.size() / 2; i++) {						// Se recorre el vector que almacena las etiquetas y su posici�n
		for (int j = 1; j <= get_m(); j++) {							// Se recorre el vector que almacena el opcode y su operando/etiqueta
			if (vTag[2 * i + 1] == get_P(j, 2))						// Si coincide el nombre de la etiqueta con el etiqueta del opcode
				set_P(j, 2, vTag[2 * i]);							// Se cambia por el n� de l�nea
		}
	}

	return file;
}

//========================================================================================
// LECTURA POR FICHERO LA CINTA DE ENTRADA
//========================================================================================

istream& RAM::read_CE(istream& file)
{
	get_CE().clear();
	string str;

	while (file.good()) {
		file >> str;
		set_CE(str);
	}

	return file;
}

//========================================================================================
// IMPRIME LA ESTRUCTURA, QUE SE GUARDA CODIFICADA
//========================================================================================

void RAM::print_P_Cod() {
	cout << "\t OPCODE \t OPERANDO/ETIQUETA \n";
	cout << "       *******************************\n";
	for (int i = 1; i <= get_m(); i++) 
		cout << "L" << i << "\t  " << get_P(i, 1) << "\t\t" << get_P(i, 2) << "\n";
}

//========================================================================================
// IMPRIME LA ESTRUCTURA, QUE SE GUARDA CODIFICADA
//========================================================================================

void RAM::print_P_Desc() {
	cout << "\t OPCODE \t OPERANDO/ETIQUETA \n";
	cout << "       *******************************\n";
	for (int i = 1; i <= get_m(); i++)
		if ((get_P(i, 1) == "9") || (get_P(i, 1) == "10") || (get_P(i, 1) == "11"))
			cout << "L" << i << "\t  " << desOpcode(get_P(i, 1)) << "\t\t\tL" << get_P(i, 2) << "\n";
		else
			cout << "L" << i << "\t  " << desOpcode(get_P(i, 1)) << "\t\t\t" << get_P(i, 2) << "\n";
}

//========================================================================================
// IMPRIME LA CINTA DE ENTRADA
//========================================================================================

void RAM::print_CE() {
	cout << "\n\n\t\t   CINTA DE ENTRADA \n";
	cout << "\t       ************************\n";
	cout << "\t\t ENTRADA\tVALOR \n";
	cout << "\t       ************************\n";
	for (int i = 1; i <= get_CE().size(); i++)
		cout << "\t\t Entrada" << i << "\t  " << get_CE(i) << "\n";

	if (get_CE().size() == 0)
		cout << "\t\t\t Salida Vacia" << endl;
}

//========================================================================================
// IMPRIME LA CINTA DE SALIDA
//========================================================================================

void RAM::print_CS() {
	cout << "\n\n\t\t   CINTA DE SALIDA \n";
	cout << "\t       ************************\n";
	cout << "\t\t SALIDA  \tVALOR \n";
	cout << "\t       ************************\n";
	for (int i = 1; i <= get_CS().size(); i++)
		cout << "\t\t Salida" << i << "\t  " << get_CS(i) << "\n";

	if (get_CS().size() == 0)
		cout << "\t\t Cinta de Salida Vacia" << endl;
}

//========================================================================================
// IMPRIME LOS REGISTROS
//========================================================================================

void RAM::print_R() {
	cout << "\n\n\t\t\tREGISTRO \n";
	cout << "\t       ************************\n";
	cout << "\t\t REGISTRO  \tVALOR \n";
	cout << "\t       ************************\n";
	for (int i = 0; i < get_R().size(); i++)
		cout << "\t\t Registro" << i << "\t  " << get_R(i) << "\n";

	if (get_R().size() == 0)
		cout << "\t\t Registros Vacio" << endl;
}

//========================================================================================
// IMPRIME LA CODIFICACI�N DEL OPCODE
//========================================================================================

void RAM::print_OPCODE() {
	cout << "\n\n\t\tOPCODE\tC\242DIGO\n";
	cout << "\t      ******************\n";
	cout << "\t\t LOAD\t   1\n";
	cout << "\t\t STORE\t   2\n";
	cout << "\t\t ADD\t   3\n";
	cout << "\t\t SUB\t   4\n";
	cout << "\t\t MULT\t   5\n";
	cout << "\t\t DIV\t   6\n";
	cout << "\t\t READ\t   7\n";
	cout << "\t\t WRITE\t   8\n";
	cout << "\t\t JUMP\t   9\n";
	cout << "\t\t JGTZ\t  10\n";
	cout << "\t\t JZERO\t  11\n";
	cout << "\t\t HALT\t  12\n";
}


//========================================================================================
// DESTRUCTOR
//========================================================================================

RAM::~RAM()
{
	get_P().clear();
	get_CE().clear();
	get_CS().clear();
	get_R().clear();
	set_m(0);
	set_n(0);
}




