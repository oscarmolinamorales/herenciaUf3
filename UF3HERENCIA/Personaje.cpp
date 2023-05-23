#pragma comment(lib, "winmm")
#include "Personaje.h"
#include <iostream>
using namespace std;
#include<stdlib.h>
#include<Windows.h>
#include <cctype>
#include <mmsystem.h>


//constructor
Personaje::Personaje(string pName, int pHp, int pLife, int pAttack1, int pPosion) {
	name = pName;
	hp = pHp;
	life = pLife;
	attack1 = pAttack1;
	posion = pPosion;
}

//getters
string Personaje::getName() {
	return name;
}

int Personaje::getHp() {
	return hp;
}

int Personaje::getLife() {
	return life;
}

int Personaje::getAttack1() {
	return attack1;
}


int Personaje::getPosion() {
	return posion;
}

//setters
void Personaje::setName(string pName) {
	name = pName;
}

void Personaje::setHp(int pHp) {
	hp = pHp;
}

void Personaje::setLife(int pLife) {
	life = pLife;
}

void Personaje::setAttack1(int pAttack1) {
	attack1 = pAttack1;
}


void Personaje::setPosion(int pPosion) {
	posion = pPosion;
}



//METHODS
void Personaje::inicio() {
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+                                        Star Wars: Episode V                                    +" << endl;
	cout << "+                                                " << getName() << "                                            + " << endl;
	cout << "+           Corre por los pasillos de la Estrella de La Muerte en busca de venganza...           +" << endl;
	cout << "+                     Lo van a intenar detener pero...Darth Vader le espera.                     +" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	system("pause");
	system("cls");
}

void Personaje::fight() {
	hp = getHp() - getAttack1();
}

void Personaje::battle() {
	
	cout << "Luke ataca a un Clone y ahora tiene" << hp << "puntos de vida " << endl;
}