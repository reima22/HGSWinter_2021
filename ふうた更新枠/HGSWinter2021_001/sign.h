//=============================================================================
//
// サイン(指示)描画処理 [sign.h]
// Author : Mare Horiai
//
//============================================================================= 
#ifndef _SIGN_H_
#define _SIGN_H_

#include "main.h"
#include "scene.h"

//==============================================================================
// タイマークラス
//==============================================================================
class CSign : public CScene
{
public:
	typedef enum
	{
		SIGNPHASE_WAIT = 0,	// 入力待機
		SIGNPHASE_ACTIVE,	// 入力開始
		SIGNPHASE_INTERVAL,	// 入力間隔
		SIGNPHASE_DUMMY,	// 偽物の入力
		SIGNPHASE_MAX
	}SIGNPHASE;

	CSign(int nPriority = PRIORITY_UI);
	~CSign();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CSign *Create(void);

	void SignEffect(void);	// サインの挙動

private:
	CScene2D *m_pScene2D;		// 2Dポリゴンのポインタ

	D3DXVECTOR2 m_size;			// サインのサイズ
	D3DXCOLOR m_col;			// サインの色
	int m_nCntActive;			// 入力指示までのカウント

	SIGNPHASE m_signPhase;		// サインの状態
};

#endif