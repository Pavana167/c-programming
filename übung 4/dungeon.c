#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DungeonBib.h"
#include <stdlib.h>
#include <time.h>


int main() {
    srand((unsigned int)time(NULL));

    char feld[SIZE][SIZE];
    int spielerPositionX = 0, spielerPositionY = 0;
    int gegnerPositionX = 1, gegnerPositionY = 4; 
    int leben = 3;
    int status = SPIELT;

    //Erweiterung
    int punkte = 0;
    


    initSpielfeld(feld);

    while (status == SPIELT) {
        druckeSpielfeld(feld, leben);
        spielerZug(feld, &spielerPositionX, &spielerPositionY, &status);
        gegnerZug(feld, &gegnerPositionX, &gegnerPositionY, &leben, spielerPositionX, spielerPositionY, &status);

        punkte++; //Erweiterung
    }

    if (status == GEWONNEN)
        printf("\nDu hast gewonnen!\n");
    else
        printf("\nDu hast verloren!\n");


    printf("Gesamtpunkte: %d\n", punkte); //Erweiterung

    return 0;
}