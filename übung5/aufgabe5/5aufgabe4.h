#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


/*
Konstanten fuer die Temperaturueberwachung.
Es werden drei Serverraeume, sechs Messwerte pro Tag und sieben Tage gespeichert.
*/
#define ANZAHL_RAEUME 3
#define ANZAHL_MESSWERTE_PRO_TAG 6
#define ANZAHL_TAGE 7

// Liest die Temperaturwerte fuer alle Raeume, Messwerte und Tage ein.
void einlesen(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG][ANZAHL_TAGE]);

// Ermittelt den hoechsten Messwert ueber alle Raeume, Messwerte und Tage.
void hMesswert(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG][ANZAHL_TAGE]);

// Gibt alle gespeicherten Temperaturwerte tabellarisch auf der Konsole aus.
void temperaturentabelle(double temperaturen[ANZAHL_RAEUME][ANZAHL_MESSWERTE_PRO_TAG][ANZAHL_TAGE]);


