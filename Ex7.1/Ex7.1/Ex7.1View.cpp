
// Ex7.1View.cpp : CEx71View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex7.1.h"
#endif

#include "Ex7.1Doc.h"
#include "Ex7.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CRect cr(10, 10, 90, 90);
int x = 40;
int flag=2;
// CEx71View

IMPLEMENT_DYNCREATE(CEx71View, CView)

BEGIN_MESSAGE_MAP(CEx71View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
ON_WM_TIMER()
ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CEx71View ����/����

CEx71View::CEx71View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx71View::~CEx71View()
{
}

BOOL CEx71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx71View ����

void CEx71View::OnDraw(CDC* pDC)
{
	CEx71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(cr);
	SetTimer(1, rand() % 250 + 300, NULL);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx71View ���

#ifdef _DEBUG
void CEx71View::AssertValid() const
{
	CView::AssertValid();
}

void CEx71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx71Doc* CEx71View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx71Doc)));
	return (CEx71Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx71View ��Ϣ�������


void CEx71View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag==1)
	{
		cr.left = point.x - x;
		cr.top = point.y - x;
		cr.right = point.x + x;
		cr.bottom = point.y + x;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CEx71View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 1; 
	CView::OnLButtonDown(nFlags, point);
}



void CEx71View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect clientRect;
	GetClientRect(&clientRect);
	if (flag == 0)
	{
			cr.top += 30;
			cr.bottom += 30;
			Invalidate();
	}
	CView::OnTimer(nIDEvent);
}


void CEx71View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 0;
	CView::OnLButtonUp(nFlags, point);
}
