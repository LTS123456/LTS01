
// Ex9.1View.cpp : CEx91View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex9.1.h"
#endif

#include "Ex9.1Doc.h"
#include "Ex9.1View.h"
#include "fstream"
#include "string"
#include "iostream"
#include "MyDialog.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int flag = 0;

// CEx91View

IMPLEMENT_DYNCREATE(CEx91View, CView)

BEGIN_MESSAGE_MAP(CEx91View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CEx91View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &CEx91View::OnFileSaveAs)
END_MESSAGE_MAP()

// CEx91View ����/����

CEx91View::CEx91View()
{
	// TODO: �ڴ˴���ӹ������
	
}

CEx91View::~CEx91View()
{
}

BOOL CEx91View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx91View ����

void CEx91View::OnDraw(CDC* /*pDC*/)
{
	CEx91Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx91View ���

#ifdef _DEBUG
void CEx91View::AssertValid() const
{
	CView::AssertValid();
}

void CEx91View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx91Doc* CEx91View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx91Doc)));
	return (CEx91Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx91View ��Ϣ�������


void CEx91View::OnFileOpen()
{
	// TODO: �ڴ���������������
	string s;
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ifstream in(cfd.GetPathName());
		in >> s;
		filename= s.c_str();
		flag = 1;
	}
	if (flag == 1)
	{
		MyDialog *dia = new MyDialog;
		dia->Create(IDD_DIALOG1);
		dia->ShowWindow(1);
	}
}

void CEx91View::OnFileSaveAs()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ofstream out (_T("C:\\Users\\ling\\Desktop\\abc.txt"));
		CString s = cfd.GetPathName();
		out << CT2A(s.GetString()) << endl;
	}
}
