
// Ex3.4View.cpp : CEx34View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex3.4.h"
#endif

#include "Ex3.4Doc.h"
#include "Ex3.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx34View

IMPLEMENT_DYNCREATE(CEx34View, CView)

BEGIN_MESSAGE_MAP(CEx34View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx34View ����/����

CEx34View::CEx34View()
{
	// TODO: �ڴ˴���ӹ������
}

CEx34View::~CEx34View()
{
}

BOOL CEx34View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx34View ����

void CEx34View::OnDraw(CDC* /*pDC*/)
{
	CEx34Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx34View ���

#ifdef _DEBUG
void CEx34View::AssertValid() const
{
	CView::AssertValid();
}

void CEx34View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx34Doc* CEx34View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx34Doc)));
	return (CEx34Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx34View ��Ϣ�������


void CEx34View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEx34Doc* pDoc = GetDocument();
	int sum = pDoc->A + pDoc->B;
	CString s;
	s.Format(_T("A+B=%d"), sum);
	CClientDC dc(this);
	dc.TextOutW(600, 300, s);
	CView::OnLButtonDown(nFlags, point);
}
