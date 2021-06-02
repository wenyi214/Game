#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<graphics.h>
#define ROW 8
#define COL 8
#define MAP 2//map�������Լ������


int count = 0;//�ĸ�mapͼ
/*
�յ�             0
ǽ	              1
Ŀ�ĵ�           2
����             3
��               4  2+4=6 ����Ŀ�ĵ�Ҳ��ʾ��
���ӵ���Ŀ�ĵ�   2+3=5


*/


IMAGE image1, image2, image3, image4, image5, image6;

int backgrand[MAP][ROW][COL] =//mapͼ
{
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 2, 0, 0, 1,
		1, 1, 0, 0, 3, 1, 1, 1,
		1, 2, 3, 0, 4, 0, 0, 1,
		1, 0, 1, 0, 3, 3, 2, 1,
		1, 1, 0, 3, 2, 0, 0, 1,
		1, 0, 0, 2, 0, 0, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1
	},
	{
		0, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 0, 2, 0, 0, 0, 1,
		1, 1, 0, 0, 3, 0, 1, 1,
		1, 2, 3, 0, 4, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 1, 1,
		1, 1, 0, 3, 2, 3, 0, 1,
		1, 0, 0, 0, 0, 2, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1
	},
};
int Judge(){//p�ж��Ƿ����һ��
	int i = 0;
	for (i = 0; i < ROW; i++){
		int j = 0;
		for (j = 0; j < COL; j++){
			if (backgrand[count][i][j] == 3 || backgrand[count][i][j] == 2){
				return 0;
			}
		}
	}
	return 1;
}

void Backgrand(){//���Ƶ�ͼ
	int i = 0;
	for (; i < ROW; i++){
		int j = 0;
		for (; j < COL; j++){
			int x = 80 * j;//������y(��)��������x���У���
			int y = 80 * i;
			switch (backgrand[count][i][j]){
			case 0:
				putimage(x, y, &image3);
				break;
			case 1:
				putimage(x, y, &image1);
				break;
			case 2:
				putimage(x, y, &image6);
				break;
			case 3:
				putimage(x, y, &image4);
				break;
			case 4:
			case 6:
				putimage(x, y, &image2);
				break;
			case 5:
				putimage(x, y, &image5);
				break;
			default:
				break;
			}
		}
	}
}

void Keymove(){//������������˶�
	int i = 0;
	int j = 0;//j��������ˣ�����forѭ��Ҫ��ʼ��
	for (i = 0; i < ROW; i++){ //�ҵ��������
		for (j = 0; j < COL; j++){
			if (backgrand[count][i][j] == 4 || backgrand[count][i][j] == 6){
				break;
			}
		}
		if (backgrand[count][i][j] == 4 || backgrand[count][i][j] == 6){
			break;
		}
	}
	char key = _getch();
	switch (key){
	case 'w':
	case 'W':
	case 72:
		if (backgrand[count][i - 1][j] == 0 ||\
			backgrand[count][i - 1][j] == 2)
		{  
			backgrand[count][i][j] = backgrand[count][i][j] - 4;//���˶������Ա��ǿյػ�����Ŀ�ĵ�
			backgrand[count][i - 1][j] = backgrand[count][i - 1][j] + 4;
		}
		if (backgrand[count][i - 1][j] == 3 && (backgrand[count][i - 2][j] == 0 || \
			backgrand[count][i - 2][j] == 2))   //���������˶����������Ա����������������Ա��ǿյء�
		{                                       //����������Ҫ����������
			backgrand[count][i][j] = backgrand[count][i][j] - 4;                                      
			backgrand[count][i - 1][j] = backgrand[count][i - 1][j] + 4;
			backgrand[count][i - 1][j] -= 3;
			backgrand[count][i - 2][j] += 3;
		}
		if (backgrand[count][i - 1][j] == 5 &&\
			backgrand[count][i - 2][j] == 0)  //���ӵ���Ŀ�ĵأ����滹�пյ����
		{
			backgrand[count][i][j] -= 4;
			backgrand[count][i - 1][j] += 4;
			backgrand[count][i - 1][j] -= 3;
			backgrand[count][i - 2][j] += 3;
		}
		break;
	case 's':
	case 'S':
	case 80:
		if (backgrand[count][i + 1][j] == 0 || \
			backgrand[count][i + 1][j] == 2)
		{  //���˶�
			backgrand[count][i][j] = backgrand[count][i][j] - 4;
			backgrand[count][i + 1][j] = backgrand[count][i + 1][j] + 4;
		}
		if (backgrand[count][i + 1][j] == 3 && (backgrand[count][i + 2][j] == 0 ||\
			backgrand[count][i + 2][j] == 2))
		{
			backgrand[count][i][j] = backgrand[count][i][j] - 4;
			backgrand[count][i + 1][j] = backgrand[count][i + 1][j] + 4;
			backgrand[count][i + 1][j] -= 3;
			backgrand[count][i + 2][j] += 3;
		}
		if (backgrand[count][i + 1][j] == 5 && \
			backgrand[count][i + 2][j] == 0)
		{
			backgrand[count][i][j] -= 4;
			backgrand[count][i + 1][j] += 4;
			backgrand[count][i + 1][j] -= 3;
			backgrand[count][i + 2][j] += 3;
		}
		break;
	case 'a':
	case 'A':
	case 75:
		if (backgrand[count][i][j - 1] == 0 || \
			backgrand[count][i][j - 1] == 2)
		{  //���˶�
			backgrand[count][i][j] = backgrand[count][i][j] - 4;
			backgrand[count][i][j - 1] = backgrand[count][i][j - 1] + 4;
		}
		if (backgrand[count][i][j - 1] == 3 &&\
			(backgrand[count][i][j - 2] == 0 ||\
			backgrand[count][i][j - 2] == 2))
		{
			backgrand[count][i][j] = backgrand[count][i][j] - 4;
			backgrand[count][i][j - 1] = backgrand[count][i][j - 1] + 4;
			backgrand[count][i][j - 1] -= 3;
			backgrand[count][i][j - 2] += 3;
		}
		if (backgrand[count][i][j - 1] == 5 && \
			backgrand[count][i][j - 2] == 0)
		{
			backgrand[count][i][j] -= 4;
			backgrand[count][i][j - 1] += 4;
			backgrand[count][i][j - 1] -= 3;
			backgrand[count][i][j - 2] += 3;
		}
		break;
	case 'd':
	case 'D':
	case 77:
		if (backgrand[count][i][j + 1] == 0 || \
			backgrand[count][i][j + 1] == 2)
		{  //���˶�
			backgrand[count][i][j] = backgrand[count][i][j] - 4;
			backgrand[count][i][j + 1] = backgrand[count][i][j + 1] + 4;
		}
		if (backgrand[count][i][j + 1] == 3 && (backgrand[count][i][j + 2] == 0 ||\
			backgrand[count][i][j + 2] == 2))
		{
			backgrand[count][i][j] -= 4;
			backgrand[count][i][j + 1] += 4;
			backgrand[count][i][j + 1] -= 3;
			backgrand[count][i][j + 2] += 3;
		}
		if (backgrand[count][i][j + 1] == 5 && backgrand[count][i][j + 2] == 0){
			backgrand[count][i][j] -= 4;
			backgrand[count][i][j + 1] += 4;
			backgrand[count][i][j + 1] -= 3;
			backgrand[count][i][j + 2] += 3;
		}
		break;
	default:
		break;
	}


}


void Initgraph(){
	initgraph(80 * ROW, 80 * COL);
	loadimage(&image1, "1.jpg");//ǽ
	loadimage(&image2, "2.jpg");//��
	loadimage(&image3, "3.jpg");//�յ�
	loadimage(&image4, "4.jpg");//����
	loadimage(&image6, "6.jpg");//Ŀ�ĵ�
	loadimage(&image5, "5.jpg");//���ӵ�Ŀ�ĵ�
}




int main(){
	Initgraph();
	while (1){
		Backgrand();
		Keymove();
		if (Judge()){
			Backgrand();
			Sleep(500);
			count++;
		}
		if (count == MAP){
			break;
		}
	}


	getchar();
	closegraph();
	system("pause");
	return 0;
}