/******* Pr7_Lote.h ***************************************************/ /**
 *
 * @file Pr7_Lote.h
 *
 * Fichero de cabecera de la clase Lote
 *
 * @version 1.0
 * @author Mario Gil Domingo
 * @author Luis Razvan Petrisor
 * @date 11/05/2022
 *  
 ***************************************************************************/
 
#include <fstream> 
#include "Pr4_Fecha.h"

using namespace std;

#ifndef _LOTE_H_
#define _LOTE_H_

/**
 * @brief Clase para el manejo de los lotes
 *
 * Interfaz de la clase Lote, que representa las vacunas de un lote
 *
 */

class Lote: public Fecha
{
    public:
        // Constructor por defecto
        Lote ();
        void AsignaValores(string,Fecha,bool,Fecha,int);
        void AsignaFechaAdministracion (Fecha);
        Fecha DevuelveFechaCaducidad();
        Fecha DevuelveFechaAdministracion();
        bool DevuelveAdministrado();
        string DevuelveIdentificador();
        int DevuelveMarca();
		bool GuardarLote (ostream &);
		// Leer el lote
		bool LeerLote (ifstream &, Lote &);
		// Mostrar el lote
		friend ostream & operator << (ostream &, const Lote &);

    private:
    	//  Identificador del lote, de tipo Cadena
		string identificador;
		//  Fecha de caducidad
		Fecha caducidad;
		// Si ha sido administrado o no
		bool administrado;
		// Fecha de administracion
		Fecha administracion;
		// Marca, de tipo entero (0 No definida; 1 Moelna; 2 Piastra Azteca)
		int marca;
};

#endif
