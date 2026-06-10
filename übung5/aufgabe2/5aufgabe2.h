#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


/*
Konstanten fuer die Anzahl der Raeume und Messwerte.
Jeder Raum besitzt sechs Messwerte fuer einen Tag.
*/
#define ANZAHL_RAEUME 3
#define ANZAHL_MESSWERTE_PRO_TAG 6


//Funktionsprototypen fuer die Temperaturueberwachung
void einlesen(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG]);
void durchschnitt(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG], int messwerteProRaum);
void hMesswert(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG]);
void stbRaum(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG]);
void temperaturentabelle(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG]);
