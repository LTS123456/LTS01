
// Ex8.2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Ex8.2.h"
#include "Ex8.2Dlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CEx82Dlg �Ի���



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


// CEx82Dlg ��Ϣ�������

BOOL CEx82Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_edit.SetWindowText((LPCTSTR)"");
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CEx82Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
			MessageBox(_T("��������Ϊ0!"));    
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Save();
	UpdateData(TRUE);
	m_str.Format(m_str + _T("+"));
	UpdateData(FALSE);
	strle = m_str.GetLength();    
	mark = 0;
}


void CEx82Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Save();  
	UpdateData(TRUE);
	m_str.Format(m_str + _T("-"));
	UpdateData(FALSE);
	strle = m_str.GetLength();
	mark = 1;
}


void CEx82Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Save();
	UpdateData(TRUE);
	m_str.Format(m_str + _T("x"));
	UpdateData(FALSE);
	strle = m_str.GetLength();
	mark = 2;
}


void CEx82Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Save();
	UpdateData(TRUE);
	m_str.Format(m_str + _T("��"));
	UpdateData(FALSE);
	strle = m_str.GetLength();
	mark = 3;
}


void CEx82Dlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	num1 = _wtof(m_str);
	if(num1 < 0.0f)
		MessageBox(_T("�������ܿ���!"));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString c=_T("1/");
	m_str.Format(c + m_str);
	UpdateData(FALSE);
}


void CEx82Dlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_str = "";
	UpdateData(FALSE);
}
