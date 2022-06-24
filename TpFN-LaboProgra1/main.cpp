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
	cTorreControl* torreControl = new cTorreControl(5, 5, 300, 300);
	cout << "Torre de control generada." << endl;

	// generacion biplanos
	cout << "Generando el primer biplano para despegue..." << endl;
	cBiplano* biplano1 = new cBiplano("05", 5, 5);
	verificarID(biplano1);
	cin >> *biplano1;
	cout << "Biplano generado." << endl;

	cout << "Generando el segundo biplano para aterrizaje..." << endl;
	cBiplano* biplano2 = new cBiplano("08", 6, 7);
	verificarID(biplano2);
	cin >> *biplano2;
	cout << "Biplano generado." << endl;

	// generacion CESSNAS
	cout << "Generando el primer CESSNA para despegue..." << endl;
	cCESSNA* CESSNA1 = new cCESSNA("02", 4, 3);
	cin >> *CESSNA1;
	cout << "CESSNA generado";

	cout << "Generando el primer CESSNA para aterrizaje..." << endl;
	cCESSNA* CESSNA2 = new cCESSNA("04", 4, 3);
	cin >> *CESSNA1;
	cout << "CESSNA generado";

	// despegue 
	torreControl->AgregarAvionesListados(biplano1);	// lo agrego a la lista de la torre y el hangar para que se pueda registrar y despachar
	torreControl->autorizarDespegue(biplano1);		// 
	torreControl->AgregarAvionesListados(CESSNA1);
	torreControl->autorizarDespegue(CESSNA1);

	// aterrizaje
	torreControl->autorizarAterrizaje(biplano2);
	torreControl->autorizarAterrizaje(CESSNA2);

	// verificar horario de aviones despegados
	torreControl->verificarHorario(biplano1);
	torreControl->verificarHorario(CESSNA1);

	// imprimir detalles
	torreControl->imprimirDetalles();

	//deletes aca abajo


	return 0;
}

void verificarID(cAvion* avion)
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
