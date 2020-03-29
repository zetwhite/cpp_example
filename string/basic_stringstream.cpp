#include <iostream>
#include <sstream>
using namespace std;

int main(){
    //istringstream example
    cout << "==== istringstream example ====" << endl;
    istringstream iss("zetwhite zetwhite@naver.com");
    string id, mail;
    iss >> id >> mail;
    iss.clear();

    cout << "id : " << id << endl;
    cout << "mail : " << mail << endl;
    cout << endl;

    //ostringstream example
    cout << "==== ostringstream example ====" << endl;
    ostringstream oss;
    int n = 10;
    oss << "countdown from " << n << " : ";
    for(int i = n; i >=0 ; i--){
        oss << i << " ";
    }
    cout << oss.str() << endl;
    return 0;
}
