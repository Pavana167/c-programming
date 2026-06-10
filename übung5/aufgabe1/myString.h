//Max Schulz, Pavana Shaji

#pragma once

//Maximale Laenge der Zeichenkette
#define SIZE 1000

/*
Funktion die, die Zeichen einer Zeichenkette zaehlt
Parameter:	s[]:	array von chars,
					Zeichenkette, deren Laenge gezaehlt wird
Rueckgabewert:	positive Ganzzahl als int,
				Anzhal der Zeichen
*/
int myStrlen(char s[]);

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
int myStrcmp(char string1[], char string2[]);

/*
Funktion, die ein Zeichen in einer Zeichenkette sucht
Parameter:	s[]:	array von chars,
					Zeichenkette, die durchsucht wird
			c:		char,
					Zeichen, nach dem gesucht wird
Rueckgabewert:	-1, wenn das Zeichen c ist in der Zeichenkette s[] nicht vorhanden ist
				positive Ganzzahl als int, deren Wert die erste Stelle entspricht, an der das Zeichen c in der Zeichenkette s[] ist, wobei bei 0 angefangen wird zu zaehlen
*/
int myStrchr(char s[], char c);

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
int myStrcat(char s1[], char s2[], int n);