﻿#include "Header.h"

using namespace OurFunkyLibrary;

wchar_t NotLegalW[] = {L'\r', L'\n', '~','`','!','@','#','$','%','^','&','*','(',')','-','_','+','=','[',']','{','}','|','\\',';',':','\'','\"',',','<','.','>','/','?' };
int len = sizeof(NotLegalW) / sizeof(wchar_t);
template <class T>
class unordered_set 
{
public:
    T element;

private:
    struct nigger
    {
        T data;
        nigger* tail = nullptr;
    };
    nigger* top = nullptr;

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
        if (top == nullptr)
        {
            top = new nigger;
            (*top).data = newElement;
        }
        else
        {
            nigger* LetSGOO = top;
            while ((*LetSGOO).tail != nullptr)
            {
                LetSGOO = (*LetSGOO).tail;
            };
            (*LetSGOO).tail = new nigger;
            ((*(*LetSGOO).tail)).data = newElement;
        };
    };

    int find(T findElement)
    {
        if (top == nullptr)
        {
            return 0;
        }
        else
        {
            nigger* LetSGOO = top;
            while (LetSGOO != nullptr)
            {
                if ((*LetSGOO).data == findElement) return 1;
                LetSGOO = (*LetSGOO).tail;
            };
            return 0;
        };
    };
};


template <class T, class U>
class unordered_map
{
public:
    //T element;

private:
    struct nigger
    {
        T first;
        U second;
        nigger* tail = nullptr;
    };
    nigger* top = nullptr;
    nigger* bot = nullptr;

public:
    unordered_map()
    {
    };
    U* operator [] (const T index)
    {
        //if map empty
        if (top == nullptr)
        {
            top = new nigger;
            top->first = index;
            bot = top;
            return &(top->second);
        }
        else
        {
            nigger* LetSGOO = top;
            //If element ton tai trong map
            while (LetSGOO != nullptr)
            {
                if (LetSGOO->first == index) return &(LetSGOO->second);
                LetSGOO = (*LetSGOO).tail;
            };
            //If element khong ton tai trong map.
            bot->tail = new nigger;
            (bot->tail)->first = index;
            bot = bot->tail;
            return &(bot->second);
        };
    };
    nigger* begin()
    {
        return top;
    }
    nigger* end()
    {
        return bot;
    }
    nigger* operator++ ()
    {
        return nigger->tail;
    };

    void insert(T newElement, U newElement2)
    {
        if (top == nullptr)
        {
            top = new nigger;
            (*top).first = newElement;
            (*top).second = newElement2;
            bot = top;
        }
        else
        {
            nigger* LetSGOO = top;
            while ((*LetSGOO).tail != nullptr)
            {
                LetSGOO = (*LetSGOO).tail;
            };
            (*LetSGOO).tail = new nigger;
            ((*(*LetSGOO).tail)).first = newElement;
            ((*(*LetSGOO).tail)).second = newElement2;
        };
    };

    int find(T findElement)
    {
        if (top == nullptr)
        {
            return 0;
        }
        else
        {
            nigger* LetSGOO = top;
            while (LetSGOO != nullptr)
            {
                if ((*LetSGOO).first == findElement) return 1;
                LetSGOO = (*LetSGOO).tail;
            };
            return 0;
        };
    };
};

unordered_set<std::wstring> stopwords;
unordered_set<std::wstring> stopwords1;
unordered_set<std::wstring> stopwords2;
unordered_set<std::wstring> stopwords3;
unordered_set<wchar_t> IllegalCharSet(NotLegalW, NotLegalW + sizeof(NotLegalW) / sizeof(wchar_t));


void ReadStopWords(const char filename[])
{
    unordered_map <wstring, int> gaynigger;
    gaynigger.insert(L"Test", 15);
    gaynigger[L"gayy"];
    _setmode(_fileno(stdout), _O_U16TEXT);
    wifstream file(filename);
    wstring s;
    size_t NumSpace;
    while (getline(file, s))
    {
        NumSpace = std::count(s.begin(), s.end(), ' ');
        switch (NumSpace)
        {
        case 0:
            stopwords.insert(s);
            break;
        case 1:
            stopwords1.insert(s);
            break;
        case 2:
            stopwords2.insert(s);
            break;
        case 3:
            stopwords3.insert(s);
            break;           
        };
    };
    //std::cout << "stopwords contains: ";
    //for (const std::wstring& x : stopwords) std::wcout << x << "\n";
};
void generate_hash(const char filename[])
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    wifstream file(filename);
    wstring s;
    size_t NumSpace;
    unsigned long int hash_size = 0;
    std::unordered_set<unsigned long int> gay1;
    std::unordered_set<unsigned long int> gay2;
    std::unordered_set<unsigned long int> gay3;
    std::unordered_set<unsigned long int> gay4;
    while (getline(file, s))
    {
        hash_size = 0;
        //hash_size = (unsigned long int(s[0]) ^ 1);
        for (auto i = 0; i < s.length(); i++)
        {
            hash_size = hash_size * 17 + unsigned long int(s[i]);
        };
        //hash_size = hash_size % 4000000; //gooood
        hash_size = hash_size % 1000007;

        NumSpace = std::count(s.begin(), s.end(), ' ');
        switch (NumSpace)
        {
        case 0:
            if (gay1.find(hash_size) != gay1.end())
            {
                wcout << s << " " << hash_size << " FUCK NO\n";
                return;
            };
            gay1.insert(hash_size);
            break;
        case 1:
            if (gay2.find(hash_size) != gay2.end())
            {
                wcout << s << " " << hash_size << " FUCK NO\n";
                return;
            };
            gay2.insert(hash_size);
            break;
        case 2:
            if (gay3.find(hash_size) != gay3.end())
            {
                wcout << s << " " << hash_size << " FUCK NO\n";
                return;
            };
            gay3.insert(hash_size);
            break;
        case 3:
            if (gay4.find(hash_size) != gay4.end())
            {
                wcout << s << " " << hash_size << " FUCK NO\n";
                return;
            };
            gay4.insert(hash_size);
            break;
        };

        wcout << s << " " << hash_size << "\n";
    };
};
string WstringToString(wstring wStr)
{
    std::string Str;
    std::transform(wStr.begin(), wStr.end(), std::back_inserter(Str), [](wchar_t c) {
        return (char)c;
        });
    return Str;
};
wstring StringToWstring(string Str)
{
    std::wstring wStr;
    std::transform(Str.begin(), Str.end(), std::back_inserter(wStr), [](char c) {
        return (wchar_t)c;
        });
    return wStr;
};
bool IllegalChar(wchar_t c)
{
    //if (IllegalCharSet.find(c) == IllegalCharSet.end())
    if (!IllegalCharSet.find(c))
        return false;
    else
        return true;
}
wstring cleanWstring(wstring& a)
{
    int i = 0;
    int len = a.length();
    if (IllegalChar(a[i])) a.replace(i, 1, L" ");
    i = 1;
    while (i < len)
    {
        if (IllegalChar(a[i]))
        {
             a.replace(i, 1, L" ");
        } else i++;
        //i++; //testing speed

        if ((a[i] == ' ') && (a[i - 1] == ' '))
        {
            a.replace(i - 1, 2, L" ");
            len--;
            i--;
        };
    };
    return a;
};
string inpString(string message)
{
    wcout << StringToWstring ( message);
    string s;
    getline(std::cin, s);
    //wcin >> s;
    return s;
};
wstring inpWstring(wstring message)
{
    wcout << message;
    wstring s;
    getline(std::wcin, s);
    return s;
};

std::wstring readFile(wstring path)
//https://vicidi.wordpress.com/2015/03/09/reading-utf-file-with-bom-to-utf-8-encoded-stdstring-in-c11-on-windows/
{
    std::string result;
    std::ifstream ifs(path.c_str(), std::ios::binary);
    std::stringstream ss;
    int encoding = ENCODING_ASCII;
    //if (mode == 1)
    //{
    //    if (!ifs.is_open()) {
    //        result.clear();
    //        return L"";
    //    }
    //    return L"gay";
    //};
    if (!ifs.is_open()) {
        // Unable to read file
        result.clear();
        return L"";
    }
    else if (ifs.eof()) {
        // Empty file
        result.clear();
    }
    else {
        int ch1 = ifs.get();
        int ch2 = ifs.get();
        if (ch1 == 0xff && ch2 == 0xfe) {
            // UTF-16LE BOM
            encoding = ENCODING_UTF16LE;
        }
        else if (ch1 == 0xfe && ch2 == 0xff) {
            // UTF-16BE BOM
            encoding = ENCODING_UTF16BE;
        }
        else {
            int ch3 = ifs.get();
            if (ch1 == 0xef && ch2 == 0xbb && ch3 == 0xbf) {
                // UTF-8 BOM
                encoding = ENCODING_UTF8;
            }
            else {
                encoding = ENCODING_ASCII;
                ifs.seekg(0);
            }
        }
    }
    ss << ifs.rdbuf() << '\0';
    if (encoding == ENCODING_UTF16LE) {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> utfconv;
        result = utfconv.to_bytes(std::wstring((wchar_t*)ss.str().c_str()));
    }
    else if (encoding == ENCODING_UTF16BE) {
        std::string src = ss.str();
        std::string dst = src;
        // Using Windows API
        _swab(&src[0u], &dst[0u], src.size() + 1);
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> utfconv;
        result = utfconv.to_bytes(std::wstring((wchar_t*)dst.c_str()));
    }
    else if (encoding == ENCODING_UTF8) {
        result = ss.str();
    }
    else {
        result = ss.str();
    }
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> utfconv;
    std::wstring utf16LeContent = utfconv.from_bytes(result);
    return utf16LeContent;
}

wstring fileWstring(wstring file_name)
{
    std::unordered_map<wchar_t, wchar_t> rs = {
        {L'Á',L'á'},{L'À',L'à'},{L'Ạ',L'ạ'},{L'Ả',L'ả'},{L'Ã',L'ã'},{L'Â',L'â'},{L'Ấ',L'ấ'},{L'Ầ',L'ầ'},{L'Ẩ',L'ẩ'},{L'Ẫ',L'ẫ'},
        {L'Ậ',L'ậ'},{L'Ă',L'ă'},{L'Ắ',L'ắ'},{L'Ằ',L'ằ'},{L'Ẳ',L'ẳ'},{L'Ẵ',L'ẵ'},{L'Ặ',L'ặ'},{L'É',L'é'},{L'È',L'è'},{L'Ẻ',L'ẻ'},
        {L'Ẽ',L'ẽ'},{L'Ẹ',L'ẹ'},{L'Ê',L'ê'},{L'Ế',L'ế'},{L'Ề',L'ề'},{L'Ệ',L'ệ'},{L'Ễ',L'ễ'},{L'Ể',L'ể'},{L'Ú',L'ú'},{L'Ù',L'ù'},
        {L'Ủ',L'ủ'},{L'Ũ',L'ũ'},{L'Ụ',L'ụ'},{L'Ư',L'ư'},{L'Ứ',L'ứ'},{L'Ừ',L'ừ'},{L'Ự',L'ự'},{L'Ử',L'ử'},{L'Ữ',L'ữ'},{L'Ó',L'ó'},
        {L'Ò',L'ò'},{L'Ỏ',L'ỏ'},{L'Õ',L'õ'},{L'Ọ',L'ọ'},{L'Ô',L'ô'},{L'Ố',L'ố'},{L'Ồ',L'ồ'},{L'Ổ',L'ổ'},{L'Ỗ',L'ỗ'},{L'Ộ',L'ộ'},
        {L'Ơ',L'ơ'},{L'Ớ',L'ớ'},{L'Ờ',L'ờ'},{L'Ợ',L'ợ'},{L'Ở',L'ở'},{L'Ỡ',L'ỡ'},{L'Í',L'í'},{L'Ì',L'ì'},{L'Ị',L'ị'},{L'Ỉ',L'ỉ'},
        {L'Ĩ',L'ĩ'},{L'Đ',L'đ'},{L'Ý',L'ý'},{L'Ỳ',L'ỳ'},{L'Ỷ',L'ỷ'},{L'Ỹ',L'ỹ'},{L'Ỵ',L'ỵ'},{L'Q',L'q'},{L'W',L'w'},{L'E',L'e'},
        {L'R',L'r'},{L'T',L't'},{L'Y',L'y'},{L'U',L'u'},{L'I',L'i'},{L'O',L'o'},{L'P',L'p'},{L'A',L'a'},{L'S',L's'},{L'D',L'd'},
        {L'F',L'f'},{L'G',L'g'},{L'H',L'h'},{L'J',L'j'},{L'K',L'k'},{L'L',L'l'},{L'Z',L'z'},{L'X',L'x'},{L'C',L'c'},{L'V',L'v'},
        {L'B',L'b'},{L'N',L'n'},{L'M',L'm'}
    };

    _setmode(_fileno(stdout), _O_U16TEXT);
    std::locale::global(std::locale("vi_VN.utf8"));
    std::setlocale(LC_ALL, "vi_VN.utf8");

    wstring s;
    s = readFile(file_name); 

   // wcout << L"S OG:\n" << s << "\n\n";
    cleanWstring(s);

    wchar_t r; //replacement
    std::replace_if(s.begin(), s.end(), [&](wchar_t c) { return (rs.find(c) != rs.end())
        && (r = rs[c]); }, r); //287 - 202 = 85s
    //wcout << L"S stopword removal:\n" << s << "\n\n";

    return s;
};


wstring StopwordRemove(wstring InputString)
{
    wstring result = InputString;
    //wcout << "Stopword remove: " << result << "\n";
    wstring word = L"";
    wstring word_2 = L"";
    wstring word_3 = L"";
    wstring word_4 = L"";
    wistringstream iss(InputString, wistringstream::in);
    unsigned int pos = 0;
    while (iss >> word)
    {
        pos = pos + word.length();

        if (stopwords3.find(word_4 + L' ' + word_3 + L' ' + word_2 + L' ' + word))
        {
            result.erase(pos - (word_4 + L' ' + word_3 + L' ' + word_2 + L' ' + word).length(), (word_4 + L' ' + word_3 + L' ' + word_2 + L' ' + word).length() + 1);
            pos -= (word_4 + L' ' + word_3 + L' ' + word_2 + L' ' + word).length();
            continue;
        };
        if (stopwords2.find(word_3 + L' ' + word_2 + L' ' + word))
        {
            result.erase(pos - (word_3 + L' ' + word_2 + L' ' + word).length(), (word_3 + L' ' + word_2 + L' ' + word).length() + 1);
            pos -= (word_3 + L' ' + word_2 + L' ' + word).length();
            continue;
        };
        if (stopwords1.find(word_2 + L' ' + word))
        {
            result.erase(pos - (word_2 + L' ' + word).length(), (word_2 + L' ' + word).length() + 1);
            pos -= (word_2 + L' ' + word).length();
            continue;
        };
        if (stopwords.find(word))
        {
            result.erase(pos - word.length(), word.length() + 1);
            pos -= word.length();
            continue;
        };

        word_4 = word_3;
        word_3 = word_2;
        word_2 = word;
        pos = pos+1;
    };
    //wcout << "Stopword remove: " << result << "\n";
    return result;
};
wstring dondep(wstring s)
{
    std::unordered_map<wchar_t, wchar_t> rs = {
        {L'Á',L'á'},{L'À',L'à'},{L'Ạ',L'ạ'},{L'Ả',L'ả'},{L'Ã',L'ã'},{L'Â',L'â'},{L'Ấ',L'ấ'},{L'Ầ',L'ầ'},{L'Ẩ',L'ẩ'},{L'Ẫ',L'ẫ'},
        {L'Ậ',L'ậ'},{L'Ă',L'ă'},{L'Ắ',L'ắ'},{L'Ằ',L'ằ'},{L'Ẳ',L'ẳ'},{L'Ẵ',L'ẵ'},{L'Ặ',L'ặ'},{L'É',L'é'},{L'È',L'è'},{L'Ẻ',L'ẻ'},
        {L'Ẽ',L'ẽ'},{L'Ẹ',L'ẹ'},{L'Ê',L'ê'},{L'Ế',L'ế'},{L'Ề',L'ề'},{L'Ệ',L'ệ'},{L'Ễ',L'ễ'},{L'Ể',L'ể'},{L'Ú',L'ú'},{L'Ù',L'ù'},
        {L'Ủ',L'ủ'},{L'Ũ',L'ũ'},{L'Ụ',L'ụ'},{L'Ư',L'ư'},{L'Ứ',L'ứ'},{L'Ừ',L'ừ'},{L'Ự',L'ự'},{L'Ử',L'ử'},{L'Ữ',L'ữ'},{L'Ó',L'ó'},
        {L'Ò',L'ò'},{L'Ỏ',L'ỏ'},{L'Õ',L'õ'},{L'Ọ',L'ọ'},{L'Ô',L'ô'},{L'Ố',L'ố'},{L'Ồ',L'ồ'},{L'Ổ',L'ổ'},{L'Ỗ',L'ỗ'},{L'Ộ',L'ộ'},
        {L'Ơ',L'ơ'},{L'Ớ',L'ớ'},{L'Ờ',L'ờ'},{L'Ợ',L'ợ'},{L'Ở',L'ở'},{L'Ỡ',L'ỡ'},{L'Í',L'í'},{L'Ì',L'ì'},{L'Ị',L'ị'},{L'Ỉ',L'ỉ'},
        {L'Ĩ',L'ĩ'},{L'Đ',L'đ'},{L'Ý',L'ý'},{L'Ỳ',L'ỳ'},{L'Ỷ',L'ỷ'},{L'Ỹ',L'ỹ'},{L'Ỵ',L'ỵ'},{L'Q',L'q'},{L'W',L'w'},{L'E',L'e'},
        {L'R',L'r'},{L'T',L't'},{L'Y',L'y'},{L'U',L'u'},{L'I',L'i'},{L'O',L'o'},{L'P',L'p'},{L'A',L'a'},{L'S',L's'},{L'D',L'd'},
        {L'F',L'f'},{L'G',L'g'},{L'H',L'h'},{L'J',L'j'},{L'K',L'k'},{L'L',L'l'},{L'Z',L'z'},{L'X',L'x'},{L'C',L'c'},{L'V',L'v'},
        {L'B',L'b'},{L'N',L'n'},{L'M',L'm'}
    };

    s = cleanWstring(s);
    wchar_t r;
    std::replace_if(s.begin(), s.end(), [&](wchar_t c) { return (rs.find(c) != rs.end())
        && (r = rs[c]); }, r);
    return s;
};
std::map<wstring, int> FeatureSelection(wstring InputString)
{
    //wcout << "input string: " << InputString << "\n";
    wstring word;
    wstring word_2 = L"";
    wstring word_3 = L"";
    wstring word_4 = L"";
    wistringstream iss(InputString, wistringstream::in);
    std::map<wstring, int> gay;
    //std::map<wstring, int> gay2;
    int*pairPointer;
    while (iss >> word)
    {
        //if (stopwords.find(word) != stopwords.end()) continue;
        gay[word]++;
        //std::wcout << "[word]" << word << "Gay [word]: " << gay[word] << "\n";
        pairPointer = &gay[word_2 + L' ' + word];
        (*pairPointer)++;
        //gay[word_2 + L' ' + word]++;
        if (*pairPointer > 1)
        {
            pairPointer = &gay[word_3 + L' ' + word_2 + L' ' + word];
            (*pairPointer)++;
            if (*pairPointer > 1)
            {
                gay[word_4 + L' ' + word_3 + L' ' + word_2 + L' ' + word]++;
            };
        };
        //gay[word_3 + L' ' + word_2 + L' ' + word]++;
        //gay[word_4 + L' ' + word_3 + L' ' + word_2 + L' ' + word]++;
        word_4 = word_3;
        word_3 = word_2;
        word_2 = word;
    };
    
    //long int count = 0;
    //wstring test;
    //for (auto it = gay.cbegin(); it != gay.cend(); ++it) {
    //    if ((*it).second > 1)
    //    {
    //        test = (*it).first;
    //        if (stopwords.find (test) == stopwords.end()) gay2.insert((*it));
    //        std::wcout << "{" << (*it).first << ": " << (*it).second << "}\n";
    //        count = count - 1;
    //    };
    //}

    //wcout << count << " NO \n";

    //for (auto it = gay2.cbegin(); it != gay2.cend(); ++it) {
    //        std::wcout << "{" << (*it).first << ": " << (*it).second << "}\n";
            //count = count + 1;
    //};
    //wcout << count << " YES \n";
    /* //OG, working.
    bool checkBreak = false;
    for (std::map<wstring, int>::iterator it = gay.begin(); it != gay.end(); ++it) {
        while (it->second < 3)
        {
            //wcout << "Test " << it->first;
            it = gay.erase(it);
            if (it == gay.end()) { checkBreak = true; break; };
            //wcout << "   " << it->first << "\n";
        };
        if (checkBreak) break;
    }
    return gay;
    */

    std::map<wstring, int> gay2;
    bool checkBreak = false;
    for (std::map<wstring, int>::iterator it = gay.begin(); it != gay.end(); ++it) {
        if (it->second > 2)
        {
            gay2.insert(*it);
        };
    }
    return gay2;

};
int ReadOneFile(std::map<wstring, std::map<wstring, int>>& FeatureMapList, wstring filename)
{
    wstring data = fileWstring(filename);
    data = StopwordRemove(data);
    FeatureMapList[filename] = FeatureSelection(data);
    return 0;
};
int FeatureMapListSave(std::map<wstring, std::map<wstring, int>> &FeatureMapList, wstring filename, int encoding = ENCODING_UTF8)
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::locale::global(std::locale("vi_VN.utf8"));
    std::setlocale(LC_ALL, "vi_VN.utf8");
    std::string result;
    std::wofstream ofs(filename, std::ios::binary);

    if (!ofs.is_open()) {
        // Unable to write file
        return 2;
    }
    else
    {
        for (const auto& p : FeatureMapList)
        {
            //std::wcout << p.first << std::endl;
            ofs << p.first<<",0\r\n";
            for (const auto& pp : p.second)
            {
                ofs << pp.first << "," << pp.second <<"\r\n";
            };

        };
    };
    return 0;
};
int FeatureMapListRead(std::map<wstring, std::map<wstring, int>>& FeatureMapList, wstring filename)
{
    wstring gay = readFile(filename);
    if (gay.empty()) return 1;
    wstring temp;
    wstring name;
    int temp2;
    wistringstream gayy (gay);
    std::map<wstring, int > FeatureMap;

    std::getline(gayy, name, L',');
    gayy >> temp2;
    std::getline(gayy, temp);
    while (gayy)
    {
        std::getline(gayy, temp, L',');
        gayy >> temp2;
        if (temp2 == 0)
        {
            FeatureMapList.insert({name, FeatureMap});
            FeatureMap.clear();
            name = temp;
        } else
        FeatureMap.insert({ temp, temp2 });
        std::getline(gayy, temp);
    };
    FeatureMapList.insert({ name, FeatureMap });
    FeatureMap.clear();
    return 0;
};
int Search(std::map<wstring, std::map<wstring, int>>& FeatureMapList, wstring KeyWord)
{
    wstring word = L"";
    wstring word_2 = L"";
    wstring word_3 = L"";
    wstring word_4 = L"";
    wistringstream iss(KeyWord, wistringstream::in);
    int count;
    int max = 0;
    //auto maxIndex;
    wstring maxIndex;
    for (const auto& p : FeatureMapList)
    {
        count = 0;
        iss.seekg(0);
        wstring word = L"";
        wstring word_2 = L"";
        wstring word_3 = L"";
        wstring word_4 = L"";
        while (iss >> word)
        {
            if (p.second.find(word) != p.second.end())
            {
                count += p.second.find(word)->second;
            };
            word_4 = word_3;
            word_3 = word_2;
            word_2 = word;
        };
        if (max < count)
        {
            max = count;
            maxIndex = p.first;
        };
    };
    wcout << "ket qua: " << maxIndex << "\n";
    return 0;
};