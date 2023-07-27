
/******* Fecha.h ******************************************************/ /**
 *
 * @file Pr4_Fecha.h
 *
 * Fichero de cabecera de la clase Fecha
 *
 * @version 1.0
 * @author Mario Gil Domingo
 * @author Luis Razvan Petrisor
 * @date 11/05/2022
 *  
 ***************************************************************************/

#ifndef _FECHA_H_
#define _FECHA_H_

#include <iostream>
using namespace std;

/**
 * Clase para guardar y manipular de forma sencilla fechas
 */
class Fecha
{
    public:
        Fecha();
        bool AsignarValores(int, int, int);
        int DevuelveDia() const;
        int DevuelveMes() const;
        int DevuelveAnyo() const;
        friend ostream & operator<<(ostream & out, const Fecha & f);
        friend istream & operator>>(istream & in, Fecha & f);
		friend bool operator> ( Fecha, Fecha);
        friend bool operator< ( Fecha, Fecha);
        
    private:
        int dia;    ///< Dia de la fecha
        int mes;    ///< Mes de la fecha
        int anyo;   ///< Anyo de la fecha
        
        /// Funciones auxiliares privadas
        bool FechaValida (int d, int m, int a);
        int DiasMes (int m, int a);
        bool Bisiesto (int a);
};

#endif
