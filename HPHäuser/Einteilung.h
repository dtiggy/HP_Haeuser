#pragma once

typedef struct schüler {
	std::string name;
	std::string haus;
}schüler_t;

bool einlesen(int& r, int& s, int& g, int& h, std::vector<schüler_t>& schülerliste);
void neuerBenutzer(std::vector<schüler_t> &schülerliste);
void abspeichern(int& r, int& s, int& g, int& h, std::vector<schüler_t>& schülerliste);
void SchülerlisteAusgeben(std::vector<schüler_t>& schülerliste);