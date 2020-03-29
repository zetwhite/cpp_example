#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int count_words(string sentence){
    stringstream ss(sentence);
    string tmp;
    int count = 0;

    while(!ss.eof()){
        ss >> tmp;
        count ++;
        cout << count << " : " << tmp << endl;
    }
    return count;
}

int main(){
    cout << "==== example of using count_words() ====" << endl;
    string sentence = "In spite of everything, I till believe that people are really good at heart";
    cout << '"' << sentence << "\" consists of " << count_words(sentence) << " words" << endl;
    return 0;
}
