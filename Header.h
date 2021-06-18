#pragma once
#ifndef  __BaiTapList_H__
#define  __BaiTapList_H__

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <codecvt>
#include <algorithm>
#include <map>


using namespace std;
wstring inpWstring(const wchar_t message[]);
string WstringToString(wstring wStr);
std::wstring readFile(string path);
wstring fileWstring(wstring file_name);

//void Bai1();
void Bai2();
void Bai3();
void Bai4();
void Bai5();
void Bai6();
void Bai7();
void Bai8();
void Bai9();

#endif // _BaiTapList_H_ 