
// Ex3.3View.cpp : CEx33View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex3.3.h"
#endif

#include "Ex3.3Doc.h"
#include "Ex3.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx33View

IMPLEMENT_DYNCREATE(CEx33View, CView)

BEGIN_MESSAGE_MAP(CEx33View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CEx33View ����/����

CEx33View::CEx33View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx33View::~CEx33View()
{
}

BOOL CEx33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx33View ����

void CEx33View::OnDraw(CDC* /*pDC*/)
{
	CEx33Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx33View ���

#ifdef _DEBUG
void CEx33View::AssertValid() const
{
	CView::AssertValid();
}

void CEx33View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx33Doc* CEx33View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx33Doc)));
	return (CEx33Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx33View ��Ϣ�������


void CEx33View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s = _T("�����������");
	CClientDC dc(this);
	dc.TextOutW(600, 300, s);
	CView::OnLButtonDown(nFlags, point);
}


void CEx33View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s = _T("�������̧��");
	CClientDC dc(this);
	dc.TextOutW(600, 300, s);
	CView::OnLButtonUp(nFlags, point);
}
