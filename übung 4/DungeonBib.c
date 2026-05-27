#include "DungeonBib.h"
#include <stdbool.h>
#include <stdlib.h> 



/*
Initialisiert das Spielfeld mit Startwerten.
Legende für die Spielfelder:
- S fuer Spieler
- G fuer Gegner
- A fuer Ausgang
- # fuer Wand
- . fuer leeres Feld
Auf dem Spielfeld sollen der Spieler, der Gegner, der Ausgang sowie sechs Waende platziert werden.
Alle anderen Felder werden mit einem Punkt als leeres Feld markiert.

Parameter:
    feld: 2D-Array, das das Spielfeld speichert

Rueckgabewert:
    keiner
*/
void initSpielfeld(char feld[SIZE][SIZE]) {     //Die Funktion speichert,das mit "start" implementierte Spielfeld in, dem ihr uebergebenen, Vektor
    char start[SIZE][SIZE] = {                  //"start" ist ein, in der Funktion, als 2D Array, gespeichertes Spielfeld
        {'S', '.', '#', '.', '.'},              //"start" und der uebergebene Vektor haben die gleiche Groesse SIZE (= 5)
        {'.', '.', '#', '.', 'G'},
        {'#', '.', 'T', '.', '#'},
        {'.', '#', '#', '.', '.'},
        {'.', '.', '.', 'A', '.'}
    };

    for (int i = 0; i < SIZE; i++) {            //Hier wird der Vektor, der der Funktion uebergeben wurde, gleich "start" gesetzt
        for (int j = 0; j < SIZE; j++) {        //Die Funktion "initSpielfeld" koennte auch in der Datei mit der main-Funktion implementiert werden
            feld[i][j] = start[i][j];
        }
    }
}


/*
Gibt das aktuelle Spielfeld und die verbleibenden Leben des Spielers
auf dem Bildschirm aus.

Parameter:
    feld: 2D - Array mit dem aktuellen Spielfeld
    leben: aktuelle Anzahl an Leben des Spielers

Rueckgabewert:
    keiner(void)
*/
void druckeSpielfeld(char feld[SIZE][SIZE], int leben) {
    printf("\n---------------------------\n");
    printf("Leben: %d\n", leben);
    for (int i = 0;i < SIZE;i++) {
        for (int a = 0;a < SIZE;a++) {
            printf("%c ", feld[i][a]);
        }
        printf("\n");
    }
    printf("\n");
}


/*
Verarbeitet eine Bewegung des Spielers.
Hierfuer fragt die Funktion den Spieler zunaechst nach seinem Zug.
Die moeglichen Optionen sind
- o/O fuer oben
- u/U fuer unten
- l/L fuer links
- r/R fuer rechts
- Wird ein anderes Zeichen eingegeben, so wird die Funktion beendet.
Anschliessend prueft die Funktion den Zug,
passt ggf. die Koordinaten des Spielers per CbR an und
aendert die Position des Spielers auf dem Spielfeld:
- Bei einer Kollision mit einer Wand oder
  einem Zug ausserhalb des 2D-Spielfelds,
  wird der Zug ignoriert.
- Erreicht der Spieler den Ausgang, hat der Spieler gewonnen.

Parameter:
    feld: 2D - Array des Spielfelds
    px, py: aktuelle x- und y-Position des Spielers;
            mittels CbR wird die neue Position des Spielers zuruekgegeben
    status: aktueller Spielstatus(SPIELT, GEWONNEN, VERLOREN);
            mittels CbR wird der neue Status des Spiels zurueckgegeben.

Rueckgabewert:
    keiner
*/
void spielerZug(char feld[SIZE][SIZE], int* spielerPositionX,
    int* spielerPositionY, int* status) {

    //Variablendeklarationen
    char eingabe;
    int hilfeX = *spielerPositionX;
    int hilfeY = *spielerPositionY;
    bool richtigeEingabe;

    do {
        richtigeEingabe = true;

        //Rufen Sie den Benutzer auf, den naechsten Spielzug zu waehlen
        printf("Was wollen Sie tun?\n");

        //Zeigen Sie ihm die moeglichen Optionen
        printf("o/O - Oben, u/U - Unten, r/R - Rechts, l/L - Links, alles Andere - Nichts\n");

        //Lesen Sie die Benutzereingabe sicher von der Konsole ein
        scanf_s("%c", &eingabe, 1);
        while (getchar() != '\n');

        //Aktualisieren Sie die Spielerposition
        //Ueberpruefen, ob der Spieler das Spielfeld verlassen wuerde
        if (*spielerPositionX == 0 && (eingabe == 'l' || eingabe == 'L')) {
            printf("Sie k%cnnen das Spielfeld nicht verlassen.\n", (char)148);
            richtigeEingabe = false;
        }
        if (*spielerPositionX == SIZE - 1 && (eingabe == 'r' || eingabe == 'R')) {
            printf("Sie k%cnnen das Spielfeld nicht verlassen.\n", (char)148);
            richtigeEingabe = false;
        }
        if (*spielerPositionY == 0 && (eingabe == 'o' || eingabe == 'O')) {
            printf("Sie k%cnnen das Spielfeld nicht verlassen.\n", (char)148);
            richtigeEingabe = false;
        }
        if (*spielerPositionY == SIZE - 1 && (eingabe == 'u' || eingabe == 'U')) {
            printf("Sie k%cnnen das Spielfeld nicht verlassen.\n", (char)148);
            richtigeEingabe = false;
        }

        //Ueberpruefen, ob der Spieler eine Wand beruehren wuerde
        if (*spielerPositionY != 0) { //Ueberpruefen, ob die Indizes zulaessig sind
            if (feld[*spielerPositionY - 1][*spielerPositionX] == '#' && (eingabe == 'o' || eingabe == 'O')) {
                printf("Sie k%cnnen nicht auf eine Wand laufen.\n", (char)148);
                richtigeEingabe = false;
            }
        }
        if (*spielerPositionY != SIZE - 1) {
            if (feld[*spielerPositionY + 1][*spielerPositionX] == '#' && (eingabe == 'u' || eingabe == 'U')) {
                printf("Sie k%cnnen nicht auf eine Wand laufen.\n", (char)148);
                richtigeEingabe = false;
            }
        }
        if (*spielerPositionX != 0) {
            if (feld[*spielerPositionY][*spielerPositionX - 1] == '#' && (eingabe == 'l' || eingabe == 'L')) {
                printf("Sie k%cnnen nicht auf eine Wand laufen.\n", (char)148);
                richtigeEingabe = false;
            }
        }
        if (*spielerPositionX != SIZE - 1) {
            if (feld[*spielerPositionY][*spielerPositionX + 1] == '#' && (eingabe == 'r' || eingabe == 'R')) {
                printf("Sie k%cnnen nicht auf eine Wand laufen.\n", (char)148);
                richtigeEingabe = false;
            }
        }
    } while (richtigeEingabe == false);

    //Aktualisieren der Spielerposition
    switch (eingabe) {
    case 'l':
    case 'L':
        *spielerPositionX -= 1;
        break;
    case 'r':
    case 'R':
        *spielerPositionX += 1;
        break;
    case 'o':
    case 'O':
        *spielerPositionY -= 1;
        break;
    case 'u':
    case 'U':
        *spielerPositionY += 1;
        break;
    default:
        return;
    }

    //Aktualisieren Sie ggf. den Spielstatus in Abhaengigkeit vom gewaehlten Spielzug
    //Ueberpruefen, ob die Indizes zulaessig sind. Sie muessen zulaessig sein, da sie oben sonst nicht veraendert werden (Z. 115)
    //aber ohne Ueberpruefung erhaellt man c6385 bzw. c6386
    if (*spielerPositionY < SIZE && *spielerPositionX < SIZE) {
        if (feld[*spielerPositionY][*spielerPositionX] == 'A') {
            *status = GEWONNEN;
        }


        //Erweiterung
        // Spieler betritt einen Teleporter
        if (feld[*spielerPositionY][*spielerPositionX] == 'T') {

            // altes Feld leeren
            feld[*spielerPositionY][*spielerPositionX] = '.';

            // neue zufällige Position finden
            int nx, ny;
            do {
                nx = rand() % SIZE;
                ny = rand() % SIZE;
            } while (feld[ny][nx] != '.');   // nur auf freie Felder teleportieren

            // Spieler versetzen
            *spielerPositionX = nx;
            *spielerPositionY = ny;

            printf("Teleport! Du wurdest zufällig versetzt.\n");
        }


        //Aktualisieren Sie das Spielfeld
        //Die Y-Koordinate gibt die Zeile und die X-Koordinate Spalte an
        feld[*spielerPositionY][*spielerPositionX] = 'S';
        feld[hilfeY][hilfeX] = '.';
    }
}


/*
Von Copilot generiert
//TODO
Funktion, die den Zug des Gegners (Computer) ausfuehrt
Parameter:  feld[][]:    Array, in dem das Spielfeld gespeichert ist
            gx, gy:      Pointer einer positiven Ganzzahl
                         die X-Koordinate bzw. Y-Koordinate des Gegners
            leben:       Pointer einer positiven Ganzzahl
                         die aktuellen Leben des Spielers
            px, py:      positive Ganzzahl
                         die aktuelle X-Koordinate bzw.Y-Koordinate des Spielers
            status:      Pointer einer positiven Ganzzahl
                         der Status des Spiels wird in dieser Variable mithilfe von Konstanten gespeichert
Rueckgabewert: keiner 
 */
void gegnerZug(char feld[SIZE][SIZE], int* gx, int* gy,
    int* leben, int px, int py, int* status) {

    //Hilfsvariablen fuer die Bewegung
    int dx = 0, dy = 0;

    //Ueberpruefen, wie sich der Gegner bewegen muss, um den Spieler zu erreichen
    //wenn z. B. die X-Koordinate des Spielers kleiner ist als die des Gegners, muss sie kleiner werden ( dx = -1)
    if (px < *gx) dx = -1;
    if (px > *gx) dx = 1;
    if (py < *gy) dy = -1;
    if (py > *gy) dy = 1;

    //Variablen zum Speichern der neuen Position des Gegners
    int nx = *gx + dx;
    int ny = *gy + dy;

    //Wenn der Spieler auf der gleichen (neuen) Position wie der Gegner steht, verliert der Spieler ein Leben
    if (feld[nx][ny] == 'S') {
        (*leben)--;
        //Wenn der Spieler keine Leben mehr hat, aendert sich der Status des Spiels zu "VERLOREN" und die Funktion wird beendet
        if (*leben <= 0)
            *status = VERLOREN;
        return;
    }

    // Das Spielfeld wird aktualisiert
    //Nach "initSpielfeld" gibt der erste Index die Zeile und der zweite die Spalte an
    //Hier gibt also die X-Koordinate die Zeile an, waehrend die Y-Koordinate die Spalten angiebt
    //In anderen Funktionen ist das andersherum (z. B. spielerZug)
    if (feld[nx][ny] == '.') {
        feld[*gx][*gy] = '.';
        *gx = nx;
        *gy = ny;
        feld[*gx][*gy] = 'G';
    }
}