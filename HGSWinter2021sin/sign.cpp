//==============================================================================
//
// �T�C��(�w��)�`�揈���ksign.cpp�l
// Author : Mare Horiai
//
//==============================================================================
#include "main.h"
#include "scene2D.h"
#include "renderer.h"
#include "manager.h"
#include "sign.h"
#include "input.h"
#include "game.h"
#include "chara.h"
#include "match_result.h"
#include "select.h"

//==============================================================================
// �R���X�g���N�^
//==============================================================================
CSign::CSign(int nPriority) : CScene(nPriority)
{
	m_nCntActive = 0;
	m_nCntChange = 0;
	m_nCntSelect = 0;
}

//==============================================================================
// �f�X�g���N�^
//==============================================================================
CSign::~CSign()
{
}

//==============================================================================
// �T�C���̏���������
//==============================================================================
HRESULT CSign::Init(void)
{
	// ������
	if (m_pScene2D == NULL)
	{
		m_pScene2D = new CScene2D;
		m_pScene2D->Init();
		m_pScene2D->SetPosition(SCREEN_CENTER);
		m_pScene2D->SetSize(VECTOR2_NULL);
		m_pScene2D->BindTexture("MERRY_SIGN");
		m_pScene2D->SetTex(1, 1, 0, 0, 0.0f, 0.0f);
	}

	// �I������l
	m_nCntEnd = rand() % 4 + 2 ;

	return S_OK;
}

//==============================================================================
// �T�C���̏I������
//==============================================================================
void CSign::Uninit(void)
{
	// �|���S���̔j��
	if (m_pScene2D != NULL)
	{
		m_pScene2D->Uninit();
		m_pScene2D = NULL;
	}

	Release();
}

//==============================================================================
// �T�C���̍X�V����
//==============================================================================
void CSign::Update(void)
{
	// �T�C���̋���
	SignBehave();
}

//==============================================================================
// �T�C���̕`�揈��
//==============================================================================
void CSign::Draw(void)
{

}

//==============================================================================
// �T�C���̐�������
//==============================================================================
CSign *CSign::Create(void)
{
	// �C���X�^���X����
	CSign *pSign;
	pSign = new CSign;

	// ������
	if (pSign != NULL)
	{
		pSign->Init();
	}

	return pSign;
}

//==============================================================================
// �T�C���̋���
//==============================================================================
void CSign::SignBehave(void)
{
	// ���[�J���ϐ��錾
	D3DXVECTOR2 size = m_pScene2D->GetSize();	// �T�C�Y�̎擾
	CInputKeyboard *keyboard = CManager::GetInputKeyboard();

	CGame::MATCH match = CGame::GetMatch();	// ���s���̎擾
	CChara *pChara = CGame::GetChara();		// �L�������̎擾
	CMatchResult *pMatchResult = CGame::GetMatchResult();

	// ��Ԃ��Ƃ̋���
	switch (m_signPhase)
	{
	case SIGNPHASE_WAIT:	// �ҋ@���
		m_pScene2D->BindTexture("SIGN_MERRY");

		size += D3DXVECTOR2(1.0f, 0.5f);

		m_pScene2D->SetSize(size);

		// �ړ�
		pChara->CharaMove();

		m_nCntActive++;

		if (m_nCntActive >= 180)
		{
			m_signPhase = SIGNPHASE_ACTIVE;
			m_pScene2D->SetSize(D3DXVECTOR2(400.0f, 400.0f));
			m_pScene2D->BindTexture("DUMMY0");
			m_nCntActive = 0;
		}

		break;

	case SIGNPHASE_ACTIVE:	// ���͉\���

		if (m_imageType != IMAGETYPE_TRUE)
		{
			m_nCntActive++;
		}
		else
		{
			m_nCntActive = 1;
		}
		
		// �摜�̍����ւ������_��
		if ((m_nCntActive % 150 == 0) )
		{
			int nType = -1;
			while (nType == (int)m_imageType)
			{// �d�����
				nType = (rand() % (int)IMAGETYPE_MAX - 1) + 1;
			}

			m_imageType = (IMAGETYPE)nType;
			m_nCntChange++;

			if (m_nCntChange == m_nCntEnd)
			{
				m_imageType = IMAGETYPE_TRUE;
			}

			m_pSound->Play(CSound::SOUND_LABEL_SE_SAVEPOINT);
		}

		switch (m_imageType)
		{
		case IMAGETYPE_TRUE:
			m_pScene2D->BindTexture("SIGN_XMAS");
			break;

		case IMAGETYPE_DAMMY_A:
			m_pScene2D->BindTexture("DUMMY0");
			break;

		case IMAGETYPE_DAMMY_B:
			m_pScene2D->BindTexture("DUMMY1");
			break;

		case IMAGETYPE_DAMMY_C:
			m_pScene2D->BindTexture("DUMMY2");
			break;

		case IMAGETYPE_DAMMY_D:
			m_pScene2D->BindTexture("DUMMY3");
			break;

		case IMAGETYPE_DAMMY_E:
			m_pScene2D->BindTexture("DUMMY4");
			break;

		case IMAGETYPE_DAMMY_F:
			m_pScene2D->BindTexture("DUMMY5");
			break;

		case IMAGETYPE_DAMMY_G:
			m_pScene2D->BindTexture("DUMMY6");
			break;

		case IMAGETYPE_DAMMY_H:
			m_pScene2D->BindTexture("DUMMY7");
			break;

		case IMAGETYPE_DAMMY_I:
			m_pScene2D->BindTexture("DUMMY8");
			break;

		case IMAGETYPE_DAMMY_J:
			m_pScene2D->BindTexture("DUMMY9");
			break;

		case IMAGETYPE_DAMMY_K:
			m_pScene2D->BindTexture("DUMMY10");
			break;

		case IMAGETYPE_DAMMY_L:
			m_pScene2D->BindTexture("DUMMY11");
			break;

		case IMAGETYPE_DAMMY_M:
			m_pScene2D->BindTexture("DUMMY12");
			break;

		case IMAGETYPE_DAMMY_N:
			m_pScene2D->BindTexture("DUMMY13");
			break;

		case IMAGETYPE_DAMMY_O:
			m_pScene2D->BindTexture("DUMMY14");
			break;

		case IMAGETYPE_DAMMY_P:
			m_pScene2D->BindTexture("DUMMY15");
			break;

		case IMAGETYPE_DAMMY_Q:
			m_pScene2D->BindTexture("DUMMY16");
			break;

		case IMAGETYPE_DAMMY_R:
			m_pScene2D->BindTexture("DUMMY17");
			break;
		}

		if (CGame::GetMatch() == CGame::MATCH_NONE && m_imageType == IMAGETYPE_TRUE)
		{
			// ��������
			if (keyboard->GetTrigger(CInput::KEYINFO_GO_LEFT) == true && keyboard->GetTrigger(CInput::KEYINFO_GO_RIGHT) == true)
			{
				CGame::SetMatch(CGame::MATCH_DRAW);
			}

			// ����������
			if (keyboard->GetTrigger(CInput::KEYINFO_GO_LEFT) == true)
			{
				CGame::SetMatch(CGame::MATCH_LEFT);
			}

			// �E��������	
			if (keyboard->GetTrigger(CInput::KEYINFO_GO_RIGHT) == true)
			{
				CGame::SetMatch(CGame::MATCH_RIGHT);
			}
		}

		if (CGame::GetMatch() != CGame::MATCH_NONE)
		{
			pMatchResult->MatchResult();
			
			m_nCntSelect++;

			if (m_nCntSelect >= 120)
			{
				CSelect::On();
			}
		}
		
		
		break;

	//case SIGNPHASE_DUMMY:		// �U�̓���
	//	break;

	case SIGNPHASE_INTERVAL:	// ���͊Ԋu
		break;
	}
}