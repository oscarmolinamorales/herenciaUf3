#pragma once
#include "Personaje.h"
#include <iostream>
using namespace std;

class darthVader : public Personaje
{
private:
	int attackLaser;
	int attackMental;

public:
	//CONSTRUCTOR CON ELEMENTOS DE LA CLASE DE PERSONAJES Y LA DEL SUPER ENEMIGO

	darthVader(string pName, int pHp, int pAttack1, int pLife, int pPosion ,int pLaser, int pMental);

	//GETTERS Y SETTERS

	int getLaser();
	int getMental();

	void setLaser(int pLaser);
	void setMental(int pMental);

	//METODOS PROPIOS

	void printAllStats();
};

