#pragma once
#include "DarthVader.h"
#include <iostream>
using namespace std;

//CONSTRUCTOR
//TIENE COMO PAR�METROS DE ENTRADA LOS ATRIBUTOS PROPIOS
//Y LOS ATRIBUTOS DE LA CLASE QUE HEREDA
//LOS PAR�METROS DE LA CLASE QUE HEREDA SE PASAN COMO PAR�METROS DE ENTRADA
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
	cout << "Tiene una espada laser que te si te toca...Tiene de da�o: " << getAttack1() << endl;
	cout << "Tiene un bloqueo de: " << getLife() << endl;
	cout << "Es un Jeday como tu...Su ataque de Pu�o Telepatico es de: " << getLaser() << endl;
	cout << "Su rodilla de azero fundido en penas y dolor por la muerte de su amada te va a reventar con un da�o de: " << getMental() << endl;
}
