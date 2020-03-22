#include <iostream>
using namespace std;

namespace first{
    int value = 1;
    void print(){
        cout <<"hi from first namespace" << endl;
    }
}

namespace second{
    int value = 2;
    void print(){
        cout <<"hi from second namespace" << endl;
    }
}

int main(){
    cout << first::value << endl;
    cout << second::value << endl;
    first::print();
    second::print();
    return 0;
}
