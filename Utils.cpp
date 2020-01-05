#include "stdafx.h"
#include"Utils.h"
#include<Windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;

void Utils::gotoXY(int x, int y)      //�趨���λ��
{
	COORD c;   //���λ��
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//��ȡ���������λ��
	showCursor(false);   //ȡ�������˸
}
//-----------------------------------------------------------------
void Utils::color(int a)              //��ɫ����
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

//---------------------------------------------
void Utils::setWindows(int cols, int lines) {
	system("title ̰����");
	char ch[30];
	sprintf_s(ch, "mode con cols=%d lines=%d", cols, lines);
	system(ch);
}
//---------------------------------------------
void Utils::showCursor(bool isShow) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;   //����̨�����Ϣ�ṹ����
	cci.dwSize = 1;   //����С
	cci.bVisible = isShow;      //�Ƿ���ʾ���  true��ʾ
	SetConsoleCursorInfo(hOutStd, &cci);   //���ÿ���̨��Ļ����С�Ϳɼ���
}

//------------------------------------
void Utils::setEnglish() {        //���뷨�л�ΪӢ������״̬
	keybd_event(VK_SHIFT, 0, 0, 0);
	Sleep(100);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
}

//----------------------------------------------------------
void Utils::save()      //�洢��߷ּ�����
{
	FILE *fp;
	if (fopen_s(&fp, "Hero_list", "wb") != 0)
	{
		cout << "can not open file!" << endl; return;
	}
	if (fwrite(&Hero, sizeof(struct HeroList), 1, fp) != 1)
		cout << "file write error!" << endl;
	fclose(fp);
}


//-----------------------------