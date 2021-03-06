//==============================================================================
//
// タイマーカウント描画処理〔timer_count.cpp〕
// Author : Mare Horiai
//
//==============================================================================
#include "main.h"
#include "scene2D.h"
#include "renderer.h"
#include "manager.h"
#include "number.h"
#include "texture.h"
#include "timer_count.h"
#include "game.h"
#include "ui.h"
#include "timeralert_logo.h"

// 静的メンバ変数宣言
int CTimerCount::m_nTimerResult = 0;	// リザルトへ引き継ぐ値

//==============================================================================
// コンストラクタ
//==============================================================================
CTimerCount::CTimerCount()
{
	for (int nCnt = 0; nCnt < TIMER_DIGIT_NUM; nCnt++)
	{
		// 各ナンバーNULL化
		m_apNumber[nCnt] = NULL;
	}
}

//==============================================================================
// デストラクタ
//==============================================================================
CTimerCount::~CTimerCount()
{

}

//==============================================================================
// タイマーカウントの初期化処理
//==============================================================================
HRESULT CTimerCount::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	// タイマー設定
	m_nTimer = 31;

	// 数字の表示処理初期化
	for (int nCntDigit = 0; nCntDigit < TIMER_DIGIT_NUM; nCntDigit++)
	{
		m_apNumber[nCntDigit] = CNumber::Create(
			D3DXVECTOR3(pos.x + (nCntDigit * (size.x * 2)), pos.y, 0.0f), size);

		m_apNumber[nCntDigit]->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}

	return S_OK;
}

//==============================================================================
// タイマーカウントの終了処理
//==============================================================================
void CTimerCount::Uninit(void)
{
	for (int nCntDigit = 0; nCntDigit < TIMER_DIGIT_NUM; nCntDigit++)
	{
		if (m_apNumber[nCntDigit] != NULL)
		{// NULLチェック後に破棄
			m_apNumber[nCntDigit]->Uninit();
			m_apNumber[nCntDigit] = NULL;
		}
	}

	m_nTimerResult = m_nTimer;
}

//==============================================================================
// タイマーカウントの更新処理
//==============================================================================
void CTimerCount::Update(void)
{
	if (m_bStartCnt == true && CGame::GetGameEnd() == false)
	{
		// タイマー減少
		TimerDecrease();
	}

	// タイマーの設定
	SetNumber(m_nTimer);

	// 数字の更新
	for (int nCnt = 0; nCnt < TIMER_DIGIT_NUM; nCnt++)
	{
		m_apNumber[nCnt]->Update();
	}
}

//==============================================================================
// タイマーカウントの描画処理
//==============================================================================
void CTimerCount::Draw(void)
{
	for (int nCntDigit = 0; nCntDigit < TIMER_DIGIT_NUM; nCntDigit++)
	{
		if (m_apNumber[nCntDigit] != NULL)
		{// NULLチェック後に描画
			m_apNumber[nCntDigit]->Draw();
		}
	}
}

//==============================================================================
// タイマーカウントの生成処理
//==============================================================================
CTimerCount *CTimerCount::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	// インスタンス生成
	CTimerCount *pTimerCount;
	pTimerCount = new CTimerCount;

	// 初期化
	if (pTimerCount != NULL)
	{
		pTimerCount->Init(pos, size);
	}

	return pTimerCount;
}

//==============================================================================
// タイマーの減少
//==============================================================================
void CTimerCount::TimerDecrease(void)
{
	// 減少カウント
	m_nDecereaseCnt++;

	if (m_nDecereaseCnt % 60 == 0 && m_nTimer > 0)
	{
		m_nTimer--;
	}

	CUi *pUi = CGame::GetUi();

	// 残り時間3割
	if (m_nTimer == 100 * 30 / 100)
	{
		m_pSound->Play(CSound::SOUND_LABEL_SE_TIMEWARNING);
		
		pUi->GetAlertLogo()->MoveTypeNext();

		for (int nCnt = 0; nCnt < TIMER_DIGIT_NUM; nCnt++)
		{
			m_apNumber[nCnt]->SetCol(D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
		}
	}

	if (m_nTimer == (100 * 30 / 100 - 3))
	{
		for (int nCnt = 0; nCnt < TIMER_DIGIT_NUM; nCnt++)
		{
			m_apNumber[nCnt]->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		}
	}
}

//==============================================================================
// タイマー数値設定
//==============================================================================
void CTimerCount::SetNumber(int nTimer)
{
	// スコアの設定
	m_nTimer = nTimer;

	int nData = (int)pow(10, (TIMER_DIGIT_NUM - 1));

	for (int nCnt = 0; nCnt < TIMER_DIGIT_NUM; nCnt++)
	{
		// 各桁の算出
		int nNumber;
		nNumber = (m_nTimer / nData) % 10;
		nData /= 10;

		// 桁の設定
		m_apNumber[nCnt]->SetNumber(nNumber);
	}
}