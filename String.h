#pragma once  
#include <iostream>
using namespace std;
class String
{
protected:
    char* arr;
    int n;
public:
    String();
    String(const char* s);
    String(const String& s);
    ~String();

    int GetN();
    void SetN(int n);
    char& GetChar(int i);
    void SetChar(int i, char a);

    String operator +(const String& other);
    bool operator ==(const String& other);
    bool operator >(const String& other);
    bool operator <(const String& other);
    String operator =(const String& other);
    char& operator [](int i);


    friend ostream& operator<<(ostream& os, const String& str);
    friend istream& operator>>(istream& in, String& str);

    int FindChar(char c);
    int Find(String& s);
    String* Strtok(const char* c);

    String Dublicate(int k);

    void FindPodstr(String a);

    char Poisk();

    void Set();
};