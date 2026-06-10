#pragma once
#define _CRT_SECURE_NO_WARNINGS_

#include<stdio.h>

// Symbolische Konstanten fuer die Groesse des Hoersaals.
#define SITZ_REIHEN 12
#define PLAETZEN 10

void ausgebenHoersaal(char hoersaal[SITZ_REIHEN][PLAETZEN]);// Gibt den aktuellen Sitzplan des Hoersaals auf der Konsole aus.
void besetzeHoersaal(char hoersaal[SITZ_REIHEN][PLAETZEN]);// Besetzt den Hoersaal nach den vorgegebenen Sitzregeln.
int darfsitzen(char hoersaal[SITZ_REIHEN][PLAETZEN], int i , int j);// Prueft, ob sich ein Studierender auf den Platz in Reihe i und Spalte j setzen darf.
int zaehleBelegtePlaetze(char hoersaal[SITZ_REIHEN][PLAETZEN]);// Zaehlt alle belegten Plaetze im Hoersaal.
