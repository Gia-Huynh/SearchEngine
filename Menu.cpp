// 20120070.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Header.h"
#include <windows.h>
void printHelp()
{
    wprintf(L"_______________________________________\n");
    wprintf(L"|                                     |\n");
    wprintf(L"| 0 Thoat chuong trinh                |\n");
    wprintf(L"| 1                 |\n");
    wprintf(L"| 2                     |\n");
    wprintf(L"| 3                     |\n");
    wprintf(L"| 4               |\n");
    wprintf(L"| 10 Hien thi lai menu              |\n");
    wprintf(L"|_____________________________________|\n");
};
int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    locale::global(locale("vi_VN.utf8"));
    wstring Str = L"Tiếng Việt";
    wcout << Str << endl;
    //return 0;
    char yes;
    int n = 1;
    Str = inpWstring(L"test input: ");
    wcout << Str << endl;
    /*
    printHelp();
    while (true)
    {
        wprintf(L"Nhap so (0-10): ");
        scanf_s(" %d", &n);
        switch (n)
        {
        case 0:
            wprintf(L"Chuong trinh tu huy trong 3...2...1...0");
            return 0;
            break;
        case 1:
            Bai1();
            break;
        case 2:
            Bai2();
            break;
        case 3:
            Bai3();
            break;
        case 4:
            Bai4();
            break;
        case 5:
            Bai5();
            break;
        case 6:
            Bai6();
            break;
        case 7:
            Bai7();
            break;
        case 8:
            Bai8();
            break;
        case 9:
            Bai9();
            break;
        case 10:
            printHelp();
            break;
        default:
            wprintf(L"Khong hop le\n");
        };
    };*/
};