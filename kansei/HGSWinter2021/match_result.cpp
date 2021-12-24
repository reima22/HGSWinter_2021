//==============================================================================
//
// �X�^���o�C�`�揈���kstand_by.cpp�l
// Author : Mare Horiai
//
//==============================================================================
#include "main.h"
#include "scene2D.h"
#include "renderer.h"
#include "manager.h"
//#include "sign.h"
#include "match_result.h"
#include "input.h"
#include "game.h"

//==============================================================================
// �R���X�g���N�^
//==============================================================================
CMatchResult::CMatchResult(int nPriority) : CScene(nPriority)
{
}

//==============================================================================
// �f�X�g���N�^
//==============================================================================
CMatchResult::~CMatchResult()
{
}

//==============================================================================
// �L�����N�^�[�̏���������
//==============================================================================
HRESULT CMatchResult::Init(void)
{
	// ������
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (m_apScene[nCnt] == NULL)
		{
			m_apScene[nCnt] = CScene2D::Create();
			m_apScene[nCnt]->SetPosition(VECTOR3_NULL);
			m_apScene[nCnt]->SetSize(RESULT_SIZE);
			m_apScene[nCnt]->SetTex(1, 1, 0, 0, 0.0f, 0.0f);
			m_apScene[nCnt]->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
		}
	}

	return S_OK;
}

//==============================================================================
// �X�^���o�C��ʂ̏I������
//==============================================================================
void CMatchResult::Uninit(void)
{
	// �|���S���̔j��
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (m_apScene[nCnt] != NULL)
		{
			m_apScene[nCnt]->Uninit();
			m_apScene[nCnt] = NULL;
		}
	}

	Release();
}

//==============================================================================
// �X�^���o�C��ʂ̍X�V����
//==============================================================================
void CMatchResult::Update(void)
{

}

//==============================================================================
// �X�^���o�C��ʂ̕`�揈��
//==============================================================================
void CMatchResult::Draw(void)
{
}

//==============================================================================
// �X�^���o�C��ʂ̐�������
//==============================================================================
CMatchResult *CMatchResult::Create(void)
{
	// �C���X�^���X����
	CMatchResult *pMatchResult;
	pMatchResult = new CMatchResult;

	// ������
	if (pMatchResult != NULL)
	{
		pMatchResult->Init();
	}

	return pMatchResult;
}

// ���s���o
void CMatchResult::MatchResult(void)
{
	switch (CGame::GetMatch())
	{
	case CGame::MATCH_LEFT:

		m_apScene[0]->SetPosition(RESULT_POS_WIN_LEFT);
		m_apScene[0]->BindTexture("WIN");

		m_apScene[1]->SetPosition(RESULT_POS_LOSE_RIGHT);
		m_apScene[1]->BindTexture("LOSE");

		break;

	case CGame::MATCH_RIGHT:

		m_apScene[0]->SetPosition(RESULT_POS_LOSE_LEFT);
		m_apScene[0]->BindTexture("LOSE");

		m_apScene[1]->SetPosition(RESULT_POS_WIN_RIGHT);
		m_apScene[1]->BindTexture("WIN");
		
		break;

	case CGame::MATCH_DRAW:
		break;
	}

	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		m_apScene[nCnt]->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}
}