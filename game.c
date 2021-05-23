#include"mytest.h"

int main(){
	int quit = 0;
	while (!quit){
	menu();
	int s = 0;
	scanf("%d", &s);
	switch (s){
	case 1:
		game();
		break;
	case 2:
		quit = 1;
		break;
	default:
		printf("输入错误！请再次输入\n");
		break;
	}

}





	system("pause");
	return 0;
}