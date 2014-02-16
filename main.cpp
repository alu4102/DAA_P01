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
	int opcion;

	RAM A;

	string line;							// Se encargar� de leer las l�neas e imprimir el c�digo original
	string filename = "test2.ram";			// Nombre del archivo por defecto
	ifstream in(filename.c_str());			// Entrada del fichero y establezco uno cargado est�ndar para a�adir los datos a RAM desde los ficheros
	if (in.is_open())
	{
		A.readFile(in);						// Carga en la matriz desde el fichero, los datos necesarios
		in.close();							// Se cierra el fichero
		do // Empieza el Men�
		{
			system("cls");
			cout << "\n\n";
			cout << "                                MENU " << endl;
			cout << "    ***************************************************************" << endl;
			cout << "\t 1) Cargar fichero (por defecto est� test2.ram). " << endl;
			cout << "\t 2) Imprimir el c\242digo codificado. " << endl;
			cout << "\t 3) Imprimir el c\242digo descodificado. " << endl;
			cout << "\t 4) Imprimir el c\242digo original. " << endl;
			cout << "\t 5) C\242digos de los OPCODE. " << endl;
			cout << "\t 0) Salir. " << endl;
			cout << "    ***************************************************************" << endl;
			cout << "\t    Elige una opci\242n: ";
			cin >> opcion;

			system("cls");

			switch (opcion)
			{
			case 1: 
					cout << "\n\n\t\t Escriba el nombre del archivo a leer: ";
					cin >> filename;
					in.open(filename.c_str(), ifstream::in);			// Se carga el nuevo archivo para analizar su c�digo
					if (in.is_open()) {
						A.readFile(in);
						in.close();
						cout << "\n\n\t\t El archivo ha sido cargado con \202xito.";
						cin.get();
					} else {
						cout << "\n\n\t\t Error al leer fichero uno de los ficheros."; 
						cin.get();
					}
					break;
			case 2: system("cls"); A.printCod(); cin.get(); break;		// Se imprime el c�digo codificado
			case 3:	system("cls"); A.printDesc(); cin.get(); break;		// Se imprime el c�digo descodificado despu�s de haber sido codificado
			case 4:	system("cls"); 
					in.open(filename.c_str(), ifstream::in);
					if (in.is_open()) {
						while (getline(in, line)) {							// Se recorre el archivo l�nea a l�nea
							cout << line << endl;							// Se imprime cada l�nea
						}
						in.close();
					}
					else {
						cout << "\n\n\t\t Error al leer fichero uno de los ficheros.";
						cin.get();
					}
					cin.get(); break;
			case 5:	system("cls");
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
					cin.get(); break;
			case 0: system("cls"); cout << "\n\n\t\t Esperemos verlo nuevamente... "; continue;
			default: cout << "\n\n\n\t\t Opcion no valida. "; cin.get(); break;
			}
			cout << endl << "\n\tPresione <Enter>...";
			cin.get();
		} while (opcion != 0);
	}
	else	/* En caso de que alguno de los ficheros no pueda abrirse. */
	{
		cout << "\n\n\t\t Error al leer fichero uno de los ficheros.";
	}
	cin.get();
}