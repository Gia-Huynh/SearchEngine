﻿#include "Header.h"
wstring inpWstring(const wchar_t message[])
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    locale::global(locale("vi_VN.utf8"));
    wprintf(message);
    wstring s;
    getline(std::wcin, s);
    //wcin >> s;
    return s;
};


wstring fileWstring(const wchar_t file_name[])
{
    wifstream inFile;
    _setmode(_fileno(stdin), _O_U16TEXT);
    locale::global(locale("vi_VN.utf8"));
    inFile.open(file_name);
    wstring s;
    //s = inFile.read();
    while (inFile >> ws, getline(inFile, s, L' '))
    {
        //replace(s.begin(), s.end(), '\n', ' ');
        wcout << "Yes: " << s << endl;
    };
    //getline(std::wcin, s);
    //wcin >> s;
    return s;
};

void Bai1()
{
        _setmode(_fileno(stdout), _O_U16TEXT);
        wstring Str = L"Tiếng Việt";
        wcout << Str << endl;
};
void Bai2()
{
};
void Bai3()
{
};
void Bai4()
{
};
void Bai5()
{
};
void Bai6()
{
};
void Bai7()
{
};
void Bai8()
{
};
void Bai9()
{
};