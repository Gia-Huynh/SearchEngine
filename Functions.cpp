#include "Header.h"

wchar_t NotLegalW[] = {'\r', '~','`','!','@','#','$','%','^','&','*','(',')','-','_','+','=','[',']','{','}','|','\\',';',':','\'','\"',',','<','.','>','/','?' };
int len = sizeof(NotLegalW) / sizeof(wchar_t);
char NotLegal[] = { '\r',  '~','`','!','@','#','$','%','^','&','*','(',')','-','_','+','=','[',']','{','}','|','\\',';',':','\'','\"',',','<','.','>','/','?' };
std::unordered_set<std::wstring> stopwords;

void ReadStopWords(const char filename[])
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    wifstream file(filename);
    wstring s;
    while (getline(file, s))
        stopwords.insert(L" " + s + L" ");
    //std::cout << "stopwords contains: ";
    //for (const std::wstring& x : stopwords) std::wcout << x << "\n";
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
            //a.erase(i, 1);
            //len--;
            a.replace(i, 1, L" ");
        }
            i++;
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

wstring fileWstring(string file_name)
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    locale::global(locale("vi_VN.utf8"));
    std::setlocale(LC_ALL, "vi_VN.utf8");

    wstring s;
    s = readFile(file_name);
    //wcout << L"S OG:\n" << s << "\n\n";
    s = cleanWstring(s);
    //wcout << L"S cleanWstring:\n" << s << "\n\n";

    while (s.find(L"\n") < s.length()) { 
        s.replace(s.find(L"\n"), 1, L" ");
    };
    //wcout << L"S replace \\n:\n" << s << "\n\n";

    while (s.find(L"  ") < s.length()) { s.replace(s.find(L"  "), sizeof(L" ") - 2, L" "); };
    //wcout << L"S remove double space:\n" << s << "\n\n";



    wchar_t r; //replacement
    std::map<wchar_t, wchar_t> rs = {
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
    std::replace_if(s.begin(), s.end(), [&](wchar_t c) { return (rs.find(c) != rs.end())
        && (r = rs[c]); }, r);

    //wcout << L"S lowercase (working?):\n" << s << "\n\n";
    //stopword removal
    size_t pos;
    for (const auto& elem : stopwords) {
        pos = 0;
        while ((pos = s.find(elem, pos)) != std::wstring::npos) {
            s.erase(pos, elem.length()-1);
            pos += elem.length()-1;
        }
    }

    //wcout << L"S stopword removal:\n" << s << "\n\n";
    return s;
};


/*
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