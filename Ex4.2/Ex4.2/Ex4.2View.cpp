
// Ex4.2View.cpp : CEx42View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex4.2.h"
#endif

#include "Ex4.2Doc.h"
#include "Ex4.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int T = 0;
int x = 0;
int  one = 0;
// CEx42View
void CEx42View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nFlags)
		T++;
	CView::OnMouseMove(nFlags, point);
}


void CEx42View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	x = point.x;
	CView::OnLButtonDown(nFlags, point);
}

void CEx42View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	x = point.x - x;
	one = x / T;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
IMPLEMENT_DYNCREATE(CEx42View, CView)

BEGIN_MESSAGE_MAP(CEx42View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx42View ����/����

CEx42View::CEx42View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx42View::~CEx42View()
{
}

BOOL CEx42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx42View ����

void CEx42View::OnDraw(CDC* pDC)
{
	CEx42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString str;
	str.Format(_T("MouseMove�ƶ���%d�Σ������ƶ�%d�����ط���һ�Ρ�"), T, one);
	pDC->TextOutA(500, 500, str);
	T = 0;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx42View ���

#ifdef _DEBUG
void CEx42View::AssertValid() const
{
	CView::AssertValid();
}

void CEx42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx42Doc* CEx42View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx42Doc)));
	return (CEx42Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx42View ��Ϣ�������


