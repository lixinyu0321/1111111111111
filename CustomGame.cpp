#include "stdafx.h"
#include"CustomGame.h"
#include"CustomMap.h"
#include"Food.h"
#include"CSnake.h"
#include"Utils.h"
#include"SnakeGame.h"
#include"conio.h"


int snakeCM[2][500];   //�����Զ����ͼ��λ�õ�����
Block* blockCM = new Block[10];//�����Զ����ϰ�������


void CustomGame::playCGame() {

	CSnake cs;
	int a[22][22] = { 0 };
	if (memcmp(imageCM, a, sizeof(imageCM)) == 0) {
	
		map.initPartMapCM();
		cs.foodCM.createFoodCM();           //����ʳ��
		blockCM[0].createBlockCM(blockCM);
	}
	map.initPartMapCM();
	cs.foodCM.createFoodCM();           //����ʳ��

	customMap.displayCM();//��ʾ��ͼ

	cs.displayCMer();//��ʾ�������

	utils.showCursor(false);
	PlaySoundA("sound\\bg_snake.wav", NULL, SND_ASYNC | SND_LOOP);   //ѭ�����ű�����Ч
	utils.setEnglish();  //�л�Ӣ�����뷨

	while (!cs.gameOver)
	{
		if (_kbhit())          //���հ���
		{
			cs.arrowKey = _getch();
		}
		if (cs.direction == 2 || cs.direction == 8)  //�ƶ�����ʱ�����ҿ���
		{
			switch (cs.arrowKey)
			{
			case'6':cs.toRight(); break;
			case'4':cs.toLeft(); break;
			case'e':exit(1); break;
			case'p':cs.pauseCMGame(); break;
			default:;//break;
			}
		}
		else if (cs.direction == 4 || cs.direction == 6)  //�ƶ�����ʱ�����¿���
		{
			switch (cs.arrowKey)
			{
			case'8':cs.toUp(); break;
			case'5':cs.toDown(); break;
			case'e':exit(1); break;
			case'p':cs.pauseCMGame(); break;
			default:;// break;
			}
		}
		Sleep(cs.gamespeed);    //�ƶ�һ����ٶ�
		cs.automoveCM();			   // С���Զ��ƶ�
		cs.gameoverCM();            //�ж���Ϸ�Ƿ����
		if (cs.gameOver == 1) {     //��Ϸ��������ѭ��
			PlaySoundA("sound\\die.wav", NULL, SND_ASYNC | SND_NODEFAULT);   //��������������Ч
			break;
		}
		cs.drawSnakeCM();        //�ж��Ƿ��ʳ�� 
		 //��ʾ��Ϸ���
		customMap.displayCM();

		cs.displayCMer();     //��ʾ�������

		utils.showCursor(false);
	}

	delete blockCM;
	system("pause");
	system("cls");
	exit(1);
}