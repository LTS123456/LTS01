
// Ex13.1View.cpp : CEx131View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex13.1.h"
#endif

#include "Ex13.1Set.h"
#include "Ex13.1Doc.h"
#include "Ex13.1View.h"
#include "Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx131View

IMPLEMENT_DYNCREATE(CEx131View, CRecordView)

BEGIN_MESSAGE_MAP(CEx131View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON2, &CEx131View::OnBnClickedButton2)
	ON_COMMAND(ID_RECORD_FIRST, &CEx131View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CEx131View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CEx131View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CEx131View::OnRecordLast)
END_MESSAGE_MAP()

// CEx131View ����/����

CEx131View::CEx131View()
	: CRecordView(IDD_EX131_FORM)
	, m_edit(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CEx131View::~CEx131View()
{
}

void CEx131View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_0jpg);
}

BOOL CEx131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CEx131View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex131Set;
	CRecordView::OnInitialUpdate();

}


// CEx131View ���

#ifdef _DEBUG
void CEx131View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx131View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx131Doc* CEx131View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx131Doc)));
	return (CEx131Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx131View ���ݿ�֧��
CRecordset* CEx131View::OnGetRecordset()
{
	return m_pSet;
}

// CEx131View ��Ϣ�������
void CEx131View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
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

void CEx131View::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s = _T("C:\\Users\\ling\\Desktop\\ѧ����Ƭ\\");
	path = s + m_pSet->m_0jpg;
	Dialog *dia = new Dialog;
	dia->Create(IDD_DIALOG1);
	dia->ShowWindow(1);
}


void CEx131View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	UpdateData(FALSE);
	CImage img;
	CString s = _T("C:\\Users\\ling\\Desktop\\ѧ����Ƭ\\");
	img.Load(s + m_pSet->m_0jpg);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx131View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	UpdateData(FALSE);
	CImage img;
	CString s = _T("C:\\Users\\ling\\Desktop\\ѧ����Ƭ\\");
	img.Load(s + m_pSet->m_0jpg);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx131View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveLast();
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	UpdateData(FALSE);
	CImage img;
	CString s = _T("C:\\Users\\ling\\Desktop\\ѧ����Ƭ\\");
	img.Load(s + m_pSet->m_0jpg);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx131View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	UpdateData(FALSE);
	CImage img;
	CString s = _T("C:\\Users\\ling\\Desktop\\ѧ����Ƭ\\");
	img.Load(s + m_pSet->m_0jpg);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}
