/****** Pr6_JuegoCartas.cpp *****************************************************/ /**
 *
 * @file Pr6_JuegoCartas.cpp
 *
 * @brief Prácticas de Programación.
 *
 * Programa que implementa una baraja de cartas.
 *
 * @version 1.0
 * @author Mario Gil Domingo
 * @author Luis Razvan Petrisor
 *
 * @date 06/05/2022
 *
 */ /***************************************************************************/
 
#include <stdlib.h> 
#include <time.h>
#include <iostream>
#include <vector>
#include "Pr6_Carta.h"
#include "Pr6_Pila.h"

using namespace std;

/*
 * Una baraja es un vector de cartas
 *
 */
typedef vector<Carta> Baraja;

struct jugador
{
	Pila<Carta> Mazo;
	Pila<Carta> Ganadas;
	int puntuacion;
};

typedef vector<jugador> Jugador;

//Funciones
void IniciarBaraja (Baraja&);
void Barajar (Baraja&);
void RepartirCartas(Jugador&,Baraja&, int);
void InicializarJugadores (Jugador&, int);
void MostrarMazo (Jugador, unsigned int);
int  Comparar (Baraja, unsigned int);
void CartasAJugar (Jugador&);
void CartasGanadas (jugador&, Baraja);
void Puntuacion1 (Jugador&);
void Puntuacion2 (Jugador&);
void Puntuacion3 (Jugador&);
void Puntuacion4 (Jugador&);
void MostrarResultados (Jugador);

int main()
{
	Baraja b;
	Jugador j;
	unsigned int n;
	char opcion;
	
	// Crea la baraja
    IniciarBaraja (b);  
    // Baraja las cartas de la baraja
    Barajar (b);
	cout << "Introduce numero de los participantes ( 2, 3 o 4 ) " << endl;
	cin >> n;
	 
	//Inicializamos los jugadores para que no hayan errores inesperados
    InicializarJugadores (j,n);
	// Repartimos las cartas en base al numero de jugadores que haya
	RepartirCartas (j,b,n);
	// Mostramos el mazo (sus cartas) de cada jugador por pantalla	
	MostrarMazo(j,n);
    // Comparación de cartas    
    do
    {
    	CartasAJugar(j);
    	cout << "Desea continuar (s/n)? ";
    	cin >> opcion;    	    	
    	cout << endl;
    	for (unsigned int i = 0; i < n; i++)
		{
			cout << "Jugador " << i + 1 << " ha ganado las siguientes cartas: " << endl;
			cout << j[i].Ganadas << endl;
		}
//		MostrarMazo(j,n);
	}
	while (opcion == 's');
	
	Puntuacion1(j);
	Puntuacion2(j);
	Puntuacion3(j);
	Puntuacion4(j);
	MostrarResultados(j);

	return 0;
}


/**********************************************************************/ /**
 *
 *  Iniciar la baraja antes de empezar a jugar
 *  Se introducen todas las cartas en la baraja b, en el siguiente orden:
 *  12 cartas de oros, copas, espadas y bastos
 *
 *  @param  [in,out]  b  Baraja que se inicia
 *
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/
void IniciarBaraja (Baraja& b)
{
	Carta c;
	char palos[4] = {'O','C','E','B'};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			c.EstablecePalo(palos[i]);
			c.EstableceNumero(j);
			b.push_back(c);
		}
	}
}

/**********************************************************************/ /**
 *
 *  Barajar las cartas de la baraja
 *
 *  @param  [in,out]  b  Baraja
 *
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/
void Barajar (Baraja& b)
{
    Carta temp;
    int i, m;
    
    if (b.empty ())
		cout << "No hay cartas para barajar." << endl;
	else
	{    
	    srand (time (NULL) );
	    //Barajando, Intercambiando 1000 cartas
	    for (int k = 0; k < 1000; k++) 
		{
	        i = rand() % b.size ();
	        m = rand() % b.size ();
	        temp = b[i];
	        b[i] = b[m];
	        b[m] = temp;
	    }
	}
}
/**********************************************************************/ /**
 *
 *  Repartir las cartas de la baraja a cada jugador 'k'
 *  cogiendo la ultima carta de la baraja 'b' y apilandola en el mazo del jugador
 *  y con pop_back eliminamos esa carta del mazo total. Esto se realiza mientras hayan
 * cartas en el mazo.
 *
 *  @param  [in,out]  b  Baraja, paso por referencia
 *  @param  [in,out] j Jugador, vector de jugadores
 *	@param  [in] n entero, numero de jugadores
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/
void RepartirCartas (Jugador& j, Baraja& b, int n)
{
	Carta c;

	while(b.size()>0)
	{
		for (int k = 0; k < n; k++)
		{
			c = b.back();
			j[k].Mazo.Apilar(c);
			b.pop_back();
		}
	}
	return;
}
/**********************************************************************/ /**
 *
 *  Inicializamos los jugadores en base al numero que haya
 *
 *  @param  [in,out] j Jugador, vector de jugadores
 *	@param  [in] n entero, numero de jugadores
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/
void InicializarJugadores (Jugador& j, int n)
{
	jugador player;
	for (int i = 0; i < n; i++)
	{
		j.push_back(player);
		j[i].puntuacion = 0;
	}
	return;
}

/**********************************************************************/ /**
 *
 *  Mostramos el mazo (sus cartas) de cada jugador por pantalla
 *  mediante la sobrecarga de operador ya creada antes
 *
 *  @param  [in] j Jugador, vector de jugadores
 *	@param  [in] njugadores entero, numero de jugadores
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/
 
void MostrarMazo (Jugador j, unsigned int njugadores)
{
		for (unsigned int i = 0; i < njugadores; i++)
	{
			cout << "Jugador " << i + 1 << " posee las siguientes cartas: " << endl;
			cout << j[i].Mazo << endl;
	}
	return;
}

/**********************************************************************/ /**
 *
 *  Compara la primera carta, que ponemos como centinela y vamos comparando
 *	una con una para sacar cual es la carta mas alta.
 *
 *  @param  [in]  b Baraja con su mazo de cartas y mazo de cartas ganadas
 *	@param [in]	  njugadores entero, numero de jugadores
 *
 *  @return mjugador entero, la posicion del jugador que ha ganado la ronda
 *
 */ /**********************************************************************/
int Comparar (Baraja b, unsigned int njugadores)
{
	int mjugador;
 	Carta peorcarta;
 	peorcarta = b[0];
 	for(unsigned int i = 1; i < njugadores; i++)
	{
	 	if (peorcarta < b[i])
		 {
		 	mjugador = i;
			peorcarta = b[i];
		 }
	}
 	return mjugador;
}
/**********************************************************************/ /**
 *
 *  Crear una baraja con las cartas que se van a apostar los jugadores,
 *	substrayendo de su mazo la primera carta y desapilandola. Luego obtenemos el ganador
 *	y llamamos CartasGanadas
 *
 *  @param  [in,out]  j Jugador con su mazo de cartas y mazo de cartas ganadas
 *
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/
void CartasAJugar (Jugador& j)
{
	Baraja b;
	Carta c;
	int ganador;
	for ( unsigned int i = 0; i<j.size();i++)
	{
		j[i].Mazo.CimaPila(c);
		b.push_back(c);
		j[i].Mazo.Desapilar();
		cout <<"Jugador "<< i+1 << " carta: "<< c << endl;
	}
	ganador = Comparar (b, j.size());
	CartasGanadas (j[ganador], b);
	return;
}
/**********************************************************************/ /**
 *
 *  Apila en el ganador, en su mazo de cartas ganadas, las cartas apostadas
 *
 *  @param  [in,out]  j jugador ganador de la apuesta, solo es un jugador no su vector
 *	@param [in]	  	  b Baraja, la baraja de las cartas apostadas
 *
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/
void CartasGanadas (jugador& j, Baraja b)
{
	for ( unsigned int i = 0; i< b.size(); i++)
	{
		j.Ganadas.Apilar(b[i]);
	}
	return;
}
/**********************************************************************/ /**
 *
 *  Puntuacion1: El jugador que haya ganado más cartas obtendrá 3 puntos. En caso de 
 *	empate, cada jugador implicado recibirá 2 puntos.
 *	
 *	Desapilamos la pila de cartas para contar el numero de estas que tiene cada jugador,
 *  el numero de cartas de cada jugador se almacena en 'marta'. Luego buscamos mediante un
 *	centinela cual es el que tiene mas cartas, se le suma 2 puntos, si es solo este jugador
 *	el que ha ganado se le suma otro punto.
 *
 *  @param  [in,out]  j Jugador con su mazo de cartas y mazo de cartas ganadas
 *
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/
void Puntuacion1(Jugador& j)
{
	Carta c;
	Baraja b;
	// marta es el numero de cartas ganadas
	int marta[j.size()];
	int centinela = 0, nganadores = 0, pos;
	
	// Inicializamos el vector de marta
	for (unsigned int i = 0;i < j.size();i++)
	{
		marta[i] = 0;
	}
	
	for (unsigned int i = 0; i < j.size(); i++)
	{
		// Desapilamos la pila para saber el numero de elementos
		while (!j[i].Ganadas.PilaVacia())
		{
			j[i].Ganadas.CimaPila(c);
			b.push_back(c);
			j[i].Ganadas.Desapilar();
			marta[i]++;
		}
		// Volvemos a apilar la pila
		for ( int z = 0; z < marta[i]; z++)
		{
			j[i].Ganadas.Apilar(b.back());
			b.pop_back();
		}	
	}
	// Buscamos el mayor numero de cartas
	for (unsigned int i = 0; i < j.size(); i++)
	{
		if (marta[i] > centinela)
		{
			centinela = marta[i];
		}
	}
		for (unsigned int i = 0; i < j.size(); i++)
	{
		if (marta[i] == centinela)
		{
			nganadores++;
			j[i].puntuacion += 2;
			pos = i;
		}

	}
	if (nganadores == 1)
		j[pos].puntuacion ++;
	
	return;
}

/**********************************************************************/ /**
 *
 *  Puntuacion2: El jugador para el que la suma de los números de las cartas 
 *	ganadas sea mayor obtendrá 2 puntos. En caso de empate, cada jugador implicado recibirá 
 *  1 punto.
 *
 *	Despilamos el mazo de los jugadores, sumamos en la variable 'marta' el valor de cada carta
 *	y apilamos las cartas. EL que la suma sea mayor gana 1 punto en caso de haber un solo ganador,
 *  se le suma otro punto.
 *
 *  @param  [in,out]  j Jugador con su mazo de cartas y mazo de cartas ganadas
 *
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/

void Puntuacion2(Jugador& j)
{
	Carta c;
	Baraja b;
	// marta es el numero de cartas ganadas
	int marta[j.size()];
	int centinela = 0, nganadores = 0, pos = 0;
	// Inicializamos el vector de marta
	for (unsigned int i = 0;i < j.size();i++)
	{
		marta[i] = 0;
	}
	for (unsigned int i = 0; i < j.size(); i++)
	{
		// Desapilamos la pila para saber el numero de elementos
		while (!j[i].Ganadas.PilaVacia())
		{
			j[i].Ganadas.CimaPila(c);
			b.push_back(c);
			j[i].Ganadas.Desapilar();
			marta[i] = marta[i] + c.DevuelveNumero();
		}
		// Volvemos a apilar la pila
		for ( int z = 0; z < marta[i]; z++)
		{
			j[i].Ganadas.Apilar(b.back());
			b.pop_back();
		}	
	}
	// Buscamos el mayor numero de cartas
	for (unsigned int i = 0; i < j.size(); i++)
	{
		if (marta[i] > centinela)
		{
			centinela = marta[i];
		}
	}
	// Buscamos si hay algun jugador con el mismo valor
		for (unsigned int i = 0; i < j.size(); i++)
	{
		if (marta[i] == centinela)
		{
			nganadores++;
			j[i].puntuacion += 1;
			pos = i;
		}
	}
	if (nganadores == 1)
		j[pos].puntuacion ++;
			
return;
}

/**********************************************************************/ /**
 *
 *  Puntuacion3: El jugador que haya ganado más cartas del palo Oros obtendrá 1 punto.
 *  En caso de empate, cada jugador implicado recibirá 1 punto.
 *
 *  Despilamos el mazo de los jugadores, sumamos en la variable 'marta' el numero de cartas
 *  cuyo palo sera Oros. A continuacion comparamos quien tiene mas oros y se le suma un punto.
 *
 *  @param  [in,out]  j Jugador con su mazo de cartas y mazo de cartas ganadas
 *
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/

void Puntuacion3(Jugador& j)
{
	Carta c;
	Baraja b;
	// marta es el numero de cartas ganadas
	int marta[j.size()];
	int centinela = 0;
	// Inicializamos el vector de marta
	for (unsigned int i = 0;i < j.size();i++)
	{
		marta[i] = 0;
	}
	for (unsigned int i = 0; i < j.size(); i++)
	{
		// Desapilamos la pila para saber el numero de elementos
		while (!j[i].Ganadas.PilaVacia())
		{
			j[i].Ganadas.CimaPila(c);
			b.push_back(c);
			j[i].Ganadas.Desapilar();
			if(c.DevuelvePalo() == 'O')
				marta[i]++;
		}
		// Volvemos a apilar la pila
		for ( int z = 0; z < marta[i]; z++)
		{
			j[i].Ganadas.Apilar(b.back());
			b.pop_back();
		}	
	}
	// Buscamos el mayor numero de cartas
	for (unsigned int i = 0; i < j.size(); i++)
	{
		if (marta[i] > centinela)
		{
			centinela = marta[i];
		}
	}
		for (unsigned int i = 0; i < j.size(); i++)
	{
		if (marta[i] == centinela)
			j[i].puntuacion += 1;

	}
		
return;
}

/**********************************************************************/ /**
 *
 *  Puntuacion4: El jugador que haya ganado algunas de las cartas consideradas como 
 *  especiales obtendrá 1 punto por cada una de ellas. Las cartas especiales son: 1 de Copas, 
 *  7 de Oros, 10 de Espadas y 12 de Bastos.
 *
 *  Despilamos el mazo de los jugadores, sumamos en la variable 'marta' si poseen en el mazo
 *  alguna de las cartas anteriores. Si poseen las cartas de antes se le suma un punto.
 *
 *  @param  [in,out]  j Jugador con su mazo de cartas y mazo de cartas ganadas
 *
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/

void Puntuacion4(Jugador& j)
{
	Carta c;
	Baraja b;
	// marta es el numero de cartas ganadas
	int marta[j.size()];
	int centinela = 0;
	// Inicializamos el vector de marta
	for (unsigned int i = 0; i < j.size();i++)
	{
		marta[i] = 0;
	}
	for (unsigned int i = 0; i < j.size(); i++)
	{
		// Desapilamos la pila para saber el numero de elementos
		while (!j[i].Ganadas.PilaVacia())
		{
			j[i].Ganadas.CimaPila(c);
			b.push_back(c);
			j[i].Ganadas.Desapilar();
			if(c.DevuelvePalo() == 'O' && c.DevuelveNumero() == 7)
				marta[i]++;
			if(c.DevuelvePalo() == 'C' && c.DevuelveNumero() == 1)
				marta[i]++;	
			if(c.DevuelvePalo() == 'E' && c.DevuelveNumero() == 10)
				marta[i]++;		
			if(c.DevuelvePalo() == 'B' && c.DevuelveNumero() == 12)
				marta[i]++;		
		}
		// Volvemos a apilar la pila
		for ( int z = 0; z < marta[i]; z++)
		{
			j[i].Ganadas.Apilar(b.back());
			b.pop_back();
		}	
	}
	// Buscamos el mayor numero de cartas
	for (unsigned int i = 0; i < j.size(); i++)
	{
		if (marta[i] > centinela)
		{
			centinela = marta[i];
		}
	}
		for (unsigned int i = 0; i < j.size(); i++)
	{
		if (marta[i] == centinela)
			j[i].puntuacion += 1;
	}
		
return;
}
/**********************************************************************/ /**
 *
 *  Muestra la puntuacion obtenida por cada jugador
 *
 *  @param  [in]  j Jugador con su puntuacion obtenida en base a los 4 criterios
 *
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/
void MostrarResultados(Jugador j)
{
		for(unsigned int i = 0; i < j.size(); i++)
	{
		cout << "El jugador " << i+1 << " ha ganado: ";
		cout << j[i].puntuacion << " puntos estelares." << endl;
	}
	return;
}


