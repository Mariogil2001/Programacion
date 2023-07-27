/****** pr2.cpp ****************************************************/ /**
 *
 * @file pr2.cpp
 *
 * @brief Prácticas de Programacion 2.
 *
 * Lee la informacion de las personas vacunadas guardada en un fichero, los pone
 * en una estructura y los muestra por pantalla utilizando la clase Persona.
 *
 * El programa está preparado para probar y analizar los algoritmos de ordenación
 *
 * @version 0.9
 * @author Mario Gil Domingo, Luis Razvan Petrisor
 * @date 22-02-2022
 */ /**************************************************************************/
 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  //Equivalente C, #include <stdlib.h>
#include <ctime>    //Equivalente C, #include <time.h>

#include "persona.h"

using namespace std;

/**
 * Maximo nº de personas que es posible guardar en la estructura
 */
const int MAX = 5100;

///< Numero de algoritmos con los que trabajar
const int N_ALGORITMOS = 3;

///< Codificación de los algoritmos de ordenación
const int INSERCION = 0;
const int SELECCION = 1;
const int QUICKSORT = 2;

//const string NOM_FICH = "vacunaciones_small.csv";  ///< Nombre del fichero a leer
const string NOM_FICH = "vacunaciones_big.csv";  ///< Nombre del fichero a leer

/**
 * Usaremos la clase Persona para guardar la informacion relativa a cada una de las
 * personas vacunadas.
 */
   
/**
 * Tipo vector de personas vacunadas: Estructura auxiliar para construir el registro Personas
 */ 
typedef Persona TVecPersonas[MAX+1];

/**
 * Registro Personas donde guardar toda la informacion de las personas vacunadas
 * (la informacion de cada persona vacunada, asi como el numero de personas vacunadas)
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
void ResetContadores(TContadores&);
 
Personas LeerFichero (string);
void MostrarPersonas (Personas);

bool Ordenado(TVecPersonas, int);
void Desordenar(TVecPersonas, int);

void OrdenarInsercion(TVecPersonas, int, int &);
void OrdenarSeleccion(TVecPersonas, int, int &);
void OrdenarQuicksort(TVecPersonas, int, int &); 
void Particion(TVecPersonas, int, int, int &);

void ProbarOrdenaciones(Personas &, int, TContadores);
void RealizarExperimentos(Personas &, int, TContadores, int);

/*
 * Programa principal
 */
int main ()
{
    Personas personas;     // Registro en el que vamos a buscar
    TContadores contadores;  // Contadores del total de operaciones, 1 x algoritmo
    unsigned int talla, repeticiones;
    
    //Permite mostrar caracteres del lenguaje castellano: acentos, ñ, ...
	setlocale (LC_ALL, "spanish");
   	ResetContadores(contadores);      		
    // Leemos la informacion del conjunto de personas
    personas = LeerFichero (NOM_FICH);
	do
	{
//    	ResetContadores(contadores);      		
	    cout << "Indica la talla del vector a estudiar: ";
	    cin >> talla;
	
	    cout << "Indica el numero de repeticiones: ";
	    cin >> repeticiones;	
		RealizarExperimentos(personas, talla, contadores, repeticiones);   
	}while(talla!=0);
    
    // Verificamos en pantalla los datos leidos
	//    MostrarPersonas (personas);
	//    if(Ordenado(personas.info, personas.num))
	//        cout << endl << "El fichero original esta ordenado creciente." << endl;
	//    else    
	//        cout << endl << "El fichero original NO esta ordenado creciente." << endl;
        
    //ResetContadores(contadores);      
    //ProbarOrdenaciones(personas, personas.num, contadores);

                
    return 0;
}

/**********************************************************************/ /**
 *
 *  Lee la informacion de las personaes contenidas en el fichero del que se
 *  nos pasa el nombre y la guarda en el registro Personas de forma
 *  adecuada.
 *  La funcion NO mostrara NADA por pantalla. Si el fichero no se puede
 *  abrir, en numero de personas leido sera cero.
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
        
        while ( personas.info[personas.num].LeerDeFichero(fich_in) )
            personas.num++;
            
        fich_in.close ();
    }

    return personas;
}

/**********************************************************************/ /**
 *
 *  Muestra la informacion de las personas contenidas en el vector
 *
 *  @param [in]  personas  registro con la informacion de las personas
 *
 */ /**********************************************************************/
void MostrarPersonas (Personas personas)
{
    // Mostrar por pantalla los datos leidos
    for (unsigned int i = 0; i < personas.num; i++)
    {
        //Mostrar por pantalla los datos del objeto personas.info[i] que es de la clase Persona
        personas.info[i].Mostrar();
    } 

}

/**********************************************************************/ /**
 *
 *  Inicia a 0 los contadores de pasos de los algoritmos
 *
 *  @param [in,out]  t  array de contadores de pasos
 *
 */ /**********************************************************************/
void ResetContadores(TContadores& t)
{
    for (int i = 0; i < N_ALGORITMOS; i++)
        t[i] = 0;
}

/**********************************************************************/ /**
 *
 *  Indica si los primeros num elementos de un vector de personas están en orden creciente
 *
 *  @param [in]  v  Vector de objetos de la clase Persona.
 *
 *  @param [in]  num Número de personas a comprobar del vector
 *
 *  @return  Verdadero si cada elemento es "menor" que el siguiente
 *
 */ /**********************************************************************/
bool Ordenado(TVecPersonas v, int num)
{
    bool respuesta;
    int i;
    
    i = 0;
    while( i < (num - 1) && v[i].DevuelveIdentificador() < v[i+1].DevuelveIdentificador() )
        i++;
        
    if(i == num - 1)
        respuesta = true;
    else
        respuesta = false;
                
    return respuesta;
}

/**********************************************************************/ /**
 *
 *  Desordena n elementos de un vector aleatoriamente
 *
 *  @param [in/out]  v  Vector de objetos de la clase Persona.
 *
 *  @param [in]  n Número de personas que se ordenan
 *
 */ /**********************************************************************/
void Desordenar(TVecPersonas v, int n)
{
    int i, cual;
    Persona auxpersona;
    
    
    for(i=0; i<n; i++)
    {
        cual = rand()%n;
        auxpersona = v[cual];
        v[cual] = v[0];
        v[0] = auxpersona;
    }
    
    return;
}

/**********************************************************************/ /**
 *
 *  Ordena de modo creciente n elementos de un vector por el algoritmo de inserción
 *
 *  @param [in/out]  v  Vector de objetos de la clase TPersona
 *
 *  @param [in]  n Número de personas que se ordenan
 *
 *  @param [in/out]  pasos  incrementa el numero de pasos
 *
 */ /**********************************************************************/
void OrdenarInsercion(TVecPersonas v, int n, int & pasos)
{ 
   
    int i, j;

    
    //la parte ordenada está al final de vector
    for (i = n-2; i>=0; i--)
    {
        v[n] = v[i]; //centinela
        pasos++;
        j = i+1;
        while ( v[j].DevuelveIdentificador() < v[n].DevuelveIdentificador() )
        {       
            v[j-1] = v[j];
            j++;
            pasos += 2;
        }
        v[j-1] = v[n];
        pasos+=2;
    }
    
    return;
}

/**********************************************************************/ /**
 *
 *  Ordena de modo creciente n elementos de un vector por el algoritmo de selección
 *
 *  @param [in/out]  v  Vector de objetos de la clase TPersona.
 *
 *  @param [in]  n Número de personas que se ordenan
 *
 *  @param [in/out]  pasos  incrementa el numero de pasos
 *
 */ /**********************************************************************/
void OrdenarSeleccion(TVecPersonas v, int n, int & pasos)
{ 
   
    int i, j, pos_min;
    Persona aux;

   
    for (i = 0; i < n - 1; i++)
    {    
        pos_min = i;
        for (j = i + 1; j < n; j++)
        {
            if (v[j].DevuelveIdentificador() < v[pos_min].DevuelveIdentificador() )
                pos_min = j;
                pasos++;
        }
              
        if (pos_min != i)
        {  
            aux = v[i];
            v[i] = v[pos_min];
            v[pos_min] = aux;
            pasos+=3;
        }
    }    

    return;
}

/**********************************************************************/ /**
 *
 *  Ordena de modo creciente n elementos de un vector por el algoritmo Quicksort
 *
 *  @param [in/out]  v  Vector de objetos de la clase TPersona.
 *
 *  @param [in]  n Número de personas que se ordenan
 *
 *  @param [in/out]  pasos  incrementa el numero de pasos
 *
 */ /**********************************************************************/
void OrdenarQuicksort(TVecPersonas v, int n, int & pasos)
{
   
    Particion(v, 0, n-1, pasos);

}

/**********************************************************************/ /**
 *
 *  Función de partición para el algoritmo de ordenación por Quicksort
 *
 *  @param [in/out]  v  Vector de objetos de la clase TPersona.
 *
 *  @param [in]  izq  posición izquierda
 *
 *  @param [in]  der  posición derecha
 *
 *  @param [in/out]  pasos  incrementa el numero de pasos
 *
 */ /**********************************************************************/
void Particion(TVecPersonas v, int izq, int der, int & pasos)
{    
    int i, j;
    Persona aux, piv;


    piv = v[(izq+der)/2];
    pasos++;
    i = izq;
    j = der;
    
    while(i<=j)
    {
        while( v[i].DevuelveIdentificador() < piv.DevuelveIdentificador() ) 
        {
            i++;
            pasos++;
        }
        pasos++;
        while( piv.DevuelveIdentificador() < v[j].DevuelveIdentificador() )
        {
            j--;
            pasos++;
        }
        pasos++;    
        if(i < j)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
            pasos+=3;
        } 
        else if (i == j)
        {   
            i++;
            j--;   
        }          
    }    
    
    if(izq < j)
        Particion(v, izq, j, pasos);
    if(i < der)
        Particion(v, i, der, pasos);    


    return;
}

/**********************************************************************/ /**
 *
 *  Prueba los diferentes algoritmos de ordenación.
 *
 *  @param [in/out] personas  Estructura con vector de personas y número de elementos.
 *  @param [in]     n         Tamaño del vector con el que se va a trabajar
 *  @param [in/out] pasos     Contadores de pasos acumulados por algoritmo
 *
 */ /**********************************************************************/
void ProbarOrdenaciones(Personas & personas, int n, TContadores pasos)
{
    Personas personas_copia;
    
    if(Ordenado(personas.info, personas.num))
        cout << endl << "Original ordenado." << endl;
    else
        cout << endl << "Original desordenado." << endl;    
    
    // desordenamos un conjunto de personas con la talla estudiada
    Desordenar(personas.info, n);
    cout << "Se ha desordenado el vector." << endl;

    // hacemos una copia para utilizar el mismo "desorden" en los diferentes algoritmos
    personas_copia = personas;
         
    OrdenarInsercion(personas.info, n, pasos[INSERCION]);
    if(Ordenado(personas.info, n))
        cout << endl << "Vector de " << n << " elementos ordenado";
    else
        cout << endl << "Vector de " << n << " elementos desordenado";        
    cout << " por insercion en " << pasos[INSERCION] << " pasos." << endl;    
    //personas.num = n; 
    //MostrarPersonas(personas);

    // retomamos el mismo "desorden"
    personas = personas_copia;
            
    OrdenarSeleccion(personas.info, n, pasos[SELECCION]);
    if(Ordenado(personas.info, n))
        cout << endl << "Vector de " << n << " elementos ordenado";
    else
        cout << endl << "Vector de " << n << " elementos desordenado";        
    cout << " por seleccion en " << pasos[SELECCION] << " pasos." << endl;    
    //personas.num = n; 
    //MostrarPersonas(personas);
    
    // retomamos el mismo "desorden"
    personas = personas_copia;

    OrdenarQuicksort(personas.info, n, pasos[QUICKSORT]);
    if(Ordenado(personas.info, n))
        cout << endl << "Vector de " << n << " elementos ordenado";
    else
        cout << endl << "Vector de " << n << " elementos desordenado";        
    cout << " por quicksort en " << pasos[QUICKSORT] << " pasos." << endl;    
    //personas.num = n; 
    //MostrarPersonas(personas);
   
    return;
}

/**********************************************************************/ /**
 *
 *  Realiza experimentos con los diferentes algoritmos de ordenación.
 *
 *  @param [in/out] personas  Estructura con vector de personas y número de elementos.
 *  @param [in]     n         Tamaño del vector con el que se va a trabajar
 *  @param [in/out] pasos     Contadores de pasos acumulados por algoritmo
 *  @param [in]     veces     Numero de repeticiones del experimento. 
 *
 */ /**********************************************************************/
void RealizarExperimentos(Personas & personas, int n, TContadores pasos, int veces)
{
    Personas personas_copia;
	
    srand(time(NULL)*time(NULL)); //para que los experimentos sean aleatorios
    // desordenamos un conjunto de personas con la talla estudiada    
    Desordenar(personas.info, n);
    // hacemos una copia para utilizar el mismo "desorden" en los diferentes algoritmos    
	personas_copia = personas;

    for (int i = 0; i < veces; i++)
	{
		
    // retomamos el mismo "desorden"
    personas = personas_copia;
    OrdenarInsercion(personas.info, n, pasos[INSERCION]);
    
    personas = personas_copia;
    OrdenarSeleccion(personas.info, n, pasos[SELECCION]);
    
    personas = personas_copia;
	OrdenarQuicksort(personas.info, n, pasos[QUICKSORT]);
	}



    cout << endl << "Talla: " << n << endl;
    cout << "\t Numero de repeticiones: " << veces << endl;    
    cout << "\t Media de pasos realizados por los 3 algoritmos" << endl;
    cout << "\t\t insercion: " << pasos[INSERCION]/(double)veces << endl;
    cout << "\t\t seleccion: " << pasos[SELECCION]/(double)veces << endl;
    cout << "\t\t quicksort: " << pasos[QUICKSORT]/(double)veces << endl;
    cout << endl;    
    
    return;
}

