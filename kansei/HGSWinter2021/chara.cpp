//==============================================================================
//
// �L�����N�^�[�`�揈���kchara.cpp�l
// Author : Mare Horiai
//
//==============================================================================
#include "main.h"
#include "scene2D.h"
#include "renderer.h"
#include "manager.h"
#include "sign.h"
#include "chara.h"
#include "input.h"
#include "game.h"

//==============================================================================
// �R���X�g���N�^
//==============================================================================
CChara::CChara(int nPriority) : CScene(nPriority)
{
}

//==============================================================================
// �f�X�g���N�^
//==============================================================================
CChara::~CChara()
{
}

//==============================================================================
// �L�����N�^�[�̏���������
//==============================================================================
HRESULT CChara::Init(void)
{
	// ������
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (m_apScene2D[nCnt] == NULL)
		{
			m_apScene2D[nCnt] = CScene2D::Create();
			
			m_apScene2D[nCnt]->SetSize(CHARA_SIZE);
			m_apScene2D[nCnt]->SetTex(1, 1, 0, 0, 0.0f, 0.0f);

			// ���E��
			if (nCnt == 0)
			{// ��
				m_apScene2D[nCnt]->SetPosition(CHARA_POS_LEFT);
				m_apScene2D[nCnt]->BindTexture("CHARACTER_LEFT");
			}
			else
			{// �E
				m_apScene2D[nCnt]->SetPosition(CHARA_POS_RIGHT);
				m_apScene2D[nCnt]->BindTexture("CHARACTER_RIGHT");
			}
		}
	}


	return S_OK;
}

//==============================================================================
// �L�����N�^�[�̏I������
//==============================================================================
void CChara::Uninit(void)
{
	// �|���S���̔j��
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (m_apScene2D[nCnt] != NULL)
		{
			m_apScene2D[nCnt]->Uninit();
			m_apScene2D[nCnt] = NULL;
		}
	}

	Release();
}

//==============================================================================
// �L�����N�^�[�̍X�V����
//==============================================================================
void CChara::Update(void)
{
	GameEnd();
}

//==============================================================================
// �L�����N�^�[�̕`�揈��
//==============================================================================
void CChara::Draw(void)
{

}

//==============================================================================
// �L�����N�^�[�̐�������
//==============================================================================
CChara *CChara::Create(void)
{
	// �C���X�^���X����
	CChara *pChara;
	pChara = new CChara;

	// ������
	if (pChara != NULL)
	{
		pChara->Init();
	}

	return pChara;
}

//==============================================================================
// �T�C���̋���
//==============================================================================
void CChara::CharaMove(void)
{
	// �ړ�
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		D3DXVECTOR2 size = m_apScene2D[nCnt]->GetSize();	// �T�C�Y�̎擾
		D3DXVECTOR3 pos = m_apScene2D[nCnt]->GetPosition();	// �ʒu�̎擾

		size += D3DXVECTOR2(0.5f, 1.0f);

		if (nCnt == 0)
		{
			pos.x -= 1.0f;
			pos.y += 0.5f;
		}
		else
		{
			pos.x += 1.0f;
			pos.y += 0.5f;
		}
		
		m_apScene2D[nCnt]->SetSize(size);
		m_apScene2D[nCnt]->SetPosition(pos);
	}
}

// �Q�[���G���h
void CChara::GameEnd(void)
{
	// ���[�J���ϐ��錾
	D3DXVECTOR3 posLeft = m_apScene2D[0]->GetPosition();
	D3DXVECTOR3 posRight = m_apScene2D[1]->GetPosition();

	// ������������
	switch (CGame::GetMatch())
	{
	case CGame::MATCH_LEFT:

		if (m_bFallSide == true)
		{
			posRight.x += 2.0f;
		}
		else
		{
			posRight.x -= 2.0f;
		}

		posRight.y += 1.0f;

		m_apScene2D[1]->SetPosition(posRight);

		break;

	case CGame::MATCH_RIGHT:

		if (m_bFallSide == true)
		{
			posLeft.x += 2.0f;
		}
		else
		{
			posLeft.x -= 2.0f;
		}

		posLeft.y += 1.0f;

		m_apScene2D[0]->SetPosition(posLeft);

		break;
	}

	m_bFallSide = !m_bFallSide;
}