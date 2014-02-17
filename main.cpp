#include "header.h"

void menu(void);

int main(int argc, char* argv[]) {

	menu();

	//cout << endl << "Presione <Enter>...";
	cin.get();
	return 0;
}

void menu(void)
{
	char opcion;

	RAM A;

	string line;							// Se encargará de leer las líneas e imprimir el código original
	string fileP = "test2.ram";				// Nombre del archivo por defecto del Programa a cargar en la Máquina RAM
	string fileCE = "in2.ram";				// Nombre del archivo de la cinta de entrada por defecto
	string fileCS = "out2.ram";				// Nombre del archivo de la cinta de salida
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
			cout << "\t l) Cargar ficheros (por defecto está test2.ram). " << endl;
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
			cin >> opcion;

			system("cls");

			switch (opcion)
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
					cout << "\n\n\t\t El archivo ha sido cargado con \202xito.";
					cin.get();
				} else {
					cout << "\n\n\t\t Error al leer alguno de los ficheros."; 
					cin.get();
				}
				break;
				// ****************************************
				// VER REGISTRO
			case 'r':
				A.print_R();
				cin.get(); break;
				// VER CINTA DE ENTRADA
			case 'i':
				A.print_CE();
				cin.get(); break;
				// VER CINTA DE ENTRADA
			case 'o':
				A.print_CS();
				cin.get(); break;
				// IMPRIMIR CÓDIGO CODIFICADO
			case 'u':	A.print_P_Cod(); cin.get(); break;		// Se imprime el código codificado
				// IMPRIMIR CÓDIGO ORIGINAL
			case 'w':
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
				cin.get(); break;
				// IMPRIME LOS CÓDIGOS DEL OPCODE CORRESPONDIENTE
			case 'c':
				A.print_OPCODE();
				cin.get(); break;
				// ****************************************
				// TRAZA
			case 't':
				cout << "\n\n\t\t TRAZA \n\n";
				A.traza();
				cin.get(); break;
				// GO
			case 'g':
				A.go();
				cout << "\n\n\t\t La ejecuci\242n se ha realizado con  \202xito.";
				cin.get(); break;
				// DESENSAMBLADOR
			case 's':
				cout << "\n\n\t\t DESENSAMBLADOR \n\n";
				A.print_P_Desc(); cin.get(); break;	// Se imprime el código descodificado después de haber sido codificado
				cin.get(); break;
				// ****************************************
				// AYUDA
			case 'h':
				cin.get(); break;
				// ****************************************
				// SALIR
			case 'x': system("cls"); cout << "\n\n\t\t Esperemos verlo nuevamente... "; continue;
			default: cout << "\n\n\n\t\t Opcion no valida. "; cin.get(); break;
			} // Fin switch
			cout << endl << "\n\tPresione <Enter>...";
			cin.get();
		} while (opcion != 'x');
	}
	else	/* En caso de que alguno de los ficheros no pueda abrirse. */
	{
		cout << "\n\n\t\t Error al leer fichero uno de los ficheros.";
	}
	cin.get();
}