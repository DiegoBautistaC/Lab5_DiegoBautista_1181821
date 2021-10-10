#pragma once
class SolitarioSimple
{
	struct Carta
	{
		int numero;
		char color;
		Carta *next;
	};

private:
	Carta *header = nullptr;

public:
	
	void AgregarCarta(int numero, char color);
	
	void AgregarFinal();

	void SacarCarta();

	void LlenarMazo();
	
	bool CartaValidaMazo(int numero, char color);

	void Grupo(int cantidad, SolitarioSimple *&mazo);

	void ImprimirCartas(int vPosicion);

	int ContarGrupo();

	void MovimientoJugador(int posicionCartas, SolitarioSimple *&GrupoDestino, int* vOrigen, int* vDestino);
	
	bool MovimientoValido(int numero, char color);

	bool ValidarEnPosicion(Carta *GrupoOrigen, int posicion);

	void AgregarDeA(Carta* &GrupoOrigen, int posicion, int* vDestino, int* vOrigen);
};

