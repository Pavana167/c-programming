#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Makros
#define SIZE 5
#define SPIELT 0
#define GEWONNEN 1
#define VERLOREN 2

//Prototypen der Funktionen
void initSpielfeld(char feld[SIZE][SIZE]);
void druckeSpielfeld(char feld[SIZE][SIZE], int leben);
void spielerZug(char feld[SIZE][SIZE], int* spielerPositionX,
    int* spielerPositionY, int* status);
void gegnerZug(char feld[SIZE][SIZE], int* gx, int* gy,
    int* leben, int px, int py, int* status);
