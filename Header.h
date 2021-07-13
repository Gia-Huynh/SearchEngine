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
#include <filesystem>
//namespace fs = std::filesystem;


#define ENCODING_ASCII      0
#define ENCODING_UTF8       1
#define ENCODING_UTF16LE    2
#define ENCODING_UTF16BE    3

//std::unordered_set<std::wstring> stopwords;
void ReadStopWords(const char filename[]);
//using namespace std;
//namespace wstring = std::string;

namespace OurFunkyLibrary
{
    using string = std::string; 
    using wstring = std::wstring;
    using wifstream = std::wifstream;
    using wistringstream = std::wistringstream;
    using wostream = std::wostream;
    using std::wcout;
    using std::wcin;
    using std::endl;
}
using namespace OurFunkyLibrary;

wstring inpWstring(wstring message);
string inpString(string message);
string WstringToString(wstring wStr);
wstring StringToWstring(string Str);
std::wstring readFile(wstring path);
wstring fileWstring(wstring file_name);
std::map<wstring, int> FeatureSelection(wstring InputString);
wstring StopwordRemove(wstring InputString);
int FeatureMapListSave(std::map<wstring, std::map<wstring, int>>& FeatureMapList, wstring filename, int encoding);
int FeatureMapListRead(std::map<wstring, std::map<wstring, int>>& FeatureMapList, wstring filename);
int ReadOneFile(std::map<wstring, std::map<wstring, int>>& FeatureMapList, wstring filename);
wstring dondep(wstring s);

#endif // _BaiTapList_H_ 