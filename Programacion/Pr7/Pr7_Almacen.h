/******* Pr7_Almacen.h ***************************************************/ /**
 *
 * @file Pr7_Almacen.h
 *
 * Fichero de cabecera de la clase Almacen
 *
 * @version 1.0
 * @author Mario Gil Domingo
 * @author Luis Razvan Petrisor
 * @date 13/05/2022
 *  
 ***************************************************************************/

#include<queue>
#include "Pr7_Lote.h"

using namespace std;

#ifndef _ALMACEN_H_
#define _ALMACEN_H_

/**
 * @brief Clase para el manejo del almacen que hereda del lote
 *
 * Interfaz de la clase Almacen, que representa el conjunto de lotes
 *
 */

class Almacen : public Lote
{
    public:
        // Constructor por defecto
        Almacen(string);
        void AlmacenarLote(Lote);
        Fecha DevuelveFechaPrimerLote();
        Lote ExtraeLote ();
        int DevuelveStock() const;
        bool AlmacenVacio();
        bool GuardaAlmacen(ostream &) const;
        friend ostream & operator << (ostream&, const Almacen &);
        


    protected:
    	//  Identificador del nombre, de tipo Cadena
		string nombre;
		queue <Lote> vacunas;
		
};

#endif
