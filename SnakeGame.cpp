
#include "stdafx.h"
#include <stdio.h>  
#include <windows.h>  
#include <time.h>  
#include <conio.h> 
#include"Utils.h"
#include"StartScreen.h"
#include"CSnake.h"
#include"SnakeGame.h"
#include"CustomGame.h"
#include <iostream>
#pragma comment(lib,"winmm.lib")
using namespace std;

HeroList Hero[10];
CSnake* SNAKE;

void main()         //������
{
	startGame();
}


void startGame() {
	if (SNAKE == NULL) {
		SNAKE = new CSnake();
	}

	char Name[10] = " ";
	char ch;    //�˵�ѡ���
	Utils utils;
	utils.setWindows(80, 30);

	StartScreen ss;
	ss.Welcome();

	while (1)
	{
		utils.color(14);       // �������ɫ
		utils.gotoXY(10 * 2, 1);
		cout << "     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     " << endl;
		utils.gotoXY(10 * 2, 2);
		cout << "   -----* - * - * - * - * - * - *----   " << endl;
		utils.gotoXY(10 * 2, 3);
		cout << "   ��  �x�x�x�x�x�x�x�x�x�x�x�x�x�x   ��     " << endl;
		utils.gotoXY(10 * 2, 4);
		cout << "   ��  ��                          �� ��     " << endl;
		utils.gotoXY(10 * 2, 5);
		cout << "   ��  ��       1.��ʼ��Ϸ         �� ��     " << endl;
		utils.gotoXY(10 * 2, 6);
		cout << "   ��  ��       2.�����Ѷ�         �� ��     " << endl;
		utils.gotoXY(10 * 2, 7);
		cout << "   ��  ��       3.��Ϸ�̳�         �� ��     " << endl;
		utils.gotoXY(10 * 2, 8);
		cout << "   ��  ��       4.�߷ְ�           �� ��     " << endl;
		utils.gotoXY(10 * 2, 9);
		cout << "   ��  ��       5.�Զ���           �� ��     " << endl;
		utils.gotoXY(10 * 2, 10);
		cout << "   ��  ��       6.��ȡ�浵         �� ��     " << endl;
		utils.gotoXY(10 * 2, 11);
		cout << "   ��  ��       7.�˳�             �� ��     " << endl;
		utils.gotoXY(10 * 2, 12);
		cout << "   ��  ��                          �� ��     " << endl;
		utils.gotoXY(10 * 2, 13);
		cout << "   ��  ����������������������������   ��     " << endl;
		utils.gotoXY(10 * 2, 14);
		cout << "   -----* - * - * - * - * - * - *----   " << endl;
		utils.gotoXY(10 * 2, 15);
		cout << "     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     " << endl;
		utils.gotoXY(10 * 2, 16);
		cout << "���������Ĳ���ѡ�";
		cin >> ch;

		if (ch == '1')
		{
			system("cls");

			if (SNAKE == NULL) {
				SNAKE = new CSnake();
			}
			
			SNAKE->playGame();
			system("cls");
			if (Hero[0].Highscore < 100)
			{
				cout << "��ˣ�" << endl; cout << endl;
			}
			else if (200 > Hero[0].Highscore&&Hero[0].Highscore >= 100)
			{
				cout << "���ͣ�" << endl; cout << endl;
			}
			else if (400 > Hero[0].Highscore&&Hero[0].Highscore >= 200)
			{
				cout << "����Ŷ��" << endl; cout << endl;
			}
			else if (600 > Hero[0].Highscore&&Hero[0].Highscore >= 400)
			{
				cout << "̫ǿ����" << endl; cout << endl;
			}
			else
			{
				cout << "6666666666666666666" << endl; cout << endl;
			}
			if (Hero[0].Highscore > 10)
			{
				cout << "���������Ĵ�����";
				cin >> Hero[0].Name;
				utils.save();
			}
			delete SNAKE;
			system("pause");
			system("cls");
			continue;
		}


		else if (ch == '2')
		{
			system("cls");
			SNAKE->setspeed();
			system("pause");
			system("cls");
			continue;
		}


		else if (ch == '3')       //��ϸʹ��˵��
		{
			system("cls");
			cout << "                                                    " << endl;
			cout << "                                                    " << endl; utils.color(3);
			cout << "    *********************************************** " << endl; utils.color(3);
			cout << "    *   ���ƣ�8 ;       ���ƣ�4 ;    ��ͣ��p      * " << endl;
			cout << "    *   ���ƣ�5 ;       ���ƣ�6 ;    �˳���e      * " << endl; utils.color(3);
			cout << "    *********************************************** " << endl; utils.color(3);
			cout << "    $            �������������в���!            $ " << endl;
			cout << "    $         �༭�Զ����ͼ���Ȱ�p��������       $ " << endl;
			cout << "    $ ��������ǽ���һ����ϰ�����˫����ɾ��! $ " << endl; utils.color(3);
			cout << "    #-------------------------------------------- # " << endl;
			cout << "    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
			cout << "                                                    " << endl;
			cout << "                                                    " << endl;
			system("pause");
			system("cls");
			continue;
		}
		else if (ch == '4')                                             // ��¼��߷֣���ʾӢ�۰�
		{
			system("cls");
			utils.color(10);

			FILE *fp;
			fopen_s(&fp, "Hero_list", "rb");
			fread(&Hero, sizeof(struct HeroList), 1, fp);

			for (int i = 0; i < 10 && Hero[i].Highscore != 0; i++) {

				cout << "$#######_---   �߷ְ�  ---_#######$" << endl;
				cout << "               ����:" << Hero[i].Name << endl;
				cout << "               ����:" << Hero[i].Highscore << endl;
				cout << "--------------------------------------------" << endl;
			}

			fclose(fp);

			system("pause");
			system("cls");
			continue;
		}
		else if (ch == '5') {//�Զ�����Ϸ
			system("cls");
			CustomGame customGame;
			customGame.customMap.editMap();

			system("pause");
			system("cls");
		}
		else if (ch == '6') {//��ȡ�浵��Ϸ
			system("cls");
			SNAKE->readGame();
			SNAKE->playGame();


			system("cls");
			if (Hero[0].Highscore < 100)
			{
				cout << "��ˣ�" << endl; cout << endl;
			}
			else if (200 > Hero[0].Highscore&&Hero[0].Highscore >= 100)
			{
				cout << "���ͣ�" << endl; cout << endl;
			}
			else if (400 > Hero[0].Highscore&&Hero[0].Highscore >= 200)
			{
				cout << "����Ŷ��" << endl; cout << endl;
			}
			else if (600 > Hero[0].Highscore&&Hero[0].Highscore >= 400)
			{
				cout << "̫ǿ����" << endl; cout << endl;
			}
			else
			{
				cout << "6666666666666666666" << endl; cout << endl;
			}
			if (Hero[0].Highscore > 10)
			{
				cout << "���������Ĵ�����";
				cin >> Hero[0].Name;
				utils.save();
			}
			delete SNAKE;
			system("pause");
			system("cls");
			continue;

		}
		else if (ch == '7')//�˳���Ϸ
		{
			system("cls");
			exit(0);
		}
		else
		{
			system("cls");
			cout << "���������룡" << endl;
			continue;
		}
	}

}