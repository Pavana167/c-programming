//Max Schulz, Pavana Shaji

#include <stdio.h>
#include <math.h>

//implementieren der Funktionen
int *dezAlsBin();
void druckeVektor();

//Hauptschleife
int main() {

	//Eingabe vom Benutzer, double damit Gleitpunktzahlen erkannt werden
	double dezimalzahl;
	//Für Schleife benoetigt
	int programmaktiv = 1;
	//Merker für falsche Eingaben
	int eingabe;
	//Speichert Binaerzahl
	//Die letzte Zahl im Vektor (ganz Rechts) ist die erste Ziffer der Binaerzahl
	int vektor[8];
	//Die Laenge des Vektors bestimmen (Gesammtgroesse / Groesse eines Elements)
	// laenge = 8, da in ""vektor" 8 Elemente sind, aendert sich jedoch, wenn "vektor" veraendert wird
	int laenge = sizeof(vektor) / sizeof(vektor[0]);

	//Einfuehren des Benutzers
	printf("---Programm zur Umwandlung einer Dezimalzahl in einer Bin%crzahl---\n",(char)132);
	printf("Das Programm verarbeitet nur Ganzzahlen.\n");
	printf("Beende das Programm mit -1.\n");

	//Programm ausführen
	while (programmaktiv == 1) {
		printf("\nGib eine Dezimalzahl von 0 bis 255 ein: ");

		//Statt der falschen Eingabe wird nichts uebernommen,
		//deshalb die Variable "eingabe" um zu kontrollieren, ob ein richtiger Wert eingegeben wurde
		eingabe = scanf_s("%lf", &dezimalzahl);
		while (getchar() != '\n');

		//Ueberpruefen, ob die eingegebene Zahl eine Ganzzahl ist
		double i = dezimalzahl;
		int ganzzahl;
		while (i > 0) {
			i--;
		}
		if (i == 0) {
			ganzzahl = 1;
		}
		else {
			ganzzahl = 0;
		}


		//Eingabe Ueberpruefen
		if (dezimalzahl < 0 || dezimalzahl > 255 || eingabe == 0 || ganzzahl == 0) {

			//Programm beenden
			if (dezimalzahl == -1) {
				programmaktiv = 0;
				continue;
			}
			printf("Es wurde eine ung%cltige Eingabe gemacht.\n", (char)129);
			continue;
		}

		//Die eingegebene Zahl in ein Intiger umwandeln, da "dezAlsBin" ein Intiger als Argument benoetigt
		int intdezimalzahl = (int)dezimalzahl;

		//Binaerzahl ausgeben
		druckeVektor(dezAlsBin(intdezimalzahl,vektor,laenge), laenge);
	}
	return 0;
}

//initialisieren der Funktionen

/*
Funktion, die eine Dezimalzahl in eine Binaerzahl umwandelt
Parameter: dez:		 positive ganzzahlige Dezimalzahl,
					 die Zahl wird umgewandelt
		   vektor[]: ein Vektor, in dem die Binaerzahl gespeichert wird,
					 das letzte Element des Vektors entspricht der ersten Ziffer der Binaerzahl
		   anzahl:	 die Länge des Vektors als positive ganzzahlige Dezimalzahl,
					 anzahl muss mindestens so gross wie die Anzahl der Ziffern der Binaerzahl +1 sein
Rueckgabewert: vektor[] wird zurueckgegeben
*/
int *dezAlsBin(int dez,int vektor[],int anzahl) {

	while (dez > 0) {
		if (dez - pow(2, anzahl -1) >= 0) {
			vektor[anzahl - 1] = 1;					//anzahl -1, da das letzte Element des Vektors der ersten Ziffer der Binaerzahl entspricht, anzahl aber die Anzahl der Elemente des Arrays ist
			dez = dez - (int)pow(2, anzahl -1);
		}
		else if (dez - pow(2, anzahl -1) < 0) {
			vektor[anzahl -1] = 0;
		}
		anzahl--;
	}
	//Wenn dez = 0 wird die Schleife beendet und die verbleibenden Ziffern werden nicht aktualisiert
	//Hier werden die Restlichen Ziffern auf 0 gesetzt
	if (dez == 0) {
		for (anzahl;anzahl > 0;anzahl--) {
			vektor[anzahl -1] = 0;
		}
	}
	return vektor;
}
/*
Funktion, die in einem Vektor gespeicherte Werte auf der Konsole ausgibt
Parameter: vektor[]: Vektor,
					 Werte des Vektors werden vom letzten bis zum ersten Element, ohne Luecken o. ae. dazwischen ausgegeben
		   anzahl:	 positive ganzzahlige Dezimalzahl,
					 Anzahl der Elemente in "vektor[]"
Rueckgabewert: kein Rueckgabewert,
			   gibt auf der Konsole aus
*/
void druckeVektor(int vektor[], int anzahl) {

	//Fuer Schleife benoetigt
	int i = 0;
	
	//Binaerzahl ausgeben
	printf("Bin%crzahl: ", (char)132);
	while (i <= anzahl -1) {						//anzahl -1, da das letzte Element des Vektors der ersten Ziffer der Binaerzahl entspricht, anzahl aber die Anzahl der Elemente des Arrays ist
		printf("%d", vektor[anzahl -1 -i]); 
		i++;
	}
}