//Max Schulz , Pavana Shaji

#include <stdio.h>

// Da hier nur `scanf` verwendet wird, müsste man eigentlich
// `_CRT_SECURE_NO_WARNINGS` definieren, um die Warnungen zu unterdrücken.
// Problem : Ohne diese Einstellung gibt es Compiler-Warnungen.
// Vorschlag : Entweder `scanf_s` verwenden oder `_CRT_SECURE_NO_WARNINGS` setzen.





// Funktion: Getränk kaufen
void kaufeGetraenk(int* bestand, int* verkauft, double preis, double* umsatz) {
    if (*bestand > 0) {
        (*bestand)--;
        (*verkauft)++;
        (*umsatz) += preis;
        printf("Getraenk verkauft!\n");
    }
    else {
        printf("Kein Getraenk mehr verfuegbar!\n");
    }
}

// Funktion: Getränke nachfüllen
void fuelleNach(int* bestand, int* nachfuellVorgaenge) {
    int menge;
    printf("Wie viele Getraenke sollen nachgefuellt werden? ");

    if (scanf("%d", &menge) == 1 && menge > 0) {
        *bestand += menge;
        (*nachfuellVorgaenge)++;
        printf("Nachfuellen erfolgreich!\n");
    }
    else {
        printf("Ungueltige Eingabe beim Nachfuellen!\n");
        // PROBLEM: Ungueltige Eingaben beim Nachfuellen werden zwar erkannt,
        // aber nicht im Zaehler "ungueltigeEingaben" beruecksichtigt.
        // VORSCHLAG : "ungueltigeEingaben" muss hier ebenfalls inkrementiert werden.
    }
}

int main() {
    double preis, umsatz = 0.0;
    int bestand, startbestand;
    char abbruchZeichen;

    // Statistikvariablen
    int verkauft = 0;
    int nachfuellVorgaenge = 0;
    int ungueltigeEingaben = 0;


    printf("Preis eines Getraenks: ");
    scanf("%lf", &preis);
    // PROBLEM: Keine Eingabeprüfung (negative und nicht-numerische Werte führen zu Fehlern)
    // Vorschlag: Eingabevalidierung mit Schleife und Pufferbereinigung verwenden


    printf("Startbestand: ");
    scanf("%d", &bestand);
    // PROBLEM: Keine Eingabeprüfung (negative und nicht-numerische Werte führen zu Fehlern)
    // Vorschlag: Eingabevalidierung mit Schleife und Pufferbereinigung verwenden
    startbestand = bestand;

    printf("Abbruchzeichen: ");
    scanf(" %c", &abbruchZeichen);
    // Problem: 'K' und 'N' könnten hier eingegeben werden, werden aber später für andere Funktionen benötigt
    // Vorschlag: Eingabe mit Schleife prüfen und 'K' und 'N' ablehnen (bei Fehler erneut abfragen)



    // Laufzeit des Automaten
    char eingabe;
    while (1) {
        printf("\nAktion (k = kaufen, n = nachfuellen, %c = beenden): ", abbruchZeichen);
        scanf(" %c", &eingabe);

        if (eingabe == abbruchZeichen) {
            break;
        }

        switch (eingabe) {
        case 'k':
            //case 'K': (could be added)
            kaufeGetraenk(&bestand, &verkauft, preis, &umsatz);
            break;

        case 'n':
            //case 'N': (could be added)
            fuelleNach(&bestand, &nachfuellVorgaenge);
            break;

        default:
            printf("Ungueltige Eingabe!\n");
            ungueltigeEingaben++;
            break;
        }
    }

    // Endausgabe
    printf("\n--- Statistik ---\n");
    printf("Startbestand: %d\n", startbestand);
    printf("Endbestand: %d\n", bestand);
    printf("Verkaufte Getraenke: %d\n", verkauft);
    printf("Nachfuellvorgaenge: %d\n", nachfuellVorgaenge);
    printf("Ungueltige Eingaben: %d\n", ungueltigeEingaben);
    printf("Gesamtumsatz: %.2f\n", umsatz);

    return 0;
}