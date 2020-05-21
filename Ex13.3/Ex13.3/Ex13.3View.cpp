
// Ex13.3View.cpp : CEx133View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex13.3.h"
#endif

#include "Ex13.3Set.h"
#include "Ex13.3Doc.h"
#include "Ex13.3View.h"
#include "ADD_DIALOG.h"
#include "DEL_DIALOG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx133View

IMPLEMENT_DYNCREATE(CEx133View, CRecordView)

BEGIN_MESSAGE_MAP(CEx133View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON3, &CEx133View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CEx133View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CEx133View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CEx133View ����/����

CEx133View::CEx133View()
	: CRecordView(IDD_EX133_FORM)
	, m_1(0)
	, m_2(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CEx133View::~CEx133View()
{
}

void CEx133View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
}

BOOL CEx133View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CEx133View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex133Set;
	CRecordView::OnInitialUpdate();

}


// CEx133View ���

#ifdef _DEBUG
void CEx133View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx133View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx133Doc* CEx133View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx133Doc)));
	return (CEx133Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx133View ���ݿ�֧��
CRecordset* CEx133View::OnGetRecordset()
{
	return m_pSet;
}



// CEx133View ��Ϣ�������


void CEx133View::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(FALSE);
}


void CEx133View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ADD_DIALOG dia;
	int r = dia.DoModal();
	if (r == IDOK)
	{
		long add = dia.m_add;
		m_pSet->AddNew();
		m_pSet->m_1 = add;
		m_pSet->Update();
		UpdateData(FALSE);
	}
}


void CEx133View::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	change = m_pSet->m_1;
	DEL_DIALOG dia;
	int r = dia.DoModal();
	if (r == IDOK)
	{
		long del = dia.m_del;
		m_pSet->Edit();
		m_pSet->m_1 = del;
		m_pSet->Update();
		UpdateData(FALSE);
	}
}
