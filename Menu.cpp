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
    locale::global(locale("vi_VN.utf8"));
    std::setlocale(LC_ALL, "vi_VN.utf8");
    //_setmode(_fileno(stdout), _O_U16TEXT);
    //_setmode(_fileno(stdout), _O_WTEXT);

    ReadStopWords("vietnamese-stopwords.txt");
    wstring IndexPath = L"Yes";
    wstring FolderPath;
    //return 0;
    char yes;
    int n = 1;
    IndexPath = inpWstring(L"index.txt file location: ");
    //Str = inpString("Input file: ");
    wcout << L"String inputed: " <<  IndexPath << endl;

    if ((IndexPath.length() >= 9) && (IndexPath.substr(max (1, IndexPath.length() - 8))) == L"ndex.txt")
        FolderPath = IndexPath.substr(0, IndexPath.length() - 9);
    else
    {
        if (IndexPath.substr(IndexPath.length() - 1) != L"\\")
            IndexPath.push_back('\\');
            //IndexPath = IndexPath + "/";
        FolderPath = IndexPath;
        IndexPath = IndexPath.substr(0, string::npos) + L"index.txt";
    };
    wcout << L"Index.txt location: " << IndexPath << endl;
    wcout << L"Folder path: " << FolderPath << endl;
        

    wifstream IndexStream; 
    IndexStream.open(IndexPath);

    //ifstream == 1 if fail, == 0 if success
    if (!IndexStream)
    {
        wcout << "index.txt open failure, recheck file name? (index.txt, khong phai Index)\n";
        exit(EXIT_FAILURE);
    }

    wstring TxtFile;
    wstring data;
    wcout << "Getting index.txt data....\n";
    long long fileNums = 0;
    long long fileCurrentNums = 0;
    while ((getline(IndexStream, TxtFile))) {
        fileNums++;
    }
    IndexStream.clear();
    IndexStream.seekg(0);
    
    map<wstring, int> FeatureMap;
    map<wstring, map<wstring, int>> FeatureMapList;

    long long t0 = time(NULL);
    long long t1;
    wcout << "Reading files....\n";
    while ((getline(IndexStream, TxtFile))) {
        fileCurrentNums++;
        t1 = time(NULL);
        if (fileCurrentNums % 50 == 0) wcout << TxtFile << " " << fileCurrentNums << "/" << fileNums << " ETA: " << float(((t1-t0) * (fileNums - fileCurrentNums)))  / fileCurrentNums << "s\n";
        //data = fileWstring(WstringToString( FolderPath + TxtFile)); 
        data = fileWstring((FolderPath + TxtFile));
        data = StopwordRemove(data);
        FeatureMap = FeatureSelection(data);
        FeatureMapList[FolderPath + TxtFile] = FeatureMap;
    }
    SaveToFile(FeatureMapList, L"metadata.txt", ENCODING_UTF8);
    IndexStream.close();
    t1 = time(NULL);
    wcout << "Total time elapsed: " << t1 - t0 <<"\n";
    return 0;
    //if (TxtFile)
    //    free(TxtFile);







    //wstring FileStr = fileWstring(Str);
    
    
    
    ///Below this line is full of shit
    /// 
    //string nameInp;
    //nameInp = inpString("Input file not WIDE: ");
    //cout << "File inputed: " << nameInp << endl;
    //string FileStr = " ";
    //FileStr = fileString(nameInp.data());


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