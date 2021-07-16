#include "kksk.h"
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
int main(void)
{
	double a = 6378137;
	double f = 1 / 298.257223563;
	double GM = 3986004.418e8;
	double w = 7292115e-11;
	string aa = "19.0211111111111111111111111111111111111111111111111111111111111111111";
	double aaa = atof(aa.c_str());
	double aaaa = stod(aa);
	//cout << aaa << endl;
	/*kksk wow;
	wow.to(a, f, GM, w);
	char origen[100];
	printf("请输入原坐标文件地址：\n"); cin >> origen;
	wow.ini(origen);*/
	//string filename1 = "E:\\360MoveData\\Users\\DELL\\Desktop\\物理大地测量\\ProjectNO2\\2018302141042NO1.txt";
	//string filename2 = "E:\\360MoveData\\Users\\DELL\\Desktop\\物理大地测量\\ProjectNO2\\2018302141042NO2.txt";
	//double sita;
	//double a, f, GM, w;
	//cout << "按照a,1/f,GM,w的顺序输入椭球参数" << endl;
	//cin >> a >> f >> GM >> w;
	//cout << "按度分秒输入大地纬度" << endl;
	//double k, kk, kks,h;
	//cin >> k >> kk >> kks;	
	//sita = k + kk / 60 + kks / 3600;
	//kksk wow;
	//double f0;
	//f0 = 1 / f;

	//wow.kj();
	//wow.jdbg();
 //   wow.kksk3(filename1);
	//wow.kksk2( sita,h, filename2);
	system("pause");
	return 0;
}