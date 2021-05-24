#include"game.h"


void Menu(){
	printf("#####################\n");
	printf("##1.Play     2.Exit##\n");
	printf("#####################\n");
	printf("Please input you select:");
}



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
			printf("Byebye\n");
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}
	}



	system("pause");
	return 0;

}