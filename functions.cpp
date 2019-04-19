#include "Instructor.h"
#include "Course.h"
#include "Assignment.h"
#include <vector>
#include <random>
#include "time.h"
void CalculateMatchScore(instructor i, Course c, vector <Assignment> & assig);
void instructorInput(vector<instructor>& v)
{
	srand(time(NULL));
	cout << "Please enter number of instructors" << endl;
	int numberOfInstructors;
	cin >> numberOfInstructors;
	int count = 0;
	while (count < numberOfInstructors)
	{

		double algo = rand() % 5 + 0;
		double arch = rand() % 5 + 0;
		double html = rand() % 5 + 0;
		double math = rand() % 5 + 0;
		double prog = rand() % 5 + 0;

		instructor i;
		i.setId();
		i.setAlgo(algo);
		i.setMath(math);
		i.setArch(arch);
		i.setHtml(html);
		i.setProg(prog);
		v.push_back(i);
		count++;

	}
}
	void displayInstructorInfo(vector <instructor> v)
	{
		cout << "Instructor ID" << "\t Algorithm" << "\t Archetecture" << "\t Html" << "\t Math" << "\t Programing" << endl;
		for (int i = 0; i < v.size(); i++)
		{
			
			cout << v[i].getId() << "\t\t\t" << v[i].getAlgo()*5/100 << "\t\t" << v[i].getArch()*5/100 << "\t" << v[i].getHtml()*5/100 << "\t" << v[i].getMath()*5/100 << "\t" << v[i].getProg()*5/100 << endl;
			
			
		}
	}
	void courseInput(vector<Course> & v, int numberOfCourses)
	{
		srand(time(NULL));
		int count = 0;
		double algo, arch, html, math, prog, total = 0;
		while (count < numberOfCourses)
		{
			algo = rand() % 100 + 0;
			arch = rand() % 100 + 0;
			html = rand() % 100 + 0;
			math = rand() % 100 + 0;
			prog = rand() % 100 + 0;
			total = algo + arch + html + math + prog;
			algo = algo / total * 100;
			arch = arch / total * 100;
			html = html / total * 100;
			math = math / total * 100;
			prog = prog / total * 100;
			Course c;
			c.setId();
			c.setAlgo(algo);
			c.setArch(arch);
			c.setHtml(html);
			c.setMath(math);
			c.setProg(prog);
			v.push_back(c);
			count++;

		}
	}
	void displayCourseInfo(vector <Course> v)
	{
		cout << "Course ID" << "\t Algorithm" << "\t Archetecture" << "\t Html" << "\t Math" << "\t Programing" << endl;
		for (int i = 0; i < v.size(); i++)
		{

			cout << v[i].getId() << "\t\t\t" << v[i].getAlgo() << "\t\t" << v[i].getArch() << "\t" << v[i].getHtml() << "\t" << v[i].getMath() << "\t" << v[i].getProg() << endl;


		}
	}
	void assign(vector<instructor> i, vector<Course> c, vector<Assignment> &a)
	{
		while (c.size() != 0)
		{
			Assignment assi;
			
				if (c.size() != 0 && (c.back().getAlgo() + c.back().getHtml()) > (c.back().getArch() + c.back().getMath()))
				{
					for (int k = 0; k < i.size(); k++)
					{
						if (i[k].getAlgo() > c.back().getAlgo())
						{
							assi.setCourseID(c.back().getId());
							assi.setInstructorId(i[k].getId());
							a.push_back(assi);
							CalculateMatchScore(i[k], c.back(),a);
							c.pop_back();
							swap(i[k], i.back());
							
							i.pop_back();
							break;
						}
					}
					if (c.size() != 0)
					{
						assi.setCourseID(c.back().getId());
						assi.setInstructorId(i.back().getId());
						a.push_back(assi);
						CalculateMatchScore(i.back(), c.back(), a);
						c.pop_back();

						i.pop_back();
					}
				}

				 if (c.size() != 0 && c.back().getArch() > c.back().getHtml())
				{
					for (int k = 0; k < i.size(); k++)
					{
						if (i[k].getArch() > c.back().getArch())
						{
							assi.setCourseID(c.back().getId());
							assi.setInstructorId(i[k].getId());
							a.push_back(assi);
							CalculateMatchScore(i[k], c.back(), a);
							c.pop_back();
							swap(i[k], i.back());
							
							i.pop_back();
							break;
						}
					}
					if (c.size() != 0)
					{
						assi.setCourseID(c.back().getId());
						assi.setInstructorId(i.back().getId());
						a.push_back(assi);
						CalculateMatchScore(i.back(), c.back(), a);
						c.pop_back();

						i.pop_back();
					}

				}
				  if (c.size() != 0 && c.back().getProg() > c.back().getHtml())
				{
					for (int k = 0; k < i.size(); k++)
					{
						if (i[k].getProg() > c.back().getProg())
						{
							assi.setCourseID(c.back().getId());
							assi.setInstructorId(i[k].getId());
							a.push_back(assi);
							CalculateMatchScore(i[k], c.back(), a);
							c.pop_back();
							swap(i[k], i.back());
							
							i.pop_back();
							break;
						}
					}
					if (c.size() != 0)
					{
						assi.setCourseID(c.back().getId());
						assi.setInstructorId(i.back().getId());
						a.push_back(assi);
						CalculateMatchScore(i.back(), c.back(), a);
						c.pop_back();

						i.pop_back();
					}

				}
				  if (c.size() != 0 && c.back().getHtml() > c.back().getAlgo())
				{
					for (int k = 0; k < i.size(); k++)
					{
						if (i[k].getHtml() > c.back().getHtml())
						{
							assi.setCourseID(c.back().getId());
							assi.setInstructorId(i[k].getId());
							a.push_back(assi);
							CalculateMatchScore(i[k], c.back(), a);
							c.pop_back();
							swap(i[k], i.back());
							
							i.pop_back();
							break;
						}
					}
					if (c.size() != 0)
					{
						assi.setCourseID(c.back().getId());
						assi.setInstructorId(i.back().getId());
						a.push_back(assi);
						CalculateMatchScore(i.back(), c.back(), a);
						c.pop_back();

						i.pop_back();
					}

				}
			
			else
			{
					  if (c.size() != 0)
					  {
						  assi.setCourseID(c.back().getId());
						  assi.setInstructorId(i.back().getId());
						  a.push_back(assi);
						  CalculateMatchScore(i.back(), c.back(), a);
						  c.pop_back();

						  i.pop_back();
					  }

			}
		}

	}
	void CalculateMatchScore(instructor i, Course c, vector <Assignment> & a)

	{
		double matchScore = 0;
		if (i.getAlgo() >= c.getAlgo())
		{
			matchScore += 20;
		}
		else if (i.getAlgo() < c.getAlgo())
		{
			matchScore += 20 - 20 * (c.getAlgo() - i.getAlgo()) / c.getAlgo();
		}
		if (i.getArch() >= c.getArch())
		{
			matchScore += 20;
		}
		else if (i.getArch() < c.getArch())
		{
			matchScore += 20 - 20 * (c.getArch() - i.getArch()) / c.getArch();
		}
		if (i.getHtml() >= c.getHtml())
		{
			matchScore += 20;
		}
		else if (i.getHtml() < c.getHtml())
		{
			matchScore += 20 - 20 * (c.getHtml() - i.getHtml()) / c.getHtml();
		}
		if (i.getMath() >= c.getMath())
		{
			matchScore += 20;
		}
		else if (i.getMath() < c.getMath())
		{
			matchScore += 20 - 20 * (c.getMath() - i.getMath()) / c.getMath();
		}
		if (i.getProg() >= c.getProg())
		{
			matchScore += 20;
		}
		else if (i.getProg() < c.getProg())
		{
			matchScore += 20 - 20 * (c.getProg() - i.getProg()) / c.getProg();
		}
		a.back().setMatchScore(matchScore);
		

		

	}
