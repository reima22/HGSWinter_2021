//==============================================================================
//
// ���l�`�揈���knumber.cpp�l
// Author : Mare Horiai
//
//==============================================================================
#include "main.h"
#include "scene2D.h"
#include "renderer.h"
#include "manager.h"
#include "number.h"
#include "texture.h"
#include "textdata_texture.h"

// �ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CNumber::m_pTexture = NULL;

//==============================================================================
// �R���X�g���N�^
//==============================================================================
CNumber::CNumber()
{
}

//==============================================================================
// �f�X�g���N�^
//==============================================================================
CNumber::~CNumber()
{
}

//==============================================================================
// ���l�`��̏���������
//==============================================================================
HRESULT CNumber::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	// ���[�J���ϐ��錾
	VERTEX_2D *pVtx;

	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �e�N�X�`���|�C���^�̎擾
	CTexture *pTexture;
	pTexture = CManager::GetTexture();

	// �e�N�X�`���ݒ�
	m_pTexture = pTexture->GetAddress("NUMBER");

	// ���_����ݒ�
	// ���_�o�b�t�@�̐���
	if (FAILED(pDevice->CreateVertexBuffer(
		sizeof(VERTEX_2D) * 4,	// �m�ۂ���o�b�t�@�T�C�Y
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,			// ���_�t�H�[�}�b�g
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL)))
	{
		return E_FAIL;
	}

	m_pos = pos;

	// �T�C�Y�ݒ�
	m_size = size;

	m_fLength = sqrtf(m_size.x * m_size.x + m_size.y * m_size.y);
	m_fAngle = atan2f(m_size.x, m_size.y);

	// ���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// ���l�̊e���_���W
	pVtx[0].pos = D3DXVECTOR3(
		m_pos.x + sinf(-m_fAngle) * m_fLength,
		m_pos.y + cosf(-m_fAngle) * m_fLength,
		0.0f);
	pVtx[1].pos = D3DXVECTOR3(
		m_pos.x + sinf(m_fAngle - D3DX_PI) * m_fLength,
		m_pos.y + cosf(m_fAngle - D3DX_PI) * m_fLength,
		0.0f);
	pVtx[2].pos = D3DXVECTOR3(
		m_pos.x + sinf(m_fAngle) * m_fLength,
		m_pos.y + cosf(m_fAngle) * m_fLength,
		0.0f);
	pVtx[3].pos = D3DXVECTOR3(
		m_pos.x + sinf(-m_fAngle + D3DX_PI) * m_fLength,
		m_pos.y + cosf(-m_fAngle + D3DX_PI) * m_fLength,
		0.0f);

	// rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	// �e���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// ���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//==============================================================================
// ���l�`��̏I������
//==============================================================================
void CNumber::Uninit(void)
{
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
}

//==============================================================================
// ���l�`��̍X�V����
//==============================================================================
void CNumber::Update(void)
{
	// ���[�J���ϐ��錾
	VERTEX_2D *pVtx;

	// ���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// ���l�̊e���_���W
	pVtx[0].pos = D3DXVECTOR3(
		m_pos.x + sinf(-m_fAngle) * m_fLength,
		m_pos.y + cosf(-m_fAngle) * m_fLength,
		0.0f);
	pVtx[1].pos = D3DXVECTOR3(
		m_pos.x + sinf(m_fAngle - D3DX_PI) * m_fLength,
		m_pos.y + cosf(m_fAngle - D3DX_PI) * m_fLength,
		0.0f);
	pVtx[2].pos = D3DXVECTOR3(
		m_pos.x + sinf(m_fAngle) * m_fLength,
		m_pos.y + cosf(m_fAngle) * m_fLength,
		0.0f);
	pVtx[3].pos = D3DXVECTOR3(
		m_pos.x + sinf(-m_fAngle + D3DX_PI) * m_fLength,
		m_pos.y + cosf(-m_fAngle + D3DX_PI) * m_fLength,
		0.0f);

	// ���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//==============================================================================
// ���l�`��̕`�揈��
//==============================================================================
void CNumber::Draw(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);

	// ���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(
		0,
		m_pVtxBuff,
		0,
		sizeof(VERTEX_2D));

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	// �e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTexture);

	// �|���S���̕`��
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,	// �v���~�e�B�u�̎��
		0,						// �`����J�n���钸�_�C���f�b�N�X
		2);						// �`�悷��v���~�e�B�u��

	pDevice->SetRenderState(D3DRS_FOGENABLE, TRUE);
}

//==============================================================================
// ���l�ݒ�
//==============================================================================
void CNumber::SetNumber(int nNumber)
{
	// ���[�J���ϐ��錾
	VERTEX_2D *pVtx;

	// ���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// �e�N�X�`�����W�ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f + ((float)nNumber / 10), 1.0f);
	pVtx[1].tex = D3DXVECTOR2(0.0f + ((float)nNumber / 10), 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.1f + ((float)nNumber / 10), 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.1f + ((float)nNumber / 10), 0.0f);

	// ���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//==============================================================================
// ��������
//==============================================================================
CNumber *CNumber::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	// CNumber�̃C���X�^���X����
	CNumber *pNumber;
	pNumber = new CNumber;

	// CNumber�̏�����
	if (pNumber != NULL)
	{
		pNumber->Init(pos, size);
	}

	return pNumber;
}

//==============================================================================
// �z�F�ݒ�
//==============================================================================
void CNumber::SetCol(D3DXCOLOR col)
{
	// ���[�J���ϐ��錾
	VERTEX_2D *pVtx;

	// ���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// �e���_�J���[�̐ݒ�
	pVtx[0].col = col;
	pVtx[1].col = col;
	pVtx[2].col = col;
	pVtx[3].col = col;

	// ���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//==============================================================================
// �|���S���̃T�C�Y�ݒ�
//==============================================================================
void CNumber::SetSize(D3DXVECTOR2 size)
{
	// �T�C�Y
	m_size = size;

	// �Ίp���̐ݒ�
	m_fLength = sqrtf(m_size.x * m_size.x + m_size.y * m_size.y);
	m_fAngle = atan2f(m_size.x, m_size.y);
}