#pragma once
#include <iostream>
using namespace std;
#include <windows.h>

class Personaje {

private:
	//Personaje
	string name;
	int    hp;
	int    life;
	int    attack1;
	int    posion;

public:
	//constructor

	Personaje(string pName, int pHp, int pLife, int pAttack1, int pPosion);

	//getters
	string getName();
	int    getHp();
	int    getLife();
	int    getAttack1();
	int    getPosion();


	//setters
	void setName(string pName);
	void setHp(int pHp);
	void setLife(int pLife);
	void setAttack1(int pAttack1);
	void setPosion(int pPosion);



	//METHODS
	void inicio();
	void fight();
	void battle();
};