#pragma once
#include"Utils.h"

class Utils;

class Map {
	Utils utils;
public:
	void initPartMap(); //��ʼ�����ֵ�ͼ����
	void initPartMapCM();

	void display();// ��ʾ��Ϸ��壨����Χǽ��ʳ�ＰС�ߣ�

	int showMenu();
	int showMenuCM();
	void setBackColor();
};

