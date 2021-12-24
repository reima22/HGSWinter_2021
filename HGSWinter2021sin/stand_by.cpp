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
#include "stand_by.h"
#include "input.h"

//==============================================================================
// �R���X�g���N�^
//==============================================================================
CStandBy::CStandBy(int nPriority) : CScene(nPriority)
{
	m_pBase = NULL;
	m_pControlSign = NULL;
}

//==============================================================================
// �f�X�g���N�^
//==============================================================================
CStandBy::~CStandBy()
{
}

//==============================================================================
// �L�����N�^�[�̏���������
//==============================================================================
HRESULT CStandBy::Init(void)
{
	// ������
	if (m_pBase == NULL)
	{
		m_pBase = CScene2D::Create();
		m_pBase->SetPosition(SCREEN_CENTER);
		m_pBase->SetSize(STAND_BY_SIZE);
		//m_pBase->BindTexture("GAME_BG");
		m_pBase->SetCol(D3DXCOLOR(1.0f, 0.0f, 0.0f, 0.5f));
		m_pBase->SetTex(1, 1, 0, 0, 0.0f, 0.0f);
	}

	if (m_pControlSign == NULL)
	{
		m_pControlSign = CScene2D::Create();
		m_pControlSign->SetPosition(SCREEN_CENTER);
		m_pControlSign->SetSize(STAND_BY_SIGN_SIZE);

		m_pControlSign->BindTexture("STANDBY_LOGO");
		m_pControlSign->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		m_pControlSign->SetTex(1, 1, 0, 0, 0.0f, 0.0f);
	}

	return S_OK;
}

//==============================================================================
// �X�^���o�C��ʂ̏I������
//==============================================================================
void CStandBy::Uninit(void)
{
	// �|���S���̔j��
	if (m_pBase != NULL)
	{
		m_pBase->Uninit();
		m_pBase = NULL;
	}

	if (m_pControlSign != NULL)
	{
		m_pControlSign->Uninit();
		m_pControlSign = NULL;
	}

	Release();
}

//==============================================================================
// �X�^���o�C��ʂ̍X�V����
//==============================================================================
void CStandBy::Update(void)
{
	
}

//==============================================================================
// �X�^���o�C��ʂ̕`�揈��
//==============================================================================
void CStandBy::Draw(void)
{
}

//==============================================================================
// �X�^���o�C��ʂ̐�������
//==============================================================================
CStandBy *CStandBy::Create(void)
{
	// �C���X�^���X����
	CStandBy *pStandBy;
	pStandBy = new CStandBy;

	// ������
	if (pStandBy != NULL)
	{
		pStandBy->Init();
	}

	return pStandBy;
}

// ��ʂ̏���
void CStandBy::DeleteWindow(void)
{
	if (m_pBase != NULL)
	{
		m_pBase->SetCol(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));
	}
	if (m_pControlSign != NULL)
	{
		m_pControlSign->SetCol(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));
	}
}