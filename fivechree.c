#include"fivechree.h"

static int x = 0;
static int y = 0;

void Menu(){
	printf("+---------------------+\n");
	printf("+- 1.Play    2.Exit  -+\n");
	printf("+---------------------+\n");
	printf("Please Enter Your Select#");

}
static void Showboard(int board[][COL], int row, int col){//展示棋盘 o玩家1棋子，x玩家2棋子
	system("cls");
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			switch (board[i][j]){
			case PLAYER1:
				board[i][j] = 'o';
				break;
			case PLAYER2:
				board[i][j] = 'x';
				break;
			case 0:
				board[i][j] = INIT;
				break;
			default:
				break;
			}
		}
	}
	printf("  ");
	for (int i =1; i <= row; i++){
		printf("%2d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++){
		printf("%-2d", i);
		for (int j = 1; j <= col; j++){
			printf(" %c ", board[i - 1][j - 1]);
		}
		printf("\n");
	}
}

static void Playermove(int board[][COL], int row, int col, int who){//玩家下子，who 为哪个玩家下子
	while (1){
		printf("Please Enter PLAYER%d Postion<x,y>#", who);
		scanf("%d %d", &x, &y);
		if (x<1 || x>row || y<1 || y>col){  //超过棋盘范围
			printf("Postion is error!\n");
			continue;
		}
		if (board[x - 1][y - 1] == INIT){//判断位置是否已被下子
			board[x - 1][y - 1] = who;
			break;
		}
		printf("Postion is not empty\n");
	}

}

static int Getcount(int board[][COL], int row, int col, int dir){//判断8个方向相同棋子的数目
	int _x = x;//_x,_y变化，后面与x，y棋子相比较
	int _y = y;
	int count = 0;
	while (1){
		switch (dir){
		case UP:
			_x--;
			break;
		case DOWN:
			_x++;
			break;
		case LEFT:
			_y--;
			break;
		case RIGHT:
			_y++;
			break;
		case RIGHT_UP:
			_x--, _y++;
			break;
		case RIGHT_DOWN:
			_x++, _y++;
			break;
		case LEFT_DOWN:
			_x++, _y--;
			break;
		case LEFT_UP:
			_x--, _y--;
			break;
		default:
			break;
		}
		if (_x>=1 || _x<=row || _y>=1 || _y<=col){//棋子不能越界
			if (board[x-1][y-1] == board[_x-1][_y-1]){
				//printf("yes\n");
				count++;
			}
			else{
				//printf("no\n");
				break;
			}
		}
		else{
			return count;
		}
		
	}
	return count;
}
//如何判断：从下子位置的8个方向(上，下，左，右，右上，右下，左上，左下)
//计算相同棋子数目，然后将对角的棋子数相加,等于5说明有5子连线
static int Judge(int board[][COL], int row, int col){
	int count1 = Getcount(board, row, col, UP)\
		+ Getcount(board, row, col, DOWN);
	//printf("%d\n", count1);
	if (count1 >= 4){
		return board[x-1][y-1];
	}
	count1 = Getcount(board, row, col, RIGHT_UP)\
		+ Getcount(board, row, col, LEFT_DOWN);
	//printf("%d\n", count1);
	if (count1 >= 4){
		return board[x-1][y-1];
	}
	count1 = Getcount(board, row, col, RIGHT)\
		+ Getcount(board, row, col, LEFT);
	//printf("%d\n", count1);
	if (count1 >= 4){
		return board[x-1][y-1];
	}
	count1 = Getcount(board, row, col, RIGHT_DOWN)\
		+ Getcount(board, row, col, LEFT_UP);
	if (count1 >= 4){
		return board[x-1][y-1];
	}

	for (int i = 0; i < row; i++){//判断棋盘是否下满
		for (int j = 0; j < col; j++){
			if (board[i][j] == INIT){
				return NEXT;
			}
		}
	}
	return DRAW;
}



void Game(){
	int board[ROW][COL] = { 0 };
	//memset(board, INIT, ROW*COL);
	int result = 0;
	int cur = PLAYER1;
	Showboard(board, ROW, COL);//先展示棋盘
	while (1){
		//Showboard(board, ROW, COL);
		Playermove(board, ROW, COL, cur);
		Showboard(board, ROW, COL);//棋盘将board数组变化，所以要在判断前将数组变化
		result = Judge(board, ROW, COL);
		if (result != NEXT){
			break;
		}
		cur = (cur == PLAYER1 ? PLAYER2 : PLAYER1);//三目表达式，注意不是 PLAYER1 ? PLAYER2 : PLAYER1
	}

	Showboard(board, ROW, COL);
	switch (result){
	case 'o':
		printf("Player1 Win!\n");
		break;
	case 'x':
		printf("Player2 Win!\n");
		break;
	case DRAW:
		printf("Tie Game!\n");
		break;
	default:
		//printf("%c\n", result);
		printf("BUG\n");
		break;
	}
}