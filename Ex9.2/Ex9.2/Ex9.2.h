
// Ex9.2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CEx92App: 
// �йش����ʵ�֣������ Ex9.2.cpp
//

class CEx92App : public CWinApp
{
public:
	CEx92App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CEx92App theApp;