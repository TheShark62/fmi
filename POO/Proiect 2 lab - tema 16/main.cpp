#include<iostream>
#include "Angajat.h"
#include "Administrator.h"
#include "Departament.h"
#include<list>
#include<string>
#include <algorithm>

int main() {
	std::list<Angajat> listaAngajati;
	std::list<Departament> listaSectii;

	while (true) {
		unsigned int choice;

		std::cout << "Alegeti optiunea dorita:\n";
		std::cout << "1. Adauga n angajati\n";
		std::cout << "2. Afiseaza angajatii\n";
		std::cout << "3. Afiseaza sectiile\n";
		std::cout << "0. Iesire\n";

		std::cin >> choice;

		switch (choice) {
		case 1: {
			unsigned int n;
			std::cout << "Introduceti numarul de angajati pe care doriti sa il adaugati:";
			std::cin >> n;
			std::cout << '\n';

			for (unsigned int index = 0; index < n; index++) {
				std::string nume;
				std::cout << "Introduceti numele: ";
				std::cin >> nume;
				std::cout << '\n';
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				float salariu;
				std::cout << "Introduceti salariul: ";
				std::cin >> salariu;
				std::cout << '\n';

				bool isAdmin;
				std::cout << "Este administrator? (y/n)";
				{
					char adminChoice;
					std::cin >> adminChoice;
					isAdmin = putchar(tolower(adminChoice)) == 'y' ? true : false;
				}
				if (isAdmin) {
					std::cout << "Introduceti numele sectiei pe care o conduce: ";
					std::string numeSectie;
					std::cin >> numeSectie;
					std::list<Departament>::iterator it = std::find_if(listaSectii.begin(), listaSectii.end(), [&](Departament sectie) {
						return sectie.getNume() == numeSectie;
					});
					if (it != listaSectii.end()) {
						Administrator aux(nume.c_str(), salariu, *it);
						listaAngajati.push_back(aux);
					}
					else {
						Departament sectieNoua(numeSectie.c_str());
						listaSectii.push_back(sectieNoua);
						Administrator aux(nume.c_str(), salariu, sectieNoua);
						listaAngajati.push_back(aux);
					}
				}
				else {
					Angajat aux(nume.c_str(), salariu);
					listaAngajati.push_back(aux);
				}
			}
			break;
		}
		case 2: {
			for (Angajat angajat : listaAngajati)
				angajat.display();
			break;
		}
		case 3: {
			for (Departament sectie : listaSectii)
				std::cout << sectie.getNume() << '\n';
			break;
		}

		case 0: {
			std::cout << "Va multumim!";
			return 0;
		}

		default:
			break;
		}
	}

	return 0;
}