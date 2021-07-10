// 20120070.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Header.h"
#include <windows.h>
int ReadMode = 0;
int MaxNumSearch = 3;
void printHelp()
{
    wprintf(L"____________________________________________________________________\n");
    wprintf(L"|                                                                  |\n");
    wprintf(L"| 0 Thoát chương trình                                             |\n");
    wprintf(L"| 1 Chọn thư mục                                                   |\n");
    if (ReadMode == 0)  
    wprintf(L"| 2 Chọn chế độ đọc [-->> cập nhật <<-- / đọc lại tất cả]          |\n");
    else 
    wprintf(L"| 2 Chọn chế độ đọc [cập nhật / -->> đọc lại tất cả <<--]          |\n");
    wprintf(L"| 3 Cập nhật cơ sở dữ liệu                                         |\n");
    wprintf(L"| 4 Lưu cơ sở dữ liệu                                              |\n");
    wprintf(L"| 5 Chọn tối đa số lượng kết quả trả về ( Hiện tại:%2d )            |\n", MaxNumSearch);
    wprintf(L"| 6 Tìm kiếm                                                       |\n");
    wprintf(L"| 7 Hiển thị lại menu                                              |\n");
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
        wcout << "Chưa nhập đường dẫn tới thư mục! \n";
        return 2;
    };
    IndexStream.open(IndexPath);
    //ifstream == 1 if fail, == 0 if success
    if (!IndexStream)
    {
        wcout << L"\"index.txt\" mở thất bại, kiểm tra tên file?\n";
        wcout << L"Tự động tạo file index.txt\n";
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
    wcout << "Chế độ đọc hiện tại: " << ReadMode << "\n";
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
    wprintf(L"Đã cập nhật %lld files\n", fileNums);
    return 0;
}
int Search ()
{
    wstring TuKhoa;
    wstring word;
    wstring word_2 = L" ";
    wstring word_3 = L" ";
    wstring word_4 = L" ";
    //wistringstream iss;
    if (FeatureMapList.empty() == true)
    {
        wcout << L"Chưa đọc file!\n";
        return 2;
    };
    while (true)
    {
        TuKhoa = inpWstring(L"Nhập từ khóa cần tìm kiếm (nhập \"exit\" để thoát chế độ tìm kiếm): ");
        TuKhoa = dondep(TuKhoa);

        wcout << L"___________________________________________\n";
        if (TuKhoa == L"exit") return 0;
        word;
        word_2 = L" ";
        word_3 = L" ";
        word_4 = L" ";
        wistringstream iss(TuKhoa, wistringstream::in);
        std::map<wstring, int> gay;

        while (iss >> word)
        {
            gay[word]++;
            //std::wcout << "[word]" << word << "Gay [word]: " << gay[word] << "\n";
            if (word_2 != L" ") gay[word_2 + L' ' + word]++;
            if (word_3 != L" ") gay[word_3 + L' ' + word_2 + L' ' + word]++;
            if (word_4 != L" ")  gay[word_4 + L' ' + word_3 + L' ' + word_2 + L' ' + word]++;
            word_4 = word_3;
            word_3 = word_2;
            word_2 = word;
        };
        long a;
        //long max = 0;
        //wstring best;
        long* ranking = new long[MaxNumSearch]();
        wstring* best = new wstring[MaxNumSearch];
        for (auto p = FeatureMapList.begin(); p != FeatureMapList.end(); p++)
        {
            a = 0;
            for (auto pp = gay.begin(); pp != gay.end(); pp++)
            {
                size_t NumSpace = std::count((pp->first).begin(), (pp->first).end(), ' ');
                if (p->second.find(pp->first) != p->second.end())
                {
                    a = a + (p->second[pp->first]) * NumSpace;
                };
            };
            for (int i = 0; i < MaxNumSearch; i++)
            {
                if (a > ranking[i])
                {

                    for (int j = i + 1; j < MaxNumSearch; j++)
                    {
                        ranking[j] = ranking[j - 1];
                        best[j] = best[j - 1];
                    }
                    ranking[i] = a;
                    best[i] = p->first;
                    break;
                };
            };
        };
        if ((best[0].substr(max(1, best[0].length() - 8))) == L"ndex.txt")
        {
            wcout << L"Đã hết tài liệu phù hợp.\n\n";
        }
        else
        {
            wcout << L"\nKết quả tìm kiếm:\n\n";
            for (int i = 0; i < MaxNumSearch; i++)
            {
                wcout << "[" << i + 1 << "]: " << best[i] << "\n";
                word = readFile(best[i]);
                wcout << L"Tóm tắt: " << word.substr(0, min(word.length(), 200)) << "...\n\n";
                if ((i != MaxNumSearch - 1) && (best[i] == best[i + 1]))
                {
                    wcout << L"Không còn kết quả phù hợp\n\n";
                    break;
                };
            };
            wcout << L"___________________________________________\n";
        };
    };
    return 0;
};

int SetReadMode()
{
    wprintf(L"____________________________________\n");
    wprintf(L"| 0: Cập nhật các thay đổi (nhanh) |\n");
    wprintf(L"| 1: Cập nhật tất cả file (chậm)   |\n");
    wprintf(L"|__________________________________|\n");
    int a = 2;
    while ((a!=0) && (a!=1))
    {
        wcout << L"Nhập lựa chọn: ";
        wscanf_s(L" %d", &a);
        if ((a != 0) && (a != 1)) wcout << L"Không hợp lệ, nhập lại\n";
    };
    if (a == 0)
    {
        wprintf(L" Bạn đã chọn [0: Cập nhật các thay đổi]\n");
    } else wprintf(L" Bạn đã chọn [1: Cập nhật tất cả file]\n");;
    return a;
};


int SetMaxNumSearch()
{
    wprintf(L"____________________________________\n");
    MaxNumSearch = 0;
    while (MaxNumSearch < 1)
    {
        wprintf(L"Nhập số lượng kết quả trả về mỗi lần tìm kiếm: ");
        wscanf_s(L" %d", &MaxNumSearch);
        if (MaxNumSearch < 1) wcout << "Không hợp lệ, nhập lại\n";
        if (MaxNumSearch > 10) wcout << L"Trả về quá nhiều sẽ khiến quá trình tìm kiếm lâu, xin cân nhắc.\n";
    };
    return 0;
};

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    std::locale::global(std::locale("vi_VN.utf8"));
    std::setlocale(LC_ALL, "vi_VN.utf8");
    _setmode(_fileno(stdout), _O_U16TEXT);

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
        wprintf(L"\nNhap so (0-7): ");
        wscanf_s(L" %d", &n);
        switch (n)
        {
        case 0:
            wprintf(L"Chuong trinh tu huy trong 3...2...1...0");
            return 0;
            break;
        case 1:
            getline(std::wcin, temp);
            IndexPath = inpWstring(L"Nhập đường dẫn tương đối (relative path) tới thư mục: ");
            std::transform(IndexPath.begin(), IndexPath.end(), IndexPath.begin(), ::tolower);
            findTxt(IndexPath, FolderPath);
            break;
        case 2:
            ReadMode = SetReadMode();
            break;
        case 3:
            if (checkIndex(IndexStream, IndexPath, FolderPath) == 2) break;
            fileNums = 0;
            wcout << L"Đọc dữ liệu file index.txt....\n";
            countIndex(IndexStream, TxtFile, fileNums);
            wcout << L"Done.\n";
            wcout << L"Đọc dữ liệu file metadata.txt....\n";
            ReadMetadata();
            wcout << L"Done.\n";
            wcout << L"Đọc dữ liệu cac file van bang....\n";
            ReadAllFile(IndexStream, TxtFile, FolderPath, fileNums);
            printHelp();
            break;
        case 4:
            wcout << L"Đang lưu file metadata.txt...\n";
            FeatureMapListSave(FeatureMapList, L"metadata.txt", ENCODING_UTF8);
            wcout << L"Done.\n";
            break;
        case 5:
            SetMaxNumSearch();
            break;
        case 6:
            getline(std::wcin, temp);
            Search();
            printHelp();
            break;
        case 7:
            printHelp();
            break;
        default:
            wprintf(L"Không hợp lệ\n");
        };
    };
    return 0;
};