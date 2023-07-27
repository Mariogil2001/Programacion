
/******* persona.cpp ****************************************************/ /**
 *
 * @file persona.cpp
 *
 * Implementación de los métodos de la clase Persona
 *
 * @version 1.0
 * @author Jose Fco. Garcia, Jesus V. Albert
 * @date 22/02/2022
 *  
 ***************************************************************************/

#include "persona.h"

/*** Persona::Persona() **************************************************/ /**
 *
 *  Asigna valores iniciales 'coherentes' a los distintos atributos de la
 *  clase
 *
 */ /**********************************************************************/
Persona::Persona ()
{
    /*
       No seria necesario iniciar los 'string' porque se inician de forma
       automatica a vacios en cuanto se declaran, como p.e. identificador = "";
    
        Si se quiere, podríamos iniciarlos a valores 'por defecto'
    */
    
    identificador = "unknown";
    nombre = "unknown";
    vacuna = "unknown";
    f_1 = "unknown";
    f_2 = "unknown";
    f_3 = "unknown";
}

/*** void Persona::Mostrar () ******************/ /**
 *
 *  Muestra por la salida estandar los datos de la vacunacion de las personas
 *
 */ /**********************************************************************/
void Persona::Mostrar ()
{
    string sep = "    ";
    
    cout << "*** Datos de vacunación:" << endl;
    cout << sep << "- Idnetificador: " << identificador << endl;
    cout << sep << "- Nombre: " << nombre << endl;
    cout << sep << "- Vacuna: " << vacuna << endl;
    cout << sep << "- Fecha primera dosis: " << f_1 << endl;
    cout << sep << "- Fecha segunda dosis: " << f_2 << endl;
    cout << sep << "- Fecha tercera dosis: " << f_3 << endl;
    cout << endl;  
    
    return;  
}

/*** istream & LeerDeFichero (istream &) ************************/ /**
 *
 *  @param [in/out]  fich_in  stream del que vamos a obtener la informacion.
 *
 *  @return  El stream modificado tras su utilizacion
 *
 */ /**********************************************************************/
bool Persona::LeerDeFichero (ifstream & fich_in)
{
    bool ok;
    string salto;

    if ( getline (fich_in, identificador,';') )
    {
        getline (fich_in, nombre,';');
        getline (fich_in, vacuna,';');    
        getline (fich_in, f_1,';');    
        getline (fich_in, f_2,';');    
        getline (fich_in, f_3,';');    
        getline (fich_in,salto); //Saltar a la siguiente linea
        ok = true;
    }
    else
        ok = false;
        
    return ok;       
}


/**********************************************************************/ /**
 *
 *  Devuelve el identificador de la persona vacunada.
 *
 *  @return  el string con el identificador de la persona vacunada.
 *
 */ /**********************************************************************/
 string Persona::DevuelveIdentificador ()
 {
    return identificador;
 }
   
/**********************************************************************/ /**
 *
 *  Modifica el identificador de la persona vacunada recibido como parámetro.
 *
 *  @param[in]  ident    nuevo identificador de la persona vacunada.
 *
 */ /**********************************************************************/
 void Persona::PonIdentificador (string ident)
 {
    identificador = ident;
    
    return;
 }

