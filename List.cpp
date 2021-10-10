#include <iostream>
#include "List.h"

void List::Agregar(int elemento)
{
	Node *newNodo = new Node();
	newNodo->data = elemento;
	newNodo->next = header;
	header = newNodo;
}

void List::Limpiar()
{
	if (header != nullptr)
	{
		while (header != nullptr)
		{
			Node *aux = header;
			header = aux->next;
			delete(aux);
		}
	}
	else
	{
		std::cout << "Error: La lista esta vacia.\n";
	}
	
}

int List::Contar()
{
	Node *aux = header;
	if (aux == nullptr)
	{
		return 0;
	}
	else
	{
		Node *aux2 = new Node();
		int i = 0;
		for (i; aux != nullptr; i++)
		{
			aux2 = aux;
			aux = aux2->next;
		}
		return i;
	}
}

bool List::Contiene(int elemento)
{
	Node *aux = header;
	while (aux != nullptr)
	{
		if (aux->data == elemento)
		{
			return true;
		}
		else
		{
			aux = aux->next;
		}
	}
	return false;
}

int List::IndiceDe(int elemento)
{
	Node *aux = header;
	for (size_t i = 0; aux != nullptr; i++)
	{
		if (aux->data == elemento)
		{
			return i;
		}
		else
		{
			Node *aux2 = aux;
			aux = aux->next;
		}
	}
	return -1;
	//Le puede servir a Vicfrost
	//int count = 0;
	//for (NodoSimple^ indice = Cabeza; indice != nullptr; indice = indice->Siguiente)
	//{
	//	if (indice->Valor == valor)
	//		return count;
	//	count++;
	//}
	//return -1;
}

void List::Insertar(int indice, int elemento)
{
	if (indice < 0 || indice >= Contar())
	{
		std::cout << "Error: el elemento no puede ser colocado en la posición deseada.\n";
	}
	else if (indice == 0)
	{
		Agregar(elemento);
	}
	else
	{
		Node *NewNodo = new Node();
		NewNodo->data = elemento;
		Node *posicion = header;
		Node *anterior = header;
		for (size_t indiceActual = 0; indiceActual < indice; indiceActual++)
		{
			anterior = posicion;
			posicion = posicion->next;
		}
		NewNodo->next = posicion;
		anterior->next = NewNodo;
	}
}

int List::ObtenerElemento(int indice)
{
	if (indice < 0 || indice >= Contar())
	{
		std::cout << "Error: No existe un elemento en el indice solicitado.\n";
		return -1;
	}
	else
	{
		Node *aux = header;
		int indiceActual = 0;
		while (indiceActual < indice)
		{
			aux = aux->next;
			indiceActual++;
		}
		return aux->data;
	}
}

void List::CambiarElemento(int indice, int elemento)
{
	if (indice >= Contar() || indice < 0)
	{
		std::cout << "Error: no puede cambiarse el elemento en el indice indicado.\n";
	}
	else
	{
		Node *aux = header;
		int indiceActual = 0;
		while (indiceActual < indice)
		{
			aux = aux->next;
			indiceActual++;
		}
		aux->data = elemento;
	}
}

int List::UltimoIndiceDe(int elemento)
{
	Node *aux = header;
	int posicion = -1, indice = 0;
	while (aux != nullptr)
	{
		if (aux->data == elemento)
		{
			posicion = indice;
		}
		aux = aux->next;
		indice++;
	}
	return posicion;
}

bool List::Remover(int elemento)
{
	int posicion = IndiceDe(elemento);
	if (posicion == -1)
	{
		std::cout << "Error: el elemento no se encuentra en la lista.\n";
		return false;
	}
	else
	{
		Node *aux = header;
		if (posicion == 0)
		{
			header = aux->next;
			delete(aux);
			return true;
		}
		else
		{
			Node *anterior = header;
			for (size_t i = 0; i < posicion; i++)
			{
				anterior = aux;
				aux = aux->next;
			}
			anterior->next = aux->next;
			delete(aux);
			return true;
		}
	}
}

void List::RemoverEn(int indice)
{
	if (indice < 0 || indice >= Contar())
	{
		std::cout << "Error: No puede removerse un elemento del indice solicitado.";
	}
	else
	{
		Node *aux = header;
		if (indice == 0)
		{
			header = aux->next;
			delete(aux);
		}
		else
		{
			Node *anterior = header;
			for (size_t i = 0; i < indice; i++)
			{
				anterior = aux;
				aux = aux->next;
			}
			anterior->next = aux->next;
			delete(aux);
		}
	}
}