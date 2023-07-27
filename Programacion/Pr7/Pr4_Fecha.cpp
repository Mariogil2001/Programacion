
/******* Fecha.cpp *****************************************************/ /**
 *
 * @file Pr4_Fecha.cpp
 *
 * Implementacion de los metodos de la clase Fecha
 *
 * @version 1.0
 * @author Mario Gil Domingo
 * @author Luis Razvan Petrisor
 * @date 09/03/2022
 *  
 ***************************************************************************/

#include "Pr4_Fecha.h"

// Implementacion de los metodos publicos

/**
 * Constructor por defecto de la clase.
 */
Fecha::Fecha()
{
    dia = 1;
    mes = 1;
    anyo = 1970;
}

/**
 * Metodo para iniciar los valores del dia, mes y anyo de la fecha.
 *
 * @param [in] dia_ Entero referente al dia de la fecha
 * @param [in] mes_ Entero referente al mes de la fecha
 * @param [in] anyo_ Entero referente al anyo de la fecha
 *
 * @retval true Los valores se han asignado correctamente porque conforman una
 *             fecha correcta
 * @retval false No se han asignado los valores porque los valores no conforman
 *              una fecha correcta
 */
bool Fecha::AsignarValores(int dia_, int mes_, int anyo_)
{
    bool ok;
    
    if (FechaValida(dia_, mes_, anyo_))
    {
        ok = true;
        
        dia = dia_;
        mes = mes_;
        anyo = anyo_;
    }
    else
        ok = false;
        
    return ok;
}

/**
 * Metodo para consultar el dia de la fecha.
 *
 * @return  El dia de la fecha
 */
int Fecha::DevuelveDia() const
{
    return dia;
}

/**
 * Metodo para consultar el mes de la fecha.
 *
 * @return  El mes de la fecha
 */
int Fecha::DevuelveMes() const
{
    return mes;
}

/**
 * Metodo para consultar el anyo de la fecha.
 *
 * @return  El anyo de la fecha
 */
int Fecha::DevuelveAnyo() const
{
    return anyo;
}

/**
 * Sobrecarga del operador << a traves de una funcion 'friend' de la clase
 * para poder 'mostrar' la información de una fecha en un stream.
 *
 * @param [in, out] out  stream en el que depositar la informacion de la fecha
 * @param [in] f  Fecha a depositar en el stream. Se pasa por referencia
 *                constante para evitar realizar la copia
 *
 * @return  El stream modificado
 */
ostream & operator<<(ostream & out, const Fecha & f)
{
    out.fill('0');
    out.width(2);
    out << f.dia << '/';
    out.fill('0');
    out.width(2);
    out << f.mes << '/';
    out.fill('0');
    out.width(4);
    out << f.anyo;
    
    return out;
}

/**
 * Sobrecarga del operador >> a traves de una funcion 'friend' de la clase
 * para poder leer la informacion de una fecha desde un stream.
 * Si la fecha del stream no es correcta, la asignacion de la nueva fecha no
 * se produce.
 * El formato de entrada de la fecha seran tres enteros separados por un solo
 * caracter.
 * Ejemplos: 10 3 2022
 *           10/03/2022
 *           10-03-2022
 *
 * @param [in, out] in  stream del que extraer la informacion de la fecha
 * @param [out] f  Fecha a rellenar con la informacion extraida desde el stream
 *
 * @return  El stream modificado
 */
istream & operator>>(istream & in, Fecha & f)
{
    int dia_, mes_, anyo_;
    
    in >> dia_;
    in.ignore();
    in >> mes_;
    in.ignore();
    in >> anyo_;
    in.ignore();

    f.AsignarValores(dia_, mes_, anyo_);
    
    return in;
}

// Implementacion de los metodos auxiliares privados

/**
 * Comprueba que la terna de enteros conforman una fecha válida desde el anyo
 * -45.
 *
 * @param [in] dia_  dia de la fecha
 * @param [in] mes_  mes de la fecha
 * @param [in] anyo_  anyo de la fecha
 *
 * @retval  true  La terna conforma una fecha valida
 * @retval  false  La terna NO conforma una fecha valida
 */
bool Fecha::FechaValida(int dia_, int mes_, int anyo_)
{
    bool ok;
    
    if ((0 < dia_ && dia_ <= DiasMes(mes_, anyo_))
        && (0 < mes_ && mes_ <= 12))
        ok = true;
    else
        ok = false;
        
    return ok;
}

/**
 * Nos dice los dias que tiene el mes pasado como parametro.
 *
 * @param [in] mes_  mes del que queremos determinar cuantos dias tiene
 * @param [in] anyo_  anyo de la fecha para saber si es un anyo bisiesto o no
 *                para los dias del mes de febrero
 *
 * @return  El numero de dias del mes. Si el mes no es valido devolvera -1
 */
int Fecha::DiasMes(int mes_, int anyo_)
{
    int dias_mes;
    
    switch(mes_)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dias_mes = 31;
            
            break;
            
        case 4:
        case 6:
        case 9:
        case 11:
            dias_mes = 30;
            
            break;
            
        case 2:
            if (Bisiesto(anyo_))
                dias_mes = 29;
            else
                dias_mes = 28;

            break;
            
        default:
            dias_mes = -1;
    }
    
    return dias_mes;
}

/**
 * Determina si un anyo pasado como parametro es o no bisiesto
 *
 * @pre El valor de 'anyo_' debe ser un valor correcto, es decir, mayor que -40
 *      (fecha de aparicion de los anyos bisiestos) y distinto de cero.
 *
 * @param [in] anyo_  Entero que representa al anyo de estudio
 *
 * @retval  true  El anyo estudiado es bisiesto
 * @retval  false  El anyo estudiado NO es bisiesto
 */
bool Fecha::Bisiesto(int anyo_)
{
    bool es_bisiesto;
    
    // Si es menor que 1580 se aplica el calendario Juliano
    if (anyo_ < 1580)
        if (anyo_ > 0)
            if (anyo_ % 4 == 0)
                es_bisiesto = true;
            else
                es_bisiesto = false;
        else
            if ((anyo_ - 1) % 4 == 0)
                es_bisiesto = true;
            else
                es_bisiesto = false;
    // Si es mayor o igual a 1580 se aplica el calendario Gregoriano
    else
        // Los anyos seculares multiplos de 400 SON bisiestos
        if (anyo_ % 400 == 0)
            es_bisiesto = true;
        else
            // Los anyos seculares no multiplos de 400 NO son bisiestos
            if (anyo_ % 100 == 0)
                es_bisiesto = false;
            else
                // El resto de anyos SON bisiestos si son multiplos de 4
                if (anyo_ % 4 == 0)
                    es_bisiesto = true;
                // Si no son multiplos de 4 NO son bisiestos
                else
                    es_bisiesto = false;
                    
    return es_bisiesto;
}
/**
 * Sobrecarga del operador > a traves de una funcion 'friend' de la clase
 * para poder comparar la informacion de dos fechas.
 * Si la fecha 1 es posterior que la fecha 2, el booleano sera true.
 *
 * El formato de entrada de la fecha seran tres enteros separados por un solo
 * caracter.
 * Ejemplos: 10 3 2022
 *           10/03/2022
 *           10-03-2022
 *
 * @param [in]  la informacion de la fecha 1
 * @param [in]  la informacion de la fecha 2
 *
 * @return bool de si la fecha 1 es mayor que la fecha 2
 *
 */
 bool operator> ( Fecha f1, Fecha f2)
{
	bool aux = false;
	// Si anyo fecha 1 > anyo fecha 2, no hace falta comparar mas
	if (f1.DevuelveAnyo() > f2.DevuelveAnyo())
		aux = true;
	// Si el anyo es el mismo, comprobaremos mes
	else if (f1.DevuelveAnyo() == f2.DevuelveAnyo())
	{
	// Si mes fecha 1 > mes fecha 2, no hace falta comparar mas		
		if (f1.DevuelveMes() > f2.DevuelveMes())
			aux = true;
	// Si el mes es el mismo, comprobaremos dia			
		else if (f1.DevuelveMes() == f2.DevuelveMes())
		{
			if (f1.DevuelveDia() > f2.DevuelveDia())
				aux = true;
		}	
	}
	return aux;
}
/**
 * Sobrecarga del operador < a traves de una funcion 'friend' de la clase
 * para poder comparar la informacion de dos fechas.
 * Si la fecha 1 es anterior que la fecha 2, el booleano sera true.
 *
 * El formato de entrada de la fecha seran tres enteros separados por un solo
 * caracter.
 * Ejemplos: 10 3 2022
 *           10/03/2022
 *           10-03-2022
 *
 * @param [in]  la informacion de la fecha 1
 * @param [in]  la informacion de la fecha 2
 *
 * @return bool de si la fecha 1 es anterior a
  la fecha 2
 *
 */
 bool operator< ( Fecha f1, Fecha f2)
{
	bool aux = false;
	// Si anyo fecha 1 > anyo fecha 2, no hace falta comparar mas
	if (f2.DevuelveAnyo() > f1.DevuelveAnyo())
		aux = true;
	// Si el anyo es el mismo, comprobaremos mes
	else if (f1.DevuelveAnyo() == f2.DevuelveAnyo())
	{
	// Si mes fecha 1 > mes fecha 2, no hace falta comparar mas		
		if (f2.DevuelveMes() > f1.DevuelveMes())
			aux = true;
	// Si el mes es el mismo, comprobaremos dia			
		else if (f1.DevuelveMes() == f2.DevuelveMes())
		{
			if (f2.DevuelveDia() > f1.DevuelveDia())
				aux = true;
		}	
	}
	return aux;
}
