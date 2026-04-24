/*
Datei: aufgabe_5.c
Autor : Pavana
Version : 1.0
Datum : 19.04.2026
Beschreibung : Programm korrigieren 

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

    int zahl = 0;
    /*der Variablen muss ein Wert zugewiesen werden,
     andernfalls werden Zufallszahlen angezeigt*/


    //Der Datentyp double wird f�r Gleitpunktzahlen benutzt
    double pi = 3.14;
    /*semi colon hinzugefuegt, um den Ende der Anweisung
    fuer den Compiler zu definieren*/


    int alter = 20;
    //leerstellen entfernt fuer bessere Lesbarkeit

    printf("Hallo Welt\n");
    //Escape-Sequenz korrigiert fuer Zeilenumbruch




    printf("Zahl: % d\n", zahl);
    /* ' ' zu " geaendert: strings erfodern in
     C doppelte Anfuerungszeichnen */


    printf("Pi: %lf\n", pi);
    /* %f zu %lf geaendert : pi ist als datatyp double
    initialisiert ,nicht als float*/


    printf("Alter: %d\n", alter);
    /* %lf zu %d geaendert : alter ist als datatyp int
    initialisiert, nicht als double */

    return 0;
} /*scliessende klammer von ) zu } korrigiert, um den
   Functionsblock von main funcktion zu beenden*/


   /*
      KI-Unterstützung:
      - Nachgeschlagen, ob "\m" eine besondere Bedeutung wie "\n" hat.
      - Formatbezeichner für double recherchiert (z. B. %lf).
   */