#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    //setw
    /*
        the arg given to setw() is minimum width.
        if the value needs more space, the output will use more.
        default field width is 0 .
    */
    cout << "setw example : "<< endl;
    cout << "|" << "helloworld" << "|" << endl;
    cout << "|" << setw(3) << "helloworld" << "|" << endl;
    cout << "|" << setw(20) << "helloworld" << "|" << endl;
    cout << endl;

    //justification
    /*
        the default justification is right.
        all manipulators except setw() are persistent.
    */
    cout << "justification example : " << endl;
    cout << left;
    cout << "left :\t|" << setw(10) << -3.14 << "|" << endl;
    cout << right;
    cout << "right :\t|" << setw(10) << -3.14 << "|" << endl;
    cout << internal;
    cout << "internal :\t|" << setw(10) << -3.14 << "|" << endl;
    cout << "internal :\t|" << setw(10) << +3.14 << "|" << endl;
    cout << endl;

    //showpos and noshowpos
    /*
        (no)showpos determines whether print in front plus sign
        of positive number or not.
    */
    cout << "showpos example : "<< endl;
    cout << showpos;
    cout << "showpos " << endl;
    cout << "|" << setw(10) << +3.14 << "|" << endl;
    cout << "|" << setw(10) << 1024 << "|" << endl;
    cout << "|" << setw(10) << 0 << "|" << endl;
    cout << noshowpos;
    cout << "noshowpos" << endl;
    cout << "|" << setw(10) << +3.14 << "|" << endl;
    cout << "|" << setw(10) << 1024 << "|" << endl;
    cout << "|" << setw(10) << 0 << "|" << endl;
    cout << endl;

    //boolalpha and noboolalpha
    cout << "boolalpha example : " << endl;
    cout << "booalpha" << endl;
    cout << boolalpha;
    cout << false << endl;
    cout << true << endl;
    cout << "print interger 1 : " << 1 << endl; //just 1 printed
    cout << "noboolalpha" << endl;
    cout << noboolalpha;
    cout << false << endl;
    cout << true << endl;
    cout << endl;

    //integer base
    /*
        negative integers are not printed as oct or hex.
        Internal bits are just interpreted as being positive.
        also, float are just printed same as in dec, not oct or hex.
    */
    cout << "integer base example: "<< endl;
    int pos_num = 16;
    cout << "test positive nubmer : " << pos_num << endl;
    cout << "dec : " << dec << pos_num << endl;
    cout << "oct : " << oct << pos_num << endl;
    cout << "hex : " << hex << pos_num << endl;
    int neg_num = -24;
    cout << "test negative number : " << neg_num << endl;
    cout << "dec : " << dec << neg_num << endl;
    cout << "oct : " << oct << neg_num << endl; //no
    cout << "hex : " << hex << neg_num << endl; //no
    float flo_num = 2.71;
    cout << "test float : " << flo_num << endl;
    cout << "dec : " << dec << flo_num << endl;
    cout << "oct : " << oct << flo_num << endl; //2.71
    cout << "hex : " << hex << flo_num << endl; //2.71
    cout <<endl;

    //showbase and noshowbase
    cout << "showbase example : " << endl;
    cout << showbase;
    cout << "dec : " << dec << pos_num << endl;
    cout << "oct : " << oct << pos_num << endl;
    cout << "hex : " << hex << pos_num << endl;
    cout << endl;

    //uppercase and nouppercase
    cout << "uppercase example : " << endl;
    int value = 12345678;
    float large_f = 1230000000.0;
    cout << "uppercase with showbase and hex format" << endl;
    cout << showbase << hex << uppercase;
    cout << "hex : " << value << endl;
    cout << "exp : " << large_f << endl;
    cout << "nouppercase with showbase and hex format" << endl;
    cout << nouppercase;
    cout << "hex : " << value << endl;
    cout << "exp : " << large_f << endl;
    cout << endl;

    //fixed and scientific
    cout << "fixed and scientific example : " << endl;
    double small = 3.1415926535897932;
    double large = 6.0234567e17; //avogadro constant
    double whole = 2.0000000000000000;
    cout << "default format" << endl;
    cout << "small : " << small << endl;
    cout << "large : " << large << endl;
    cout << "whole : " << whole << endl;
    cout << "scientific format" << endl;
    cout << scientific;
    cout << "small : " << small << endl;
    cout << "large : " << large << endl;
    cout << "whole : " << whole << endl;
    cout << "fixed format " << endl;
    cout << fixed;
    cout << "small : " << small << endl;
    cout << "large : " << large << endl;
    cout << "whole : " << whole << endl;
    cout << endl;

    //set preicion
    /*
        <iomanip> header file is needed.
        default precision is 6.
    */
    cout << "setprecision example : " << endl;
    double pi = 3.14159;
    cout << "default :\t" << pi << endl;
    cout << setprecision(5) << endl;
    cout << "setpre(5) :\t" << pi << endl; //3.1416
    cout << setprecision(9) << endl;
    cout << "setpre(9) :\t" << pi << endl; //3.14159
    cout << fixed;
    cout << "setpre(9) with fixed : " << pi << endl; //3.141590000
    cout << endl;

    return 0;
}
