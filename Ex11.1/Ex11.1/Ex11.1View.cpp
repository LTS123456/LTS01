
// Ex11.1View.cpp : CEx111View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex11.1.h"
#endif

#include "Ex11.1Set.h"
#include "Ex11.1Doc.h"
#include "Ex11.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int flag = 0;
CRect cr;

// CEx111View

IMPLEMENT_DYNCREATE(CEx111View, CRecordView)

BEGIN_MESSAGE_MAP(CEx111View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CEx111View::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CEx111View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CEx111View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CEx111View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CEx111View::OnRecordLast)
END_MESSAGE_MAP()

// CEx111View ����/����

CEx111View::CEx111View()
	: CRecordView(IDD_EX111_FORM)
	, ID(0)
	, m_num(_T(""))
	, m_name(_T(""))
	, m_age(0)
	, m_tele(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CEx111View::~CEx111View()
{
}

void CEx111View::DoDataExchange(CDataExchange* pDX)
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

BOOL CEx111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CEx111View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex111Set;
	CRecordView::OnInitialUpdate();

}


// CEx111View ���

#ifdef _DEBUG
void CEx111View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx111View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx111Doc* CEx111View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx111Doc)));
	return (CEx111Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx111View ���ݿ�֧��
CRecordset* CEx111View::OnGetRecordset()
{
	return m_pSet;
}

void CEx111View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio) {
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;

	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;

	}
}

// CEx111View ��Ϣ�������


void CEx111View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();//�����õ�getdc�����ͷ���
	pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx111View::OnPaint()
{
		CPaintDC dc(this); // device context for painting
				// TODO: �ڴ˴������Ϣ����������		   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
}


void CEx111View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
}


void CEx111View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
}


void CEx111View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
}


void CEx111View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
}
