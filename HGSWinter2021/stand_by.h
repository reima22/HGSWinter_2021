//=============================================================================
//
// �X�^���o�C��ʕ`�揈�� [stand_by.h]
// Author : Mare Horiai
//
//============================================================================= 
#ifndef _STAND_BY_H_
#define _STAND_BY_H_

#include "main.h"
#include "scene.h"

// �}�N����`
#define STAND_BY_SIZE			(D3DXVECTOR2(1000.0f, 800.0f))			// ��ʂ̃T�C�Y
#define STAND_BY_SIGN_SIZE		(D3DXVECTOR2(400.0f, 100.0f))			// �T�C���T�C�Y
#define STAND_BY_SIGN_POS		(D3DXVECTOR3(1000.0f, 600.0f,0.0f))

//==============================================================================
// �X�^���o�C��ʃN���X
//==============================================================================
class CStandBy : public CScene
{
public:
	CStandBy(int nPriority = PRIORITY_UI);
	~CStandBy();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CStandBy *Create(void);

	// ����
	void DeleteWindow(void);

private:
	CScene2D *m_pBase;			// �匳�|�C���^
	CScene2D *m_pControlSign;	// ����T�C���p�摜

	D3DXVECTOR2 m_size;			// �L�����̃T�C�Y
};

#endif