
// UselibView.cpp : CUselibView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Uselib.h"
#endif

#include "UselibDoc.h"
#include "UselibView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "win32.h"

// CUselibView

IMPLEMENT_DYNCREATE(CUselibView, CView)

BEGIN_MESSAGE_MAP(CUselibView, CView)
END_MESSAGE_MAP()

// CUselibView ����/����

CUselibView::CUselibView()
{
	// TODO: �ڴ˴���ӹ������

}

CUselibView::~CUselibView()
{
}

BOOL CUselibView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CUselibView ����

void CUselibView::OnDraw(CDC* pDC)
{
	CUselibDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	f1 f;
	s.Format(_T("%d"), f.factorial(5));
	pDC->TextOutW(200, 300, s);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CUselibView ���

#ifdef _DEBUG
void CUselibView::AssertValid() const
{
	CView::AssertValid();
}

void CUselibView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUselibDoc* CUselibView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUselibDoc)));
	return (CUselibDoc*)m_pDocument;
}
#endif //_DEBUG


// CUselibView ��Ϣ�������
