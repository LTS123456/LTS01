
// Ex2.3View.cpp : CEx23View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex2.3.h"
#endif

#include "Ex2.3Doc.h"
#include "Ex2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx23View

IMPLEMENT_DYNCREATE(CEx23View, CView)

BEGIN_MESSAGE_MAP(CEx23View, CView)
END_MESSAGE_MAP()

// CEx23View ����/����

CEx23View::CEx23View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx23View::~CEx23View()
{
}

BOOL CEx23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx23View ����

void CEx23View::OnDraw(CDC* pDC)
{
	CEx23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s = _T("������ͬ��");
	int A = 66;
	CString a;
	a.Format(_T("%d"), A);
	pDC->TextOutW(600, 300, s + a);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx23View ���

#ifdef _DEBUG
void CEx23View::AssertValid() const
{
	CView::AssertValid();
}

void CEx23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx23Doc* CEx23View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx23Doc)));
	return (CEx23Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx23View ��Ϣ�������
