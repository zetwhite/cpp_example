#ifndef _SINFO__H_
#define _SINFO__H_

#include <iostream>
using namespace std;

namespace samples
{
	class StudentInfo
	{
	public:
		StudentInfo(const string& name, const string& studentID);

		const string& GetName() const;
		const string& GetStudentID() const;
		
		bool operator<(const StudentInfo& object) const;

	private:
		string mName;
		string mStudentID;
	};
}

#endif