#include"game.h"



void Init_board(char board1[][COL], char board2[][COL],int lin, int col){
	int i = 0;
	for (; i < lin; i++){
		int j = 0;
		for (; j < col; j++){                                           //���������̣����û��������̳�ʼ������ʾ���̳�ʼ��*������������ʾ0  0->û����   1->��
			board1[i][j] = '*';
			board2[i][j] = '0';
		}
	}


}
void Mines_borad(char board[][COL], int lin, int col){
	int i = 0;
	while (i<MINE){
		int x = rand() % (lin - 2) + 1;
		int y = rand() % (col - 2) + 1;                                //�������
		if (board[x][y] == '0'){
			board[x][y] = '1';
			i++;
		}
	}

}
void Shows_board(char board[][COL], int lin, int col){
	int i = 1;
	printf("   ");                                                   //չʾ����
	for (; i < lin - 1; i++){
		printf("%d|", i);
	}
	printf("\n");

	for (i = 0; i < lin-4; i++){
		printf("---");
	}
	printf("\n");

	for (i = 1; i < lin - 1; i++){
		printf("%2d|", i);
		int j = 1;
		for (; j < col - 1; j++){
			printf("%c|", board[i][j]);

		}
		printf("\n");
		int k = 0;
		for (; k < col - 4; k++){
			printf("---");
		}
		printf("\n");
	}

}

int Count_game(char board[][COL], int x, int y){
	return board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] + board[x][y - 1] + \
		board[x][y + 1] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] - 8 * '0';         //����ѡ��λ����Χ�м�����
}

void Game(){
	srand((unsigned long)time(NULL));
	char show_board[LIN][COL];
	char mine_board[LIN][COL];
	//memset(show_board, '*', sizeof(show_board));
	//memset(mine_board, '0', sizeof(mine_board));
	Init_board(show_board, mine_board, LIN, COL);
	Mines_borad(mine_board, LIN, COL);
	int times = LIN*COL - MINE;
	do{
		
		Shows_board(show_board, LIN, COL);
		int x = 0;
		int y = 0;
		printf("please input <x,y>");
		scanf("%d %d", &x, &y);
		if (x<1 || x>10 || y<1 || y>10){
			printf("���볬����Χ������������\n");
			continue;
		}
		if (show_board[x][y] != '*'){
			printf("λ���ѱ�ռ�ã�����������\n");
			continue;
		}
		if (mine_board[x][y] == '1'){
			printf("game over!\n");
			Shows_board(mine_board, LIN, COL);
			break;
		}
		int count = Count_game(mine_board, x, y);
		show_board[x][y] = count+'0';      //���ַ�'0'����ʾ�ַ�
		times--;
		system("cls");



	} while (times>0);


}