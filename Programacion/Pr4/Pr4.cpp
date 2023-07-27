/****** Pr4.cpp **********************************************************/ /**
 *
 * @file Pr4.cpp
 *
 * @brief Pr?cticas de Programacion.
 *
 * VERSI?N INICIAL DE:
 * Programa de prueba para probar la correcta implementaci?n de la clase Atleta.
 *
 * @version 1.0
 * @author Miguel A. Gamon
 * @date 01/03/2022
 *
 * @version 2.4
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
 *  La clase "Evento" especifica la estructura de informacion del evento
 */
#include "Evento.h"


const string NOM_FICH = "atletas_big.csv";  ///< Nombre del fichero a leer

const int MAX_ATLETAS = 350;		///< Maximo n de atletas que es posible guardar en la estructura
const int MAX_ESPECIALIDADES = 20;	///< Maximo n de especialidades que es posible guardar en la estructura
const int MAX_PAISES = 50;			///< Maximo n de paises que es posible guardar en la estructura
typedef Atleta V_Atletas[MAX_ATLETAS];
typedef string TVecEspecialidades[MAX_ESPECIALIDADES];
typedef string TVecPaises[MAX_PAISES];


struct Atletas
{
	V_Atletas info;
	int num;
};
	
struct Especialidades
{
    TVecEspecialidades info;
    unsigned int num;
};

struct Paises
{
    TVecPaises info;
    unsigned int num;
};

Atletas LeerFichero (string);
void IniciarEvento(Evento&,Atletas);
Atletas CargarAtletasEvento( Atletas, string , string , bool );
void MostrarAtletas(Atletas);
void GuardarEvento(Evento, ofstream& );
void GuardarListadoAtletas(Evento, ofstream& );
/*
 * Programa principal
 */
 
int main ()
{
	Atletas atletas;
	Evento evento;
    atletas = LeerFichero (NOM_FICH);
    cout << "Se han leido "<< atletas.num <<  endl;   
    system("pause");
   IniciarEvento(evento, atletas);
   cout << evento;

   return 0;
}

Atletas LeerFichero (string nom_fich)
{
	Atletas atleta;
    ifstream fich_in;
    string cab;
    
    fich_in.open (nom_fich);
    
    atleta.num = 0;
    
    if (fich_in)
    {
        getline(fich_in,cab); //Leer la linea de cabecera
        
        while ( atleta.info[atleta.num].LeerDeFichero(fich_in) )	
			atleta.num++;
            
        fich_in.close ();
    }
	else
		cout << "Error al leer el fichero " << endl;
    return atleta;
}

void IniciarEvento(Evento & eve, Atletas atletas)
{
	ofstream f;
	Atletas grupoAtletas;
	Fecha fe;
	Especialidades especialidades;
	Paises paises;
	string cod,nom,ciu,pais,espe,inter;
	int dia,mes,anyo;
	bool tipoevento;
	
	cout << "Codigo del evento" << endl;
	getline(cin,cod);
	cout << "Nombre del evento" << endl;
	getline (cin,nom);
	cout << "Ciudad donde se realiza el evento" << endl;
	getline (cin, ciu);
	cout << "Pais donde se realiza el evento" << endl;
	getline (cin,pais);
	cout << "Introduce especialidad del evento" << endl;
	getline (cin,espe); 
	cout << "Introduce el tipo de evento" << endl;
	getline(cin,inter);
	cout << "Introduce dia del evento" << endl;
	cin >> dia;
	cout << "Introduce mes del evento" << endl;
	cin >> mes;
	cout << "Introduce anyo del evento" << endl;
	cin >> anyo;

	
	fe.AsignarValores(dia,mes,anyo);
	
	eve.AsignarValores(cod,nom,ciu,pais,fe,espe,inter);

	tipoevento = eve.EsInternacional();
	grupoAtletas = CargarAtletasEvento (atletas,espe, pais, tipoevento);
//	MostrarAtletas (grupoAtletas);


	cod = cod + ".evento";
	f.open(cod.c_str());
	if(!f) cout << "Error al abrir el fichero" << cod;
	else
	{
		GuardarEvento(eve,f);
		for (int i = 0; i < grupoAtletas.num; i++)
		{
	//		f << grupoAtleta.info[i].DevuelveCodigo();
		 	f << grupoAtletas.info[i].DevuelveNombre();
		 	f <<  " (" << grupoAtletas.info[i].DevuelvePais() <<") " << endl;
	//	 	f << grupoAtleta.info[i].DevuelveEspecialidad();
		}
		f.close();
	}
	
	for (int k = 0; k < grupoAtletas.num;k++)
	{
		eve.InvitarAtleta(grupoAtletas.info[k]);
	}
	
	GuardarListadoAtletas(eve, f);
	
	
	return;
}


Atletas CargarAtletasEvento( Atletas atleta,string especialidad, string pais, bool tipoevento)
 {
 	Atletas grupoAtletas;
 	grupoAtletas.num = 0;

	for (int i = 0; i < atleta.num; i++)
	{
		if(tipoevento)
		{
			if (especialidad == atleta.info[i].DevuelveEspecialidad())
			{
					grupoAtletas.info[grupoAtletas.num] = atleta.info[i];
					grupoAtletas.num++;
			}
		}
		else if (especialidad == atleta.info[i].DevuelveEspecialidad() && pais == atleta.info[i].DevuelvePais())
		{
			grupoAtletas.info[grupoAtletas.num] = atleta.info[i];
			grupoAtletas.num++;
		}
	} 
 
 	return grupoAtletas;
 }

void MostrarAtletas (Atletas atletas)
{
    // Mostrar por pantalla los datos leidos
    for ( int i = 0; i < atletas.num; i++)
    	atletas.info[i].Mostrar();
        //Mostrar por pantalla los datos del objeto atletas.info[i] que es de la clase Atleta
}

void GuardarEvento(Evento e, ofstream &f)
{
	f << e;
}

void GuardarListadoAtletas(Evento evento, ofstream &f)
{
	string cod = evento.DevuelveCodigo() + ".csv";
	f.open(cod.c_str());
	if(!f) cout << "Error al abrir el fichero" << cod;
	else
	{
		f << "id;apellidos_nombre;pais;especialidad" << endl;
		evento.GuardarAtletas(f);
		f.close();
	}
	
	
}





