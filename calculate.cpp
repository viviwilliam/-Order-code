#include"calculate.h"
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

calculate::calculate(list aa, list bb,char ope)//定义构造函数 
{
	a=aa;//第一个大整数 
	b=bb;//第二个大整数 
	optor=ope;//运算符 
}

void calculate::display1()//输出式子； 
{
	a.display() ;
	cout<<'('<<a.length() +1<<"位"<<')' ;
	if(optor=='+')cout<<" + ";
	else if(optor=='-')cout<<" - ";
	else if(optor=='*')cout<<" * ";
	else if(optor=='/')cout<<" / ";
	else if(optor=='^')cout<<" ^ ";
	b.display() ;
	cout<<'('<<b.length() +1<<"位"<<')' ;
	cout<<" = ";
}
void calculate::display2()//输出结果 
{
	a.display() ;
	cout<<'('<<a.length() +1<<"位"<<')' ;
	if(optor=='/')//如果为除法，那么既要输出商，又要输出余数 
	{
		cout<<".......";
		b.display() ;
		cout<<'('<<b.length() +1<<"位"<<')' ;
	}
	cout<<endl; 
} 
void calculate::display3()//输出结果 
{
	a.display();
	cout << '(' << a.length() + 1 << "位" << ')';
	cout << " ! ";
	cout << " = ";
}
void calculate::filedisplay2(ofstream&outfile)//将答案输出到文件 
{
	a.filedisplay(outfile) ;
	if(optor=='/')
	{
		outfile<<".......";
		b.filedisplay(outfile) ;
	}
	outfile<<endl; 
}
int calculate::compare()//两个大整数大小的比较 
{
	node *head1=a.p;
	node *head2=b.p;
	if(a.length()<b.length())return -1;//如果a的长度小于b的长度，那么一定b大，则返回-1 
	else if(a.length()>b.length())return 1;// 如果b的长度小于a的长度，那么一定a大，则返回1 
	else//长度相同的情况 
	{
		while(head1!=NULL)//逐位比较 
		{
			if(head1->data<head2->data)return -1; 
			if(head1->data>head2->data)return 1;
			head1=head1->next;
			head2=head2->next;
		}
		return 0;//知道最后一位都相同，那么两个大整数相同，返回0 
	}
}
void calculate::D_add()//十进制加法 
{
	
	if(compare()==-1)//比较两个大整数，大的为a，小的为b 
	{
		node *t;
		t=a.p;
		a.p=b.p;
		b.p=t;
	}
	a.reverse();//链表的转置 
	b.reverse();
	node*b1=b.p;
	node*a1=a.p;
	for (;b1!=NULL;a1=a1->next,b1= b1->next)//从两条链表的头开始遍历 
	{	
		int sum = a1->data + b1->data;//相同的位相加			
		if (sum >= 10)//如果和大于等于10，则取余10，下一位进1 
		{
			a1->data  = sum % 10;
			++(a1->next->data);
		}
		else//反之则直接等于两数的和 
		{
			a1->data = sum;
		}
	}
	a.reverse();//将相加的结果转置 
}
void calculate::D_sub()//十进制减法 
{
	if(compare()==0)//若两个大整数相等，则将a的链表清空，并赋值为0 
	{
		a.p=a.clear();
		a.p=a.app(0);
	}
	else{
		int flag=1;
		if(compare()==-1)//若不相等，则先判断符号，若a<b,则flag为-1，且将a和b交换 
		{
			node *t;
			t=a.p;
			a.p=b.p;
			b.p=t;
			flag=-1;
		}//是大的数为a，小的数为b
		 a.reverse() ;//链表转置 
		 b.reverse() ;
		 node*b1=b.p;
		node*a1=a.p;
		for (;b1!=NULL;a1=a1->next,b1= b1->next)//两条链表从头开始遍历 
		{	
			if(a1->data>=b1->data)//如果同一位上，a的数值大于等于b的数值 
			{
				a1->data=a1->data-b1->data;//该位的结果即为两数相减 
			}
			else//反之 
			{
				a1->data=a1->data+10-b1->data;//该位加10，相减 
				((a1->next)->data)--;//下一位减1 
			}
		}
		a.reverse();//将链表转置 
		a.delt_0();//删除头上无效的0 
		if(flag==-1)//若结果应该为负数 
		a.changefirst_to_neg() ;//则将链表的表头元素变为相反数 
		}	
}

void calculate::D_multi()//十进制乘法 
{
	if((a.length()==0&&a.lastdata()==0)||(b.length()==0&&b.lastdata()==0))//如果a或b等于0 
	{
		a.p=a.clear();//将a中的链表清空 
		a.p=a.app(0); //将a变为0 
	}
	else
	{
		list pa;//定义两个list对象 
		list pb;
		pa.p=a.copy();//pa为a的拷贝 
		pb.p=b.copy();//pb为b的拷贝 
		pa.reverse() ;//将pa和pb转置 
		pb.reverse() ;
		node*b1=pb.p;	
		a.p=a.clear();
		a.p=a.app(0); //将a中的链表变为0 
		for(int i=0;b1!=NULL;i++,b1=b1->next)//遍历链表pb 
		{
			list paa;
			paa.p=pa.copy();//定义链表paa为pa的拷贝 
			node*a1=paa.p;
			list q;//定义list对象q，用于存放b中的每一位与a相乘的结果 
			int flag=0;//用来记录前一位的进位数 
			for(;a1!=NULL;a1=a1->next)//遍历链表paa 
			{
				int sum=(a1->data)*(b1->data);//逐位相乘 
				sum=sum+flag;
				flag=0;//相加完后，进位数清0 
				q.p=q.app(sum%10);//在链表q尾部追加该位的数 
				flag+=(sum/10);//再次记录进位数 
			}
			q.p=q.app(flag);//如果最后又进位数没有进完，那么再增加一位来保存该进位数 
			b.p=q.copy();//b为q的拷贝 
			q.p=q.clear();//再将q清空，继续存放下一位的运算结果 
			b.reverse() ;//将b转置 
			for(int j=0;j<i;j++)//在末尾添加0，以保证位数正确 
			{
				b.p=b.app(0); 
			}
			D_add();//链表a和链表b相加 
		}

	}//最后结果为链表a的值 

}
void calculate::D_divide()//十进制除法 
{
	if(b.eaquls_0() ==1)
	{
		cout<<"除数为0无法计算"<<endl;
		exit(1); 
	 } 		 
	
	else if(compare()==-1)//如果被除数小于除数，那么商为0，余数即为除数 
	{
		a.p=a.clear();
		a.p=a.app(0);
	}
	else if(compare()==0)//如果两数相等，商为1，余数为0 
	{
		a.p=a.clear();
		a.p=a.app(1);
		b.p=b.clear();
		b.p=b.app(0);
	 }
	 else
	 {//pa是始终为a、和b的初始值； 
	 	list remainder;//余数
		list pb,pbb;
		pb.p=b.copy();
		int n=a.length()-b.length();//n为两个大整数长度之差 
		list res;//定义list类型的对象，存放商 
		for(;n>=0;n--)//先把除数扩大到10^n倍 
		{
			int i=0;
			pbb.p=pb.copy();
			for(int j=0;j<n;j++)
			{
				pbb.p=pbb.app(0);
			}
			while(1)//相减，直到被除数小于除数 
			{
				b.p=pbb.copy();
				a.p=a.delt_0() ;
				if(compare()==-1)break;
				i++;
				D_sub();
			}
			res.p=res.app(i);//每次循环结束将减掉的除数的个数存放到商中 
			remainder.p=a.copy();//剩余的被除数则变为余数 
		}
		a.p=res.copy();//将商存放到a中 
		b.p=remainder.copy();//将余数存放到b中 
	 } 
}
void calculate::D_exp()//十进制的乘方 
{
	if(b.eaquls_0() ==1)//如果指数为0，则答案为1 
	{
		a.p=a.clear();
		a.p=a.app(1);
	 } 
	 else{	
	 list exp;
	exp.p=b.copy();//定义一个list对象，为指数的拷贝 
	list pa;
	pa.p=a.copy();//定义一个pa对象，为底数的拷贝 
	exp.p=exp.D_decre_1();//先将指数-1 
	while(exp.eaquls_0() !=1)//当指数不为0时，执行此循环 
	{
		b.p=pa.copy();//b为pa的拷贝 
		D_multi();//将a，b相乘 
		exp.p=exp.D_decre_1();//指数减一 
	}
	 }
}

void calculate::D_jiechen() 
{
	list pa;
	pa.p = a.copy();//定义一个pa对象，为底数的拷贝 
	while (pa.eaquls_0() != 1)//当指数不为0时，执行此循环 
	{
		pa.p = pa.D_decre_1();//指数减一 
		if (pa.eaquls_0() != 1)
		{
			b.p = pa.copy();//b为pa的拷贝 
			D_multi();//将a，b相乘 		
		}

	}
}

void calculate::B_add()
{	
	if(compare()==-1)
	{
		node *t;
		t=a.p;
		a.p=b.p;
		b.p=t;
	}
	a.reverse();
	b.reverse();
	node*b1=b.p;
	node*a1=a.p;
	for (;b1!=NULL;a1=a1->next,b1= b1->next)
	{	
		int sum = a1->data + b1->data;
		if (sum >= 2)
		{
			a1->data  = sum % 2;
			if(a1->next==NULL)a1=a.app(1);
			else (a1->next->data)++;
		}
		else
		{
			a1->data = sum;
		}
	}
	for(;a1!=NULL;a1=a1->next)
		{
			if(a1->data==2){
			a1->data-=2;
			if(a1->next==NULL)a1=a.app(1);
			else (a1->next->data)++;
			}
		}
	
	a.reverse();
}
void calculate::B_sub()
{
	if(compare()==0)
	{
		a.p=a.clear();
		a.p=a.app(0);
	}
	else{
		int flag=1;
		if(compare()==-1)
		{
			node *t;
			t=a.p;
			a.p=b.p;
			b.p=t;
			flag=-1;
		}//是大的数为a，小的数为b
		 a.reverse() ;
		 b.reverse() ;
		 node*b1=b.p;
		node*a1=a.p;
		for (;b1!=NULL;a1=a1->next,b1= b1->next)
		{	
			if(a1->data>=b1->data)
			{
				a1->data=a1->data-b1->data;
			}
			else
			{
				a1->data=a1->data+2-b1->data;
				((a1->next)->data)--;
			}
		}
		for(;a1!=NULL;a1=a1->next)
		{
			if(a1->data<0){a1->data+=2;(a1->next->data)--;
			}
		}
		a.reverse();
		a.delt_0();
		if(flag==-1)
		a.changefirst_to_neg() ;
		}	
}

void calculate::B_multi()
{
	if((a.length()==0&&a.lastdata()==0)||(b.length()==0&&b.lastdata()==0))
	{
		a.p=a.clear();
		a.p=a.app(0); 
	}
	else
	{
		list pa;
		list pb;
		pa.p=a.copy();
		pb.p=b.copy();//对象的复制 
		pa.reverse() ;
		pb.reverse() ;
		node*b1=pb.p;	
		a.p=a.clear();
		a.p=a.app(0); 
		for(int i=0;b1!=NULL;i++,b1=b1->next)
		{
			list paa;
			paa.p=pa.copy();
			node*a1=paa.p;
			list q;
			int flag=0;
			for(;a1!=NULL;a1=a1->next)
			{
				int sum=(a1->data)*(b1->data);
				sum=sum+flag;
				flag=0;
				q.p=q.app(sum%2);
				flag+=(sum/2);
			}
			q.p=q.app(flag);
			b.p=q.copy();
			q.p=q.clear();
			b.reverse() ;
			for(int j=0;j<i;j++)
			{
				b.p=b.app(0); 
			}
			B_add();
		}

	}

}
void calculate::B_divide()
{
	if(b.eaquls_0() ==1)
	{
		cout<<"除数为0无法计算"<<endl;
		exit(1); 
	 } 	 
	
	else if(compare()==-1)
	{
		a.p=a.clear();
		a.p=a.app(0);
	}
	else if(compare()==0)
	{
		a.p=a.clear();
		a.p=a.app(1);
		b.p=b.clear();
		b.p=b.app(0);
	 }
	 else
	 {//pa是始终为a、和b的初始值； 
	 	list remainder;//余数
		list pb,pbb;
		pb.p=b.copy();
		int n=a.length()-b.length();
		list res;
		for(;n>=0;n--)
		{
			int i=0;
			pbb.p=pb.copy();
			for(int j=0;j<n;j++)
			{
				pbb.p=pbb.app(0);
			}
			while(1)
			{
				b.p=pbb.copy();
				a.p=a.delt_0() ;
				if(compare()==-1)break;
				i++;
				B_sub();
			}
			res.p=res.app(i);
			remainder.p=a.copy();
		}
		a.p=res.copy();
		b.p=remainder.copy();
	 } 
}
void calculate::B_exp()
{
	if(b.eaquls_0() ==1)
	{
		a.p=a.clear();
		a.p=a.app(1);
	 } 
	 else{
	 	list exp;
		exp.p=b.copy();
		list pa;
		pa.p=a.copy();
		exp.p=exp.B_decre_1();
		while(exp.eaquls_0() !=1)
		{
			b.p=pa.copy();
			B_multi();
			exp.p=exp.B_decre_1();
		}
	 }
	
}
