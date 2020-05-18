
// Ex12.1View.cpp : CEx121View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex12.1.h"
#endif

#include "Ex12.1Set.h"
#include "Ex12.1Doc.h"
#include "Ex12.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEx121View

IMPLEMENT_DYNCREATE(CEx121View, CRecordView)

BEGIN_MESSAGE_MAP(CEx121View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CEx121View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CEx121View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CEx121View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CEx121View::OnRecordLast)
//	ON_WM_PAINT()
END_MESSAGE_MAP()

// CEx121View ����/����

CEx121View::CEx121View()
	: CRecordView(IDD_EX121_FORM)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CEx121View::~CEx121View()
{
}

void CEx121View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
}

BOOL CEx121View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CEx121View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex121Set;
	CRecordView::OnInitialUpdate();

}


// CEx121View ���

#ifdef _DEBUG
void CEx121View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx121View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx121Doc* CEx121View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx121Doc)));
	return (CEx121Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx121View ���ݿ�֧��
CRecordset* CEx121View::OnGetRecordset()
{
	return m_pSet;
}

void CEx121View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
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

// CEx121View ��Ϣ�������


void CEx121View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CImage img;
	CString s = _T("C:\\Users\\ling\\Desktop\\ѧ����Ƭ\\");
	img.Load(s+m_pSet->m_0jpg);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx121View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CImage img;
	CString s = _T("C:\\Users\\ling\\Desktop\\ѧ����Ƭ\\");
	img.Load(s + m_pSet->m_0jpg);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx121View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveLast();
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CImage img;
	CString s = _T("C:\\Users\\ling\\Desktop\\ѧ����Ƭ\\");
	img.Load(s + m_pSet->m_0jpg);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx121View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CImage img;
	CString s = _T("C:\\Users\\ling\\Desktop\\ѧ����Ƭ\\");
	img.Load(s + m_pSet->m_0jpg);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


