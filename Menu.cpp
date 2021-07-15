// 20120070.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Header.h"
#include <windows.h>
int ReadMode = 1;
long long t0;
int MaxNumSearch = 3;
/*
template <typename  T>
void quicksort(T* begin, T* end)
{
    T gaynigger;
    T pivot;
    if (begin <= end)
    {
        pivot.first = begin->first;
        T* i = (begin - 1);  // Index of smaller element
        for (T* j = begin; j <= end - 1; j++)
        {
            if ((*j).first <= pivot.first)
            {
                i++;

                gaynigger = *i;
                *i = *j;
                *j = gaynigger;

            }
        };

        gaynigger = (*(i + 1));
        *i = *end;
        *end = gaynigger;


        T* center = (i + 1);
        quicksort(begin, center - 1);
        quicksort(center + 1, end);
    }
};
*/
template <typename  T, typename U>
void quicksort(T begin, T end, U test)
{    
    //ALL GOOD 
    /*
    auto k = begin;
    for (auto i = begin; (i+1) != end; i++)
    {
        k = i;
        for (auto j = i+1; j != end; j++)
        {
            if (k->first > j->first)
            {
                k = j;
            };
        };
        iter_swap(i, k);
    };
    return;
    */
    if (begin >= end) return;
    T gaynigger;
    auto pivot = (end - begin)/2 + begin;
    if (begin < end)
    {
        pivot = (end - begin)/2 + begin;
        //pivot = begin->first;
        T left = begin;
        T right = end;
        while (true)
        {
            if (left->first < pivot->first) {};
            while (left <= right && left->first < pivot->first) {left++; }
            while (right >= left && right->first > pivot->first) {right--; };
            if (left >= right) break;
            //wcout << "Swap: " << left->first << " " << right->first << "\n";
            iter_swap(left, right);
            left++;
            right--;
        };
        //wcout << "Swap: " << left->first << " " << right->first << "\n";
        //iter_swap(left, right);

        if (pivot != begin)
            quicksort(begin, pivot, test);
        if (pivot != end)
            quicksort(pivot+1, end, test);
    };
    //wcout << "Done!\n";
};

/*template <class T, class U>
class wtf_map
{
public:
    U default_value;
private:
    std::vector<pair<T, U>> nigger;
public:
    wtf_map()
    {
    };
    void operator = (const std::initializer_list<std::pair <T, U>>& faggot)
    {
        for (auto i = faggot.begin(); i != faggot.end(); i++)
        {
            insert(i->first, i->second);
        };
    };
    U* operator [] (const T gayy)
    {
        std::vector<pair<T, U>>::iterator low = nigger.begin();
        std::vector<pair<T, U>>::iterator high = nigger.end();
        std::vector<pair<T, U>>::iterator center = (nigger.end() - nigger.begin()) / 2 + nigger.begin();
        wcout << "searching... asdasd\n";
        while (low < high)
        {
            center = (high - low) / 2 + low;
            if (gayy > center.first)
            {
                low = center + 1;
            }
            else high = center;
        };
        wcout << "done searching... asdasd\n";
        if (center.first == gayy) return &center.second;

        insert (gayy, default_value);

        low = nigger.begin();
        high = nigger.end();
        wcout << "searching 2... asdasd\n";
        while (low < high)
        {
            center = (high - low) / 2 + low;
            if (gayy > center.first)
            {
                low = center + 1;
            }
            else high = center;
        };
        wcout << "done searching 2... asdasd\n";
        if (center.first == gayy) return &center.second;
    };
    void insert(T newElement, U newKey)
    {
        nigger.push_back(std::make_pair(newElement, newKey));
        quicksort(nigger.begin(), nigger.end());
    };
    std::vector<pair<T, U>>::iterator begin()
    {
        return nigger.begin();
    };
    std::vector<pair<T, U>>::iterator end()
    {
        return nigger.end();
    };
    std::vector<T>::iterator find(T findElement)
    {
        //Binary search tree baby

        std::vector<pair<T, U>>::iterator low = nigger.begin();
        std::vector<pair<T, U>>::iterator high = nigger.end();
        std::vector<pair<T, U>>::iterator center = (nigger.end() - nigger.begin()) / 2 + nigger.begin();
        wcout << "searching... asdasd\n";
        while (low < high)
        {
            center = (high - low) / 2 + low;
            if (gayy > center.first)
            {
                low = center + 1;
            }
            else high = center;
        };
        wcout << "done searching... asdasd\n";
        if (center.first == gayy) return center;
        return nigger.end();
    };

    void clean()
    {
    };
};
*/


//wtf_map <wstring, int> FeatureMap;
//wtf_map<wstring, wtf_map<wstring, int>> FeatureMapList;
wtf_map<wstring, int> FeatureMap;
wtf_map<wstring, wtf_map<wstring, int>> FeatureMapList;
void printHelp()
{
    wprintf(L"____________________________________________________________________\n");
    wprintf(L"|                                                                  |\n");
    wprintf(L"| 0 Thoát chương trình                                             |\n");
    wprintf(L"| 1 Đọc một file                                                   |\n");
    wprintf(L"| 2 Chọn thư mục                                                   |\n");
    if (ReadMode == 0)  
    wprintf(L"| 3 Chọn chế độ đọc [-->> cập nhật <<-- / đọc lại tất cả]          |\n");
    else 
    wprintf(L"| 3 Chọn chế độ đọc [cập nhật / -->> đọc lại tất cả <<--]          |\n");
    wprintf(L"| 4 Đọc thư mục                                                    |\n");
    wprintf(L"| 5 Lưu cơ sở dữ liệu                                              |\n");
    wprintf(L"| 6 Chọn tối đa số lượng kết quả trả về ( Hiện tại:%2d )            |\n", MaxNumSearch);
    wprintf(L"| 7 Tìm kiếm                                                       |\n");
    wprintf(L"| 8 Hiển thị lại menu                                              |\n");
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
    else
    {
        wcout << L"Đã tồn tại file \"index.txt\", tiến hành đọc.\n";
    };
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

int ReadMetadata ()
{
    FeatureMapListRead(FeatureMapList, L"metadata.txt");
    ReadStopWords("vietnamese-stopwords.txt"); 
    return 0;
};
int ReadAllFile(wifstream& IndexStream, wstring TxtFile, wstring FolderPath, long long fileNums)
{
    long long ttt1;
    long long ttt2;
    long long timeFile = 0;
    long long timeStopWord = 0;
    long long timeFeature = 0;
    long long timeAdd = 0;



    long long tt1;
    tt1 = time(NULL);
    long long t1;
    long long fileCurrentNums = 0;
    wstring data;
    wcout << L"Chế độ đọc hiện tại test: " << ReadMode << "\n";
    FeatureMapList.resize(fileNums);
    while ((getline(IndexStream, TxtFile))) {
        fileCurrentNums++;
        t1 = time(NULL);
        if (fileCurrentNums % 100 == 0) wcout << fileCurrentNums << "/" << fileNums << " Time taken: " << (time(NULL) - tt1)  << "s ETA: " << float(((t1 - tt1) * (fileNums - fileCurrentNums))) / fileCurrentNums << "s\n";
        //if (fileCurrentNums % 100 == 0) wcout << timeFile  << " " << timeStopWord << " " << timeFeature << " " << timeAdd << "\n";
        if ((ReadMode == 1) || (FeatureMapList.find(FolderPath + TxtFile) == FeatureMapList.end()))
        {
            //wcout << TxtFile << "\n";
            //max(1, TxtFile.length() - 8);
            //wcout << TxtFile.length() - 8 << "\n";
            if (TxtFile.substr(max(0, long int(TxtFile.length()) - 8)) == L"ndex.txt") { fileNums--; continue; };

            //wcout << "fileWstring\n";
            //wcout << (FolderPath + TxtFile) << "\n";
            data = fileWstring((FolderPath + TxtFile));
            if (data == L"") { wcout << "empty files! skipping\n"; continue;};
            data = StopwordRemove(data);
            //wcout << "FeatureSelection\n";
            FeatureMap = FeatureSelection(data);

            //wcout << "FeatureMapList.insert\n";
            FeatureMap.optimize();
            *(FeatureMapList[FolderPath + TxtFile]) = FeatureMap;

            //if (ReadMode == 1) *(FeatureMapList[FolderPath + TxtFile]) = FeatureMap; else
            //FeatureMapList.insert(FolderPath + TxtFile, FeatureMap);
            FeatureMap.clear();
            //for (auto i = FeatureMapList.begin(); i != FeatureMapList.end(); i++)
            //{
            //    wcout << i->first << "\n";
            //};
            //(*FeatureMapList[FolderPath + TxtFile]) = FeatureMap;
            //wcout << "YOOOOOOO\n\n\n\n";
        }
        else
        {
            //wcout << "\n FeatureMapList.find != end() \n\n";
        };
    };
    wcout << "Sorting...\n";
    FeatureMapList.sort();
    wprintf(L"Đã cập nhật %lld files\n", fileNums);
    wprintf(L"Tổng thời gian: %lld", time(NULL) - tt1);
    return 0;
}
int Search ()
{
    wstring TuKhoa;
    wstring word;
    wstring word_2 = L" ";
    wstring word_3 = L" ";
    wstring word_4 = L" ";
    //if (FeatureMapList.empty() == true)
    if (FeatureMapList.top == 0)
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
        wtf_map<wstring, int> gay;

        while (iss >> word)
        {
            (*gay[word])++;
            if (word_2 != L" ") (*gay[word_2 + L' ' + word])++;
            if (word_3 != L" ") (*gay[word_3 + L' ' + word_2 + L' ' + word])++;
            //if (word_4 != L" ") (*gay[word_4 + L' ' + word_3 + L' ' + word_2 + L' ' + word])++;
            //word_4 = word_3;
            word_3 = word_2;
            word_2 = word;
        };
        long a;
        //long max = 0;
        //wstring best;
        long* ranking = new long[MaxNumSearch]();
        wstring* best = new wstring[MaxNumSearch];
        best[0] = L"index.txt";
        //wcout << "Sorting...\n";
        //FeatureMapList.sort();
        //wcout << "Sorting done\n";
        for (auto p = FeatureMapList.begin(); p != FeatureMapList.end(); p++)
        {
            a = 0;
            for (auto pp = gay.begin(); pp != gay.end(); pp++)
            {
                size_t NumSpace = std::count((pp->first).begin(), (pp->first).end(), ' ') + 1;
                if (p->second.quick_find(pp->first) != p->second.end())
                {
                    a = a + *(p->second[pp->first]) * NumSpace;
                    //a = a + *((*p).second[(*pp).first]) * NumSpace;
                };
            };
            //wcout << a << " Yay\n";
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
                    best[i] = ((*p).first);
                    break;
                };
            };
        };
        //wcout << "exited\n";
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

int ListAll()
{
    wcout << "List ALL\n";
    for (auto a = FeatureMapList.begin(); a != FeatureMapList.end(); a++)
    {
        wcout << a->first << "\n";
    };
    FeatureMapList.sort();
    wcout << "Sorted\n";
    for (auto a = FeatureMapList.begin(); a != FeatureMapList.end(); a++)
    {
        wcout << a->first << "\n";
        for (auto b = (a->second).begin(); b != (a->second).end(); b++)
        {
            wcout << "      " << b->first << "  " << b->second << "\n";
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
    }
    else { wprintf(L" Bạn đã chọn [1: Cập nhật tất cả file]\n"); FeatureMapList.clear(); }
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
    wstring SingleFilePath = L"NO";
    wstring IndexPath = L"Yes";
    wstring FolderPath;
    int n = 1;

    //Below this line is full of shit
    //generate_hash("vietnamese-stopwords.txt");
    //return 0;


    wifstream IndexStream;
    wstring TxtFile;
    long long fileNums;
    wcout << L"Đọc dữ liệu file metadata.txt....\n";
    ReadMetadata();
    wcout << L"Done.\n";

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
            SingleFilePath = inpWstring(L"Nhập đường dẫn tương đối (relative path) tới file: ");
            ReadOneFile(FeatureMapList, SingleFilePath);
            break;
        case 2:
            getline(std::wcin, temp);
            IndexPath = inpWstring(L"Nhập đường dẫn tương đối (relative path) tới thư mục: ");
            std::transform(IndexPath.begin(), IndexPath.end(), IndexPath.begin(), ::tolower);
            findTxt(IndexPath, FolderPath);
            break;
        case 3:
            ReadMode = SetReadMode();
            break;
        case 4:
            if (checkIndex(IndexStream, IndexPath, FolderPath) == 2) break;
            fileNums = 0;
            wcout << L"Đọc dữ liệu file index.txt....\n";
            countIndex(IndexStream, TxtFile, fileNums);
            wcout << L"Done.\n";
            wcout << L"Đọc dữ liệu các file văn bản....\n";
            ReadAllFile(IndexStream, TxtFile, FolderPath, fileNums);
            IndexStream.close();
            printHelp();
            break;
        case 5:
            wcout << L"Đang lưu file metadata.txt...\n";
            FeatureMapListSave(FeatureMapList, L"metadata.txt", ENCODING_UTF8);
            wcout << L"Done.\n";
            break;
        case 6:
            ListAll(); 
            break;
                
            SetMaxNumSearch();
            break;
        case 7:
            getline(std::wcin, temp);
            Search();
            printHelp();
            break;
        case 8:
            printHelp();
            break;
        default:
            wprintf(L"Không hợp lệ\n");
        };
    };
    return 0;
};