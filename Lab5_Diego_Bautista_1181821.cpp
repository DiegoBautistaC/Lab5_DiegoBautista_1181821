#include <iostream>
#include "list.h"
#include "SolitarioSimple.h"

using namespace std;

void ComienzaElJuego();
void ImprimirJuego();
void Movimiento(SolitarioSimple* &GrupoOrigen, SolitarioSimple* &GrupoDestino, int posicion, int* vOrigen, int* vDestino);
int* GD(int grupoDestino);
SolitarioSimple* GrupoDestino(int grupoDestino);

SolitarioSimple *mazo = new SolitarioSimple();
SolitarioSimple *G1 = new SolitarioSimple();
SolitarioSimple *G2 = new SolitarioSimple();
SolitarioSimple *G3 = new SolitarioSimple();
SolitarioSimple *G4 = new SolitarioSimple();
SolitarioSimple *G5 = new SolitarioSimple();
SolitarioSimple *G6 = new SolitarioSimple();
SolitarioSimple *G7 = new SolitarioSimple();

int vv1 = 0, vv2 = 0, vv3 = 0, vv4 = 0, vv5 = 0, vv6 = 0, vv7 = 0, ma = 0;
int* v1 = &vv1;
int* v2 = &vv2;
int* v3 = &vv3;
int* v4 = &vv4;
int* v5 = &vv5;
int* v6 = &vv6; 
int* v7 = &vv7;
int* m = &ma;

int main()
{
	mazo->LlenarMazo();
	char eleccion;
	try
	{
		cout << "Ingrese un comando:\n(R)Comenzar a jugar\n(S)salir" << endl;
		cin >> eleccion;
		switch (eleccion)
		{
		case 's':
			cout << "\nGracias por su preferencia, que tenga buen dia.";
			break;
		case 'S':
			cout << "\nGracias por su preferencia, que tenga buen dia.";
			break;
		case 'r':
			ComienzaElJuego();
			break;
		case 'R':
			ComienzaElJuego();
			break;
		default:
			cout << "No ha ingresado un caracter correcto, el programa se reiniciara.";
			break;
		}
	}
	catch (const std::exception&)
	{
		cout << "Error: no ha ingresado un valor valido.";
	}
}

void ComienzaElJuego()
{
	G1->Grupo(7, mazo);
	G2->Grupo(6, mazo);
	G3->Grupo(5, mazo);
	G4->Grupo(4, mazo);
	G5->Grupo(3, mazo);
	G6->Grupo(2, mazo);
	G7->Grupo(1, mazo);
	bool gano = false;
	while (!gano)
	{
		try
		{
			ImprimirJuego();
			int grupoOrigen, posicion, grupoDestino;
			cout << "\n\nSeleccione el grupo (1-7)(Si desea tomar del mazo seleccione 0)(Si desea sacar una carta del maso -1) del que desea mover cartas: ";
			cin >> grupoOrigen;
			if (grupoOrigen == -1)
			{
				mazo->AgregarFinal();
			}
			else
			{
				cout << "Seleccione la posicion desde la cual tomara cartas (De izquierda a derecha comenzando en 0): ";
				cin >> posicion;
				cout << "Seleccione el grupo al que movera las cartas: ";
				cin >> grupoDestino;
				if (grupoDestino < 1 || grupoDestino > 7 || grupoOrigen < 0 || grupoOrigen > 7 || grupoDestino == grupoOrigen)
				{
					cout << "El movimiento es invalido." << endl;
				}
				else
				{
					SolitarioSimple* aux = GrupoDestino(grupoDestino);
					switch (grupoOrigen)
					{
					case 0:
						Movimiento(mazo, aux, posicion, m, GD(grupoDestino));
						break;
					case 1:
						Movimiento(G1, aux, posicion, v1, GD(grupoDestino));
						break;
					case 2:
						Movimiento(G2, aux, posicion, v2, GD(grupoDestino));
						break;
					case 3:
						Movimiento(G3, aux, posicion, v3, GD(grupoDestino));
						break;
					case 4:
						Movimiento(G4, aux, posicion, v4, GD(grupoDestino));
						break;
					case 5:
						Movimiento(G5, aux, posicion, v5, GD(grupoDestino));
						break;
					case 6:
						Movimiento(G6, aux, posicion, v6, GD(grupoDestino));
						break;
					case 7:
						Movimiento(G7, aux, posicion, v7, GD(grupoDestino));
						break;
					default:
						break;
					}
				}
			}
			if (*v1 >= 4 || *v2 >= 4 || *v3 >= 4 || *v4 >= 4 || *v5 >= 4 || *v6 >= 4 || *v7 >= 4)
			{
				ImprimirJuego();
				cout << "\n\n\t\t\t\t\t\"HA GANADO\"" << endl;
				gano = true;
			}
		}
		catch (const std::exception&)
		{
			cout << "Error: ha ingresado un valor que no es válido.\n" << endl;
		}
	}
}

void ImprimirJuego()
{
	cout << "\nMazo: ";
	mazo->ImprimirCartas(0);
	cout << endl;
	cout << "G1: ";
	G1->ImprimirCartas(*v1);
	cout << endl;
	cout << "G2: ";
	G2->ImprimirCartas(*v2);
	cout << endl;
	cout << "G3: ";
	G3->ImprimirCartas(*v3);
	cout << endl;
	cout << "G4: ";
	G4->ImprimirCartas(*v4);
	cout << endl;
	cout << "G5: ";
	G5->ImprimirCartas(*v5);
	cout << endl;
	cout << "G6: ";
	G6->ImprimirCartas(*v6);
	cout << endl;
	cout << "G7: ";
	G7->ImprimirCartas(*v7);
	cout << endl;
}

void Movimiento(SolitarioSimple* &GrupoOrigen, SolitarioSimple* &GrupoDestino, int posicion, int* vOrigen, int* vDestino)
{
	if (posicion <= *vOrigen)
	{
		GrupoOrigen->MovimientoJugador(posicion, GrupoDestino, vOrigen, vDestino);
	}
	else
	{
		cout << "El moviminento no puede ser realizado.\n" << endl;
	}
}

SolitarioSimple* GrupoDestino(int GrupoDestino)
{
	switch (GrupoDestino)
	{
	case 1:
		return G1;
		break;
	case 2:
		return G2;
		break;
	case 3:
		return G3;
		break;
	case 4:
		return G4;
		break;
	case 5:
		return G5;
		break;
	case 6:
		return G6;
		break;
	case 7:
		return G7;
		break;
	default:
		return G1;
		break;
	}
}

int* GD(int grupoDestino)
{
	switch (grupoDestino)
	{
	case 1:
		return v1;
		break;
	case 2:
		return v2;
		break;
	case 3:
		return v3;
		break;
	case 4:
		return v4;
		break;
	case 5:
		return v5;
		break;
	case 6:
		return v6;
		break;
	case 7:
		return v7;
		break;
	default:
		return v1;
		break;
	}
}
