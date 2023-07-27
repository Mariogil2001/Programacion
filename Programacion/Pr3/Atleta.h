
/******* Atleta.h ***************************************************/ /**
 *
 * @file Atleta.h
 *
 * Fichero de cabecera de la clase Atleta
 *
 * @version 1.1
 * @author Mario Gil Domingo, Luis Razvan Petrisor
 * @date 11/03/2022
 *
 *  
 ***************************************************************************/

#ifndef _ATLETA_H_
#define _ATLETA_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Clase para el manejo de Atleta
 *
 * Clase para manejar la informacion de la
 * información de los atletas que participan
 * en una competición de atletismo.
 *
  */
class Atleta
{
    public:
        // Constructor por defecto
        Atleta();
        // Crear un atleta. Deberá inicializar todos los campos de información del atleta con el valor “<Sin asignar>”.
        // void CrearAtleta ();
        // Asigna la información del atleta a, c1=código, c2=nombre, c3=país,c4=especialidad.
		void AsignarValores(string,string,string,string);
        bool LeerDeFichero(ifstream &); // Hecho
        void Mostrar(); // Hecho
		// Operaciones para devolver información del codigo del atleta
		string DevuelveCodigo();
		// Operaciones para devolver información del nombre del atleta
		string DevuelveNombre();
		// Operaciones para devolver información del Pais del atleta
		string DevuelvePais();
		// Operaciones para devolver información de la especialidad del atleta
		string DevuelveEspecialidad();						



    private:       
        // Atributos propios de una persona vacunada:
        string Codigo;       ///< Codigo del atleta, formato AA000000
        string Nombre;              ///< Nombre y apellidos del atleta
        string Pais;              ///< País de origen del atleta, seguramente jamaicano como Usain Bolt
        string Especialidad;     ///< Especialidad en la que participa el atleta (solo una)
};

#endif
