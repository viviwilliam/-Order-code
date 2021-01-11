#include"list.h"
#include"calculate.h"
#include<fstream>
#include<string>
#include<ctime>
#include<iostream>
#include "stdio.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;
#define ERROR 0
#define OK 1
#define OVERFLOW -1
typedef struct DulNode {//双向链表存储结构
	struct DulNode* prior;//前指针
	struct DulNode* next;//后指针
	int data;//节点数据
}DulNode, * DuList;

int InistList(DuList& L, char fh)//创建空链表，并初始化,fh为符号标识符
{
	L = (DuList)malloc(sizeof(DulNode));//动态分配存储空间
	if (fh == '-') L->data = 1;//L->data存放符号节点，如果是‘-’则为1，否则为0
	else L->data = 0;
	L->prior = L;
	L->next = L;
	return OK;
}

int DestroyList(DuList & L)
{
	DuList p, q;//定义两个结构体指针
	if (!L)return ERROR;//链表不存在
	p = L->prior;//p指向链表头节点的前驱
	while (p != L)//删除节点节点p
	{
		q = p->prior;
		free(p);//释放节点p的空间
		p = q;
	}
	free(L);//释放链表L的存储空间
	return OK;
}

int Insfirst(DuList & L, int e)//在头结点后插入新节点p
{
	DuList p, q;
	p = (DuList)malloc(sizeof(DulNode));
	p->data = e;
	q = L->next;
	L->next = p;
	p->prior = L;
	p->next = q;
	q->prior = p;
	return OK;
}

int Inslast(DuList & L, int e)//在链表最后插入新节点
{
	DuList p, q;
	p = (DuList)malloc(sizeof(DulNode));
	p->data = e;
	q = L->prior;
	q->next = p;
	p->prior = q;
	p->next = L;
	L->prior = p;
	return OK;
}

int CountNode(DuList L)//计算链表的节点数
{
	DuList p;
	p = L;
	int i;
	for (i = 0; p->next != L; i++, p = p->next);
	return i;
}

int Count(int e)//计算节点元素e的位数
{
	int i, k;
	for (i = 1, k = 1000; e / k <= 0; i++, k = k / 10);
	return i;
}

int Dzero(DuList & L)//去掉无效0函数
{
	DuList p;
	if (CountNode(L) <= 1)return ERROR;//链表节点为空
	p = L->next;
	while (!p->data)p = p->next;
	L->next = p;
	p->prior = L;
	return OK;
}

int CountB(DuList L)//计算长整数位数函数
{
	if (L->next == L)return 0;//空链表
	Dzero(L);//删除0
	int i;
	i = Count(L->next->data) + (CountNode(L) - 1) * 4;//头节点数据的位数加上节点个数*4，每个节点有四位数
	return i;
}

int ConversionD(char* s, int i, int& e)//将字符转化为数字
{
	int k, g, x, sum = 0;
	for (k = 1, g = 1; k <= i; k++, g = g * 10)
	{
		x = *(s - k) - 48;
		sum = sum + x * g;
	}
	e = sum;
	return OK;
}

int Creat(DuList & L, char* s)//通过相应的字符串建立链表
{
	int i = 0;
	int e;
	InistList(L, s[0]);
	if (*s == '-')
		s++;//长整数为负数
	while (*s != '\0')//每个节点最多存放四位数，当i=‘，’时，i又从零开始加起，把‘，’插入到结尾链表结尾
	{
		if (*s == ',')
		{
			ConversionD(s, i, e);
			Inslast(L, e);
			i = -1;
		}
		i++;
		s++;
	}
	ConversionD(s, i, e);//不是‘，’则直接插入到链表结尾中
	Inslast(L, e);


	return OK;
}

int Cmp(DuList L, DuList K)//结点相同时的比较两数大小函数
{
	DuList p, q;
	p = L->next;
	q = K->next;
	while (p != L && q != K)//两链表都还没读完
	{
		if (p->data > q->data) return 1;//p的数值>q数值
		if (p->data < q->data) return -1;//p的数值<q数值
		p = p->next;
		q = q->next;
	}
	return 0;
}


int print(DuList L)//输出链表函数
{
	int i;
	DuList p;
	if (L->data == 1 && L->next->data == 0)//如果结果是-0则符号标识清0，输出0
		L->data = 0;
	if (L->data == 1 && L->next->data != 0)
		cout << "-";//输出符号
	p = L->next;
	while (p->data == 0 && p->next != L)//跳过无效零
		p = p->next;
	if (p == L)      //输出0
	{
		cout << 0;
		return OK;
	}
	if (p->next == L)     //p是最后一个节点，输出最后一个结点的数值
	{
		cout << p->data;
		return OK;
	}
	if (p->next != L)//p不是最后一个节点，输出数值并且输出‘，’作为分隔符
		cout << p->data << ',';
	p = p->next;
	while (p->next != L)    //循环输出不是最后结点的数
	{
		if (p->data == 0) cout << "0000" << ",";
		else
		{
			for (i = 1; i < Count(p->data); i++)//节点上如果某一位为0，则输出0，否则输出数值
				cout << '0';
			cout << p->data << ",";
		}
		p = p->next;
	}
	if (p->data == 0) cout << "0000";//输出最后一个节点的数值
	else
	{
		for (i = 1; i < Count(p->data); i++)
			cout << '0';
		cout << p->data;
	}
	return OK;
}
DuList add(DuList L, DuList K, char fh)//无符号加法,fh为符号标识符
{
	int temp, cf = 0;
	DuList p, q, R;
	InistList(R, fh);
	p = L->prior;
	q = K->prior;
	while (p != L && q != K)        //从最后一个节点开始进行加法，进制10000
	{
		temp = p->data + q->data + cf;
		if (temp >= 10000)//两数相加的和大于10000，temp=temp-10000且进位标识为1
		{
			Insfirst(R, temp - temp / 10000 * 10000);
			cf = 1;
		}
		else
		{
			Insfirst(R, temp);//无进位
			cf = 0;
		}
		p = p->prior;//p向前搜索
		q = q->prior;//q向前搜索
	}
	while (p != L)//K加完，L还有没加的，p加上进位
	{
		temp = p->data + cf;
		cf = temp / 10000;
		Insfirst(R, temp - temp / 10000 * 10000);
		p = p->prior;
	}
	while (q != K)//L加完，K还有没加的，q加进位
	{
		temp = q->data + cf;
		cf = temp / 10000;
		Insfirst(R, temp - temp / 10000 * 10000);
		q = q->prior;
	}
	if (cf != 0) Insfirst(R, cf);//最后判断是否还有进位，如果有在链表表头新增一个节点，数据为进位
	return R;
}

DuList sub(DuList L, DuList K, char fh)//无符号减法函数,fh为符号标识位
{
	DuList p, q, R;
	int temp, cf = 0;
	InistList(R, fh);
	p = L->prior;
	q = K->prior;
	while (p != L && q != K)//进行减法，不够减就借位
	{
		temp = p->data - q->data - cf;//两数相减并减去借位
		if (temp < 0)//有借位
		{
			temp = temp + 10000;
			Insfirst(R, temp);
			cf = 1;//有借位
		}
		else
		{
			Insfirst(R, temp);//无借位
			cf = 0;
		}
		p = p->prior;
		q = q->prior;
	}
	while (p != L && cf)//减完，还有借位
	{
		if (p->data - cf == 0 && p->prior == L)//减去借位 
			return R;
		temp = p->data - cf;
		if (temp > 0)
		{
			Insfirst(R, temp);
			p = p->prior;
			break;
		}
		else
		{
			Insfirst(R, temp + 10000);
			cf = 1;
		}
		p = p->prior;
	}
	while (p != L)//把L剩下的都复制过结果链表
	{
		Insfirst(R, p->data);
		p = p->prior;
	}
	return R;
}

DuList Computing(DuList L, DuList K, char ys)//四则运算控制函数
{
	DuList R;
	char fh = 'h';
	InistList(R, fh);
	Dzero(L);//删去L，K无效0
	Dzero(K);
	if (!L->data && !K->data) R = add(L, K, '+');
	else if (L->data && K->data) R = add(L, K, '-');
	else if (!L->data && K->data)
	{
		if (CountNode(L) > CountNode(K)) R = sub(L, K, '+');
		else if (CountNode(L) < CountNode(K)) R = sub(K, L, '-');
		else if (Cmp(L, K) == 1 || Cmp(L, K) == 0) R = sub(L, K, '+');
		else if (Cmp(L, K) == -1) R = sub(K, L, '-');
	}
	else//被加数是负数，加数是正数
	{
		if (CountNode(L) > CountNode(K)) R = sub(L, K, '-');
		else if (CountNode(L) < CountNode(K)) R = sub(K, L, '+');			       else if (Cmp(L, K) == 1 || Cmp(L, K) == 0) R = sub(L, K, '-');
		else if (Cmp(L, K) == -1) R = sub(K, L, '+');
	}
	return R;
}

int PanGS(char* s)//判断输入格式
{
	int k, i = 1;
	if (*s < 48 && *s != '-' || *s>57) return ERROR;//输入的不是数字也不是‘-’，出错
	if (*s == '-') k = 0;//负数符号不算入节点位数
	else k = 1;
	while (*(s + i) != ',' && *(s + i) != '\0')//输入的字符不是','和'\0'，输入错误
	{
		if (*(s + i) < 48 || *(s + i) > 57)
			return ERROR;
		k++;
		i++;
	}
	if (k > 4) return ERROR;//每个节点输入的字符大于4个，输入错误
	if (*(s + i) == '\0')
		return OK;//输入完成
	k = 4;
	while (*(s + i) != '\0')//输入的不是‘\0’并且不是‘，’则输入错误
	{
		if (*(s + i) < '0' && *(s + i) != ',' || *(s + i) > '9')
			return ERROR;
		if (*(s + i) == ',')//如果遇到‘，’，k从-1开始算保证每个节点位数是四位
		{
			if (k != 4)//中间节点的位数不是四位，输入错误
				return ERROR;
			k = -1;
		}
		k++;//如果遇到‘，’后，k从零开始
		i++;
	}
	if (k != 4)
		return ERROR;
	return OK;
}

int InputS(char* cz, char* cz1)//从键盘输入两个长整数
{
	cout << "请输入长整数!" << endl;
	cout << "长整数1:";
	cin >> cz;
	while (!PanGS(cz))//判断输入格式是否正确 
	{
		cout << "输入格式错误,请重新输入!" << endl
			<< "输入格式应为：XXXX，XXXX，XXXX……，XXXX(X是数字)" << endl << "长整数1:";
		cin >> cz;//输入错误，重新输入
	}
	cout << "长整数2:";
	cin >> cz1;
	while (!PanGS(cz1))//判断输入格式是否正确
	{
		cout << "输入格式错误,请重新输入!" << endl
			<< "输入格式应为：XXXX，XXXX，XXXX……，XXXX(X是数字)" << endl << "长整数2:";
		cin >> cz1;//输入错误，重新输入
	}
	return OK;
}

int main()
{
	int optor2;//定义一个字符变量 
	cout << "请输入需要现需要进行的运算   1、加减乘除乘方阶乘   2、长整数加减";
	cin >> optor2;//用户从键盘输入输入运算符 
	if (optor2 == 1)
	{
		//ofstream outfile2("f2.txt", ios::app);
		clock_t start, finish;//定义计时器 
		while (1) {
			char optor1;//定义一个字符变量 
			cout << "请输入要进行的运算：";
			cin >> optor1;//用户从键盘输入输入运算符 
			if (optor1 == '+')
			{
				cout << "请输入第一个十进制大整数：";
				string str1, str2;    //定义两个字符串 
				cin >> str1;//输入第一个字符串 
				cout << "请输入第二个十进制大整数：";
				cin >> str2;//输入第二个字符串 
				start = clock();//开始计时 
				list A(str1);//定义一个以str1为参数的list对象 
				list B(str2);//定义一个以str2为参数的list对象 
				calculate val1(A, B, optor1);//定义一个calculate对象	
				val1.display1();//输出运算的式子 
				val1.D_add();
				val1.display2();//输出运算结果 
			}//进行加法运算 
			if (optor1 == '-')
			{
				cout << "请输入第一个十进制大整数：";
				string str1, str2;    //定义两个字符串 
				cin >> str1;//输入第一个字符串 
				cout << "请输入第二个十进制大整数：";
				cin >> str2;//输入第二个字符串 
				start = clock();//开始计时 
				list A(str1);//定义一个以str1为参数的list对象 
				list B(str2);//定义一个以str2为参数的list对象 
				calculate val1(A, B, optor1);//定义一个calculate对象	
				val1.display1();//输出运算的式子 
				val1.D_sub();
				val1.display2();//输出运算结果 
			}//进行减法运算 
			if (optor1 == '*')
			{
				cout << "请输入第一个十进制大整数：";
				string str1, str2;    //定义两个字符串 
				cin >> str1;//输入第一个字符串 
				cout << "请输入第二个十进制大整数：";
				cin >> str2;//输入第二个字符串 
				start = clock();//开始计时 
				list A(str1);//定义一个以str1为参数的list对象 
				list B(str2);//定义一个以str2为参数的list对象 
				calculate val1(A, B, optor1);//定义一个calculate对象	
				val1.display1();//输出运算的式子 
				val1.D_multi();
				val1.display2();//输出运算结果 
			}//进行乘法运算 
			if (optor1 == '/')
			{
				cout << "请输入第一个十进制大整数：";
				string str1, str2;    //定义两个字符串 
				cin >> str1;//输入第一个字符串 
				cout << "请输入第二个十进制大整数：";
				cin >> str2;//输入第二个字符串 
				start = clock();//开始计时 
				list A(str1);//定义一个以str1为参数的list对象 
				list B(str2);//定义一个以str2为参数的list对象 
				calculate val1(A, B, optor1);//定义一个calculate对象	
				val1.display1();//输出运算的式子 
				val1.D_divide();
				val1.display2();//输出运算结果 
			}//进行除法运算 
			if (optor1 == '^')
			{
				cout << "请输入第一个十进制大整数：";
				string str1, str2;    //定义两个字符串 
				cin >> str1;//输入第一个字符串 
				cout << "请输入第二个十进制大整数：";
				cin >> str2;//输入第二个字符串 
				start = clock();//开始计时 
				list A(str1);//定义一个以str1为参数的list对象 
				list B(str2);//定义一个以str2为参数的list对象 
				calculate val1(A, B, optor1);//定义一个calculate对象	
				val1.display1();//输出运算的式子 
				val1.D_exp();
				val1.display2();//输出运算结果 
			}//进行乘方运算 
			if (optor1 == '!')
			{
				cout << "请输入第一个十进制大整数：";
				string str1, str2;    //定义两个字符串 
				cin >> str1;//输入第一个字符串 
				str2 = "1";//输入第二个字符串 
				start = clock();//开始计时 
				list A(str1);//定义一个以str1为参数的list对象 
				list B(str2);//定义一个以str2为参数的list对象 
				calculate val1(A, B, optor1);//定义一个calculate对象	
				val1.display3();//输出运算的式子 
				val1.D_jiechen();
				val1.display2();//输出运算结果 
			}
			finish = clock();//计时结束 

			cout << "程序运行时间是：" << finish - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;//输出运算时间
			cout << "1.继续运算" << endl;
			cout << "2.退出程序" << endl;
			cout << "请输入1或2" << endl;
			int key3;
			cin >> key3;
			if (key3 == 2)exit(1);
		}
	}
	else
	{
	char cz[99999];      //定义字符串数组，用里保存从键盘输入的长整数
	char cz1[99999];
	DuList L1, L2, R;
	int flag = 1;
	char xz;
	cout << "*************************************************************" << endl
		<< "                   欢迎使用长整数加法运算器!" << endl
		<< "*************************************************************"
		<< endl
		<< "长整数的输入格式为：XXXX，XXXX，XXXX……，XXXX;" << endl;
	while (1)//判断键入的是否为无效命令
	{
		InputS(cz, cz1);//从键盘输入长整数形式的字符串，同时判别输入格式 
		Creat(L1, cz);//把长整数字符串转换为循环链表的储存结构
		Creat(L2, cz1);
		R = Computing(L1, L2, '+');
		cout << "运算结果:";
		print(R);//结果以长整数标准形式输出
		cout << endl;
		DestroyList(L1);//销毁函数，以释放空间
		DestroyList(L2);
		DestroyList(R);
	}
	}

	return 0;
}
