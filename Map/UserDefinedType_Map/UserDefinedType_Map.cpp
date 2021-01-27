#include <iostream>
#include <map>
#include <string>
#include "StudentInfo.h"

using namespace std;
using namespace samples; 

int main(){
		map<StudentInfo, int> studentScores;

		studentScores.insert(pair<StudentInfo, int>(StudentInfo("Lulu", "A01234567"), 10));
		studentScores.insert(pair<StudentInfo, int>(StudentInfo("Poppy", "A12345678"), 70));
		studentScores.insert(pair<StudentInfo, int>(StudentInfo("Lulu", "A01234567"), 50));

		for (map<StudentInfo, int>::iterator iter = studentScores.begin(); iter != studentScores.end(); ++iter)
		{
			cout << iter->first.GetName() << "[" << iter->first.GetStudentID() << "]:  " << iter->second << endl;
		}
    /*
    output : 
    Lulu[A01234567]:  10
    Poppy[A12345678]:  70
    */

    return 0; 
}