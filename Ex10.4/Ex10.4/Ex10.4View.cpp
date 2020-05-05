
// Ex10.4View.cpp : CEx104View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex10.4.h"
#endif

#include "Ex10.4Set.h"
#include "Ex10.4Doc.h"
#include "Ex10.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx104View

IMPLEMENT_DYNCREATE(CEx104View, CRecordView)

BEGIN_MESSAGE_MAP(CEx104View, CRecordView)
END_MESSAGE_MAP()

// CEx104View ����/����

CEx104View::CEx104View()
	: CRecordView(IDD_EX104_FORM)
	, ID(0)
	, snum(_T(""))
	, sname(_T(""))
	, age(0)
	, telenum(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CEx104View::~CEx104View()
{
}

void CEx104View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
}

BOOL CEx104View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CEx104View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex104Set;
	CRecordView::OnInitialUpdate();

}


// CEx104View ���

#ifdef _DEBUG
void CEx104View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx104View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx104Doc* CEx104View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx104Doc)));
	return (CEx104Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx104View ���ݿ�֧��
CRecordset* CEx104View::OnGetRecordset()
{
	return m_pSet;
}



// CEx104View ��Ϣ�������
