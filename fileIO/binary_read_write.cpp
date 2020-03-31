#include <fstream>
#include <iostream>
using namespace std;

int read_binary_file(string path, char** data){
    ifstream fin;
    fin.open(path.c_str(), ios_base::binary);
    if(!fin.is_open()){
        return -1;
    }

    fin.seekg(0, ios_base::end);
    int length = fin.tellg();
    fin.seekg(0, ios_base::beg);

    *data = new char[length];
    fin.read(*data, length);
    fin.close();
    return length;
}

int write_binary_file(string path, const char* const data, const int length){
    ofstream fout;
    fout.open(path.c_str(), ios_base::binary|ios_base::trunc);
    if(!fout.is_open()){
        return -1;
    }

    fout.write(data, length);
    fout.close();
    return length;
}

int main(){
    string lyrics = "Didn't even really wanna go\nBut if you get me out, you get a show\n";
    string filename = "down_lyrics.txt";
    write_binary_file(filename, lyrics.c_str(), lyrics.length());

    char* data;
    int len = read_binary_file(filename, &data);

    for(int i = 0; i < len; i++)
        cout << data[i];
    return 0;
}
