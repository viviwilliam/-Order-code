#ifndef _LIST_H_
#define _LIST_H_
#include<iostream>
using namespace std;
struct node //����һ���ڵ����� 
{
	int data;//������� 
	node *next;//�����һ���ڵ��λ�� 
};
class list //����һ���� 
{
private:
	node *p;//һ�������ͷ��� 
public:
	friend class calculate;//����listΪcalculate����Ԫ�� 
	list();//�����޲εĹ��캯�� 
	list(string str);//�������ַ���Ϊ�����Ĺ��캯�� 
	node *app(int num);//������β��׷�ӽڵ� 
	void display();//�������Ļ 
	void filedisplay(ofstream&outfile1);//������ļ� 
	void reverse();//����ת�� 
	node*copy();//����������Ӹ��� 
	node*clear();//�������� 
	void delt();//ɾ�������������һ���ڵ� 
	int lastdata();//�õ����һ���ڵ��ֵ 
	void changefirst_to_neg();//�����һ������ɸ��� 
	int length();//��������ĳ��� 
	node*D_decre_1();//ʮ���ƴ���������ֵ�Լ�1
	node*B_decre_1();//�����ƴ���������ֵ�Լ�1
	node*delt_0();//ɾ������ǰ�����Ч��0 
	int eaquls_0();//�жϴ������Ƿ�Ϊ0 
};
#endif

