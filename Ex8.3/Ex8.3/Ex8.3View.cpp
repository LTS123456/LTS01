
// Ex8.3View.cpp : CEx83View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex8.3.h"
#endif

#include "Ex8.3Doc.h"
#include "Ex8.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CRect cr;
int flag = 0;
// CEx83View

IMPLEMENT_DYNCREATE(CEx83View, CView)

BEGIN_MESSAGE_MAP(CEx83View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CEx83View ����/����

CEx83View::CEx83View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx83View::~CEx83View()
{
}

BOOL CEx83View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx83View ����

void CEx83View::OnDraw(CDC* pDC)
{
	CEx83Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag)
		pDC->Ellipse(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx83View ���

#ifdef _DEBUG
void CEx83View::AssertValid() const
{
	CView::AssertValid();
}

void CEx83View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx83Doc* CEx83View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx83Doc)));
	return (CEx83Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx83View ��Ϣ�������


void CEx83View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	cr.right = point.x;
	cr.bottom = point.y;
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CEx83View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 1;
	cr.left = point.x;
	cr.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CEx83View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 0;
	CView::OnLButtonUp(nFlags, point);
}
