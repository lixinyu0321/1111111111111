#pragma once
#include"windows.h"

extern int imageCM[22][22]; //�߻��Χ

class CustomMap {
public :

void MouseEventProc(MOUSE_EVENT_RECORD mer);  // ����¼�������
void MessageLoop();  //��Ϣ������
void keyEventProc(KEY_EVENT_RECORD ker);
void gotoXYCM(int x, int y);
void displayCM();
void showCursorCM(bool isShow);
void colorCM(int a);
void printRange();
void editMap();
int x;
int y;
int n;

};