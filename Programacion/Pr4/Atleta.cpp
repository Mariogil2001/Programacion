
/******* Atleta.cpp ****************************************************/ /**
 *
 * @file Atleta.cpp
 *
 * Implementación de los métodos de la clase Atleta
 *
 * @version 1.0
 * @author Mario Gil Domingo, Luis Razvan Petrisor
 * @date 11/03/2022
 *  
 ***************************************************************************/

#include "Atleta.h"

/*** Atleta::Atleta() **************************************************/ /**
 *
 *  Asigna valores iniciales 'coherentes' a los distintos atributos de la
 *  clase
 *
 */ /**********************************************************************/
Atleta::Atleta ()
{
    /*
       No seria necesario iniciar los 'string' porque se inician de forma
       automatica a vacios en cuanto se declaran, como p.e. codigo = "";
    
        Si se quiere, podríamos iniciarlos a valores 'por defecto'
    */
    
    Codigo = "unknown";
    Nombre = "unknown";
    Pais = "unknown";
    Especialidad = "unknown";

}

/*** void Atleta::Mostrar () ******************/ /**
 *
 *  Muestra por la salida estandar los datos de la vacunacion de las personas
 *
 */ /**********************************************************************/
void Atleta::Mostrar ()
{
    string sep = "    ";
    
    cout << "*** Datos del Atleta:" << endl;
    cout << sep << "- Codigo: " << Codigo << endl;
    cout << sep << "- Apellidos, Nombre: " << Nombre << endl;
    cout << sep << "- Pais: " << Pais << endl;
    cout << sep << "- Especialidad: " << Especialidad << endl;

    cout << endl;  
    
    return;  
}

/*** ifstream & LeerDeFichero (ifstream & ) ************************/ /**
 *
 *  
 *
 *  @return  El stream modificado tras su utilizacion
 *
 */ /**********************************************************************/
bool Atleta::LeerDeFichero (ifstream & fich_in)
{
    bool ok;

    if ( getline (fich_in, Codigo,';') )
    {
        getline (fich_in, Nombre,';');
        getline (fich_in, Pais,';');    
        getline (fich_in, Especialidad);       
        ok = true;
    }
    else
        ok = false;
        
    return ok;       
}


/**********************************************************************/ /**
 *
 *  Devuelve el codigo del atleta.
 *
 *  @return    String para devolver información del codigo del atleta
 *
 */ /**********************************************************************/
 string Atleta::DevuelveCodigo () const
 {
    return Codigo;
 }
   
 /**********************************************************************/ /**
 *
 *  Devuelve el codigo del atleta.
 *
 *  @return    String para devolver información del Pais del atleta
 *
 */ /**********************************************************************/
 string Atleta::DevuelveNombre () const
 {
    return Nombre;
 }

  /**********************************************************************/ /**
 *
 *  Devuelve el codigo del atleta.
 *
 *  @return    String para devolver información de la especialidad del atleta
 *
 */ /**********************************************************************/
 string Atleta::DevuelvePais () const
 {
    return Pais;
 }
 
   /**********************************************************************/ /**
 *
 *  Devuelve el codigo del atleta.
 *
 *  @return    String para devolver información de la especialidad del atleta
 *
 */ /**********************************************************************/
 string Atleta::DevuelveEspecialidad () const
 {
    return Especialidad;
 }						

/**********************************************************************/ /**
 *
 *  Asigna los valores del atleta  recibido como parámetro.
 *
 *  @param[in]  c1 Codigo del Atleta
 *  @param[in]  c2 Nombre del Atleta
 *  @param[in]  c3 Pais del Atleta
 *  @param[in]  c4 Especialida del Atleta
 *
 */ /**********************************************************************/
 void Atleta::AsignarValores(string c1 ,string c2, string c3 ,string c4)
 {
    Codigo = c1;
    Nombre = c2;
    Pais = c3;
    Especialidad = c4;
    
    return;
 }

