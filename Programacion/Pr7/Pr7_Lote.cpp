/******* Pr7_Lote.cpp ***************************************************/ /**
 *
 * @file Pr7_Lote.cpp
 *
 * Fichero de funciones de la clase Lote
 *
 * @version 1.0
 * @author Mario Gil Domingo
 * @author Luis Razvan Petrisor
 * @date 11/05/2022
 *  
 ***************************************************************************/
 
 #include "Pr7_Lote.h"
 
 
/*  
 *  Crea un lote. Debería iniciar todos los campos de información 
 *  del evento correctamente: la cadena a “<Sin asignar>”, las 
 *  fechas a un valor correcto de fecha, por ejemplo 1/1/1970, y 
 *  la marca a 0.
 */
 
 // Constructor por defecto
 Lote::Lote()
 :Fecha()
 {
 	identificador = "<Sin asignar>";
 	administracion.AsignarValores(1,1,1970);
 	caducidad.AsignarValores(1,1,1970);
 	administrado = false;
 	marca = 0;
 }
 
/**
 * Metodo para asignar los valores del identificador, fecha de administracion,
 * fecha de caducidad, si ha sido adinistrado y la marca.
 * Asigna valores a la información del lote l:
 * id= identificador, f1= fecha de caducidad, admin= administrado, 
 * f2= fecha de administración, m= marca.
 *
 * @param [in] id Cadena referente al identificador de la vacuna
 * @param [in] f1 Fecha referente a la fecha de administracion del lote
 * @param [in] admin Booleano referente a si ha sido administrado o no
 * @param [in] f2 Fecha referente a la fecha de caducidad del lote de vacunas
 * @param [in] m Entero referente a la marca de las vacunas
 *
 * @return no devuelve nada
 *
 */
 
void Lote::AsignaValores (string id, Fecha f1, bool admin, Fecha f2, int m)
{
	
	identificador = id;
  	caducidad = f1;
 	administrado = admin;
	administracion = f2;
	marca = m;	
  		    
    return;
}

/**
 * Metodo para consultar la fecha de caducidad.
 *
 * @return  La fecha de caducidad
 *
 */
 
Fecha Lote::DevuelveFechaCaducidad()
{
	return caducidad;
}

/**
 * Metodo para consultar la fecha de administracion.
 *
 * @return  La fecha de administracion
 *
 */
 
Fecha Lote::DevuelveFechaAdministracion()
{
	return administracion;
}

/**
 * Metodo para consultar si el lote ha sido administrado.
 *
 * @return  Si ha sido administrado o no
 *
 */
 
bool Lote::DevuelveAdministrado()
{
	bool aux = false;
	if(administrado)
		aux = true;
		
	return aux;
}

/**
 * Metodo para consultar el identificador.
 *
 * @return  La cadena del identificador
 *
 */
 
string Lote::DevuelveIdentificador()
{
	return identificador;
}

/**
 * Metodo para consultar la marca del lote.
 *
 * @return  Entero con la marca
 *
 */
 
int Lote::DevuelveMarca()
{
	return marca;
}
/**
 * Metodo para guardar en memoria el lote.
 *
 * @return  si se ha podido guardar
 *
 */
bool Lote::GuardarLote(ostream & os)
{
	bool aux;
	if (!os)
		aux = false;
	else
	{
		os << identificador  << ";" ;
		os << caducidad << ";";
		os << administrado << ";";
		os << administracion << ";";
		os << marca << endl;		
		aux = true;
	}

	return aux;
}

 /*** ifstream & LeerLote (ifstream & ) ************************/ /**
 *
 *  Lectura de un fichero mediante ifstream, el formato de entrada del lote es
 *  identificacion;fecha caducidad;administrado;Fecha administracion;marca
 * 
 *
 * 
 *  @return  Si se ha leido el lote
 *
 */ /**********************************************************************/
 
 bool Lote::LeerLote(ifstream & fich_in, Lote & lot)
 {
 	bool ok;
 	string aux, ident;
	Fecha f1, f2;
	bool a;
	int m;
    if (getline (fich_in, ident,';') )
    {
    	fich_in >> f1;
		
    	getline (fich_in,aux,';');
    	a = bool(stoi(aux));
    	
    	fich_in >> f2;
		
		getline (fich_in, aux);
		m = stoi(aux);
		lot.AsignaValores(ident,f1,a,f2,m);
	 	ok = true;
	 }
	 else
	 	ok = false;
	 return ok;	
 }


/**
 * Sobrecarga del operador << a para poder almacenar la informacion de un
 * stream en un Lote.
 *
 * @param [in, out] ins  stream del que extraer la informacion del lote
 * @param [in, out] lot  Lote en el que almacenar la informacion. 
 *
 *
 * return  El stream modificado
 */
 
ostream & operator << (ostream & out, const Lote & lot)
{
	out << "Lote " << lot.identificador << endl;
	out << "Fabricante: ";
	if(lot.marca == 1)
		out << "Moelna" << endl;
	if (lot.marca == 2)
		out << "Piastra Azteca" << endl;	
	if (lot.marca == 0)
		out << "No definida :(" << endl;
		
	out << "Fecha de caducidad: " << lot.caducidad << endl;
	out << "Fecha de administracion: ";
	if (lot.administrado)
		out << lot.administracion << endl;
	else
		out << "NO ADIMINISTRADO" << endl;
	out << endl;
			
    return out;
};
