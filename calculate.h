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
	calculate(list aa, list bb,char ope);//���캯�� 
	void D_add();//ʮ���Ƽӷ� 
	void D_sub();//ʮ���Ƽ��� 
	void D_multi();//ʮ���Ƴ˷� 
	void D_divide();//ʮ���Ƴ��� 
	void D_exp();//ʮ���Ƴ˷� 
	void B_add();//�����Ƽӷ� 
	void B_sub();//�����Ƽ��� 
	void B_multi();//�����Ƴ˷� 
	void B_divide();//�����Ƴ��� 
	void B_exp();//�����Ƴ˷� 
	void display1();//ʽ���������Ļ 
	void display2();//���������Ļ 
	void filedisplay1();//ʽ��������ļ��� 
	void filedisplay2(ofstream&outfile);//���������ļ��� 
	int compare();//�Ƚ�a��b�Ĵ�С��a�������1��һ����Ϊ0��b�������-1 
	void D_jiechen();//ʮ���Ƴ˷�
	void display3();
};
#endif
