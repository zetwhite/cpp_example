#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin;
    fin.open("script.txt");

    if(!fin.is_open()){
        cout << "can not open script.txt" << endl;
        return 1;
    }

    int number;
    string trash;
    while(true){
        fin >> number;
        if(!fin.fail()){
            cout << number << endl;
            continue;
        }

        if(fin.eof()){
            break;
        }
        fin.clear();
        fin >> trash;
    }
    fin.close();
    return 0;
}
