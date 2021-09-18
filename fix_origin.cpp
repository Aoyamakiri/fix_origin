#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
int main()
{
	printf("请等待一会\n");
	DWORD processID;
	DWORD threadID;
	HANDLE hProcess = NULL;
	int back;
	HWND hwnd = FindWindow(NULL, "Origin");
	threadID = GetWindowThreadProcessId(hwnd, &processID);
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
	back = TerminateProcess(hProcess, 0);
	if (back == 0)
	{
		printf("请打开Origin后执行本程序\n");
		printf("终止进程失败\n");
	}
	else
	{
		Sleep(3000);
		printf("正在执行\n");
		system("rmdir /s /q %HOMEPATH%\\AppData\\Roaming\\Origin");
		system("rmdir /s /q %HOMEPATH%\\AppData\\Local\\Origin");
	}
}
