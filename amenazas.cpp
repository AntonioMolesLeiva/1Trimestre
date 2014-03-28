/*
Nombre fichero a entregar: amenazas.cpp

Enunciado: El ejército quiere implantar un sistema automático de detección de amenazas sobre una determinada zona del
territorio. Se considera una amenaza a cualquier objeto en movimiento detectado dentro de la zona de exclusión. Dicha
zona de exclusión, viene definida como una esfera de radio R y centrada en el punto O (x 0 ,y 0 ,0). Se tiene un sistema de
radares que detectan la presencia de objetos en movimiento. Los radares transmiten sobre cada objeto detectado, un
carácter ’T’ y un par de números reales ‘x’ e ‘y ‘cuando la amenaza es terrestre (la componente z del punto es cero) y un
carácter ’A’ y una terna de números reales ‘x’, ‘y’ y ‘z’ cuando la amenaza es aérea. El sistema se desconecta al recibir el
carácter ’D’ como carácter del objeto detectado.

Se pide desarrollar un programa que procese la información emitida por el sistema de radares y detecte si se han producido
amenazas y en el caso de producirse, indicar si la primera amenaza fue terrestre o aérea. Al principio de la ejecución se
reciben 3 número reales, el primero es el radio R y los dos siguientes las coordenadas x 0 e y 0 del punto central de la esfera
O. A partir de ese momento empieza la transmisión para la detección de objetos.

AYUDA MATEMÁTICA: Un punto cualquiera P con sus coordenadas (x 1 ,y 1 ,z 1 ), está dentro de una esfera de radio R y de
origen O (x 0 ,y 0 ,z 0 ) si y sólo sí: (x 1 −x 0 )² + (y 1 −y 0 )² + (z 1 −z 0 )² < R²

NOTA DEL PROGRAMADOR: El sistema de referencia usado es la visión desde el terreno por lo que:
	 el eje X se refiere al ancho
	 el eje Z se refiere a la profundidad
	 el eje Y se refiere a la altura
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
* @brief función de comprobación de si la circunferencia es válida
* @param double radioCircunferencia
* @return  boolcontrol con =true si es válida e =false si es inválida
*/
bool comprobarCircunferencia(double radioCircunferencia) {
	
	//declaraciones
	bool boolcontrol=false;
	
	//operaciones
	if (radioCircunferencia>0.0) {
		boolcontrol=true;
		}
	//salidas
	return(boolcontrol);
}
/*
* @brief función de entrada que lee una amenaza, la identifica y muestra los valores a introducir de dicha amenaza
* @param char &amenaza (E-S) por referencia, para pasar el código de la amenaza
* @param double &puntoX (E-S) por referencia para pasar la coordenada X introducida
* @param double &puntoY (E-S) por referencia para pasar la coordenada Y introducida
* @param double &puntoZ (E-S) por referencia para pasar la coordenada Z introducida
*/
void leerAmenaza(char &amenaza,double &puntoX,double &puntoY,double &puntoZ) {
	
	//entradas
	cout<<"Introduzca vehículo (A=Aéreo,T=Terrestre): ";
	cin>>amenaza;
	
	//operaciones
	while (amenaza!='D'&&amenaza!='A'&&amenaza!='T') //filtro para las letras específicas
	 {
		cout<<"Vehículo erróneo, por favor, introduzca vehículo (A=Aéreo,T=Terrestre): ";
		cin>>amenaza;
	}
	
	switch (amenaza) {
		case 'A':
			cout<<"Introduzca coordenada X: ";
			cin>>puntoX;
			cout<<"Introduzca coordenada Y: ";
			cin>>puntoY;
			cout<<"Introduzca coordenada Z: ";
			cin>>puntoZ;
			break;
		case 'T':
			cout<<"Introduzca coordenada X: ";
			cin>>puntoX;
			cout<<"Introduzca coordenada Z: ";
			cin>>puntoZ;
			break;
	}

}
/*
* @brief función que comprueba si existe una amenaza aerea con los parámetros pasados.
* @param double puntoX (E) para pasar la coordenada X introducida
* @param double puntoY (E) para pasar la coordenada Y introducida
* @param double puntoZ (E) por para pasar la coordenada Z introducida
* @param double xCircunferencia (E) para pasar la coordenada X de la circunferencia
* @param double zCircunferencia (E) para pasar la coordenada Z de la circunferencia
* @param double radio (E) para pasar el radio de la circunferencia para hacer las operaciones
* @param bool &alarmaAerea (E-S) para devolver si hay alarma aérea si o no =true si hay alarma y =false si no la hay.
*/
void comprobarAmenazaAerea(double puntoX,double puntoY,double puntoZ, double xCircunferencia, double zCircunferencia,bool &alarmaAerea,double radio) {
	
	//declaraciones
	double sumaPosiciones;
	
	//operaciones	
	sumaPosiciones=pow((puntoX-xCircunferencia),2)+pow((puntoY),2)+pow((puntoZ-zCircunferencia),2);
	
	if (sumaPosiciones<=pow(radio,2))	alarmaAerea=true;

}

/*
* @brief función que comprueba si existe una amenaza terrestre con los parámetros pasados.
* @param double puntoX (E) para pasar la coordenada X introducida
* @param double puntoZ (E) por para pasar la coordenada Z introducida
* @param double xCircunferencia (E) para pasar la coordenada X de la circunferencia
* @param double zCircunferencia (E) para pasar la coordenada Z de la circunferencia
* @param double radio (E) para pasar el radio de la circunferencia para hacer las operaciones
* @param bool &alarmaTerrestre (E-S) para devolver si hay alarma terrestre si o no =true si hay alarma y =false si no la hay.
*/
void comprobarAmenazaTerrestre(double puntoX,double puntoZ,double xCircunferencia,double zCircunferencia, bool &alarmaTerrestre,double radio) {

	//declaraciones
	double sumaPosiciones;
	
	//operaciones		
		sumaPosiciones=(pow((puntoX-xCircunferencia),2)+pow((puntoZ-zCircunferencia),2));
	
		if (sumaPosiciones<=pow(radio,2))	alarmaTerrestre=true;
	
	

}

int main () {

	//declaraciones
	bool errorCircunferencia=false,alarmaAerea=false,alarmaTerrestre=false;
	double radioCircunferencia=0.0,xCircunferencia=0.0,zCircunferencia=0.0,puntoX,puntoY,puntoZ;
	char amenaza='A';
	
	cout<<"Bienvenido al sistema de Detección de amenazas V1.0.\n Comprobando radar...\n Conectado OK! \n"<<endl;
	
	//entrada
	while (errorCircunferencia==false) {
		cout<<"Establezca el radio de acción del radar, por favor."<<endl;
		cout<<"Introduce el radio de acción: ";
		cin>>radioCircunferencia;
		cout<<"Introduce el coordenada de X del radar: ";
		cin>>xCircunferencia;
		cout<<"Introduce el coordenada de Z del radar: ";
		cin>>zCircunferencia;
	
		//operacion
		errorCircunferencia=comprobarCircunferencia(radioCircunferencia);
	}
	
	cout<<"\n radio de acción habilitado, iniciando transmisión..."<<endl;
	
	while(amenaza!='D') {
	
		//2º entrada	
		leerAmenaza(amenaza,puntoX,puntoY,puntoZ);
		
		//operaciones
		if (amenaza=='T') {
			comprobarAmenazaTerrestre(puntoX,puntoZ,xCircunferencia,zCircunferencia,alarmaTerrestre,radioCircunferencia);

		}
	
		else if (amenaza=='A') {
				
				//comprobación de amenaza aérea no vuela bajo tierra
				if (puntoZ<0) {
					cout<<"Coordenadas  de la amenaza aérea erróneas (no puede volar bajo el suelo).\nVuelva a introducir los datos, por favor."<<endl;
					comprobarAmenazaAerea(puntoX,puntoY,puntoZ,xCircunferencia,zCircunferencia,alarmaAerea,radioCircunferencia);
				}
				else comprobarAmenazaAerea(puntoX,puntoY,puntoZ,xCircunferencia,zCircunferencia,alarmaAerea,radioCircunferencia);
		}
	
	}
	
	//salidas
	if(alarmaTerrestre&&alarmaAerea) {
		cout<<"¡PELIGRO!\n Se encontraron amenazas aéreas y terrestres"<<endl;
	
	}
	
		else if(alarmaTerrestre) {
			cout<<"¡PELIGRO!\n Se encontraron amenazas terrestres"<<endl;
		}
	
			else if(alarmaAerea) {
				cout<<"¡PELIGRO!\n Se encontraron amenazas aéreas."<<endl;
			}
	
				else {
	
					cout<<"No se encontraron ningún tipo de amenazas\n todo OK!"<<endl;
				}
	
	

}
