#pragma once

#include "myglobal.h"

int fontHandle;//�t�H���g�ǂݍ��ݗp�ϐ�
int mouseX = 0, mouseY = 0;//�}�E�X���W

						   //�L�[�擾�p�̔z��
char buf[256] = { 0 };
int keyState[256] = { 0 };

//�L�[���͏�Ԃ��X�V����֐�
void keyUpdate()
{
	GetHitKeyStateAll(buf);
	for (int i = 0; i< 256; i++)
	{
		if (buf[i] == 1) keyState[i]++;
		else keyState[i] = 0;
	}
}