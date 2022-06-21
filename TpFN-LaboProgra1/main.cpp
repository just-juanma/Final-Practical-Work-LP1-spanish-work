#include "cTorreControl.h"
#include "cBiplano.h"
#include "cCESSNA.h"

int main() {

	/* 
		Trabajo Practico Final
			- Adriel Levy
			- Bautista Farfaglia
			- Juan Manuel Gonzalez Kapnik 
	*/
	
	srand(time(WRANDOM));
	
	
	// generacion torre de control
	cout << "Generando torre de control..." << endl;
	cTorreControl* torreControl = new cTorreControl(5, 5, 50, 50);
	cout << "Torre de control generada." << endl;
	
	// generacion biplanos
	cout << "Generando el primer biplano..." << endl;
	cBiplano* biplano1 = new cBiplano("05", 5, 5);
	cin >> *biplano1;
	cout << "Biplano generado." << endl;
	
	cout << "Generando el segundo biplano..." << endl;
	cBiplano* biplano2 = new cBiplano("08", 6, 7);
	cin >> *biplano2;
	cout << "Biplano generado." << endl;

	// generacion CESSNAS
	cout << "Generando el primer CESSNA..." << endl;
	cCESSNA* CESSNA1 = new cCESSNA("02", 4, 3);
	cin >> *CESSNA1;
	
	return 0;
}

