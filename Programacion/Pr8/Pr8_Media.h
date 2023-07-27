/****** Pr8_Media.h **************************************************/ /**
 *
 * @file Pr8_Media.h
 *
 * @brief Fichero de cabecera de la clase Media
 *
 * @version 1.0
 * @author Mario Gil Domingo
 * @author Luis Razvan Petrisor
 * @date 19-05-2022
 */ /**************************************************************************/

#ifndef _MEDIA_H_
#define _MEDIA_H_

#include <iostream>
#include "Pr8_Tiempo.h"

using namespace std;

/** Clase Media para la gestión de una lista de reproduccion */
class Media
{
    public:
        Media ();
		void EstablecerMedia (string,string,string,Tiempo);
		void EstablecerTitulo (string);	
        void EstablecerInformacion (string);
        void EstablecerRuta (string);
        void EstablecerTiempo (Tiempo);
        string DevuelveTitulo();
        string DevuelveInformacion();
        string DevuelveRuta();
        Tiempo DevuelveTiempo();
        
        //sobrecargas
        friend istream& operator>> (istream&, Media&); 
        friend ostream& operator<< (ostream&, Media);
  
        
    private:
		string titulo;
		string informacion;
		string ruta;
		Tiempo duracion;
};

#endif
