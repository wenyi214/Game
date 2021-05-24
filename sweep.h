#ifndef _GAME_H_
#define _GAME_H_


#include<stdio.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)


#define LIN 12
#define COL 12
#define MINE 20


void Init_board(char board1[][COL], char board2[][COL], int lin, int col);
void Mines_borad(char board[][COL], int lin, int col);
void Shows_board(char board[][COL], int lin, int col);
int Count_game(char board[][COL], int lin, int col);
void Game();







#endif