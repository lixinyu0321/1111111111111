#include "stdafx.h"
#include"CustomMap.h"
#include"Block.h"
#include"CustomGame.h"
#include"conio.h"
#include"CSnake.h"
#include<iostream>
using namespace std;

int imageCM[22][22];


void CustomMap::editMap() {

	for (int i = 0; i < 10; i++) {//��ʼ��
		blockCM[i].blockX = 0;
		blockCM[i].blockY = 0;
	}

	for (int i = 0; i<20; i++)      //��ʼ��
		for (int j = 0; j<20; j++)
			imageCM[i][j] = 0;   //�ÿ�

	for (int i = 1; i <= 3; i++)  //��ʼ���߸��ڵ�ͼ��
		imageCM[1][i] = 3;
	imageCM[1][4] = 1;

	displayCM();
	showCursorCM(false);
	MessageLoop();
	getchar();
	system("pause");
}

void CustomMap::MouseEventProc(MOUSE_EVENT_RECORD mer) {
	switch (mer.dwEventFlags) {
	case 0:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			//����������ǽ��ڵ�
			imageCM[x][y] = 5;

			displayCM();
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
			//WriteChar(0,0,"�Ҽ�����",0x50);
			//�Ҽ���������ϰ���
			
			if (n <=10) {
			for (int i = 0; i < 10; i++) {
				if (blockCM[i].blockX == 0) {
					blockCM[i].blockX = x;
					blockCM[i].blockY = y;
					imageCM[x][y] = 4;
					n++;
					break;
				}
			}
			}
			else {
				gotoXYCM(30,30);
				printf("�Ѿ��ﵽ�ϰ�����");
			}


			displayCM();

		}
		break;
	case DOUBLE_CLICK:
		//˫��ɾ��
	{
		//ɾ���ϰ�
		if (imageCM[x][y]==4) {
			imageCM[x][y] = 0;
			for (int i = 0; i < 10; i++) {
				if (blockCM[i].blockX == x) {
					blockCM[i].blockX = 0;
					blockCM[i].blockY = 0;
					n--;
					break;
				}
			}
		}
		else imageCM[x][y] = 0;  //ɾ��ǽ��

		displayCM();

	}
	break;
	case MOUSE_MOVED:
	{
		y = mer.dwMousePosition.X / 2;
		x = mer.dwMousePosition.Y; }
	break;

	}

}


void CustomMap::keyEventProc(KEY_EVENT_RECORD ker) {
	if (ker.bKeyDown) {	
		char ch;
		ch = _getch();
		if (ch=='p') {
			CSnake cs;
			cs.pauseCM();
		}
	}
}


void CustomMap::MessageLoop() {
	Utils utils;
	utils.setEnglish();

	ShowCursor(false);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);


	while (1) {
		//�ȴ��¼�
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);
		//�����¼�
		if (stcRecord.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRecord.Event.MouseEvent);
		}
		else if(stcRecord.EventType ==KEY_EVENT) {
			keyEventProc(stcRecord.Event.KeyEvent);
		}
	}
}

void CustomMap::showCursorCM(bool isShow) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;   //����̨�����Ϣ�ṹ����
	cci.dwSize = 1;   //����С
	cci.bVisible = isShow;      //�Ƿ���ʾ���  true��ʾ
	SetConsoleCursorInfo(hOutStd, &cci);   //���ÿ���̨��Ļ����С�Ϳɼ���
}



void CustomMap::gotoXYCM(int x, int y)      //�趨���λ��
{
	COORD c;   //���λ��
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//��ȡ���������λ��
	showCursorCM(false);   //ȡ�������˸
}

void CustomMap::colorCM(int a)              //��ɫ����
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}


void CustomMap::printRange() {
	colorCM(6);
	gotoXYCM(0, 22);
	for (int i = 0; i < 22; i++) {
		printf("--");
	}
	colorCM(6);
	for (int j = 0; j < 22; j++) {
		gotoXYCM(22 * 2, j);
		printf("|");
	}
}


void CustomMap::displayCM() {
	// system("cls");
	printRange();
	colorCM(7);
	gotoXYCM(25*2, 0);
	printf("���밴p��������༭��ͼ��");
	gotoXYCM(24 * 2, 1);
	printf("ע������ϰ���������Ϊ10��");
	gotoXYCM(0, 0);
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 22; j++) {
			switch (imageCM[i][j]) {
			case 0:colorCM(15); printf("  "); break;
			case 1:colorCM(2); printf("��"); break;   //��ͷ
			case 2:colorCM(12); printf("��"); break;   //ʳ��
			case 3:colorCM(13); printf("��"); break;    //����ڵ�
			case 4:colorCM(5); printf("��"); break;     //�ϰ���
			case 5:colorCM(4); printf("��"); break;
			}
		}
		printf("\n");
	}
	showCursorCM(false);
}
