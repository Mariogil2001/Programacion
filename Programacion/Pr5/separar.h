/******* separar.h *****************************************************/ /**
 *
 * @file separar.h
 *
 * Funciones para obtener los elementos de una cadena separados por ";"
 *
 * @version 1.0
 * @author Jesus Albert
 * @date 17/03/2022
 *  
 ***************************************************************************/

#ifndef _SEPARAR_H_
#define _SEPARAR_H_

#include <string>
#include <sstream>
#include <vector>
using namespace std;

/**
 * Funcion que obtiene los elementos str contenidos en una cadena 
 * separados por ";".
 *
 * Ej: e = "a;b;c", return {"a", "b", "c"}
 *
 * @param [in] e Cadena a separar
 * @return  vector de string con los diferentes elementos contenidos en e
 */
vector<string> SepararStr(string e)
{
    vector<string> res;     ///< vector resultante
    stringstream aux(e);    ///< stream en memoria para leer como un archivo con getline
    string x;               ///< elemento extraido de e
    
    while ( getline(aux, x, ';') )
        res.push_back(x); //incorporar al final del vector
        
    return res;
}

/**
 * Funcion que obtiene los valores float contenidos en una cadena
 * separados por ";".
 *
 * Ej: e = "1.2;3.14;65.3", return {1.2, 3.14, 65.3}
 *
 * @param [in] e Cadena a separar
 * @return  vector de float con los diferentes valores contenidos en e
 */
vector<float> SepararFloat(string e)
{
    vector<float> res;      ///< vector resultante
    stringstream aux(e);    ///< stream en memoria para leer como un archivo con getline
    string x;               ///< elemento extraido de e
    
    while ( getline(aux, x, ';') )
        res.push_back(stof(x)); //incorporar al final del vector
        
    return res;
}

#endif
