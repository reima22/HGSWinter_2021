
//==============================================================================
//
// ゲームモード処理〔game.cpp〕
// Author : Mare Horiai
//
//==============================================================================
#include "main.h"
#include "scene2D.h"
#include "renderer.h"
#include "manager.h"
#include "game.h"
#include "sound.h"
#include "fade.h"
#include "result.h"
#include "pause.h"

#include "timer_count.h"
#include "camera.h"

#include "effect.h"
#include "gamesetlogo.h"
#include "bg.h"
#include "ui.h"

//==============================================================================
// 静的メンバ変数宣言
//==============================================================================
CPause *CGame::m_pPause = NULL;										// ポーズポインタ
bool CGame::m_bGameEnd = false;										// ゲーム終了のフラグ
int CGame::m_nClearDirectingCnt = 0;								// ゲーム終了演出カウント
CGame::CLEARPHASE CGame::m_clearPhase = CLEARPHASE_NONE;			// クリアフェイズ
CGame::GAMEOVERPHASE CGame::m_gameoverPhase = GAMEOVERPHASE_NONE;	// ゲームオーバーフェイズ
CGamesetLogo *CGame::m_pGamesetLogo = NULL;							// ゲーム終了ロゴ

CUi *CGame::m_pUi = NULL;											// UIクラス
CBg *CGame::m_pBg = NULL;											// 背景クラス

//==============================================================================
// コンストラクタ
//==============================================================================
CGame::CGame(int nPriority) : CMode(nPriority)
{
	m_bGameEnd = false;
	m_nClearDirectingCnt = 0;
	m_clearPhase = CLEARPHASE_NONE;
	m_gameoverPhase = GAMEOVERPHASE_NONE;
}

//==============================================================================
// デストラクタ
//==============================================================================
CGame::~CGame()
{
}

//==============================================================================
// ゲームモードの初期化処理
//==============================================================================
HRESULT CGame::Init(void)
{
	// カメラの位置初期化
	CCamera *pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->SetInit();
	}

	// 背景の生成
	if (m_pBg == NULL)
	{
		m_pBg = CBg::Create();
	}

	// UIの生成
	if (m_pUi == NULL)
	{
		m_pUi = CUi::Create();
	}

	// ポーズの生成
	if (m_pPause == NULL)
	{
		m_pPause = CPause::Create();
	}
	
	return S_OK;
}

//==============================================================================
// ゲームモードの終了処理
//==============================================================================
void CGame::Uninit(void)
{
	// BGMの停止
	if (m_pSound != NULL && CManager::GetBGMPlay(CSound::BGMTYPE_GAME) == true)
	{
		m_pSound->Stop();
	}

	// ポーズの終了
	if (m_pPause != NULL)
	{
		m_pPause->Uninit();
		m_pPause = NULL;
	}

	// UIの終了
	if (m_pUi != NULL)
	{
		m_pUi->Uninit();
		m_pUi = NULL;
	}

	Release();	// インスタンスのデリート
}

//==============================================================================
// ゲームモードの更新処理
//==============================================================================
void CGame::Update(void)
{
	// タイマーによる終了
	if (m_pUi != NULL)
	{
		if (m_pUi->GetTimer()->GetTimerCnt()->GetNumber() <= 0)
		{
			// 時間切れでゲームオーバー
			CResult::SetEndState(CResult::ENDSTATE_GAMEOVER);
			//m_pPlayer->SetGameOver(true);
			m_bGameEnd = true;
		}
	}

	// ゲーム終了
	if (m_bGameEnd == true)
	{
		EndGame();
	}
}

//==============================================================================
// ゲームモードの描画処理
//==============================================================================
void CGame::Draw(void)
{
}

//==============================================================================
// ゲームモードの生成処理
//==============================================================================
CGame *CGame::Create()
{
	// インスタンス生成
	CGame *pGame;
	pGame = new CGame;

	// 初期化
	if (pGame != NULL)
	{
		pGame->Init();
	}

	return pGame;
}

//==============================================================================
// ステージオブジェクト設定
//==============================================================================
void CGame::SetStageObject(void)
{

}

//==============================================================================
// ゲーム終了演出
//==============================================================================
void CGame::EndGame(void)
{
	// クリア演出カウントの加算
	m_nClearDirectingCnt++;

	switch (CResult::GetEndState())
	{
	case CResult::ENDSTATE_CLEAR:		// クリア時

		//GameClear();

		break;

	case CResult::ENDSTATE_GAMEOVER:	// ゲームオーバー時

		GameOver();

		break;
	}
}

//==============================================================================
// ゲームクリア
//==============================================================================
//void CGame::GameClear(void)
//{
//	// フェード情報の取得
//	CFade *pFade;
//	pFade = CManager::GetFade();
//
//	switch (m_clearPhase)
//	{
//	case CLEARPHASE_NONE:
//		SetClearPhase(CGame::CLEARPHASE_WAIT);
//		break;
//
//	case CLEARPHASE_WAIT:
//		
//		if (m_nClearDirectingCnt >= CNT_ONE_SECOND)
//		{
//			m_pSound->Play(CSound::SOUND_LABEL_SE_STAGECLEAR);	// ファンファーレ
//															
//			m_pGamesetLogo = CGamesetLogo::Create();	// ロゴ生成
//			SetClearPhase(CLEARPHASE_PAUSE);
//			m_nClearDirectingCnt = 0;
//		}
//
//		break;
//
//	case CLEARPHASE_PAUSE:
//
//		//m_pPlayer->GetMotionPlayer()->SetMotion(CMotionPlayer::MOTIONTYPE_CLEAR);
//
//
//
//		if (m_nClearDirectingCnt % 6 == 0)
//		{
//			CEffectDetail::Create(CEffectDetail::EFFECTTYPE_GAMECLEAR, VECTOR3_NULL);
//
//		}
//
//		if (m_nClearDirectingCnt >= CNT_ONE_SECOND * 6)
//		{
//			SetClearPhase(CLEARPHASE_FADE);
//		}
//
//		break;
//
//	case CLEARPHASE_FADE:
//
//		CResult::SetEndState(CResult::ENDSTATE_CLEAR);
//		pFade->SetFade(CFade::FADE_OUT, CMode::MODE_RESULT);
//
//		break;
//	}
//}

//==============================================================================
// ゲームオーバー
//==============================================================================
void CGame::GameOver(void)
{
	// フェード情報の取得
	CFade *pFade;
	pFade = CManager::GetFade();

	switch (m_gameoverPhase)
	{
	case GAMEOVERPHASE_NONE:
		m_pSound->Stop();
		m_pSound->Play(CSound::SOUND_LABEL_SE_TIMEOVER);
		SetOverPhase(GAMEOVERPHASE_WAIT);
		break;

	case GAMEOVERPHASE_WAIT:
		if (m_nClearDirectingCnt >= CNT_ONE_SECOND * 2)
		{
			SetOverPhase(GAMEOVERPHASE_DIRECTION);
			m_pSound->Play(CSound::SOUND_LABEL_SE_GAMEOVER);
			m_nClearDirectingCnt = 0;
		}
		break;

	case GAMEOVERPHASE_DIRECTION:

		// ロゴ生成
		m_pGamesetLogo = CGamesetLogo::Create();

		if (m_nClearDirectingCnt >= CNT_ONE_SECOND * 6)
		{
			SetOverPhase(GAMEOVERPHASE_FADE);
		}
		break;

	case GAMEOVERPHASE_FADE:

		CResult::SetEndState(CResult::ENDSTATE_GAMEOVER);
		pFade->SetFade(CFade::FADE_OUT, CMode::MODE_RESULT);

		break;
	}
}