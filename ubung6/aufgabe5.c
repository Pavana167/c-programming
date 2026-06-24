// Pavana Shaji, Max Schulz

#include <stdio.h>

int main() {
	
	// Jede Person bekommt ein Bit
	int A = 1; // 0001
	int B = 2; // 0010
	int C = 4; // 0100
	int D = 8; // 1000

	printf("Familienfeier - gueltige Kombinationen\n");
	printf("--------------------------------------\n\n\n");
	printf("Gueltige Kombinationen sind:\n");

	int count = 0; // Zaehler fuer gueltige Kombinationen
	for (int komb = 0; komb < 16; komb++) { // alle 16 moeglichen Kombinationen (0000 bis 1111)
        
		// Mit Bitmasken pruefen, ob jemand geht
		int A_geht = (komb & A);					//Beispiel: komb = 5
		int B_geht = (komb & B);					//Binaerdarstellung: 0101
		int C_geht = (komb & C);
		int D_geht = (komb & D);					//Pruefung mit Bitmasken:
													// A_geht = 0101 & 0001 = 0001 : Wert = 1 : (nicht 0) Andreas geht
													// B_geht = 0101 & 0010 = 0000 : Wert = 0 : Bine bleibt zuhause
													// C_geht = 0101 & 0100 = 0100 : Wert = 4 : (nicht 0) Conni geht
													// D_geht = 0101 & 1000 = 0000 : Wert = 0 : Dennis bleibt zuhause
													//if (A_geht) --> true, Andreas geht
													//if (!B_geht) --> true, Bine bleibt zuhause 
							
		if (!A_geht && !B_geht && !C_geht && !D_geht) continue;		// Regel 1: Mindestens eine Person muss gehen
		if (D_geht && A_geht) continue;								// Regel 2: Andreas und Dennis duerfen nicht zusammen gehen
		if (B_geht && !C_geht) continue;							// Regel 3: Wenn Bine geht, muss Conni auch gehen
		if ((A_geht && C_geht) && B_geht) continue;					// Regel 4: Wenn Andreas und Conni gehen, muss Bine zuhause bleiben
		if (!A_geht && !C_geht && !D_geht) continue;				// Regel 5: Wenn Andreas zuhause bleibt, muss Conni oder Dennis gehen oder beide

		// Ausgabe: nur gueltige Kombinationen
		printf("Kombination %d : ", ++count);
		if (A_geht) printf("Andreas ");
		if (B_geht) printf("Bine ");
		if (C_geht) printf("Conni ");
		if (D_geht) printf("Dennis ");
		printf("\n");
	}
	return 0;
}