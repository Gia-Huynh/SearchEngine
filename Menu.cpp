// 20120070.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Header.h"
#include <windows.h>
int ReadMode = 0;
void printHelp()
{
    wprintf(L"____________________________________________________________________\n");
    wprintf(L"|                                                                  |\n");
    wprintf(L"| 0 Thoat chuong trinh                                             |\n");
    wprintf(L"| 1 Chon thu muc                                                   |\n");
    if (ReadMode == 0)  
    wprintf(L"| 2 Chon che do doc [-->> cap nhat <<-- / doc lai tat ca]          |\n");
    else 
    wprintf(L"| 2 Chon che do doc [cap nhat / -->> doc lai tat ca <<--]          |\n");
    wprintf(L"| 3 Cap nhat co so du dieu                                         |\n");
    wprintf(L"| 4 Luu co so du dieu                                              |\n");
    wprintf(L"| 5 Tim kiem                                                       |\n");
    wprintf(L"| 6 Hien thi lai menu                                              |\n");
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
    if (FolderPath == L"")
    {
        wcout << "Chua nhap duong dan toi thu muc! \n";
        return 2;
    };
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
    FeatureMapListRead(FeatureMapList, L"metadata.txt");
    ReadStopWords("vietnamese-stopwords.txt"); 
    return 0;
};
long long t0;
int ReadAllFile(wifstream& IndexStream, wstring TxtFile, wstring FolderPath, long long fileNums)
{
    long long tt1;
    tt1 = time(NULL);
    long long t1;
    long long fileCurrentNums = 0;
    wstring data;
    wcout << "Read mode: " << ReadMode << "\n";
    while ((getline(IndexStream, TxtFile))) {
        fileCurrentNums++;
        t1 = time(NULL);
        if (fileCurrentNums % 100 == 0) wcout << TxtFile << " " << fileCurrentNums << "/" << fileNums << " ETA: " << float(((t1 - tt1) * (fileNums - fileCurrentNums))) / fileCurrentNums << "s\n";
        if ((FeatureMapList.find(FolderPath + TxtFile) == FeatureMapList.end()) || (ReadMode == 1))
        {
            data = fileWstring((FolderPath + TxtFile));
            data = StopwordRemove(data);
            FeatureMap = FeatureSelection(data);
            FeatureMapList[FolderPath + TxtFile] = FeatureMap;
        }
        else
        {
        };
    };
    wprintf(L"Da cap nhat %ld files\n", fileNums);
    return 0;
}
int length = 1;
int Search ()
{
    if (FeatureMapList.empty() == true)
    {
        wcout << "Chua doc file!\n";
        return 2;
    };
    wstring TuKhoa = inpWstring(L"Nhập từ khóa cần tìm kiếm: ");

    wstring word;
    wstring word_2;
    wstring word_3;
    wstring word_4;
    wistringstream iss(TuKhoa, wistringstream::in);
    std::map<wstring, int> gay;

    while (iss >> word)
    {
        gay[word]++;
        //std::wcout << "[word]" << word << "Gay [word]: " << gay[word] << "\n";
        gay[word_2 + L' ' + word]++;
        gay[word_3 + L' ' + word_2 + L' ' + word]++;
        gay[word_4 + L' ' + word_3 + L' ' + word_2 + L' ' + word]++;
        word_4 = word_3;
        word_3 = word_2;
        word_2 = word;
    };
    long a;
    long max = 0;
    wstring best;
    for (auto p = FeatureMapList.begin(); p != FeatureMapList.end(); p++)
    {
        a = 0;
        for (auto pp = gay.begin(); pp != gay.end(); pp++)
        {
            if (p->second.find(pp->first) != p->second.end())
            {
                a = a + p->second[pp->first];
            };
        };
        if (a > max)
        {
            max = a;
            best = p->first;
        };
    };
    if ((best.substr(max(1, best.length() - 8))) == L"ndex.txt")
    {
        wcout << "Khong co tai lieu phu hop.\n";
    }
    else
    {
        wcout << "Kết quả: " << best << "\n";
        word = readFile(best);
        wcout << "Tóm tắt: " << word.substr(0, max (word.length(), 100)) << "...\n";
    };
};

int SetReadMode()
{
    wprintf(L"____________________________________\n");
    wprintf(L"| 0: Cap nhat cac thay doi (nhanh) |\n");
    wprintf(L"| 1: Cap nhat tat ca file (cham)   |\n");
    wprintf(L"|__________________________________|\n");
    int a = 2;
    while ((a!=0) && (a!=1))
    {
        wcout << "Nhap lua chon: ";
        wscanf_s(L" %d", &a);
        if ((a != 0) && (a != 1)) wcout << "Khong hop le, nhap lai\n";
    };
    if (a == 0)
    {
        wprintf(L" Ban da chon [0: Cap nhat cac thay doi]\n");
    } else wprintf(L" Ban da chon [1: Cap nhat tat ca file]\n");;
    return a;
};

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    std::locale::global(std::locale("vi_VN.utf8"));
    std::setlocale(LC_ALL, "vi_VN.utf8");
    //_setmode(_fileno(stdout), _O_U16TEXT);

    wstring temp;
    wstring IndexPath = L"Yes";
    wstring FolderPath;
    int n = 1;

    /*
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
       
    */

    //Below this line is full of shit

    wifstream IndexStream;
    wstring TxtFile;
    long long fileNums;
    printHelp();
    while (true)
    {
        wprintf(L"\nNhap so (0-6): ");
        wscanf_s(L" %d", &n);
        switch (n)
        {
        case 0:
            wprintf(L"Chuong trinh tu huy trong 3...2...1...0");
            return 0;
            break;
        case 1:
            getline(std::wcin, temp);
            IndexPath = inpWstring(L"Nhap duong dan tuong doi (relative path) toi thu muc: ");
            std::transform(IndexPath.begin(), IndexPath.end(), IndexPath.begin(), ::tolower);
            findTxt(IndexPath, FolderPath);
            break;
        case 2:
            ReadMode = SetReadMode();
            break;
        case 3:
            if (checkIndex(IndexStream, IndexPath, FolderPath) == 2) break;
            fileNums = 0;
            wcout << "Doc du lieu file index.txt....\n";
            countIndex(IndexStream, TxtFile, fileNums);
            wcout << "Done.\n";
            wcout << "Doc du lieu file metadata.txt....\n";
            ReadMetadata();
            wcout << "Done.\n";
            wcout << "Doc du lieu cac file van bang....\n";
            ReadAllFile(IndexStream, TxtFile, FolderPath, fileNums);
            printHelp();
            break;
        case 4:
            wcout << "Dang luu file metadata.txt...\n";
            FeatureMapListSave(FeatureMapList, L"metadata.txt", ENCODING_UTF8);
            wcout << "Done.\n";
            break;
        case 5:
            getline(std::wcin, temp);
            Search();
            break;
        case 6:
            printHelp();
            break;
        default:
            wprintf(L"Khong hop le\n");
        };
    };
    return 0;
};