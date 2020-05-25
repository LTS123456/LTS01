
// Ex14.1View.cpp : CEx141View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex14.1.h"
#endif

#include "Ex14.1Set.h"
#include "Ex14.1Doc.h"
#include "Ex14.1View.h"
#include "ShowDialog.h"
#include "SerchDialog.h"
#include "LineDialog.h"
#include "SDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int flag = 1;
int flag1 = 0;

// CEx141View

IMPLEMENT_DYNCREATE(CEx141View, CRecordView)

BEGIN_MESSAGE_MAP(CEx141View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CEx141View::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_FIRST, &CEx141View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CEx141View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CEx141View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CEx141View::OnRecordLast)
	ON_WM_PAINT()
	ON_COMMAND(ID_Serch, &CEx141View::OnSerch)
	ON_BN_CLICKED(IDC_BUTTON2, &CEx141View::OnBnClickedButton2)
	ON_COMMAND(ID_Line, &CEx141View::OnLine)
	ON_COMMAND(ID_Show, &CEx141View::OnShow)
END_MESSAGE_MAP()

// CEx141View ����/����

CEx141View::CEx141View()
	: CRecordView(IDD_EX141_FORM)
	, ID(0)
	, m_num(_T(""))
	, m_name(_T(""))
	, m_age(0)
	, m_tele(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CEx141View::~CEx141View()
{
}

void CEx141View::DoDataExchange(CDataExchange* pDX)
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

BOOL CEx141View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CEx141View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex141Set;
	CRecordView::OnInitialUpdate();

}


// CEx141View ���

#ifdef _DEBUG
void CEx141View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx141View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx141Doc* CEx141View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx141Doc)));
	return (CEx141Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx141View ���ݿ�֧��
CRecordset* CEx141View::OnGetRecordset()
{
	return m_pSet;
}



// CEx141View ��Ϣ�������

void CEx141View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
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

void CEx141View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	path = m_pSet->column5;
	ShowDialog *dia = new ShowDialog;
	dia->Create(IDD_DIALOG1);
	dia->ShowWindow(1);
}


void CEx141View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx141View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx141View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx141View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx141View::OnPaint()
{
	CPaintDC dc(this); 
	if (flag)
	{
		CImage img;
		img.Load(m_pSet->column5);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
		flag = 0;
	}
}


void CEx141View::OnSerch()
{
	// TODO: �ڴ���������������
	SerchDialog dia;
	int r = dia.DoModal();
	CString s;
	if (r == IDOK)
		s = dia.m_Search;
	m_pSet->m_strFilter = s;
	m_pSet->Requery();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
	flag1 = 1;
}


void CEx141View::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (flag1 == 1)
	{
		m_pSet->m_strFilter = _T("");
		m_pSet->Requery();
		UpdateData(false);
		GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
		CImage img;
		img.Load(m_pSet->column5);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
		flag1 = 0;
	}
	if (flag1 == 2)
	{
		m_pSet->m_strSort = _T("");
		m_pSet->Requery();
		UpdateData(false);
		GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
		CImage img;
		img.Load(m_pSet->column5);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
		flag1 = 0;
	}
}


void CEx141View::OnLine()
{
	// TODO: �ڴ���������������
	LineDialog dia;
	int r = dia.DoModal();
	CString s;
	if (r == IDOK)
		s = dia.m_Line;
	m_pSet->m_strSort = s;
	m_pSet->Requery();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
	flag1 = 2;
}


void CEx141View::OnShow()
{
	// TODO: �ڴ���������������
	SDialog *dia = new SDialog;
	dia->m_pSet = m_pSet;
	dia->Create(IDD_DIALOG4);
	dia->ShowWindow(1);
}
