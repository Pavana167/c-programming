
      //Datei: aufgabe_4.c
	  //Autor: Pavana
	  //Version: 2.0
	  //Datum: 19.04.2026
	  //Beschreibung: Untersuchung der Ausgabe von Sonderzeichen und Korrektur 
	  //eines Programms mit falscher Zeichenkodierung.
	
	  


#include <stdio.h>

// windows.h wird benötigt, um die Windows-Funktion SetConsoleOutputCP verwenden zu können
#include <windows.h>

int main() {
	// Konsole auf UTF-8 umstellen, damit die Sonderzeichen „ü“ und „ß“ korrekt ausgegeben werden
	SetConsoleOutputCP(65001);

	printf("Und tschüß!\n");
	return 0;
}

/*
	KI-Unterstützung :
	- Erklärung des Encoding-Problems erhalten (UTF-8 vs. Windows-Codepage).
	- Lösung zur korrekten Ausgabe der Sonderzeichen gefunden
	  (SetConsoleOutputCP(65001) für UTF-8 in der Windows-Konsole).
*/

