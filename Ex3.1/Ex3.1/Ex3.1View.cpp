
// Ex3.1View.cpp : CEx31View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex3.1.h"
#endif

#include "Ex3.1Doc.h"
#include "Ex3.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CRect cr;

// CEx31View

IMPLEMENT_DYNCREATE(CEx31View, CView)

BEGIN_MESSAGE_MAP(CEx31View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx31View ����/����

CEx31View::CEx31View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx31View::~CEx31View()
{
}

BOOL CEx31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx31View ����

void CEx31View::OnDraw(CDC* pDC)
{
	CEx31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect clientRect;
	GetClientRect(&clientRect);
	cr = CRect(clientRect.top, clientRect.top, clientRect.bottom, clientRect.bottom);
	pDC->Ellipse(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx31View ���

#ifdef _DEBUG
void CEx31View::AssertValid() const
{
	CView::AssertValid();
}

void CEx31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx31Doc* CEx31View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx31Doc)));
	return (CEx31Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx31View ��Ϣ�������


void CEx31View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
