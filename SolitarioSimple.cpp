#include <iostream>
#include "SolitarioSimple.h"
#include <ctime>
#include <cstdlib>

//Método para egregar una carta en la pila
void SolitarioSimple::AgregarCarta(int numero, char color)
{
	Carta *carta = new Carta();
	carta->color = color;
	carta->numero = numero;
	carta->next = header;
	header = carta;
}

void SolitarioSimple::AgregarFinal()
{
	Carta* aux = header;
	Carta *anterior = header;
	Carta *reemplazo = new Carta();
	reemplazo->color = header->color;
	reemplazo->numero = header->numero;
	header = header->next;
	for (size_t i = 0; aux != nullptr; aux = aux->next)
	{
		anterior = aux;
	}
	anterior->next = reemplazo;
}

//Método para sacar la primera carta que aparece en la pila
void SolitarioSimple::SacarCarta()
{
	if (header != nullptr)
	{
		Carta *aux = header;
		header = aux->next;
		delete (aux);
	}
}

//Método utilizado para llenar una lista con las cartas de un mazo de forma aletorio
void SolitarioSimple::LlenarMazo()
{
	srand((unsigned)time(0));
	int n;
	int c;
	char colores[] = { 'R','N' };
	int total = 52;
	while (total > 0)
	{
		n = 1 + rand() % (14 - 1);
		c = rand() % 2;
		if (CartaValidaMazo(n,colores[c]))
		{
			AgregarCarta(n,colores[c]);
			total--;
		}
	}
}

//Método utilizado para validar si al llenar la pila, la nueva carta que se agregará puede agregarse o es incorrecta.
bool SolitarioSimple::CartaValidaMazo(int numero, char color)
{
	Carta *aux = header;
	int n = 0;
	int c = 0;
	for (aux; aux != nullptr; aux = aux->next)
	{
		if (n >= 4 || c >= 2)
		{
			return false;
		}
		else
		{
			if (aux->numero == numero)
			{
				n++;
				if (aux->color == color)
				{
					c++;
				}
			}
		}
	}
	return true;
}

void SolitarioSimple::Grupo(int cantidad, SolitarioSimple *&mazo)
{
	Carta *aux = new Carta();
	while (cantidad > 0)
	{
		aux = mazo->header;
		AgregarCarta(aux->numero, aux->color);
		mazo->SacarCarta();
		cantidad--;
	}
}
void SolitarioSimple::ImprimirCartas(int vPosicion)
{
	if (header != nullptr)
	{
		if (vPosicion == 0)
		{
			std::cout << header->numero << header->color;
		}
		else
		{
			Carta *aux = header;
			while (vPosicion >= 0)
			{
				if (aux == nullptr)
				{
					break;
				}
				std::cout << aux->numero << aux->color << " ";
				aux = aux->next;
				vPosicion--;
			}
		}
	}
	else
	{
		std::cout << "0";
	}
}

int SolitarioSimple::ContarGrupo()
{
	Carta *aux = header;
	if (aux == nullptr)
	{
		return 0;
	}
	else
	{
		int contador = 0;
		for (aux; aux != nullptr; aux = aux->next)
		{
			contador++;
		}
		return contador;
	}
}

//Método que trabaja con el grupo de origen como objeto y el grupo destino como parámetro
void SolitarioSimple::MovimientoJugador(int posicionCartas, SolitarioSimple *& GrupoDestino, int* vOrigen, int* vDestino)
{
	Carta *grupoDestino = GrupoDestino->header;
	if (posicionCartas == 0)
	{
		if (grupoDestino == nullptr)
		{
			GrupoDestino->AgregarCarta(header->numero, header->color);
			header = header->next;
			*vDestino += 1;
		}
		else if (MovimientoValido(grupoDestino->numero, grupoDestino->color))
		{
			Carta *aux = header;
			header = aux->next;
			aux->next = grupoDestino;
			GrupoDestino->header = aux;
			*vDestino += 1;
		}
		else
		{
			std::cout << "El movimiento es invalido." << std::endl;
		}
	}
	else
	{
		if (ValidarEnPosicion(header, posicionCartas))
		{
			while (posicionCartas >= 0)
			{
				GrupoDestino->AgregarDeA(header, posicionCartas, vDestino, vOrigen);
				posicionCartas--;
			}
		}
		else
		{
			std::cout << "El movimiento es invalido." << std::endl;
		}
	}
}

bool SolitarioSimple::MovimientoValido(int numero, char color)
{
	if (header->numero + 1 == numero)
	{
		if (header->color != color)
		{
			return true;
		}
	}
	return false;
}

bool SolitarioSimple::ValidarEnPosicion(Carta *GrupoOrigen, int posicion)
{
	Carta *aux = GrupoOrigen;
	while (posicion > 0)
	{
		aux = aux->next;
		posicion--;
	}
	if (MovimientoValido(aux->numero, aux->color))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Método que utiliza el grupo de destino como objeto, y el grupo de origen como parámetro
void SolitarioSimple::AgregarDeA(Carta *& GrupoOrigen, int posicion, int* vDestino, int* vOrigen)
{
	Carta* aux = GrupoOrigen;
	Carta* anterior = GrupoOrigen;
	if (posicion == 0)
	{
		GrupoOrigen = GrupoOrigen->next;
		AgregarCarta(aux->numero, aux->color);
		*vDestino += 1;
	}
	else
	{
		while (posicion > 0)
		{
			anterior = aux;
			aux = aux->next;
			posicion--;
		}
		anterior->next = aux->next;
		AgregarCarta(aux->numero, aux->color);
		*vDestino += 1;
		*vOrigen -= 1;
		delete(aux);
	}
	
}
