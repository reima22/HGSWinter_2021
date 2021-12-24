//=============================================================================
//
// �T�C��(�w��)�`�揈�� [sign.h]
// Author : Mare Horiai
//
//============================================================================= 
#ifndef _SIGN_H_
#define _SIGN_H_

#include "main.h"
#include "scene.h"

// �}�N����`
#define SIGNCNT_MAX	(180)

//==============================================================================
// �^�C�}�[�N���X
//==============================================================================
class CSign : public CScene
{
public:
	typedef enum
	{
		SIGNPHASE_NONE = 0,	// �J�n�O
		SIGNPHASE_WAIT,		// ���͑ҋ@
		SIGNPHASE_ACTIVE,	// ���͊J�n
		SIGNPHASE_INTERVAL,	// ���͊Ԋu
		SIGNPHASE_DUMMY,	// �U���̓���
		SIGNPHASE_MAX
	}SIGNPHASE;

	typedef enum
	{
		IMAGETYPE_NONE = 0,	// �ҋ@���
		IMAGETYPE_TRUE,		// �������摜
		IMAGETYPE_DAMMY_A,	// �U�摜0
		IMAGETYPE_DAMMY_B,	// �U�摜1
		IMAGETYPE_DAMMY_C,	// �U�摜2
		IMAGETYPE_DAMMY_D,	// �U�摜3
		IMAGETYPE_DAMMY_E,	// �U�摜4
		IMAGETYPE_DAMMY_F,	// �U�摜5
		IMAGETYPE_DAMMY_G,	// �U�摜6
		IMAGETYPE_DAMMY_H,	// �U�摜7
		IMAGETYPE_DAMMY_I,	// �U�摜8
		IMAGETYPE_DAMMY_J,	// �U�摜9
		IMAGETYPE_DAMMY_K,	// �U�摜10
		IMAGETYPE_DAMMY_L,	// �U�摜11
		IMAGETYPE_DAMMY_M,	// �U�摜12
		IMAGETYPE_DAMMY_N,	// �U�摜13
		IMAGETYPE_DAMMY_O,	// �U�摜14
		IMAGETYPE_DAMMY_P,	// �U�摜15
		IMAGETYPE_DAMMY_Q,	// �U�摜16
		IMAGETYPE_DAMMY_R,	// �U�摜17
		IMAGETYPE_MAX
	}IMAGETYPE;


	CSign(int nPriority = PRIORITY_UI);
	~CSign();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CSign *Create(void);

	// �T�C�������̊J�n
	void StartSign(void) { m_signPhase = SIGNPHASE_WAIT; }

	void SignBehave(void);	// �T�C���̋���

	SIGNPHASE GetPhase(void) { return m_signPhase; }

private:
	CScene2D *m_pScene2D;		// 2D�|���S���̃|�C���^

	D3DXVECTOR2 m_size;			// �T�C���̃T�C�Y
	D3DXCOLOR m_col;			// �T�C���̐F
	int m_nCntActive;			// ���͎w���܂ł̃J�E���g

	int m_nCntChange;			// �ύX��
	int m_nCntEnd;				// �I������l
	int m_nCntSelect;			// �I��

	SIGNPHASE m_signPhase;		// �T�C���̏��
	IMAGETYPE m_imageType;		// �o���摜�̎��
};

#endif