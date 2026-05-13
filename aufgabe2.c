#include <stdio.h>

int main() {

	char letter1;
	char letter2;
	int num5 = 0;
	int num4 = 0;
	int pruefziffer = 0;
	int check1 = 1;

	while (check1 == 1) {
		printf("Enter the first Letter\n");
		scanf_s("%c", &letter1,1);
		while (getchar() != '\n');

		if ((int)letter1 < 65 || (int)letter1>90) {
			printf("Invalid Entry: Please enter a CAPITAL LETTER\n\n");
			check1=1;
		}
		else {
			letter1 -= 64;
			check1=0;
		}
			
	}
	


	/*printf("Enter the second Letter\n");
	scanf_s(" %c", &letter2);
	while (getchar() != '\n');
	letter2 -= 64; */


	printf("%d \n", letter1);
	//printf("%d \n", letter2);

}