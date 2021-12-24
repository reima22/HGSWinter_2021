
//=============================================================================
//
// ゲームモード処理 [game.h]
// Author : Mare Horiai
//
//============================================================================= 
#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"
#include "scene.h"
#include "mode.h"

// 前方宣言
class CPause;			// ポーズクラス
class CTimer;			// タイマークラス
class CFall;			// 落下数クラス
class CSound;			// サウンドクラス
class CStartCntdown;	// 開始時カウントダウンクラス
class CBonus;			// ボーナスクラス
class CCheckpointLogo;	// チェックポイントロゴクラス
class CGamesetLogo;		// ゲーム結果ロゴ
class CUi;				// UIクラス
class CBg;				// 背景クラス

//==============================================================================
// ゲームモードクラス
//==============================================================================
class CGame : public CMode
{
public:
	// フェイズ分割
	typedef enum
	{
		CLEARPHASE_NONE = 0,	// クリア判定なし
		CLEARPHASE_WAIT,		// 待機
		CLEARPHASE_PAUSE,		// クリアポーズ演出
		CLEARPHASE_FADE,		// フェードアウト
		CLEARPHASE_MAX
	}CLEARPHASE;

	typedef enum
	{
		GAMEOVERPHASE_NONE = 0,		// 判定無し
		GAMEOVERPHASE_WAIT,			// 待機
		GAMEOVERPHASE_DIRECTION,	// 演出
		GAMEOVERPHASE_FADE,			// フェードアウト
		GAMEOVERPHASE_MAX
	}GAMEOVERPHASE;

	CGame(int nPriority = PRIORITY_DEFAULT);
	~CGame();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CGame *Create(void);

	void SetStageObject(void);

	void EndGame(void);
	//void GameClear(void);
	void GameOver(void);

	static CUi *GetUi(void) { return m_pUi; }									// UIの取得

	// ゲーム終了フラグの取得・設定
	static bool GetGameEnd(void) { return m_bGameEnd; }
	static void SetGameEnd(bool bGameEnd) { m_bGameEnd = bGameEnd; }

	// ゲームクリアのフェイズの取得・設定
	static CLEARPHASE GetClearPhase(void) { return m_clearPhase; }
	static void SetClearPhase(CLEARPHASE clearPhase) { m_clearPhase = clearPhase; }

	// ゲームオーバーフェイズの取得・設定
	static GAMEOVERPHASE GetOverPhase(void) { return m_gameoverPhase; }
	static void SetOverPhase(GAMEOVERPHASE overPhase) { m_gameoverPhase = overPhase; }

private:
	int m_nNumObject;						// オブジェクト数
	int m_nNumMeshfield;					// メッシュフィールドの数
	static CPause *m_pPause;				// ポーズのポインタ

	static bool m_bGameEnd;					// ゲーム終了のフラグ
	static int m_nClearDirectingCnt;		// クリア演出カウント

	static CLEARPHASE m_clearPhase;			// クリア時のフェイズ分割
	static GAMEOVERPHASE m_gameoverPhase;	// ゲームオーバー時のフェーズ分割

	static CGamesetLogo *m_pGamesetLogo;

	static CBg *m_pBg;						// 背景ポインタ
	static CUi *m_pUi;						// UIのポインタ
};

#endif