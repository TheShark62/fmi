#include "Angajat.h"
#include<string.h>

Angajat::Angajat() {
	this->nume = new char[strlen("Fara nume") + 1];
	strcpy(this->nume, "Fara nume");
	this->salariu = 0;
}

Angajat::Angajat(const char* nume, float salariu) {
	this->nume = new char[strlen(nume) + 1];
	strcpy(this->nume, nume);
	this->salariu = salariu;
}

Angajat::Angajat(const Angajat & cpyAngajat) {
	this->nume = new char[strlen(cpyAngajat.nume) + 1];
	strcpy(this->nume, cpyAngajat.nume);
	this->salariu = cpyAngajat.salariu;
}

Angajat::~Angajat() {
	delete[] this->nume;
}

Angajat & Angajat::operator = (const Angajat &obj) {
	this->nume = new char[strlen(obj.nume) + 1];
	strcpy(this->nume, obj.nume);
	this->salariu = obj.salariu;
	return *this;
}

void Angajat::display() {
	std::cout << *this;
}

void Angajat::display(std::ostream ostream) {
	ostream << *this;
}

float Angajat::getSalariu() {
	return this->salariu;
}

void Angajat::setSalariu(float salariu) {
	this->salariu = salariu;
}
