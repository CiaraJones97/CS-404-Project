# include <iostream>
#include <string>
using namespace std;

class Assignment
{
private:
	int instructorId;
	int courseId;
	double MatchScore;
public:
	int getInstructorId()
	{
		return instructorId;
	}
	int getCourseId()
	{
		return courseId;
	}
	double getMatchScore()
	{
		return MatchScore;
	}
	void setInstructorId(int x)
	{
		instructorId = x;
	}
	void setCourseID(int x)
	{
		courseId = x;
	}
	void setMatchScore(double x)
	{
		MatchScore = x;
	}
};

