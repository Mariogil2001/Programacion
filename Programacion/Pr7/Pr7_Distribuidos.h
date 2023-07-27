/******* Pr7_Distribuidos.h ***************************************************/ /**
 *
 * @file Pr7_Distribuidos.h
 *
 * Fichero de cabecera de la clase Distribudos
 *
 * @version 1.0
 * @author Mario Gil Domingo
 * @author Luis Razvan Petrisor
 * @date 14/05/2022
 *  
 ***************************************************************************/

#include "Pr7_Almacen.h"


#ifndef _DISTRIBUIDOS_H_
#define _DISTRIBUIDOS_H_

/**
 * @brief Clase para el manejo del almacen que hereda del lote
 *
 * Interfaz de la clase Almacen, que representa el conjunto de lotes
 *
 */

class Distribuidos : public Almacen
{
    public:
        // Constructor por defecto
        Distribuidos(string);
        void DistribuirLote (Lote, Fecha);
        Fecha DevuelveFechaUltimoLote();
        int DevuelveCantidadDistribuidos();
        
    private:
	queue <Lote> distribuidas;
		
};

#endif
