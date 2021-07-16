#include <stdlib.h>
#include <string>
#include <fstream>
#include <cassert>
#include <sstream>
#include<iomanip>
#include <vector>
#include <iostream>
#include<cmath>
using namespace std;
#define PI 4*atan(1.0)
class kksk
{
private:
	double b;
	double m;
	double e2;
	double q0;
	double q02;
	double ra;
	double rb;
	double E;
	double a;
	double f;
	double GM;
	double w;
	double r;
	vector<string> anydata;
	vector<vector<double> > everydata;
	vector<double> dealLine(string str);
	void pushevery(void);
public:
	void to(double a, double f, double GM, double w);
	double kksk1( double sita);
	void kksk3(string filename);
	void kksk2( double sita, double h,string filename);
	void ini(char* file);
	void kj();//空间改正
	void jdbg();//简单布格改正
};