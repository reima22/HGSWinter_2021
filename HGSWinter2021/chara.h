//=============================================================================
//
// �L�����N�^�[�`�揈�� [chara.h]
// Author : Mare Horiai
//
//============================================================================= 
#ifndef _CHARA_H_
#define _CHARA_H_

#include "main.h"
#include "scene.h"

// �}�N����`
#define CHARA_SIZE			(D3DXVECTOR2(150.0f,300.0f))			// �L�����N�^�[�̃T�C�Y
#define CHARA_POS_LEFT		(D3DXVECTOR3(300.0f, 520.0f, 0.0f))		// �L�����N�^�[���̈ʒu
#define CHARA_POS_RIGHT		(D3DXVECTOR3(980.0f, 520.0f, 0.0f))		// �L�����N�^�[�E�̈ʒu

//==============================================================================
// �L�����N�^�[�N���X
//==============================================================================
class CChara : public CScene
{
public:
	typedef enum
	{
		CHARAPHASE_NONE = 0,	// �J�n�O
		CHARAPHASE_WAIT,		// ���͑ҋ@
		CHARAPHASE_ACTIVE,		// ���͊J�n
		CHARAPHASE_INTERVAL,	// ���͊Ԋu
		CHARAPHASE_DUMMY,		// �U���̓���
		CHARAPHASE_MAX
	}CHARAPHASE;

	CChara(int nPriority = PRIORITY_UI);
	~CChara();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CChara *Create(void);

	void CharaMove(void);	// �L�������o

	void GameEnd(void);		// �I�����̉��o

private:
	CScene2D *m_apScene2D[2];	// 2D�|���S���̃|�C���^

	D3DXVECTOR2 m_size;			// �L�����̃T�C�Y

	int m_nCntActive;			// ���͎w���܂ł̃J�E���g

	bool m_bFallSide;			// �~�����E	
};

#endif