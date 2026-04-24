/*Max Schulz*/
#include <stdio.h>
#include <stdbool.h>

int main() {
	/*Jahr abfragen*/
	unsigned short jahr;
	printf("Jahr eingeben: ");
	scanf_s("%hu", &jahr);

	/*Jahr auf Schaltjahr überprüfen*/
	bool schaltjahr = true;
	/*Durch 4 teilbar*/
	if (jahr % 4 == 0) {
		schaltjahr = true;
	}
	else
		schaltjahr = false;
	/*Durch 100 teilbar*/
	if (jahr % 100 == 0) {
		schaltjahr = false;
	}
	/*Durch 400 teilbar*/
	if (jahr % 400 == 0) {
		schaltjahr = true;
	}
	/*Ausgabe*/
	if (schaltjahr == true) {
		printf("\n%d ist ein Schaltjahr\n", jahr);
	}
	else
		printf("\n%d ist kein Schaltjahr\n", jahr);
	return 0;
}