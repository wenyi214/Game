#include"test.h"

void Menu(){
	printf("+---------------+\n");
	printf("+-1.Play 2.Exit-+\n");
	printf("+---------------+\n");
	printf("Please Enter You Select\n");
}
int Computer_guess(int max, int min){
	while (1){
		int x = rand() % 100 + 1;
		if (x >= min&&x <= max){
			return x;
			break;
		}
	}
}

void Game(){
	char ans[10];
	int min = 0;
	int max = 100;
	int x = rand() % 100 + 1;
	printf("Please think of a number <1-100>\n");
	Sleep(3000);
	while (1){

		printf("Is it %d\n", x);
		scanf("%s", ans);
		if (strcmp(ans, "big") == 0){
			max = x - 1;
		}
		else if (strcmp(ans, "small") == 0){
			min = x + 1;
		}
		else if (strcmp(ans, "right") == 0){
			break;
		}
		x = Computer_guess(max,min);
	}
	printf("you lose!\n");

}