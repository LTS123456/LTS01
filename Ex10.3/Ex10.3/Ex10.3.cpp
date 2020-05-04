// Ex10.3.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Ex10.3.h"


// 这是导出变量的一个示例
EX103_API int nEx103=0;

// 这是导出函数的一个示例。
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

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 Ex10.3.h
CEx103::CEx103()
{
    return;
}
