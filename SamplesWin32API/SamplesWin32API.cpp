// SamplesWin32API.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "iostream"

void main()
{
	setlocale(LC_ALL, "Russian");
	HWND hwnd;
	char p[100];
	hwnd = GetDesktopWindow();
	hwnd = GetWindow(hwnd, GW_CHILD);
	while (hwnd != 0)
	{
		hwnd = GetWindow(hwnd, GW_HWNDNEXT);
		GetWindowText(hwnd, p, 100);
		if (strlen(p)>0)  std::cout << p << std::endl;
	}

}