//Max Schulz, Pavana Shaji
#include <stdio.h>
#include "myMath.h"
#include <math.h>

const double pi = 3.14159265358979323;

//Deklaration der Funktion
double bogenmass(double gradmass);

int main() {
	double winkel;
	int genauigkeit;
	int programmaktiv = 1;

	//Einführen des Benutzers
	printf("-----Ein Programm zum Berechnen des Sinusses-----\n\n");
	//Die Berechnungen dauern zu lange, wenn die Eingaben zu groß sind
	printf("Zum Beenden des Programms '0' als Genauigkeit eingeben.\n");
	printf("Es k%cnnen nur Winkel von -999999 bis 999999 eingegeben werden.\n",(char)148);
	printf("Winkel die kleiner bzw. gr%csser als -360%c bzw. 360%c sind,\nwerden in den entsprechenden Winkel, in der Periode umgerechnet.\n",(char)148,(char)248,(char)248);
	//mySin funktoniert für größere Zahlen nicht
	printf("Die Genauigkeit muss als positive Ganzzahl, von 1 bis 100 eingegeben werden, wobei 1 die geringste genauigkeit ist.\n\n");

	//Hauptschleife
	while (programmaktiv == 1) {
		//Werte abfragen
		printf("Geben Sie einen Winkel in Grad an: ");
		scanf_s("%lf", &winkel);
		while (getchar() != '\n');
		
		//Auf eine falsche Eingabe kontrollierren
		if (winkel > 999999 || winkel < -999999) {
			printf("Es wurde eine ung%cltige Zahl eingegeben.\n",(char)129);
			continue;
		}	

		//Da das Programm Fehlerhaft wird, wenn "winkel" sehr groß wird, wird hier "winkel" auf den entsprechenden Wert von 0 bis 360 gebracht
		//Das ist in Ordnung, da nur eine normale Sinusfunktion mit einer Periode von 360° berechnet wird
		while (winkel > 360) {
			winkel = winkel - 360;
		}
		while (winkel < 0) {
			winkel = winkel + 360;
		}

		//Es ist in Ordnug, wenn "genauigkeit" durch falsche Eingabe die Dezimalstellen abgeschnitten werden,
		//da die Auswirkungen auf das Programm seher klein sind
		printf("Geben Sie an, wie genau der Sinus berechnet werden soll: ");
		scanf_s("%d", &genauigkeit);
		while (getchar() != '\n');

		//Auf eine zu große Eingabe kontrollierren
		if (genauigkeit > 100 || genauigkeit < 1) {

			//Programm beenden
			if (genauigkeit == 0) {
				programmaktiv = 0;
				continue;
			}
			printf("Es wurde eine ung%cltige Zahl eingegeben.\n", (char)129);
			continue;
		}

		//Sinus berechnen und ausgeben
		printf("Berechnung mit mySin: sin(%lf) = %lf\n", (double)winkel, mySinus(bogenmass(winkel), (int)genauigkeit));
		printf("Berechnung mit sin: sin(%lf) = %lf\n\n", (double)winkel, sin((bogenmass(winkel))));
	}

	return 0;
}

//Implementierung der Funktion
//Funktion zur Umrechnung des Winkels in Bogenmaß
double bogenmass(double gradmass) {
	double bogenmass = 0;
	bogenmass = gradmass * pi / 180;
	return bogenmass;
}
