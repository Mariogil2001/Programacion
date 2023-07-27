
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

#ifndef _EVENTO_H_
#define _EVENTO_H_

#include <iostream>
#include <fstream>
#include <string>
#include "Pr3_Atleta.h"
#include "Pr4_Fecha.h"


using namespace std;
static const int MAX = 350;
typedef Atleta V_Atletas[MAX];


/**
 * @brief Clase para el manejo de Atleta
 *
 * Clase para manejar la informacion de la
 * información de los atletas que participan
 * en una competición de atletismo.
 *
  */
class Evento
{

		
    public:
        // Constructor por defecto
        Evento();
		void AsignarValores(string,string,string,string, Fecha, string, string);
        void InvitarAtleta(Atleta);
		string DevuelveCodigo() const;
		string DevuelveNombre() const;
		void DevuelveLocalizacion(string&, string&) const;
		Fecha DevuelveFecha() const;
		string DevuelveEspecialidad() const;
		bool EsInternacional() const;
		void GuardarAtletas (ostream &) const;
		friend ostream & operator << (ostream & out, const Evento & e);

	    private:       
        // Atributos propios de una persona vacunada:
        string Codigo;       ///< Codigo del atleta, formato AA000000
        string Nombre;
		string Ciudad;              ///< Nombre y apellidos del atleta
        string Pais;
		Fecha fecha;              ///< País de origen del atleta, seguramente jamaicano como Usain Bolt
        string Especialidad;
		string TipoEvento;
		struct Atletas
		{
			V_Atletas info;
			int num;
		};
		Atletas listatleta;
		
};

#endif
