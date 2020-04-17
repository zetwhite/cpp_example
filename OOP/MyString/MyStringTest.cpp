#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    zetwhite::MyString greeting("hello world!");
    for(int i = 0; i < greeting.Length(); i++)
        cout << greeting.At(i) << ", ";
    cout << endl;
    for(int i = 0; i < greeting.Length(); i++)
        cout << greeting[i] << ". ";
    cout << endl;


    zetwhite::MyString name;
    cout << "What is Your name? ";
    cin >> name;
    greeting = "My name is ";
    greeting += name;
    cout << greeting << endl;

    zetwhite::MyString pattern("admin");
    int a= greeting.Find(pattern);
    if(a == -1){
        cout << "well you are not " << pattern << endl;
    }
    else{
        cout <<"hi," << name << endl;
    }

    cout << "=== longStringTest === " << endl;
    zetwhite::MyString longString = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    cout << "length : " << longString.Length() << endl;
    cout << "capacity : " << longString.Capacity() << endl;
    cout << longString << endl;
    return 0;
}
