//==============================================================================
//
// �G���^�[�T�C���`�揈���ktitle_enter.cpp�l
// Author : Mare Horiai
//
//==============================================================================
#include "main.h"
#include "scene2D.h"
#include "renderer.h"
#include "manager.h"
#include "polygon.h"
#include "sound.h"
#include "title.h"
#include "title_logo.h"
#include "title_enter.h"
#include "input.h"
#include "gamepad.h"
#include "fade.h"
#include "tutorial_page.h"

CTutorialPage *CTitleEnter::m_pTutorialPage = NULL;


//==============================================================================
// �R���X�g���N�^
//==============================================================================
CTitleEnter::CTitleEnter(int nPriority) : CScene2D(nPriority)
{
	// �|���S���̏�����
	m_p2DGameUI = NULL;
	m_p2DTutorialUI = NULL;
	m_bTutorial = false;
}

//==============================================================================
// �f�X�g���N�^
//==============================================================================
CTitleEnter::~CTitleEnter()
{
}

//==============================================================================
// �G���^�[�T�C���̏���������
//==============================================================================
HRESULT CTitleEnter::Init(D3DXVECTOR3 pos)
{
	// �����o�[�ϐ�������
	m_pos = pos;
	m_GameUIpos = pos;
	m_GameUIpos.x -= 250.0f;
	m_TutorialUIpos = pos;
	m_TutorialUIpos.x += 250.0f;
	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_SelectID = SELECT_TUTORIAL;
	m_nMoveTime = 0;

	// �Q�[�����[�h�ړ�UI
	if (m_p2DGameUI == NULL)
	{
		m_p2DGameUI = CScene2D::Create();
		m_p2DGameUI->SetPosition(pos);
		m_p2DGameUI->SetSize(T_ENTER_SIZE);
		m_p2DGameUI->SetTex(1, 1, 0, 0, 0.0f, 0.0f);
		m_p2DGameUI->SetCol(m_col);
		m_p2DGameUI->BindTexture("GAME_MODE_MOVE");
	}

	// �`���[�g���A�����[�h�ړ�UI
	if (m_p2DTutorialUI == NULL)
	{
		m_p2DTutorialUI = CScene2D::Create();
		m_p2DTutorialUI->SetPosition(pos);
		m_p2DTutorialUI->SetSize(T_ENTER_SIZE);
		m_p2DTutorialUI->SetTex(1, 1, 0, 0, 0.0f, 0.0f);
		m_p2DTutorialUI->SetCol(m_col);
		m_p2DTutorialUI->BindTexture("TUTORIAL_MODE_MOVE");
	}

	return S_OK;
}

//==============================================================================
// �G���^�[�T�C���̏I������
//==============================================================================
void CTitleEnter::Uninit(void)
{
	if (m_p2DGameUI != NULL)
	{// NULL�`�F�b�N��ɔj��
		m_p2DGameUI->Uninit();
		m_p2DGameUI = NULL;
	}
	if (m_p2DTutorialUI != NULL)
	{// NULL�`�F�b�N��ɔj��
		m_p2DTutorialUI->Uninit();
		m_p2DTutorialUI = NULL;
	}


	Release();	// �C���X�^���X�̃f���[�g
}

//==============================================================================
// �G���^�[�T�C���̍X�V����
//==============================================================================
void CTitleEnter::Update(void)
{
	// �L�[�{�[�h�̎擾
	CInputKeyboard *keyboard = CManager::GetInputKeyboard();

	// �Q�[���p�b�h�̎擾
	CGamepad *gamepad = CManager::GetInputGamepad();

	// �t�F�[�h�̎擾
	CFade *pFade = CManager::GetFade();
	CFade::FADE fade = pFade->GetFade();

	// �^�C�}�[
	m_nTimer++;

	if (m_bTutorial == false)
	{
		// ���[�h�̑I��
		if (keyboard->GetTrigger(CInput::KEYINFO_RIGHT) == true ||
			keyboard->GetTrigger(CInput::KEYINFO_LEFT) == true)
		{
			// BGM�̍Đ�
			if (m_pSound != NULL && CManager::GetBGMPlay(CSound::BGMTYPE_TITLE) == true)
			{
				m_pSound->Play(CSound::SOUND_LABEL_SE_SELECT);
			}
			// ID�̓���
			m_SelectID = m_SelectID ? SELECT_GAME : SELECT_TUTORIAL;
		}
		// ���肪true�̏ꍇ
		if (m_bEnter == true && (keyboard->GetTrigger(CInput::KEYINFO_OK) == true && fade == CFade::FADE_NONE ||
			gamepad->GetTrigger(CInput::KEYINFO_OK) == true) && m_bNextScene == false)
		{
			// �����true�ɕς���
			m_bNextScene = true;

			// SE
			m_pSound->Play(CSound::SOUND_LABEL_SE_TITLEENTER);
		}
		else if (m_bEnter == false)
		{// ���肪false�̏ꍇ

		 // �G���^�[�L�[���������ꍇ
			if (keyboard->GetTrigger(CInput::KEYINFO_OK) == true || gamepad->GetTrigger(CInput::KEYINFO_OK) == true)
			{
				// �����true�ɕς���
				m_bEnter = true;

				// �J�E���g�̒l��0�ɂ���
				m_nTimeColor = 0;
			}
		}

	}
	else
	{
		int nPageCnt = m_pTutorialPage->GetPageCnt();

		if (nPageCnt == 0 && keyboard->GetTrigger(CInput::KEYINFO_OK) == true)
		{
			// �`���[�g���A���y�[�W�̔j��
			if (m_pTutorialPage != NULL)
			{
				m_pTutorialPage->Uninit();
				m_pTutorialPage = NULL;
			}
			m_bTutorial = false;
		}
	}

	// ���肪�ǂ����true�̏ꍇ
	if (m_bEnter == true && m_bNextScene == true)
	{
		// �J�E���g���Z
		m_nTimeColor++;

		// �J�E���g��5�Ŋ����0�ɂȂ�ꍇ
		if (m_nTimeColor % 5 == 0)
		{
			// �F
			m_col.a = 1.0f;
		}
		else
		{
			// �F
			m_col.a = 0.5f;
		}

		// �J�E���g��50�𒴂����ꍇ
		if (m_nTimeColor >= TIME_COLOR)
		{
			switch (m_SelectID)
			{
			case CTitleEnter::SELECT_GAME:
				// �t�F�[�h
				pFade->SetFade(CFade::FADE_OUT, CMode::MODE_GAME);
				break;

			case CTitleEnter::SELECT_TUTORIAL:
				// �`���[�g���A���y�[�W�̐���
				m_pTutorialPage = CTutorialPage::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 200.0f, 0.0f));
				m_bTutorial = true;
				break;

			default:
				break;
			}

			// �����false�ɕς���
			m_bEnter = false;
			// �����false�ɕς���
			m_bNextScene = false;
			// �^�C�}�[��0�ɂ���
			m_nTimer = 0;
		}
		switch (m_SelectID)
		{
		case CTitleEnter::SELECT_GAME:
			m_p2DGameUI->SetCol(m_col);
			break;
		case CTitleEnter::SELECT_TUTORIAL:
			m_p2DTutorialUI->SetCol(m_col);
			break;
		default:
			break;
		}
	}
	else
	{
		// �I�𒆂̐F�ݒ�
		switch (m_SelectID)
		{
		case CTitleEnter::SELECT_GAME:
			m_p2DGameUI->SetCol(m_SelectCol);
			m_p2DTutorialUI->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
			break;

		case CTitleEnter::SELECT_TUTORIAL:
			m_p2DTutorialUI->SetCol(m_SelectCol);
			m_p2DGameUI->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
			break;

		default:
			break;
		}
	}

	// �ʒu�������������ʒu�ɂ��邩���肪false�̏ꍇ
	if (m_pos.y > T_ENTER_SETPOS.y && m_bEnter == false)
	{
		// �ړ��l
		m_move.y = MOVE_START_Y;

		// �F
		m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		m_SelectCol = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	}
	else
	{
		// �ʒu��^����
		m_pos = T_ENTER_SETPOS;
		m_TutorialUIpos.y = m_pos.y;
		m_GameUIpos.y = m_pos.y;

		// �ړ��l
		m_move.y = 0.0f;

		// �����true�ɕς���
		m_bEnter = true;

		//�ҋ@�_�ŃJ�E���g
		m_nCntColor++;

		// �I�𒆂�UI�̍X�V
		SelectModeUI(m_SelectID);
	}

	// �ʒu�̉��Z
	m_pos += m_move;
	m_TutorialUIpos += m_move;
	m_GameUIpos += m_move;

	// �ʒu�ݒ�
	m_p2DGameUI->SetPosition(m_GameUIpos);

	// �ʒu�ݒ�
	m_p2DTutorialUI->SetPosition(m_TutorialUIpos);
}

//==============================================================================
// �G���^�[�T�C���̕`�揈��
//==============================================================================
void CTitleEnter::Draw(void)
{

}

//==============================================================================
// �G���^�[�T�C���̐�������
//==============================================================================
CTitleEnter *CTitleEnter::Create(D3DXVECTOR3 pos)
{
	// �C���X�^���X����
	CTitleEnter *pTitleEnter;
	pTitleEnter = new CTitleEnter;

	// ������
	if (pTitleEnter != NULL)
	{
		pTitleEnter->Init(pos);
	}

	return pTitleEnter;
}

void CTitleEnter::SelectModeUI(SELECT_TYPE ID)
{
	// �ړ��p�̎��ԉ��Z
	m_nMoveTime++;

	// �I�𒆂�ID�݈̂ړ��J�n
	switch (ID)
	{
	case CTitleEnter::SELECT_GAME:
		m_GameUIpos.y += (sinf((D3DX_PI * 2) / 120 * (m_nMoveTime)) * 10);
		m_TutorialUIpos.y = m_pos.y;
		break;

	case CTitleEnter::SELECT_TUTORIAL:
		m_TutorialUIpos.y += (sinf((D3DX_PI * 2) / 120 * (m_nMoveTime)) * 10);
		m_GameUIpos.y = m_pos.y;
		break;

	default:
		break;
	}
}

