
// Ex12.1Set.cpp : CEx121Set 类的实现
//

#include "stdafx.h"
#include "Ex12.1.h"
#include "Ex12.1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx121Set 实现

// 代码生成在 2020年5月18日, 15:32

IMPLEMENT_DYNAMIC(CEx121Set, CRecordset)

CEx121Set::CEx121Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_0jpg = L"";
	m_nFields = 1;
	m_nDefaultType = snapshot;
}

// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CEx121Set::GetDefaultConnect()
{
	return _T("DSN=\x7167\x7247;DBQ=C:\\Users\\ling\\Desktop\\\x7167\x7247.xls;DefaultDir=C:\\Users\\ling\\Desktop;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CEx121Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CEx121Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[0#jpg]"), m_0jpg);

}
/////////////////////////////////////////////////////////////////////////////
// CEx121Set 诊断

#ifdef _DEBUG
void CEx121Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEx121Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

