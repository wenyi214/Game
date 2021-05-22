#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#pragma warning (disable:4996)

#define ID "TOM"
#define PASSWARD "12345"

void Menu(){
	printf("+----------------+\n");
	printf("+-1.play  2.exit-+\n");
	printf("+----------------+\n");
}


void Guess(){
	int num = rand() % 100 + 1;
	int guess = 0;
	printf("Please Gusee\n");
	while (1){
		scanf("%d", &guess);
		if (guess > num){
			printf("It is big!\n");
		}
		else if (guess < num){
			printf("It is small\n");
		}
		else{
			printf("you are right!\n");
			break;
		}
	}
}





void Game(){
	srand((unsigned long)time(NULL));
	int quit = 0;
	while (!quit){
		Menu();
		int select = 0;
		scanf("%d", &select);
		switch (select){
		case 1:
			Guess();
			break;
		case 2:
			quit = 1;
			break;
		default:
			printf("Enter error! Please Try again\n");
			break;
		}
	}

}




int main(){
	char name[64];
	char passward[64];
	int count = 3;
	while (count>0){
		printf("id:");
		scanf("%s", name);
		printf("passwd:");
		scanf("%s", passward);
		if (strcmp(name, ID) == 0 && strcmp(passward, PASSWARD) == 0){
			break;
		}
		count--;
		printf("id or passward error,you have %d chance\n", count);
	}
	if (count > 0){
		int i = 5;
		for (; i>0; i--){
			printf("Logining.....%d\r",i);
			Sleep(1000);
		}
		Game();
	}
	else{
		printf("Login Fail\n");
	}




	system("pause");
	return 0;
}