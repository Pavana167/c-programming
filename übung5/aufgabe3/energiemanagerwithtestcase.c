//Max Schulz, Pavana Shaji

#include <stdio.h>

/*
@brief Diese Funktion liest eine Ganzzahl in einem bestimmten Intervall von der Tastatur ein.
Falls der Benutzer eine ungueltige Ganzzahl eingibt, wird der Benutzer zur erneuten Eingabe aufgefordert.
Dies geschieht solange, bis der Benutzer eine gueltige Ganzzahl eingibt.

@param min Dies ist die Untergrenze des gueltigen Intervalls.
@param max Dies ist die Obergrenze des gueltigen Intervalls.

@returns Die eingelesene Ganzzahl oder "0", wenn min > max
*/
int einlesenIntIntervall(int min, int max) {
	double eingabe;				//Vom Benutzer eingegebene Zahl, double statt int, damit Gleitunktzahlen erkannt und nicht abgeschnitten werden
	double hilfe;				//Hilfswert zum Rechnen
	int eingabeRichtig = 0;		//Abbruchbedingung fuehr die Schleife

	//Ueberpruefen, ob min < max
	//Wenn min > max ist, wird eine Endlosschleife entstehen, da "eingabe" dann nicht gleichzeitig groesser als "min" und kleiner als "max" sein kann
	//Wenn max = min gibt es nur eine Eingabemoeglichkeit
	if (min > max) {
		return 0;
	}
	int check = 0;
	while(eingabeRichtig == 0){

		//Eingabe
		if (check == 1) {
			printf("\nBitte geben Sie eine Ganzzahl zwischen %d und %d ein: ", min, max);
		}
		

		//Pruefen, ob die Eingabe eine Zahl ist
		if (scanf_s("%lf", &eingabe) == 0) {
			printf("Das ist keine Zahl.");
			while (getchar() != '\n');
			check = 1;
			continue;
		}
		while (getchar() != '\n');

		//Eingabe pruefen
		//Eingabe auf Ganzzahl pruefen
		if (eingabe < 0) {
			hilfe = eingabe * -1;
		}
		else {
			hilfe = eingabe;
		}
		while (hilfe > 0) {
			hilfe--;
		}
		if (hilfe < 0) {
			printf("Die Zahl muss eine Ganzzahl sein.");
			check = 1;
			continue;
		}

		//Pruefen, ob die Eingabe im Intervall liegt
		if (eingabe > max) {
			printf("Die Zahl ist zu gross.");
			check = 1;
			continue;
		}
		else if (eingabe < min) {
			printf("Die Zahl ist zu klein.");
			check = 1;
			continue;
		}
		else {
			eingabeRichtig = 1;
		}
	}
	return (int)eingabe;
}
/*
 Function: einlesenIntIntervall

Test fall 1:
Eingabe parameters: min = 1, max = 5
Benutzer Eingabe: 3
Erwartete Ausgabe: 3
Erklärung: 3 ist ein integer and liegt innerhalb der  interval [1, 5].

Test fall 2:
Eingabe parameters: min = 1, max = 5
Benutzer Eingabe: 8, then 4
Erwartete Ausgabe: 8 wird abgelehnt, da es zu groß ist. 4 wird akzeptiert und zurückgegeben.
*/

/**
@brief Die Funktion berechnet die Kosten in Euro fuer die durch den Parameter energie gegebene Energie in kWh.
Die Kosten berechnen sich nach der folgenden Staffel:
- Energie betraegt weniger als 20 kWh -> Die kWh kostet 40Ct.
- Energie betraegt weniger als oder genau 50 kWh -> Die kWh kostet 35Ct.
- Energie betraegt mehr als 50 kWh -> Die kWh kostet 30Ct.
- Falls die Energie 40 kWh uebersteigt, faellt ein Kostenzuschlag von 10% an.

@param energie Fuer die gegebene Energie in kWh sollen die Kosten in Euro berechnet werden.

@returns Die Funktion gibt die Kosten für die Energie in Euro oder "-1", falls der Parameter energie < 0 ist, zurueck.
*/
double kostenBerechnenMitTarif(double energie) {
	double kosten = 0;		//Der Rueckgabewert

	//Parameter ueberpruefen
	if (energie < 0) {
		return -1;
	}

	//Kosten anhand der Energiemenge Berechnen
	if (energie < 20) {
		kosten = 0.4 * energie;
	}
	else if (energie <= 50) {
		kosten = 0.35 * energie;
	}
	else if (energie > 50) {
		kosten = 0.3 * energie;
	}

	//Kostenzuschlag berechnen
	if (energie > 40) {
		kosten = kosten * 1.1;
	}
	return kosten;
}

/*
Funktion: kostenBerechnenMitTarif

Testfall 1:
Eingabe: energie = 10
Erwartete Ausgabe: 4.00
Erklärung: 10 kWh liegt unter 20 kWh, daher beträgt der Preis 0,40 Euro/kWh.
10 * 0,40 = 4,00

Testfall 2:
Eingabe: energie = 45
Erwartete Ausgabe: 17.325
Erklärung: 45 kWh ist <= 50, daher beträgt der Preis 0,35 Euro/kWh.
Da 45 > 40 ist, wird ein Zuschlag von 10 % hinzugefügt.
45 * 0,35 * 1,1 = 17,325
*/

/*
void main() {
	double eingabe;
	scanf_s("%lf", &eingabe);
	printf("%lf", kostenBerechnenMitTarif(eingabe));
}
*/


void main() {
	einlesenIntIntervall(-100, 100);
}




/*
Übergreifender Testfall für das Gesamtprogramm:

Zu Beginn sind alle 10 Ladesäulen frei. Daher gilt:
typen[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
zeiten[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

Im ersten Schritt wird über das Menü ein neuer Ladevorgang gestartet. 
Dazu wird die Menüauswahl 1 eingegeben. Als Ladetyp wird 2 gewählt und als 
Ladezeit werden 60 Minuten eingegeben. Der Ladevorgang soll an der ersten freien 
Ladesäule, also Ladesäule 1, gestartet werden. Danach gilt:
typen[] = {2, 0, 0, 0, 0, 0, 0, 0, 0, 0}
zeiten[] = {60, 0, 0, 0, 0, 0, 0, 0, 0, 0}

Im zweiten Schritt wird wieder die Menüauswahl 1 eingegeben, um einen weiteren 
Ladevorgang zu starten. Als Ladetyp wird 3 gewählt und als Ladezeit werden 30 Minuten 
eingegeben. Dieser Ladevorgang soll an Ladesäule 2 gestartet werden. Danach gilt:
typen[] = {2, 3, 0, 0, 0, 0, 0, 0, 0, 0}
zeiten[] = {60, 30, 0, 0, 0, 0, 0, 0, 0, 0}

Im dritten Schritt wird erneut die Menüauswahl 1 eingegeben. Als Ladetyp wird 1 gewählt 
und als Ladezeit werden 90 Minuten eingegeben. Dieser Ladevorgang soll an Ladesäule 3 
gestartet werden. Danach gilt:
typen[] = {2, 3, 1, 0, 0, 0, 0, 0, 0, 0}
zeiten[] = {60, 30, 90, 0, 0, 0, 0, 0, 0, 0}

Die Gesamtleistung der drei laufenden Ladevorgänge beträgt:
LADETYP2 = 11,0 kW
LADETYP3 = 22,0 kW
LADETYP1 = 3,7 kW
Gesamtleistung = 11,0 kW + 22,0 kW + 3,7 kW = 36,7 kW.
Da 36,7 kW kleiner als MAX_GESAMTLEISTUNG_KW = 100 kW ist, entsteht keine Überlast und
alle drei Ladevorgänge dürfen gestartet werden.

Im vierten Schritt wird die Menüauswahl 3 eingegeben, um die aktuelle Gesamtleistung
und die aktuelle Gesamtenergie anzeigen zu lassen. Erwartet wird eine Gesamtleistung von 36,70 kW.
Die erwartete Gesamtenergie wird wie folgt berechnet: Für Ladesäule 1 mit Ladetyp 2 und 
60 Minuten ergibt sich 11,0 * 60 / 60 = 11,0 kWh. Für Ladesäule 2 mit Ladetyp 3 und 30 Minuten 
ergibt sich zuerst 22,0 * 30 / 60 = 11,0 kWh. Da 30 Minuten ein Kurzladevorgang ist, wird die 
Energie um 10 Prozent erhöht: 11,0 * 1,1 = 12,1 kWh. Für Ladesäule 3 mit Ladetyp 1 und 90 Minuten 
ergibt sich zuerst 3,7 * 90 / 60 = 5,55 kWh. Da 90 Minuten ein Langladevorgang ist, wird die Energie 
um 5 Prozent verringert: 5,55 * 0,95 = 5,2725 kWh. Die Gesamtenergie beträgt
somit 11,0 + 12,1 + 5,2725 = 28,3725 kWh. Erwartete Ausgabe: ungefähr 28,37 kWh.

Im fünften Schritt wird die Menüauswahl 2 eingegeben, um einen Ladevorgang zu beenden. Es wird Ladesäule 2 ausgewählt. 
Dort läuft aktuell ein Ladevorgang mit Ladetyp 3 und 30 Minuten Ladezeit. Die Energie dieses Ladevorgangs beträgt wie 
oben berechnet 12,1 kWh. Da 12,1 kWh weniger als 20 kWh sind, kostet eine kWh 0,40 Euro. Die Kosten betragen 
daher 12,1 * 0,40 = 4,84 Euro. Erwartet wird, dass das Programm ungefähr 12,10 kWh und 4,84 Euro ausgibt. Anschließend 
muss der Ladevorgang an Ladesäule 2 beendet werden, indem Ladetyp und Ladezeit auf 0 gesetzt werden. Danach gilt:
typen[] = {2, 0, 1, 0, 0, 0, 0, 0, 0, 0}
zeiten[] = {60, 0, 90, 0, 0, 0, 0, 0, 0, 0}

Im sechsten Schritt wird erneut die Menüauswahl 3 eingegeben. Jetzt laufen nur noch die Ladevorgänge an Ladesäule 1 und
Ladesäule 3. Die erwartete Gesamtleistung beträgt 11,0 kW + 3,7 kW = 14,7 kW. Die erwartete Gesamtenergie
beträgt 11,0 kWh + 5,2725 kWh = 16,2725 kWh. Erwartete Ausgabe: ungefähr 14,70 kW und 16,27 kWh.

Im siebten Schritt wird das Programm durch Eingabe einer beliebigen anderen Ziffer, zum Beispiel 9, beendet. Beim Beenden 
berechnet das Programm die Gesamtenergie und die Kosten für die noch laufenden Ladevorgänge. Es laufen noch 
Ladesäule 1 und Ladesäule 3. Die Gesamtenergie beträgt 16,2725 kWh, also ungefähr 16,27 kWh. Die Kosten für Ladesäule 1 
betragen 11,0 * 0,40 = 4,40 Euro. Die Kosten für Ladesäule 3 betragen 5,2725 * 0,40 = 2,109 Euro. Die Gesamtkosten für die 
noch laufenden Ladevorgänge betragen daher 4,40 + 2,109 = 6,509 Euro. Erwartete Ausgabe: ungefähr 16,27 kWh und 6,51 Euro.

Mit diesem Testfall werden das Starten von Ladevorgängen, die Prüfung der Gesamtleistung, die Berechnung der Gesamtenergie, 
der Kurzladevorgang-Zuschlag, die Langladevorgang-Reduktion, das Beenden eines Ladevorgangs, die Kostenberechnung mit 
Tarif sowie die Aktualisierung der Arrays typen[] und zeiten[] getestet.

*/