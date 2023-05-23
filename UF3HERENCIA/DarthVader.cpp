#pragma once
#include "DarthVader.h"
#include <iostream>
using namespace std;

//CONSTRUCTOR
//TIENE COMO PARÁMETROS DE ENTRADA LOS ATRIBUTOS PROPIOS
//Y LOS ATRIBUTOS DE LA CLASE QUE HEREDA
//LOS PARÁMETROS DE LA CLASE QUE HEREDA SE PASAN COMO PARÁMETROS DE ENTRADA
//AL CONSTRUCTOR HEREDADO


	darthVader::darthVader(string pName,int pHp, int pAttack1, int pLife, int pPosion, int pLaser, int pMental) : 
	Personaje(pName, pHp, pAttack1, pLife, pPosion) {attackLaser = pLaser; attackMental = pMental;}

//GETTERS Y SETTERS
int darthVader::getLaser() {
	return attackLaser;
}
int darthVader::getMental() {
	return attackMental;
}
void darthVader::setLaser(int pLaser) {
	attackLaser = pLaser;
}
void darthVader::setMental(int pMental) {
	attackMental = pMental;
}

//METODOS PROPIOS
void darthVader::printAllStats() {
	cout << "Spoiler...Es tu padre... " << getName() << endl;
	cout << "Y va fuerte...Su fuerza oscura es de: " << getHp() << endl;
	cout << "Tiene una espada laser que te si te toca...Tiene de daño: " << getAttack1() << endl;
	cout << "Tiene un bloqueo de: " << getLife() << endl;
	cout << "Es un Jeday como tu...Su ataque de Puño Telepatico es de: " << getLaser() << endl;
	cout << "Su rodilla de azero fundido en penas y dolor por la muerte de su amada te va a reventar con un daño de: " << getMental() << endl;
}
