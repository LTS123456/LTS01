
// Ex1.1View.cpp : CEx11View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex1.1.h"
#endif

#include "Ex1.1Doc.h"
#include "Ex1.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx11View

IMPLEMENT_DYNCREATE(CEx11View, CView)

BEGIN_MESSAGE_MAP(CEx11View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx11View ����/����

CEx11View::CEx11View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx11View::~CEx11View()
{
}

BOOL CEx11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx11View ����

void CEx11View::OnDraw(CDC* /*pDC*/)
{
	CEx11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx11View ���

#ifdef _DEBUG
void CEx11View::AssertValid() const
{
	CView::AssertValid();
}

void CEx11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx11Doc* CEx11View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx11Doc)));
	return (CEx11Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx11View ��Ϣ�������


void CEx11View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEx11Doc* pDoc = GetDocument();
	CClientDC dc(this);
	dc.TextOutW(600, 300, pDoc->name);
	CView::OnLButtonDown(nFlags, point);
}
