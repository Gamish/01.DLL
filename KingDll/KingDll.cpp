// KingDll.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "KingDll.h"
#include <iostream>

using namespace std;

// 这是导出变量的一个示例
KINGDLL_API int nKingDll=0;

// 这是导出函数的一个示例。
KINGDLL_API int fnKingDll(void)
{
	cout << "King_Dll" << endl;
    return 0;
}
KINGDLL_API int Sub(int a, int b)
{
	return a - b;
}

// 这是已导出类的构造函数。
CKingDll::CKingDll()
{
    return;
}

void CKingDll::PrintHelloWorld()
{
	cout << "Hello World! King!";
}

int CKingDll::Add(int a, int b)
{
	return a + b;
}




