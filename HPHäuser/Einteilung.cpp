#include <iostream>
#include <string>
#include <vector>
#include "Einteilung.h"
#include <fstream> 

int main()
{
	std::vector<schüler_t> schülerliste;
	int hufflepuff;
	int ravenclaw;
	int slytherin;
	int gryffindor;
	bool weiter = true;

	if (!einlesen(ravenclaw, slytherin, gryffindor, hufflepuff, schülerliste))
	{
		std::cout << "Einlesefehler..." << std::endl;
		std::cout << "[I]nitialisieren?" << std::endl;
		int e;
		e = getchar();
		if (e == 73 || e == 105)
		{
			std::ofstream erstelle("stand.gtf");
			for (int i = 0; i < 4; ++i)
			{
				erstelle << "0" << std::endl;
			}
			erstelle.close();
			if(einlesen(ravenclaw, slytherin, gryffindor, hufflepuff, schülerliste))
				std::cout << "Viel Spass!" << std::endl;
			else
			{
				std::cout << "Das hat nicht geklappt..." << std::endl;
				weiter = false;
			}
		}
		else
		{
			weiter = false;
		}
		
	}

	while (weiter) {

		std::cout << "[neu], [ausgeben] oder erster Buchstabe des Hauses und die zu addierende Zahl" << std::endl;

		std::string eingabe;
		std::cin >> eingabe;
		bool erfolgreich = true;

		if (eingabe.compare("neu") == 0)
		{
			neuerBenutzer(schülerliste);
		}
		else if (eingabe == "exit" || eingabe == "beenden")
		{
			weiter = false;
			continue;
		}
		else if (eingabe == "ausgeben" || eingabe == "Ausgeben")
		{
			SchülerlisteAusgeben(schülerliste);
			continue;
		}
		else
		{

			try {
				int zahl = std::stoi(eingabe.substr(1));

				if (eingabe.at(0) == 'h' || eingabe.at(0) == 'H')
				{
					hufflepuff += zahl;
					std::cout << "Hufflepuff " << zahl << " neuer Stand: " << hufflepuff << std::endl;
				}
				else if (eingabe.at(0) == 'r' || eingabe.at(0) == 'R')
				{
					ravenclaw += zahl;
					std::cout << "Ravenclaw " << zahl << " neuer Stand: " << ravenclaw << std::endl;
				}
				else if (eingabe.at(0) == 'g' || eingabe.at(0) == 'G')
				{
					gryffindor += zahl;
					std::cout << "Gryffindor " << zahl << " neuer Stand: " << gryffindor << std::endl;
				}
				else if (eingabe.at(0) == 's' || eingabe.at(0) == 'S')
				{
					slytherin += zahl;
					std::cout << "Slytherin " << zahl << " neuer Stand: " << slytherin << std::endl;
				}
				else if (eingabe.at(0) == 'a' || eingabe.at(0) == 'A')
				{
					hufflepuff += zahl;
					slytherin += zahl;
					gryffindor += zahl;
					ravenclaw += zahl;
					std::cout << "Hufflepuff " << zahl << " neuer Stand: " << hufflepuff << std::endl;
					std::cout << "Ravenclaw " << zahl << " neuer Stand: " << ravenclaw << std::endl;
					std::cout << "Gryffindor " << zahl << " neuer Stand: " << gryffindor << std::endl;
					std::cout << "Slytherin " << zahl << " neuer Stand: " << slytherin << std::endl;
				}
				else
				{
					erfolgreich = false;
				}
			}
			catch (const std::exception& e)
			{
				erfolgreich = false;
			}
			if (!erfolgreich)
			{
				std::cout << "Hmm ... Ueberpruefe mal deine Eingabe und versuchs nochmal." << std::endl;
			}
		}
		abspeichern(ravenclaw, slytherin, gryffindor, hufflepuff, schülerliste);
		
	}

	std::cout << "Tschuess" << std::endl;
}

bool einlesen(int& r, int& s, int& g, int& h, std::vector<schüler_t>& schülerliste)
{
	std::ifstream rein("stand.gtf");
	std::string zeile;
	schüler_t schüler;
	int i = -4;
	if (rein.is_open())
	{
		while (getline(rein, zeile))
		{
			switch (i)
			{
			case -4:
				std::cout << "Stand Slytherin: " << zeile << std::endl;
				s = std::stoi(zeile);
				break;
			case -3:
				std::cout << "Stand Ravenclav: " << zeile << std::endl;
				r = std::stoi(zeile);
				break;
			case -2:
				std::cout << "Stand Hufflepuff: " << zeile << std::endl;
				h = std::stoi(zeile);
				break;
			case -1:
				std::cout << "Stand Gryffindor: " << zeile << std::endl;
				g = std::stoi(zeile);
				break;
			default:
				schüler.haus = zeile.at(0);
				schüler.name = zeile.substr(1);
				schülerliste.push_back(schüler);
				break;
			}
			++i;
		}
		rein.close();
		return true;
	}
	else
	{
		return false;
	}
}

void neuerBenutzer(std::vector<schüler_t> &schülerliste)
{
	schüler s;
	std::cout << "Name: ";
	std::cin >> s.name;
	int z = 0;

	for (int i = 0; i < s.name.length(); ++i)
	{
		int zi = s.name.at(i);
		//std::cout << s.name.at(i) << zi << std::endl;

		z += s.name.at(i);
	}

	z = z * s.name.length();

	std::cout << "Welche Eigenschaften passen am Besten zu dir?" << std::endl;
	std::cout << "1) Mut, Tapferkeit und Entschlossenheit" << std::endl;
	std::cout << "2) Fleiss, Hilfsbereitschaft, Treue und Gerechtigkeit" << std::endl;
	std::cout << "3) Stolz, Ehrgeiz und Gerissenheit" << std::endl; 
	std::cout << "4) Intelligenz, Gelehrsamkeit und Weisheit" << std::endl;

	int eigenschaft = 0;


	do {
		try
		{
			std::cin >> eigenschaft;
		}
		catch (const std::exception& e)
		{
			eigenschaft = 0;
			std::cout << "Probiers nochmal, ist nur eine Zahl." << std::endl;
		}
	} while (eigenschaft < 1 || eigenschaft > 4);

	srand(z);
	int zufall = rand() % 5;
	switch (zufall)
	{
	case 0: s.haus = "Hufflepuff";
		break;
	case 1: s.haus = "Gryffindor";
		break;
	case 2: s.haus = "Slytherin";
		break;
	case 3: s.haus = "Ravenclaw";
		break;
	case 4: s.haus = "4";
		switch (eigenschaft)
		{
		case 1: s.haus = "Gryffindor";
			break;
		case 2: s.haus = "Hufflepuff";
			break;
		case 3: s.haus = "Slytherin";
			break;
		case 4: s.haus = "Ravenclaw";
			break;
		default: std::cout << "Fehler in der Matrix";
			break;
		}
		break;
	default: std::cout << "Fehler in der Matrix";
		break;
	}
	std::cout << "Herzlich Willkommen in " << s.haus << std::endl;

	schülerliste.push_back(s);
}

void abspeichern(int& r, int& s, int& g, int& h, std::vector<schüler_t>& schülerliste)
{
	std::ofstream schreiben("stand.gtf");
	schreiben << s <<std::endl;
	schreiben << r << std::endl;
	schreiben << h << std::endl;
	schreiben << g << std::endl;
	
	for (std::vector<schüler_t>::iterator it = schülerliste.begin(); it != schülerliste.end(); ++it)
	{
		char s;
		if (it->haus == "Slytherin")
		{
			s = 's';
		}
		else if (it->haus == "Gryffindor")
		{
			s = 'g';
		}
		else if (it->haus == "Hufflepuff")
		{
			s = 'h';
		}
		else if (it->haus == "Ravenclaw")
		{
			s = 'r';
		}
		else
		{
			s = 'b';
			std::cout << "Fehler, bitte manuell ausgeben." << it->haus << std::endl;
		}
		schreiben << s << it->name << std::endl;
	}
	schreiben.close();
}

void SchülerlisteAusgeben(std::vector<schüler_t>& schülerliste)
{
	for (std::vector<schüler_t>::iterator it = schülerliste.begin(); it != schülerliste.end(); ++it)
	{
		std::cout << it->name << ": " << it->haus << std::endl;
	}
}