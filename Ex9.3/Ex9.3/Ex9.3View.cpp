
// Ex9.3View.cpp : CEx93View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex9.3.h"
#endif

#include "Ex9.3Doc.h"
#include "Ex9.3View.h"
#include "iostream"
#include "string"
#include "fstream"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int flag;


// CEx93View

IMPLEMENT_DYNCREATE(CEx93View, CView)

BEGIN_MESSAGE_MAP(CEx93View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CEx93View::OnFileOpen)
//	ON_WM_CLOSE()
END_MESSAGE_MAP()

// CEx93View ����/����

CEx93View::CEx93View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx93View::~CEx93View()
{
}

BOOL CEx93View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx93View ����

void CEx93View::OnDraw(CDC* pDC)
{
	CEx93Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	if (count != 0)
	{
		int i;
		CString filename = _T("G:\\MyPoject\\Ex9.3\\Ellipse.txt");
		ofstream of(filename);
		for (i = 0; i < count; i++)
		{
			pDC->Ellipse(a[i]);
			of << a[i].left << ' ' << a[i].top << ' ' << a[i].right << ' ' << a[i].bottom << endl;
		}
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx93View ���

#ifdef _DEBUG
void CEx93View::AssertValid() const
{
	CView::AssertValid();
}

void CEx93View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx93Doc* CEx93View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx93Doc)));
	return (CEx93Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx93View ��Ϣ�������


void CEx93View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 1;
	cr.left = point.x;
	cr.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CEx93View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 1)
	{
		cr.right = point.x;
		cr.bottom = point.y;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CEx93View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 0;
	a.Add(cr);
	count++;
	CView::OnLButtonUp(nFlags, point);
}


void CEx93View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CClientDC dc(this);
	CString filename = _T("G:\\MyPoject\\Ex9.3\\Ellipse.txt");
	ifstream ifs(filename);
	string s;
	int count = 0, i = 0;
	int num[4];
	while (ifs >> s)
	{
		num[i] = atoi(s.c_str());
		i++;
		count++;
		if (count % 4 == 0)
		{
			CRect cr(num[0], num[1], num[2], num[3]);
			dc.Ellipse(cr);
			i = 0;
		}
	}
}


