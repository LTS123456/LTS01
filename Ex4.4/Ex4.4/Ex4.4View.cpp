
// Ex4.4View.cpp : CEx44View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex4.4.h"
#endif

#include "Ex4.4Doc.h"
#include "Ex4.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx44View

IMPLEMENT_DYNCREATE(CEx44View, CView)

BEGIN_MESSAGE_MAP(CEx44View, CView)
END_MESSAGE_MAP()

// CEx44View ����/����

CEx44View::CEx44View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx44View::~CEx44View()
{
}

BOOL CEx44View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx44View ����

void CEx44View::OnDraw(CDC* /*pDC*/)
{
	CEx44Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx44View ���

#ifdef _DEBUG
void CEx44View::AssertValid() const
{
	CView::AssertValid();
}

void CEx44View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx44Doc* CEx44View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx44Doc)));
	return (CEx44Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx44View ��Ϣ�������
