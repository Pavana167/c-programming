// Max Schulz, Pavana Shjia
#include <stdio.h>

/*
Gemessen wird die Temperatur, indem der Strom eines Wiederstandes (z. B. Pt100) bei einer bestimmten Spannung gemessen wird, gemessen wird in mA mit einer Tolleranzz von +-1mA
Gültigkeitsbereich: 0 < Werte < 5000
Abbruchwert = 0
Restliche Auswertungen nur mit gültigen Werten
*/

int main() {
	int aktuellerWert;
	int anzahlGueltigeWerte = 0;
	int anzahlUngueltigeWerte = 0;
	int anzahlGeradeWerte = 0;
	int anzahlUngeradeWerte = 0;
	int summeGueltigeWerte = 0;
	int groessterWert = 0;
	int kleinsterWert = 5000;
	int programmaktiv = 1;
	double durchschnitt;
	double verhaeltniss;

	printf("Auswertungssoftware\n");

	/*Hauptschleife*/
	while (programmaktiv == 1) {

		/*Werte einlesen*/
		printf("\nBitte geben Sie einen Wert ein: ");
		scanf_s("%d", &aktuellerWert);

		/*Wert auf Gültigkeit überprüfen*/
		if (aktuellerWert > 0 && aktuellerWert < 5000) {
			anzahlGueltigeWerte++;
			summeGueltigeWerte += aktuellerWert;

			 /*größten Messwert bestimmen*/
			if (aktuellerWert > groessterWert) {
				groessterWert = aktuellerWert;
			}

			/*kleinsten Messwert bestimmen*/
			if (aktuellerWert < kleinsterWert) {
				kleinsterWert = aktuellerWert;
			}

			/*gerade und ungerade Werte bestimmen*/
			if (aktuellerWert % 2 == 1) {
				anzahlUngeradeWerte++;
			}
			else {
				anzahlGeradeWerte++;
			}
		}
		else if (aktuellerWert < 0) {
			anzahlUngueltigeWerte++;
		}
		else if (aktuellerWert == 0) {
			programmaktiv == 0;
		}
	}

	/*Durchschnitt bestimmen*/
	durchschnitt = (double)(summeGueltigeWerte/anzahlGueltigeWerte);

	/*Verhälltniss gerade/ungerade bestimmen*/
	verhaeltniss = (double)(anzahlGeradeWerte/anzahlUngeradeWerte)

	/*Ausgabe*/
	printf("Auswertung:\n");
	printf("Anzahl g\cltige Messwerte: \d\n",(char)129,anzahlGueltigeWerte);
	printf("Anzahl ignorierter Eingaben: \d\n",anzahlUngueltigeWerte);
	printf("Kleinster Wert: \d\n",kleinsterWert);
	printf("Gr\csster Wert: \d\n",(char)148,groessterWert);
	printf("Durchschnitt: \lf\n",durchschnitt);
	printf("Verh\clltnis von geraden zu ungeraden Werten: \lf\n",(char)132,verhaeltniss);
	return 0;
}