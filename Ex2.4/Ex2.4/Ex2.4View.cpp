
// Ex2.4View.cpp : CEx24View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex2.4.h"
#endif

#include "Ex2.4Doc.h"
#include "Ex2.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx24View

IMPLEMENT_DYNCREATE(CEx24View, CView)

BEGIN_MESSAGE_MAP(CEx24View, CView)
END_MESSAGE_MAP()

// CEx24View ����/����

CEx24View::CEx24View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx24View::~CEx24View()
{
}

BOOL CEx24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx24View ����

void CEx24View::OnDraw(CDC* pDC)
{
	CEx24Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString a;
	a.Format(_T("%d"), pDoc->A);
	pDC->TextOutW(600, 300, pDoc->s + a);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx24View ���

#ifdef _DEBUG
void CEx24View::AssertValid() const
{
	CView::AssertValid();
}

void CEx24View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx24Doc* CEx24View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx24Doc)));
	return (CEx24Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx24View ��Ϣ�������
