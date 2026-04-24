/*Max Schulz*/
#include <stdio.h>
#include <stdbool.h>

int main() {
	float gewicht;
	char reduktionsfaktorSymbol;
	float reduktionsfaktorWert;
	float volumen;
	char getraenk;
	float alkoholvolumenanteil;
	float masseAlkohol;
	char wiederholung;
	bool rechnerAktiv = true;
	bool eingabenKorrekt;
	/*Blutalkoholkonzetration*/
	float bak;
	
	/*Hauptschleife*/
	do {
		eingabenKorrekt = true;
		/*Daten abfragen*/
		printf("Was ist dein Gewicht in kg? ");
		scanf_s("%f", &gewicht);
		printf("Was ist der Reduktionsfaktor? ");
		scanf_s(" %c", &reduktionsfaktorSymbol);
		printf("Wie viel hast du in l getrunken? ");
		scanf_s("%f", &volumen);

		/*Alkoholvolumenanteil über Getränkeliste abfragen*/
		printf("\n ---Welches Getr%cnk hast du getrunken?---\n", (char)132);
		printf("Bier (B)\n");
		printf("Starkbier (S)\n");
		printf("Biermix (M)\n");
		printf("Cognac (C)\n");
		printf("Vodka (V)\n");
		scanf_s(" %c", &getraenk);

		switch (getraenk) {
		case'b':
		case'B':
			alkoholvolumenanteil = 5;
			break;
		case's':
		case'S':
			alkoholvolumenanteil = 8;
			break;
		case'm':
		case'M':
			alkoholvolumenanteil = 2.5;
			break;
		case'c':
		case'C':
			alkoholvolumenanteil = 38;
			break;
		case'v':
		case'V':
			alkoholvolumenanteil = 42;
			break;
		default:
			printf("Du hast ein ungültiges Getränk eingegeben.");
			eingabenKorrekt = false;
		}

		/*Reduktionsfaktor bestimmen, || ist oder*/
		if (reduktionsfaktorSymbol == 'k' || reduktionsfaktorSymbol == 'K') {
			reduktionsfaktorWert = 0.6;
		}
		if (reduktionsfaktorSymbol == 'g' || reduktionsfaktorSymbol == 'G') {
			reduktionsfaktorWert = 0.7;
		}
		/*Wird nur ausgeführt, wenn alle Eingaben korrekt sind.*/
		if ( eingabenKorrekt == true) {
			/*Berechnungen*/
			masseAlkohol = 8 * volumen * alkoholvolumenanteil;
			bak = masseAlkohol / (gewicht * reduktionsfaktorWert);

			/*Ausgabe*/
			printf("Dein Blutalkoholgehalt ist %.2f Promille.\n", bak);
			if (bak >= 0.5) {
				printf("Du solltest nicht mehr Auto fahren.");
			}
			else
				printf("Du bist noch fahrt%cchtig.", (char)129);

			/*Abfrage, ob das Programm wiederholt werden soll*/
			printf("\n\nWillst du eine weitere Berechnung durchf%chren? ", (char)129);
			scanf_s(" %c", &wiederholung);
			switch (wiederholung) {
			case'N':
			case'n':
				rechnerAktiv = false;
				break;
			}
			printf("\n");
		}
	} while (rechnerAktiv == true);
	return 0;
}