#include "Evento.h"
//#include "Atleta.h"
//#include "Pr4_Fecha.h"

using namespace std;

Evento::Evento()
{
	listatleta.num = 0;
	Codigo = "unknown";
	Nombre = "unknown";
	Ciudad = "unknown";
	Pais = "unknown";
	Especialidad = "unknown";
	TipoEvento = "Internacional";
}

 ostream & operator << (ostream & out, const Evento & e)
 {
 	out << e.Codigo << " " << e.Nombre << " (" << e.Especialidad << ") " << endl;
 	out << e.Ciudad << " (" << e.Pais << ") - " << e.fecha << " - (" << e.TipoEvento <<")" << endl;
 
	return out;   
 }
 
 void Evento::AsignarValores(string c1, string c2, string c3, string c4, Fecha fec, string c5, string c6)
 {
 	Codigo = c1;
 	Nombre = c2;
 	Ciudad = c3;
 	Pais = c4;
 	fecha = fec;
 	Especialidad = c5;
 	TipoEvento = c6;
 	return;
 }
 
 void Evento::GuardarAtletas(ostream & f) const
 {
	for ( int i = 0; i < listatleta.num; i++)
	{
		f << listatleta.info[i].DevuelveCodigo()<<";";
	 	f << listatleta.info[i].DevuelveNombre() << ";";
	 	f << listatleta.info[i].DevuelvePais() <<";" ;
	 	f << listatleta.info[i].DevuelveEspecialidad()<< endl;
    }
    
 	return;
 }
 
 bool Evento::EsInternacional() const
 {
 	bool entrenaciones;
 	Evento e;
 	if (e.TipoEvento == "Internacional")
 		entrenaciones = true;
 	else
 		entrenaciones = false;
 	return entrenaciones;	
 }
 
 void Evento::InvitarAtleta(Atleta atlete)
 {
	listatleta.info[listatleta.num] = atlete;
	listatleta.num++; 	
 	return;
 }

 string Evento::DevuelveNombre() const
 {
 	return Nombre;
 }
 
 string Evento::DevuelveCodigo() const
 {
 	return Codigo;
 }
 
 string Evento::DevuelveEspecialidad() const
 {
 	return Especialidad;
 }
 
 Fecha Evento::DevuelveFecha() const
 {
 	return fecha;
 }
 
 void Evento::DevuelveLocalizacion(string& ciudad, string & pais) const
 {
 	ciudad = Ciudad;
 	pais  = Pais;
 	return;
 }
