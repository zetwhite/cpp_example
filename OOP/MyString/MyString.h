#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

#include <iostream>
#include <stdexcept>
using std::ostream;
using std::istream;

namespace zetwhite{

class MyString{
private:
    const static char _nullchar = '\0';
    const static int max = 10000;
    int _capacity;
    int _length;
    char* _string;
    int GetCapacity(const int length) const;
public:
    MyString();
    MyString(const MyString& other);
    MyString(const char* str);
    MyString(const int capacity);
    ~MyString();

    char At(const int index) const;
    int Capacity() const;
    int Length() const;
    const char* c_str() const;
    void Clear();
    void Append(const MyString& other);
    int Compare(const MyString& other) const;
    int Find(const MyString& pattern) const;
    MyString Substr(int startIdx, int size) const;

    MyString operator= (const MyString& rhs);
    MyString operator= (const char* str);
    MyString operator+ (const MyString& rhs);
    MyString& operator+= (const MyString& rhs);
    bool operator== (const MyString& rhs) const;
    char& operator[] (int index);
    friend ostream& operator << (ostream& os, const MyString& str);
    friend istream& operator >> (istream& is, MyString& str);
};

}

#endif // MYSTRING_H_INCLUDED
