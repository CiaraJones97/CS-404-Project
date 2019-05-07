# include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Instructor.h"
#include "Course.h"
#include "Assignment.h"
#include <random>
using namespace std;

void instructorInput(vector<instructor> &v); // to randomly generate instructor information
void courseInput(vector<Course> & v,int numberOfCourses); // to randomly generate course informaion
void displayInstructorInfo(vector <instructor> v);
void displayCourseInfo(vector <Course> v);
void assign(vector<instructor> i, vector<Course> c,vector<Assignment> &a); // to match course and instructor

int main()
{
	vector<instructor> instructorInfo; // to store instructors
	vector<Course> courseInfo;// to store course
	vector<Assignment> assigning;// to store course - instructor assignment during iteration 
	vector <Assignment> optimal; // to store optimal assignment
	
	
	
	instructorInput(instructorInfo);
	int numberOfCourses = instructorInfo.size(); // number of courses = number of instructors 
	
	
	courseInput(courseInfo, numberOfCourses);
	cout << endl;
	cout << "\t..................... Instructor experties out of 5..........." << endl;
	displayInstructorInfo(instructorInfo);
	cout << endl;
	cout << "\t................... Percentage of course content............." << endl;
	displayCourseInfo(courseInfo);

	//couseid and course name
	cout << endl;
	cout << "\t............Course ID...........Course name......." << endl;
	cout << endl;
	for (int n = 0; n < numberOfCourses; n++) {
		cout << "\t\t\t"<< courseInfo[n].getId() << "\t\tProblem solving and Programming  " << n + 1 << endl;
	}
	//instructor id and name
	cout << endl;
	cout << "\t...........Instructor ID.........Instructor name......." << endl;
	cout << endl;
	for (int n = 0; n < numberOfCourses; n++) {
		cout << "\t\t\t" << instructorInfo[n].getId() << "\t\tInstructor  " << n + 1 << endl;
	}


	int assignmetSum = 0; // to store match score for each iteration
	int optimalSum = 0;// to store optimal match score
	assign(instructorInfo, courseInfo, assigning);
	for (int i = 0; i < numberOfCourses*10 ; i++)
	{
		
		random_shuffle(courseInfo.begin(), courseInfo.end());
		assign(instructorInfo, courseInfo, assigning);


		for (int i = 0; i < assigning.size(); i++)
		{
			assignmetSum += assigning[i].getMatchScore();
		}
		if (assignmetSum > optimalSum)
		{
			optimal.clear();
			for (int i = 0; i < assigning.size(); i++)
			{
				optimal.push_back(assigning[i]);
			}

			optimalSum = assignmetSum;
		}	
	
	}
	cout << endl;
	cout<<"......................................."<<endl;
	cout << "CourseID\t InstructorID \t MatchScore" << endl<<endl;
	
	for (int i = 0; i < numberOfCourses; i++)
	{
		
		cout << optimal[i].getCourseId() << " \t\t" << optimal[i].getInstructorId() << "\t\t" << optimal[i].getMatchScore() << endl;
	}
	system("pause");
	return 0;
}
