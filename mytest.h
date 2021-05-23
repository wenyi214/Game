#ifndef _MYTEST_H_
#define _MYTEST_H_

#include<stdio.h>
#include<windows.h>
#include<time.h>
#pragma warning(disable:4996)

#define H 3
#define L 3
#define P 'X'
#define C 'O'
#define Q ' '
#define W 'P'

void menu();
void init(char str[][L]);
void show(char str[][L]);
void comput(char str[][L]);
char judge(char str[][L]);
void game();


#endif