// Ex10.3.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Ex10.3.h"


// ���ǵ���������һ��ʾ��
EX103_API int nEx103=0;

// ���ǵ���������һ��ʾ����
EX103_API int fnEx103(void)
{
    return 42;
}

EX103_API int factorial(int n)
{
	int r = 1, i;
	for (i = n; i > 0; i--)
	{
		r = r*i;
	}
	return r;
}

EX103_API float convert(float deg)
{
	float h;
	h = deg / 180 * (float)3.14;
	return h;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� Ex10.3.h
CEx103::CEx103()
{
    return;
}
