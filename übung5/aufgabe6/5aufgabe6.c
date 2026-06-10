#include "5aufgabe6.h"


/*
Ziel:
	Gibt den aktuellen Sitzplan des Hoersaals auf der Konsole aus.

Parameter:
	hoersaal: Zweidimensionales Array mit dem aktuellen Sitzplan.
			  '*' bedeutet belegt, ' ' bedeutet frei.

Rueckgabe:
	Keine.
*/
void ausgebenHoersaal(char hoersaal[SITZ_REIHEN][PLAETZEN]) {
	for (int i = 0; i < SITZ_REIHEN;i++) {
		for (int j = 0; j < PLAETZEN;j++) {
			printf("|%c",hoersaal[i][j]);// Jeder Platz wird mit einem Trennzeichen ausgegeben.
		}
		printf("|\n");
	}
}


/*
Ziel:
	Prueft, ob sich ein Studierender auf den Platz in Reihe i und Spalte j setzen darf.

Parameter:
	hoersaal: Zweidimensionales Array mit dem aktuellen Sitzplan.
	i: Index der zu pruefenden Reihe.
	j: Index des zu pruefenden Platzes in der Reihe.

Rueckgabe:
	1, wenn der Platz nach allen Regeln besetzt werden darf.
	0, wenn der Platz nicht besetzt werden darf.
*/
int darfsitzen(char hoersaal[SITZ_REIHEN][PLAETZEN], int i, int j) {
	if (hoersaal[i][j] == '*') return 0;// Ein bereits belegter Platz kann nicht erneut besetzt werden.
	if (i > 0 && hoersaal[i - 1][j] == '*') return 0;// Niemand darf sich direkt hinter einen bereits sitzenden Studierenden setzen.
	

	// Bei Randplaetzen gibt es nur einen direkten Nachbarplatz, der deshalb frei sein muss.
	if (j == 0) {
		if (hoersaal[i][1] == '*') return 0;
	}
	else if (j == PLAETZEN - 1) {
		if (hoersaal[i][PLAETZEN - 2] == '*') return 0;
	}
	else {
		if (hoersaal[i][j - 1] == '*' && hoersaal[i][j + 1] == '*') return 0;// Bei mittleren Plaetzen darf der Studierende nicht zwischen zwei Personen sitzen.
	}


	// Falls links bereits jemand sitzt, wird geprueft, ob diese Person
	// nach dem neuen Besetzen weiterhin mindestens einen freien Nachbarplatz hat.
	if (j > 0 && hoersaal[i][j - 1] == '*') {
		if (j - 1 == 0) return 0;// Sitzt die linke Person am Rand, haette sie nach rechts keinen freien Platz mehr.
		if (hoersaal[i][j - 2] == '*') return 0;// Wenn links von der linken Person auch jemand sitzt, waere sie eingeschlossen.
	}

	// Falls rechts bereits jemand sitzt, wird geprueft, ob diese Person
	// nach dem neuen Besetzen weiterhin mindestens einen freien Nachbarplatz hat.
	if (j < PLAETZEN - 1 && hoersaal[i][j + 1] == '*') {
		if (j + 1 == PLAETZEN - 1) return 0; // Sitzt die rechte Person am Rand, haette sie nach links keinen freien Platz mehr.
		if (hoersaal[i][j + 2] == '*') return 0;// Wenn rechts von der rechten Person auch jemand sitzt, waere sie eingeschlossen.
	}

	return 1;// Wenn keine Regel verletzt wurde, darf der Platz besetzt werden.


}

/*
Ziel:
	Besetzt den Hoersaal mit moeglichst vielen Studierenden nach den vorgegebenen Regeln.

Parameter:
	hoersaal: Zweidimensionales Array mit dem aktuellen Sitzplan.
			  Das Array wird direkt veraendert.

Rueckgabe:
	Keine.
*/
void besetzeHoersaal(char hoersaal[SITZ_REIHEN][PLAETZEN]) {
	for (int i =0;i < SITZ_REIHEN;i++) {// Die Suche beginnt vorne links und laeuft Reihe fuer Reihe durch den Hoersaal.
		for (int j = 0; j < PLAETZEN;j++) {
			if (darfsitzen(hoersaal, i, j)) {// Wenn der aktuelle Platz erlaubt ist, wird er besetzt.
				hoersaal[i][j] = '*';
			}
		}
	}
}


/*
Ziel:
	Zaehlt alle belegten Plaetze im Hoersaal.

Parameter:
	hoersaal: Zweidimensionales Array mit dem aktuellen Sitzplan.

Rueckgabe:
	Anzahl der belegten Plaetze.
*/
int zaehleBelegtePlaetze(char hoersaal[SITZ_REIHEN][PLAETZEN]) {
	int belegtePlaetze = 0;// Zaehler fuer alle belegten Plaetze.
	for (int i = 0;i < SITZ_REIHEN;i++) {// Der gesamte Hoersaal wird durchsucht.
		for (int j = 0;j < PLAETZEN;j++) {
			if (hoersaal[i][j] == '*') {// Jeder belegte Platz wird mitgezaehlt.
				belegtePlaetze += 1;
			}
		}
	}
	return belegtePlaetze;
}