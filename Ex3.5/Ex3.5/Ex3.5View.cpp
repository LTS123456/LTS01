
// Ex3.5View.cpp : CEx35View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex3.5.h"
#endif

#include "Ex3.5Doc.h"
#include "Ex3.5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEx35View

IMPLEMENT_DYNCREATE(CEx35View, CView)

BEGIN_MESSAGE_MAP(CEx35View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEx35View ����/����

CEx35View::CEx35View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx35View::~CEx35View()
{
}

BOOL CEx35View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx35View ����

void CEx35View::OnDraw(CDC* pDC)
{
	CEx35Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->cr1);
	pDC->Rectangle(pDoc->cr2);
	pDC->Rectangle(pDoc->cr3);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx35View ���

#ifdef _DEBUG
void CEx35View::AssertValid() const
{
	CView::AssertValid();
}

void CEx35View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx35Doc* CEx35View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx35Doc)));
	return (CEx35Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx35View ��Ϣ�������


void CEx35View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEx35Doc* pDoc = GetDocument();
	CClientDC dc(this);
	if (point.x<300||point.x>900 || point.y<250 || point.y>350)
	{
		CString s = _T("�����Ч");
		dc.TextOutW(point.x, point.y, s);
	}
	if (300 < point.x && point.x < 500 && 250 < point.y && point.y < 350)
	{
		pDoc->a = rand() % 100;
		CString s;
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (500 < point.x && point.x < 700 && 250 < point.y && point.y < 350)
	{
		pDoc->b = rand() % 100;
		CString s;
		s.Format(_T("%d"), pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	CView::OnLButtonDown(nFlags, point);
}


void CEx35View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEx35Doc* pDoc = GetDocument();
	CClientDC dc(this);
	if (point.x > 700 && point.x < 900 && point.y > 250 && point.y < 350)
	{
		CString s;
		s.Format(_T("%d"), pDoc->a + pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	CView::OnRButtonDown(nFlags, point);
}
