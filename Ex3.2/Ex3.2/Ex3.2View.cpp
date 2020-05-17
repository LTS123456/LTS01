
// Ex3.2View.cpp : CEx32View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex3.2.h"
#endif

#include "Ex3.2Doc.h"
#include "Ex3.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx32View

IMPLEMENT_DYNCREATE(CEx32View, CView)

BEGIN_MESSAGE_MAP(CEx32View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx32View ����/����

CEx32View::CEx32View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx32View::~CEx32View()
{
}

BOOL CEx32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx32View ����

void CEx32View::OnDraw(CDC* pDC)
{
	CEx32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int i;
	for (i = 0; i < pDoc->count; i++)
	{
		pDC->Ellipse(pDoc->cr[i]);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx32View ���

#ifdef _DEBUG
void CEx32View::AssertValid() const
{
	CView::AssertValid();
}

void CEx32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx32Doc* CEx32View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx32Doc)));
	return (CEx32Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx32View ��Ϣ�������


void CEx32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEx32Doc* pDoc = GetDocument();
	int a = rand() % 150+20;
	int b = rand() % 100 + 20;
	pDoc->cr.Add(CRect(point.x - a, point.y - b, point.x + a, point.y + b));
	pDoc->count++;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
