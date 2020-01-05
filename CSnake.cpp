#include "stdafx.h"
#include <windows.h>  
#include <time.h>  
#include <conio.h> 
#include"CSnake.h"
#include"Utils.h"
#include"Food.h"
#include"Map.h"
#include"SnakeGame.h"
#include"CustomMap.h"
#include"CustomGame.h"
#include <iostream>
#include<string.h>
#include<fstream>
#pragma comment(lib,"winmm.lib")
using namespace std;

int image[20][20];        //�߻��Χs
int snake[2][500];       //��¼���������������

//---------------------------------------------------------------
int CSnake::gameover()    //�ж���Ϸ�Ƿ����
{
	//����ֵΪ�㣬��Ϸ����
	if (healthPoint == 0) {
		utils.gotoXY(1, 25);
		cout << "��Ϸ����!" << endl;
		gameOver = 1;
		return gameOver;
	}

	if (snakeX < 0 || snakeX>19 || snakeY < 0 || snakeY>19)    // ����ǽ����Ϸ����
	{
		utils.gotoXY(1, 25);
		cout << "��Ϸ����!" << endl;
		gameOver = 1;
		return gameOver;
	}
	if ((image[snakeX][snakeY] != 0) && !(snakeX == food.getX() && snakeY == food.getY())
		&& !(snakeX == block.blockX && snakeY == block.blockY))   //��ͷ����������Ϸ����
	{
		utils.gotoXY(1, 25);
		cout << "��Ϸ����!" << endl;
		gameOver = 1;
		return gameOver;
	}
	return 0;
}

//---------------------------------------------------------
int CSnake::gameoverCM()    //�ж��Զ�����Ϸ�Ƿ����
{
	//����ֵΪ�㣬��Ϸ����
	if (healthPoint == 0) {
		utils.gotoXY(1, 25);
		cout << "��Ϸ����!" << endl;
		gameOver = 1;
		return gameOver;
	}
	if (snakeX < 0 || snakeX>21 || snakeY < 0 || snakeY>21)    // ����ǽ����Ϸ����
	{
		utils.gotoXY(1, 25);
		cout << "��Ϸ����!" << endl;
		gameOver = 1;
		return gameOver;
	}
	if (imageCM[snakeX][snakeY] == 5)    // ����ǽ����Ϸ����
	{
		utils.gotoXY(1, 25);
		cout << "��Ϸ����!" << endl;
		gameOver = 1;
		return gameOver;
	}


	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (blockCM[i].blockX == snakeX) {
			count = i;
			break;
		}
	}


	if ((imageCM[snakeX][snakeY] != 0) && !(snakeX == foodCM.getX() && snakeY == foodCM.getY())
		&& !(snakeX == blockCM[count].blockX && snakeY == blockCM[count].blockY))   //��ͷ����������Ϸ����
	{
		utils.gotoXY(1, 25);
		cout << "��Ϸ����!" << endl;
		gameOver = 1;
		return gameOver;
	}

	return 0;
}


//----------------------------------------------------------------
int CSnake::drawSnake()
{
	if (snakeX == food.getX() && snakeY == food.getY())  //��С��ͷ��������ʳ�������ص���Ե�ʳ��
	{
		node++;     // �߽ڵ�����һ
		score += 10;   //�������� 


		length++;
		if (length >= 10)     //����������10�ڵ㣬�ȼ���һ
		{
			length -= 10;
			level++;
			gamespeed -= 20;

		}
		image[snakeX][snakeY] = 1;      //С��ͷ���ƶ�����һλ��ͷ��ͼ���Ӧ��ֵ����ͼ��
		image[snake[0][head]][snake[1][head]] = 3;   //С��ͷ��������������һ���ƶ�����һλ��ͷ��ͼ���Ӧ��ֵ����ͼ��
		head = (head + 1) % 10000;
		snake[0][head] = snakeX;     //��С��ͷ����ʱ������ֵ������¼ͷ�������snake[0][head]
		snake[1][head] = snakeY;
		food.generatefood();              	//�Ե�ʳ������������ʳ��
		map.display();        //ˢ����ʾ
		display_er();
	}
	else if (snakeX == block.blockX && snakeY == block.blockY) {  //ײ���ϰ���

		healthPoint -= 20;  //��Ѫ
		image[snake[0][tail]][snake[1][tail]] = 0;   //��ȥС��β��
		tail = (tail + 1) % 10000;
		image[snake[0][head]][snake[1][head]] = 3;    //С��ͷ��������������һ���ƶ�����һλ��ͷ��ͼ���Ӧ��ֵ����ͼ��
		head = (head + 1) % 10000;
		snake[0][head] = snakeX;                     //��С��ͷ����ʱ������ֵ������¼ͷ�������snake[0][head]
		snake[1][head] = snakeY;
		image[snake[0][head]][snake[1][head]] = 1;   //С��ͷ���ƶ�����һλ��ͷ��ͼ���Ӧ��ֵ����ͼ��

		block.generateBlock();  //�����µ��ϰ�

		map.display();
		display_er();

	}

	else
	{                                               //û�г�ʳ��
		image[snake[0][tail]][snake[1][tail]] = 0;   //��ȥС��β��

		tail = (tail + 1) % 10000;

		image[snake[0][head]][snake[1][head]] = 3;   //С��ͷ����һ���ƶ�����һλ��ͷ��ͼ���Ӧ��ֵ����ͼ��
		head = (head + 1) % 10000;
		snake[0][head] = snakeX;                     //��С��ͷ������ֵ������¼ͷ�������snake[0][head]
		snake[1][head] = snakeY;
		image[snake[0][head]][snake[1][head]] = 1;   //С��ͷ���ƶ�����һλ��ͷ��ͼ���Ӧ��ֵ����ͼ��
		map.display();
		display_er();
	}
	return 0;
}


//---------------------------------------------------
int CSnake::drawSnakeCM() {

	if (snakeX == foodCM.getX() && snakeY == foodCM.getY())  //��С��ͷ��������ʳ�������ص���Ե�ʳ��
	{
		node++;     // �߽ڵ�����һ
		score += 10;   //�������� 

		length++;
		if (length >= 10)     //����������10���ڵ㣬�ȼ���һ
		{
			length -= 10;
			level++;
			gamespeed -= 20;
		}
		imageCM[snakeX][snakeY] = 1;      //��һλ��ͷ��ͼ���Ӧ��ֵ����ͼ������
		imageCM[snakeCM[0][head]][snakeCM[1][head]] = 3;   //��һλ��ͼ���Ӧ��ֵ����ͼ������

		head = (head + 1) % 10000;

		snakeCM[0][head] = snakeX;     //��С��ͷ������ֵ������¼ͷ�������snake[0][head]
		snakeCM[1][head] = snakeY;
		//�Ե�ʳ������������ʳ��
		foodCM.createFoodCM();
		//ˢ����ʾ
		customMap.displayCM();
		display_er();
	}
	else
	{                                               //û�г�ʳ��
		imageCM[snakeCM[0][tail]][snakeCM[1][tail]] = 0;   //��ȥС��β��
		tail = (tail + 1) % 10000;
		imageCM[snakeCM[0][head]][snakeCM[1][head]] = 3;   //��һλ��ͷ��ͼ���Ӧ��ֵ����ͼ������
		head = (head + 1) % 10000;
		snakeCM[0][head] = snakeX;                     //����ͷ����ʱ������ֵ������¼ͷ�������snake[0][head]
		snakeCM[1][head] = snakeY;
		imageCM[snakeCM[0][head]][snakeCM[1][head]] = 1;   //��һλ��ͷ��ͼ���Ӧ��ֵ����ͼ������
		customMap.displayCM();
		display_er();
	}




	//�Ե��Զ�����ϰ���
	for (int i = 0; i < 10; i++) {
		if (snakeX == blockCM[i].blockX && snakeY == blockCM[i].blockY) {
			healthPoint -= 20;  //��Ѫ
			imageCM[snakeCM[0][tail]][snakeCM[1][tail]] = 0;   //��ȥС��β��
			tail = (tail + 1) % 10000;
			imageCM[snakeCM[0][head]][snakeCM[1][head]] = 3;    //��һλ��ͷ��ͼ���Ӧ��ֵ����ͼ������
			head = (head + 1) % 10000;
			snakeCM[0][head] = snakeX;                     //����ͷ������ֵ������¼ͷ�������snake[0][head]
			snakeCM[1][head] = snakeY;
			imageCM[snakeCM[0][head]][snakeCM[1][head]] = 1;   //��һλ��ͷ��ͼ���Ӧ��ֵ����ͼ������

            //�����µ��ϰ�
			blockCM[i].createBlockCM(blockCM);
			customMap.displayCM();
			display_er();
		}
	}

	return 0;
}






//-----------------------------------------------------------
void CSnake::toLeft()      //����
{
	direction = 4;
}
//++++++++++++++++++++++++++
void CSnake::toRight()            //����
{
	direction = 6;
}
//+++++++++++++++++++++++++++
void CSnake::toUp()        //����
{
	direction = 8;
}
//+++++++++++++++++++++++++++
void CSnake::toDown()      //����
{
	direction = 2;
}
//------------------------------------------------------
void CSnake::automove()
{
	switch (direction)
	{
		//���ң���ͷ��Y�����һ��X���겻��
	case 6:snakeX = snake[0][head]; snakeY = snake[1][head] + 1; break;

		//����Y�����һ��X���겻��
	case 4:snakeX = snake[0][head]; snakeY = snake[1][head] - 1; break;

		//����X�����һ��Y���겻��
	case 8:snakeX = snake[0][head] - 1; snakeY = snake[1][head]; break;

		//����X�����һ��Y���겻��
	case 2:snakeX = snake[0][head] + 1; snakeY = snake[1][head]; break;
	default:;
	}
}

//---------------------------------------------
void CSnake::automoveCM() {
	switch (direction)
	{
		//���ң���ͷ��Y�����һ��X���겻��
	case 6:snakeX = snakeCM[0][head]; snakeY = snakeCM[1][head] + 1; break;

		//����Y�����һ��X���겻��
	case 4:snakeX = snakeCM[0][head]; snakeY = snakeCM[1][head] - 1; break;

		//����X�����һ��Y���겻��
	case 8:snakeX = snakeCM[0][head] - 1; snakeY = snakeCM[1][head]; break;

		//����X�����һ��Y���겻��
	case 2:snakeX = snakeCM[0][head] + 1; snakeY = snakeCM[1][head]; break;
	default:;
	}
}


//----------------------------------------------------
void CSnake::setspeed()     //����С���ƶ����ٶ�
{
	int flag = 0;
	while (!flag)
	{
		int speed;
		utils.color(12);
		cout << "1.�ǳ���   2.��   3.����   4.��   5.�ǳ��� " << endl;
		cout << "����������ѡ��";
		cin >> speed;
		switch (speed)
		{
		case 0:
			flag = 1;
			gamespeed = 300;
			break;
		case 1:
			gamespeed = 300;
			flag = 1;
			break;
		case 2:
			gamespeed = 200;
			flag = 1;
			break;
		case 3:
			gamespeed = 80;
			flag = 1;
			break;
		case 4:
			gamespeed = 30;
			flag = 1;
			break;
		case 5:
			gamespeed = 12;
			flag = 1;
			break;
		default:
			flag = 0;
		}
	}
}
//-----------------------------------------------------------
int CSnake::pause()                   //��ͣ����
{

	int tmp = map.showMenu();//չʾ�˵�������ֵ

	if (tmp == 1) { arrowKey = 0; return arrowKey; }  //������Ϸ
	else if (tmp == 2) {
		//������Ϸ
		saveGame();
		system("cls");
		PlaySoundA(NULL, NULL, SND_FILENAME);//�ر�����
		startGame();

	}
	else {
		system("cls");
		PlaySoundA(NULL, NULL, SND_FILENAME);
		startGame();
	}  //�˳���Ϸ����������

	return 0;

}
//---------------------------------------
//�Զ�����Ϸ�е���ͣ
int CSnake::pauseCMGame() {
	char c;
	do {
		c = _getch();
	} while (c != 'p');
	arrowKey = 0;
	return arrowKey;
}

//---------------------------------
int CSnake::pauseCM() {
	int tmp = map.showMenuCM();//�˵�������ֵ

	if (tmp == 1) { arrowKey = 0; return arrowKey; }  //�����༭
	else if (tmp == 2) {//��ʼ��Ϸ

		system("cls");
		CustomGame customGame;
		customGame.playCGame();

	}
	else {
		delete blockCM;
		system("cls");
		startGame();
	}

	return 0;
}




//--------------------------------------------   
int CSnake::playGame()        //ִ����Ϸ
{
	int a[20][20] = { 0 };
	if (memcmp(image, a, sizeof(image)) == 0) {
		map.initPartMap();          //��ʼ������
		food.generatefood();           //����ʳ��
		block.generateBlock();
	}

	map.display();                //��ʾ��Ϸ���
	display_er();
	utils.showCursor(false);
	PlaySoundA("sound\\bg_snake.wav", NULL, SND_ASYNC | SND_LOOP);   //ѭ�����ű�����Ч
	utils.setEnglish();  //�л�Ӣ�����뷨

	while (!gameOver)
	{
		if (_kbhit())          //���հ���
		{
			arrowKey = _getch();
		}
		if (direction == 2 || direction == 8)  //�ƶ�����Ϊ����ʱ�����Ҽ���������
		{
			switch (arrowKey)
			{
			case'6':toRight(); break;
			case'4':toLeft(); break;
			case'e':exit(1); break;
			case'p':pause(); break;
			default:;//break;
			}
		}
		else if (direction == 4 || direction == 6)  //�ƶ�����Ϊ����ʱ�����¼���������
		{
			switch (arrowKey)
			{
			case'8':toUp(); break;
			case'5':toDown(); break;
			case'e':exit(1); break;
			case'p':pause(); break;
			default:;//break;
			} 
		}
		Sleep(gamespeed);    //С���ƶ��ٶ�
		automove();			   // С���Զ��ƶ�
		gameover();            //�ж���Ϸ�Ƿ����
		if (gameOver == 1) {     //��Ϸ��������ѭ��
			PlaySoundA("sound\\die.wav", NULL, SND_ASYNC | SND_NODEFAULT);   //��������������Ч
			break;
		}
		drawSnake();        //�ж��Ƿ��ʳ�� 
		map.display();       //��ʾ��Ϸ���
		display_er();     //��ʾ�������
		utils.showCursor(false);
	}

	Hero[0].Highscore = score;
	return 0;
}


void CSnake::display_er() {
	utils.gotoXY(46, 9); printf("SCORE:     ");      //����
	utils.gotoXY(46, 10); printf("LEVEL:    "); //�ȼ�
	utils.gotoXY(46, 11); printf("HP:       ");  //����ֵ

	utils.gotoXY(46, 9); printf("SCORE: %d", SNAKE->score);      //����
	utils.gotoXY(46, 10); printf("LEVEL: %d", SNAKE->level); //�ȼ�
	utils.gotoXY(46, 11); printf("HP: %d", SNAKE->healthPoint);  //����ֵ
}
//-------------------------------
void CSnake::displayCMer() {      //��ʾ�Զ����ͼ�������
	utils.gotoXY(46, 9); printf("SCORE:     ");      //����
	utils.gotoXY(46, 10); printf("LEVEL:    "); //�ȼ�
	utils.gotoXY(46, 11); printf("HP:       ");  //����ֵ

	utils.gotoXY(46, 9); printf("SCORE: %d", this->score);      //����
	utils.gotoXY(46, 10); printf("LEVEL: %d", this->level); //�ȼ�
	utils.gotoXY(46, 11); printf("HP: %d", this->healthPoint);  //����ֵ
}




void CSnake::saveGame() {
	FILE * file;
	if (fopen_s(&file, "snake1.txt", "wb") != 0)
	{
		cout << "can not open file!" << endl; return;
	}
	if (fwrite(&SNAKE, sizeof(CSnake), 1, file) != 1)
		cout << "file write error!" << endl;
	fclose(file);

	ofstream out1("snake2.txt");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 500; j++) {
			out1 << snake[i][j] << ' ';
		}
		out1 << endl;
	}
	out1.close();


	//image;
	ofstream out2("image.txt");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			out2 << image[i][j] << ' ';
		}
		out2 << endl;
	}
	out2.close();


	//������ɽ���
	utils.color(11);
	utils.gotoXY(10, 20);
	cout << "��������������������������������������������";
	utils.gotoXY(9, 21);
	cout << " ��              ����ɹ� !!!              ��";
	utils.gotoXY(10, 22);
	cout << "��������������������������������������������";
	Sleep(500);

}


void CSnake::readGame() {   //��ȡ��һ����Ϸ����

	int x[20][20];
	FILE* fp1;
	int flag1 = fopen_s(&fp1, "image.txt", "rb");   //��Ϸͼ������
	if (flag1 == 0) {
		cout << "open file" << endl;
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				fscanf_s(fp1, "%d", &x[i][j]);
			}
		}
	}
	fclose(fp1);

	memcpy(image, x, sizeof(x));

	int y[2][500];
	FILE* fp2;
	int flag2 = fopen_s(&fp2, "snake2.txt", "rb");  //��Ϸ��λ������
	if (flag2 == 0) {
		cout << "open file" << endl;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 500; j++) {
				fscanf_s(fp2, "%d", &y[i][j]);
			}
		}
	}
	fclose(fp2);

	memcpy(snake, y, sizeof(y));

	FILE *fp;
	if (fopen_s(&fp, "snake1.txt", "rb") == 0) {  //��Ϸ���ߵĸ�������
		fread(&SNAKE, sizeof(CSnake), 1, fp);
	}
	fclose(fp);
}