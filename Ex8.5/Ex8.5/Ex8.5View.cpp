
// Ex8.5View.cpp : CEx85View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex8.5.h"
#endif

#include "Ex8.5Doc.h"
#include "Ex8.5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int flag1 = 0;
int flag2 = 0;
CRect cr;
// CEx85View

IMPLEMENT_DYNCREATE(CEx85View, CView)

BEGIN_MESSAGE_MAP(CEx85View, CView)
//	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEx85View ����/����

CEx85View::CEx85View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx85View::~CEx85View()
{
}

BOOL CEx85View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx85View ����

void CEx85View::OnDraw(CDC* pDC)
{
	CEx85Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	if (flag2)
	{
		CPen pen;
		pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
		pDC->SelectObject(&pen);
		pDC->MoveTo(cr.left, cr.top);
		pDC->LineTo(cr.right, cr.top);
		pDC->MoveTo(cr.right, cr.top);
		pDC->LineTo(cr.right, cr.bottom);
		pDC->MoveTo(cr.right, cr.bottom);
		pDC->LineTo(cr.left, cr.bottom);
		pDC->MoveTo(cr.left, cr.bottom);
		pDC->LineTo(cr.left, cr.top);
		flag2 = 0;
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx85View ���

#ifdef _DEBUG
void CEx85View::AssertValid() const
{
	CView::AssertValid();
}

void CEx85View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx85Doc* CEx85View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx85Doc)));
	return (CEx85Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx85View ��Ϣ�������


void CEx85View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (point.x > cr.left &&point.x < cr.right &&point.y > cr.top &&point.y < cr.bottom)
		flag2 = 1;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CEx85View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	cr.left = point.x - 100;
	cr.top = point.y - 70;
	cr.right = point.x + 100;
	cr.bottom = point.y + 70;
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}
