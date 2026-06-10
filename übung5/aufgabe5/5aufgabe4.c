#include "5aufgabe4.h"

/*
Ziel:
	Liest die Temperaturwerte fuer alle Serverraeume und alle sieben Tage ein.

Parameter:
	temperaturen: Dreidimensionales Array zur Speicherung der Messwerte.
				  Aufbau: [Raum][Messwert pro Tag][Tag]

Rueckgabe:
	Keine.
*/
void einlesen(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG][ANZAHL_TAGE]) {
	// Die aeussere Schleife durchlaeuft alle sieben Tage.
	for (int i = 0;i < ANZAHL_TAGE;i++) {
		printf("-----------------------------\n");
		printf("Tag %d\n", i+1);
		printf("-----------------------------\n");
		for (int j = 0; j < ANZAHL_RAEUME; j++) {// Fuer jeden Tag werden die Werte aller Serverraeume eingelesen.
			printf("  Raum % d:\n",j+1);
			
			for (int k = 0; k < ANZAHL_MESSWERTE_PRO_TAG;k++) {// Pro Raum werden sechs Messwerte eingegeben.
				printf("\tMesswert %d: ",k+1);
				int test = scanf_s("%lf", &temperaturen[j][k][i]);
				while (getchar()!='\n');

				if (test != 1) {// Bei ungueltiger Eingabe wird derselbe Messwert erneut abgefragt.
					printf("Ungueltige Eingabe!\n\n");
					k--;
					continue;
				}
			}
			printf("\n");
			
		}
	}
}

/*
Ziel:
	Ermittelt die hoechste gemessene Temperatur ueber alle Raeume,
	alle Messwerte und alle Tage.

Parameter:
	temperaturen: Dreidimensionales Array mit allen gespeicherten Messwerten.
				  Aufbau: [Raum][Messwert pro Tag][Tag]

Rueckgabe:
	Keine.
*/
void hMesswert(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG][ANZAHL_TAGE]) {
	double max = temperaturen[0][0][0];// Der erste Messwert dient als Startwert fuer den Vergleich.

	//Maximal Temperatur finden
	for (int i = 0; i < ANZAHL_RAEUME; i++) {
		for (int j = 0; j < ANZAHL_MESSWERTE_PRO_TAG;j++) {
			for (int k = 0;k < ANZAHL_TAGE;k++) {
				if (temperaturen[i][j][k] > max) {
					max = temperaturen[i][j][k];
				}
			}

		}
	}
	printf("\nHoechster Messwert: %.1lf %cC (", max, (char)248);
	int luecke = 1;// steuert, ob ein Abstand vor weiteren Eintraegen gesetzt wird

	// Alle Raeume ausgeben, die den hoechsten Wert haben
	for (int i = 0; i < ANZAHL_RAEUME;i++) {
		for (int j = 0;j < ANZAHL_MESSWERTE_PRO_TAG;j++) {
			for (int k = 0;k < ANZAHL_TAGE;k++) {
				if (temperaturen[i][j][k] == max) {
					if (luecke != 1) {
						printf("     "); //Abstand zwichen Eintragen
					}
					printf("Tag %d,Raum %d,Messwert %d ", k+1, i + 1, j + 1);
					luecke = 0;
				}
			}
		}
	}

	printf(")\n");
}

/*
Ziel:
	Gibt alle Temperaturwerte tabellarisch auf der Konsole aus.

Parameter:
	temperaturen: Dreidimensionales Array mit allen gespeicherten Messwerten.
				  Aufbau: [Raum][Messwert pro Tag][Tag]

Rueckgabe:
	Keine.
*/
void temperaturentabelle(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG][ANZAHL_TAGE]) {

	// Die Tabelle wird tageweise ausgegeben.
	for (int k = 0; k < ANZAHL_TAGE;k++) {
		printf("-----------------------------\n");
		printf("Tag %d\n", k + 1);
		printf("-----------------------------\n");
		for (int i = 0; i < ANZAHL_RAEUME;i++) {// Fuer jeden Tag werden alle Raeume mit ihren sechs Messwerten ausgegeben.
			printf("Raum %d:", i + 1);
			for (int j = 0;j < ANZAHL_MESSWERTE_PRO_TAG;j++) {
				printf("%10.1lf %cC", temperaturen[i][j][k], (char)248);
			}
			printf("\n");
		}
		printf("\n");
	}
	
}


	