#include "Departament.h"
#include<string.h>
#include<iostream>

Departament::Departament() {
	this->nume = new char[strlen("Fara nume") + 1];
	strcpy(this->nume, "Fara nume");
}

Departament::Departament(const char* nume) {
	this->nume = new char[strlen(nume) + 1];
	strcpy(this->nume, nume);
}

Departament::Departament(const Departament &aux) {
	this->nume = new char[strlen(aux.nume) + 1];
	strcpy(this->nume, aux.nume);
}

Departament::~Departament() {
	delete[] this->nume;
}

Departament & Departament::operator = (const Departament &obj) {
	this->nume = new char[strlen(obj.nume) + 1];
	strcpy(this->nume, obj.nume);
	return *this;
}

char* Departament::getNume() {
	return this->nume;
}

void Departament::setNume(char* nume) {
	this->nume = nume;
}