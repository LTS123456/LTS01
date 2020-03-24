
// Ex5.2View.cpp : CEx52View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex5.2.h"
#endif

#include "Ex5.2Doc.h"
#include "Ex5.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int flag;
int x1;
int x2;
int m1;
int m2;

// CEx52View

IMPLEMENT_DYNCREATE(CEx52View, CView)

BEGIN_MESSAGE_MAP(CEx52View, CView)
	ON_COMMAND(ID_SHOWNAME, &CEx52View::OnShowname)
	ON_COMMAND(ID_SHOWBMP, &CEx52View::OnShowbmp)
	ON_COMMAND(ID_DRAWLINE, &CEx52View::OnDrawline)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_DRAWRECTANGLE, &CEx52View::OnDrawrectangle)
	ON_COMMAND(ID_DRAWELLIPSE, &CEx52View::OnDrawellipse)
END_MESSAGE_MAP()

// CEx52View ����/����

void CEx52View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	x1 = point.x;
	m1 = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CEx52View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	x2 = point.x;
	m2 = point.y;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}

CEx52View::CEx52View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx52View::~CEx52View()
{
}

BOOL CEx52View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx52View ����

void CEx52View::OnDraw(CDC* pDC)
{
	CEx52Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag == 0)
	{
		pDC->MoveTo(x1, m1);
		pDC->LineTo(x2, m2);
		x1 = m1 = x2 = m2 = 0;
	}
	if (flag == 1)
	{
		CRect cr(x1, m1, x2, m2);
		pDC->Rectangle(cr);
		x1 = m1 = x2 = m2 = 0;
	}
	if (flag == 2)
	{
		CRect cr(x1, m1, x2, m2);
		pDC->Ellipse(cr);
		x1 = m1 = x2 = m2 = 0;
	}
	if (flag == 3)
	{
		CString s = _T("��ͬ��");
		pDC->TextOutW(650, 250, s);
	}
	if (flag == 4)
	{
		CBitmap m_Bitmap;
		int w;
		int h;
		BITMAP BM;
		m_Bitmap.LoadBitmapW(IDB_BITMAP1);
		m_Bitmap.GetBitmap(&BM);
		w = BM.bmWidth;
		h = BM.bmHeight;
		CDC MemDC;
		MemDC.CreateCompatibleDC(NULL);
		MemDC.SelectObject(m_Bitmap);
		pDC->BitBlt(500, 150, w, h, &MemDC, 0, 0, SRCCOPY);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx52View ���

#ifdef _DEBUG
void CEx52View::AssertValid() const
{
	CView::AssertValid();
}

void CEx52View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx52Doc* CEx52View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx52Doc)));
	return (CEx52Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx52View ��Ϣ�������
void CEx52View::OnDrawline()
{
	// TODO: �ڴ���������������
	flag = 0;
}



void CEx52View::OnDrawrectangle()
{
	// TODO: �ڴ���������������
	flag = 1;
}




void CEx52View::OnDrawellipse()
{
	// TODO: �ڴ���������������
	flag = 2;
}

void CEx52View::OnShowname()
{
	// TODO: �ڴ���������������
	flag = 3;
	Invalidate();
}


void CEx52View::OnShowbmp()
{
	// TODO: �ڴ���������������
	flag = 4;
	Invalidate();
}



