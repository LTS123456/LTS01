
// Ex7.2View.cpp : CEx72View ���ʵ��
//

#include "stdafx.h"
#include "MyDialog.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex7.2.h"
#endif

#include "Ex7.2Doc.h"
#include "Ex7.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx72View

IMPLEMENT_DYNCREATE(CEx72View, CView)

BEGIN_MESSAGE_MAP(CEx72View, CView)
	ON_COMMAND(ID_COUNT, &CEx72View::OnCount)
END_MESSAGE_MAP()

// CEx72View ����/����

CEx72View::CEx72View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx72View::~CEx72View()
{
}

BOOL CEx72View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx72View ����

void CEx72View::OnDraw(CDC* /*pDC*/)
{
	CEx72Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx72View ���

#ifdef _DEBUG
void CEx72View::AssertValid() const
{
	CView::AssertValid();
}

void CEx72View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx72Doc* CEx72View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx72Doc)));
	return (CEx72Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx72View ��Ϣ�������


void CEx72View::OnCount()
{
	// TODO: �ڴ���������������
	MyDialog dia;
	int sum;
	CClientDC dc(this);
	int r = dia.DoModal();
	if (r == IDOK)
	{
		int A = dia.a;
		int B = dia.b;
		sum = A + B;
		CString c;
		c.Format(_T("����Ľ���ǣ�%d"), sum);
		dc.TextOutW(600, 200, c);
	}
}
