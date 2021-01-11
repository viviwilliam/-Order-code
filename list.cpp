#include"list.h"//导入List头文件 
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<cmath>
#include<iostream>
using namespace std;

list::list()//创建链表，一条链表即为一个大整数，每个节点的数据部分均为个位的正整数
{
	p=NULL;//链表为空 
}
list::list(string str)
{
	node*p1, *p2;//定义两个node类型的指针 
	p= NULL;//先把头节点p赋值为空 
	p1 = (node*)malloc(sizeof(node));//给p1分配动态空间 
	p1->data = str[0]-48;//把字符串的第一个字符存入p1的data中 ，数字字符的ASCII值-48为数字本身 
	p= p1;//把p1赋值给头结点 
	for(int i=1;i<str.length();i++)//for循环将字符串的每个字符逐个存进链表中 
	{
		p2 = (node*)malloc(sizeof(node));//给p2分配动态内存空间 
		p2->data=str[i]-48;//给p2的data赋值 
		p1->next = p2;//循环使用p1和p2给链表添加节点 
		p1 = p2;
	}
	p1->next=NULL;//尾节点的next为空 

}
void list::display()//大整数的输出
{
	p=delt_0();//将链表的前缀的无效的0删除 
	node*head=p;//将头结点赋值给head。避免在后续操作中头结点丢失 
	while (head != NULL)//判断循环是否执行到最后了 
	{
		cout << head->data;//如果没有执行得到最后，那么输出当前节点的数据 
		head = head->next;//head指向下一个节点 
	}
}
void list::filedisplay(ofstream&outfile1)//大整数输出到文件
{ 
	p=delt_0();//将链表的前缀的无效的0删除 
	node*head=p;//将头结点赋值给head。避免在后续操作中头结点丢失 
	while (head != NULL)//判断循环是否执行到最后了 
	{
		outfile1<< head->data;//如果没有执行得到最后，那么输出当前节点的数据到指定文件 
		head = head->next;//head指向下一个节点 
	}
} 
node* list::app(int num)//在链表尾部追加指定数据 
{
	node*head=p;//把链表的头结点赋值给head 
	node *p1=(node*)malloc(sizeof(node));//给添加的节点分配动态内存空间 
	p1->data =num;//把该节点的data部分赋值为num 
	if(head==NULL) {head=p1;head->next=NULL;p=head;return p;}//若head为空，那么说明该链表为空，添加的该节点为头结点，
	                                                     //把p1赋值给head，head的next指向空 ，再把head返还给p，返回头结点 
	else//否则，添加的节点仅为该链表的尾节点 
	{
		while(head->next!=NULL) head=head->next;//将指针遍历链表，直到指针指向链表的最后一个节点	
		head->next=p1;//把尾节点的next指向p1 
		p1->next =NULL;	//p1的next指向null，这是p1即为该链表的尾节点 
	}
	return p;//返回头结点p 
}
void list::reverse()//大整数的逆向存储，因为运算时需要从个位开始运算
{
	node*head = p;
	node *pre, *cur, *nex;
	pre = head;
	cur = head->next;
	while (cur)
	{
		nex = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nex;
	}
	head->next = NULL;
	head = pre;
	p=head;
}
node *list::copy()//链表的无连接复制 
{
	node*head=p; 
	node*pp=NULL;
	node *p1,*p2;
	p1 = (node*)malloc(sizeof(node));
	p1->data =head->data;
	pp=p1;
	while(head->next!=NULL)
	{
		head=head->next;
		p2 = (node*)malloc(sizeof(node));
		p2->data=head->data;
		p1->next = p2;
		p1 = p2;
	}
	p1->next=NULL;
	return pp;
}
node*list::clear()//链表的清空 
{
	node**head=&p;//把头指针的地址放在一个二级指针中 
	node*temp=NULL;//定义一个空的指针 
	while((*head)->next!=NULL)//当头指针的地址的next不为空时 
	{
		temp=(*head)->next;
		free(*head);//释放掉head的空间 
		(*head)=temp;
	}
	if((*head)!=NULL)//当head不为空时 
	{
		free((*head));//释放掉head 
		(*head)=NULL;//head的地址为空 
	}
	return *head;//返回head的地址 
}
void list::delt()//删除链表最后一个节点 
{
	node*&current=p;//地址的引用 
	if(current==NULL)return;//如果链表本身为空，则无法操作 
	node*ne=current->next;
	if(ne==NULL){current=NULL;p=NULL;return;}//如果链表只有一个节点，那么清楚头结点，链表返回空 
	while(ne->next!=NULL) //若以上情况都不是 
	{
		current=ne;	
		ne=ne->next;		//遍历链表，将current指向链表的倒数第二个节点，ne指向链表的最后一个节点 
	}
	current->next=NULL;//最后一个节点赋值为空 
}
int list::lastdata()//得到链表最后一个节点的数值 
{
	node*head=p;
	while(head->next!=NULL)//遍历到链表最后一个节点 
	head=head->next;
	return head->data;//返回最后一个节点的数值 
}
void list::changefirst_to_neg()//把链表的表头变为负数 
{
	node *head=p;
	head->data=head->data*(-1);//返回表头data的负数 
}
int list::length()// 得到链表的长度-1 
{
	int count = 0;//定义计数变量 
	node *head = p;
	while (head->next != NULL)//遍历链表 
	{
		count++;//计数变量自加1 
		head = head->next;
	}
	return count;//返回链表的长度-1 
}
node*list::D_decre_1()//十进制大整数的数值自减1
{

	reverse();
	node*head=p;
	head->data--;
	while(head->data<0)//当末尾为连续的0时，要连续向前借位 
	{
		head->data=9;
		(head->next->data)--;
		head=head->next;
	}
	reverse();
	p=delt_0();
	return p;

}
node*list::B_decre_1()//二进制大整数的数值自减1，原理和十进制一样 
{
	reverse();
	node*head=p;
	head->data--;
	while(head->data<0)//当末尾为连续的0时，要连续向前借位 
	{
		head->data=1;
		(head->next->data)--;
		head=head->next;
	}
	reverse();
	p=delt_0();
	return p;
}
node*list::delt_0()//删除整数前面的无效的0 
{
	node*head=p;
	while(head->data==0&&length()!=0)head=head->next;//如果链表的第一位为1，且链表的长度不为1，那么删除链表的头结点，即头指针后一位 
	node*new_head=head;//定义一个新的头结点 ,把从不为0开始节点赋值给他 
	return new_head;//	返回新的头节点 
 } 
 int list::eaquls_0()//判断大整数是否为0,为0则返回1，否则返回0； 
 {
 	p=delt_0();//先把大整数前面的无效0删除 
 	node*head=p;
 	if(head->data==0)return 1;//如果头节点为0，且不为无效0，那么该大整数即为0，返回1 
 	else return 0;//反之返回0 
 }
