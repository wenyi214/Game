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
		printf("����������ٴ�����\n");
		break;
	}

}





	system("pause");
	return 0;
}