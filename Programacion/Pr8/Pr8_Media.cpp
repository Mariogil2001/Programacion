/****** Pr8_Media.cpp ************************************************/ /**
 *
 * @file Pr8_Media.cpp
 *
 * @brief Implementacion de los metodos de la clase Media
 *
 * @version 1.0
 * @author Mario Gil Domingo
 * @author Luis Razvan Petrisor
 * @date 19-05-2022
 */ /**************************************************************************/

#include "Pr8_Media.h"
#include <iomanip>

/**** Media::Media () ***************************************************/ /**
 *
 * Constructor por defecto de la clase Media.
 *
 */ /********************************************************************************/
 
 Media::Media()
 {
 	titulo = "<Sin titulo>";
 	informacion = "<Sin informacion>";
 	ruta = "<Sin ruta>";
	duracion.SetTiempo(0,0,0);
 }
 
 /**** void Media::EstablecerMedia (string nombre, string inf, string ubicacion, Tiempo tempo) ***************
 *
 * Asigna los valores del titulo, la informacion, la ruta y la duracion
 * 
 * @param[in]  nombre        string con el titulo de la cancion
 * @param[in]  inf           string con la informacion de la cancion
 * @param[in]  ubicacion     string con la ruta de la cancion
 * @param[in]  tempo         tiempo con la duracion de la cancion
 * @return no devuelve nada
 *
 */ /********************************************************************************/
 
 void Media::EstablecerMedia(string nombre,string inf,string ubicacion, Tiempo tempo)
 {
 	titulo = nombre;
 	informacion = inf;
 	ruta = ubicacion;
 	duracion = tempo;
 	return;
 }
 
  /**** void Media::EstablecerTitulo (string nombre) **************************/ /*
 *
 * Asigna los valores del titulo
 * 
 * @param[in] nombre string con el titulo de la cancion
 *
 * @return no devuelve nada
 *
 */ /********************************************************************************/
 
 void Media::EstablecerTitulo (string nombre)
 {
 	titulo = nombre;
 	return;
 }
 
/**** void Media::EstablecerInformacion (string inf) **************************/ /*
 *
 * Asigna los valores de la informacion
 * 
 * @param[in] inf string con la informacion de la cancion
 *
 * @return no devuelve nada
 *
 */ /********************************************************************************/
 
 void Media::EstablecerInformacion (string inf)
 {
 	informacion = inf;
 	return;
 }
 
 /**** void Media::EstablecerRuta (string ubicacion) **************************/ /*
 *
 * Asigna los valores de la ruta
 * 
 * @param[in] ubicacion string con la ruta de la cancion
 *
 * @return no devuelve nada
 *
 */ /********************************************************************************/
 
 void Media::EstablecerRuta (string ubicacion)
 {
 	ruta = ubicacion;
 	return;
 }

 /**** void Media::EstablecerTiempo (Tiempo tempo) **************************/ /*
 *
 * Asigna los valores de la duracion de la cancion
 * 
 * @param[in] tempo tiempo con la duracion de la cancion
 *
 * @return no devuelve nada
 *
 */ /********************************************************************************/
 
 void Media::EstablecerTiempo (Tiempo tempo)
 {
 	duracion = tempo;
 	return;
 } 
/**** string Media::DevuelveTitulo () **************************/ /*
 *
 * Devuelve el titulo
 * 
 *
 */ /********************************************************************************/
 
 string Media::DevuelveTitulo()
 {
 	return titulo;
 }
 
/**** string Media::DevuelveInformacion () **************************/ /*
 *
 * Devuelve la informacion
 * 
 *
 */ /********************************************************************************/ 
 
 string Media::DevuelveInformacion()
 {
 	return informacion;
 }
 
/**** string Media::DevuelveRuta () **************************/ /*
 *
 * Devuelve la ruta
 * 
 *
 */ /********************************************************************************/ 
 
 string Media::DevuelveRuta()
 {
 	return ruta;
 }
 
/**** Tiempo Media::DevuelveTiempo () **************************/ /*
 *
 * Devuelve el tiempo
 * 
 *
 */ /********************************************************************************/
 
 Tiempo Media::DevuelveTiempo()
 {
 	return duracion;
 }
 
/**
 * Sobrecarga del operador >> para poder almacenar la informacion de un
 * stream en un Media.
 *
 * @param [in, out] iss  stream del que extraer la informacion de la Media
 * @param [in, out] m  Media en el que almacenar la informacion. 
 *
 *
 * return  El stream modificado
 */
 
 istream& operator >> (istream& is, Media& m)
 {
 	string titulo, informacion, ruta;
 	Tiempo duracion;
 	if (getline (is, titulo))
	 {
	 	getline (is, informacion);
	 	getline (is, ruta);
	 	is >> duracion;
	 	m.EstablecerMedia(titulo,informacion,ruta,duracion);
	 }

 	return is;
 }
 
/**
 * Sobrecarga del operador << a para poder mostrar la informacion de un
 * stream en una Media.
 *
 * @param [in, out] out  stream donde mostrara la informacion de la Media
 * @param [in] m  Media en el que almacenar la informacion. 
 *
 *
 * return  El stream modificado
 */ 
 
 ostream& operator << (ostream& out, Media m)
 {
 	out << m.titulo << endl;
 	out << m.informacion << endl;
 	out << m.ruta << endl;
 	out << m.duracion << endl;
 	return out;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
