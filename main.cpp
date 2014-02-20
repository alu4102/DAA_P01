#include "header.h"

void menu(void);

int main(int argc, char* argv[]) {

	menu();

	cin.get();
	return 0;
}

void menu(void)
{
	char opcion;

	RAM A;

	string line;							// Se encargará de leer las líneas e imprimir el código original
	string fileP = "test4.ram";				// Nombre del archivo por defecto del Programa a cargar en la Máquina RAM
	string fileCE = "in4.ram";				// Nombre del archivo de la cinta de entrada por defecto
	string fileCS = "out4.ram";				// Nombre del archivo de la cinta de salida
		// Ficheros Estándar
	ifstream inP(fileP.c_str());			// Entrada del fichero del programa a cargar en la máquina de RAM
	ifstream inCE(fileCE.c_str());			// Entrada del fichero de la cinta de entrada
	if (inP.is_open() && inCE.is_open())
	{
		A.read_P(inP);						// Carga en la matriz desde el fichero, los datos necesarios
		inP.close();						// Se cierra el fichero
		A.read_CE(inCE);					// Carga la cinta de entrada
		inCE.close();						// Se cierra el fichero
		do // Empieza el Menú
		{
			system("cls");
			cout << "\n\n";
			cout << "                                MENU " << endl;
			cout << "    ***************************************************************" << endl;
			cout << "\t l) Cargar ficheros (por defecto " << fileP << "). " << endl;
			cout << "" << endl;
			cout << "\t r) Ver los registros. " << endl;
			cout << "\t i) Ver Cinta de Entrada. " << endl;
			cout << "\t o) Ver Cinta de Salida. " << endl;
			cout << "\t u) Ver el c\242digo codificado. " << endl;
			cout << "\t w) Ver el c\242digo original. " << endl;
			cout << "\t c) Ver C\242digos de los OPCODE. " << endl;
			cout << "" << endl;
			cout << "\t t) Traza. " << endl;
			cout << "\t g) Go. " << endl;
			cout << "\t s) Desensamblador. " << endl;
			cout << "" << endl;
			cout << "\t h) Ayuda. " << endl;
			cout << "" << endl;
			cout << "\t x) Salir. " << endl;
			cout << "    ***************************************************************" << endl;
			cout << "\t    Elige una opci\242n: ";
			opcion = getchar();
			
			system("cls");

			switch (tolower(opcion))
			{
				// ****************************************
				// CARGAR FICHEROS
			case 'l': 
				cout << "\n\n\t\t Escriba los nombres de los archivos: \n";
				cout << "\t\t Programa: \t\t";
				cin >> fileP;
				cout << "\t\t Cinta de Entrada: \t";
				cin >> fileCE;
				cout << "\t\t Cinta de Salida: \t";
				cin >> fileCS;
				inP.open(fileP.c_str(), ifstream::in);			
				inCE.open(fileCE.c_str(), ifstream::in);
				if (inP.is_open() && inCE.is_open()) {
					A.read_P(inP);						// Carga en la matriz desde el fichero, los datos necesarios
					inP.close();						// Se cierra el fichero
					A.read_CE(inCE);					// Carga la cinta de entrada
					inCE.close();
					cout << "\n\n\t\t Los archivos han sido cargado con \202xito.";
				} else {
					cout << "\n\n\t\t Error al leer alguno de los ficheros."; 
				}
				break;
			case 'r':													// VER REGISTRO
				A.print_R();
				break;
			case 'i':													// VER CINTA DE ENTRADA
				A.print_CE();
				break;
			case 'o':													// VER CINTA DE SALIDA
				A.print_CS();
				break;
			case 'u':	
				A.print_P_Cod();										// IMPRIMIR CÓDIGO CODIFICADO
				break;
			case 'w':													// IMPRIMIR CÓDIGO ORIGINAL
				inP.open(fileP.c_str(), ifstream::in);
				if (inP.is_open()) {
					while (getline(inP, line)) {						// Se recorre el archivo línea a línea
						cout << line << endl;							// Se imprime cada línea
					}
					inP.close();
				}
				else {
					cout << "\n\n\t\t Error al leer fichero uno de los ficheros.";
					cin.get();
				}
				break;
			case 'c':													// IMPRIME LOS CÓDIGOS DEL OPCODE CORRESPONDIENTE
				A.print_OPCODE();
				break;
			case 't':													// TRAZA
				A.traza();
				break;
			case 'g':													// GO
				A.go();
				break;
			case 's':													// DESENSAMBLADOR
				A.print_P_Desc();
				break;
			case 'h':													// AYUDA
				cout << "\n\n\t\t AYUDA \n\n";
				cout << "       ******************************************************\n";
				cout << "\t Deber\241a primero:\n";
				cout << "\t 1) Cargar los ficheros con el comando l).\n";
				cout << "\t Luego, ya podr\241a ver estos ficheros con los \n";
				cout << "\t comandos: r, i, o, w. Una vez verificado los \n";
				cout << "\t ficheros, puedes observar como queda la codi- \n";
				cout << "\t ficaci\242n con el comando: w y con el comando c\n";
				cout << "\t la codificaci\242n utilizada.\n";
				cout << "\t Por \243ltimo, puedes utilizar los comandos: g\n";
				cout << "\t para ejecutar el programa.\n";
				cout << "\t O el comando t para ejecutarlo pero observando\n";
				cout << "\t cada paso.\n";
				cout << "\t O observar como quedar\241a al descodificarlo tras\n";
				cout << "\t haberlo codificado con.\n";
				cout << "\t el comando s.\n";
				break;
			case 'x':													// SALIR
				system("cls"); cout << "\n\n\t\t Esperemos verlo nuevamente... "; continue;
			default:													// OTRA OPCIÓN
				cout << "\n\n\n\t\t Opci\242n no valida. "; cin.get(); break;
			}															// FIN SWITCH
			cout << endl << "\n\tPresione <Enter>...";
			cin.ignore();
			cin.get();
		} while (opcion != 'x');										// FIN MENÚ
	}
	else	/* En caso de que alguno de los ficheros no pueda abrirse. */
	{
		cout << "\n\n\t\t Error al leer fichero uno de los ficheros.";
	}

	//cout << "\n\n\t\t Se est\240 descangando el contenido de la cinta de salida en el fichero " << fileCS;
	ofstream outCS;
	outCS.open(fileCS.c_str(), ofstream::out | ofstream::trunc);
	(outCS) ? A.write_CS(outCS) : cout << "\n\n\t\t Error al leer escribir en el fichero.";;
	outCS.close();
}