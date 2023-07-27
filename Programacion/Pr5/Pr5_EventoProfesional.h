
/******* Pr5_EventoProfesional.h ***************************************************/ /**
 *
 * @file Pr5_EventoProfesional.h
 *
 * Fichero de cabecera de la clase EventoProfesional
 *
 * @version 1.1
 * @author Mario Gil Domingo, Luis Razvan Petrisor
 * @date 08/04/2022
 *
 *  
 ***************************************************************************/

 #ifndef _EVENTOPROFESIONAL_H_
 #define _EVENTOPROFESIONAL_H_

 #include "Pr4_Evento.h"
 #include "Pr5_AtletaProfesional.h"
 
/**
 * @brief Clase para el manejo de EventoProfesional
 *
 * Clase para manejar la informacion de la
 * información del evento profesional donde participan
 * atletas profesionales en una competición de atletismo.
 * La clase evento profesional hereda de la clase evento.
  */
  
class EventoProfesional : public Evento
{

    public: 
        // Constructor por defecto
        EventoProfesional();
        // Devuelve la marca minima
		float DevuelveMarcaMinima() const;
		// Lo mismo que asignar valores al evento, pero añadiendo una marca minima
		void AsignarValores(string,string,string,string, Fecha, string, string, float);
		//Invita al atleta profesional
		void InvitarAtleta (AtletaProfesional);
		void GuardarAtletas (ostream &) const;
		friend ostream & operator << (ostream & out, const EventoProfesional & e);

	    private:       
    	// Atributos propios de un evento profesional:
    	vector <AtletaProfesional> atletapro;
        float marcamin;
		
};

#endif
