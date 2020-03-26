#include <iostream>
using namespace std;

void swap(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main(){
	int x = 100;
	int y = 200;
	swap(x, y);
	cout << "x = " << x << endl; //x = 200
	cout << "y = " << y << endl; //y = 100
	return 0;
}
