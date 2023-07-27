/******* Pr6_Carta.h ***************************************************/ /**
 *
 * @file Pr6_Carta.h
 *
 * Fichero de cabecera de la clase Carta
 *
 * @version 1.0
 * @author Jes�s Albert
 * @author Miguel A. Gam�n
 * @date 19/04/2022
 *  
 ***************************************************************************/
  
#include <iostream>

using namespace std;

#ifndef _CARTA_H_
#define _CARTA_H_

/**
 * @brief Clase para el manejo de cartas
 *
 * Interfaz de la clase Carta, que representa cartas de la baraja espa�ola
 * identificadas por un palo (oros, copas, espadas y bastos) y por un n�mero
 * en el rango 1 a 12.
 */

class Carta
{
    public:
        // Constructor por defecto
        Carta ();
        
        // Constructor indicando el palo (char) y el n�mero (int) de la carta
        Carta (char, int);
        
        // Modificar el palo de la carta
        void EstablecePalo (char);
        
        // Modificar el n�mero de la carta
        void EstableceNumero (int);
        
        // Obtener el palo de la carta
        char DevuelvePalo ();
        
        // Obtener el n�mero de la carta
        int DevuelveNumero ();
        
        // Sobrecarga del operador de salida (<<)
        friend ostream& operator<< (ostream&, Carta);
        friend bool operator> ( Carta, Carta);
        friend bool operator< ( Carta, Carta);


    private:
        // El palo de la carta ('O', 'C', 'E', 'B')
        char palo;
        
        // El n�mero de la carta (1 - 12)
        int numero;
};

#endif
