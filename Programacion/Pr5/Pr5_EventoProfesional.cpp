
 /******* Pr5_EventoProfesional.cpp ****************************************************/ /**
 *
 * @file Pr5_EventoProfesional.cpp
 *
 * Implementación de los métodos de la clase Evento Profesional
 *
 * @version 1.0
 * @author Mario Gil Domingo, Luis Razvan Petrisor
 * @date 08/04/2022
 *  
 ***************************************************************************/
 #include "Pr5_EventoProfesional.h"

 using namespace std;

 /**
 * Constructor por defecto de la clase AtletaProfesional.
 */
 
 EventoProfesional::EventoProfesional()
 :Evento()
 {}
 
  /*** EventoProfesional::DevuelveMarcaMinima() ********************************************/ /**
 *
 * Metodo para consultar las marca minima del Evento Profesional.
 *
 * @return marcamin float con la marca minima para participar en el evento
 *
 */ /**********************************************************************/
 
 float EventoProfesional::DevuelveMarcaMinima() const
 {

 	return marcamin;
 }
 
  /*** EventoProfesional::AsignarValores(string,string,string,string,Fecha,string,string,float) *****
 *
 * Metodo para asignar valores al evento profesional
 *
 * @param [in] c1 codigo del evento
 * @param [in] c2 nombre del evento
 * @param [in] c3 ciudad del evento
 * @param [in] c4 pais del evento
 * @param [in] fec tipo fecha con la fecha del evento
 * @param [in] c5 especialidad del evento
 * @param [in] c6 tipo de evento del evento
 * @param [in] t tiempo minimo para participar en el evento
 *
 * @return 
 *
 */ /**********************************************************************/
 
 void EventoProfesional::AsignarValores(string c1, string c2, string c3, string c4, Fecha fec, string c5, string c6, float t)
 {
 	Evento::AsignarValores(c1,c2,c3,c4,fec,c5,c6);
 	marcamin = t;
 	return;
 }
 
   /*** EventoProfesional::GuardarAtletas() ********************************************/ /**
 *
 * Guarda en fichero mediante 'ostream' la informacion de los atletas
 * con su mejor marca.
 * Formato:
 * codigo;nombre;pais;especialidad;mejormarca
 *
 * @return 
 *
 */ /**********************************************************************/
 
 void EventoProfesional::GuardarAtletas(ostream & f) const
 {
	for (unsigned int i = 0; i < atletapro.size(); i++)
	{
		f << atletapro[i].DevuelveCodigo()<<";";
	 	f << atletapro[i].DevuelveNombre() << ";";
	 	f << atletapro[i].DevuelvePais() <<";" ;
	 	f << atletapro[i].DevuelveEspecialidad() <<";";
	 	f << atletapro[i].DevuelveMejorMarca() << endl;

	}
 	return;
 }
 
    /*** EventoProfesional::InvitarAtleta(AtletaProfesional) ********************************************/ /**
 *
 * @param [in] atleta tipo AtletaProfesional
 *
 * Anyade al final de la lista de atletas profesionales el atleta invitado
 * mediante la funcion push_back
 *
 * @return 
 *
 */ /**********************************************************************/
 
 void EventoProfesional::InvitarAtleta(AtletaProfesional atleta)
 {
	atletapro.push_back(atleta);
 	return;
 }

 /**
 * Sobrecarga del operador << a traves de una funcion 'friend' de la clase
 * para poder 'mostrar' la informacion del evento profesional en un stream.
 *
 * @param [in, out] out  stream en el que depositar la informacion de la fecha
 * @param [in] 		e    EventoProfesional a depositar en el stream. Se pasa por referencia
 *               	     constante para evitar realizar la copia.
 * Llamamos al la funcion DevuelveLocalizacion para obtener la ciudad 
 * y el pais del evento profesional
 *
 * @return  El stream modificado
 */
 
  ostream & operator << (ostream & out, const EventoProfesional & e)
 {
 	string ciudad,pais;
 	e.DevuelveLocalizacion(ciudad,pais);
 	out << "############################################################" << endl;
 	out << "# " << e.DevuelveCodigo() << " " << e.DevuelveNombre() << " (" << e.DevuelveEspecialidad() << ") " << endl;
 	out << "# " << ciudad <<" (" << pais <<") " << " - " << e.DevuelveFecha() << " - " ;
 	if(e.EsInternacional())
 		out << "(Internacional)";
 	else
	 	out << "(Nacional)";
	out << endl;
	out << "# Marca minima requerida: " << e.marcamin << " seg." << endl;
	out << "############################################################" << endl; 	
 	out << endl;
 	for (unsigned int i = 0; i < e.EventoProfesional::atletapro.size(); i++)
	 {
	 	out << e.atletapro[i].DevuelveNombre() << " (" << e.atletapro[i].DevuelvePais();
		out << ") " << e.atletapro[i].DevuelveMejorMarca() << " seg." << endl;
	 }	 
	return out;   
 }
 
