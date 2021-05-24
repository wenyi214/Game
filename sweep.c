#include"game.h"



void Init_board(char board1[][COL], char board2[][COL],int lin, int col){
	int i = 0;
	for (; i < lin; i++){
		int j = 0;
		for (; j < col; j++){                                           //将埋雷棋盘，给用户看的棋盘初始化。显示棋盘初始化*，埋雷棋盘显示0  0->没有雷   1->雷
			board1[i][j] = '*';
			board2[i][j] = '0';
		}
	}


}
void Mines_borad(char board[][COL], int lin, int col){
	int i = 0;
	while (i<MINE){
		int x = rand() % (lin - 2) + 1;
		int y = rand() % (col - 2) + 1;                                //随机埋雷
		if (board[x][y] == '0'){
			board[x][y] = '1';
			i++;
		}
	}

}
void Shows_board(char board[][COL], int lin, int col){
	int i = 1;
	printf("   ");                                                   //展示棋盘
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
		board[x][y + 1] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] - 8 * '0';         //计算选择位置周围有几个雷
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
			printf("输入超过范围，请重新输入\n");
			continue;
		}
		if (show_board[x][y] != '*'){
			printf("位置已被占用，请重新输入\n");
			continue;
		}
		if (mine_board[x][y] == '1'){
			printf("game over!\n");
			Shows_board(mine_board, LIN, COL);
			break;
		}
		int count = Count_game(mine_board, x, y);
		show_board[x][y] = count+'0';      //加字符'0'才显示字符
		times--;
		system("cls");



	} while (times>0);


}