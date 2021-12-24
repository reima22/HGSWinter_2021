//==============================================================================
//
// ���͏����kinput.h�l
// AUTHOR : MARE HORIAI
//
//==============================================================================
#pragma once
#ifndef _INPUT_H_
#define _INPUT_H_

#include "main.h"

//==============================================================================
// �}�N����`
//==============================================================================
#define KEY_STATE	(256)	// ���͏��

// ���̓N���X
class CInput
{
public:
	typedef enum 
	{
		KEYINFO_OK = 0,				// ����
		KEYINFO_UP,					// ��
		KEYINFO_DOWN,				// ��
		KEYINFO_LEFT,				// ��
		KEYINFO_RIGHT,				// �E
		KEYINFO_ARROW_UP,			// ��(�����L�[)
		KEYINFO_ARROW_DOWN,			// ��(�����L�[)
		KEYINFO_ARROW_LEFT,			// ��(�����L�[)
		KEYINFO_ARROW_RIGHT,		// �E(�����L�[)
		KEYINFO_START_SPACE,		// �W�����v
		KEYINFO_PAUSE,				// �|�[�Y
		KEYINFO_TUTO_BACK,			// �`���[�g���A���y�[�W�߂�
		KEYINFO_GO_LEFT,			// ���v���C���[�̓���
		KEYINFO_GO_RIGHT,			// �E�v���C���[�̓���
		KEYINFO_MAX
	}KEYINFO;

	CInput();
	virtual ~CInput();
	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	virtual void Uninit(void);
	virtual void Update(void) = 0;	// �������z�֐���

protected:
	LPDIRECTINPUTDEVICE8 m_pDevice;		// �f�o�C�X�|�C���^
	static LPDIRECTINPUT8 m_pInput;		// �S�̂ň�ŗǂ�(static:�ÓI�����o�ϐ�)	
	static int m_aKeyInfo[KEYINFO_MAX];	// ���̓L�[���
};

class CInputKeyboard : public CInput
{
public:
	CInputKeyboard();
	~CInputKeyboard();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit(void);
	void Update(void);

	static CInputKeyboard *Create(HINSTANCE hInstance, HWND hWnd);

	bool GetPress(int nKey);
	bool GetTrigger(int nKey);
	bool GetRelease(int nKey);
	bool GetRepeat(int nKey);

private:
	BYTE m_aKeyState[KEY_STATE];			// �L�[�v���X���
	BYTE m_aKeyStateTrigger[KEY_STATE];		// �L�[�g���K�[���
	BYTE m_aKeyStateRelease[KEY_STATE];		// �L�[�����[�X���
	BYTE m_aKeyStateRepeat[KEY_STATE];		// �L�[���s�[�g���

	int m_nCountRepeat;						// ���s�[�g�J�E���g
};

#endif
