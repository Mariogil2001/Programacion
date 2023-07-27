/****** Pr1_v0_9.cpp ****************************************************/ /**
 *
 * @file Pr1_v0_9.cpp
 *
 * @brief Prácticas de Programacion.
 *
 * Lee la informacion de las personas guardada en un fichero, las pone en un 
 * registro y realiza diferentes busquedas en el mismo para realizar medidas
 * empiricas de esas busquedas.
 *
 * @version 0.9
 * @author Mario Gil Domingo, Luis Razvan Petrisor
 * @date 16-02-2022
 */ /**************************************************************************/
 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Maximo de personas que es posible guardar en la estructura
 */
const int MAX = 5100;

///< Numero de algoritmos con los que trabajar
const int N_ALGORITMOS = 4;

///< Codificación de los algoritmos de busqueda
const int SECUENCIAL           = 0;
const int SECUENCIAL_PARADA    = 1;
const int SECUENCIAL_CENTINELA = 2;
const int BUSQUEDA_BINARIA     = 3;

const string NOM_FICH = "vacunaciones_big.csv";  ///< Nombre del fichero a leer

/**
 * Registro Persona donde guardamos la informacion relativa a cada uno de las
 * personas vacunadas.
 */
struct TPersona
{
    string identificador;   ///< Identificador de la persona
    string nombre;          ///< Nombre de la persona
    string vacuna;          ///< Nombre de la vacuna administrada
    string f_1; ///< Fecha en la que le pusieron la primera dosis
    string f_2; ///< Fecha en la que le pusieron la segunda dosis    
    string f_3; ///< Fecha en la que le pusieron la terecera dosis    
};
   
/**
 * Tipo vector de personas: Estructura auxiliar para construir el registro Personas
 */ 
typedef TPersona TVecPersonas[MAX];

/**
 * Registro Personas donde guardar toda la informacion de las personas vacunadas
 * (la informacion de cada persona, asi como el numero de personas)
 */
struct Personas
{
    TVecPersonas info;
    unsigned int num;
};

///< Tipo para el vector de contadores
typedef int TContadores[N_ALGORITMOS];

/*
 * Prototipos de las funciones empleadas,
 * implementadas despues de main()
 */
void MostrarPersona(TPersona);
Personas LeerFichero (string);
bool LeerPersonaFichero (ifstream &, TPersona &);
int BusquedaSecuencial (TVecPersonas, int, string, int &);
int BusquedaSecuencialParada (TVecPersonas, int, string, int &);
int BusquedaConCentinela (TVecPersonas, int, string, int &);
int BusquedaBinaria (TVecPersonas, string, int, int &);
int RealizarBusquedas (Personas, string, TContadores);

/*
 * Programa principal
 */
int main ()
{
	system ("MODE CON COLS=60 LINES=26");
    system ("color B0");
	ifstream f;
	unsigned int j;
	int ok, Vacunados = 0, Paleoliticos = 0, dosis1 = 0, dosis2 = 0, dosis3 = 0;
	string identificaciones[MAX];
    Personas personas;     // Registro en el que vamos a buscar
    TContadores contar;   // Contadores de pasos, 1 x algoritmo
    
    // Leer la informacion de las personas vacunadas
    personas = LeerFichero (NOM_FICH);
    
    // Verificar en pantalla los datos leidos
    /*for (unsigned int i = 0; i < personas.num; i++)
        MostrarPersona(personas.info[i]); */ 
    
    
    
	f.open ("verificar.dat");
	if (!f) cout << "Error al abrir el fichero " << endl;
	else
	{
		while (!f.eof())
		{
			f >> identificaciones[j];
			ok = RealizarBusquedas (personas, identificaciones[j], contar);
			if(ok!=-1)
			{
				Vacunados++;
				if(personas.info[ok].f_3!="")
					dosis3++;		
				else if(personas.info[ok].f_2!="")
					dosis2++;
				else // if(personas.info[ok].f_1!="")
					dosis1++;
			}
			else
				Paleoliticos++;
			j++;
		}
		
	f.close ();
	}

	
	
	cout << "--------------------------"                                    << endl; 	
	cout << " RESULTADOS Talla = "                    << personas.num       << endl;
	cout << "--------------------------"                                    << endl; 	
	cout << " Pacientes buscados = "                  << j                  << endl;
	cout << "	- Vacunados: "                        << Vacunados          << endl;
	cout << "	- Solo 1 dosis: "                     << dosis1             << endl;
	cout << "	- Solo 2 dosis: "                     << dosis2             << endl;
	cout << "	- 3 dosis: "                          << dosis3             << endl;
	cout << "	- No Vacunados: "                     << Paleoliticos       << endl;
	cout << " Media de pasos de los 4 algoritmos: "                         << endl; 
	cout << "	- Busqueda Secuencial: "              << contar[0]/float(j) << endl;
	cout << "	- Busqueda Secuencial con Parada: "   << contar[1]/float(j) << endl;
	cout << "	- Busqueda Secuencia con Centinela: " << contar[2]/float(j) << endl;
	cout << "	- Busqueda Binaria: "                 << contar[3]/float(j) << endl;
    cout << "--------------------------"                                    << endl; 	
	    
    return 0;
}

/**********************************************************************/ /**
 *
 *  Muestra por pantalla la información de 1 Persona
 *
 *  @param [in]  p  Persona cuyos datos se van a mostrar
 *
 */ /**********************************************************************/
void MostrarPersona(TPersona p)
{
    string sep = "    ";
    cout << "*** Datos de la persona:"                                       << endl;
    cout << sep << "- Identificador: "                << p.identificador     << endl;
    cout << sep << "- Mombre: "                       << p.nombre            << endl;
    cout << sep << "- Vacuna: "                       << p.vacuna            << endl;
    cout << sep << "- Fecha primera dosis: "          << p.f_1               << endl;
    cout << sep << "- Fecha segunda dosis: "          << p.f_2               << endl;
    cout << sep << "- Fecha tercera dosis: "          << p.f_3               << endl;
    cout                                                                     << endl;
 }

/**********************************************************************/ /**
 *
 *  Lee la informacion de los personas contenidos en el fichero del que se
 *  nos pasa el nombre y la guarda en el registro Personas de forma
 *  adecuada.
 *  Si el fichero no se puede abrir, el numero de personas leido sera cero.
 *
 *  @param [in]  nom_fich  Nombre del fichero donde esta la informacion de
 *                         las personas.
 *
 *  @return  El registro Personas debidamente rellenado.
 *
 */ /**********************************************************************/
Personas LeerFichero (string nom_fich)
{
    ifstream fich_in;
    Personas personas;
    string cab;
    
    fich_in.open (nom_fich);
    
    personas.num = 0;
    
    if (fich_in)
    {
        getline(fich_in,cab); //Leer la linea de cabecera
        
        while ( LeerPersonaFichero (fich_in, personas.info[personas.num]) )
            personas.num++;
            
        fich_in.close ();
    }
    else
        cerr << "Error al abrir archivo " << nom_fich << endl;

    return personas;
}

/**********************************************************************/ /**
 *
 *  Lee, si es posible, UNA persona del fichero del que se pasa el descriptor
 *  y devuelve el registro Persona debidamente rellenado y si ha podido o no
 *  rellenarlo adecuadamente.
 *
 *  @pre  El descriptor del fichero debe referirse a un fichero previamente
 *        abierto de forma correcta.
 *
 *  @param [in,out]  fich_in  Descriptor del fichero del que vamos a leer
 *                            la informacion.
 *
 *  @param [out]     persona  Registro Persona debidamente rellenado con la
 *                            informacion leida del fichero.
 *
 *  @retval  true   La informacion ha podido ser leida de forma correcta.
 *
 *  @retval  false  La informacion no ha podido ser leida de forma correcta
 *                  (probablemente porque se ha terminado el fichero).
 *
 */ /**********************************************************************/
bool LeerPersonaFichero (ifstream & fich_in, TPersona & persona)
{
    bool ok;
    string salto;

    if ( getline (fich_in, persona.identificador,';') )
    {
        getline (fich_in, persona.nombre,';');
        getline (fich_in, persona.vacuna,';');    
        getline (fich_in, persona.f_1,';');    
        getline (fich_in, persona.f_2,';');    
        getline (fich_in, persona.f_3,';');    
        getline (fich_in,salto); //Saltar a la siguiente linea
        ok = true;
    }
    else
        ok = false;
        
    return ok;
}

/**********************************************************************/ /**
 *
 *  Implementa el metodo de busqueda secuencial (sin parada):
 *
 *  @pre  n debe ser un valor entero positivo
 *
 *  @param [in]  v   vector que contiene los datos
 *  @param [in]  n   numero de elementos 'validos' en el vector
 *  @param [in]  id  clave del elemento a buscar
 
 *  @param [out]  pasos  Numero total de pasos realizados para completar
 *                       la busqueda. Se pone a cero (0) al iniciar la funcion
 *
 *  @return enc   Da el número de la posición del valor buscado
 *
 */ /**********************************************************************/
 int BusquedaSecuencial (TVecPersonas v, int n, string id, int & pasos) 
{
    int i, posicion;
    int enc = 0;
    
    i = 0;
    
    while (i < n)
    {
        if (v[i].identificador == id)
        {
            enc = posicion;           
            pasos++;
        }
        posicion++;
        i = i + 1;
		pasos+=3;
    }

    
    return enc;
}


/**********************************************************************/ /**
 *
 *  Implementa el metodo de busqueda secuencial con parada:
 *
 *  @pre  n debe ser un valor entero positivo
 *
 *  @param [in]  v   vector que contiene los datos
 *  @param [in]  n   numero de elementos 'validos' en el vector
 *  @param [in]  id  clave del elemento a buscar
 
 *  @param [out]  pasos  Numero total de pasos realizados para completar
 *                       la busqueda. Se pone a cero (0) al iniciar la funcion
 *
 * @return enc   Da el número de la posición del valor buscado
 *
 */ /**********************************************************************/
int BusquedaSecuencialParada (TVecPersonas v, int n, string id, int & pasos)
{
    int i;
    int enc;
    
    i = 0;
    
    while ( (i < n) && (v[i].identificador != id) )
	{
        i = i + 1;
		pasos+=3;
	}
        
     /* Si i ha llegado a n es que el elemento 'id' no se ha encontrado
      * si no es que nos hemos detenido antes y el 'id' si que esta en v
      */
    if (i == n)
        enc = -1;
    else
        enc = i;
    return enc;
}

/**********************************************************************/ /**
 *
 *  Implementa el metodo de busqueda secuencial con centinela:
 *
 *  @pre  n debe ser un valor entero positivo
 *
 *  @param [in]  v   vector que contiene los datos
 *  @param [in]  n   numero de elementos 'validos' en el vector
 *  @param [in]  id  clave del elemento a buscar
 
 *  @param [out]  pasos  Numero total de pasos realizados para completar
 *                       la busqueda. Se pone a cero (0) al iniciar la funcion
 *
 * @return enc   Da el número de la posición del valor buscado
 *
 */ /**********************************************************************/
int BusquedaConCentinela (TVecPersonas v, int n, string id, int & pasos)
{
    int i, busqueda = 0;
    int enc;
    
    //fijar centinela antes de buscar
    v[n].identificador = id;

    i = 0;
    while (v[i].identificador != id)
	{
        i = i + 1;
		pasos+=2;
		busqueda++;
	}
    
     /* Si i ha llegado a n es que hemos localizado al centinela
      * y el 'id' no está en v
      * sino es que nos hemos detenido antes de localizar al centinela
      * y el 'id' si que esta en v
      */
    if (i == n)
        enc = -1;
    else
        enc = busqueda;

    return enc;
}

/**********************************************************************/ /**
 *
 *  Implementa el metodo de busqueda binaria:
 *
 *  @pre  n debe ser un valor entero positivo
 *
 *  @param [in]  v   vector que contiene los datos
 *  @param [in]  n   numero de elementos 'validos' en el vector
 *  @param [in]  id  clave del elemento a buscar
 
 *  @param [out]  pasos  Numero total de pasos realizados para completar
 *                       la busqueda. Se pone a cero (0) al iniciar la funcion
 *
 * @return enc   Da el número de la posición del valor buscado
 *
 */ /**********************************************************************/
int BusquedaBinaria (TVecPersonas v, int n, string id, int & pasos)
{
    int izq, der, cen;
    int busqueda;
    /*
     * izq y der delimitan la zona del vector donde se busca
     * cen es la posición del elemento central de esta zona
     */
    int enc = -1;
    
    izq = 0;
    der = n - 1;
    cen = (izq + der) / 2;
    
    
    /*
     * Mientras no se encuentre el elemento
     * y existan más de un elemento en el subvector continúa
     * la búsqueda
    */
    while ( (izq <= der) && (v[cen].identificador != id) )
    {
		pasos+=2;
        if (id < v[cen].identificador)
            der = cen - 1;
        else
            izq = cen + 1;
            
        cen = (izq + der) / 2;
		pasos+=3;
		busqueda++;
    }
 
    /*
     * Se puede salir del bucle por haber encontrado el
     * elemento o por haber llegado a un subvector sin elementos
     */
    if (izq > der)
        enc = -1;
    else
        enc = busqueda;
 
    return enc;
}

/**********************************************************************/ /**
 *
 *  Lanza secuencialmente los 4 algoritmos de búsqueda sobre
 *  el mismo identificador de persona.
 *
 *  @pre  El catálogo de personas debe estar correctamente rellenado.
 *
 *  @param [in]  personas  Registro Personas con la informacion de los
 *                       personas y el numero de personas validos para la
 *                       realizacion de la busqueda.
 *
 *  @param [in]  iden    Identificador de la persona a buscar.
 *
 *  @param [out]  contadores  Vector en donde guardaremos el numero 
 *                            de pasos realizados dependiendo del metodo
 *                            de busqueda seleccionado.
 *
 *  @retval  True   Si hemos concluido la busqueda con exito
 *  @retval  False  Si no hemos conseguido encontrar la persona buscada
 *
 */ /**********************************************************************/
int RealizarBusquedas (Personas personas, string iden, TContadores contadores)
{
    int ok;
  //  cout << endl << "** Buscando " << iden << " ... " << endl;
   // cout << endl;
  
    BusquedaSecuencial (personas.info, personas.num, iden, contadores[0]);
/*  
    cout << "Busqueda secuencial...";
    cout << "Hecho" << endl;
    cout << "Ha tardado "<< contadores[0] << " pasos con Busqueda Secuencial" << endl;
*/   
    ok = BusquedaSecuencialParada (personas.info, personas.num, iden, contadores[1]);
/* 
    cout << "Busqueda secuencial con Parada...";
    cout << "Hecho" << endl;
    cout << "Ha tardado "<< contadores[1] << " pasos con Busqueda Secuencial con Parada " << endl;
*/

    BusquedaConCentinela (personas.info, personas.num, iden, contadores[2]);
/* 
    cout << "Busqueda secuencial con centinela...";
    cout << "Hecho" << endl;
    cout << "Ha tardado "<< contadores[2] << " pasos con Busqueda Secuencial con centinela " << endl;
*/
	BusquedaBinaria (personas.info, personas.num, iden, contadores[3]);
/*
    cout << "Busqueda binaria...";
    cout << "Hecho." << endl;
    cout << "Ha tardado "<< contadores[3] << " pasos con Busqueda binaria " << endl;     
	cout << endl;
    cout << ok << " posicion " << endl;
*/
        
    return ok;
}

