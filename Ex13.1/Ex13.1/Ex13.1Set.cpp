
// Ex13.1Set.cpp : CEx131Set 类的实现
//

#include "stdafx.h"
#include "Ex13.1.h"
#include "Ex13.1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx131Set 实现

// 代码生成在 2020年5月21日, 9:33

IMPLEMENT_DYNAMIC(CEx131Set, CRecordset)

CEx131Set::CEx131Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_0jpg = L"";
	m_nFields = 1;
	m_nDefaultType = snapshot;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CEx131Set::GetDefaultConnect()
{
	return _T("DSN=\x7167\x7247;DBQ=C:\\Users\\ling\\Desktop\\\x7167\x7247.xls;DefaultDir=C:\\Users\\ling\\Desktop;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CEx131Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CEx131Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[0#jpg]"), m_0jpg);

}
/////////////////////////////////////////////////////////////////////////////
// CEx131Set 诊断

#ifdef _DEBUG
void CEx131Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEx131Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

