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
		int y = rand() % L;   //��3ȡ�෶Χ0 1 2
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
		}                                                                      //δ�ų��� �����
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
	init(str);//�������е�ÿһλ��ֵΪ�� ��
	do{
		srand((unsigned long )time(NULL));
		show(str);//չʾ����
		printf("please input <x,y>:");
		scanf("%d%d" ,&x,&y);
		if (x<1 || x>3 || y<1 || y>3){
			printf("������Χ������������\n");   //�ж��Ƿ񳬹���Χ��������ж�λ���Ƿ�����֮ǰ�����λ����������ܲ�Ϊ�ա�
			continue;
		}
		if (str[x-1][y-1] != Q){
			printf("��λ���ѱ�����\n");    //�ж�λ���Ƿ�����
			continue;
		}
		str[x - 1][y - 1] = P;
		result = judge(str);  //�ж��������Ӯ ����Ӯ ������û��Ӯ   û����      
		if (result != 'N'){
			break; //�����������˳���
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