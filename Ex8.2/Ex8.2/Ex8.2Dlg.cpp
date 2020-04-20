
// Ex8.2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex8.2.h"
#include "Ex8.2Dlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CEx82Dlg 对话框



CEx82Dlg::CEx82Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EX82_DIALOG, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx82Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CEx82Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CEx82Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CEx82Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CEx82Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CEx82Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CEx82Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CEx82Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CEx82Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CEx82Dlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CEx82Dlg 消息处理程序

BOOL CEx82Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_edit.SetWindowText((LPCTSTR)"");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CEx82Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CEx82Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CEx82Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CEx82Dlg::Save()
{
	UpdateData(TRUE);
	num1 = _wtof(m_str);  
	UpdateData(FALSE);
}

void CEx82Dlg::Calculator()
{
	UpdateData(TRUE);
	num2 = _wtof(m_str.Right(m_str.GetLength() - strle));
	double f = 0.0f;             
	switch (mark)    
	{
	case 0:
		f = num1 + num2;  
		break;
	case 1:
		f = num1 - num2;   
		break;
	case 2:
		f = num1 * num2;     
		break;
	case 3:
		if (num2 == 0.0f)                
		{
			MessageBox(_T("除数不能为0!"));    
			f = num1;
		}
		else
		{
			f = num1 / num2;          
		}
		break;
	default:
		break;
	}
	if (f - int(f) <= 1e-5)
	{
		m_str.Format(_T("%d"), (int)f);
	}
	else
	{
		m_str.Format(_T("%g"), f);       
	}
	UpdateData(FALSE);
}

void CEx82Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Save();
	UpdateData(TRUE);
	m_str.Format(m_str + _T("+"));
	UpdateData(FALSE);
	strle = m_str.GetLength();    
	mark = 0;
}


void CEx82Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	Save();  
	UpdateData(TRUE);
	m_str.Format(m_str + _T("-"));
	UpdateData(FALSE);
	strle = m_str.GetLength();
	mark = 1;
}


void CEx82Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	Save();
	UpdateData(TRUE);
	m_str.Format(m_str + _T("x"));
	UpdateData(FALSE);
	strle = m_str.GetLength();
	mark = 2;
}


void CEx82Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	Save();
	UpdateData(TRUE);
	m_str.Format(m_str + _T("÷"));
	UpdateData(FALSE);
	strle = m_str.GetLength();
	mark = 3;
}


void CEx82Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	num1 = _wtof(m_str);
	if(num1 < 0.0f)
		MessageBox(_T("负数不能开方!"));
	else
	{
		double f = sqrt(num1);
		if (f - (int)f <= 1e-5)
		{
			m_str.Format(_T("%d"), (int)f);
		}
		else
		{
			m_str.Format(_T("%g"), f);
		}
		UpdateData(FALSE);
	}
}


void CEx82Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString c=_T("1/");
	m_str.Format(c + m_str);
	UpdateData(FALSE);
}


void CEx82Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (mark != 0 && mark != 1 && mark != 2 && mark != 3)
	{
		num1 = _wtof(m_str);
	}
	else
		Calculator();
	UpdateData(FALSE);
}


void CEx82Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = "";
	UpdateData(FALSE);
}
