#include "Administrator.h"



Administrator::Administrator() {

}

Administrator::Administrator(const char* nume, float salariu, Departament sectie) : Angajat(nume, salariu) {
	this->sectie = sectie;
}

Administrator::Administrator(Administrator &aux) : Angajat(aux) {
	this->sectie = aux.sectie;
}

Administrator::~Administrator() {

}

Administrator & Administrator::operator = (const Administrator &obj) {
	this->nume = new char[strlen(obj.nume) + 1];
	strcpy(this->nume, obj.nume);
	this->salariu = obj.salariu;
	this->sectie = obj.sectie;
	return *this;
}

void Administrator::display() {
	std::cout << *this;
}

Departament Administrator::getSectie() {
	return this->sectie;
}

void Administrator::setSectie(Departament sectie) {
	this->sectie = sectie;
}

