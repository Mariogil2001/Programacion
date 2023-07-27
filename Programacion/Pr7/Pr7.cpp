
/****** Pr7.cpp **********************************************************/ /**
 *
 * @file Pr7.cpp
 *
 * @brief Practicas de Programacion Practica 7.
 *
 * Este programa prueba la carga de informacion de un almacen.
 *
 * @version 1.1
 * @author Mario Gil Domingo
 * @authoe Luis Razvan Petrisor
 * @date 30/04/2022
 *
 */ /***************************************************************************/



#include "Pr7_Distribuidos.h"
#include "Pr7_istreams.h"

using namespace std;

int Menu();
void RecibirVacunas (Almacen&,Almacen&);
void EnviarVacunas (Almacen&,Almacen&,Almacen&);
void EnviarVacunasPuntoVacunacion(Almacen&, Distribuidos&);
void MostrarEstadoAlmacenes(Almacen, Almacen, Almacen);
void GuardarEstadoAlmacenes(Almacen, Almacen, Almacen, ofstream&);

int main() 
{
    ofstream of;
    int op;
    Distribuidos distribuido("Vacunas Administradas");
    Almacen almacen_a1("Almacen A1");
	Almacen almacen_a2("Almacen A2");
	Almacen almacen_b("Almacen B");
	do
	{	
		op = Menu();
		switch (op)
		{
			case 1:				
				RecibirVacunas (almacen_a1, almacen_a2);
				system("Pause");

				break;
			case 2:
				EnviarVacunas (almacen_a1, almacen_a2, almacen_b);
				system("Pause");

				break;	
			case 3:
				EnviarVacunasPuntoVacunacion (almacen_b, distribuido);
				system("Pause");
				break;	
			case 4:
				MostrarEstadoAlmacenes (almacen_a1, almacen_a2, almacen_b);
				system("Pause");
				break;
			case 5:
				GuardarEstadoAlmacenes (almacen_a1, almacen_a2, almacen_b, of);
				system ("Pause");
				break;
		}
		system ("cls");
	} 
	while (op != 0);
	
	
	

    return 0;
}


int Menu()
{
	int opc;
	do
	{
		cout << "Seleccion una accion: " << endl;
		cout << "1. Recibir vacunas. " << endl;
		cout << "2. Enviar vacunas a almacen B." << endl;
		cout << "3. Enviar vacunas a puntos de vacunacion." << endl;
		cout << "4. Mostrar estado almacenes." << endl;
		cout << "5. Guardar estado almacenes." << endl;
		cout << "0. Salir." << endl;
		cin >> opc;
	}while (opc > 5);
	
	return opc;
}

/* Se solicitará el nombre de un fichero con la información de los lotes recibidos. 
 * Los lotes se insertarán en el mismo orden en que se encuentran en el fichero, en los almacenes 
 * A1 o A2, en función del fabricante.
 *
 * @param [in,out] Almacen a1, Almacen a2
 * @return no devuelve nada
 *
*/

void RecibirVacunas(Almacen & a1, Almacen & a2)
{
	Almacen almacen("PreDistribucion");
	Lote lot;
	ifstream f;
	string fichero;
	// Introducimos el nombre del fichero que vamos a abrir
	cout << "Introduce nombre del fichero: " << endl;
	cin >> fichero;
	
	fichero = fichero + ".csv";
	f.open(fichero);
	if (!f)
		cout << "Error";
	else
		f >> almacen;
	// Guardamos en un almacen vacio, de donde distribuiremos segun su marca
	while (almacen.DevuelveStock() != 0)
	{
		// Con la funcion extraer guardamos el primer lote de la cola y lo eliminamos
		lot = almacen.ExtraeLote();
		// Si la Marca es 1, es decir, Moelna, se ira al almacen 1
		if (lot.DevuelveMarca() == 1)
			a1.AlmacenarLote(lot);
		// Si la Marca es 2, es decir, Piastra Azteca, se ira al almacen 2
		else if (lot.DevuelveMarca() == 2)
			a2.AlmacenarLote(lot);
	}

	return;
}

/* Enviar vacunas al almacén B. Se solicitará al usuario la cantidad de vacunas a enviar.
 * Se irá extrayendo la vacuna con fecha de caducidad más baja disponible en los almacenes de larga 
 * duración (A1 y A2) y se insertará en el almacén de distibución (almacén B). Al terminar la 
 * acción se mostrará un mensaje.
 *
 */

void EnviarVacunas(Almacen & a1, Almacen & a2, Almacen & b)
{
	// Numero de vacunas a enviar
	int nvacunas;
	int Moelna = 0, Azteca = 0;
	Lote lot;
	cout << "Cantidad de vacunas a enviar: " << endl;
	cin >> nvacunas;
	for ( int i = 0; i < nvacunas; i++)
	{
		if (a1.DevuelveFechaPrimerLote() < a2.DevuelveFechaPrimerLote())
		{
			lot = a1.ExtraeLote();
			Moelna++;
			b.AlmacenarLote(lot);		
		}

		else if (a1.DevuelveFechaPrimerLote() > a2.DevuelveFechaPrimerLote())
		{
			lot = a2.ExtraeLote();
			Azteca++;
			b.AlmacenarLote(lot);
		}
	}
	
	cout << "==================================" << endl;
	cout << "Envio con " << Moelna+Azteca << " lotes" << endl;
	cout << Moelna << " lotes de la marca Moelna" << endl;
	cout << Azteca << " lotes de la marca Piastra Azteca" << endl;
	cout << "La fecha de caducidad del primer lote extraido es el " << b.DevuelveFechaPrimerLote() << endl;
	if (nvacunas > Moelna+Azteca)
	{
		cout << "** AVISO INSENSATO: Envio incompleto. ** " << endl;
		cout << "** Se solicitaron " << nvacunas << " lotes. Stock disponible: " << Moelna+Azteca << " . **" << endl;
	}
		
	
	return;
}
/*  
 * Se pedira una cantidad de vacunas, informando sobre 
 * la cantidad maxima disponible en el almacen B, y una fecha para el envio. El numero de lotes 
 * solicitado (o el maximo disponible) se extraera del almacen B y se registraran como Vacunas 
 * Administradas indicando la fecha de administracion.
 *
 * @param [in,out] Almacen b, de donde se enviaran las vacunas
 * @param [in,out] Distribuidos d, las vacunas que han sido distribuidas
 * @return no devuelve nada
*/
void EnviarVacunasPuntoVacunacion (Almacen& b, Distribuidos & d)
{
	Lote lot;
	Fecha fec;
	int cantidadvacunas, diaenvio, mesenvio, anyoenvio;
	
	cout << "Numero de vacunas ( " << b.DevuelveStock() <<" vacunas disponibles en el almacen ): " << endl;
	cin >> cantidadvacunas;
	cout << "Dia de envio "<< endl;
	cin >> diaenvio;
	cout << "Mes de envio" << endl;
	cin >> mesenvio;
	cout << "Anyo envio" << endl;
	cin >> anyoenvio;
	lot = b.ExtraeLote();
	
	fec.AsignarValores(diaenvio,mesenvio,anyoenvio);
	d.DistribuirLote(lot,fec);
	
	return;
}

/*
 * Para cada almacen, mostrara los lotes con caducidad mas cercana 
 * y mas lejana del almacen y el numero de lotes disponibles, de acuerdo con el formato 
 * especificado en la Tarea 3.
 *
 * @param [in] Almacen a1
 * @param [in] Almacen a2
 * @param [in] Almacen b
 * @return no devuelve nada
 *
*/

void MostrarEstadoAlmacenes(Almacen a1, Almacen a2, Almacen b)
{
	cout << a1 << endl;
	cout << a2 << endl;
	cout << b << endl;
	
	return;
}

/*
 * Se solicitará un nombre de sesión, que será una cadena sin 
 * espacios, y se guardarán los lotes de los 3 almacenes y de las vacunas administradas en 4 
 * ficheros CSV. Los nombres de los ficheros seran el nombre de sesión seguido de un sufijo 
 * indicando el almacen. Por ejemplo, si el nombre de sesion es “4MAYO22”, los ficheros se 
 * llamarán “4MAYO22_A1.csv”, “4MAYO22_A2.csv”, “4MAYO22_B.csv”, “4MAYO22_VA.csv”.
 *
 * @param [in] Almacen a1
 * @param [in] Almacen a2
 * @param [in] Almacen b
 * @return no devuelve nada
 *
*/

void GuardarEstadoAlmacenes(Almacen a1, Almacen a2, Almacen b, ofstream & f)
{
	string nombre, almacen_a1, almacen_a2, almacen_b;
	cout << "Introduce el nombre del archivo a guardar: "<< endl;
	cin >> nombre;
	almacen_a1 = nombre + "_A1.csv";
	almacen_a2 = nombre + "_A2.csv";
	almacen_b = nombre + "_B.csv";
	f.open (almacen_a1.c_str());	
	if(!f)
		cout << "Error al abrir el fichero." << endl;
	else	
		f << a1.GuardaAlmacen(f);
	f.open (almacen_a2.c_str());	
	if(!f)
		cout << "Error al abrir el fichero." << endl;
	else	
		f << a2.GuardaAlmacen(f);
	f.open (almacen_b.c_str());	
	if(!f)
		cout << "Error al abrir el fichero." << endl;
	else	
		f << b.GuardaAlmacen(f);
	
	
}

