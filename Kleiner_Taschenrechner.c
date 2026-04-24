/*Max Schulz*/
#include <stdio.h>
#include <stdbool.h>
int main() {
	int zahl1;
	int zahl2;
	char rechenoperation;
	bool rechnerAktiv = true;

	/*Hauptschleife*/
	while (rechnerAktiv) {
		/*Zahlen abfragen*/
		printf("\nErste Zahl: ");
		scanf_s("%d", &zahl1);
		printf("Zweite Zahl: ");
		scanf_s("%d", &zahl2);

		/*Rechenart abfragen*/
		printf("Rechenoperation eingeben: ");
		/*Leerzeichen vor %c lassen, weil scanf sonst nicht funktioniert, (scanf liest nur \n von vorheriger Zeile und gibt das zurück)*/
		scanf_s(" %c", &rechenoperation, 1);

		/*Rechnen und Ausgeben*/
		switch (rechenoperation) {
		case '+':
		case 'a':
		case 'A':
			printf("\nSumme: %d \n", (zahl1 + zahl2));
			break;
		case '-':
		case 's':
		case 'S':
			printf("\nDifferenz: %d \n", (zahl1 - zahl2));
			break;
		case 'M':
		case '*':
		case 'm':
			printf("\nProdukt: %d \n", (zahl1 * zahl2));
			break;
		case 'D':
		case '/':
		case 'd':
			if (zahl2 != 0) {
				printf("\nQuotient: %.1f \n", ((float)zahl1 / zahl2));
			}
			else
				printf("Man kann nicht durch 0 teilen.\n");
			break;
		case 'R':
		case '%':
		case 'r':
			printf("\nModulo: %d \n", (zahl1 % zahl2));
			break;
		case 'B':
		case 'b':
			rechnerAktiv = false;
			printf("Rechner beendet.");
			break;
		default:
			printf("Die Rechenoperation ist nicht vorhanden.\n");
			break;
		}
	}
	return 0;
}