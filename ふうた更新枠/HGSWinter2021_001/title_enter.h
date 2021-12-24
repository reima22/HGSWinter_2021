//=============================================================================
//
// �^�C�g���G���^�[�T�C���`�揈�� [title_enter.h]
// Author : Mare Horiai
//
//============================================================================= 
#ifndef _TITLE_ENTER_H_
#define _TITLE_ENTER_H_

#include "main.h"
#include "scene.h"
#include "scene2D.h"

// �}�N����`
#define T_ENTER_POS		(D3DXVECTOR3(640.0f, 3100.0f, 0))	// �G���^�[�T�C���̈ʒu
#define T_ENTER_SIZE	(D3DXVECTOR2(150.0f, 100.0f / 2.0f))		// �G���^�[�T�C���̃T�C�Y
#define T_ENTER_SETPOS	(D3DXVECTOR3(640.0f, 450.0f, 0.0f))

#define TIME_COLOR				(50)								//	�F�ω�����

#define MOVE_START_Y			(-8.0f)								//	START�@		Y���̈ړ��l
#define MOVE_START_X			(0.0f)

//#define T_ENTER_SIZEX	(340.0f)	// ��
//#define T_ENTER_SIZEY	(40.0f)		// ����

class CTutorialPage;	// �`���[�g���A���y�[�W�|�C���^


//==============================================================================
// �G���^�[�T�C���N���X
//==============================================================================
class CTitleEnter : public CScene2D
{
public:
	enum SELECT_TYPE
	{
		SELECT_GAME = 0,
		SELECT_TUTORIAL,
		SELECT_MAX
	};

	CTitleEnter(int nPriority = PRIORITY_UI);
	~CTitleEnter();
	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CTitleEnter *Create(D3DXVECTOR3 pos);
	
private:

	void SelectModeUI(SELECT_TYPE ID);

	static CTutorialPage *m_pTutorialPage;			// �`���[�g���A���y�[�W�|�C���^

	CScene2D *m_p2DGameUI;		// 2D�|���S���N���X�|�C���^
	CScene2D *m_p2DTutorialUI;	// 2D�|���S���N���X�|�C���^
	D3DXVECTOR3 m_GameUIpos;				// �ʒu
	D3DXVECTOR3 m_TutorialUIpos;			// �ʒu
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_move;			// �ړ���
	D3DXCOLOR m_col;			// �F
	D3DXCOLOR m_SelectCol;

	bool m_bEnter;			// �G���^�[�����������ǂ���
	bool m_bNextScene;		// ���̃V�[���Ɉړ����邩�ǂ���
	bool m_bJump;			// �W�����v����
	int m_nCntColor;		// �ҋ@�_�ŃJ�E���g
	int m_nTimeColor;		// ����_�ŃJ�E���g
	int m_nTimer;			// �^�C�}�[
	int m_nMoveTime;
	bool m_bTutorial;

	SELECT_TYPE m_SelectID;			// �I�𒆂̃��[�h
};
#endif
