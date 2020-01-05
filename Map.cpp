#include"stdafx.h"
#include"windows.h"
#include"Map.h"
#include"CSnake.h"
#include"Utils.h"
#include"conio.h"
#include"CustomGame.h"
#include<iostream>
using namespace std;

void Map::initPartMap() {
	for (int i = 0; i<20; i++)      //��ʼ����Ϸ��� 
		for (int j = 0; j<20; j++)
			image[i][j] = 0;   //�ÿ�
	for (int i = 0; i<4; i++)      //��ʼ��С�߳�ʼλ��
	{
		snake[0][i] = 1;     //�����ڵ������Ϊ1  ��ֵ������
		snake[1][i] = i + 1;  //���ڵ�������ֱ�Ϊ1,2,3,4  ��ֵ������
	}
	for (int i = 1; i <= 3; i++)  //��ʼ��С�߸��ڵ�ͼ��
		image[1][i] = 3;
	image[1][4] = 1;
}


void Map::initPartMapCM() {

	for (int i = 0; i<4; i++)      //��ʼ��С�߳�ʼλ��
	{
		snakeCM[0][i] = 1;     //�����ڵ������Ϊ1  ��ֵ������
		snakeCM[1][i] = i + 1;  //���ڵ�������ֱ�Ϊ1,2,3,4  ��ֵ������
	}
}


void Map::display() { //��ʾ��Ϸ���int& score,int& level,int& healthPoint
	utils.color(8);
	utils.gotoXY(1, 1);
	for (int i = 0; i<22; i++)
		printf("��");
	utils.gotoXY(1, 2);
	for (int i = 0; i<20; i++)
	{
		utils.color(8);
		printf("��");
		for (int j = 0; j<20; j++)
		{
			switch (image[i][j])
			{
			case 0:utils.color(15); printf("  "); break;
			case 1:utils.color(2); printf("��"); break;   //��ͷ
			case 2:utils.color(12); printf("��"); break;   //ʳ��
			case 3:utils.color(13); printf("��"); break;    //����ڵ�
			case 4:utils.color(5); printf("��"); break;     //�ϰ���
			}
		}  utils.color(8);
		printf("��\n");
	}
	utils.color(8);
	for (int i = 0; i<22; i++)
		printf("��");  utils.color(13);
	utils.color(12);
	utils.gotoXY(46, 5); printf("��Ȥ��C++̰������Ϸ��\n");
	utils.gotoXY(46, 6); printf("������Ϸ����ȥѧϰ��\n");
}

void Map::setBackColor()//�����ı�����ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);
}

int Map::showMenu() {
	utils.color(11);
	utils.gotoXY(46, 13);
	cout << "�˵���";
	Sleep(100);
	utils.gotoXY(46, 15);
	setBackColor();
	std::cout << "������Ϸ";
	Sleep(100);
	utils.gotoXY(46, 17);
	utils.color(11);
	std::cout << "������Ϸ";
	Sleep(100);
	utils.gotoXY(46, 19);
	std::cout << "���ز˵�";

	/*ѡ�񲿷�*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 72://UP
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					utils.gotoXY(46,15);
					setBackColor();
					std::cout << "������Ϸ";
					utils.gotoXY(46, 17);
					utils.color(11);
					std::cout << "������Ϸ";

					--tmp_key;
					break;
				case 3:
					utils.gotoXY(46, 17);
					setBackColor();
					std::cout << "������Ϸ";
					utils.gotoXY(46, 19);
					utils.color(11);
					std::cout << "���ز˵�";

					--tmp_key;
					break;
				}
			}
			break;

		case 80://DOWN
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					utils.gotoXY(46, 17);
					setBackColor();
					std::cout << "������Ϸ";
					utils.gotoXY(46, 15);
					utils.color(11);
					std::cout << "������Ϸ";

					++tmp_key;
					break;
				case 2:
					utils.gotoXY(46, 19);
					setBackColor();
					std::cout << "���ز˵�";
					utils.gotoXY(46, 17);
					utils.color(11);
					std::cout << "������Ϸ";

					++tmp_key;
					break;
				}
			}
			break;

		case 13://Enter
			flag = true;
			break;

		default:
			break;
		}

		if (flag)
		{
			break;
		}
		utils.gotoXY(0, 31);
	}

	if (tmp_key == 1) //ѡ�������Ϸ���򽫲˵�����
	{
		utils.gotoXY(46, 13);
		std::cout << "      ";
		utils.gotoXY(46, 17);
		std::cout << "        ";
		utils.gotoXY(46, 15);
		std::cout << "        ";
		utils.gotoXY(46, 19);
		std::cout << "        ";
	}
	return tmp_key;
}




int Map::showMenuCM() {
	utils.color(11);
	utils.gotoXY(46, 13);
	cout << "�˵���";
	Sleep(100);
	utils.gotoXY(46, 15);
	setBackColor();
	std::cout << "�����༭";
	Sleep(100);
	utils.gotoXY(46, 17);
	utils.color(11);
	std::cout << "��ʼ��Ϸ";
	Sleep(100);
	utils.gotoXY(46, 19);
	std::cout << "���ز˵�";

	/*ѡ�񲿷�*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 72://UP
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					utils.gotoXY(46, 15);
					setBackColor();
					std::cout << "�����༭";
					utils.gotoXY(46, 17);
					utils.color(11);
					std::cout << "��ʼ��Ϸ";

					--tmp_key;
					break;
				case 3:
					utils.gotoXY(46, 17);
					setBackColor();
					std::cout << "��ʼ��Ϸ";
					utils.gotoXY(46, 19);
					utils.color(11);
					std::cout << "���ز˵�";

					--tmp_key;
					break;
				}
			}
			break;

		case 80://DOWN
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					utils.gotoXY(46, 17);
					setBackColor();
					std::cout << "��ʼ��Ϸ";
					utils.gotoXY(46, 15);
					utils.color(11);
					std::cout << "�����༭";

					++tmp_key;
					break;
				case 2:
					utils.gotoXY(46, 19);
					setBackColor();
					std::cout << "���ز˵�";
					utils.gotoXY(46, 17);
					utils.color(11);
					std::cout << "��ʼ��Ϸ";

					++tmp_key;
					break;
				}
			}
			break;

		case 13://Enter
			flag = true;
			break;

		default:
			break;
		}

		if (flag)
		{
			break;
		}
		utils.gotoXY(0, 31);
	}

	if (tmp_key == 1) //ѡ������༭���򽫲˵�����
	{
		utils.gotoXY(46, 13);
		std::cout << "      ";
		utils.gotoXY(46, 17);
		std::cout << "        ";
		utils.gotoXY(46, 15);
		std::cout << "        ";
		utils.gotoXY(46, 19);
		std::cout << "        ";
	}
	return tmp_key;

}
