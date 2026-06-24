// Pavana Shaji , Max Schulz
/*

Berechnetes Ergebnis                  Programmausgabe
1. Ergebnis: 1						1. Ergebnis: 1
2. Ergebnis: 1						2. Ergebnis: 1
3. Ergebnis: 1						3. Ergebnis: 1	
4. Ergebnis: 63						4. Ergebnis: -1
5. Ergebnis: 2						5. Ergebnis: 2
6. Ergebnis: -3						6. Ergebnis: -2
7. Ergebnis: 2						7. Ergebnis: 2

Analyse des Fehlers in Ergebnis 4:
Die anfängliche Berechnung behandelte die Zahl 52 so, als würde sie nur in 6 Bit gespeichert (110100).
Wird auf diese 6 Bit der bitweise NOT‑Operator(~) angewendet, entsteht 001011; ein anschließendes Exklusiv-ODER(^) 
mit 52 ergibt 111111, was dem Dezimalwert 63 entspricht.
Dieser Ansatz ist jedoch fehlerhaft, da ein int in C nicht 6 Bit, sondern 32 Bit verwendet.
Daher wird 52 tatsächlich als 00000000 00000000 00000000 00110100 gespeichert.
Der bitweise NOT‑Operator(~) invertiert alle 32 Bit, wodurch 11111111 11111111 11111111 11001011 entsteht.
Ein Exklusiv-ODER(^) mit 52 auf dieser 32‑Bit‑Darstellung liefert anschließend 11111111 11111111 11111111 11111111.
In der Zweierkomplementdarstellung entspricht ein 32‑Bit‑Muster, das ausschließlich aus Einsen besteht, dem Wert −1.
Damit ist −1 das korrekte Ergebnis des Ausdrucks.

Analyse des Fehlers in Ergebnis 6:
Bei Ergebnis 6 wurde zunächst angenommen, dass der Ausdruck den Wert −3 liefert, da die Bedingung 
~0 == -1 als falsch interpretiert wurde. Diese Annahme beruhte auf der fehlerhaften Vorstellung, 
dass ~0 lediglich die sichtbaren Bits invertiert und dadurch einen positiven Wert wie 63 ergibt.
Tatsächlich wird 0 jedoch als 32‑Bit‑Wert gespeichert (00000000 00000000 00000000 00000000), und der 
bitweise NOT‑Operator(~) invertiert alle 32 Bit.
Dadurch entsteht das Bitmuster 11111111 11111111 11111111 11111111, welches in der Zweierkomplementdarstellung 
dem Wert −1 entspricht.
Da die Bedingung ~0 == -1 somit wahr ist, wird im ternären Operator der erste Ausdruck ausgewählt, 
sodass das korrekte Ergebnis −2 lautet.
*/

#include <stdio.h>

int main()
{
	int x = 1, y = 1, erg;
	erg = 5 != 6 || 1;
	printf("1. Ergebnis: %d\n", erg);
	erg = x++ || y++;
	printf("2. Ergebnis: %d\n", erg);
	x = 1, y = 1;
	erg = (x--)-(--y);
	printf("3. Ergebnis: %d\n", erg);
	erg = ~52 ^ 52;
	printf("4. Ergebnis: %d\n", erg);
	erg = 1 ? 2 : 3;
	printf("5. Ergebnis: %d\n", erg);
	erg = ~0 == -1 ? -2 : -3;
	printf("6. Ergebnis: %d\n", erg);
	erg = -1 ^ ~0 ? 1 : 2;
	printf("7. Ergebnis: %d\n", erg);
}