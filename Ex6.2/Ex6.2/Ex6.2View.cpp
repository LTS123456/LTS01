
// Ex6.2View.cpp : CEx62View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex6.2.h"
#endif

#include "Ex6.2Doc.h"
#include "Ex6.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString s,s1;
CArray<CString, CString> m;
CPoint p;
CRect cr(600,200,800,225);
int x,flag,h;
// CEx62View

IMPLEMENT_DYNCREATE(CEx62View, CView)

BEGIN_MESSAGE_MAP(CEx62View, CView)
	ON_WM_CHAR()
//	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx62View ����/����

CEx62View::CEx62View()
{
	// TODO: �ڴ˴���ӹ������
	s = "";
	s1 = "";
	p.x = 605;
	p.y = 203;
	x = 605;
	flag = 0;
	h = 0;
}

CEx62View::~CEx62View()
{
}

BOOL CEx62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx62View ����

void CEx62View::OnDraw(CDC* pDC)
{
	CEx62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(cr);
	if (flag)
	{
		for(int i=0;i<flag;i++)
		pDC->TextOutW(605, 203 + (i*h), m[i]);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx62View ���

#ifdef _DEBUG
void CEx62View::AssertValid() const
{
	CView::AssertValid();
}

void CEx62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx62Doc* CEx62View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx62Doc)));
	return (CEx62Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx62View ��Ϣ�������


void CEx62View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CClientDC dc(this);
	char c = nChar;
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	h = tm.tmHeight;
	s1 = s;
	s += c;
	CSize z=
	x += 9;
	if (x >= cr.right)
	{
		m.Add(s1);
		flag += 1;
		s.Empty();
		p.y += tm.tmHeight;
		cr.bottom += tm.tmHeight;
		Invalidate();
		x = 605;
	}
	dc.TextOut(p.x, p.y, s);  
	CView::OnChar(nChar, nRepCnt, nFlags);
}

