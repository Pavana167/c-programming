

#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int year = 0;

	printf("Enter the year\n");
	scanf_s("%d", &year);

	if (year % 4 == 0 && year % 100 != 0) {
		printf("The year %d is a leap year\n", year);

	}
	else 
		if (year % 400 == 0) {
			printf("The year %d is a leap year\n", year);

		}
		else {
			printf("The year %d is not a leap year\n", year);

		}

	return 0;
	
}

