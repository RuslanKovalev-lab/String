#define _CRT_SECURE_NO_WARNINGS

#include "String.h"
#include "string.h"
#include "math.h"
#include "iostream"
using namespace std;

String::String()
{
    n = 1;
    arr = new char[1];
    arr[0] = 0;
}

String::String(const char* s)
{
    n = strlen(s) + 1;
    arr = new char[n];
    for (int i = 0; i < n - 1; i++)
        arr[i] = s[i];
    arr[n - 1] = 0;
}

String::String(const String& s)
{
    n = s.n;
    arr = new char[n];
    for (int i = 0; i < n; i++)
        arr[i] = s.arr[i];
}

String::~String()
{
    if (arr != 0)
    {
        delete[] arr;
        arr = 0;
        n = 0;
    }
}




char& String::GetChar(int i)
{
    if (i < n && i >= 0)
        return arr[i];
}

void String::SetChar(int i, char a)
{
    if (i < n && i >= 0)
        arr[i] = a;
}
int String::GetN()
{
    return n;
}

void String::SetN(int n)
{
    delete[] arr;
    this->n = n;
    arr = new char[n];
}




String String::operator+(const String& other)
{
    String str;
    str.n = this->n + other.n - 1;
    str.arr = new char[str.n];
    for (int i = 0; i < n - 1; i++)
        str.arr[i] = arr[i];
    for (int i = n - 1; i < str.n - 1; i++)
        str.arr[i] = other.arr[i - n + 1];
    str.arr[str.n - 1] = '\0';

    return str;
}

bool String::operator==(const String& other)
{
    if (n != other.n)
        return false;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] != other.arr[i])
            return false;
    return true;
}
bool String::operator>(const String& other)
{
    if (n > other.n)
        return true;
    return false;
}
bool String::operator<(const String& other)
{
    if (n < other.n)
        return true;
    return false;
}
String String::operator=(const String& other)
{
    if (this == &other)
        return *this;
    delete[] arr;
    this->n = other.n;
    this->arr = new char[other.n];
    for (int i = 0; i < n - 1; i++)
        arr[i] = other.arr[i];
    arr[n - 1] = 0;
    return *this;
}

char& String::operator[](int i)
{
    char o = NULL;
    if (i < n && i >= 0)
        return this->arr[i];
    return o;
}






ostream& operator<<(ostream& os, const String& str)
{
    os << str.arr;
    return os;
}

istream& operator>>(istream& in, String& str)
{
    char temp[256];
    in >> temp;
    String T(temp);
    str = T;
    return in;
}








int String::FindChar(char c)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == c)
            return i;
    return -1;
}


int String::Find(String& s)
{
    bool f = true;

    for (int i = 0; i < n; i++)
    {
        f = true;
        for (int j = 0; j < s.n - 1; j++)
            if (arr[i + j] != s.arr[j])
            {
                f = false;
                break;
            }
        if (f)
            return i;
    }
    return -1;
}


String* String::Strtok(const char* c)
{
    int k = 0;
    String temp = *this;
    char* token = strtok(temp.arr, c);
    while (token)
    {
        k++;
        token = strtok(NULL, c);
    }


    temp = *this;
    token = strtok(temp.arr, c);
    String* result = new String[k];

    for (int i = 0; i < k; i++)
    {
        result[i] = token;
        token = strtok(NULL, c);
    }
    return result;
}

 String String::Dublicate(int k)
{
    String b=arr;
    String a = arr;
    for (int i = 0; i < k; i++)
    {
        a = a + b;
    }
    return a;
}

void String::FindPodstr(String s)
{
    bool f = true;

    for (int i = 0; i < n; i++)
    {
        f = true;
        for (int j = 0; j < s.n - 1; j++)
            if (arr[i + j] != s.arr[j])
            {
                f = false;
                break;
            }
        if (f)
            cout<<i<<" ";
    }
    cout << endl;
}
char String::Poisk()
{
    int max = 0;
    String b = arr;
    char a=b[0];
    for (int i = 0; i < b.n; i++)
    {
        int count = 0;
        for (int j = i; j < b.n; j++)
        {
            if (b[i] == b[j]) count++;
        }
        if (count > max) {
            max = count;
            a = b[i];
        }
    }
    return a;
}

void String::Set()
{
    String a=arr;
    cout << a.n;
    cout << a[0]<<" ";
    int count = 1;
    for (int i = 1; i < a.n; i++)
    {
        bool good = true;
        for (int j = 0; j < i; j++)
        {
            if (a[j] == a[i]) good = false;
        }

        if (good)
        {
            count++;
            cout << a[i] << " ";
        }
    }
}