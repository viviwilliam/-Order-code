#include"list.h"//����Listͷ�ļ� 
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<cmath>
#include<iostream>
using namespace std;

list::list()//��������һ������Ϊһ����������ÿ���ڵ�����ݲ��־�Ϊ��λ��������
{
	p=NULL;//����Ϊ�� 
}
list::list(string str)
{
	node*p1, *p2;//��������node���͵�ָ�� 
	p= NULL;//�Ȱ�ͷ�ڵ�p��ֵΪ�� 
	p1 = (node*)malloc(sizeof(node));//��p1���䶯̬�ռ� 
	p1->data = str[0]-48;//���ַ����ĵ�һ���ַ�����p1��data�� �������ַ���ASCIIֵ-48Ϊ���ֱ��� 
	p= p1;//��p1��ֵ��ͷ��� 
	for(int i=1;i<str.length();i++)//forѭ�����ַ�����ÿ���ַ������������� 
	{
		p2 = (node*)malloc(sizeof(node));//��p2���䶯̬�ڴ�ռ� 
		p2->data=str[i]-48;//��p2��data��ֵ 
		p1->next = p2;//ѭ��ʹ��p1��p2��������ӽڵ� 
		p1 = p2;
	}
	p1->next=NULL;//β�ڵ��nextΪ�� 

}
void list::display()//�����������
{
	p=delt_0();//�������ǰ׺����Ч��0ɾ�� 
	node*head=p;//��ͷ��㸳ֵ��head�������ں���������ͷ��㶪ʧ 
	while (head != NULL)//�ж�ѭ���Ƿ�ִ�е������ 
	{
		cout << head->data;//���û��ִ�еõ������ô�����ǰ�ڵ������ 
		head = head->next;//headָ����һ���ڵ� 
	}
}
void list::filedisplay(ofstream&outfile1)//������������ļ�
{ 
	p=delt_0();//�������ǰ׺����Ч��0ɾ�� 
	node*head=p;//��ͷ��㸳ֵ��head�������ں���������ͷ��㶪ʧ 
	while (head != NULL)//�ж�ѭ���Ƿ�ִ�е������ 
	{
		outfile1<< head->data;//���û��ִ�еõ������ô�����ǰ�ڵ�����ݵ�ָ���ļ� 
		head = head->next;//headָ����һ���ڵ� 
	}
} 
node* list::app(int num)//������β��׷��ָ������ 
{
	node*head=p;//�������ͷ��㸳ֵ��head 
	node *p1=(node*)malloc(sizeof(node));//����ӵĽڵ���䶯̬�ڴ�ռ� 
	p1->data =num;//�Ѹýڵ��data���ָ�ֵΪnum 
	if(head==NULL) {head=p1;head->next=NULL;p=head;return p;}//��headΪ�գ���ô˵��������Ϊ�գ���ӵĸýڵ�Ϊͷ��㣬
	                                                     //��p1��ֵ��head��head��nextָ��� ���ٰ�head������p������ͷ��� 
	else//������ӵĽڵ��Ϊ�������β�ڵ� 
	{
		while(head->next!=NULL) head=head->next;//��ָ���������ֱ��ָ��ָ����������һ���ڵ�	
		head->next=p1;//��β�ڵ��nextָ��p1 
		p1->next =NULL;	//p1��nextָ��null������p1��Ϊ�������β�ڵ� 
	}
	return p;//����ͷ���p 
}
void list::reverse()//������������洢����Ϊ����ʱ��Ҫ�Ӹ�λ��ʼ����
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
node *list::copy()//����������Ӹ��� 
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
node*list::clear()//�������� 
{
	node**head=&p;//��ͷָ��ĵ�ַ����һ������ָ���� 
	node*temp=NULL;//����һ���յ�ָ�� 
	while((*head)->next!=NULL)//��ͷָ��ĵ�ַ��next��Ϊ��ʱ 
	{
		temp=(*head)->next;
		free(*head);//�ͷŵ�head�Ŀռ� 
		(*head)=temp;
	}
	if((*head)!=NULL)//��head��Ϊ��ʱ 
	{
		free((*head));//�ͷŵ�head 
		(*head)=NULL;//head�ĵ�ַΪ�� 
	}
	return *head;//����head�ĵ�ַ 
}
void list::delt()//ɾ���������һ���ڵ� 
{
	node*&current=p;//��ַ������ 
	if(current==NULL)return;//���������Ϊ�գ����޷����� 
	node*ne=current->next;
	if(ne==NULL){current=NULL;p=NULL;return;}//�������ֻ��һ���ڵ㣬��ô���ͷ��㣬�����ؿ� 
	while(ne->next!=NULL) //��������������� 
	{
		current=ne;	
		ne=ne->next;		//����������currentָ������ĵ����ڶ����ڵ㣬neָ����������һ���ڵ� 
	}
	current->next=NULL;//���һ���ڵ㸳ֵΪ�� 
}
int list::lastdata()//�õ��������һ���ڵ����ֵ 
{
	node*head=p;
	while(head->next!=NULL)//�������������һ���ڵ� 
	head=head->next;
	return head->data;//�������һ���ڵ����ֵ 
}
void list::changefirst_to_neg()//������ı�ͷ��Ϊ���� 
{
	node *head=p;
	head->data=head->data*(-1);//���ر�ͷdata�ĸ��� 
}
int list::length()// �õ�����ĳ���-1 
{
	int count = 0;//����������� 
	node *head = p;
	while (head->next != NULL)//�������� 
	{
		count++;//���������Լ�1 
		head = head->next;
	}
	return count;//��������ĳ���-1 
}
node*list::D_decre_1()//ʮ���ƴ���������ֵ�Լ�1
{

	reverse();
	node*head=p;
	head->data--;
	while(head->data<0)//��ĩβΪ������0ʱ��Ҫ������ǰ��λ 
	{
		head->data=9;
		(head->next->data)--;
		head=head->next;
	}
	reverse();
	p=delt_0();
	return p;

}
node*list::B_decre_1()//�����ƴ���������ֵ�Լ�1��ԭ���ʮ����һ�� 
{
	reverse();
	node*head=p;
	head->data--;
	while(head->data<0)//��ĩβΪ������0ʱ��Ҫ������ǰ��λ 
	{
		head->data=1;
		(head->next->data)--;
		head=head->next;
	}
	reverse();
	p=delt_0();
	return p;
}
node*list::delt_0()//ɾ������ǰ�����Ч��0 
{
	node*head=p;
	while(head->data==0&&length()!=0)head=head->next;//�������ĵ�һλΪ1��������ĳ��Ȳ�Ϊ1����ôɾ�������ͷ��㣬��ͷָ���һλ 
	node*new_head=head;//����һ���µ�ͷ��� ,�ѴӲ�Ϊ0��ʼ�ڵ㸳ֵ���� 
	return new_head;//	�����µ�ͷ�ڵ� 
 } 
 int list::eaquls_0()//�жϴ������Ƿ�Ϊ0,Ϊ0�򷵻�1�����򷵻�0�� 
 {
 	p=delt_0();//�ȰѴ�����ǰ�����Ч0ɾ�� 
 	node*head=p;
 	if(head->data==0)return 1;//���ͷ�ڵ�Ϊ0���Ҳ�Ϊ��Ч0����ô�ô�������Ϊ0������1 
 	else return 0;//��֮����0 
 }
