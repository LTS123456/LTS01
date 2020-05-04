#include "stdafx.h"
#include "win32.h"

int f1 :: factorial(int n)
{
	int r=1,i;
	for (i = n; i > 0; i--)
	{
		r = r*i;
	}
	return r;
}