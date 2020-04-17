#include "MyString.h"

namespace zetwhite{

int MyString::GetCapacity(const int length) const{
    if(length < 0)
        throw std::invalid_argument("length must be positive or zero");
    int newCapacity = 16;
    while(newCapacity <= length){
        newCapacity = newCapacity << 1;
        if(newCapacity > max)
            throw std::out_of_range("is out of string capacity");
    }
    return newCapacity-1;
}

MyString::MyString()
    :_capacity(15), _length(0){
    _string = new char[_capacity+1];
    _string[_length] = _nullchar;
}

MyString::MyString(const MyString& other)
    :_capacity(other._capacity), _length(other._length){
    _string = new char[_capacity+1];
    for(int i = 0; i < _length; i++)
        _string[i] = other._string[i];
    _string[_length] = _nullchar;
}

MyString::MyString(const char* str){
    int length = 0;
    while(str[length]!=_nullchar)
        length++;
    _length = length;
    _capacity = GetCapacity(length);
    _string = new char[_capacity+1];
    for(int i = 0; i < _length; i++)
        _string[i] = str[i];
    _string[_length] = _nullchar;
}

MyString::MyString(const int capacity)
    :_capacity(capacity), _length(0){
    _string = new char[_capacity+1];
    _string[_length] = 0;
}

MyString::~MyString(){
    delete[] _string;
}

char MyString::At(const int index) const{
    if(index > _length)
        throw std::out_of_range("index is out of range");
    return _string[index];
}

int MyString::Capacity() const{
    return _capacity;
}

int MyString::Length() const{
    return _length;
}

const char* MyString::c_str() const{
    return _string;
}

void MyString::Clear(){
    if(_capacity > 15){
        delete _string;
        _capacity = 15;
        _string = new char[_capacity+1];
    }
    _length = 0;
}

void MyString::Append(const MyString& other){
    if(_length+other._length > _capacity){
        _capacity = GetCapacity(_length);
        char* newString = new char[_capacity+1];
        for(int i = 0; i < _length; i++){
            newString[i] = _string[i];
        }
        delete[] _string;
        _string = newString;
    }
    for(int i = 0; i < other._length; i++){
        _string[_length + i] = other._string[i];
    }
    _length+= other._length;
    _string[_length] = _nullchar;
}

int MyString::Compare(const MyString& other) const{
    int idx = 0;
    while(_string[idx] == other._string[idx]){
        idx++;
        if(_string[idx] == _nullchar || other._string[idx] == _nullchar)
            break;
    }
    if(_string[idx] < other._string[idx])
        return -1;
    else if (_string[idx] == other._string[idx])
        return 0;
    else
        return 1;
}

int MyString::Find(const MyString& pattern) const{
    int idx = 0, p = 0;
    for(idx = 0; idx < _length-pattern._length; idx++){
        for(p = 0; p < pattern._length; p++){
            if(_string[idx+p] != pattern._string[p])
                break;
        }
        if(p == pattern._length)
            return idx;
    }
    return -1;
}

MyString MyString::Substr(int startIdx, int size) const{
    MyString newString(size);
    for(int i = startIdx; i < startIdx + size; i++){
        newString[i - startIdx] = _string[i];
    }
    return newString;
}

char& MyString::operator[] (int index){
    if(index > _length)
        throw std::out_of_range("inde is out of range");
    return _string[index];
}

MyString MyString::operator= (const MyString& rhs){
    delete[] _string;
    _capacity = rhs._capacity;
    _length = rhs._length;
    _string = new char[_capacity+1];
    for(int i = 0; i < _length; i++){
        _string[i] = rhs._string[i];
    }
    _string[_length] = _nullchar;
    return *this;
}

MyString MyString::operator= (const char* str){
    delete[] _string;
    int length = 0;
    while(str[length]!=_nullchar)
        length++;
    _length = length;
    _capacity = GetCapacity(length);
    _string = new char[_capacity+1];
    for(int i = 0; i < _length; i++)
        _string[i] = str[i];
    _string[_length] = _nullchar;
    return *this;
}

MyString MyString::operator+(const MyString& rhs){
    MyString newString(_length + rhs._length);
    newString = *this;
    newString.Append(rhs);
    return newString;
}

MyString& MyString::operator+=(const MyString& rhs){
    Append(rhs);
    return *this;
}

bool MyString::operator== (const MyString& rhs) const{
    if(_length != rhs._length)
        return false;
    for(int i = 0; i < _length; i++){
        if(_string[i] != rhs._string[i])
            return false;
    }
    return true;
}

ostream& operator << (ostream& os, const MyString& str){
    for(int i = 0; i < str.Length(); i++){
         os << str._string[i];
    }
    return os;
}

istream& operator >> (istream& is, MyString& str){
    delete[] str._string;
    char buff[str.max];
    int idx = 0;
    while(!is.eof()){
        is.get(buff[idx]);
        if(is.bad()){
            throw std::runtime_error("bad input for string");
        }
        if(buff[idx] == str._nullchar || buff[idx] == ' ' || buff[idx] == '\n')
            break;
        idx++;
        if(idx >= str.max){
            throw std::out_of_range("string length is out of string max capacity");
        }
    }
    str._capacity = str.GetCapacity(idx);
    str._length = idx;
    str._string = new char[str._capacity + 1];
    for(int i = 0; i < str._length; i++){
        str._string[i] = buff[i];
    }
    str._string[str._length] = str._nullchar;
    return is;
}

}
