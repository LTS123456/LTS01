#include "stdafx.h"
#include "win32.h"

float FAC::convert(float deg)
{
	float h;
	h = deg / 180 * (float)3.14;
	return h;
}