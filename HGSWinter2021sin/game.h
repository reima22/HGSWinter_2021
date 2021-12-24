
//=============================================================================
//
// �Q�[�����[�h���� [game.h]
// Author : Mare Horiai
//
//============================================================================= 
#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"
#include "scene.h"
#include "mode.h"

// �O���錾
class CPause;			// �|�[�Y�N���X
class CTimer;			// �^�C�}�[�N���X
class CFall;			// �������N���X
class CSound;			// �T�E���h�N���X
class CStartCntdown;	// �J�n���J�E���g�_�E���N���X
class CBonus;			// �{�[�i�X�N���X
class CCheckpointLogo;	// �`�F�b�N�|�C���g���S�N���X
class CGamesetLogo;		// �Q�[�����ʃ��S
class CUi;				// UI�N���X
class CBg;				// �w�i�N���X
class CSign;			// �T�C���N���X
class CChara;			// �L�����N�^�[�N���X
class CStandBy;			// �X�^���o�C��ʃN���X
class CMatchResult;		// ����
class CSelect;			// �I���N���X

//==============================================================================
// �Q�[�����[�h�N���X
//==============================================================================
class CGame : public CMode
{
public:
	// �������ʂ̎��
	typedef enum
	{
		MATCH_NONE = 0,	// �����O
		MATCH_LEFT,		// ���̏���
		MATCH_RIGHT,	// �E�̏���
		MATCH_DRAW,		// ��������
		MATCH_MAX	
	}MATCH;

	CGame(int nPriority = PRIORITY_DEFAULT);
	~CGame();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CGame *Create(void);

	//void EndGame(void);

	//void GameClear(void);
	//void GameOver(void);

	static CUi *GetUi(void) { return m_pUi; }			// UI�̎擾
	static CChara *GetChara(void) { return m_pChara; }	// �L�����N�^�[�̎擾
	static CMatchResult *GetMatchResult(void) { return m_pMatchResult; }

	// �Q�[���I���t���O�̎擾�E�ݒ�
	static bool GetGameEnd(void) { return m_bGameEnd; }
	static void SetGameEnd(bool bGameEnd) { m_bGameEnd = bGameEnd; }

	// ���s���擾�E�ݒ�
	static MATCH GetMatch(void) { return m_match; }
	static void SetMatch(MATCH match) { m_match = match; }

private:
	int m_nNumObject;						// �I�u�W�F�N�g��
	int m_nNumMeshfield;					// ���b�V���t�B�[���h�̐�
	static CPause *m_pPause;				// �|�[�Y�̃|�C���^

	static bool m_bGameEnd;					// �Q�[���I���̃t���O
	static int m_nClearDirectingCnt;		// �N���A���o�J�E���g

	static CGamesetLogo *m_pGamesetLogo;

	static CBg *m_pBg;						// �w�i�|�C���^
	static CUi *m_pUi;						// UI�̃|�C���^
	static CSign *m_pSign;					// �T�C���N���X
	static CChara *m_pChara;				// �L�����N���X
	static CStandBy *m_pStandBy;			// �X�^���o�C��ʃN���X
	static CMatchResult *m_pMatchResult;	// ���ʃN���X
	static CSelect *m_pSelect;				// �I���N���X

	static MATCH m_match;							// ���s���
};

#endif