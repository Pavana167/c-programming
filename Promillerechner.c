/*Max Schulz*/
#include <stdio.h>
#include <stdbool.h>

int main() {
	/*unsigned float wird zu unsigned int*/
	float gewicht;
	char reduktionsfaktorSymbol;
	float reduktionsfaktorWert;
	float volumen;
	char getraenk;
	float alkoholvolumenanteil;
	float masseAlkohol;
	char wiederholung;
	bool rechnerAktiv = true;
	/*Blutalkoholkonzetration*/
	float bak;
	
	/*Hauptschleife*/
	do {
		/*Gewicht eingeben und Eingabe kontrollieren*/
		do {
			printf("Was ist dein Gewicht in kg? ");
			scanf_s("%f", &gewicht);
			while (getchar() != '\n');
			if (gewicht > 1000 || gewicht < 0) {
				printf("\nDu hast ein ung%cltiges Gewicht eingegeben.\n", (char)129);
				gewicht = 0;
			}
		} while (gewicht == 0);

		/*Reduktionsfaktor bestimmen und Eingabe kontrollieren, || ist oder*/
		do {
			printf("Was ist der Reduktionsfaktor? ");
			scanf_s(" %c", &reduktionsfaktorSymbol);
			while (getchar() != '\n');
			if (reduktionsfaktorSymbol == 'k' || reduktionsfaktorSymbol == 'K') {
				reduktionsfaktorWert = 0.6;
			}
			else if (reduktionsfaktorSymbol == 'g' || reduktionsfaktorSymbol == 'G') {
				reduktionsfaktorWert = 0.7;
			}
			else {
				printf("\nDu hast ein ung%cltigen Reduktionsfaktor eingegeben.\n", (char)129);
				reduktionsfaktorSymbol = 0;
			}
		} while (reduktionsfaktorSymbol == 0);

		/*Volumen abfragen und Eingabe kontrollieren*/
		do {
			printf("Wie viel hast du in l getrunken? ");
			scanf_s("%f", &volumen);
			while (getchar() != '\n');
			if (volumen > 100 || volumen < 0) {
				printf("\nDu hast eine ung%cltige Getr%cnkemenge eingegeben.\n", (char)129, (char)132);
				volumen = 0;
			}
		} while (volumen == 0);

		/*Alkoholvolumenanteil über Getränkeliste abfragen und Eingabe kontrollieren*/
		do {
			printf("\n ---Welches Getr%cnk hast du getrunken?---\n", (char)132);
			printf("Bier (B)\n");
			printf("Starkbier (S)\n");
			printf("Biermix (M)\n");
			printf("Cognac (C)\n");
			printf("Vodka (V)\n");
			scanf_s(" %c", &getraenk);
			while (getchar() != '\n');

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
				printf("\nDu hast ein ung%cltiges Getr%cnk eingegeben.\n", (char)129, (char)132);
				alkoholvolumenanteil = 0;
				break;
			}
		} while (alkoholvolumenanteil == 0); 
		
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
		
	} while (rechnerAktiv == true);
	return 0;
}