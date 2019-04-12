#pragma once
#include<iostream>

class Angajat {
protected:
	char* nume;
	float salariu;
public:
	Angajat();
	Angajat(const char* nume, float salariu);
	Angajat(const Angajat &);
	~Angajat();

	Angajat & operator = (const Angajat &obj);
	friend std::ostream& operator<<(std::ostream& os, const Angajat& dt) {
		os << dt.nume << ' ' << dt.salariu << '\n';
		return os;
	};

	friend std::istream & operator >> (std::istream &is, Angajat &dt) {
		is >> dt.nume >> dt.salariu;
		return is;
	};

	virtual void display();
	virtual void display(std::ostream ostream);
	float getSalariu();
	void setSalariu(float salariu);
};

