#pragma once

struct HeroList   //Ӣ�۰�ṹ����Ϣ
{
	char Name[10];
	int Highscore;
};

extern HeroList Hero[10];

class Utils {
public:
	void gotoXY(int x, int y);
	void color(int a);
	void setWindows(int cols, int lines);
	void showCursor(bool isShow);
	void setEnglish();
	void save();

};
