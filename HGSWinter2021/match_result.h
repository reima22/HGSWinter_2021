//=============================================================================
//
// ���s���S��ʕ`�揈�� [match_result.h]
// Author : Mare Horiai
//
//============================================================================= 
#ifndef _MATCH_RESULT_H_
#define _MATCH_RESULT_H_

#include "main.h"
#include "scene.h"

// �}�N����`
#define RESULT_SIZE					(D3DXVECTOR2(200.0f, 100.0f))			// ��ʂ̃T�C�Y
#define RESULT_POS_WIN_LEFT			(D3DXVECTOR3(200.0f, 200.0f,0.0f))
#define RESULT_POS_LOSE_LEFT		(D3DXVECTOR3(200.0f, 400.0f,0.0f))
#define RESULT_POS_WIN_RIGHT		(D3DXVECTOR3(1080.0f, 200.0f,0.0f))
#define RESULT_POS_LOSE_RIGHT		(D3DXVECTOR3(1080.0f, 400.0f,0.0f))

//==============================================================================
// ���s���S�N���X
//==============================================================================
class CMatchResult : public CScene
{
public:
	CMatchResult(int nPriority = PRIORITY_UI);
	~CMatchResult();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CMatchResult *Create(void);

	// ���s���o
	void MatchResult(void);

private:
	CScene2D *m_apScene[2];		// �匳�|�C���^

	D3DXVECTOR2 m_size;			// �L�����̃T�C�Y
};

#endif