#include"test.h"

int main()
{
	srand((unsigned long)time(NULL));
	int quit = 0;
	while (!quit){
		//system("cls");
		Menu();
		int select = 0;
		scanf("%d", &select);
		switch (select){
		case 1:
			Game();
			break;
		case 2:
			quit = 1;
			break;
		default:
			printf("Enter error,Try again\n");
			break;



		}

	}
	system("pause");
	return 0;
}