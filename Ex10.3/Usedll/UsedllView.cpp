
// UsedllView.cpp : CUsedllView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Usedll.h"
#endif

#include "UsedllDoc.h"
#include "UsedllView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Ex10.3.h"

// CUsedllView

IMPLEMENT_DYNCREATE(CUsedllView, CView)

BEGIN_MESSAGE_MAP(CUsedllView, CView)
END_MESSAGE_MAP()

// CUsedllView ����/����

CUsedllView::CUsedllView()
{
	// TODO: �ڴ˴���ӹ������

}

CUsedllView::~CUsedllView()
{
}

BOOL CUsedllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CUsedllView ����

void CUsedllView::OnDraw(CDC* pDC)
{
	CUsedllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s1;
	s1.Format(_T("%d"), factorial(5));
	pDC->TextOutW(200, 300, s1);
	CString s2;
	s2.Format(_T("%f"), convert(30.0));
	pDC->TextOutW(200, 350, s2);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CUsedllView ���

#ifdef _DEBUG
void CUsedllView::AssertValid() const
{
	CView::AssertValid();
}

void CUsedllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsedllDoc* CUsedllView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsedllDoc)));
	return (CUsedllDoc*)m_pDocument;
}
#endif //_DEBUG


// CUsedllView ��Ϣ�������
