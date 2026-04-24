
	/*
	Datei: aufgabe_3.c
	Autor: Pavana
	Version: 2.0
	Datum: 19.04.2026
	Beschreibung: Begrüßung, Datum einlesen, eigene Erweiterung, Verabschiedung
	*/




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int tag = 0;
	int monat = 0;
	int jahr = 0;

	//Begruessung
	printf("Hallo\n");

	//Datum Abfrage
	printf("Geben Sie den Tag ein:\n");
	scanf_s("%d", &tag);
	printf("Geben Sie den Monat ein:\n");
	scanf_s("%d", &monat);
	printf("Geben Sie das Jahr ein:\n");
	scanf_s("%d", &jahr);

	//Ausgabe des Datums
	printf("Heute ist der %d.%d.%d.\n", tag, monat, jahr);


	char name[20];
	char ort[20];
	char hobby[20];
	char studium[20];
	int alter = 0;
	int lieblingszahl = 0;


	//Benutzer nach persönlichen Daten fragen
	printf("Wie heissen Sie?\n");
	scanf_s("%s", name, 20);

	printf("Wie alt sind Sie?\n");
	scanf_s("%d", &alter);

	printf("Wo wohnen Sie?\n");
	scanf_s("%s", ort, 20);

	printf("Was ist Ihr Hobby?\n");
	scanf_s("%s", hobby, 20);

	printf("Was ist Ihre Lieblingszahl?\n");
	scanf_s("%d", &lieblingszahl);

	printf("Was Studieren Sie?\n");
	scanf_s("%s", studium, 20);




	//Ausgabe der Persoenlichen Beschreibung
	printf("\n --- Ihre persoenliche Beschreibung--- \n");
	printf("Sie heissen %s und sind %d Jahre alt.\n", name, alter);
	printf("Sie wohnen in %s und Ihr Hobby ist %s.\n", ort, hobby);
	printf("Ihre Lieblingszahl ist %d. und Sie studieren %s\n", lieblingszahl, studium);


	//Verabschiedung
	printf("\nViel Spass und viel Erfolg beim Programmieren!\n");


	return 0;

}