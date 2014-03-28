/*
Nombre fichero a entregar: aureo.cpp

Escribir un programa que calcule el número áureo con un error de aproximación menor o igual al determinado por el
usuario, y que muestre como salida hasta que “n” es necesario calcular la progresión y dicho valor aproximado mediante la
progresión. Ayuda: error = valor_usando_sqrt - valor_aproximado_mediante_progresión.
*/
#include<iostream>
#include<cmath>

using namespace std;

/*
* @brief función que calcula el fibonacci de un número double de manera recursiva
* @param double numero, como numero para hacer fibonacci
* @return int resultado, devuelve la solución
*/
double fibonacciRecursivo (double numero) {

	//declaraciones
	double resultado;
	
	//operaciones
		if (numero<=0) resultado=0;
		else if (numero==1) resultado=1;
		else {
			resultado=fibonacciRecursivo(numero-1)+fibonacciRecursivo(numero-2);
			}
	
	//salidas
	return(resultado);
}

/*
* @brief calcula la aproximación al número aúreo
* @param double AUREO, (E) como constante del número aúreo.
* @param double errorPermitido, (E) va a ser el error máximo que va a ter nuestra aproximación
* @param int n, (E-S) va a contener el número con el que hemos probado para obtener la aproximación
* @param double valorFinal, (E-S) contendrá la aproximación cuando sea correcta
*/
void aproximacionAureo(double AUREO,double errorPermitido, int &n, double &valorFinal) {
	
	//declaraciones
	double valorOperacion,
		  errorAprox=errorPermitido+1; // para que entre al bucle por primera vez
	
	//operaciones
	while(errorAprox>errorPermitido) {
	
	n++;
	valorOperacion=fibonacciRecursivo(n+1)/fibonacciRecursivo(n);

	if (AUREO-valorOperacion<0) errorAprox=valorOperacion-AUREO;
	
	else errorAprox=AUREO-valorOperacion;

	}
	
	//salida
	valorFinal=valorOperacion;
}

int main () {
	
	//declaraciones
	const double AUREO=(1+sqrt(5))/2;
	double errorPermitido=0.0,valorFinal=0,valorOperacion=0.0;
	int n=0;
	
	//entradas
	cout<<"Bienvenido al programa que calcula el valor del número aúreo.\n"<<endl;
	cout<<"Introduzca el valor del error expresado en decimal: ";
	cin>>errorPermitido;
	
	//operaciones
	aproximacionAureo(AUREO,errorPermitido,n,valorFinal);
	
	//salidas
	cout<<"el número de veces para calcular el número aúreo con precisión "<<errorPermitido<<" ha sido "<<n<<" y el número aproximado es: "<<valorFinal<<endl;
	


}
