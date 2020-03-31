#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin;
    fin.open("script.txt");
    if(!fin.is_open()){
        cout << "can not open the file" << endl;
        return 0;
    }
    string line;
    while(!fin.eof()){
        getline(fin, line);
        cout << line << endl;
    }

    fin.close();
}
