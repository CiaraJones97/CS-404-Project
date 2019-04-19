# include <iostream>
#include <string>
using namespace std;

class Course
{
private:
	int id;
	int algo;
	int math;
	int arch;
	int html;
	int prog;
public:
	int getId()
	{
		return id;
	}
	int getAlgo()
	{
		return algo;
	}
	int getMath()

	{
		return math;
	}
	int getArch()
	{
		return arch;

	}
	int getHtml()
	{
		return html;
	}
	int getProg()
	{
		return prog;
	}
	void setId()
	{
		id = rand() % 400 + 100;
	}
	void setAlgo(double x)
	{
		algo = x;
	}
	void setMath(double x)
	{
		math = x;
	}
	void setArch(double x)
	{
		arch = x;
	}
	void setHtml(double x)
	{
		html = x;
	}
	void setProg(double x)
	{
		prog = x;
	}
};

