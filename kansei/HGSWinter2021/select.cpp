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
#include "select.h"
#include "fade.h"

bool CSelect::m_bActiveOn = false;
//==============================================================================
// �R���X�g���N�^
//==============================================================================
CSelect::CSelect(int nPriority) : CScene(nPriority)
{
	m_bActiveOn = false;
}

//==============================================================================
// �f�X�g���N�^
//==============================================================================
CSelect::~CSelect()
{
}

//==============================================================================
// �L�����N�^�[�̏���������
//==============================================================================
HRESULT CSelect::Init(void)
{
	if (m_pBase == NULL)
	{
		m_pBase = CScene2D::Create();
		m_pBase->SetPosition(SCREEN_CENTER);
		m_pBase->SetSize(SCREEN_SIZE);
		m_pBase->SetTex(1, 1, 0, 0, 0.0f, 0.0f);
		m_pBase->SetCol(D3DXCOLOR(0.0f, 1.0f, 1.0f, 0.0f));
	}

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

	m_apScene[0]->BindTexture("RETRY");
	m_apScene[1]->BindTexture("TOTITLE");
	m_select = SELECT_RETRY;

	return S_OK;
}

//==============================================================================
// �X�^���o�C��ʂ̏I������
//==============================================================================
void CSelect::Uninit(void)
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

	if (m_pBase != NULL)
	{
		m_pBase->Uninit();
		m_pBase = NULL;
	}

	Release();
}

//==============================================================================
// �X�^���o�C��ʂ̍X�V����
//==============================================================================
void CSelect::Update(void)
{
	if (m_bActiveOn == true)
	{
		Active();
	}
}

//==============================================================================
// �X�^���o�C��ʂ̕`�揈��
//==============================================================================
void CSelect::Draw(void)
{
}

//==============================================================================
// �X�^���o�C��ʂ̐�������
//==============================================================================
CSelect *CSelect::Create(void)
{
	// �C���X�^���X����
	CSelect *pSelect;
	pSelect = new CSelect;

	// ������
	if (pSelect != NULL)
	{
		pSelect->Init();
	}

	return pSelect;
}

void CSelect::Active(void)
{
	CInputKeyboard *keyboard = CManager::GetInputKeyboard();
	CFade *pFade = CManager::GetFade();


	if (CGame::GetMatch() != CGame::MATCH_NONE)
	{
		m_pBase->SetCol(D3DXCOLOR(0.0f, 1.0f, 1.0f, 0.5f));

		// ����
		if (keyboard->GetTrigger(CInput::KEYINFO_DOWN) == true || keyboard->GetTrigger(CInput::KEYINFO_ARROW_DOWN) == true)
		{
			m_select = (SELECT)(m_select + 1);

			if (m_select == SELECT_MAX)
			{
				m_select = (SELECT)0;
			}
		}
		else if (keyboard->GetTrigger(CInput::KEYINFO_UP) == true || keyboard->GetTrigger(CInput::KEYINFO_ARROW_UP) == true)
		{
			m_select = (SELECT)(m_select - 1);

			if (m_select < 0)
			{
				m_select = (SELECT)(SELECT_MAX - 1);
			}
		}

		switch (m_select)
		{
		case SELECT_RETRY:
			m_apScene[0]->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			m_apScene[1]->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));

			if (keyboard->GetTrigger(CInput::KEYINFO_OK) == true)
			{
				pFade->SetFade(CFade::FADE_OUT, CMode::MODE_GAME);
			}

			break;

		case SELECT_TOTITLE:

			m_apScene[0]->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
			m_apScene[1]->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

			if (keyboard->GetTrigger(CInput::KEYINFO_OK) == true)
			{
				pFade->SetFade(CFade::FADE_OUT, CMode::MODE_TITLE);
			}

			break;
		}

		m_apScene[0]->SetPosition(RETRY_POS);
		m_apScene[1]->SetPosition(TOTITLE_POS);
	}

	
}