
// Ex11.2View.cpp : CEx112View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex11.2.h"
#endif

#include "Ex11.2Set.h"
#include "Ex11.2Doc.h"
#include "Ex11.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx112View

IMPLEMENT_DYNCREATE(CEx112View, CRecordView)

BEGIN_MESSAGE_MAP(CEx112View, CRecordView)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CEx112View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CEx112View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CEx112View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CEx112View::OnRecordLast)
END_MESSAGE_MAP()

// CEx112View ����/����

CEx112View::CEx112View()
	: CRecordView(IDD_EX112_FORM)
	, ID(0)
	, m_num(_T(""))
	, m_name(_T(""))
	, m_age(0)
	, m_tele(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CEx112View::~CEx112View()
{
}

void CEx112View::DoDataExchange(CDataExchange* pDX)
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

BOOL CEx112View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CEx112View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex112Set;
	CRecordView::OnInitialUpdate();

}


// CEx112View ���

#ifdef _DEBUG
void CEx112View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx112View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx112Doc* CEx112View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx112Doc)));
	return (CEx112Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx112View ���ݿ�֧��
CRecordset* CEx112View::OnGetRecordset()
{
	return m_pSet;
}

void CEx112View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
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

// CEx112View ��Ϣ�������


void CEx112View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();//�����õ�getdc�����ͷ���
	pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
}



void CEx112View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	CRect cr;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void CEx112View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	CRect cr;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void CEx112View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveLast();
	UpdateData(false);
	CRect cr;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void CEx112View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	CRect cr;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&cr);
	InvalidateRect(cr);
}
