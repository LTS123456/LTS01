
// Ex2.2View.cpp : CEx22View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex2.2.h"
#endif

#include "Ex2.2Doc.h"
#include "Ex2.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx22View

IMPLEMENT_DYNCREATE(CEx22View, CView)

BEGIN_MESSAGE_MAP(CEx22View, CView)
END_MESSAGE_MAP()

// CEx22View ����/����

CEx22View::CEx22View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx22View::~CEx22View()
{
}

BOOL CEx22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx22View ����

void CEx22View::OnDraw(CDC* pDC)
{
	CEx22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CBrush b(RGB(150,61,0));
	pDC->SelectObject(&b);
	CRect clientRect;
	GetClientRect(&clientRect);
	pDC->Ellipse(clientRect);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx22View ���

#ifdef _DEBUG
void CEx22View::AssertValid() const
{
	CView::AssertValid();
}

void CEx22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx22Doc* CEx22View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx22Doc)));
	return (CEx22Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx22View ��Ϣ�������
