/*
	Datei: aufgabe_2.c
	Autor: Pavana
	Version: 1.0
	Datum: 19.04.2026
	Beschreibung: Grundrechenarten 
*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int zahl1 = 0;
	int zahl2 = 0;

	//Benutzereingabe einlesen
	printf("Geben Sie die erste Zahl ein:\n");
	scanf_s("%d", &zahl1);
	printf("Geben Sie die zweite Zahl ein:\n");
	scanf_s("%d", &zahl2);

	// Berechnung der fünf Grundrechenarten
	int summe = zahl1 + zahl2;
	int differenz = zahl1 - zahl2;
	int produkt = zahl1 * zahl2;
	int quotient = zahl1 / zahl2;
	int modulo = zahl1 % zahl2;

	// Ausgabe der Ergebnisse auf der Konsole
	printf("Die fuenf Rechenarten fuer die Zahlen %d und %d:\n", zahl1, zahl2);
	printf("Summe: %d\n", summe);
	printf("Differenz: %d\n", differenz);
	printf("Produkt: %d\n", produkt);
	printf("Quotient: %d\n", quotient);
	printf("Modulo: %d\n", modulo);

	return 0;

}