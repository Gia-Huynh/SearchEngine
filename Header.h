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
#include <unordered_map>
#include <unordered_set>
#include <clocale>
#include <time.h>
#include <vector>


#define ENCODING_ASCII      0
#define ENCODING_UTF8       1
#define ENCODING_UTF16LE    2
#define ENCODING_UTF16BE    3

using namespace std; 
//std::unordered_set<std::wstring> stopwords;
void ReadStopWords(const char filename[]);
wstring inpWstring(wstring message);
string inpString(string message);
string WstringToString(wstring wStr);
wstring StringToWstring(string Str);
std::wstring readFile(wstring path);
wstring fileWstring(wstring file_name);
map<wstring, int> FeatureSelection(wstring InputString);
wstring StopwordRemove(wstring InputString);
int SaveToFile(map<wstring, map<wstring, int>>& FeatureMap, wstring filename, int encoding = ENCODING_UTF8);
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