//Autor: Pavana Shaji, Max Schulz
/*
	Programm: Seriennummer-Pruefziffer
	Kurzbeschreibung:
	Dieses Programm liest zwei Grossbuchstaben, eine 5-stellige und eine
	4-stellige Ziffernfolge ein. Alle Eingaben werden streng validiert.
	Danach wird die Pruefziffer aus der Quersumme aller Werte berechnet.

	Regeln:
	- Nur Grossbuchstaben (A–Z) erlaubt
	- Erste Eingabe: genau 5 Ziffern ohne Leerzeichen
	- Zweite Eingabe: genau 4 Ziffern ohne Leerzeichen
	- Pruefziffer wird separat berechnet

	Besonderheiten:
	- Bei Buchstaben wird nur ein Grossbuchstabe akzeptiert.
	  Kleinbuchstaben oder andere Zeichen fuehren zu erneuter Eingabe.
	- Bei Ziffernfolgen werden nur gueltige Ziffern (0–9) akzeptiert.
	  Ungueltige Eingaben werden erneut abgefragt.
*/

// Zur Implementierung der Array-übergabe werde eine externe seite konsultiert:https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm





#include<stdio.h>


//Funktion zum Einlesen und Validieren eines Grossbuchstabens und gibt die Quersumme seines Alphabetwerts zurück
int buchstabeCheck();

//Funktion zur Quersummenberechnung
int quersumme(int ersteB, int zweiteB, int comb1[5], int comb2[4]);

//Funktion zum Einlesen und Validieren einer 5 bzgw. 4 Ziffern Kombination
void leseZiffern(int arr[], int count);

int main() {

	int ersteB; //erster buchstabe
	int zweiteB;//zweiter buchstabe
	int comb1[5] = { 0 }; //combination1 von 5 Ziffern
	int comb2[4] = { 0 };//combination2 von 4 Ziffern
	int pruefziffer = 0;

	//Einführung für den Benutzer
	printf("===============================================\n");
	printf("      EURO-BANKNOTEN  SERIENNUMMER-PRUEFUNG\n");
	printf("===============================================\n\n");
	printf("Dieses Programm prueft die Seriennummer eines Geldscheins.\n");
	printf("So sind die Bestandteile der Seriennummer einzugeben:\n\n");
	printf("1) Erster Grossbuchstabe (A-Z)\n");
	printf("2) Zweiter Grossbuchstabe (A-Z)\n");
	printf("3) Eine 5-stellige Ziffernfolge\n");
	printf("4) Eine 4-stellige Ziffernfolge\n");
	printf("5) Die Pruefziffer (eine einzelne Ziffer)\n\n");
	printf("Hinweis:\n");
	printf("- Es werden nur Grossbuchstaben akzeptiert.\n");
	printf("- Ziffernfolgen muessen genau die geforderte Laenge haben ohne Leerzeichnen.\n\n\n");



	// Ab hier beginnt die Programmlogik
	printf("----ERSTER Buchstabe----\n");
	ersteB = buchstabeCheck();

	printf("\n\n----ZWEITER Buchstabe----\n");
	zweiteB = buchstabeCheck();


	leseZiffern(comb1, 5);
	leseZiffern(comb2, 4);


	printf("Pruefziffer Eingeben\n");
	scanf_s("%d", &pruefziffer); //Pruefziffer einlesen


	int qsumme = quersumme(ersteB, zweiteB, comb1, comb2);

	//Berechnung und Überprüfung der Pruefziffer

	int schritt1 = qsumme % 9;
	int schritt2 = 7 - schritt1;
	int calcPruefziffer = 0; // Variable zum Speichern der berechneten Pruefziffer


	if (schritt2 == 0) {
		calcPruefziffer = 9;
	}
	else if (schritt2 == -1) {
		calcPruefziffer = 8;
	}
	else {
		calcPruefziffer = schritt2;
	}

	if (pruefziffer == calcPruefziffer) {
		printf("Die Pruefziffer ist in Ordnung!\n\n");
	}
	else {
		printf("Der Geldschein ist gefaelscht!\n\n");
	}

	return 0;
}




/*
	Funktion: buchstabeCheck
	Zweck:
		Liest einen Großbuchstaben (A–Z) ein, validiert ihn und berechnet
		die Quersumme seiner Alphabetposition.

	Parameter:
		Keine

	Rückgabewert:
		Quersumme des Alphabetwertes (z.B. 'N' → 14 → 1+4 = 5)
*/

int buchstabeCheck() {
	char buchstabe;
	while (1) {
		printf("Buchstabe eingeben:\n");
		scanf_s("%c", &buchstabe, 1);
		while (getchar() != '\n');


		if (buchstabe >= 'A' && buchstabe <= 'Z') {

			int werte = buchstabe - 64;
			// Beispiel: Buchstabe 'N' → ASCII-Wert 78. 
			// Durch (78 - 64) erhaelt man 14, also die Position von 'N' im Alphabet.



			int q = (werte / 10) + (werte % 10);
			// Quersumme des Alphabetwertes berechnen.
			// Beispiel: Wert = 14 → Quersumme = 1 + 4 = 5


			return q;

		}
		else {
			printf("Ungueltige Eingabe! Es sind nur Grossbuchstaben zulaessig\n\n");


		}

	}
}




/*
	Funktion: quersumme
	Zweck:
		Berechnet die Gesamtsumme aus zwei Einzelwerten sowie allen
		Elementen der Arrays comb1 und comb2.

	Parameter:
		ersteB:  erster Summand
		zweiteB: zweiter Summand
		comb1:   Array mit 5 weiteren Summanden
		comb2:   Array mit 4 weiteren Summanden

	Rückgabewert:
		Gesamtsumme aller uebergebenen Werte
*/

int quersumme(int ersteB, int zweiteB, int comb1[5], int comb2[4]) {
	int sum = ersteB + zweiteB;

	for (int i = 0; i < 5;i++) {
		sum += comb1[i];
	}
	for (int i = 0; i < 4;i++) {
		sum += comb2[i];
	}
	return sum;
}






/*
	Funktion: leseZiffern
	Zweck:
		Liest eine festgelegte Anzahl von Ziffern ein, prüft die Eingabe
		auf gültige numerische Zeichen und speichert die Ziffern als
		Integerwerte im Array arr.

	Parameter:
		arr:   Zielarray für die eingelesenen Ziffern
		count: Anzahl der zu lesenden Ziffern

	Rückgabewert:
		Keiner (Ergebnis wird im Array arr gespeichert)
*/

void leseZiffern(int arr[], int count) {
	char temp[10] = { 0 };
	while (1) { // Validierung der eingegebenen Ziffernfolge
		printf("\nGeben Sie die %d Ziffern nacheinander ein und druecken Sie dann die Eingabetaste\n", count);
		scanf_s("%s", temp, 10);
		while (getchar() != '\n');

		int valid = 1;

		for (int i = 0; i < count;i++) {
			if (temp[i] < '0' || temp[i] > '9') {
				valid = 0;
				break;
			}
		}

		if (valid == 1) {
			for (int i = 0; i < count;i++) {
				arr[i] = temp[i] - '0';
				// Beispiel: temp[0] = '5' → ASCII 53. 
				// arr[0] = 53 - 48 = 5 (numerischer Wert der Ziffer)
			}
			break;
		}
		else {
			printf("Ungueltige Eingabe! Bitte gib %d Ziffern ein\n\n", count);
		}
	}

}
