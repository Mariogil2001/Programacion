/******* Pr7_Almacen.cpp ***************************************************/ /**
 *
 * @file Pr7_Almacen.cpp
 *
 * Fichero de funciones de la clase Almacen
 *
 * @version 1.0
 * @author Mario Gil Domingo
 * @author Luis Razvan Petrisor
 * @date 11/05/2022
 *  
 ***************************************************************************/
 
 #include "Pr7_Almacen.h"
  
/*  
 *  Crea un Almacen. Debería iniciar todos los campos de información 
 *  del evento correctamente: la cadena a “<Sin asignar>”, las 
 *  fechas a un valor correcto de fecha, por ejemplo 1/1/1970.
 */
 
 // Constructor por defecto
 Almacen::Almacen(string nom)
 :Lote()
 {
 	nombre = nom;
 }

/*  
 *  Inserta un lote al final de la cola del almacen.
 * @param [in] Lote el lote a almacenar
 * @return no devuelve nada
 */
 
void Almacen::AlmacenarLote(Lote lot)
{
	vacunas.push(lot);
	
	return;
}

/*  
 * @return Devuelve la fecha de caducidad del primer lote del almacen.
 *
 */
 
Fecha Almacen::DevuelveFechaPrimerLote()
{
	Lote lot;
	lot = vacunas.front();
	
	return	lot.DevuelveFechaCaducidad();
} 

/*  
 *  Saca de la cola el primer lote y lo devuelve.
 *
 * @return el primer lote de la cola
 */

Lote Almacen::ExtraeLote()
{
	Lote lot;
	// Obtiene el primer lote de la cola
	lot = vacunas.front();
	// Elimina el primer lote de la cola
	vacunas.pop();
	return lot;
} 

/*  
 *  Devuelve el numero de elementos en la cola.
 *
 * @return numero de lotes
 */
 
 int Almacen::DevuelveStock() const
 {
 	return vacunas.size();
 }
 
/*  
 * Indica si el almacen esta vacio o no.
 *
 * @return bool si el almacen esta vacio true
 *
 */
 
 bool Almacen::AlmacenVacio()
 {
 	bool aux = false;
 	if(vacunas.empty())
 		aux = true;
 	return aux;	
 }
 
/*  
 * Guarda la información de los lotes almacenados
 * en el flujo de salida.
 * 
 * @param [in,out] ostream
 * @return no devuelve nada
 *
 */
 
 bool Almacen::GuardaAlmacen (ostream & out) const
 {
 	queue <Lote> vacuna2 = vacunas;
	bool aux;
	Lote lot;
	
	if (!out)
		aux = false;
	else
	{
		while(!vacuna2.empty())
		{
			lot = vacuna2.front();
			vacuna2.pop();
			lot.GuardarLote(out);
		}
		aux = true;
	}

 	return aux;
 }
 
 /*  
 * Muestra por pantalla los lotes con caducidad mas cercana y 
 * mas lejana del almacen y el numero de lotes.
 * 
 * @param [in,out] ostream, Almacen
 * @return no devuelve nada
 *
 */
 
ostream & operator << (ostream & of, const Almacen & almacen)
{
	of << "*********************************************" << endl,
	of << "Datos del Almacen:" << endl;
	of << "== " << almacen.nombre << " ==" << endl;
	of << "Cantidad de lotes almacenados: " << almacen.DevuelveStock() << endl;
	of << endl;
	of << "** Lote mas antiguo: **" << endl;
	of << almacen.vacunas.front();
	of << endl;
	of << "** Lote mas reciente: **" << endl;
	of << almacen.vacunas.back();
	of << "*********************************************" << endl;
	
	return of;
}

 
