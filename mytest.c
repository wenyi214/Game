#include"mytest.h"


void menu(){
	printf("###################\n");
	printf("##1.play   2.exit##\n");
	printf("###################\n");
}

void init(char str[][L]){
	int i = 0;
	for (; i < H; i++){
		int j = 0;
		for (; j < L; j++){
			str[i][j] = Q;
		}
	}
}

void show(char str[][L]){
	printf("    1| 2| 3|\n");
	printf(" -----------\n");
	int i = 0;
	for (; i < H; i++){
		printf(" %d|",i+1);
		int j = 0;
		for (; j < L; j++){
			printf("%c |", str[i][j]);
		}
		printf("\n");
		printf(" -----------\n");
	}
}

void comput(char str[][L]){
	while (1){
		int x = rand() % H;
		int y = rand() % L;   //对3取余范围0 1 2
		if (str[x][y] == Q){     
			str[x][y] = C;
			break;
		}
	}


}

char judge(char str[][L]){
	int i = 0;
	for (; i < H; i++){
		if (str[0][i] == str[1][i] && str[1][i] == str[2][i] && \
			str[0][i] != Q&&str[1][i] != Q&&str[2][i] != Q){
			return str[0][i];
		}
	}
	for (i = 0; i < L; i++){
		if (str[i][0] == str[i][1] && str[i][1] == str[i][2] && \
			str[i][0] != Q&&str[i][1] != Q&&str[i][2] != Q){
			return str[i][1];
		}                                                                      //未排除‘ ’情况
	}
	if (str[1][1] == str[0][0] && str[1][1] == str[2][2] && \
		str[1][1] != Q && str[0][0] != Q &&str[2][2] != Q){
		return str[1][1];
	}
	if (str[1][1] == str[0][2] && str[1][1] == str[2][0] && \
		str[1][1] != Q && str[0][2] != Q &&str[2][0] != Q){
		return str[1][1];
	}
	for (i = 0; i < H; i++){
		int j = 0;
		for (; j < L; j++){
			if (str[i][j] == Q){
				return 'N';
			}
		}
	}
	return 'F';
	
}


void game(){
	char str[H][L];
	int x = 0;
	int y = 0;
	char result;
	init(str);//将棋盘中的每一位赋值为‘ ’
	do{
		srand((unsigned long )time(NULL));
		show(str);//展示棋盘
		printf("please input <x,y>:");
		scanf("%d%d" ,&x,&y);
		if (x<1 || x>3 || y<1 || y>3){
			printf("超过范围，请重新输入\n");   //判断是否超过范围，需放在判断位置是否被填入之前，别的位置随机数可能不为空。
			continue;
		}
		if (str[x-1][y-1] != Q){
			printf("该位置已被填入\n");    //判断位置是否被填入
			continue;
		}
		str[x - 1][y - 1] = P;
		result = judge(str);  //判断情况有人赢 电脑赢 下满了没人赢   没下满      
		if (result != 'N'){
			break; //这样的条件退出好
		}
		comput(str);
		result = judge(str);
		if (result != 'N'){
			break;
		}
	} while (1);
	if (result == P){
		printf("you are win!\n");
	}
	else if (result == C){
		printf("you are lose!\n");    
	}
	else{
		printf("tie game!\n");
	}
	
}