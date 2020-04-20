
// Ex8.4View.cpp : CEx84View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex8.4.h"
#endif

#include "Ex8.4Doc.h"
#include "Ex8.4View.h"
#include "Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int flag = 0;
int x = 0;
int y = 0;
int l = 0;
int s = 0;
CRect cr;
// CEx84View

IMPLEMENT_DYNCREATE(CEx84View, CView)

BEGIN_MESSAGE_MAP(CEx84View, CView)
	ON_COMMAND(ID_DRAWELLIPSE, &CEx84View::OnDrawellipse)
END_MESSAGE_MAP()

// CEx84View ����/����

CEx84View::CEx84View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx84View::~CEx84View()
{
}

BOOL CEx84View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx84View ����

void CEx84View::OnDraw(CDC* pDC)
{
	CEx84Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag)
	{
		Dialog dia;
		int r=dia.DoModal();
		if (r == IDOK)
		{
			x = dia.m_x;
			y = dia.m_y;
			l = dia.m_long;
			s = dia.m_short;
		}
		cr = CRect(x - l, y - s, x + l, y + s);
		pDC->Ellipse(cr);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx84View ���

#ifdef _DEBUG
void CEx84View::AssertValid() const
{
	CView::AssertValid();
}

void CEx84View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx84Doc* CEx84View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx84Doc)));
	return (CEx84Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx84View ��Ϣ�������


void CEx84View::OnDrawellipse()
{
	// TODO: �ڴ���������������
	flag = 1;
	Invalidate();
}
