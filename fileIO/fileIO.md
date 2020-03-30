# fileIO
We are going to handle how to read or write a file.  
To do this, `fstream` header must be included.  
```cpp
#include <fstream>
using namespace std;
```
There are 3 types of object for handling file stream.   
- ifstream : input file stream. this is used to read information from file. 
- ofstream : output file stream. this is used to create file or write infomation to file.
- fstream : this is general type for both ifstream and ofstream. this can be used for both reading and writing.

## file open and close 
File must be opened before reading or writing. 
We can open file using `open` function.
```cpp
void open(const char* filename, ios::openmode mode);
``` 
second argument is to set a mode of opening file.   
There are 6 flags to set the mode and it is possible to combine 2 or more flags together by using bitwiseOR.   
| flag | meaning|
|---|-----|
|ios_base::in| open file for input ( default for ifstream ) |
|ios_base::out| open file for ouput ( default for ofstream ) |
|ios_base::ate| come from 'at end', seek to the end-of-file before reading/writing, after that we can freely move the seek position |
|ios_base::app| come form 'append', seek to end-of-file before each write. we can not freely move the seek position. Only appending is allowed |
|ios_base::trunc| All contents that existed in the file are discarded before open the file |
|ios_base::binary| reading and writing are performed in binary mode (alternative is text mode) |

we can check if a file stream is opended or not by using `is_open`. It returns true if the file is opened successfully.
```cpp
bool is_open();
```

In C++ when object is no more valid, the object is automatically deleted.    
So, file stream objects are also deleted, automatically.
But it is safer to close file stream, after all file operations are done. 
```cpp
void close()
```

## file read and caution points
Since `ifstream` is child class of `istream`, we can use same functions that are inherited form `istream`.  
so, `get`, `getline`, `operator >>` can be used. 
```cpp
ifstream fin;
fin.open("helloworld.txt");

char charcater;
fin.get(character);//get one character;

string str;
fin.getline(str, 20);//read one line or until lenth get 20 
getline(fin, str, '|'); //read oneu until |

int number;
fin >> number; //read int value;
```
Also, there are flags to check state of stream.
Those state flags and check functions are inherited from `ios`.
|flags|meaning|check function|
|------|----------|----------|
|goodbit|no error|good()|
|eofbit|end of file reached on input operation|eof()|
|failbit|logical error on i/o operation, like trying to read alphabet to int variable. |fail()|
|badbit|reading/writing error on i/o operation. badbit indicates fatal error to stream. like stream is courrupted of lost data. | bad()|
- cautions   
if failbit is set, the istream doesn't work anymore.   
so, it is important to clear the flags by using `clear()` before istream gets the next input. 

Input can be various forms, so it is really important to handle all cases.  
Some inputs include invalid format. 
there are both cases that file ends with only end-of-file or \n and end-of-file.  

## seeking in file 
We can set a position to read or write cursor.  
There are functions to set or get position of cursors.  
And those functions are inherited from `istream` and `ostream`
```cpp
istream& seekg(streampos pos); 
istream& seekg(streamoff off, ios_base::seekdir way);
```
if one argument(`pos`) is given, the position is just set to `pos`.   
otherwise if two arguments(`off`, `way`) are given, position is set to `way`+`off`.  
`way` value points out a exact index of file, like beginning of file or end of file. 
|ios_base::seekdir|meaning|
|------------|-------|
|ios_base::beg|beginning of the stream|
|ios_base::cur|current position in the stream|
|ios_base::end|end of the stream|

|seeking func|meaning|
|---------|-----|
|seekg|set position of reading cursor|
|tellg|get position of reading cursor|
|seekp|set position of writing sequence|
|tellp|get postion of writing sequence|
 
