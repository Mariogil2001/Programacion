/******* Pr6_Carta.cpp *************************************************/ /**
 *
 * @file Pr6_Carta.cp
 *
 * Implementación de los métodos de la clase Carta
 *
 * @version 1.0
 * @author Jesús Albert
 * @author Miguel A. Gamón
 * @date 19/04/2022
 *  
 ***************************************************************************/

#include "Pr6_Carta.h"

/**************************************************************************/ /**
 *
 *  Construye una carta y asigna valores iniciales a los atributos:
 *  1 de Oros ('O').
 *
 */ /*************************************************************************/
using namespace std;

Carta::Carta ()
:palo ('O'), numero (1)
{}

/**************************************************************************/ /**
 *
 *  Construye una carta y asigna valores a los atributos a partir de los
 *  parámetros.
 *  @param  [in]	p	palo de la carta
 *  @param  [in]	n	número de la carta
 *
 */ /*************************************************************************/
Carta::Carta (char p, int n)
{
    switch ( p )
    {
        case 'O': case 'C':
        case 'E': case 'B':
            palo = p;
        default:
            cerr << "Carta mal inicializada. Id. palo incorrecto." << endl;
    }
    if ( ( n>=1 ) && ( n <= 12 ) )
        numero = n;
    else
        cerr << "Carta mal inicializada. Numero incorrecto." << endl;
}

/**********************************************************************/ /**
 *
 *  Asigna el palo de la carta. Los valores correctos para asignar el
 *  palo deben ser ('O', 'C', 'E', 'B').
 *
 *  @param  [in]	p	palo de la carta
 *
 */ /**********************************************************************/
void Carta::EstablecePalo (char p)
{
    switch ( p )
    {
        case 'O': case 'C':
        case 'E': case 'B':
            palo = p;
            break;
        default:
            cerr << "Id. palo incorrecto." << endl;
    }
}

/**********************************************************************/ /**
 *
 *  Asigna el número de la carta. Los valores correctas para asignar el
 *  número deben del 1 al 12.
 *
 *  @param  [in]	n	número de la carta
 *
 */ /**********************************************************************/
void Carta::EstableceNumero (int n)
{
    if ( ( n>=1 ) && ( n <= 12 ) )
        numero = n;
    else
        cerr << "Numero incorrecto." << endl;
}

/**********************************************************************/ /**
 *
 *  Devuelve el palo de la carta.
 *
 *  @return  Palo de la carta
 *
 */ /**********************************************************************/
char Carta::DevuelvePalo ()
{
    return palo;
}

/**********************************************************************/ /**
 *
 *  Devuelve el número de la carta.
 *
 *  @return  Número de la carta
 *
 */ /**********************************************************************/
int Carta::DevuelveNumero ()
{
    return numero;
}

/**********************************************************************/ /**
 *
 * Sobrecarga del operador << para sacar la información de la carta
 * por un stream (fichero, consola, ...).
 *
 * @param [in, out] out	stream por el que vamos a sacar la información.
 * @param [in] 		c  	objeto Carta que queremos sacar por el stream.
 *
 * @return  El stream modificado tras su utilización
 *
 */ /**********************************************************************/
ostream& operator<< (ostream& out, Carta c)
{
    out << c.numero << "/";
    switch ( c.palo )
    {
        case 'O':
            cout << "Oros";
            break;
        case 'C':
            cout << "Copas";
            break;
        case 'E':
            cout << "Espadas";
            break;
        case 'B':
            cout << "Bastos";
            break;
    }
    return out;
}
/**********************************************************************/ /**
 *
 * Sobrecarga del operador > para comparar cartas con el palo y el numero
 * 
 *
 * @param [in] 		c  	objeto Carta que queremos comparar.
 * @param [in]		c1 objeto Carta que queremos comparar.
 *
 * @return  True si es mayor y false si es menor.
 *
 */ /**********************************************************************/
bool operator> (Carta c, Carta c1)
{
	bool aux = false;
	
	if (c.DevuelveNumero()>c1.DevuelveNumero())
		aux = true;
	else if (c.DevuelveNumero()==c1.DevuelveNumero())
	{
		if(c.DevuelvePalo()=='O')
			aux = true;
		else if (c.DevuelvePalo()=='C' && c1.DevuelvePalo()!='O')
			aux = true;
		else if (c.DevuelvePalo()=='E' && c1.DevuelvePalo()!='O' && c1.DevuelvePalo()!='C')
			aux = true;
	}
		
	return aux;	
}

bool operator< (Carta c, Carta c1)
{
	bool aux = false;
	
	if (c1.DevuelveNumero() > c.DevuelveNumero())
		aux = true;
	else if (c.DevuelveNumero() == c1.DevuelveNumero())
	{
		if (c1.DevuelvePalo()=='O')
			aux = true;
		else if (c1.DevuelvePalo()=='C' && c.DevuelvePalo()!= 'O')
			aux = true;
		else if (c1.DevuelvePalo()=='E' && c.DevuelvePalo() != 'O' && c1.DevuelvePalo()!='C')
			aux = true;
	}
	return aux;	
}
