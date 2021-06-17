// 20120070.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Header.h"
void printHelp()
{
    printf("_______________________________________\n");
    printf("|                                     |\n");
    printf("| 0 Thoat chuong trinh                |\n");
    printf("| 1                 |\n");
    printf("| 2                     |\n");
    printf("| 3                     |\n");
    printf("| 4               |\n");
    printf("| 10 Hien thi lai menu              |\n");
    printf("|_____________________________________|\n");
};
int main()
{
    char yes;
    int n = 1;
    printHelp();
    while (true)
    {
        printf("Nhap so (0-10): ");
        scanf_s(" %d", &n);
        switch (n)
        {
        case 0:
            printf("Chuong trinh tu huy trong 3...2...1...0");
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
            printf("Khong hop le\n");
        };
    };
};