#ifndef _CALCULATE_H_
#define _CALCULATE_H_
#include"list.h"
#include<iostream>
using namespace std;
class calculate
{
private:
	list a;
	list b;
	char optor;
public:
	calculate(list aa, list bb,char ope);//构造函数 
	void D_add();//十进制加法 
	void D_sub();//十进制减法 
	void D_multi();//十进制乘法 
	void D_divide();//十进制除法 
	void D_exp();//十进制乘方 
	void B_add();//二进制加法 
	void B_sub();//二进制减法 
	void B_multi();//二进制乘法 
	void B_divide();//二进制除法 
	void B_exp();//二进制乘方 
	void display1();//式子输出到屏幕 
	void display2();//答案输出到屏幕 
	void filedisplay1();//式子输出到文件中 
	void filedisplay2(ofstream&outfile);//结果输出到文件中 
	int compare();//比较a和b的大小，a大则输出1，一样大为0，b大则输出-1 
	void D_jiechen();//十进制乘方
	void display3();
};
#endif
