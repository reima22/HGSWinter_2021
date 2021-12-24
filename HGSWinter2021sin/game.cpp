
//==============================================================================
//
// �Q�[�����[�h�����kgame.cpp�l
// Author : Mare Horiai
//
//==============================================================================
#include "main.h"
#include "scene2D.h"
#include "renderer.h"
#include "manager.h"
#include "game.h"
#include "sound.h"
#include "fade.h"
#include "result.h"
#include "pause.h"

#include "timer_count.h"
#include "camera.h"

#include "effect.h"
#include "gamesetlogo.h"
#include "bg.h"
#include "ui.h"
#include "sign.h"
#include "chara.h"
#include "stand_by.h"
#include "match_result.h"
#include "select.h"
#include "input.h"

//==============================================================================
// �ÓI�����o�ϐ��錾
//==============================================================================
CPause *CGame::m_pPause = NULL;										// �|�[�Y�|�C���^
bool CGame::m_bGameEnd = false;										// �Q�[���I���̃t���O
int CGame::m_nClearDirectingCnt = 0;								// �Q�[���I�����o�J�E���g
CGamesetLogo *CGame::m_pGamesetLogo = NULL;							// �Q�[���I�����S

CUi *CGame::m_pUi = NULL;											// UI�N���X
CBg *CGame::m_pBg = NULL;											// �w�i�N���X
CSign *CGame::m_pSign = NULL;										// �T�C���N���X
CChara *CGame::m_pChara = NULL;										// �L�����N���X
CStandBy *CGame::m_pStandBy = NULL;									// �X�^���o�C��ʃN���X
CMatchResult *CGame::m_pMatchResult = NULL;							// ����
CSelect *CGame::m_pSelect = NULL;									// �I��
CGame::MATCH CGame::m_match = MATCH_NONE;

//==============================================================================
// �R���X�g���N�^
//==============================================================================
CGame::CGame(int nPriority) : CMode(nPriority)
{
	m_bGameEnd = false;
	m_nClearDirectingCnt = 0;
	m_match = MATCH_NONE;
}

//==============================================================================
// �f�X�g���N�^
//==============================================================================
CGame::~CGame()
{
}

//==============================================================================
// �Q�[�����[�h�̏���������
//==============================================================================
HRESULT CGame::Init(void)
{
	// �J�����̈ʒu������
	CCamera *pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->SetInit();
	}

	// �w�i�̐���
	if (m_pBg == NULL)
	{
		m_pBg = CBg::Create();
	}

	// �T�C���N���X
	if (m_pSign == NULL)
	{
		m_pSign = CSign::Create();
	}

	// �L�����N�^�[����
	if (m_pChara == NULL)
	{
		m_pChara = CChara::Create();
	}

	// �X�^���o�C��ʃN���X
	if (m_pStandBy == NULL)
	{
		m_pStandBy = CStandBy::Create();
	}

	// ����
	if (m_pMatchResult == NULL)
	{
		m_pMatchResult = CMatchResult::Create();
	}

	// UI�̐���
	if (m_pUi == NULL)
	{
		m_pUi = CUi::Create();
	}

	// �|�[�Y�̐���
	if (m_pPause == NULL)
	{
		m_pPause = CPause::Create();
	}

	// �I���N���X
	if (m_pSelect == NULL)
	{
		m_pSelect = CSelect::Create();
	}
	
	return S_OK;
}

//==============================================================================
// �Q�[�����[�h�̏I������
//==============================================================================
void CGame::Uninit(void)
{
	// �w�i�̐���
	if (m_pBg != NULL)
	{
		m_pBg->Uninit();
		m_pBg = NULL;
	}

	// BGM�̒�~
	if (m_pSound != NULL && CManager::GetBGMPlay(CSound::BGMTYPE_GAME) == true)
	{
		m_pSound->Stop();
	}

	// �|�[�Y�̏I��
	if (m_pPause != NULL)
	{
		m_pPause->Uninit();
		m_pPause = NULL;
	}

	// UI�̏I��
	if (m_pUi != NULL)
	{
		m_pUi->Uninit();
		m_pUi = NULL;
	}

	// �L�����N�^�[�̏I��
	if (m_pChara != NULL)
	{
		m_pChara->Uninit();
		m_pChara = NULL;
	}

	// �T�C���̏I��
	if (m_pSign != NULL)
	{
		m_pSign->Uninit();
		m_pSign = NULL;
	}

	// �X�^���o�C��ʂ̏I��
	if (m_pStandBy != NULL)
	{
		m_pStandBy->Uninit();
		m_pStandBy = NULL;
	}

	// ����
	if (m_pMatchResult != NULL)
	{
		m_pMatchResult->Uninit();
		m_pMatchResult = NULL;
	}


	// �I��
	if (m_pSelect != NULL)
	{
		m_pSelect->Uninit();
		m_pSelect = NULL;
	}

	Release();	// �C���X�^���X�̃f���[�g
}

//==============================================================================
// �Q�[�����[�h�̍X�V����
//==============================================================================
void CGame::Update(void)
{
	// �L�[�{�[�h�̎擾
	CInputKeyboard *keyboard = CManager::GetInputKeyboard();


	// �T�C�������̊J�n
	if (m_pSign->GetPhase() == CSign::SIGNPHASE_NONE)
	{
		if (keyboard->GetTrigger(CInput::KEYINFO_OK) == true || keyboard->GetTrigger(CInput::KEYINFO_START_SPACE) == true)
		{
			m_pSign->StartSign();
			m_pStandBy->DeleteWindow();
		}
	}

	// �Q�[���I��
	if (m_bGameEnd == true)
	{
		//EndGame();
	}
}

//==============================================================================
// �Q�[�����[�h�̕`�揈��
//==============================================================================
void CGame::Draw(void)
{
}

//==============================================================================
// �Q�[�����[�h�̐�������
//==============================================================================
CGame *CGame::Create()
{
	// �C���X�^���X����
	CGame *pGame;
	pGame = new CGame;

	// ������
	if (pGame != NULL)
	{
		pGame->Init();
	}

	return pGame;
}

//==============================================================================
// �Q�[���I�����o
//==============================================================================
//void CGame::EndGame(void)
//{
//	// �N���A���o�J�E���g�̉��Z
//	m_nClearDirectingCnt++;
//
//	switch (CResult::GetEndState())
//	{
//	case CResult::ENDSTATE_CLEAR:		// �N���A��
//
//		//GameClear();
//
//		break;
//
//	case CResult::ENDSTATE_GAMEOVER:	// �Q�[���I�[�o�[��
//
//		GameOver();
//
//		break;
//	}
//}