
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

//==============================================================================
// �ÓI�����o�ϐ��錾
//==============================================================================
CPause *CGame::m_pPause = NULL;										// �|�[�Y�|�C���^
bool CGame::m_bGameEnd = false;										// �Q�[���I���̃t���O
int CGame::m_nClearDirectingCnt = 0;								// �Q�[���I�����o�J�E���g
CGame::CLEARPHASE CGame::m_clearPhase = CLEARPHASE_NONE;			// �N���A�t�F�C�Y
CGame::GAMEOVERPHASE CGame::m_gameoverPhase = GAMEOVERPHASE_NONE;	// �Q�[���I�[�o�[�t�F�C�Y
CGamesetLogo *CGame::m_pGamesetLogo = NULL;							// �Q�[���I�����S

CUi *CGame::m_pUi = NULL;											// UI�N���X
CBg *CGame::m_pBg = NULL;											// �w�i�N���X

//==============================================================================
// �R���X�g���N�^
//==============================================================================
CGame::CGame(int nPriority) : CMode(nPriority)
{
	m_bGameEnd = false;
	m_nClearDirectingCnt = 0;
	m_clearPhase = CLEARPHASE_NONE;
	m_gameoverPhase = GAMEOVERPHASE_NONE;
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
	
	return S_OK;
}

//==============================================================================
// �Q�[�����[�h�̏I������
//==============================================================================
void CGame::Uninit(void)
{
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

	Release();	// �C���X�^���X�̃f���[�g
}

//==============================================================================
// �Q�[�����[�h�̍X�V����
//==============================================================================
void CGame::Update(void)
{
	// �^�C�}�[�ɂ��I��
	if (m_pUi != NULL)
	{
		if (m_pUi->GetTimer()->GetTimerCnt()->GetNumber() <= 0)
		{
			// ���Ԑ؂�ŃQ�[���I�[�o�[
			CResult::SetEndState(CResult::ENDSTATE_GAMEOVER);
			//m_pPlayer->SetGameOver(true);
			m_bGameEnd = true;
		}
	}

	// �Q�[���I��
	if (m_bGameEnd == true)
	{
		EndGame();
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
// �X�e�[�W�I�u�W�F�N�g�ݒ�
//==============================================================================
void CGame::SetStageObject(void)
{

}

//==============================================================================
// �Q�[���I�����o
//==============================================================================
void CGame::EndGame(void)
{
	// �N���A���o�J�E���g�̉��Z
	m_nClearDirectingCnt++;

	switch (CResult::GetEndState())
	{
	case CResult::ENDSTATE_CLEAR:		// �N���A��

		//GameClear();

		break;

	case CResult::ENDSTATE_GAMEOVER:	// �Q�[���I�[�o�[��

		GameOver();

		break;
	}
}

//==============================================================================
// �Q�[���N���A
//==============================================================================
//void CGame::GameClear(void)
//{
//	// �t�F�[�h���̎擾
//	CFade *pFade;
//	pFade = CManager::GetFade();
//
//	switch (m_clearPhase)
//	{
//	case CLEARPHASE_NONE:
//		SetClearPhase(CGame::CLEARPHASE_WAIT);
//		break;
//
//	case CLEARPHASE_WAIT:
//		
//		if (m_nClearDirectingCnt >= CNT_ONE_SECOND)
//		{
//			m_pSound->Play(CSound::SOUND_LABEL_SE_STAGECLEAR);	// �t�@���t�@�[��
//															
//			m_pGamesetLogo = CGamesetLogo::Create();	// ���S����
//			SetClearPhase(CLEARPHASE_PAUSE);
//			m_nClearDirectingCnt = 0;
//		}
//
//		break;
//
//	case CLEARPHASE_PAUSE:
//
//		//m_pPlayer->GetMotionPlayer()->SetMotion(CMotionPlayer::MOTIONTYPE_CLEAR);
//
//
//
//		if (m_nClearDirectingCnt % 6 == 0)
//		{
//			CEffectDetail::Create(CEffectDetail::EFFECTTYPE_GAMECLEAR, VECTOR3_NULL);
//
//		}
//
//		if (m_nClearDirectingCnt >= CNT_ONE_SECOND * 6)
//		{
//			SetClearPhase(CLEARPHASE_FADE);
//		}
//
//		break;
//
//	case CLEARPHASE_FADE:
//
//		CResult::SetEndState(CResult::ENDSTATE_CLEAR);
//		pFade->SetFade(CFade::FADE_OUT, CMode::MODE_RESULT);
//
//		break;
//	}
//}

//==============================================================================
// �Q�[���I�[�o�[
//==============================================================================
void CGame::GameOver(void)
{
	// �t�F�[�h���̎擾
	CFade *pFade;
	pFade = CManager::GetFade();

	switch (m_gameoverPhase)
	{
	case GAMEOVERPHASE_NONE:
		m_pSound->Stop();
		m_pSound->Play(CSound::SOUND_LABEL_SE_TIMEOVER);
		SetOverPhase(GAMEOVERPHASE_WAIT);
		break;

	case GAMEOVERPHASE_WAIT:
		if (m_nClearDirectingCnt >= CNT_ONE_SECOND * 2)
		{
			SetOverPhase(GAMEOVERPHASE_DIRECTION);
			m_pSound->Play(CSound::SOUND_LABEL_SE_GAMEOVER);
			m_nClearDirectingCnt = 0;
		}
		break;

	case GAMEOVERPHASE_DIRECTION:

		// ���S����
		m_pGamesetLogo = CGamesetLogo::Create();

		if (m_nClearDirectingCnt >= CNT_ONE_SECOND * 6)
		{
			SetOverPhase(GAMEOVERPHASE_FADE);
		}
		break;

	case GAMEOVERPHASE_FADE:

		CResult::SetEndState(CResult::ENDSTATE_GAMEOVER);
		pFade->SetFade(CFade::FADE_OUT, CMode::MODE_RESULT);

		break;
	}
}