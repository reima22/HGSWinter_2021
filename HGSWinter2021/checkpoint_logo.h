//=============================================================================
//
// チェックポイントロゴ描画処理 [checkpoint_logo.h]
// Author : Mare Horiai
//
//============================================================================= 
#ifndef _CHECKPOINT_LOGO_H_
#define _CHECKPOINT_LOGO_H_

#include "main.h"
#include "scene2D.h"

// マクロ定義
#define CHECK_SIZE	(D3DXVECTOR2(400.0f, 80.0f))
#define CHECK_POS	(D3DXVECTOR3(SCREEN_WIDTH + CHECK_SIZE.x, 360.0f, 0.0f))

//==============================================================================
// チェックポイントクラス
//==============================================================================
class CCheckpointLogo : public CScene2D
{
public:
	// 移動状態
	typedef enum
	{
		LOGOMOVE_NONE = 0,	// 初期状態
		LOGOMOVE_START,		// 移動開始
		LOGOMOVE_STOP,		// 一時停止
		LOGOMOVE_RESTART,	// 移動再開
		LOGOMOVE_END,		// 終了
	}LOGOMOVE;

	CCheckpointLogo(int nPriority = PRIORITY_UI);
	~CCheckpointLogo();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CCheckpointLogo *Create(void);

	void MoveTypeNext(void) { if(m_logoMove == LOGOMOVE_NONE)m_logoMove = (LOGOMOVE)(m_logoMove + 1); }
	void MoveLogo(void);

private:
	CScene2D *m_pScene2D;	// 2Dポリゴンクラス
	D3DXVECTOR3 m_pos;		// 位置
	LOGOMOVE m_logoMove;	// 移動状態
	int m_nCntStop;			// 停止間カウント
};

#endif