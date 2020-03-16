
// Ex4.1View.cpp : CEx41View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex4.1.h"
#endif

#include "Ex4.1Doc.h"
#include "Ex4.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx41View

IMPLEMENT_DYNCREATE(CEx41View, CView)

BEGIN_MESSAGE_MAP(CEx41View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CEx41View ����/����

CEx41View::CEx41View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx41View::~CEx41View()
{
}

BOOL CEx41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx41View ����

void CEx41View::OnDraw(CDC* pDC)
{
	CEx41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->mRect);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx41View ���

#ifdef _DEBUG
void CEx41View::AssertValid() const
{
	CView::AssertValid();
}

void CEx41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx41Doc* CEx41View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx41Doc)));
	return (CEx41Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx41View ��Ϣ�������


void CEx41View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s;
	s.Format(_T("����λ���ǣ�X=%d,Y=%d"), point.x, point.y);
	dc.TextOutW(500, 500, s);
	CView::OnMouseMove(nFlags, point);
}


void CEx41View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEx41Doc* pDoc = GetDocument();
	pDoc->mRect.left = point.x;
	pDoc->mRect.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CEx41View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEx41Doc* pDoc = GetDocument();
	pDoc->mRect.right = point.x;
	pDoc->mRect.bottom = point.y;
	InvalidateRect(NULL, FALSE);
	CView::OnLButtonUp(nFlags, point);
}
