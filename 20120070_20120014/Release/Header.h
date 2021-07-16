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

template <typename  T, typename U>
void quicksort(T begin, T end, U test);
template <class T, class U>
class wtf_map
{
public:
    U default_value;
    long top = 0;
    bool sorted = 0;
private:
    std::vector<std::pair<T, U>> nigger;
public:
    wtf_map()
    {
        nigger.reserve(20);
    };
    void operator = (const std::initializer_list<std::pair <T, U>>& faggot)
    {
        for (auto i = faggot.begin(); i != faggot.end(); i++)
        {
            insert(i->first, i->second);
        };
    };
    /*
    U* operator [] (const T gayy)
    {
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair <T, U>>>> low = begin();
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair <T, U>>>> high = end();
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair <T, U>>>> center = (high - low) / 2 + low;
        wcout << "searching... []\n";
        while (low < high)
        {
            center = (high - low) / 2 + low;
            if (gayy > (*center).first)
            {
                low = center + 1;
            }
            else high = center;
        };
        wcout << "done searching... [] 2\n";
        if (begin() != end()) if ((*center).first == gayy) return &(*center).second;

        wcout << "No value detected, creating new\n";
        U gaynigger = default_value;
        insert(gayy, gaynigger);

        top++;
        low = begin();
        high = end();
        while (low < high)
        {
            center = (high - low) / 2 + low;
            if (gayy > (*center).first)
            {
                low = center + 1;
            }
            else high = center;
        };
        wcout << "done searching... 3\n";
        if ((*center).first == gayy) return &(*center).second;
        wcout << " Ummmmmmm W T F\n";
        return nullptr;
        //if ((*center).first == gayy) return &((*center).second);
       // return &(begin()->second);
    };*/

    U* operator [] (const T gayy)
    {
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair <T, U>>>> low = begin();
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair <T, U>>>> high = end();
        //wcout << "searching... []\n";
        for (auto i = low; i != high; i++)
        {
            if (i->first == gayy) 
            {
                //wcout << L"Found []\n"; 
                return &(i->second);
            };
        };
        //wcout << "No value detected, creating new " << gayy << " \n";
        U gaynigger = default_value;
        insert(gayy, gaynigger);
        low = begin();
        high = end();
        for (auto i = low; i != high; i++)
        {
            if (i->first == gayy)
            {
                //wcout << L"Found []\n"; 
                return &(i->second);
            };
        };
        wcout << "operator [] null pointer\n";
        return nullptr;
        //if ((*center).first == gayy) return &((*center).second);
       // return &(begin()->second);
    };
    void insert(T newElement, U newKey)
    {
        top++;
        //wcout << "insert(T newElement, U newKey)\n";
        nigger.push_back(std::make_pair(newElement, newKey));
        sorted = 0;
        //wcout << "Quicksorting...\n";
        //if (top == 20)
        //{
        //    wcout << "____________\nSorted \n";
        //    for (auto i = begin(); i != end(); i++)
        //   {
        //        wcout << i->first << "\n";
        //    };
        //};
    };
    void sort()
    {
        //wcout << "void sort() end() - 1\n";
        quicksort(begin(), end()-1, *(begin()));
    };
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair <T, U>>>> quick_find(T findElement)
    {
        if (top == 0) return end();
        //if (sorted == 0)
        //{
            //wcout << "sorting";
        //    sort();
        //    sorted = 1;
        //};
        ////Binary search
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair <T, U>>>> low = begin();
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair <T, U>>>> high = end()-1;
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair <T, U>>>> center = (high - low) / 2 + low;
        //wcout << " find(T findElement)\n";
        while (low < high)
        {
            center = (high - low) / 2 + low;
            if (findElement > (*center).first)
            {
                low = center + 1;
            }
            else high = center;
            if (high == low + 1)
            {
                if (findElement == (*low).first) return low;
                if (findElement == (*high).first) return high;
                return end();
            };
        };
        //wcout << "done find(T findElement)\n";
        if ((*center).first == findElement) { 
            //wcout << "done return find(T findElement)\n"; 
            return center; }
        //wcout << "Uhh.....\n";
        return end();
    };
    void insert(std::pair <T, U> a)
    {
        insert(a.first, a.second);
    };
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair <T, U>>>> begin()
    {
        return nigger.begin();
    };
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair <T, U>>>> end()
    {
        return nigger.end();
    };
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair <T, U>>>> find(T findElement)
    {
        if (top == 0) return end();

        //std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair <T, U>>>> low = begin();
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair <T, U>>>> high = end();
        //wcout << "searching... []\n";
        for (auto i = begin(); i != high; i++)
        {
            if (i->first == findElement)
            {
                //wcout << L"Found []\n"; 
                return i;
            };
        };

        return end();

    };
    void clear()
    {
        nigger.clear();

    };
    void optimize()
    {
        nigger.resize(top);
        nigger.shrink_to_fit();
    };
    void resize(long long a)
    {
        nigger.reserve(a + top);
    };
    void clean()
    {
    };
};




void generate_hash(const char filename[]);
wstring inpWstring(wstring message);
string inpString(string message);
string WstringToString(wstring wStr);
wstring StringToWstring(string Str);
std::wstring readFile(wstring path);
wstring fileWstring(wstring file_name);
wtf_map<wstring, int> FeatureSelection(wstring InputString);
wstring StopwordRemove(wstring InputString);
int FeatureMapListSave(wtf_map<wstring, wtf_map<wstring, int>>& FeatureMapList, wstring filename, int encoding);
int FeatureMapListRead(wtf_map<wstring, wtf_map<wstring, int>>& FeatureMapList, wstring filename);
int ReadOneFile(wtf_map<wstring, wtf_map<wstring, int>>& FeatureMapList, wstring filename);
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