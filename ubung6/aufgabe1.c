//Max Schulz, Pavana Shaji

#include <stdio.h>

/*
Funktion, die einen Grossbuchstaben in den entsprechenden Kleinbuchstaben oder einen Kleinbuchstaben in den entsprechenden Grossbuchstaben umwandelt
*/
char buchstabenwandler();

void main() {
	char buchstabe1;		//Der, vom Benutzer eingegebene, Buchstabe
	char buchstabe2;		//Zum Speichern des neuen Buchstabens
	int programmaktiv = 1;	//Um zu Ueberpruefen, ob das Programm noch ausgefuehrt werden soll

	//Einfuehrung des Benutzers
	printf("------------------------------------------------------------------------------------------------------\n");
	printf("Programm, welches ein Gro%cbuchstaben in den entsprechenden Kleinbuchstaben oder andersherum umwandelt\n", (char)225);
	printf("------------------------------------------------------------------------------------------------------\n");
	printf("Es k%cnnen nur lateinische Buchstaben verarbeitet werden.\n", (char)148);
	printf("%c, %c, %c, %c, %c, %c, %c k%cnnen nicht eingegeben werden.\n", (char)142, (char)132, (char)153, (char)148, (char)154, (char)129, (char)225, (char)148);
	printf("Das Programm wird mit '1' beendet.\n");

	//Hauptschleife
	while (programmaktiv == 1) {

		//Eingabe des Benutzers
		printf("Bitte geben Sie einen Buchstaben ein: ");
		scanf_s("%c", &buchstabe1, 1);
		while (getchar() != '\n');

		//Ueberpruefen, ob das Programm beendet werden soll
		if (buchstabe1 == '1') {
			programmaktiv = 0;
			continue;
		}

		//Eingabe Ueberpruefen
		if (((int)buchstabe1 < 65 || (int)buchstabe1 > 122) || ((int)buchstabe1 > 90 && (int)buchstabe1 < 97)) {
			printf("Das ist eine ung%cltige Eingabe.\n", (char)129);
			continue;
		}

		//Verarbeiten
		buchstabe2 = buchstabenwandler(buchstabe1);

		//Ausgabe
		printf("Der umgewandelte Buchstabe lautet: %c\n", buchstabe2);
	}
}

/*
Funktion, die einen Grossbuchstaben in den entsprechenden Kleinbuchstaben oder einen Kleinbuchstaben in den entsprechenden Grossbuchstaben umwandelt
Parameter:	buchstabe:	ein (lateinischer) Buchstabe als char,
						der Buchstabe der umgewandelt werden soll
Rueckgabewert:	der neue Buchstabe als char
*/
char buchstabenwandler(char buchstabe) {

	buchstabe = buchstabe ^ 32;		
	//  a = 0110 0001
	// 32 = 0010 0000
    // ---------------- Exklusiv-ODER(a^32)
	//	A = 0100 0001
	// Groß- und Kleinbuchstaben unterscheiden sich nur im 5. ASCII-Bit;Exklusiv-ODER Operator toggelt dieses Bit.

	return buchstabe;
}