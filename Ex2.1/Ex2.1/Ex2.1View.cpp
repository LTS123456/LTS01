
// Ex2.1View.cpp : CEx21View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex2.1.h"
#endif

#include "Ex2.1Doc.h"
#include "Ex2.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CRect cr;
// CEx21View

IMPLEMENT_DYNCREATE(CEx21View, CView)

BEGIN_MESSAGE_MAP(CEx21View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx21View ����/����

CEx21View::CEx21View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx21View::~CEx21View()
{
}

BOOL CEx21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx21View ����

void CEx21View::OnDraw(CDC* pDC)
{
	CEx21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx21View ���

#ifdef _DEBUG
void CEx21View::AssertValid() const
{
	CView::AssertValid();
}

void CEx21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx21Doc* CEx21View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx21Doc)));
	return (CEx21Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx21View ��Ϣ�������


void CEx21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int r = rand() % 300;
	cr = CRect(point.x - r, point.y - r, point.x + r, point.y + r);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
