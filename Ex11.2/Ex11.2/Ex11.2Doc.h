
// Ex11.2Doc.h : CEx112Doc ��Ľӿ�
//


#pragma once
#include "Ex11.2Set.h"


class CEx112Doc : public CDocument
{
protected: // �������л�����
	CEx112Doc();
	DECLARE_DYNCREATE(CEx112Doc)

// ����
public:
	CEx112Set m_Ex112Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CEx112Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
