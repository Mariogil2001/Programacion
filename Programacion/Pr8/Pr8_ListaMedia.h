/****** Pr8_ListaMedia.h **************************************************/ /**
 *
 * @file Pr8_ListaMedia.h
 *
 * @brief Fichero de cabecera de la clase Media
 *
 * @version 1.0
 * @author Mario Gil Domingo
 * @author Luis Razvan Petrisor
 * @date 19-05-2022
 */ /**************************************************************************/

#ifndef _LISTAMEDIA_H_
#define _LISTAMEDIA_H_

#include "Pr8_Media.h"
#include <fstream>

using namespace std;

/** Clase ListaMedia para la gestión de una lista de reproduccion */
class ListaMedia : public Media
{
	public:
		ListaMedia ();
		ListaMedia (const ListaMedia &);
		~ListaMedia ();
		const ListaMedia & operator= (const ListaMedia &);
		void Insertar (Media, int);
		void Vaciar();
		bool Eliminar ();
		void Copiar (const ListaMedia &);
		bool Consultar (Media &);
		bool ListaVacia ();
		void IrAInicio ();
		void MoverAlFinal ();
		bool Avanzar ();
		bool Retroceder (); 
		bool FinalLista ();
		void MostrarPantalla ();
		bool GuardarEnFichero (string);
		bool RecuperarDeFichero (string);
		
	private:
		struct Nodo;
		typedef Nodo* Puntero;
		struct Nodo
		{
			Media info;
			Puntero sig;
			Puntero ant;
		};
		Puntero cab; //Puntero al inicio de la lista
		Puntero pto; //Punto de interes
		//Numero de orden del archivo activo
		int activo;
		//  Numero total de archivos en la lista
		int cuantos;
		// tiempo total de la lista de reproduccion
		Tiempo total;
};
#endif
