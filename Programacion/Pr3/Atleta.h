
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
 * informaci�n de los atletas que participan
 * en una competici�n de atletismo.
 *
  */
class Atleta
{
    public:
        // Constructor por defecto
        Atleta();
        // Crear un atleta. Deber� inicializar todos los campos de informaci�n del atleta con el valor �<Sin asignar>�.
        // void CrearAtleta ();
        // Asigna la informaci�n del atleta a, c1=c�digo, c2=nombre, c3=pa�s,c4=especialidad.
		void AsignarValores(string,string,string,string);
        bool LeerDeFichero(ifstream &); // Hecho
        void Mostrar(); // Hecho
		// Operaciones para devolver informaci�n del codigo del atleta
		string DevuelveCodigo();
		// Operaciones para devolver informaci�n del nombre del atleta
		string DevuelveNombre();
		// Operaciones para devolver informaci�n del Pais del atleta
		string DevuelvePais();
		// Operaciones para devolver informaci�n de la especialidad del atleta
		string DevuelveEspecialidad();						



    private:       
        // Atributos propios de una persona vacunada:
        string Codigo;       ///< Codigo del atleta, formato AA000000
        string Nombre;              ///< Nombre y apellidos del atleta
        string Pais;              ///< Pa�s de origen del atleta, seguramente jamaicano como Usain Bolt
        string Especialidad;     ///< Especialidad en la que participa el atleta (solo una)
};

#endif
