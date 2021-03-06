//==============================================================================
//
// ゲーム結果ロゴ処理〔gamesetlogo.cpp〕
// Author : Mare Horiai
//
//==============================================================================
#include "main.h"
#include "scene2D.h"
#include "renderer.h"
#include "manager.h"
#include "number.h"
#include "texture.h"
#include "gamesetlogo.h"
#include "game.h"

//==============================================================================
// コンストラクタ
//==============================================================================
CGamesetLogo::CGamesetLogo(int nPriority) : CScene(nPriority)
{

}

//==============================================================================
// デストラクタ
//==============================================================================
CGamesetLogo::~CGamesetLogo()
{

}

//==============================================================================
// ゲーム結果ロゴの初期化処理
//==============================================================================
HRESULT CGamesetLogo::Init(void)
{
	if (m_pScene2D == NULL)
	{
		// 2Dポリゴンを生成
		m_pScene2D = CScene2D::Create();

		// 位置設定
		m_pScene2D->SetPosition(LOGO_POS);

		// サイズ設定
		m_pScene2D->SetSize(LOGO_SIZE);

		m_pScene2D->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

		m_pScene2D->SetTex(1, 1, 0, 0, 0, 0);

		// テクスチャ設定
		//if (pPlayer->GetGameClear() == true)
		//{
		//	m_pScene2D->BindTexture("G_RESULT_CLEAR");
		//}
		//else
		//{
		//	m_pScene2D->BindTexture("G_RESULT_GAMEOVER");
		//}
	}

	return S_OK;
}

//==============================================================================
// ゲーム結果ロゴの終了処理
//==============================================================================
void CGamesetLogo::Uninit(void)
{
	if (m_pScene2D != NULL)
	{
		m_pScene2D->Uninit();
		m_pScene2D = NULL;
	}
}

//==============================================================================
// ゲーム結果ロゴの更新処理
//==============================================================================
void CGamesetLogo::Update(void)
{

}

//==============================================================================
// ゲーム結果ロゴの描画処理
//==============================================================================
void CGamesetLogo::Draw(void)
{

}

//==============================================================================
// ゲーム結果ロゴの生成処理
//==============================================================================
CGamesetLogo *CGamesetLogo::Create(void)
{
	// インスタンス生成
	CGamesetLogo *pGamesetLogo;
	pGamesetLogo = new CGamesetLogo;

	// CNumberの初期化
	if (pGamesetLogo != NULL)
	{
		pGamesetLogo->Init();
	}

	return pGamesetLogo;
}