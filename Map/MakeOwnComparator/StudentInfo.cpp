#include <iostream>
#include "StudentInfo.h"

using namespace std;

namespace samples
{
	StudentInfo::StudentInfo(const string& name, const string& studentID)
		: mName(name)
		, mStudentID(studentID)
	{
	}

	const string& StudentInfo::GetName() const
	{
		return mName;
	}

	const string& StudentInfo::GetStudentID() const
	{
		return mStudentID;
	}
}