# include <iostream>
#include <string>
using namespace std;

class instructor 
{
private:
	int id;
	double algo;
	double math;
	double arch;
	double html;
	double prog;
public:
	double getId()
	{
		return id;
	}
	double getAlgo()
	{
		return algo;
	}
	double getMath()

	{
		return math;
	}
	double getArch()
	{
		return arch;

	}
	double getHtml()
	{
		return html;
	}
	double getProg()
	{
		return prog;
	}
	void setId()
	{
		id = rand() % 1000 + 100;
	}
	void setAlgo(double x)
	{
		algo = (x / 5) * 100;
	}
	void setMath(double x)
	{
		math = (x / 5) * 100;
	}
	void setArch(double x)
	{
		arch = (x / 5) * 100;
	}
	void setHtml(double x)
	{
		html = (x / 5) * 100;
	}
	void setProg(double x)
	{
		prog = (x / 5) * 100;
	}
};
