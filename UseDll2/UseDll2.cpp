// UseDll2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <windows.h>

using namespace std;

//用typedef定义一个指针函数类型
//这个指针类型，要和你调用的函数类型和参数保持一致
typedef void (*DLL_Void_Func)(void);
typedef int (*DLL_Int_Func)(int, int);

int main()
{
	//定一个句柄实例，用来取DLL的实例地址。
	HINSTANCE hdll;		
	
	//格式为hdll=LoadLibrary（“DLL地址”）；
	//这里字符串类型是LPSTR，当是unicode字符集的时候会不行，因此要在配置-属性-常规里面把默认字符集“unicode”改成支持多字符扩展即可。
	//或者使用TEXT()转换一下
	//路径可以是相对路径，也可以是绝对路径
	hdll = LoadLibrary(TEXT("../KINGDll.dll"));

	if (hdll == NULL) {
		cout << "load dll failed" << endl;
		getchar();
		return -1;
	}
	else {
		cout << "load dll success!" << endl;
	}

	//导入全局函数 sub（int，int）
	DLL_Int_Func sub = NULL;
	//sub = (DLL_Int_Func)GetProcAddress(hdll, "?Sub@@YAHHH@Z");	//执行成功
	sub = (DLL_Int_Func)GetProcAddress(hdll, "Sub");
	
	if (sub == NULL) {
		cout << "load sub function failed" << endl;
	}
	else {
		int res = sub(5, 1);
		cout << res << endl;
	}

	
	DLL_Void_Func vfunc = NULL;
	vfunc = (DLL_Void_Func)GetProcAddress(hdll, "?fnKingDll@@YAHXZ");
	if (vfunc == NULL) {
		cout << "load fnKingDll function failed" << endl;
	}
	else {
		vfunc();
	}

	//导入类成员函数 CKingDll::Add(int a, int b)
	DLL_Int_Func add = NULL;
	add = (DLL_Int_Func)GetProcAddress(hdll, "?Add@CKingDll@");
	if (add == NULL){
		cout << "load add function failed" << endl;
	}
	else {
		int res = add(5, 1);
		cout << res << endl;
	}

	FreeLibrary(hdll);
	getchar();
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
