// 20120070.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Header.h"
#include <windows.h>
void printHelp()
{
    wprintf(L"____________________________________________________________________\n");
    wprintf(L"|                                                                  |\n");
    wprintf(L"| 0 Thoat chuong trinh                                             |\n");
    wprintf(L"| 1 Chon thu muc                                                   |\n");
    wprintf(L"| 2 Chon che do doc (cap nhat (them xoa file) / doc lai tat ca)    |\n");
    wprintf(L"| 3 Cap nhat co so du dieu                                         |\n");
    wprintf(L"| 4 Tim kiem                                                       |\n");
    wprintf(L"| 5 Hien thi lai menu                                              |\n");
    wprintf(L"|__________________________________________________________________|\n");
};

int findTxt(wstring& IndexPath, wstring& FolderPath)
{
    if ((IndexPath.length() >= 9) && (IndexPath.substr(max(1, IndexPath.length() - 8))) == L"ndex.txt")
        FolderPath = IndexPath.substr(0, IndexPath.length() - 9);
    else
    {
        if (IndexPath.substr(IndexPath.length() - 1) != L"\\")
            IndexPath.push_back('\\');
        //IndexPath = IndexPath + "/";
        FolderPath = IndexPath;
        IndexPath = IndexPath.substr(0, string::npos) + L"index.txt";
    };
    return 0;
};

int checkIndex(wifstream &IndexStream, wstring IndexPath, wstring FolderPath)
{

    IndexStream.open(IndexPath);
    //ifstream == 1 if fail, == 0 if success
    if (!IndexStream)
    {
        wcout << "\"index.txt\" open failure, check file name\n";
        wcout << "auto generating index.txt\n";
        std::wofstream ofs(IndexPath, std::ios::binary);

        for (auto& p : std::filesystem::recursive_directory_iterator(FolderPath))
        {
            wstring pathtemp = p.path();
            pathtemp.erase(0, FolderPath.size());
            ofs << pathtemp << "\r\n";
        };

        IndexStream.open(IndexPath);

    }
    return 0;
};
int countIndex(wifstream& IndexStream, wstring& TxtFile, long long& fileNums)
{
    wcout << "Getting index.txt data....\n";
    while ((getline(IndexStream, TxtFile))) {
        fileNums++;
    }
    IndexStream.clear();
    IndexStream.seekg(0);
    return 0;
};
std::map<wstring, int> FeatureMap;
std::map<wstring, std::map<wstring, int>> FeatureMapList;   
int ReadMetadata ()
{
    wcout << "Reading old metadata.txt....\n";
    FeatureMapListRead(FeatureMapList, L"metadata.txt");
    ReadStopWords("vietnamese-stopwords.txt"); 
    return 0;
};
long long t0;
int ReadFile(wifstream& IndexStream, wstring TxtFile, wstring FolderPath, long long fileNums)
{
    long long t1;
    long long fileCurrentNums = 0;
    wstring data;
    while ((getline(IndexStream, TxtFile))) {
        fileCurrentNums++;
        t1 = time(NULL);
        if (fileCurrentNums % 50 == 0) wcout << TxtFile << " " << fileCurrentNums << "/" << fileNums << " ETA: " << float(((t1 - t0) * (fileNums - fileCurrentNums))) / fileCurrentNums << "s\n";
        if (FeatureMapList.find(FolderPath + TxtFile) == FeatureMapList.end())
        {
            data = fileWstring((FolderPath + TxtFile));
            data = StopwordRemove(data);
            FeatureMap = FeatureSelection(data);
            FeatureMapList[FolderPath + TxtFile] = FeatureMap;
        };
    }
    return 0;
}
int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    std::locale::global(std::locale("vi_VN.utf8"));
    std::setlocale(LC_ALL, "vi_VN.utf8");
    //_setmode(_fileno(stdout), _O_U16TEXT);
    //_setmode(_fileno(stdout), _O_WTEXT);

    wstring IndexPath = L"Yes";
    wstring FolderPath;
    int n = 1;

    IndexPath = inpWstring(L"Nhap duong dan tuong doi (relative path): ");

    t0 = time(NULL);
    long long t1;

    findTxt(IndexPath, FolderPath);
    wcout << L"Index.txt location: " << IndexPath << endl;
    wcout << L"Folder path: " << FolderPath << endl;
    

    wifstream IndexStream;
    checkIndex(IndexStream, IndexPath, FolderPath);

    wstring TxtFile;
    long long fileNums = 0;
    countIndex(IndexStream, TxtFile, fileNums);
    

    ReadMetadata();

    wcout << "Reading files....\n";
    ReadFile(IndexStream, TxtFile, FolderPath, fileNums);

    wcout << "Saving metadata.txt...\n";
    FeatureMapListSave(FeatureMapList, L"metadata.txt", ENCODING_UTF8);
    
    
    
    IndexStream.close();
    t1 = time(NULL);
    wcout << "Total time elapsed: " << t1 - t0 <<"\n";
    
    return 0;    
    
    //Below this line is full of shit


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