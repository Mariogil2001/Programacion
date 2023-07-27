/******* Pr7_Distribuidos.cpp ***************************************************/ /**
 *
 * @file Pr7_Distribuidos.cpp
 *
 * Fichero de funciones de la clase Lote
 *
 * @version 1.0
 * @author Mario Gil Domingo
 * @author Luis Razvan Petrisor
 * @date 14/05/2022
 *  
 ***************************************************************************/
 
 #include "Pr7_Distribuidos.h"
 
/*
 * Crea un conjunto de lotes distribuidos.
 * Deberá inicializar los atributos de 
 * la clase base de la manera adecuada,
 * usandocomo nombre la cadena recibida.
 *
*/

Distribuidos::Distribuidos(string nombr)
:Almacen(nombr)
{
}

/*
 * Añade un lote al final de la cola de lotes distribuidos,
 * fijando su fecha de distribución y 
 * poniendo a true el atributo correspondiente del lote.
 *
 * @param [in,out] Lote, fec
*/

void Distribuidos::DistribuirLote(Lote lot, Fecha fec)
{
	bool ok = true;
	lot.AsignaValores(lot.DevuelveIdentificador(),lot.DevuelveFechaCaducidad(),ok,fec,lot.DevuelveMarca());
	distribuidas.push(lot);
	return;
}

/*  
 * @return Devuelve la fecha de administración del último lote 
 * distribuido.
 *
 */
 
Fecha Distribuidos::DevuelveFechaUltimoLote()
{
	Lote lot;
	lot = distribuidas.back();
	
	return	lot.DevuelveFechaAdministracion();
} 

/*  
 * @return Devuelve el número de lotes de vacunas que han sido 
 * guardados como distribuidos.
 *
 */

int Distribuidos::DevuelveCantidadDistribuidos()
{
	return distribuidas.size();
}







