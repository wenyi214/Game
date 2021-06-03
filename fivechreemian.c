#include"fivechree.h"


int main(){
	int quit = 0;
	while (!quit){
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
			printf("Enter Error!\n");
			break;
			
		}

	}
	printf("Byebye\n");
	system("pause");
	return 0;
}