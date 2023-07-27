
/******* persona.h ***************************************************/ /**
 *
 * @file persona.h
 *
 * Fichero de cabecera de la clase Persona
 *
 * @version 1.1
 * @author Jose Fco. Garcia, Jesus Albert
 * @date 22/02/2022
 *  
 ***************************************************************************/

#ifndef _PERSONA_H_
#define _PERSONA_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Clase para el manejo de Persona
 *
 * Clase para manejar la informacion de vacunaciones.
  */
class Persona
{
    public:
        // Constructor por defecto
        Persona();
		// Operaciones para devolver información de la persona vacunada
		string DevuelveIdentificador();
		// Operacion para modificar información de la persona vacunada
		void PonIdentificador(string);
        bool LeerDeFichero(ifstream &);
        void Mostrar();

    private:       
        // Atributos propios de una persona vacunada:
        string identificador;       ///< Identificador de la persona vacunada, formato 0000AAA
        string nombre;              ///< Nombre de la persona
        string vacuna;              ///< Vacuna que se le suministra
        string f_1;     ///< Fecha de la primera dosis
        string f_2;     ///< Fecha de la segunda dosis
        string f_3;     ///< Fecha de la tercera dosis
};

#endif
