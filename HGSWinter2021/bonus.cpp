//==============================================================================
//
// �{�[�i�XUI�����kbonus.cpp�l
// Author : Mare Horiai
//
//==============================================================================
#include "main.h"
#include "scene2D.h"
#include "renderer.h"
#include "manager.h"
//#include "fall.h"
//#include "fall_count.h"
//#include "fall_logo.h"
#include "bonus.h"
#include "bonus_count.h"
#include "bonus_logo.h"
#include "ui_base.h"

//==============================================================================
// �R���X�g���N�^
//==============================================================================
CBonus::CBonus(int nPriority) : CScene(nPriority)
{
}

//==============================================================================
// �f�X�g���N�^
//==============================================================================
CBonus::~CBonus()
{
}

//==============================================================================
// �{�[�i�X�̏���������
//==============================================================================
HRESULT CBonus::Init(void)
{
	// UI�x�[�X�̐���
	CUiBase::Create(BONUS_UIBASE_POS, BONUS_UIBASE_SIZE, "BLOCK_TEX");

	// �{�[�i�X�J�E���g����
	m_pBonusCount = CBonusCount::Create(BONUS_COUNT_POS, BONUS_COUNT_SIZE);

	// �{�[�i�X���S����
	m_pBonusLogo = CBonusLogo::Create(BONUS_LOGO_POS, BONUS_LOGO_SIZE);

	return S_OK;
}

//==============================================================================
// �{�[�i�X�̏I������
//==============================================================================
void CBonus::Uninit(void)
{
	// �J�E���g�̔j��
	if (m_pBonusCount != NULL)
	{
		m_pBonusCount->Uninit();
		m_pBonusCount = NULL;
	}

	// ���S�̔j��
	if (m_pBonusLogo != NULL)
	{
		m_pBonusLogo->Uninit();
		m_pBonusLogo = NULL;
	}
}

//==============================================================================
// �{�[�i�X�̍X�V����
//==============================================================================
void CBonus::Update(void)
{

}

//==============================================================================
// �{�[�i�X�̕`�揈��
//==============================================================================
void CBonus::Draw(void)
{

}

//==============================================================================
// �{�[�i�X�̐�������
//==============================================================================
CBonus *CBonus::Create(void)
{
	// �C���X�^���X����
	CBonus *pBonus;
	pBonus = new CBonus;

	// ������
	if (pBonus != NULL)
	{
		pBonus->Init();
	}

	return pBonus;
}