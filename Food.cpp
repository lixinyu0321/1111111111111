#include "stdafx.h"
#include"stdlib.h"
#include"time.h"
#include"Food.h"
#include"CSnake.h"


int Food::generatefood() {
	
	srand((unsigned int) time(NULL));       //��ʱ��Ϊ���������������
	do {
		//	food.getX() = rand() % 20;       //ʳ�������X����
		//	food.getY() = rand() % 20;      //ʳ�������Y����
		setX(rand() % 20);
		setY(rand() % 20);



	} while (image[getX()][getY()] != 0);    //������ʳ�������޶�����Ϸ����ڣ���ʳ�����겻��С�����������غ�
	image[getX()][getY()] = 2;
	return image[getX()][getY()];

}


int Food::createFoodCM() {
	srand((unsigned int)time(NULL));       //��ʱ��Ϊ���������������
	do {
		//	food.getX() = rand() % 20;       //ʳ�������X����
		//	food.getY() = rand() % 20;      //ʳ�������Y����
		setX(rand() % 20);
		setY(rand() % 20);


	} while (imageCM[getX()][getY()] != 0);    //������ʳ�������޶�����Ϸ����ڣ���ʳ�����겻��С�����������غ�
	imageCM[getX()][getY()] = 2;
	return imageCM[getX()][getY()];

}





int Food::getX() { return FoodX; }
int Food::getY() { return FoodY; }
void Food::setX(int x) { this->FoodX = x; }
void  Food::setY(int y) { this->FoodY = y; }