#include "cTorreControl.h"
#include "cBiplano.h"
#include "cCESSNA.h"
void VerificarID(cModelo* avion);

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

void VerificarID(cAvion* avion)
{
	try {
			if (stoi(avion->getID()) < 6 && stoi(avion->getID()) > 0)
			{
				cAvion* AvionAux = dynamic_cast<cCESSNA*>(avion);
				if (AvionAux == NULL) throw error_id_incorrecto();
			}
			else if (stoi(avion->getID()) > 5 && stoi(avion->getID()) < 11)
			{
				cAvion* AvionAux = dynamic_cast<cBiplano*>(avion);
				if (AvionAux == NULL) throw error_id_incorrecto();
			}
		}
		catch (null_modelo& e) {
		cout << e.what();
	}
}