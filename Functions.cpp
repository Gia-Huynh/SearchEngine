#include "Header.h"

using namespace OurFunkyLibrary;

wchar_t NotLegalW[] = {L'\r', L'\n', '~','`','!','@','#','$','%','^','&','*','(',')','-','_','+','=','[',']','{','}','|','\\',';',':','\'','\"',',','<','.','>','/','?' };
int len = sizeof(NotLegalW) / sizeof(wchar_t);

unsigned long int hashFunction(wchar_t s)
{
    return unsigned long int(s);
};
    
unsigned long int hashFunction(wstring s)
{
    unsigned long int hash_size = 0;
    //hash_size = (unsigned long int(s[0]) ^ 1);
    for (auto i = 0; i < s.length(); i++)
    {
        hash_size = hash_size * 17 + unsigned long int(s[i]);
    };
    //hash_size = hash_size % 4000000; //gooood
    hash_size = hash_size % 204601; //gooood
    return hash_size;
};
/*
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
*/


/*
template <class T>
class unordered_set
{
public:
    T element;

private:
    int top;
    T* nigger = new T[204601] ();

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
        unsigned long int index = hashFunction(newElement);
        //wcout << "Old value: " << nigger[index] << " New value: " << newElement << "\n";
        //if (strlen(nigger[index]) != 0) wcout << "Hash table error! Old value: "<< nigger[index] << " New value: " << newElement << "\n";
        nigger[index] = newElement;
    };

    int find(T findElement)
    {
        unsigned long int index = hashFunction(findElement);
        //if (strlen(&nigger[index]) == 0) return 0;
        //if (nigger[index] == 0) return 0;
        if (nigger[index] == findElement) return 1;
        //wcout << "\n" << nigger[index] << " " << findElement << "\n";
        return 0;
    };
    void clean()
    {
        delete[] T;
    };
};
*/


/*template <class T, class U>
class wtf_map
{
public:

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
*/

template <class T, class U>
class unordered_map
{
public:

private:
    T* nigger = new T[204601]();
    U* nigger2 = new U[204601]();

public:
    unordered_map()
    {
    };
    void operator = (const std::initializer_list<std::pair <T, U>> &faggot)
    {
        for (auto i = faggot.begin(); i != faggot.end(); i++)
        {
            insert(i->first, i->second);
        };
    };
    U operator [] (const T gayy)
    {
        unsigned long int index = hashFunction(gayy);
        return nigger2[index];
    };
    void insert(T newElement, U newKey)
    {
        unsigned long int index = hashFunction(newElement);
        nigger[index] = newElement;
        nigger2[index] = newKey;
    };

    int find(T findElement)
    {
        unsigned long int index = hashFunction(findElement);
        if (nigger[index] == findElement) return 1;
        return 0;
    };
    int end()
    {
        return 0;
    };
    void clean()
    {
        delete[] T;
        delete[] U;
    };
};

unordered_set<std::wstring> stopwords;
unordered_set<std::wstring> stopwords1;
unordered_set<std::wstring> stopwords2;
unordered_set<std::wstring> stopwords3;
unordered_set<wchar_t> IllegalCharSet(NotLegalW, NotLegalW + sizeof(NotLegalW) / sizeof(wchar_t));
unordered_map<wchar_t, wchar_t> rs;

void ReadStopWords(const char filename[])
{
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

    rs = {
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

    file.clear();
    file.seekg(0);
    while (getline(file, s))
    {
        NumSpace = std::count(s.begin(), s.end(), ' ');
        switch (NumSpace)
        {
        case 0:
            if (!stopwords.find(s)) wcout << "found it " << s << "\n";
            break;
        case 1:
            if (!stopwords1.find(s)) wcout << "found it " << s << "\n";
            break;
        case 2:
            if (!stopwords2.find(s)) wcout << "found it " << s << "\n";
            break;
        case 3:
            if (!stopwords3.find(s)) wcout << "found it " << s << "\n";
            break;
        };
    };

    //std::cout << "stopwords contains: ";
    //for (const std::wstring& x : stopwords) std::wcout << x << "\n";
};
void generate_hash(const char filename[])
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    //wifstream file(filename);
    wstring s;
    size_t NumSpace;
    unsigned long int hash_size = 0;
    int niggerr[600] = { 200513,200569,200573,200579,200587,200591,200597,200609,200639,200657,200671,200689,200699,200713,200723,200731,200771,200779,200789,200797,200807,200843,200861,200867,200869,200881,200891,200899,200903,200909,200927,200929,200971,200983,200987,200989,201007,201011,201031,201037,201049,201073,201101,201107,201119,201121,201139,201151,201163,201167,201193,201203,201209,201211,201233,201247,201251,201281,201287,201307,201329,201337,201359,201389,201401,201403,201413,201437,201449,201451,201473,201491,201493,201497,201499,201511,201517,201547,201557,201577,201581,201589,201599,201611,201623,201629,201653,201661,201667,201673,201683,201701,201709,201731,201743,201757,201767,201769,201781,201787,201791,201797,201809,201821,201823,201827,201829,201833,201847,201881,201889,201893,201907,201911,201919,201923,201937,201947,201953,201961,201973,201979,201997,202001,202021,202031,202049,202061,202063,202067,202087,202099,202109,202121,202127,202129,202183,202187,202201,202219,202231,202243,202277,202289,202291,202309,202327,202339,202343,202357,202361,202381,202387,202393,202403,202409,202441,202471,202481,202493,202519,202529,202549,202567,202577,202591,202613,202621,202627,202637,202639,202661,202667,202679,202693,202717,202729,202733,202747,202751,202753,202757,202777,202799,202817,202823,202841,202859,202877,202879,202889,202907,202921,202931,202933,202949,202967,202973,202981,202987,202999,203011,203017,203023,203039,203051,203057,203117,203141,203173,203183,203207,203209,203213,203221,203227,203233,203249,203279,203293,203309,203311,203317,203321,203323,203339,203341,203351,203353,203363,203381,203383,203387,203393,203417,203419,203429,203431,203449,203459,203461,203531,203549,203563,203569,203579,203591,203617,203627,203641,203653,203657,203659,203663,203669,203713,203761,203767,203771,203773,203789,203807,203809,203821,203843,203857,203869,203873,203897,203909,203911,203921,203947,203953,203969,203971,203977,203989,203999,204007,204013,204019,204023,204047,204059,204067,204101,204107,204133,204137,204143,204151,204161,204163,204173,204233,204251,204299,204301,204311,204319,204329,204331,204353,204359,204361,204367,204371,204377,204397,204427,204431,204437,204439,204443,204461,204481,204487,204509,204511,204517,204521,204557,204563,204583,204587,204599,204601,204613,204623,204641,204667,204679,204707,204719,204733,204749,204751,204781,204791,204793,204797,204803,204821,204857,204859,204871,204887,204913,204917,204923,204931,204947,204973,204979,204983,205019,205031,205033,205043,205063,205069,205081,205097,205103,205111,205129,205133,205141,205151,205157,205171,205187,205201,205211,205213,205223,205237,205253,205267,205297,205307,205319,205327,205339,205357,205391,205397,205399,205417,205421,205423,205427,205433,205441,205453,205463,205477,205483,205487,205493,205507,205519,205529,205537,205549,205553,205559,205589,205603,205607,205619,205627,205633,205651,205657,205661,205663,205703,205721,205759,205763,205783,205817,205823,205837,205847,205879,205883,205913,205937,205949,205951,205957,205963,205967,205981,205991,205993,206009,206021,206027,206033,206039,206047,206051,206069,206077,206081,206083,206123,206153,206177,206179,206183,206191,206197,206203,206209,206221,206233,206237,206249,206251,206263,206273,206279,206281,206291,206299,206303,206341,206347,206351,206369,206383,206399,206407,206411,206413,206419,206447,206461,206467,206477,206483,206489,206501,206519,206527,206543,206551,206593,206597,206603,206623,206627,206639,206641,206651,206699,206749,206779,206783,206803,206807,206813,206819,206821,206827,206879,206887,206897,206909,206911,206917,206923,206933,206939,206951,206953,206993,207013,207017,207029,207037,207041,207061,207073,207079,207113,207121,207127,207139,207169,207187,207191,207197,207199,207227,207239,207241,207257,207269,207287,207293,207301,207307,207329,207331,207341,207343,207367,207371,207377,207401,207409,207433,207443,207457,207463,207469,207479,207481,207491,207497,207509,207511,207517,207521,207523,207541,207547,207551,207563,207569,207589,207593,207619,207629,207643,207653,207661,207671,207673,207679,207709,207719,207721,207743,207763,207769,207797,207799,207811,207821,207833,207847,207869,207877 
    };
    for (int i = 0; i < 599; i++)
    {
        wifstream file(filename);
        std::unordered_set<unsigned long int> gay1;
        std::unordered_set<unsigned long int> gay2;
        std::unordered_set<unsigned long int> gay3;
        std::unordered_set<unsigned long int> gay4;
        bool check = true;
        while (getline(file, s))
        {
            if (check == false) break;
            hash_size = 0;
            //hash_size = (unsigned long int(s[0]) ^ 1);
            for (auto j = 0; j < s.length(); j++)
            {
                hash_size = hash_size * 17 + unsigned long int(s[j]);
            };
            //hash_size = hash_size % 4000000; //gooood
            //hash_size = hash_size % 1000007; //gooood too
            //hash_size = hash_size % 500009; //gooood
            // 204601 gud, perhaps
            hash_size = hash_size % niggerr [i]; //gooood

            NumSpace = std::count(s.begin(), s.end(), ' ');
            switch (NumSpace)
            {
            case 0:
                if (gay1.find(hash_size) != gay1.end())
                {
                    //wcout << s << " " << hash_size << " FUCK NO\n";
                    check = false; break;
                    return;
                };
                gay1.insert(hash_size);
                break;
            case 1:
                if (gay2.find(hash_size) != gay2.end())
                {
                    //wcout << s << " " << hash_size << " FUCK NO\n";
                    check = false; break;
                    return;
                };
                gay2.insert(hash_size);
                break;
            case 2:
                if (gay3.find(hash_size) != gay3.end())
                {
                    //wcout << s << " " << hash_size << " FUCK NO\n";
                    check = false; break;
                    return;
                };
                gay3.insert(hash_size);
                break;
            case 3:
                if (gay4.find(hash_size) != gay4.end())
                {
                    //wcout << s << " " << hash_size << " FUCK NO\n";
                    check = false; break;
                    return;
                };
                gay4.insert(hash_size);
                break;
            };

            //wcout << s << " " << hash_size << "\n";
        };
        file.close();
        if (check == true) wcout << "\nFOUND IT " << niggerr[i] << "\n"; else wcout << i << " ";
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
    /*
    std::unordered_map<wchar_t, wchar_t> rs;
    rs = {
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
    };*/

    s = cleanWstring(s);
    wchar_t r;
    std::replace_if(s.begin(), s.end(), [&](wchar_t c) { return (rs.find(c) != rs.end())
        && (r = rs[c]); }, r);
    return s;
};
wtf_map<wstring, int> FeatureSelection(wstring InputString)
{
    //wcout << "input string: " << InputString << "\n";
    wstring word;
    wstring word_2 = L"";
    wstring word_3 = L"";
    wstring word_4 = L"";
    wistringstream iss(InputString, wistringstream::in);
    std::map<wstring, int> gay;
    //wtf_map<wstring, int> gay2;
    int*pairPointer;
    while (iss >> word)
    {
        //if (stopwords.find(word) != stopwords.end()) continue;
        //(*gay[word])++;
        gay[word]++;
        //std::wcout << "[word]" << word << "Gay [word]: " << gay[word] << "\n";
        if (word_2 == L"") {
            word_2 = word; continue;
        }
        pairPointer = &gay[word_2 + L' ' + word];
        (*pairPointer)++;
        //gay[word_2 + L' ' + word]++;
        if (*pairPointer > 1)
        {
            pairPointer = &gay[word_3 + L' ' + word_2 + L' ' + word];
            (*pairPointer)++;
            if (*pairPointer > 1)
            {
                (gay[word_4 + L' ' + word_3 + L' ' + word_2 + L' ' + word])++;
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
    for (wtf_map<wstring, int>::iterator it = gay.begin(); it != gay.end(); ++it) {
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

    wtf_map<wstring, int> gay2;
    bool checkBreak = false;
    for (auto it = gay.begin(); it != gay.end(); ++it) {
        if (it->second > 2)
        {
            gay2.insert(*it);
        };
    };

    /*
    for (std::pair<wstring, int>* it = gay.begin(); it != gay.end(); ++it) {
        if (it->second > 2)
        {
            gay2.insert(*it);
        };
    }*/
    return gay2;

};
int ReadOneFile(wtf_map<wstring, wtf_map<wstring, int>>& FeatureMapList, wstring filename)
{
    wstring data = fileWstring(filename);
    data = StopwordRemove(data);
    (*FeatureMapList[filename]) = FeatureSelection(data);
    return 0;
};
int FeatureMapListSave(wtf_map<wstring, wtf_map<wstring, int>> &FeatureMapList, wstring filename, int encoding = ENCODING_UTF8)
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
        for (auto& p : FeatureMapList)
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
int FeatureMapListRead(wtf_map<wstring, wtf_map<wstring, int>>& FeatureMapList, wstring filename)
{
    wstring gay = readFile(filename);
    if (gay.empty()) return 1;
    wstring temp;
    wstring name;
    int temp2;
    wistringstream gayy (gay);
    wtf_map<wstring, int > FeatureMap;

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
/*
int Search(wtf_map<wstring, wtf_map<wstring, int>>& FeatureMapList, wstring KeyWord)
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
    for (auto& p : FeatureMapList)
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
*/