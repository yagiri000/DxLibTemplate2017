#include <iostream>
#include "DxLib.h"

#include "MyGlobal.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(640, 480, 32);//��ʃT�C�Y�w��
	SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
	if (DxLib_Init() == 1) { return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��


	fontHandle = CreateFontToHandle("Segoe UI", 20, 5, DX_FONTTYPE_ANTIALIASING_4X4);//�t�H���g��ǂݍ���

																					 //
																					 //�����œG��v���C���[�̃I�u�W�F�N�g�̎��̂����
																					 //

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();//����ʏ���
		SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

		GetMousePoint(&mouseX, &mouseY); //�}�E�X���W�X�V
		keyUpdate();//(����֐�)�L�[�X�V

					//�����p�E������`��FkeyState�z��i����j�ɂ́A�e�L�[�����t���[�������ꑱ���Ă��邩�������Ă���
		DrawFormatStringToHandle(320, 320, GetColor(255, 255, 255), fontHandle, "Z KEY %d", keyState[KEY_INPUT_Z]);

		//
		//�@�����ɓG��v���C���[��update,draw������
		//

		//����ɕ����i�}�E�X�̍��W�j��`��
		DrawFormatStringToHandle(20, 20, GetColor(255, 255, 255), fontHandle, "MX:%3d MY:%3d", mouseX, mouseY);

		ScreenFlip();//����ʂ�\��ʂɃR�s�[
	}

	DxLib_End();
	return 0;
}