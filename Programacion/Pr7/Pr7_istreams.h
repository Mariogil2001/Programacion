/******* Pr7_istreams.h ******************************************************/ /**
 *
 * @file Pr7_istreams.h
 *
 * Implementación de flujos de entrada para las clases Lote y Almacen
 *
 * @version 1.0
 * @author Ignacio García
 * @date 30/04/2022
 *
 ***************************************************************************/

#ifndef _ISTREAMS_H_
#define _ISTREAMS_H_


#include<istream>
#include<sstream>

#include"Pr4_Fecha.h"
#include"Pr7_Lote.h"
#include"Pr7_Almacen.h"

using namespace std;

/**
 * Sobrecarga del operador >> a para poder almacenar la informacion de un
 * stream en un Lote.
 *
 * @param [in, out] ins  stream del que extraer la informacion del lote
 * @param [in] lot  Lote en el que almacenar la información. Se pasa
 *                  por referencia para que resulte modificado.
 *
 * return  El stream modificado
 */
istream & operator>> (istream & ins, Lote & lot)
{
    string aux,ident;
    Fecha fc,fa;
    bool a;
    int m;
    
    if ( getline(ins,ident,';') )
    {
        getline(ins,aux,';');
        stringstream(aux) >> fc;
    
        getline(ins,aux,';');
        if (aux == "0")
            a = false;
        else
            a = true;
    
        getline(ins,aux,';');
        stringstream(aux) >> fa;
    
        getline(ins,aux);
        m = stoi(aux);
    
        lot.AsignaValores(ident,fc,a,fa,m);
    }
    return ins;
};

/**
 * Sobrecarga del operador >> a para poder almacenar la informacion de un
 * stream en un Almacen.
 *
 * @param [in, out] ins stream del que extraer la informacion del lote
 * @param [in] alm  Almacen en el que almacenar la información. Se pasa
 *                  por referencia para que resulte modificado.
 *
 * return  El stream modificado
 */
istream & operator>> (istream & ins, Almacen & alm)
{
    Lote l;
    
    while (ins >> l)
        alm.AlmacenarLote(l);

    return ins;
};

#endif
