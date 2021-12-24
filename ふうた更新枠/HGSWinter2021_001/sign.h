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

//==============================================================================
// �^�C�}�[�N���X
//==============================================================================
class CSign : public CScene
{
public:
	typedef enum
	{
		SIGNPHASE_WAIT = 0,	// ���͑ҋ@
		SIGNPHASE_ACTIVE,	// ���͊J�n
		SIGNPHASE_INTERVAL,	// ���͊Ԋu
		SIGNPHASE_DUMMY,	// �U���̓���
		SIGNPHASE_MAX
	}SIGNPHASE;

	CSign(int nPriority = PRIORITY_UI);
	~CSign();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CSign *Create(void);

	void SignEffect(void);	// �T�C���̋���

private:
	CScene2D *m_pScene2D;		// 2D�|���S���̃|�C���^

	D3DXVECTOR2 m_size;			// �T�C���̃T�C�Y
	D3DXCOLOR m_col;			// �T�C���̐F
	int m_nCntActive;			// ���͎w���܂ł̃J�E���g

	SIGNPHASE m_signPhase;		// �T�C���̏��
};

#endif