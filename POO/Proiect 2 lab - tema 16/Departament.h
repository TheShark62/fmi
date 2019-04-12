#pragma once
#include<iostream>
class Departament {
private:
	char* nume;
public:
	Departament();
	Departament(const char* nume);
	Departament(const Departament &);
	~Departament();

	Departament & operator = (const Departament &obj);
	friend std::ostream& operator << (std::ostream& os, const Departament& dt) {
		os << dt.nume;
		return os;
	};
	friend std::istream & operator >> (std::istream &is, Departament &dt) {
		is >> dt.nume;
		return is;
	};

	char* getNume();
	void setNume(char* nume);
};

