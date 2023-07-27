
/******* “Pr5_AtletaProfesional.h ***************************************************/ /**
 *
 * @file “Pr5_AtletaProfesional.h
 *
 * Fichero de cabecera de la clase AtletaProfesional
 *
 * @version 1.1
 * @author Mario Gil Domingo, Luis Razvan Petrisor
 * @date 08/04/2022
 *
 *  
 ***************************************************************************/

#ifndef _ATLETAPROFESIONAL_H_
#define _ATLETAPROFESIONAL_H_

 #include <vector>
 #include "Pr3_Atleta.h"

using namespace std;

/**
 * @brief Clase para el manejo de AtletaProfesional
 *
 * Representa a un atleta profesional,
 * que es un tipo derivado del tipo Atleta.
 *
 */

class AtletaProfesional : public Atleta
{
    public:
    	AtletaProfesional();
        // Añade el tiempo t al conjunto de tiempos realizados por el atleta a.
		void IncorporarMarca(float);
		// Operaciones para devolver información de los tiempos del atleta.
		vector <float> DevuelveMarcas() const;
		// Devuelve el mejor tiempo
		float DevuelveMejorMarca () const;
		//Leer Atletas de un fichero
		bool LeerDeFichero(ifstream &);
		// Mostrar el Atleta profesional
        void Mostrar();

    private:       
        // Atributos propios de un atleta profesional:
        vector <float> tiempos;
        // tiempos es un vector cuyos elementos son de tipo float, sirve para incorporar las marcas de tiempo
	 
};

#endif
