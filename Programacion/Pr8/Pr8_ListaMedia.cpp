/****** Pr8_ListaMedia.cpp ************************************************/ /**
 *
 * @file Pr8_ListaMedia.cpp
 *
 * @brief Implementacion de los metodos de la clase ListaMedia
 *
 * @version 1.0
 * @author Mario Gil Domingo
 * @author Luis Razvan Petrisor
 * @date 19-05-2022
 */ /**************************************************************************/

#include "Pr8_ListaMedia.h"

/**** ListaMedia::ListaMedia () ***************************************************/ /**
 *
 * Constructor por defecto de la clase Media.
 *
 */ /********************************************************************************/
 
 //Constructor por defecto
ListaMedia::ListaMedia ()
{
	cab = new Nodo;
	cab->sig = cab;
	cab->ant = cab;
	pto = cab;
}

/**** ListaMedia::ListaMedia (const ListaMedia &) ***************************************************/ /**
 *
 * Constructor copia de la clase Media.
 *
 */ /********************************************************************************/
 
//Constructor de copia
ListaMedia::ListaMedia (const ListaMedia & ori)
{
	//inicia la lista como vacía
	//y después copia
	cab = new Nodo;
	cab->sig = cab;
	cab->ant = cab;
	pto = cab;
	Copiar(ori);
}

/**** ListaMedia::~ListaMedia () ***************************************************/ /**
 *
 * Destructor por defecto de la clase Media.
 *
 */ /********************************************************************************/
//Destructor de la clase
ListaMedia::~ListaMedia ()
{ 
	Vaciar();
	delete cab;
}

/**
 * Sobrecarga del operador = para copiar la informacion de un
 * stream en una  ListaMedia.
 *
 * @param [in, out] ori  ListaMedia en el que almacenar la informacion. 
 *
 *
 * return  El stream modificado
 */
 
//Operador asignación
const ListaMedia & ListaMedia::operator= (const ListaMedia & ori)
{ 
	Vaciar();
	Copiar (ori);
	return (*this);
}

/**** ListaMedia::Insertar (Media, int) ***************************************************/ /**
 *
 * 	Inserta un elemento en el punto de interes
 *	@param [in] m Media que vamos a insertar
 *	@param [in] pos entero con la posicion donde insertamos
 *	@return no devuelve nada
 *
 */ /********************************************************************************/
 
 void ListaMedia::Insertar (Media m, int pos)
{ 
	Puntero q_aux, interes;
	int i = 0;
	q_aux = new Nodo;
	q_aux->info = m;
	// Nos ponemos en la primera posicion de la lista
	interes = pto;
	interes = cab->sig;
	while (interes != cab && i < pos)
	{
		interes = pto->sig;
		i++;
	}
	q_aux->sig = interes;
	// El anterior es el anterior al punto de interes
	q_aux->ant = interes->ant;
	interes->ant->sig = q_aux;
	interes->ant = q_aux;
	ListaMedia.activo++;
	
	return;
} 

/**** ListaMedia::Eliminar () ***************************************************/ /**
 *
 * 	Elimina el elemento apuntado por el punto de interes
 *
 *	@return si se ha eliminado o no
 *
 */ /********************************************************************************/
//Eliminación del elemento apuntado por el punto de interés
bool ListaMedia::Eliminar ()
{ 
	Puntero p_aux;
	bool ok;
	// Si el pto de interes es la cabeza esta vacia la lista
	if (pto == cab)
		ok = false;
	else
	{ 
		ok = true;
		// Auxiliar apunta al siguiente del punto de interes
		p_aux = pto->sig;
		// La flecha que va desde pto siguiente a anterior apunta a pto anterior
		pto->sig->ant = pto->ant;
		// La flecha que va desde pto anterior a siguiente apunta a pto siguiente
		pto->ant->sig = pto->sig;
		// Borramos pto
		delete pto;
		// El punto de interes apunta a aux
		pto = p_aux;
	} 
	return ok;
 }
 
 /**** ListaMedia::Consultar (Media&) ***************************************************/ /**
 *
 * 	Consulta del elemento apuntado por el punto de interes
 *	@param [in,out] x Media que vamos a consultar
 * 
 *	@return si se ha consultado o no
 *
 */ /********************************************************************************/
 
 //Consulta del elemento apuntado por el punto de interes
bool ListaMedia::Consultar (Media & x)
{ 
	bool ok;
	if (pto == cab)
		ok = false;	
	else
	{ 
		ok = true;
		x = pto->info;
	} 
	return ok;
}

 /**** ListaMedia::ListaVacia () ***************************************************/ /**
 *
 * 	Comprobacion de si existen elementos en la lista
 * 
 *	@return si la lista esta vacia o no
 *
 */ /********************************************************************************/
 
//Comprobación de si existen elementos en la lista
//(además de la cabeza)
bool ListaMedia::ListaVacia ()
{ 
	return (cab == cab->sig); 
}

 /**** ListaMedia::IrAInicio () ***************************************************/ /**
 *
 * 	Situar el punto de interes en el primer elemento de la lista
 * 
 *	@return no devuelve nada
 *
 */ /********************************************************************************/
 
//Situar el punto de interés en el primer elemento de la lista
void ListaMedia::IrAInicio ()
{ 
	pto = cab->sig;
return;
} 

 /**** ListaMedia::MoverAlFinal () ***************************************************/ /**
 *
 * 	Mueve el elemento activo y lo pone al final de la lista
 * 
 *	@return no devuelve nada
 *
 */ /********************************************************************************/
 
//Mueve el elemento activo y lo pone al final de la lista.
void ListaMedia::MoverAlFinal()
{ 
	Puntero q_aux, p_aux;
	// Insertamos el nodo actual en la ultima posicion
	q_aux = new Nodo;
	q_aux->info = pto->info;
	q_aux->sig = cab;
	q_aux->ant = cab->ant;
	cab->ant->sig = q_aux;
	cab->ant = q_aux;
	// Eliminamos el nodo actual y movemos el punto de interes
	p_aux = pto->sig;
	pto->sig->ant = pto->ant;
	pto->ant->sig = pto->sig;
	delete pto;
	pto = p_aux;
		
	return;
} 

 /**** ListaMedia::Avanzar () ***************************************************/ /**
 *
 * 	Avanzar el punto de interes
 * 
 *	@return si se ha podido avanzar o no
 *
 */ /********************************************************************************/
 
//Avanzar el punto de interés
bool ListaMedia::Avanzar ()
{ 
	bool ok;
	if (pto == cab)
		ok = false;
	else
	{ 
		ok = true;
		pto = pto -> sig;
	} 
	return (ok);
 }

 /**** ListaMedia::Avanzar () ***************************************************/ /**
 *
 * 	Retrocede el punto de atención al anterior elemento de la lista, 
 *  de modo circular.
 * 
 *	@return si se ha podido retroceder o no
 *
 */ /********************************************************************************/
  
/* Retrocede el punto de atención al anterior elemento de la lista, 
de modo circular. */

bool ListaMedia::Retroceder ()
{ 
	bool ok;
	if (pto == cab->sig)
		ok = false;
	else
	{ 
		ok = true;
		pto = pto -> ant;
	} 
	return (ok);
 }  

 /**** ListaMedia::FinalLista () ***************************************************/ /**
 *
 * 	Comprobar que hemos llegado al final de la lista.
 * 
 *	@return si estamos en el final de la lista o no
 *
 */ /********************************************************************************/
  
//Comprobar que hemos llegado al final de la lista
//(de nuevo estamos en la cabeza)
bool ListaMedia::FinalLista ()
{
	return pto == cab;	
}

 /**** ListaMedia::Copiar (const ListaMedia&) ***************************************************/ /**
 *
 * 	Copiar la lista ori en this.
 * 
 *	@param[in,out] ori ListaMedia donde se va a copiar
 *	@return no devuelve nada
 *
 */ /********************************************************************************/
  
//Copiar la lista ori en this
void ListaMedia::Copiar (const ListaMedia & ori)
{
	Puntero p_aux, q_aux;
	
	//Se recorre la lista original
	p_aux = ori.cab->sig;
	while (p_aux != ori.cab)
	{
		//Se reserva espacio y actualiza la informacion
		q_aux = new Nodo;
		q_aux->info = p_aux->info;
		
		//Se van añadiendo los elementos delante de la cabeza
		//es decir, al final de la lista
		q_aux->sig = cab;
		q_aux->ant = cab->ant;
		cab->ant->sig = q_aux;
		cab->ant = q_aux;
		
		//Si estamos copiando el pto de interés lo fijamos en
		//la copia
		if (p_aux == ori.pto)
			pto = q_aux;
			
		p_aux = p_aux->sig;
	}
	return;
} 

 /**** ListaMedia::Vaciar () ***************************************************/ /**
 *
 * 	Vaciar la lista.
 * 
 *	@return no devuelve nada
 *
 */ /********************************************************************************/
 
//Vaciar la lista
void ListaMedia::Vaciar ()
{
	pto = cab->sig; 
	while ( Eliminar());
	
	return;
}

 /**** ListaMedia::MostrarPantalla () ***************************************************/ /**
 *
 * 	Muestra por pantalla el conjunto de media.
 * 
 *	@return no devuelve nada
 *
 */ /********************************************************************************/
 
void ListaMedia::MostrarPantalla()
{
	int i = 1;
	while(Avanzar())
	{
		cout << i << ". " << Media.DevuelveTitulo() << "		" << Media.DevuelveTiempo()<<endl;
	}
	
}

 /**** ListaMedia::GuardarEnFichero (string) ***************************************************/ /**
 *
 * 	Guarda en un fichero el conjunto de media.
 * 
 *	@param [in] archivo, cadena con el nombre del documento donde se guardara
 *	@return si se ha podido guardar o no
 *
 */ /********************************************************************************/
 
bool ListaMedia::GuardarEnFichero(string archivo)
{
	ofstream out;
	bool ok;
	out.open(archivo.c_str())
	if (!out) ok = false;
	else
	{
		while(Avanzar())
		{
			out << Media << endl;
		}
		ok = true;
		out.close();
	}
	
	return ok;
}
 /**** ListaMedia::RecuperarDeFichero (string) ***************************************************/ /**
 *
 * 	Lee de un fichero el conjunto de media.
 * 
 *	@param [in] archivo, cadena con el nombre del documento de donde se leera
 *	@return si se ha podido leer o no
 *
 */ /********************************************************************************/
 
bool ListaMedia::RecuperarDeFichero(string archivo)
{
	ifstream in;
	bool ok;
	in.open(archivo.c_str())
	if(!in) ok = false;
	else
	{
		while(Avanzar())
		{
			in >> Media;
		}
		ok = true;
		in.close();
	}
	 return ok;
}
