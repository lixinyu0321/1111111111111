#pragma once
#include"Food.h"
#include"Map.h"
#include"Utils.h"
#include"Block.h"
#include"CustomMap.h"

class Food;
class Map;
class Utils;
class Block;

extern int image[20][20]; //�߻��Χ
extern int snake[2][500];//��¼С���������������


class CSnake{
public:
	Food food;
	Map map;
	Utils utils;
	Block block;
	CustomMap customMap;

	Food foodCM;


	int snakeX;               //��¼С�ߵ�ͷ��X����
	int snakeY;               //��¼С�ߵ�ͷ��Y����
	int head;                 //С��ͷ���±�
	int tail;                 //С��β���±�
	int node;                 //�ߵĽڵ���
	int direction;            //��ͷ����   

	int healthPoint;  //�ߵ�����ֵ

	int gamespeed;            //��Ϸ�ٶ�
	int score;                //����
	char arrowKey;            //���հ����ı���
	int gameOver;             //ʹ��Ϸ�����ı���
	int level;                //���õȼ�
	int length;               //���ݳ������õȼ�


	CSnake()   //���캯����ʼ�����ֱ���
	{
		healthPoint = 100;   //��ʼ������ֵΪ100
		head = 3;                //��ʼ��ͷ���±�
		tail = 0;                //��ʼ��β���±�
		node = 4;                //�߳�ʼΪ�Ľڵ�
		gamespeed = 300;         //��Ϸ�ٶȣ��ƶ��ļ��ʱ��ms��
		score = 0;               //��ʼ������Ϊ0
		direction = 6;           //�ߵĳ�ʼ��������
		gameOver = 0;            //������Ϸ��ʼ��Ϊ0
		level = 1;
		length = 4;
	}
	~CSnake(){}
//	void Init();                //��ʼ����Ϸ��弰С�ߵ�����
	int  drawSnake();           //��¼С��ÿ���ƶ���ͷ�����������һ����

	int drawSnakeCM();

	void  automove();            //���Զ��ƶ�
	void automoveCM();


	int  gameover();            //�ж���Ϸ�Ƿ����
	int gameoverCM();

//	int  Generatefood();        //����ʳ��
	void display_er();             //��ʾ�������
	void displayCMer();



	void toLeft();           //����
	void toRight();          //����
	void toDown();           //����
	void toUp();	         //����
	int  playGame();            //ִ����Ϸ
	void setspeed();            //�����ٶ�

	int pause();                //��Ϸ����ͣ
	int pauseCMGame();    //�Զ�����Ϸ����ͣ
	int pauseCM();    //�Զ���༭��ͼ����ͣ

	void saveGame();
	void readGame();
};