#include "Header.h"

wchar_t NotLegalW[] = {'\r', '\n' , '~','`','!','@','#','$','%','^','&','*','(',')','-','_','+','=','[',']','{','}','|','\\',';',':','\'','\"',',','<','.','>','/','?' };
int len = sizeof(NotLegalW) / sizeof(wchar_t);
char NotLegal[] = { '\r', '\n',  '~','`','!','@','#','$','%','^','&','*','(',')','-','_','+','=','[',']','{','}','|','\\',';',':','\'','\"',',','<','.','>','/','?' };

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
    //wchar_t NotLegal[] = { '~','`','!','@','#','$','%','^','&','*','(',')','-','_','+','=','[',']','{','}','|','\\',';',':','\'','\"',',','<','.','>','/','?'};
    //int len = sizeof(NotLegal) / sizeof(wchar_t);

    for (int i = 0; i < len; i++)
        if (c == NotLegalW[i])
            return true;
    return false;
}
wstring cleanWstring(wstring a)
{
    int i = 0;
    int len = a.length();
    while (i < len)
    {
        if (IllegalChar(a[i]))
        {
            a.erase(i, 1);
            len--;
        }
        else
        {
            i++;
        };
    };
    return a;
};
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

#define ENCODING_ASCII      0
#define ENCODING_UTF8       1
#define ENCODING_UTF16LE    2
#define ENCODING_UTF16BE    3



std::wstring readFile(string path)
//https://vicidi.wordpress.com/2015/03/09/reading-utf-file-with-bom-to-utf-8-encoded-stdstring-in-c11-on-windows/
{
    std::string result;
    std::ifstream ifs(path.c_str(), std::ios::binary);
    std::stringstream ss;
    int encoding = ENCODING_ASCII;

    if (!ifs.is_open()) {
        // Unable to read file
        result.clear();
        return L"";
    }
    else if (ifs.eof()) {
        result.clear();
    }
    else {
        int ch1 = ifs.get();
        int ch2 = ifs.get();
        if (ch1 == 0xff && ch2 == 0xfe) {
            // The file contains UTF-16LE BOM
            encoding = ENCODING_UTF16LE;
        }
        else if (ch1 == 0xfe && ch2 == 0xff) {
            // The file contains UTF-16BE BOM
            encoding = ENCODING_UTF16BE;
        }
        else {
            int ch3 = ifs.get();
            if (ch1 == 0xef && ch2 == 0xbb && ch3 == 0xbf) {
                // The file contains UTF-8 BOM
                encoding = ENCODING_UTF8;
            }
            else {
                // The file does not have BOM
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
    _setmode(_fileno(stdout), _O_U16TEXT);
    locale::global(locale("vi_VN.utf8"));
    wstring s;
    s = readFile(WstringToString(file_name));
    wcout << L"S OG:\n" << s << "\n\n";
    s = cleanWstring(s);
    wcout << L"S cleanWstring:\n" << s << "\n\n";

    //wcout << "LENGTH OF space: " << wstring(L" ").length() << "\n";
    return s;
    while (s.find(L"\n") < s.length()) { 
        //wcout << static_cast<int>(s.find(L"\n")) << " " << sizeof(L"\n")-1 << "\n" << s << "\n";
        s.replace(s.find(L"\n"), 1, L"T");
        wcout << L"AAAAAAAAAAAAAAAAAA:\n" << s << "\n\n";
    };
    //s.replace(s.find(L'\n'), 1, L"R");
    wcout << L"S replace \\n:\n" << s << "\n\n";

    while (s.find(L"  ") < s.length()) { s.replace(s.find(L"  "), sizeof(L" ") - 2, L" "); };
    wcout << L"S fucked:\n" << s << "\n\n";

    return s;
};


/*
string inpString(const char message[])
{
    printf(message);
    string s;
    getline(std::cin, s);
    //wcin >> s;
    return s;
};
bool IllegalChar(char c)
{
    for (int i = 0; i < len; i++)
        if (c == NotLegal[i])
            return true;
    return false;
}

string cleanString(string a)
{
    int i = 0;
    int len = a.length();
    while (i < len)
    {
        if (IllegalChar(a[i]))
        {
            a.erase(i, 1);
            len--;
        }
        else
        {
            i++;
        };
    };
    return a;
};
string fileString(const char file_name[])
{
    ifstream inFile;
    _setmode(_fileno(stdin), _O_U8TEXT);
    //_setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_U8TEXT);
    locale::global(locale("vi_VN.utf8"));
    //inFile.open(file_name);
    string s;
    std::ifstream t(file_name);
    std::stringstream buffer;
    buffer << t.rdbuf();
    s = cleanString(buffer.str());
    replace(s.begin(), s.end(), '\n', ' ');
    while (s.find("  ") < s.length()) { s.replace(s.find("  "), sizeof(" ") - 1, " "); };
    cout << "S:\n" << s << "\n\n";
    return s;
};
*/

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