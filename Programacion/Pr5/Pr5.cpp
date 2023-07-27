/****** Pr5.cpp **********************************************************/ /**
 *
 * @file Pr5.cpp
 *
 * @brief Practica de Programacion.
 *
 * @version 1.0
 * @author Mario Gil Domingo
 * @author Luis Razvan Petrisor                                           
 * @author L1_31_66
 * @date 11/03/2022
 *                                                                         
 */ /***************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib> 
#include <fstream>

/*  
 *  La clase "EventoProfesional" especifica la estructura
 * de informacion del evento profesional.
 *
 */
#include "Pr5_EventoProfesional.h"

/*
 * Declaracion de constantes
 */
 
const string NOM_FICH = "atletas_pro_big.csv";  ///< Nombre del fichero a leer
const int MAX_ATLETASPRO = 350; ///< Maximo numero de atletas profesionales

typedef AtletaProfesional V_AtletasProfesionales[MAX_ATLETASPRO];

struct Atletas
{
	V_AtletasProfesionales info;
	int num;
};

/*
 * Prototipo de las funciones
 */
 
Atletas LeerFichero (string);
void IniciarEvento (EventoProfesional&, Atletas);
void CargarAtletasEvento (EventoProfesional&, Atletas&, string, string, bool, float);
void GuardarEvento(EventoProfesional, ofstream&);

/*
 * Programa principal
 */
 
int main ()
{
	Atletas atletas;
	EventoProfesional evento;
    atletas = LeerFichero (NOM_FICH);
    cout << "Se han leido "<< atletas.num <<  endl;   
    IniciarEvento (evento, atletas);
	cout << evento;

	
   return 0;
}
/************************* Atletas LeerFichero  *****************************************/ /**
 *
 *  Lee cada uno de los datos asociado a cada atleta del fichero seleccionado
 *
 *  @return información de atleta rellenada
 */ /**************************************************************************/
Atletas LeerFichero (string nom_fich)
{
	Atletas atleta;
    ifstream fich_in;
    string cab;
    
    fich_in.open (nom_fich);
    
    atleta.num = 0;
    
    if (fich_in)
    {
        getline (fich_in,cab); //Leer la linea de cabecera
        
        while ( atleta.info[atleta.num].AtletaProfesional::LeerDeFichero(fich_in) )	
			atleta.num++;
            
        fich_in.close ();
    }
	else
		cout << "Error al leer el fichero " << endl;
    return atleta;
}
/************************* IniciarEvento  *****************************************/ /**
 *  @param in todos los datos relativos al evento por referencia desde el proceso
 *  Inicializa la petición de datos relativos al evento
 *
 *  @return datos del evento introducidos por teclado
 */ /**************************************************************************/
void IniciarEvento (EventoProfesional & evento, Atletas atletas)
{
	Fecha fec;
	ofstream f;
	
	string cod, nom, ciu, pais, especial, inter;
	int dia, mes, anyo;
	float marcamin;
	bool tipoevento;
	string codinfo, codcsv;

	cout << "Codigo del evento" << endl;
	getline(cin,cod);
	cout << "Nombre del evento" << endl;
	getline (cin,nom);
	cout << "Ciudad donde se realiza el evento" << endl;
	getline (cin, ciu);
	cout << "Pais donde se realiza el evento" << endl;
	getline (cin,pais);
	cout << "Introduce especialidad del evento" << endl;
	getline (cin,especial); 
	cout << "Introduce el tipo de evento" << endl;
	getline(cin,inter);
	cout << "Introduce dia del evento" << endl;
	cin >> dia;
	cout << "Introduce mes del evento" << endl;
	cin >> mes;
	cout << "Introduce anyo del evento" << endl;
	cin >> anyo;
	cout << "Marca minima para participar en el evento" << endl;
	cin >> marcamin;
	
	fec.Fecha::AsignarValores(dia,mes,anyo);
	evento.EventoProfesional::AsignarValores(cod,nom,ciu,pais,fec,especial,inter,marcamin);
	tipoevento = evento.Evento::EsInternacional();
	CargarAtletasEvento (evento, atletas, especial, pais, tipoevento, marcamin);
	
	codinfo = cod + ".info";
	f.open(codinfo.c_str());
	if(!f) cout << "Error al abrir el fichero" << cod;
	else
	{
		GuardarEvento(evento,f);
		f.close();
	}
	
	codcsv = cod + ".csv";
	f.open(codcsv.c_str());
	if(!f) cout << "Error al abrir el fichero" << cod;
	else
	{
		evento.EventoProfesional::GuardarAtletas(f);
		f.close();
	}
	return;
}
/************************* CargarAtletasEvento  *****************************************/ /**
 *  @param in datos relativos a aquellos atletas
 *  Filtra aquellos atletas que pertenezcan al evento entre el total
 *
 *  @return atletas que deben ser invitados al evento
 */ /**************************************************************************/
void CargarAtletasEvento (EventoProfesional & evento, Atletas & atleta, string especialidad, string pais, bool tipoevento, float marcamin)
{
	for (int i = 0; i < atleta.num; i++)
	{

		if(tipoevento)
		{
			if (especialidad == atleta.info[i].DevuelveEspecialidad())
			{
				if (marcamin > atleta.info[i].DevuelveMejorMarca())
					evento.EventoProfesional::InvitarAtleta(atleta.info[i]);
			}
		}
		else if (especialidad == atleta.info[i].DevuelveEspecialidad())
			{
				if (pais == atleta.info[i].DevuelvePais() && marcamin > atleta.info[i].DevuelveMejorMarca())
					evento.EventoProfesional::InvitarAtleta(atleta.info[i]);
			}
	}
	return;
}

void GuardarEvento (EventoProfesional e, ofstream& f)
{
	f << e;
	
}

