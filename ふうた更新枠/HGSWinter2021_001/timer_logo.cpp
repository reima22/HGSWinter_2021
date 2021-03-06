//==============================================================================
//
// タイマーロゴ描画処理〔timer_logo.cpp〕
// Author : Mare Horiai
//
//==============================================================================
#include "main.h"
#include "scene2D.h"
#include "renderer.h"
#include "manager.h"
#include "number.h"
#include "texture.h"
//#include "timer_count.h"
#include "timer_logo.h"

//==============================================================================
// コンストラクタ
//==============================================================================
CTimerLogo::CTimerLogo(int nPriority) : CTimer(nPriority)
{

}

//==============================================================================
// デストラクタ
//==============================================================================
CTimerLogo::~CTimerLogo()
{

}

//==============================================================================
// タイマーロゴの初期化処理
//==============================================================================
HRESULT CTimerLogo::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	//CStageSelect::STAGE_SELECT select = CStageSelect::GetSelectingStage();

	// 2Dポリゴンを生成
	m_pScene2D = CScene2D::Create();

	if (m_pScene2D != NULL)
	{
		// 位置設定
		m_pScene2D->SetPosition(pos);

		// サイズ設定
		m_pScene2D->SetSize(size);

		// テクスチャ設定
		m_pScene2D->BindTexture("TIMER_LOGO");

		m_pScene2D->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		
		m_pScene2D->SetTex(1, 1, 0, 0, 0, 0);
	}

	return S_OK;
}

//==============================================================================
// タイマーロゴの終了処理
//==============================================================================
void CTimerLogo::Uninit(void)
{
	if (m_pScene2D != NULL)
	{
		m_pScene2D->Uninit();
		m_pScene2D = NULL;
	}
}

//==============================================================================
// タイマーロゴの更新処理
//==============================================================================
void CTimerLogo::Update(void)
{

}

//==============================================================================
// タイマーロゴの描画処理
//==============================================================================
void CTimerLogo::Draw(void)
{

}

//==============================================================================
// タイマーロゴの生成処理
//==============================================================================
CTimerLogo *CTimerLogo::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	// CNumberのインスタンス生成
	CTimerLogo *pTimerLogo;
	pTimerLogo = new CTimerLogo;

	// CNumberの初期化
	if (pTimerLogo != NULL)
	{
		pTimerLogo->Init(pos, size);
	}

	return pTimerLogo;
}