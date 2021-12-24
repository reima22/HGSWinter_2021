//==============================================================================
//
// �e�L�X�g�f�[�^�Ǘ��ktextdata.cpp�l
// Author : Mare Horiai
//
//==============================================================================
#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
#include "textdata.h"
#include "textdata_system.h"
#include "textdata_texture.h"
#include "textdata_pause.h"
#include "textdata_ranking.h"
#include "textdata_rankingselect.h"
#include "stdio.h"

// �ÓI�����o�ϐ��錾
char *CTextData::m_pFileName[TEXTDATA_MAX] =
{
	{ "data/TEXT/systemdata.txt" },			// ���[���Ǘ�
	{ "data/TEXT/texturedata.txt" },		// �e�N�X�`���f�[�^
	{ "data/TEXT/pausedata.txt" },			// �|�[�Y�|���S�����
	{ "data/TEXT/ranking.txt" },			// �����L���O
	{ "data/TEXT/ranking_selectdata.txt" },	// �����L���O�I���f�[�^���
};

CTextDataTexture *CTextData::m_pDataTexture = NULL;					// �e�N�X�`���f�[�^�̃|�C���^
CTextDataPause *CTextData::m_pDataPause = NULL;						// �|�[�Y�f�[�^�̃|�C���^
CTextDataRankingSelect *CTextData::m_pDataRankingSelect = NULL;		// �����L���O�I���f�[�^�̃|�C���^

//==============================================================================
// �R���X�g���N�^
//==============================================================================
CTextData::CTextData()
{

}

//==============================================================================
// �f�X�g���N�^
//==============================================================================
CTextData::~CTextData()
{

}

//==============================================================================
// ��������
//==============================================================================
CTextData *CTextData::Create(void)
{
	// ���[�J���ϐ��錾
	CTextData *pTextData;
	pTextData = new CTextData;	// �C���X�^���X����

								// �e�L�X�g�f�[�^
	if (pTextData != NULL)
	{
		// �e�L�X�g�f�[�^�̓ǂݍ���
		pTextData->LoadTextAll();
	}

	return pTextData;
}

//==============================================================================
// �e�L�X�g�f�[�^�̑S�ǂݍ���
//==============================================================================
void CTextData::LoadTextAll(void)
{
	// �e�N�X�`���f�[�^�̐���
	m_pDataTexture = CTextDataTexture::Create();

	// �|�[�Y�f�[�^�̐���
	m_pDataPause = CTextDataPause::Create();

	// �����L���O�I���f�[�^�̐���
	m_pDataRankingSelect = CTextDataRankingSelect::Create();

	// ���[���̃f�[�^�ǂݍ���
	CTextDataSystem::LoadData();
}

//==============================================================================
// �e�L�X�g�f�[�^�̑S�ǂݍ���
//==============================================================================
void CTextData::UninitAll(void)
{
	// �e�N�X�`���f�[�^�̔j��
	if (m_pDataTexture != NULL)
	{
		m_pDataTexture->Unload();
		m_pDataTexture = NULL;
	}

	// �|�[�Y�f�[�^�̔j��
	if (m_pDataPause != NULL)
	{
		m_pDataPause->Unload();
		m_pDataPause = NULL;
	}

	// �����L���O�I���f�[�^�̔j��
	if (m_pDataRankingSelect != NULL)
	{
		m_pDataRankingSelect->Unload();
		m_pDataRankingSelect = NULL;
	}
}