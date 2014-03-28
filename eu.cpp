/*
Nombre fichero a entregar: eu.cpp

Enunciado: 
La Unión Europea ha decidido premiar al país que más toneladas de hortalizas exporte a lo largo del año. Se
dispone de un registro de transacciones comerciales en el que aparecen tres valores en cada apunte. El primer valor es el
indicativo del país (E: España, F: Francia y A: Alemania), el segundo valor es un indicativo de la hortaliza que se ha vendido
en una transacción (T: Tomate, P: Patata, E: Espinaca) y el tercer valor indica las toneladas que se han vendido en esa
transacción. Diseñar un programa que lea desde el teclado este registro, el cual termina siempre al leer un país con
indicativo ’@’, y que diga qué país es el que más hortalizas exporta y las toneladas que exporta.

NOTA DEL PROGRAMADOR:
	Ya que el enunciado distingue entre patatas,tomates y espinacas he considerado que se acumulen por separado, para unas futuras estadísticas que se puedan hacer en el futuro.
*/

#include<iostream>

using namespace std;
/*
* @brief función de entrada que pide un código de un país y lo devuelve por referencia
* @param char &pais (E-S) donde se almacenará el código introducido
* @return char &pais pasado por referencia
*/
void leerPais (char &pais)
	{
	
	//entradas
	cout<<"Introduzca el código del país (A=Alemania,F=Francia,E=España): ";
	cin>>pais;
	
	}
/*
* @brief función de entrada que pide las hortalizas y toneladas del país y lo devuelve por referencia
* @param char &hortalizas (E-S) donde se almacenará el código introducido de hortaliza
* @param double &toneladas (E-S) donde se almacenará las toneladas de ésa hortaliza
* @return char &hortalizas y double &toneladas pasado por referencia
*/
void leerDatos (char &hortalizas, double &toneladas)
	{
	
	//entradas
	cout<<"Introduzca la hortaliza (T=Tomate,E=Espinaca,P=Patata):";
	cin>>hortalizas;
	cout<<"Introduzca las toneladas:";
	cin>>toneladas;
	
	}
/*
* @brief función de control que verifica si el país pasado por copia es válido
* @param char pais (E) donde se pasa el código del país introducido previamente
* @return bool boolcontrol con =true si es válido o =false si es inválido
* @pos char pais sólo puede ser 'A', 'F', o 'E'.
*/
bool controlPais (char pais){
	
	//declaraciones
	bool boolcontrol=false;
	
	//operaciones
	if (pais=='A'||pais=='F'||pais=='E') {
	
	boolcontrol=true;
	
	}
	
	//salidas
	return(boolcontrol);

	}
/*
* @brief función de control que verifica si las hortalizas y toneladas introducidas pasadas por copia son válidas
* @param char hortalizas (E) donde se pasa el código de la hortaliza introducida previamente
* @param double toneladas (E) donde se pasa las toneladas de la hortaliza pasadas previamente
* @return bool boolcontrol con =true si es válido o =false si es inválido
* @pos char hortalizas sólo puede ser 'T', 'P' o 'E' y double toneladas mayor que 0
*/
bool controlHorTon (char hortalizas,double toneladas){
	
	//declaraciones
	bool boolcontrol=false;
	
	//operaciones
	if (hortalizas=='T'||hortalizas=='P'||hortalizas=='E'&&toneladas>=0.0) {
	
	boolcontrol=true;
	
	}
	
	//salidas
	return(boolcontrol);

	}	
/*
* @brief función de control que verifica si el país, las hortalizas y toneladas introducidas pasadas por copia son válidas
* @param char pais (E) donde se pasa el código del país introducida previamente
* @param char hortalizas (E) donde se pasa el código de la hortaliza introducida previamente
* @param double toneladas (E) donde se pasa las toneladas introducidas
* @return bool boolcontrol con =true si es válido o =false si es inválido
*/
bool controlDatos(char pais,char hortalizas, double toneladas) {
	
	//declaraciones
	bool boolcontrol=false;	
	
	//operaciones
	if(controlPais(pais)&&controlHorTon(hortalizas,toneladas)) {
	
	boolcontrol=true;
	
	}
	
	//salidas
	return(boolcontrol);
	
	}
/*
* @brief función de acumulación de datos sobre las hortalizas de Alemania
* @param char hortalizas (E) donde se pasa el código de la hortaliza introducida previamente
* @param double toneladas (E) donde se pasa el valor de las toneladas de ésa hortaliza introducida previamente
* @param double &alPatata (E) donde se pasa por referencia la acumulación de toneladas de patatas para Alemania
* @param double &alPinaca (E) donde se pasa por referencia la acumulación de toneladas de espinacas para Alemania 
* @param double &alTomate (E) donde se pasa por referencia la acumulación de toneladas de tomates para Alemania
* @pre char hortalizas tiene que ser una opción válida 'P', 'E' o 'T'
*/
void acumularAlemania(char hortalizas,double toneladas,double &alPatata,double &alPinaca,double &alTomate) {
	
	//operaciones
	switch (hortalizas) {
		
		case 'P':
			alPatata+=toneladas;
			break;
		case 'E':
			alPinaca+=toneladas;
			break;
		case 'T':
			alTomate+=toneladas;
			break;
		}
	}
/*
* @brief función de acumulación de datos sobre las hortalizas de Francia
* @param char hortalizas (E) donde se pasa el código de la hortaliza introducida previamente
* @param double toneladas (E) donde se pasa el valor de las toneladas de ésa hortaliza introducida previamente
* @param double &frPatata (E) donde se pasa por referencia la acumulación de toneladas de patatas para Francia
* @param double &frPinaca (E) donde se pasa por referencia la acumulación de toneladas de espinacas para Francia 
* @param double &frTomate (E) donde se pasa por referencia la acumulación de toneladas de tomates para Francia
* @pre char hortalizas tiene que ser una opción válida 'P', 'E' o 'T'
*/
void acumularFrancia(char hortalizas,double toneladas,double &frPatata,double &frPinaca,double &frTomate) {
	
	//operaciones
	switch (hortalizas) {
		
		case 'P':
			frPatata+=toneladas;
			break;
		case 'E':
			frPinaca+=toneladas;
			break;
		case 'T':
			frTomate+=toneladas;
			break;
		}
	}
/*
* @brief función de acumulación de datos sobre las hortalizas de España
* @param char hortalizas (E) donde se pasa el código de la hortaliza introducida previamente
* @param double toneladas (E) donde se pasa el valor de las toneladas de ésa hortaliza introducida previamente
* @param double &esPatata (E) donde se pasa por referencia la acumulación de toneladas de patatas para España
* @param double &esPinaca (E) donde se pasa por referencia la acumulación de toneladas de espinacas para España 
* @param double &esTomate (E) donde se pasa por referencia la acumulación de toneladas de tomates para España
* @pre char hortalizas tiene que ser una opción válida 'P', 'E' o 'T'
*/	
void acumularEspana(char hortalizas,double toneladas,double &esPatata,double &esPinaca,double &esTomate) {
	
	//operaciones
	switch (hortalizas) {
		
		case 'P':
			esPatata+=toneladas;
			break;
		case 'E':
			esPinaca+=toneladas;
			break;
		case 'T':
			esTomate+=toneladas;
			break;
		}
	}
/*
* @brief función que calcula el país ganador y lo devuelve por un char, o lanza un error
* @param double alPatata (E) donde se pasa por copia la acumulación de toneladas de patatas para Alemania
* @param double alPinaca (E) donde se pasa por copia la acumulación de toneladas de espinacas para Alemania 
* @param double alTomate (E) donde se pasa por copia la acumulación de toneladas de tomates para Alemania
* @param double frPatata (E) donde se pasa por copia la acumulación de toneladas de patatas para Francia
* @param double frPinaca (E) donde se pasa por copia la acumulación de toneladas de espinacas para Francia 
* @param double frTomate (E) donde se pasa por copia la acumulación de toneladas de tomates para Francia
* @param double esPatata (E) donde se pasa por copia la acumulación de toneladas de patatas para España
* @param double esPinaca (E) donde se pasa por copia la acumulación de toneladas de espinacas para España 
* @param double esTomate (E) donde se pasa por copia la acumulación de toneladas de tomates para España
* @param double tganador (S) donde se acumulará las toneladas totales del vencedor
* @param bool &errorganador (S)  donde se acumulará el error si lo hay.
* @return char vencedor con 'E' 'F' o 'A' si existe o un ganador y bool &errorganador pasado por referencia si hay algún error
* @pos
*/
 char paisGanador (double alPatata,double alPinaca,double alTomate,double frPatata,double frPinaca,double frTomate,double esPatata,double esPinaca,double esTomate,double &tganador,bool &errorganador) {
 	
 	//declaraciones
 	double totalEspana=0.0,totalFrancia=0.0,totalAlemania=0.0;
 	char vencedor='0';
 	
 	//operaciones
 	totalEspana=esPatata+esPinaca+esTomate;
 	totalFrancia=frPatata+frPinaca+frTomate;
 	totalAlemania=alPatata+alPinaca+alTomate;
 	
 	
 	if (totalEspana==totalFrancia&&totalEspana==totalAlemania) errorganador=false;
 		
 		else if (totalEspana==totalFrancia) errorganador=false;
 		
 			else if (totalEspana==totalAlemania) errorganador=false;
 			
 				else if (totalFrancia==totalAlemania) errorganador=false;
 	
 	if (totalEspana>totalFrancia&&totalEspana>totalAlemania) {
	 		vencedor='E';
	 		tganador=totalEspana;
 		}
 	else if (totalFrancia>totalEspana&&totalFrancia>totalAlemania) {
	 		vencedor='F';
	 		tganador=totalFrancia;
 		}
 	else {
 			vencedor='A';
	 		tganador=totalAlemania;
 		}
 	
 	//salidas
 	return(vencedor);
	}

int main ()  {

	//declaraciones
	char pais='A',hortalizas,pGanador;
	
	double toneladas=0.0, esPatata=0.0, esPinaca=0.0, esTomate=0.0, alPatata=0.0, alPinaca=0.0;
	double alTomate=0.0, frPatata=0.0, frPinaca=0.0, frTomate=0.0, tganador=0.0;
	
	bool errorganador=true;
	
	cout<<"Bienvenido al sistema."<<endl;

	//entradas
	leerPais(pais);
	
	//operaciones
	while (pais!='@') {
	
		leerDatos(hortalizas,toneladas);
	
		if (controlDatos(pais,hortalizas,toneladas)) {
	
			switch (pais) {
				case 'A':
					acumularAlemania(hortalizas,toneladas,alPatata,alPinaca,alTomate);
					break;
				case 'F':
					acumularFrancia(hortalizas,toneladas,frPatata,frPinaca,frTomate);
					break;
				case 'E':
					acumularEspana(hortalizas,toneladas,esPatata,esPinaca,esTomate);
					break;	
			}
	
	
		}

		else {
			cout<<"Datos introducidos incorrectos, por favor, vuelva a introducir válidamente los datos."<<endl<<endl;
			}	
	
		leerPais(pais);
	
	}
	
	pGanador=paisGanador(alPatata,alPinaca,alTomate,frPatata,frPinaca,frTomate,esPatata,esPinaca,esTomate,tganador,errorganador);
	
	//salidas
	if (errorganador) {
	
		switch (pGanador) {
			case 'A':
				cout <<"Ganador Alemania con "<<tganador<<" toneladas de hortalizas."<<endl;
				break;
			case 'E':
				cout <<"Ganador España con "<<tganador<<" toneladas de hortalizas."<<endl;
				break;
			case 'F':
				cout <<"Ganador Francia con "<<tganador<<" toneladas de hortalizas."<<endl;
				break;
			}
	
		}
	
	else {
		cout<<"se ha producido un empate"<<endl;
	}


}
