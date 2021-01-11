#ifndef _LIST_H_
#define _LIST_H_
#include<iostream>
using namespace std;
struct node //定义一个节点类型 
{
	int data;//存放数据 
	node *next;//存放下一个节点的位置 
};
class list //定义一个类 
{
private:
	node *p;//一条链表的头结点 
public:
	friend class calculate;//定义list为calculate的友元类 
	list();//定义无参的构造函数 
	list(string str);//定义以字符串为参数的构造函数 
	node *app(int num);//在链表尾部追加节点 
	void display();//输出到屏幕 
	void filedisplay(ofstream&outfile1);//输出到文件 
	void reverse();//链表转置 
	node*copy();//链表的无连接复制 
	node*clear();//链表的清空 
	void delt();//删除最后链表的最后一个节点 
	int lastdata();//得到最后一个节点的值 
	void changefirst_to_neg();//把最后一个数变成负数 
	int length();//返回链表的长度 
	node*D_decre_1();//十进制大整数的数值自减1
	node*B_decre_1();//二进制大整数的数值自减1
	node*delt_0();//删除整数前面的无效的0 
	int eaquls_0();//判断大整数是否为0 
};
#endif

