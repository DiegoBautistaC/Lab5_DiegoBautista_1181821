#pragma once

class List
{
	struct Node
	{
		int data;
		Node *next;
	};

private:
	Node *header = nullptr;

public:
	void Agregar(int elemento);

	void Limpiar();

	int Contar();

	bool Contiene(int elemento);

	int IndiceDe(int elemento);

	void Insertar(int indice, int elemento);

	int ObtenerElemento(int indice);

	void CambiarElemento(int indice, int elemento);

	int UltimoIndiceDe(int elemento);

	bool Remover(int elemento);

	void RemoverEn(int indice);
};

