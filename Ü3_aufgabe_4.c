/*------------------------------------------------------------
Projekt: GGT - Berechnung(Euklidischer Algorithmus)
Autor : Pavana Shaji , Max Schulz

Beschreibung :
Dieses Programm berechnet den groessten gemeinsamen Teiler(GGT)
zweier vom Benutzer eingegebener Zahlen.

Besonderheiten :
- Das Programm akzeptiert ausschliesslich ganze Zahlen.
- Wenn der Benutzer eine Dezimalzahl eingibt, wird dies erkannt.
- Wenn der Benutzer eine nicht-numerische Eingabe macht, wird dies erkannt.
- In beiden Fällen wird die Eingabe als ungültig behandelt und der Benutzer zur erneuten Eingabe einer ganzen Zahl aufgefordert.
------------------------------------------------------------*/



#include<stdio.h>

// Funktion zur Berechnung des GGT mit dem euklidischen Algorithmus
int ggt(int a, int b);

int main() {


	// Variablen für die gültigen Ganzzahlen nach der Prüfung
	int zahl1 = 0;
	int zahl2 = 0;

	// Temporäre Float-Eingaben, um Dezimalstellen erkennen zu können
	float pruefwert1 = 0;
	float pruefwert2 = 0;
	int g = 0; // Ergebnisvariable für den GGT

	// Flags für die Eingabeprüfung
	int wiederholen1 = 1;
	int wiederholen2 = 1;


	// Einleitungstext für den Benutzer 
	printf("=========================================\n");
	printf("        GGT-Berechnung (Euklid)          \n");
	printf("=========================================\n\n");

	printf("Dieses Programm berechnet den groessten gemeinsamen Teiler (GGT)\n");
	printf("zweier ganzer Zahlen.\n\n");

	printf("Bitte beachten:\n");
	printf("- Es sind nur ganze Zahlen erlaubt (keine Dezimalzahlen!)\n");
	printf("- Bei falscher Eingabe muessen Sie die Zahl erneut eingeben.\n\n");

	printf("Los geht's!\n\n");


	// Erste Zahl einlesen und auf Ganzzahligkeit prüfen
	do {
		printf("Erste zahl eingeben: \n");
		// Eingabe als float, damit Dezimalstellen erkannt werden können
		int test1 = scanf_s("%f", &pruefwert1);


		// Prüfen, ob die Eingabe eine ganze Zahl ist (keine Dezimalzahl und keine nicht-numerische Eingabe)
		if (pruefwert1 != (int)pruefwert1 || test1 != 1) {
			printf("\nBitte geben Sie eine ganzzahl ein\n");
			while (getchar() != '\n');
			wiederholen1 = 1;
		}
		else {
			zahl1 = (int)pruefwert1;// gültige Eingabe übernehmen
			wiederholen1 = 0;
		}


	} while (wiederholen1 == 1);


	// Zweite Zahl einlesen und prüfen
	do {
		printf("\nZweite zahl eingeben:\n");
		int test2 = scanf_s("%f", &pruefwert2);


		// Prüfen, ob die Eingabe eine ganze Zahl ist (keine Dezimalzahl und keine nicht-numerische Eingabe)
		if (pruefwert2 != (int)pruefwert2 || test2 != 1) {
			printf("\nBitte geben Sie eine ganzzahl ein \n");
			while (getchar() != '\n');
			wiederholen2 = 1;
		}
		else {
			zahl2 = (int)pruefwert2;
			wiederholen2 = 0;
		}

	} while (wiederholen2 == 1);


	// GGT berechnen und Ergebnis ausgeben
	g = ggt(zahl1, zahl2);

	printf("\nGGT von %d und %d ist %d\n", zahl1, zahl2, g);

	return 0;
}


// Euklidischer Algorithmus zur Berechnung des GGT
int ggt(int a, int b) {
	if (b == 0) {
		return a;
	}
	return ggt(b, a % b); // Rekursiver Aufruf: berechnet den GGT von (b) und dem Rest (a % b)
}