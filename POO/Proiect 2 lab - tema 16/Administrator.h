#pragma once
#include "Angajat.h"
#include "Departament.h"
class Administrator : public Angajat {
private:
	Departament sectie;
public:
	Administrator();
	Administrator(const char* nume, float salariu, Departament sectie);
	Administrator(Administrator &);
	~Administrator();

	Administrator & operator = (const Administrator &obj);
	friend std::ostream& operator<<(std::ostream& os, const Administrator& dt) {
		os << dt.nume << ' ' << dt.salariu << ' ' << dt.sectie << '\n';
		return os;
	};

	friend std::istream & operator >> (std::istream &is, Administrator &dt) {
		is >> dt.nume >> dt.salariu >> dt.sectie;
		return is;
	};

	void display();
	Departament getSectie();
	void setSectie(Departament sectie);
};

