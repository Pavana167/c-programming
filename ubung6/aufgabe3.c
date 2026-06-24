/*
Max Schulz, Pavana Shaji (17.6.2026)

Aufgabe:
Erstelle ein Programm, welches ein Text von der Konsole einliest und ihn verschluesselt oder wieder entschluesselt und anschliessend wieder auf der Konsole ausgibt.
Die Verschluesselungsmethode sieht wie folgt aus:
- Jedes Zeichen soll durch ein Zeichen, dass in der ASCII-Tabelle einen bestimmten Wert weiter hinten liegt, ersetzt werden.
- Es sollen nur Gross- und Kleinbuchstaben verschluesselt werden.
- Wenn das neue Zeichen kein Buchstabe ist, soll wieder von vorne angefangen werden zu zaehlen, wobei zwischen Gross- und Kleinbuchstaben gewechselt werden soll (z. B. Wert 3, z -> C; Wert 3, Z -> c)
- Jedes Zeichen im eingegebenen Text soll mit einem anderen Wert verschluesselt werden (z. B. Wert = Laenge der Zeichenkette bis zu der Stelle)
- Die Verschluesselung soll von einem Schluessel abhaengig sein.
Das Programm soll den Benutzer nach dem Text und dem Schluessel fragen und fragen, ob entschluesselt oder verschluesselt werden soll.


Das Programm:
Das Programm ist, wie oben beschrieben. Der Wert, mit dem jedes Zeichen verschluesslet wird, wird um 1, fuer jedes Zeichen, das vorher in der Zeichnkette kam, erhoeht.
Der Schluessel ist der Ausgangswert.
*/

#include <stdio.h>
#define SIZE 1000
#define MAXZEICHEN 26

void verschluesseln(int schluessel, char text[], int laenge);
void entschluesseln(int schluessel, char text[], int laenge);

void main() {
	char eingabe;				//Eingabe des Benutzers
	int programmaktiv = 1;		//Ob das Programm noch ausgefuehrt werden soll, oder nicht
	char text[SIZE];			//Text, der verarbeitet wird
	int richtig;				//Ob die Eingabe richtig war
	double schluessel;			//Der Schluessel zum Ver- bzw. Entschluesseln
	int laenge;					//Die Anzahl an Elementen in "text"
	double hilfe;				//Ein Hilfswert zum Rechnen

	//Einfuehrung des Benutzers
	printf("-----Ein Programm zum Ver- und Entschl%csseln von Texten-----\n", (char)129);
	printf("%c, %c, %c, %c, %c, %c, %c gelten als Sonderzeichen und werden daher nicht verschl%csselt.\n", (char)142, (char)132, (char)153, (char)148, (char)154, (char)129, (char)225, (char)129);

	//Hauptschleife
	while (programmaktiv) {

		//Eingabe des Benutzers
		//Text eingeben
		printf("Es k%cnnen maximal %d Zeichen eingegeben werden. Wenn mehr eingegeben wird, wird kein Text %cbernommen.\n", (char)148, SIZE, (char)129);
		printf("Geben Sie einen Text ein: ");
		richtig = scanf_s("%[^\n]", text, SIZE);
		while (getchar() != '\n');

		//Wenn nichts eingegeben wurde, wird der Benutzer erneut aufgefordert
		if (richtig != 1) {
			printf("Es wurde nichts eingegeben.\n");
			continue;
		}

		//Laenge von "text" ermitteln
		laenge = 0;
		while (text[laenge] != '\0') {
			laenge++;
		}

		//Operation eingeben
		richtig = 0;
		while (richtig == 0) {
			printf("V - verschl%csseln, E - entschl%csseln, B - beenden\n", (char)129, (char)129);
			printf("Geben Sie ein, was getan werden soll: ");
			richtig = scanf_s("%c", &eingabe, 1);
			while (getchar() != '\n');

			//Eingabe pruefen
			switch (eingabe) {
			case 'v':
			case 'V':
			case 'e':
			case 'E':
			case 'b':
			case 'B':
				break;
			default:
				richtig = 0;
				printf("Die Eingabe war ung%cltig.\n", (char)129);
				continue;
			}
		}

		//Schluessel eingeben
		//Schluesseleingabe wird uebersprungen, wenn "b" oder "B" eingegeben wurde
		if (!((eingabe == 'b') || (eingabe == 'B'))) {
			richtig = 0;
		}

		while (richtig == 0) {
			printf("Der Schl%cssel muss eine positive Ganzzahl sein.\n", (char)129);
			printf("Geben Sie den Schl%cssel ein: ", (char)129);
			richtig = scanf_s("%lf", &schluessel);
			while (getchar() != '\n');

			//Eingabe pruefen
			//Pruefen, ob eine Zahl eingegeben wurde
			if (richtig != 1) {
				printf("Gib eine Zahl ein.\n");
				richtig = 0;
				continue;
			}

			// Pruefen, ob die Zahl zu gross ist (um zu lange rechenzeiten zu verhindern) (100.000.000 experimentell ermittelt)
			if (schluessel > 100000000) {
				printf("Die Zahl ist zu Gro%c.\n", (char)225);
				richtig = 0;
				continue;
			}

			//Pruefen, ob schluessel eine Ganzzahl ist
			hilfe = schluessel;
			while (hilfe > 0) {
				hilfe--;
			}
			if (hilfe < 0) {	//Prueft auch auf Negativitaet
				printf("Gib eine positive Ganzzahl ein.\n");
				richtig = 0;
			}
		}

		//Verarbeiten
		switch (eingabe) {
		case 'v':
		case 'V':
			verschluesseln((int)schluessel, text, laenge);
			break;
		case 'e':
		case'E':
			entschluesseln((int)schluessel, text, laenge);
			break;
		case 'b':
		case'B':
			programmaktiv = 0;
			continue;
		default:
			richtig = 0;
			printf("Die Eingabe war ung%cltig.\n", (char)129);
			continue;
		}

		//Ausgabe
		printf("\n%s\n\n", text);
	}
}

/*
Funktion, die einen Text verschluesselt
Parameter:	schluessel:	positive Ganzzahl als int
						Der Schluessel, nach dem der Text verschluesselt werden soll
			text:		Array von chars
						Der Text, der verschluesselt werden soll
			laenge:		positive Ganzzahl als int
						Die anzahl an Elementen in "text"
Rueckgabewert:	keiner
*/
void verschluesseln(int schluessel, char text[], int laenge) {
	int hilfe = 0; //Hilfswert

	//Jedes Zeichen in "text" durchgehen
	for (int i = 0; i < laenge; i++) {

		//Sicherstellen, dass maximal einmal wieder von vorne angefangen werden muss zu zaehlen
		if (schluessel > MAXZEICHEN) {
			schluessel %= MAXZEICHEN;
		}

		//Das verschluesselte Zeichen ermitteln, falls es ein Buchstabe ist
		if ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123)) {
			hilfe = (int)text[i] + schluessel;
		}
		//Falls es kein Buchstabe ist, wird das Symbol uebernommen
		else {
			hilfe = text[i];
		}

		//Sicherstellen, dass das verschluesselte Zeichen ein Buchstabe (und der richtige Buchstabe) ist
		//Der Urspruengliche Buchstabe war ein Grossbuchstabe
		if (text[i] > 64 && text[i] < 91) {
			if (hilfe > 90) {
				hilfe += 6;
			}
		}
		//Der Urspruengliche Buchstabe war ein Kleinbuchstabe
		else if (text[i] > 96 && text[i] < 123) {
			if (hilfe > 122) {
				hilfe -= 58;
			}
		}

		//Das Zeichen verschluesseln
		text[i] = (char)hilfe;

		//Wert zum verschluesseln aktualisieren
		schluessel++;
	}
}

/*
Funktion, die einen Text entschluesselt
Parameter:	schluessel:	positive Ganzzahl als int
						Der Schluessel, nach dem der Text entschluesselt werden soll
			text:		Array von chars
						Der Text, der entschluesselt werden soll
			laenge:		positive Ganzzahl als int
						Die anzahl an Elementen in "text"
Rueckgabewert:	keiner
*/
void entschluesseln(int schluessel, char text[], int laenge) {
	int hilfe = 0; //Hilfswert

	//Jedes Zeichen in "text" durchgehen
	for (int i = 0; i < laenge; i++) {

		//Sicherstellen, dass maximal einmal wieder von vorne angefangen werden muss zu zaehlen
		if (schluessel > MAXZEICHEN) {
			schluessel %= MAXZEICHEN;
		}

		//Das entschluesselte Zeichen ermitteln, falls es ein Buchstabe ist
		if ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123)) {
			hilfe = (int)text[i] - schluessel;
		}
		//Falls es kein Buchstabe ist, wird das Symbol uebernommen
		else {
			hilfe = text[i];
		}

		//Sicherstellen, dass das verschluesselte Zeichen ein Buchstabe ist
		//Der Urspruengliche Buchstabe war ein Grossbuchstabe
		if (text[i] > 64 && text[i] < 91) {
			if (hilfe < 65) {
				hilfe += 58;
			}
		}
		//Der Urspruengliche Buchstabe war ein Kleinbuchstabe
		else if (text[i] > 96 && text[i] < 123) {
			if (hilfe < 97) {
				hilfe -= 6;
			}
		}

		//Das Zeichen entschluesseln
		text[i] = (char)hilfe;

		//Wert zum verschluesseln aktualisieren
		schluessel++;
	}
}

/*Testfaelle:
*
* Schluessel:			3
* Text:					Dies ist ein Satz.
* Verschluesselung:		Gmjy qBD qvB irLS.
*
* Schluessel:			90
* Text:					Hallo Welt.
* Verschluesselung:		TnzAE oxFO.
*
* Schluessel:			385
* Text:					Hat der alte Hexenmeister sich doch einmal wegbegeben,
* Verschluesselung:		cwQ CEs dpyk PnHpzzsxIKwK NEzF Dpek jouujv IruquxwuyI,
*
* Schluessel:
* Text:
* Verschluesselung:
*
*/