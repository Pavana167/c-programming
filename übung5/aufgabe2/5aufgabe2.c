
#include "5aufgabe2.h"
/*
Liest die Temperaturwerte fuer alle Serverraeume ein.

Der Benutzer gibt fuer jeden Raum nacheinander alle Messwerte ein.
Bei einer ungueltigen Eingabe wird derselbe Messwert erneut abgefragt.

Parameter:
	temperaturen: 2D-Array, das die Temperaturwerte der Raeume speichert

Rueckgabewert:
	keiner
*/
void einlesen(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG]) { // Liest die Messwerte fuer alle Raeume ein

	for (int i = 1; i <= ANZAHL_RAEUME; i++) {
		printf("--Eingabe fuer Raum %d--\n",i);
		for (int j = 1; j <= ANZAHL_MESSWERTE_PRO_TAG; j++) {
			printf("Raum %d , Messwert %d: ",i,j);
			int test = scanf_s("%lf",&temperaturen[i-1][j-1]);
			while (getchar()!= '\n');

			if (test != 1) { // Bei ungueltiger Eingabe wird derselbe Messwerte erneut abgefragt
				printf("Ungueltige Eingabe!\n\n");
				j--;
				continue;
			}
		}
		printf("\n");
		
	}
	
} 

/*
Berechnet die Durchschnittstemperatur fuer jeden Serverraum.

Fuer jeden Raum werden alle Messwerte addiert und durch die Anzahl der
Messwerte pro Raum geteilt. Das Ergebnis wird auf der Konsole ausgegeben.

Parameter:
	temperaturen: 2D-Array, das die Temperaturwerte der Raeume speichert
	messwerteProRaum: Anzahl der Messwerte pro Raum

Rueckgabewert:
	keiner
*/
void durchschnitt(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG],int messwerteProRaum) {
	double summe = 0;
	double durchschnitt = 0;
	for (int i = 0; i < ANZAHL_RAEUME;i++) {
		for (int j = 0; j < ANZAHL_MESSWERTE_PRO_TAG;j++) {
			summe = summe + temperaturen[i][j];
		}
		durchschnitt = summe / messwerteProRaum;
		printf("Raum %d - Durchschnittstemperatur:%10.2lf %cC\n",i+1,durchschnitt, (char)248);
		summe = 0;
		
	}
}
/*
Ermittelt den hoechsten gemessenen Temperaturwert.

Es wird der hoechste Wert im gesamten Temperaturfeld gesucht.
Zusaetzlich werden die Raumnummer und die Messwertnummer dieses Wertes
auf der Konsole ausgegeben.

Parameter:
	temperaturen: 2D-Array, das die Temperaturwerte der Raeume speichert

Rueckgabewert:
	keiner
*/
//hMesswert : hoechster Messwert

void hMesswert(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG]) {
	double max = temperaturen[0][0];

	//Maximal Temperatur finden
	for (int i = 0; i < ANZAHL_RAEUME; i++) { 
		for (int j = 0; j < ANZAHL_MESSWERTE_PRO_TAG;j++) {
			if (temperaturen[i][j] > max) {
				max = temperaturen[i][j];
			}

		}
	}
	printf("\nHoechster Messwert: %.1lf %cC (", max, (char)248);
	int luecke = 1;// steuert, ob ein Abstand vor weiteren Eintraegen gesetzt wird

	// Alle Raeume ausgeben, die den hoechsten Wert haben
	for (int i = 0; i < ANZAHL_RAEUME;i++) {
		for (int j = 0;j < ANZAHL_MESSWERTE_PRO_TAG;j++) {
			if (temperaturen[i][j] == max) {
				if (luecke != 1) {
					printf("     "); //Abstand zwichen Eintragen
				}
				printf("Raum %d,Messwert %d ",i+1,j+1);
				luecke = 0;
			}
		}
	}
	
	printf(")\n");
}



/*
Ermittelt den Serverraum mit der stabilsten Temperatur.

Fuer jeden Raum wird die Differenz zwischen dem hoechsten und dem niedrigsten
Messwert berechnet. Der Raum mit der kleinsten Differenz wird als stabilster
Raum auf der Konsole ausgegeben.

Parameter:
	temperaturen: 2D-Array, das die Temperaturwerte der Raeume speichert

Rueckgabewert:
	keiner
*/
void stbRaum(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG]) {
	double diff[ANZAHL_RAEUME];
	
	for (int i = 0; i < ANZAHL_RAEUME;i++) {
		double max = temperaturen[i][0];   // fuer jeden Raum neu setzen
		double min = temperaturen[i][0];
		for (int j = 0; j < ANZAHL_MESSWERTE_PRO_TAG;j++) {
			if (temperaturen[i][j]>max) {
				max = temperaturen[i][j];
			}
			if (temperaturen[i][j] < min) {
				min = temperaturen[i][j];
			}
		}
		
		diff[i] = max - min; // Temperaturendifferenz des aktuellen Raums speichern
		
	}

	double minDiff = diff[0];
	printf("Stabilster Raum: ");
	for (int i = 1; i < ANZAHL_RAEUME;i++) { // Kleinste Temperaturdifferenz ermitteln (stabilster Raum)
		if (diff[i]<minDiff) {
			minDiff = diff[i];
		}
	}
	int luecke = 1;// steuert Abstand zwischen mehreren ausgegebenen Raeumen
	// Alle Raeume ausgeben, die die kleinste Temperaturdifferenz besitzen
	for (int i = 0; i < ANZAHL_RAEUME;i++) {
		if (diff[i] == minDiff) {
			if (luecke != 1) {
				printf("     ");// Abstand zwischen mehreren Eintraegen
			}
			printf("Raum %d",i+1);
			luecke = 0;// ab jetzt Abstand aktivieren
		}
	}

	printf(" (Temperaturdifferenz: %.2lf %cC)\n",minDiff, (char)248);

}


/*
Gibt alle Temperaturwerte tabellarisch aus.

Die gespeicherten Messwerte werden raumweise ausgegeben.
Jeder Messwert wird mit einer Feldbreite von 10 dargestellt.

Parameter:
	temperaturen: 2D-Array, das die Temperaturwerte der Raeume speichert

Rueckgabewert:
	keiner
*/
void temperaturentabelle(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG]) {
	for (int i = 0; i < ANZAHL_RAEUME;i++) {
		printf("Raum %d:",i+1);
		for (int j = 0;j < ANZAHL_MESSWERTE_PRO_TAG;j++) {
			printf("%10.1lf %cC", temperaturen[i][j], (char)248);
		}
		printf("\n");
	}
}