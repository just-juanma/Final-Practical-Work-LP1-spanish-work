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
	
	
	return 0;
}

