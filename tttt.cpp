// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
using namespace std;

void* my_memcpy_byte(void *dst, const void *src, int n)
{
	assert(dst != NULL && src != NULL && n >= 0);
	char* pdst = (char*)dst;
	const char* psrc = (const char*)src;
	if (pdst > psrc && pdst <psrc + n) //不能写src+n
	{
		pdst = pdst + n - 1;
		psrc = psrc + n - 1;
		while (n--)
		{
			*pdst-- = *psrc--;
		}
	}
	else
	{
		while (n--)
		{
			*pdst++ = *psrc++;
		}
	}
	return dst;
}

char* my_strcpy0(char* dst, const char* src)//不考虑内存重叠
{
	assert(dst != NULL && src != NULL);
	char* pdst = dst;
	while ((*dst++ = *src++) != '\0');
	return pdst;
}
char* my_strcpy1(char* dst, const char* src)//考虑内存重叠
{
	assert(dst != NULL && src != NULL);
	int n = strlen(src)+1;
	char* pres = dst;
	if (dst > src && dst <src + n)
	{
		dst = dst + n - 1;
		src = src + n - 1;
		while (n--)
		{
			*dst-- = *src--;
		}
	}
	else
	{
		while (n--)
		{
			*dst++ = *src++;
		}
	}
	return pres;
}


int main(int argc, char** argv)
{

	return 0;
}
