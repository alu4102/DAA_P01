***
>**Autora:**         *María D. Batista Galván*  
>**Fecha:**          *Lunes 17 de Febrero de 2014*  
>**Asignatura:**     *DISEÑO Y ANÁLISIS DE ALGORITMOS*  
>**Práctica:**       **Práctica 1: El simulador de la máquina RAM - I y II** 
***

##Primera Parte

>En esta primera práctica se trata de escribir un programa C++ que sea capaz de leer un programa 
RAM y almacenarlo en una estructura que permita su posterior simulación. El programa debe admitir 
el desensamblado de las instrucciones RAM así como de todo el programa RAM. Utiliza, al menos, 
los archivos de prueba que se proporcionan en esta sección.

##Segunda Parte

>En esta segunda práctica se trata de finalizar el desarrollo del simulador de programas RAM.  El programa debe estar escrito en C++ utilizando Orientación a Objetos.

###Especificaciones:###

1. Los **programas a cargar** en la máquina RAM y los contenidos de las **cintas de entrada** y de **salida** deben estar en **tres ficheros** diferentes, y sus nombres deben poder ser introducidos mediante teclado. 
2. Deben **leerse la instrucciones** desde el programa y **chequear** que sean **legales**. 
3. La instrucciones deben ser implementadas con los **direccionamientos permitidos**. 
4. Deben **chequearse los desbordamientos** en sumas, restas y multiplicaciones tanto positivos como negativos. Chequéese que no se intente realizar una **división por cero**. Ante alguno de los **errores** anteriores se debe **imprimir por pantalla** un mensaje y la **posición de memoria de la instrucción** que lo produjo y **dejar la máquina RAM en estado halt**.
5. Cuando se entra **en estado halt** se debe **descargar el contenido de la cinta de salida** en el fichero correspondiente.
6. Debe **presentarse un menú** de ejecución similar al siguiente:

>>\>h  
r: ver los registros  
t: traza  
g: go  
s: desensamblador  
i: ver cinta entrada  
o: ver cinta salida  
h: ayuda  
x: salir  
\>