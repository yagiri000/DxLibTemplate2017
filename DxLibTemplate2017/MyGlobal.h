#pragma once
#include "DxLib.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern int fontHandle;
extern int mouseX, mouseY;//�}�E�X���W

						  //�L�[�擾�}�E�X�t��
extern char buf[256];
extern int keyState[256];

//�L�[���͏�Ԃ��X�V����֐�
void keyUpdate();

