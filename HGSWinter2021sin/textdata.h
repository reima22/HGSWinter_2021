//=============================================================================
//
// �e�L�X�g�f�[�^�Ǘ� [textdata.h]
// Author : Mare Horiai
//
//============================================================================= 
#ifndef _TEXTDATA_H_
#define _TEXTDATA_H_

#include "main.h"

// �}�N����`
#define TEXT_NUM	(128)		// �e�L�X�g�f�[�^�o�C�g��

// �O���錾
class CTextDataObject;			// �I�u�W�F�N�g�f�[�^�N���X
class CTextDataTexture;			// �e�N�X�`���f�[�^�N���X
class CTextDataPause;			// �|�[�Y�f�[�^�N���X
class CTextDataRankingSelect;	// �����L���O�I���f�[�^�N���X
class CTextDataRanking;			// �����L���O�f�[�^

//==============================================================================
// �e�L�X�g�Ǘ��N���X
//==============================================================================
class CTextData
{
public:
	// �e�L�X�g�f�[�^�̎��
	typedef enum
	{
		TEXTDATA_SYSTEM = 0,	// �Q�[�����[���f�[�^
		TEXTDATA_TEXTURE,		// �e�N�X�`���f�[�^
		TEXTDATA_PAUSE,			// �|�[�Y�f�[�^
		TEXTDATA_RANKING,
		TEXTDATA_RANKINGSELECT,	// �����L���O�I���f�[�^
		TEXTDATA_MAX
	}TEXTDATA;

	CTextData();
	~CTextData();

	static CTextData *Create(void);	// ����

	static void LoadTextAll(void);
	static void UninitAll(void);

	// �f�[�^�̎擾

	static CTextDataObject *GetDataObject(void) { return m_pDataObject; }
	static CTextDataTexture *GetDataTexture(void) { return m_pDataTexture; }
	static CTextDataPause *GetDataPause(void) { return m_pDataPause; }

	static CTextDataRanking	*GetDataRanking(void) { return m_pDataRanking; }
	static CTextDataRankingSelect *GetDataSelectRanking(void) { return m_pDataRankingSelect; }

protected:
	static char *m_pFileName[TEXTDATA_MAX];			// �ǂݍ��ރt�@�C�����p�X
	//static char *m_pFileNameObj;					// �ǂݎ��I�u�W�F�N�g�t�@�C�����p�X
	//static char *m_pFileNameRanking;				// �ǂݎ�郉���L���O�t�@�C�����p�X

private:
	static CTextDataObject *m_pDataObject;					// �I�u�W�F�N�g�f�[�^
	static CTextDataTexture *m_pDataTexture;				// �e�N�X�`���f�[�^
	static CTextDataPause *m_pDataPause;					// �|�[�Y�f�[�^
	static CTextDataRanking *m_pDataRanking;				// �����L���O�f�[�^
	static CTextDataRankingSelect *m_pDataRankingSelect;	// �����L���O�I���f�[�^
};

#endif