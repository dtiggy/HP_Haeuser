#pragma once

typedef struct sch�ler {
	std::string name;
	std::string haus;
}sch�ler_t;

bool einlesen(int& r, int& s, int& g, int& h, std::vector<sch�ler_t>& sch�lerliste);
void neuerBenutzer(std::vector<sch�ler_t> &sch�lerliste);
void abspeichern(int& r, int& s, int& g, int& h, std::vector<sch�ler_t>& sch�lerliste);
void Sch�lerlisteAusgeben(std::vector<sch�ler_t>& sch�lerliste);