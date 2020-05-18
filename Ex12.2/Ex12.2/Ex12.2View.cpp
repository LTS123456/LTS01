
// Ex12.1View.cpp : CEx121View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex12.2.h"
#endif

#include "Ex12.2Set.h"
#include "Ex12.2Doc.h"
#include "Ex12.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString filename=_T("C:\\Users\\ling\\Desktop\\ѧ����Ƭ\\0.jpg");
// CEx121View

IMPLEMENT_DYNCREATE(CEx122View, CRecordView)

BEGIN_MESSAGE_MAP(CEx122View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CEx122View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CEx122View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CEx122View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CEx122View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CEx121View ����/����

CEx122View::CEx122View()
	: CRecordView(IDD_EX122_FORM)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CEx122View::~CEx122View()
{
}

void CEx122View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
}

BOOL CEx122View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CEx122View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex122Set;
	CRecordView::OnInitialUpdate();

}


// CEx121View ���

#ifdef _DEBUG
void CEx122View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx122View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx122Doc* CEx122View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx122Doc)));
	return (CEx122Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx121View ���ݿ�֧��
CRecordset* CEx122View::OnGetRecordset()
{
	return m_pSet;
}

void CEx122View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
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


void CEx122View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CString s = _T("C:\\Users\\ling\\Desktop\\ѧ����Ƭ\\");
	filename = s + m_pSet->m_0jpg;
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void CEx122View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CString s = _T("C:\\Users\\ling\\Desktop\\ѧ����Ƭ\\");
	filename = s + m_pSet->m_0jpg;
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void CEx122View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveLast();
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CString s = _T("C:\\Users\\ling\\Desktop\\ѧ����Ƭ\\");
	filename = s + m_pSet->m_0jpg;
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void CEx122View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CString s = _T("C:\\Users\\ling\\Desktop\\ѧ����Ƭ\\");
	filename= s + m_pSet->m_0jpg;
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	InvalidateRect(cr);
}




void CEx122View::OnPaint()
{
	CPaintDC dc(this);   
	CImage img;
	img.Load(filename);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}
