
// Ex4.3View.cpp : CEx43View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex4.3.h"
#endif

#include "Ex4.3Doc.h"
#include "Ex4.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx43View

IMPLEMENT_DYNCREATE(CEx43View, CView)

BEGIN_MESSAGE_MAP(CEx43View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx43View ����/����

CEx43View::CEx43View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx43View::~CEx43View()
{
}

BOOL CEx43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx43View ����

void CEx43View::OnDraw(CDC* pDC)
{
	CEx43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx43View ���

#ifdef _DEBUG
void CEx43View::AssertValid() const
{
	CView::AssertValid();
}

void CEx43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx43Doc* CEx43View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx43Doc)));
	return (CEx43Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx43View ��Ϣ�������


void CEx43View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEx43Doc* pDoc = GetDocument();
	CRect clientRect;
	GetClientRect(&clientRect);
	int x1 = clientRect.bottom - clientRect.top;
	int x2 = clientRect.right - clientRect.left;
	switch (nChar)
	{
	case VK_UP:
		if (pDoc->cr.top > 0);
		{
			pDoc->cr.top -= 50;
			pDoc->cr.bottom -= 50;
		}
		break;
	case VK_DOWN:
		if (pDoc->cr.bottom < x1);
		{
			pDoc->cr.top += 50;
			pDoc->cr.bottom += 50;
		}
		break;
	case VK_LEFT:
		if (pDoc->cr.left > 0);
		{
			pDoc->cr.left -= 50;
			pDoc->cr.right -= 50;
		}
		break;
	case VK_RIGHT:
		if (pDoc->cr.right < x2);
		{
			pDoc->cr.left += 50;
			pDoc->cr.right += 50;
		}
		break;
	case 'A':/*�ʼǱ�����û��home��*/
		if (pDoc->cr.left > 0&&pDoc->cr.top>0);
		{
			pDoc->cr.left -= 50;
			pDoc->cr.top -= 50;
		}
		break;
	case 'D':/*�ʼǱ�����û��END��*/
		if (pDoc->cr.left < pDoc->cr.right && pDoc->cr.top<pDoc->cr.bottom);
		{
			pDoc->cr.left += 50;
			pDoc->cr.top += 50;
		}
		break;
	}
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CEx43View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEx43Doc* pDoc = GetDocument();
	pDoc->cr.left = 30;
	pDoc->cr.top = 30;
	pDoc->cr.right = 130;
	pDoc->cr.bottom = 130;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
