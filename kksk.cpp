#include"kksk.h"
void kksk::ini(char* file)
{
	ifstream infile;
	infile.open(file);   //将文件流对象与文件连接起来 
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

	string s;
	int count = -1;
	int flag = false;
	int aa = 0;
	while (getline(infile, s))
	{
		if (s.substr(0, 4) == "3102")
		{
			count = 0;
			int aa = 1;
		}
		if (count == 0 || aa == 1)
		{
			anydata.push_back(s);
			
			count = -1;
		}
	}
	infile.close();             //关闭文件输入流 
	pushevery();
}
vector<double> kksk::dealLine(string str)
{
	//以下处理空格切分
	vector<string> res;
	string result;
	stringstream input(str);
	while (input >> result)
		res.push_back(result);
	//字符转化成double数据
	vector<double> data;
	for (size_t i = 0; i < res.size(); i++)
	{
		data.push_back(atof(res[i].c_str()));
		int b = rand();
	}
	return data;
}
void kksk::pushevery()
{
	int k = anydata.size();
	vector<double> data;
	for (int i = 0; i < k; i++)
	{
		data=dealLine(anydata[i]);
		everydata.push_back(data);
	}
}
void kksk::to(double a1, double f1, double GM1, double w1)
{
	a = a1;
	f = f1;
	GM = GM1;
	w = w1;
	b = a - a * f;
	E = sqrt(pow(a, 2) - pow(b, 2));
	q0 = 0.5 * ((1 + 3 * pow(b, 2) / pow(E, 2)) * atan(E / b) - 3 * b / E);
	q02 = 3 * (1 + pow(b, 2) / pow(E, 2)) * (1 - (b / E) * atan(E / b)) - 1;
	m = pow(w, 2) * pow(a, 2) * b / GM;
	e2 = E / b;
	ra = (GM / (a * b)) * (1 - m - (m / 6) * e2 * q02 / q0);
	rb = (GM / (a * a)) * (1 + m/3 * e2 * q02 / q0);
	int aaa;
}
double kksk::kksk1(double sita)
{
	double si = PI*sita/180;
	r = (a * ra * pow(cos(si), 2) + b * rb * pow(sin(si), 2)) / sqrt(a * a * pow(cos(si), 2) + b * b * pow(sin(si), 2));
	return r;
}
void kksk::kksk3(string filename)
{
	ofstream ofile1;
	ofile1.open(filename);
	ofile1 << "value" << endl;
	ofile1 << setprecision(16) << setiosflags(ios::left);
	ofile1 << r << endl;
	ofile1.close();
}
void kksk::kksk2(double sita, double h, string filename)
{
	double si = PI * sita / 180;
	double rh;
	double f = (a - b) / a;
	double r = kksk1(sita);
	rh = r * (1 - (2 / a) * (1 + f + m - 2 * f * pow(sin(si), 2)) * h + pow(h, 2) * 3 / pow(a, 2));
	ofstream ofile2;
	ofile2.open(filename);
	ofile2 << "h       value" << endl;
	ofile2 << setprecision(16) << setiosflags(ios::left);
	ofile2 << rh << endl;
	ofile2.close();
}
void kksk::kj()
{
	ofstream ofile1;
	string filename1 = "E:\\360MoveData\\Users\\DELL\\Desktop\\物理大地测量\\ProjectNO2\\空间改正.txt";
	ofile1.open(filename1);
	assert(ofile1.is_open());   //若失败,则输出错误消息,并终止程序运行 
	ofile1.unsetf(ios::fixed);
	ofile1 << setprecision(10) << setiosflags(ios::left);
	int k = everydata.size();
	for (int i = 0; i < k; i++)
	{
		everydata[i][4] = everydata[i][4] + 0.3086 * everydata[i][3] - 0.72e-7 * pow(everydata[i][3], 2);
		ofile1 << 0.3086 * everydata[i][3] - 0.72e-7 * pow(everydata[i][3], 2) << endl;
	}
	ofile1.close();
	ofstream ofile;
	string filename = "E:\\360MoveData\\Users\\DELL\\Desktop\\物理大地测量\\ProjectNO2\\2018302141042-韩志鑫-空间改正.txt";
	ofile.open(filename);
	assert(ofile.is_open());   //若失败,则输出错误消息,并终止程序运行 
	ofile.unsetf(ios::fixed);
	ofile << setprecision(10) << setiosflags(ios::left);
	for (int i = 0; i < k; i++)
	{
		r = kksk1(everydata[i][1]);
		ofile << everydata[i][1] << " " <<everydata[i][2] << " " << everydata[i][4] - r*1e5 << endl;
	}
	ofile.close();
}
void kksk::jdbg()
{
	ofstream ofile1;
	string filename1 = "E:\\360MoveData\\Users\\DELL\\Desktop\\物理大地测量\\ProjectNO2\\层间改正.txt";
	ofile1.open(filename1);
	assert(ofile1.is_open());   //若失败,则输出错误消息,并终止程序运行 
	ofile1.unsetf(ios::fixed);
	ofile1 << setprecision(10) << setiosflags(ios::left);
	int k = everydata.size();
	for (int i = 0; i < k; i++)
	{
		everydata[i][4] = everydata[i][4] - 0.1119 * everydata[i][3];
		ofile1 << -0.1119 * everydata[i][3] << endl;
	}
	ofile1.close();
	ofstream ofile;
	string filename = "E:\\360MoveData\\Users\\DELL\\Desktop\\物理大地测量\\ProjectNO2\\2018302141042-韩志鑫-简单布格改正.txt";
	ofile.open(filename);
	assert(ofile.is_open());   //若失败,则输出错误消息,并终止程序运行 
	ofile.unsetf(ios::fixed);
	ofile << setprecision(10) << setiosflags(ios::left);
	for (int i = 0; i < k; i++)
	{
		r = kksk1(everydata[i][1]);
		ofile << everydata[i][1] << " " << everydata[i][2] << " " << everydata[i][4] - r * 1e5 << endl;
	}
	ofile.close();
}