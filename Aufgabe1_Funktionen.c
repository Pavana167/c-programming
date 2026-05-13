//Max Schulz, Pavana Shaji
#include <stdio.h>
#include <math.h>

/*Fakultätsfunktion*/
double myFakultaet(double val) {
	double fakultaet = 1;

	//Die Funktion soll nur für val <= 20 ausgeführt werden
	if (val <= 20) {
		for (int i = 1;i < val + 1;i++) {
			fakultaet = fakultaet * i;
		}
		return fakultaet;
	}
	else {
		return 0;
	}
}

/*Exponentialfunktion*/
double myPow(double x, int i) {
	double potenz = 1.0;
	for (int a = 0;a < i; a++) {
		potenz *= x;
	}
	return potenz;
}

//Sinusfnuktion
double mySinus(double x) {
	double sinus = 0;

	//Taylorreihe
	//i < 10, da myFakultaet nur für Werte <= 20 funktioniert, 2 * i + 1 <= 20
	for (int i = 0;i < 10;i++) {
		sinus = sinus + (myPow(-1,i) * (myPow(x, 2 * i + 1) / myFakultaet(2 * i + 1)));
	}
	return sinus;
}

// Funktion zum Überprüfen, ob ein Wert eine Ganzzahl ist
int intcheck(double i) {
	while (i > 0) {
		i--;
	}
	/*
	Wenn i = 0 ist, ist eingabe restlos durch 1 teilbar, dann ist eingabe eine ganzzahl,
	wenn i < 0 ist, ist eingabe < 0 oder eingabe ist nicht restlos durch 1 teilbar, dann ist eingabe eine Gleitpunktzahl
	*/
	if (i < 0) {
		return 0;
	}
	if (i == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

/*Hauptschleife*/
int main() {

	// Einführung des Benutzers
	printf("---Programm zur Berechnung von Fakult%cts-, Exponential-, und Sinusfunktion---\n",(char)132);
	printf("Gib 'B' zum beenden des Programms ein.\n");
	printf("Fakult%ct: F, Potenz: E, Sinus: S\n",(char)132);

	//Was der Benutzer berechnen möchte
	char operation;

	//Ob das Programm noch ausgeführt werden soll
	int programmaktiv = 1;

	//Wiederholung des Programms
	while (programmaktiv == 1) {

		/*Herrausfinden, welche Operation ausgeführt werden soll*/
		printf("\nWas soll getan werden? ");
		scanf_s("%c", &operation, 1);

		/*Operation ausführen*/
		switch (operation) {
			case '!':
			case 'f':
			case 'F' :{

				/*Wert eingeben, float, damit Gleitpunktzahlen erkannt und nicht abgeschnitten werden*/
				float eingabe;
				printf("Bitte geben Sie eine ganze Zahl von 0 bis 20 ein: ");
				scanf_s("%f", &eingabe);
				while (getchar() != '\n');

				/*Wert überprüfen*/
				if (eingabe <= 20 && intcheck(eingabe) == 1) {

					/*Fakultätsfunktion ausführen und ausgeben*/
					printf("%.0f! = %.0lf", eingabe, myFakultaet(eingabe));
				}
				else {
					printf("Sie haben eine ung%cltige Zahl eingegeben.\n", (char)129);
				}
				break;
			}
			case '^':
			case 'e':
			case 'E' :{
				double basis;
				//double, damit Gleitpunktzahlen erkannt werden
				double exponent;

				//Werte eingeben
				printf("Wie lautet die Basis? ");
				scanf_s("%lf", &basis);
				while (getchar() != '\n');
				printf("Geben Sie den Exponenten als positive Ganzzahl an: ");
				scanf_s("%lf", &exponent);
				while (getchar() != '\n');

				// Exponenten Überprüfen
				if (exponent < 0 || intcheck(exponent) == 0) {
					printf("Es wurde eine ung%cltige Zahl eingegeben.\n", (char)129);
				}
				else {

					//Potenz berechnen und ausgeben
					printf("%lf\n", myPow(basis, (int)exponent));
					printf("%lf", pow(basis, exponent));
				}
				break;
			}
			case 's':
			case 'S': {
				double bogenmass;

				//Wert eingeben
				printf("Geben Sie einen Wert in Bogenmass zwischen -6.4 und 6.4 an: ");
				scanf_s("%lf", &bogenmass);
				while (getchar() != '\n');

				//Wert überprüfen
				if (bogenmass >= -6.4 && bogenmass <= 6.4) {

					// Sinus berechnen und ausgeben
					printf("sin(%.2lf) = %.2lf",bogenmass, round(mySinus(bogenmass)*100)/100);
				}
				else {
					printf("Es wurde eine ung%cltige Zahl eingegeben.", (char)129);
				}
				break;
			}
			case 'b':
			case 'B': {
				programmaktiv = 0;
				break;
			}
			default: {
				printf("Es wurde eine ung%cltige Eingabe gemacht.", (char)129);
				while (getchar() != '\n');
				break;
			}
		}
	}
	return 0;
}