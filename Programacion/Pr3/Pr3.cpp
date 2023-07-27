/****** Pr3.cpp **********************************************************/ /**
 *
 * @file Pr3.cpp
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
 *  La clase "Atleta" especifica la estructura de informacion de un atleta
 */
#include "Atleta.h"

const int MAX_ATLETAS = 500;		///< Maximo n? de atletas que es posible guardar en la estructura
const int MAX_ESPECIALIDADES = 20;	///< Maximo n? de especialidades que es posible guardar en la estructura
const int MAX_PAISES = 50;			///< Maximo n? de pa?ses que es posible guardar en la estructura

const string NOM_FICH = "atletas_big.csv";  ///< Nombre del fichero a leer

/**
 * Usaremos la clase Atleta para guardar la informacion relativa a cada uno de los atletas
 * de la competeci?n.
 */
   
/**
 * Tipo vector de atleta: Estructura auxiliar para construir el registro Atletas
 */ 
typedef Atleta TVecAtletas[MAX_ATLETAS];

/**
 * Registro Atletas donde guardar toda la informaci?n de los atletas participantes
 * (la informaci?n de cada atleta, as? como el n?mero de atletas)
 */
struct Atletas
{
    TVecAtletas info;
    unsigned int num;
};

/**
 * Tipo vector de especialidades: Estructura auxiliar para construir el registro Especialidades
 */ 
typedef string TVecEspecialidades[MAX_ESPECIALIDADES];

/**
 * Registro Especialidades donde guardar la informaci?n de las especialidades de la competici?n
 * (la informaci?n de cada especialidad, as? como el n?mero de especialidades)
 */
struct Especialidades
{
    TVecEspecialidades info;
    unsigned int num;
};

/**
 * Tipo vector de especialidades: Estructura auxiliar para construir el registro Especialidades
 */ 
typedef string TVecPaises[MAX_PAISES];

/**
 * Registro Paises donde guardar la informaci?n de los pa?ses de origen de los atletas
 * (la informaci?n de cada pa?s, as? como el n?mero de pa?ses)
 */
struct Paises
{
    TVecPaises info;
    unsigned int num;
};

/*
 * Prototipos de las funciones empleadas,
 * implementadas despues de main()
 */

int Menu ();

/*
TODAS ESTAS FUNCIONES DEBEN SER IMPLEMENTADAS Y
DOCUMENTADAS POR LOS ESTUDIANTES EN LA DISTINTAS TAREAS
BORRAME CUANDO FINALICES EL TRABAJO
*/

/* TAREA 1 */
Atletas LeerFichero (string);
void MostrarAtletas (Atletas atletas);
/* TAREA 2 */
Especialidades ObtenerEspecialidades(Atletas);
Paises ObtenerPaises(Atletas);
void MostrarEspecialidades(Especialidades);
void MostrarPaises(Paises);
///* TAREA 3 */
Atletas ObtenerAtletasEspecialidad(Atletas, string);
/* TAREA 4 */
Atletas ObtenerAtletasEspecialidadPais(Atletas, string , string );

/*
 * Programa principal
 */
int main ()
{
	Atletas atletas;	// Conjunto de atletas
	Atletas grupoAtletas;
	Especialidades especialidades;
	Paises paises;
	unsigned int opcion, especialidad, pais;	
	// Leemos la informacion del conjunto de atletas
    atletas = LeerFichero (NOM_FICH);
       	system("MODE CON COLS=76 LINES=30");
    system ("color E0");
    // TAREA 1: Mostrar los atletas del fichero
    // MostrarAtletas (atletas); 
    cout << "Se han leido " << atletas.num << " atletas del fichero '" << NOM_FICH << "'" << endl;
    cout << endl;   
    system("pause");

    // TAREA 2: Obtener las especialidades y los paises de los atletas
    especialidades = ObtenerEspecialidades (atletas);
	paises = ObtenerPaises (atletas);
        
    do
    {
    	system ("cls");    	
    	
    	opcion = Menu();
    	
    	switch (opcion)
    	{    	
    		case 1:
    			// TAREA 2: Mostrar las especialidades de la competicion
    			MostrarEspecialidades (especialidades);
    			break;
    			
    		case 2:
    			// TAREA 2: Mostrar los paises de los atletas
	   			MostrarPaises (paises);
    			break;
    			
    		case 3:
    			// TAREA 3: Filtrar atletas por especialidad
    			MostrarEspecialidades (especialidades);
    			do
    			{
		    		cout << "Introduce la especialidad: ";
		    		cin >> especialidad;
				}			
				while (especialidad < 1 || especialidad > especialidades.num);
				
				grupoAtletas = ObtenerAtletasEspecialidad (atletas, especialidades.info[especialidad-1]);
				MostrarAtletas (grupoAtletas);
				
    			break;
    			
    		case 4:
    			// TAREA 4: Filtrar atletas por especialidad y pais
    			MostrarEspecialidades (especialidades);
    			do
    			{
		    		cout << "Introduce la especialidad: ";
		    		cin >> especialidad;
				}			
				while (especialidad < 1 || especialidad > especialidades.num);
				
    			MostrarPaises (paises);
    			do
    			{
		    		cout << "Introduce el pais: ";
		    		cin >> pais;
				}			
				while (pais < 1 || pais > paises.num);
    			    			
				grupoAtletas = ObtenerAtletasEspecialidadPais (atletas, especialidades.info[especialidad-1], paises.info[pais-1]);
				MostrarAtletas (grupoAtletas);
    			break;
		}
		
		system ("pause");
	}
	while (opcion != 0);
	
	return 0;
} 

/************************* Menu() *****************************************/ /**
 *
 *  Muestra el menu con las opciones disponibles
 *
 *  @return opcion seleccionada (0-4)
 */ /**************************************************************************/
int Menu()
{
	int opcion;
		
    cout << "1.- Mostrar especialidades." << endl;
    cout << "2.- Mostrar paises." << endl;
    cout << "3.- Mostrar atletas por especialidad." << endl;
    cout << "4.- Mostrar atletas por especialidad y pais." << endl;
    cout << "0.- Salir." << endl;
    cout << endl;
    
    do
    {
    	cout << "Introduce la opcion a elegir: ";    
    	cin >> opcion;
	}
	while (opcion < 0 || opcion > 4);
	
	return opcion;
}

Atletas LeerFichero (string nom_fich)
{
    ifstream fich_in;
    Atletas atletas;
    string cab;
    
    fich_in.open (nom_fich);
    
    atletas.num = 0;
    
    if (fich_in)
    {
        getline(fich_in,cab); //Leer la linea de cabecera
        
        while ( atletas.info[atletas.num].LeerDeFichero(fich_in) )	
			atletas.num++;
            
        fich_in.close ();
    }

    return atletas;
}

void MostrarAtletas (Atletas atletas)
{
    // Mostrar por pantalla los datos leidos
    for (unsigned int i = 0; i < atletas.num; i++)
    	atletas.info[i].Mostrar();
        //Mostrar por pantalla los datos del objeto atletas.info[i] que es de la clase Atleta
     
}
 Especialidades ObtenerEspecialidades(Atletas atletas)
 {
 	Especialidades especialidades;
 	unsigned int j;
	especialidades.num = 0;

	for (unsigned int i = 0; i < atletas.num - 1; i++)
	{
		j = 0;
		while (atletas.info[i].DevuelveEspecialidad() != especialidades.info[j] && j < especialidades.num)
			j++;
		if (j == especialidades.num )
		{
			especialidades.info[especialidades.num] = atletas.info[i].DevuelveEspecialidad();				
			especialidades.num++;				

		}	
	}
	 	
	return especialidades;	
 }
 
void MostrarEspecialidades (Especialidades especialidades)
{
    // Mostrar por pantalla los datos leidos
    for (unsigned int i = 0; i < especialidades.num; i++)
    	cout << i+1 << ". Especialidad: " << especialidades.info[i] << endl;
        //Mostrar por pantalla los datos del objeto atletas.info[i] que es de la clase Atleta
     
}

 Paises ObtenerPaises(Atletas atletas)
 {
 	Paises paises;
 	unsigned int j;
	paises.num = 0;

	for (unsigned int i = 0; i < atletas.num - 1; i++)
	{
		j = 0;
		while (atletas.info[i].DevuelvePais() != paises.info[j] && j < paises.num)
			j++;
		if (j == paises.num )
		{
			paises.info[paises.num] = atletas.info[i].DevuelvePais();				
			paises.num++;				

		}	
	}
	 	
	return paises;	
 }
 
 void MostrarPaises (Paises paises)
 {
 	for (unsigned int i = 0; i < paises.num; i++)
 		cout << i+1 << ". Pais: " << paises.info[i] << endl;
 }
 
 Atletas ObtenerAtletasEspecialidad (Atletas atletas, string especialidad)
 {
 	Atletas grupoAtletas;
 	Especialidades especialidades;
 	unsigned int j = 0;
	grupoAtletas.num = 0;

	for (unsigned int i = 0; i < atletas.num - 1; i++)
	{
		j = 0;
		while ( atletas.info[i].DevuelveEspecialidad() != especialidad && j < atletas.num )
			j++;
		if (j < atletas.num - 1)
		{
			grupoAtletas.info[grupoAtletas.num] = atletas.info[i];
			grupoAtletas.num++;
		}
		j++;
	}
		 	
	return grupoAtletas;	
 
 }
 
 Atletas ObtenerAtletasEspecialidadPais(Atletas atletas, string especialidad, string pais)
 {
 	Atletas grupoAtletas;
 	Especialidades especialidades;
 	Paises paises;
 	unsigned int j = 0;
 	grupoAtletas.num = 0;
 	
 	for (unsigned int i = 0; i < atletas.num - 1; i++)
	 {
	 	j = 0;
	 	while (especialidad != atletas.info[i].DevuelveEspecialidad() && j < atletas.num)
	 		j++;
	 	if (pais == atletas.info[i].DevuelvePais() && especialidad == atletas.info[i].DevuelveEspecialidad())
	 		 {
		 		grupoAtletas.info[grupoAtletas.num] = atletas.info[i];
		 		grupoAtletas.num++;	
			 }
		 j++;
	 }	
 	return grupoAtletas;
 }
 
 
 
 
