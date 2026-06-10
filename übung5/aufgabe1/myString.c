//Max Schulz, Pavana Shaji

#include <stdio.h>
#include <stdbool.h>

/*
Funktion die, die Zeichen einer Zeichenkette zaehlt
Parameter:	s[]:	array von chars,
					Zeichenkette, deren Laenge gezaehlt wird
Rueckgabewert:	positive Ganzzahl als int,
				Anzhal der Zeichen
*/
int myStrlen(char s[]) {
	int i = 0;

	while (s[i] != '\0') {
		i++;
	}

	return i;
}

/*
Funktion, die zwei Zeichenketten miteinander vergleicht
Parameter:	string1[]:	array von chars,
						eine der zu vergleichenden Zeichenketten
			string2[]:	array con chars,
						eine der zu vergleichenden Zeichenketten
Rueckgabewert:	0, falls die Zeichenketten gleich sind
				1, falls die Zeichenketten gleich viele Zeichen, aber mindestens ein unterschiedliches Zeichen besitzen 
				2, falls die Zeichenketten unterschiedlich viele Zeichen besitzen
*/
int myStrcmp(char string1[], char string2[]) {

	//Ueberpruefen, ob die strings gleich lang sind
	if (myStrlen(string1) != myStrlen(string2)) {
		return 2;
	}
	else {

		//Ueberpruefen, ob die strings gleich sind
		for (int i = 0; i < myStrlen(string1); i++) {
			if (string1[i] != string2[i]) {
				return 1;
			}
		}
		return 0;		
	}
}

/*
Funktion, die ein Zeichen in einer Zeichenkette sucht
Parameter:	s[]:	array von chars,
					Zeichenkette, die durchsucht wird
			c:		char,
					Zeichen, nach dem gesucht wird
Rueckgabewert:	-1, wenn das Zeichen c ist in der Zeichenkette s[] nicht vorhanden ist
				positive Ganzzahl als int, deren Wert die erste Stelle entspricht, an der das Zeichen c in der Zeichenkette s[] ist, wobei bei 0 angefangen wird zu zaehlen
*/
int myStrchr(char s[], char c) {
	for (int i = 0; i < myStrlen(s); i++) {
		if (s[i] == c) {
			return i;
		}
	}
	return -1;
}

/*
Funktion, die zwei Zeichenketten zusammenfuegt und die entstandene Zeichenkett in der ersten speichert
Parameter:	s1[]:	array von chars,
					die erste Zeichenkette,
					hier wird die entstehende Zeichenkette gespeichert
			s2[]:	array von chars,
					die zweite Zeichenkette
			n:		positive Ganzzahl als int,
					die maximale Anzahl der Zeichen die in s1[] gespeichert werden koennen
Rueckgabewert:	0, wenn das Zusammenfuegen erfolgreich war,
				-1, wenn das Zusammenfuegen nicht erfolgreich war
*/
int myStrcat(char s1[], char s2[], int n) {
	int laenge1 = myStrlen(s1);
	int laenge2 = myStrlen(s2);

	//Ueberpruefen, ob s1 lang genug ist
	if (laenge1 + laenge2 > n) {
		return -1;
	}
	else {

		//die Zeichenketten Zusammenfuegen und in s1 speichern
		for (int i = 0; i < laenge2; i++) {
			s1[i + laenge1] = s2[i];
		}
		s1[laenge1 + laenge2] = '\0';
	}
	return 0;
}