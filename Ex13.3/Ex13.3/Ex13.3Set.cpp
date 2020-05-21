
// Ex13.3Set.cpp : CEx133Set 类的实现
//

#include "stdafx.h"
#include "Ex13.3.h"
#include "Ex13.3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx133Set 实现

// 代码生成在 2020年5月21日, 22:45

IMPLEMENT_DYNAMIC(CEx133Set, CRecordset)

CEx133Set::CEx133Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CEx133Set::GetDefaultConnect()
{
	return _T("DSN=d4;DBQ=C:\\Users\\ling\\Desktop\\d4.mdb;DefaultDir=C:\\Users\\ling\\Desktop;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CEx133Set::GetDefaultSQL()
{
	return _T("[表1]");
}

void CEx133Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[字段1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CEx133Set 诊断

#ifdef _DEBUG
void CEx133Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEx133Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

