#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
#include<conio.h>
#include<Windows.h>

#define MAX 200
HWND hwnd = NULL;

enum DIR{//ö���ƶ�����
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

struct COOR{//λ�ã�x��y����
	int x;
	int y;
};

struct SNAKE{//�ߵĻ�����Ϣ
	int size;//����
	int speed;//�˶��ٶ�
	char dir;//�˶�����
	struct COOR xy[MAX];//λ��
}snakes;

struct FOOD{//ʳ����Ϣ
	struct COOR fooddir;//ʳ��λ��
	int flag;//�ж�ʳ���Ƿ񱻳Ե���1δ���Ե���0���Ե�
}food;

void snakeInit(){//��ʼ���ߵ���Ϣ
	snakes.size = 3;//��ʼ����
	snakes.dir = RIGHT;//��ʼ�˶�����
	snakes.speed = 10;
	int i = 0;
	for (; i < snakes.size; i++){//ÿһ�����λ�ã�ע�⽫��һ����Ϊͷ
		snakes.xy[i].x = 40 - 10 * i;
		snakes.xy[i].y = 10;
	}

}

void drawSnake(){//����
	int i = 0;
	for (; i < snakes.size; i++){
	setlinecolor(BLACK);//���ߵ���ɫ
	setfillcolor(RED);//���ɫ
	//fillrectangle(snakes.xy[i].x, snakes.xy[i].y, snakes.xy[i].x + 10, snakes.xy[i].y+10);//����
	fillcircle(snakes.xy[i].x, snakes.xy[i].y, 5);//Բ��
	}


}

void moveSnake(){//�ߵ��ƶ�
	//snakes.xy[0].x++;

	int i = 0;
	for (i = snakes.size-1; i >0; i--){//���������ͷ�˶�
		snakes.xy[i].x = snakes.xy[i-1].x;
		snakes.xy[i].y = snakes.xy[i-1].y;
	}
	switch (snakes.dir){
	case UP:
		snakes.xy[0].y-=snakes.speed;
		break;
	case DOWN:
			snakes.xy[0].y+=snakes.speed;
		break;
	case LEFT:
			snakes.xy[0].x-=snakes.speed;
		break;
	case RIGHT:
			snakes.xy[0].x+=snakes.speed;
		break;
	default:
		break;
	}


}

void coorSnake(){//���������ߵ��˶�����
	if (_kbhit()){ //�ȴ���ȡ����
		char c = _getch();//��ð���
		switch (c){
		case 72:
		case'w':
			if (snakes.dir != DOWN){
				snakes.dir = UP;
			}
			break;
		case 80:
		case's':
			if (snakes.dir != UP){
				snakes.dir = DOWN;
			}
			break;
		case 75:
		case'a':
			if (snakes.dir != RIGHT){
				snakes.dir = LEFT;
			}
			break;
		case 77:
		case'd':
			if (snakes.dir != LEFT){
				snakes.dir = RIGHT;
			}
			break;
		default:
			break;
		}
	}
}
void initFood(){//��ʼ��ʳ�����Ϣ
	food.flag = 1;
	while (1){
START:
		food.fooddir.x = rand() % 63 * 10;//ʳ��λ�����
		food.fooddir.y = rand() % 47 * 10;
		for (int i = 0; i < snakes.size; i++){//��ֹʳ�������������ϡ�
			if (food.fooddir.x == snakes.xy[i].x&&food.fooddir.y == snakes.xy[i].y){
				goto START;
			}
			else{
				break;
			}
		}
		break;
	}
}

void drawFood(){//��ʳ��
	//food.fooddir.x = 100;
	//food.fooddir.y = 200;
	setlinecolor(BLACK);
	setfillcolor(RED);
	fillcircle(food.fooddir.x, food.fooddir.y, 5);

}
void eatFood(){//�߳�ʳ��
	if (snakes.xy[0].x - food.fooddir.x <= 5 && snakes.xy[0].y - food.fooddir.y <= 5 \
		&& food.fooddir.x - snakes.xy[0].x <= 5 && food.fooddir.y - snakes.xy[0].y <= 5 && food.flag == 1){
		food.flag = 0;
		snakes.size++;
	}

}

int gameOver(){//��Ϸ�������
	if (snakes.xy[0].x < 5 || snakes.xy[0].y <= 0 || snakes.xy[0].x > 635 || snakes.xy[0].y > 478){
		MessageBox(hwnd, "GAME OVER!","��ײǽ�ˣ�", MB_OK);
		return 1;
	}
	for (int i = 1; i < snakes.size; i++){
		if (snakes.xy[0].x == snakes.xy[i].x&&snakes.xy[0].y == snakes.xy[i].y){
			MessageBox(hwnd, "GAME OVER!", "��ײ���Լ�",MB_OK);
			return 1;
		}
	}
	return 0;
}



void gameInit(){
	hwnd=initgraph(640, 480);//���ô��ڴ�С
	setbkcolor(GREEN);//���ô�����ɫ
}


int main(){
	srand((unsigned long)time(NULL));//���������
	gameInit();
	cleardevice();//ˢ�´���
	snakeInit();
	initFood();
	while (1){
		cleardevice();
		if (food.flag == 0){
			initFood();
		}
		drawFood();
		drawSnake();
		coorSnake();
		eatFood();
		moveSnake();
		//eatFood();
		if (gameOver()){
			break;
		}
		//stopGame();
		Sleep(100);
	}
	getchar();//��ֹ����
	closegraph();
	system("pause");
	return 0;
}