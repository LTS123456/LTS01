
// Ex2.5View.cpp : CEx25View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex2.5.h"
#endif

#include "Ex2.5Doc.h"
#include "Ex2.5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx25View

IMPLEMENT_DYNCREATE(CEx25View, CView)

BEGIN_MESSAGE_MAP(CEx25View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEx25View ����/����

CEx25View::CEx25View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx25View::~CEx25View()
{
}

BOOL CEx25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx25View ����

void CEx25View::OnDraw(CDC* /*pDC*/)
{
	CEx25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx25View ���

#ifdef _DEBUG
void CEx25View::AssertValid() const
{
	CView::AssertValid();
}

void CEx25View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx25Doc* CEx25View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx25Doc)));
	return (CEx25Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx25View ��Ϣ�������


void CEx25View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEx25Doc* pDoc = GetDocument();
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}


void CEx25View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEx25Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->count);
	CClientDC dc(this);
	dc.TextOutW(600, 300, s);
	CView::OnRButtonDown(nFlags, point);
}
