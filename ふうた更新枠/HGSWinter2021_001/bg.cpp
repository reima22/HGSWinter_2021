//==============================================================================
//
// 背景描画処理〔bg.cpp〕
// Author : Mare Horiai
//
//==============================================================================
#include "main.h"
#include "scene2D.h"
#include "renderer.h"
#include "manager.h"
#include "input.h"
#include "gamepad.h"
#include "game.h"
#include "bg.h"
#include "texture.h"
#include "result.h"
#include "mode.h"

// 静的メンバ変数宣言
D3DXVECTOR3 CBg::m_pos = SCREEN_CENTER;

//==============================================================================
// コンストラクタ
//==============================================================================
CBg::CBg(int nPriority) : CScene(nPriority)
{
	m_pScene2D = NULL;
}

//==============================================================================
// デストラクタ
//==============================================================================
CBg::~CBg()
{
}

//==============================================================================
// 背景の初期化処理
//==============================================================================
HRESULT CBg::Init(void)
{
	// モードの取得
	CMode::MODE mode = CManager::GetModePoint()->GetMode();

	if (m_pScene2D == NULL)
	{
		m_pScene2D = CScene2D::Create();
		m_pScene2D->SetPosition(m_pos);
		m_pScene2D->SetSize(D3DXVECTOR2(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f));
		m_pScene2D->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		m_pScene2D->SetTex(1, 1, 0, 0, 0, 0);
		
		switch (mode)
		{
		case CMode::MODE_TITLE:
			
			m_pScene2D->BindTexture("TITLE_BG");

			break;

		case CMode::MODE_GAME:

			m_pScene2D->BindTexture("GAME_BG");

			break;

		case CMode::MODE_RESULT:
			m_pScene2D->BindTexture("RESULT_BG");
			break;

		case CMode::MODE_RANKING:
			//switch (CStageSelect::GetSelectingStage())
			//{
			//case CStageSelect::STAGE_SELECT_1:

			//	m_pScene2D->BindTexture("RANKING_VALLEY");

			//	break;

			//case CStageSelect::STAGE_SELECT_2:

			//	m_pScene2D->BindTexture("RANKING_SEA");

			//	break;

			//case CStageSelect::STAGE_SELECT_3:

			//	m_pScene2D->BindTexture("RANKING_LAVA");

			//	break;
			//}
			break;
		}
	}

	return S_OK;
}

//==============================================================================
// 背景の終了処理
//==============================================================================
void CBg::Uninit(void)
{
	if (m_pScene2D != NULL)
	{// NULLチェック後に破棄
		m_pScene2D->Uninit();
		m_pScene2D = NULL;
	}

	Release();	// CBgインスタンスのデリート
}

//==============================================================================
// 背景の更新処理
//==============================================================================
void CBg::Update(void)
{
	// モードの取得
	CMode::MODE mode = CManager::GetModePoint()->GetMode();
}

//==============================================================================
// 背景の描画処理
//==============================================================================
void CBg::Draw(void)
{
	/*CSceneにて実行*/
}

//==============================================================================
// 背景の生成処理
//==============================================================================
CBg *CBg::Create(void)
{
	// CBgのインスタンス生成
	CBg *pBg;
	pBg = new CBg;

	// CBgの初期化
	if (pBg != NULL)
	{
		pBg->Init();
	}

	return pBg;
}