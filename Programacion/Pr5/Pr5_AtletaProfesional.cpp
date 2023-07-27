
 /******* Pr5_AtletaProfesional.cpp ****************************************************/ /**
 *
 * @file Pr5_AtletaProfesional.cpp
 *
 * Implementación de los métodos de la clase Atleta Profesional
 *
 * @version 1.0
 * @author Mario Gil Domingo, Luis Razvan Petrisor
 * @date 08/04/2022
 *  
 ***************************************************************************/
 #include "separar.h"
 #include "Pr5_AtletaProfesional.h"
 #include <vector>


 /**
 * Constructor por defecto de la clase AtletaProfesional.
 */
 AtletaProfesional::AtletaProfesional()
 :Atleta()
 {}
  /*** AtletaProfesional::DevuelveMarcas() ********************************************/ /**
 *
 * Metodo para consultar las marcas del Atleta Profesional.
 *
 * @return vector de floats con las marcas
 *
 */ /**********************************************************************/

 vector<float> AtletaProfesional::DevuelveMarcas() const
 {
 	return tiempos;
 }
   /*** AtletaProfesional::DevuelveMejorMarcas() ********************************************/ /**
 *
 * Sirve para obtener la mejor marca 
 * o tiempo que ha obtenido ese atleta profesional.
 * 
 * @return la mejor marca de ese atleta.
 *
 */ /**********************************************************************/
 float AtletaProfesional::DevuelveMejorMarca() const
 {
 	float mejormarca;
 	mejormarca = tiempos[0];
 	for(unsigned int i = 1; i < tiempos.size(); i++)
	{
	 	if (mejormarca > tiempos[i])
	 		mejormarca = tiempos[i];	
	}
 	return mejormarca;
 }
 
 /*** ifstream & LeerDeFichero (ifstream & ) ************************/ /**
 *
 *  Lectura de un fichero mediante ifstream, el formato de entrada del atleta profesional es
 *  codigo;nombre;pais;especialidad;marca(1);marca(2)...marca(n)
 * Obtendremos las marcas como una cadena, ya que no sabemos cuantas marcas hay
 * y luego mediante la funcion SepararFloats de "separar.h" obtenemos un vector con los tiempos
 * que almacenamos en el vector<float> tiempos;
 * 
 *  @return  Si quedan mas atletas profesionales por leer
 *
 */ /**********************************************************************/
 
 bool AtletaProfesional::LeerDeFichero(ifstream & fich_in)
 {
 	bool ok;
 	string cadenamarcas;
 	string codigo, nombre, pais, especialidad;
    if ( getline (fich_in, codigo,';') )
    {
        getline (fich_in,nombre,';');
        getline (fich_in, pais,';');    
        getline (fich_in, especialidad,';'); 
	 	getline(fich_in, cadenamarcas); // Obtenemos la cadena con los tiempos
	 	tiempos = SepararFloat(cadenamarcas); // Funcion de separar.h
	 	AsignarValores(codigo,nombre,pais,especialidad);
	 	ok = true;
	 }
	 else
	 	ok = false;
	 return ok;	
 }
 /*** AtletaProfesional::Mostrar() ************************/ /**
 *
 *  Muestra por pantalla el Atleta profesional y sus tiempos
 *  Formato al mostrar:
 * id: KU812080 - AVELLAN UGIA, ANA PAZ
 * Nacionalidad: ESP
 * Especialidad: 100m (M)
 * 11.6138 10.603 11.4061 11.4797 11.7428
 *
 *  @return 
 *
 */ /**********************************************************************/
 void AtletaProfesional::Mostrar()
 {
	cout << "id: " << DevuelveCodigo() << " - " << DevuelveNombre() << endl;
	cout << "Nacionalidad: " << DevuelvePais() << endl;
	cout << "Especialidad: " << DevuelveEspecialidad() << endl;
	for (unsigned int i = 0; i < tiempos.size(); i++)
		cout << tiempos[i] << " "; // Como son varios tiempos le hacemos un for
	cout << endl;	
 	
 	return;
 }
 
  /*** AtletaProfesional::IncorporarMarca(float) ************************/ /**
 *
 *  @param [in] marca float del valor que se quiere añadir a las marcas
 * 
 * Funcion que anyade al final de la lista de tiempos una marca
 *
 *  @return 
 *
 */ /**********************************************************************/
 
 void AtletaProfesional::IncorporarMarca(float marca)
 {
 	tiempos.push_back(marca);
 	return;
 }
