#ifndef __FIVECHREE_H__
#define __FIVECHEE_H__


#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

#define ROW 10//��������
#define COL 10//��������
#define INIT '*'//���̳�ʼ��

#define PLAYER1 1
#define PLAYER2 2
#define NEXT 3//����������
#define DRAW 4//�������� ƽ��

//8������
#define	UP 10
#define	RIGHT_UP 11
#define	RIGHT 12
#define	RIGHT_DOWN 13
#define	DOWN 14
#define	LEFT_DOWN 15
#define	LEFT 16
#define	LEFT_UP 17



extern void Menu();
extern void Game();




#endif