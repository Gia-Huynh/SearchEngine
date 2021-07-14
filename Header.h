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
void generate_hash(const char filename[]);
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
unsigned long int hashFunction(wchar_t s);
unsigned long int hashFunction(wstring s);
template <class T>
class unordered_set
{
public:
    T element;

private:
    int top;
    T* nigger = new T[204601]();

public:
    unordered_set()
    {
    };
    unordered_set(wchar_t* a, wchar_t* b)
    {
        wchar_t* c = a;
        while (c != b)
        {
            insert(*c);
            c++;
        };
    };
    void insert(T newElement)
    {
        unsigned long int index = hashFunction(newElement);
        //wcout << "Old value: " << nigger[index] << " New value: " << newElement << "\n";
        //if (strlen(nigger[index]) != 0) wcout << "Hash table error! Old value: "<< nigger[index] << " New value: " << newElement << "\n";
        nigger[index] = newElement;
    };

    int find(T findElement)
    {
        unsigned long int index = hashFunction(findElement);
        //if (strlen(&nigger[index]) == 0) return 0;
        //if (nigger[index] == 0) return 0;
        if (nigger[index] == findElement) return 1;
        //wcout << "\n" << nigger[index] << " " << findElement << "\n";
        return 0;
    };
    void clean()
    {
        delete[] T;
    };
};


#endif // _BaiTapList_H_ 