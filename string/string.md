# string 
String is a object that manages sequences of characters.\
String is a not basic type in C++, but is in Standard Library facility.\
So, Appropriate header and namespace std must be stated.
```cpp
#include <string>
using namespace std;
```
C++ string is useful. Because we don't need to worry about length of characters,  unlikely in C.\
Also, it is easy to use with basic operators and member functions. 

## input and output
`operator <<` and `operator >>` are overloaded.\
or `getline(input, str, delim='\n')` function can be used.\
In getline function, \
&nbsp;&nbsp;&nbsp;&nbsp;`input parameter` is the stream to get data from.\
&nbsp;&nbsp;&nbsp;&nbsp;`str parameter` is the string to put data into.\
&nbsp;&nbsp;&nbsp;&nbsp;`delim parameter` is the character to set the end of input. the function works until it meets the delim character.  
```cpp
cout << "input your name : ";
string name;
cin >> name; 

cout << "input your email : "
string emailHeader; 
geline(cin, emailHeader, '@');
```

## operators
- assign  
```cpp
string a = "hello";
string b = a;
```
- concatenate and append  
```cpp
string greeting1 = "hello";
string greeting2 = "world";
string greeting = greeting1 + " " + greeting2;
greeting += "!";
```
- compare   
Compare operations are overloaded and do appropriate comparison.\
`==` and `!=` return `true` if two character arrays in string objects are exactly matched.  
`<`, `>`, `<=` and  `>=` compare lexicographical order of string.\
but, `!=`,  `<`, `>`, `<=` and  `>=` are removed in c++20.
```cpp
string a = 'abc';
string b = 'abc';
if( a == b ) 
	cout << "a and b are same!" << endl; 

string A = 'a';
string B = 'b';
if( a < b ) 
	cout << "a is less than b" << endl; //printed
A = 'ab';
B = 'ac';
if( a < b )
	cout << "a is less than b" << endl; //printed
```
## member function 
- size and length   
`size()` and `length()` returns the number of characters.\
Since the number of characters is cached in string object, `size()` and `length()` both take constant time.
```cpp
string a = "hello";
cout << a.size() << " " << a.length() << endl; //5 5 
``` 
- access strings  
with `[]` or `at()`, we can access a character in a string object.
```cpp
string a = "hello";
cout << a[0] << ", " << a.at(0) << endl; //h, h 

a[0] = 'H';
cout << a << endl; //Hello 

a.at(4) = 'O';
cout << a << endl; //HellO
``` 
- c_str  
`c_str()` returns a pointer to const char of character array that is in string object.\
it means by using `c_str()`, we can convert string to null terminated character array which is a C-style. 
```cpp
string greeting = "Hello";
const char* hi = greeting.c_str();
int idx = 0;
while(hi[idx] != '\0'){
    cout << hi[idx++];
}
```

- capacity and resize   
`capacity()` returns the size of allocated memory for character array in string object.\
if more memory is needed, the new larger memory is newly allocated and whole past memory is copied to new one.
`reserve()` sets the size of allocated memory.\
if we know how many memory is needed, it can be used to prevent inefficient newly allocating and copying process.
```cpp
string greeting = "hello";
cout << "capacity : " << greeting.capacity() << endl; //15
greeting.reserve(100);
cout << "capacity : " << greeting.capacity() << endl; //100
```
