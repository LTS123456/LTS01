
// Ex1.2View.cpp : CEx12View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex1.2.h"
#endif

#include "Ex1.2Doc.h"
#include "Ex1.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx12View

IMPLEMENT_DYNCREATE(CEx12View, CView)

BEGIN_MESSAGE_MAP(CEx12View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEx12View ����/����

CEx12View::CEx12View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx12View::~CEx12View()
{
}

BOOL CEx12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx12View ����

void CEx12View::OnDraw(CDC* /*pDC*/)
{
	CEx12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx12View ���

#ifdef _DEBUG
void CEx12View::AssertValid() const
{
	CView::AssertValid();
}

void CEx12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx12Doc* CEx12View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx12Doc)));
	return (CEx12Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx12View ��Ϣ�������


void CEx12View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEx12Doc* pDoc = GetDocument();
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}


void CEx12View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEx12Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->count);
	CClientDC dc(this);
	dc.TextOutW(600, 300, s);
	CView::OnRButtonDown(nFlags, point);
}
