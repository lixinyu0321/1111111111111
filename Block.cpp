#include"stdafx.h"
#include"Block.h"
#include"time.h"
#include"stdlib.h"
#include"CSnake.h"


int Block::generateBlock() {   //���ɵڼ����ϰ���
	srand((unsigned int)time(NULL));       //��ʱ��Ϊ���������������
	do {
	
		blockX = (rand() % 20);
		blockY = (rand() % 20);

	} while (image[blockX][blockY] != 0);    //������ʳ�������޶�����Ϸ����ڣ���ʳ�����겻��С�����������غ�
	image[blockX][blockY] = 4;
	return image[blockX][blockY];

}

void Block::createBlockCM(Block* blockCM) {

	srand((unsigned int)time(NULL));       //��ʱ��Ϊ���������������
	int count = 0;
	for (int i = 0; i < 10;i++) {
		if (blockCM[i].blockX == 0) {
			count = i;
			break;
		}
	}

	do {

		blockCM[count].blockX = (rand() % 20);
		blockCM[count].blockY = (rand() % 20);

	} while (image[blockCM[count].blockX][blockCM[count].blockY] != 0);    //������ʳ�������޶�����Ϸ����ڣ���ʳ�����겻��С�����������غ�
	image[blockCM[count].blockX][blockCM[count].blockY] = 4;

}