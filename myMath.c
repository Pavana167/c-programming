//Max Schulz, Pavana Shaji

/*Fakultätsfunktion*/
double myFakultaet(double val) {
	double fakultaet = 1;

	//Die Funktion soll beliebig große Zahlen verarbeiten können
	for (int i = 1;i < val + 1;i++) {
		fakultaet = fakultaet * i;
	}
	return fakultaet;
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
double mySinus(double x, int genauigkeit) {
	double sinus = 0;

	//Taylorreihe
	//Die Schleife soll so oft, wie "genauigkeit" vorgibt, aber maximal 100 mal, da die Zahlen in myFakultaet zu groß werden, ausgeführt werden
	if (genauigkeit <= 100) {
		for (int i = 0;i <= genauigkeit;i++) {
			sinus = sinus + (myPow(-1, i) * (myPow(x, 2 * i + 1) / myFakultaet(2 * i + 1)));
		}
	}
	return sinus;
}
