#include"calculate.h"
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

calculate::calculate(list aa, list bb,char ope)//���幹�캯�� 
{
	a=aa;//��һ�������� 
	b=bb;//�ڶ��������� 
	optor=ope;//����� 
}

void calculate::display1()//���ʽ�ӣ� 
{
	a.display() ;
	cout<<'('<<a.length() +1<<"λ"<<')' ;
	if(optor=='+')cout<<" + ";
	else if(optor=='-')cout<<" - ";
	else if(optor=='*')cout<<" * ";
	else if(optor=='/')cout<<" / ";
	else if(optor=='^')cout<<" ^ ";
	b.display() ;
	cout<<'('<<b.length() +1<<"λ"<<')' ;
	cout<<" = ";
}
void calculate::display2()//������ 
{
	a.display() ;
	cout<<'('<<a.length() +1<<"λ"<<')' ;
	if(optor=='/')//���Ϊ��������ô��Ҫ����̣���Ҫ������� 
	{
		cout<<".......";
		b.display() ;
		cout<<'('<<b.length() +1<<"λ"<<')' ;
	}
	cout<<endl; 
} 
void calculate::display3()//������ 
{
	a.display();
	cout << '(' << a.length() + 1 << "λ" << ')';
	cout << " ! ";
	cout << " = ";
}
void calculate::filedisplay2(ofstream&outfile)//����������ļ� 
{
	a.filedisplay(outfile) ;
	if(optor=='/')
	{
		outfile<<".......";
		b.filedisplay(outfile) ;
	}
	outfile<<endl; 
}
int calculate::compare()//������������С�ıȽ� 
{
	node *head1=a.p;
	node *head2=b.p;
	if(a.length()<b.length())return -1;//���a�ĳ���С��b�ĳ��ȣ���ôһ��b���򷵻�-1 
	else if(a.length()>b.length())return 1;// ���b�ĳ���С��a�ĳ��ȣ���ôһ��a���򷵻�1 
	else//������ͬ����� 
	{
		while(head1!=NULL)//��λ�Ƚ� 
		{
			if(head1->data<head2->data)return -1; 
			if(head1->data>head2->data)return 1;
			head1=head1->next;
			head2=head2->next;
		}
		return 0;//֪�����һλ����ͬ����ô������������ͬ������0 
	}
}
void calculate::D_add()//ʮ���Ƽӷ� 
{
	
	if(compare()==-1)//�Ƚ����������������Ϊa��С��Ϊb 
	{
		node *t;
		t=a.p;
		a.p=b.p;
		b.p=t;
	}
	a.reverse();//�����ת�� 
	b.reverse();
	node*b1=b.p;
	node*a1=a.p;
	for (;b1!=NULL;a1=a1->next,b1= b1->next)//�����������ͷ��ʼ���� 
	{	
		int sum = a1->data + b1->data;//��ͬ��λ���			
		if (sum >= 10)//����ʹ��ڵ���10����ȡ��10����һλ��1 
		{
			a1->data  = sum % 10;
			++(a1->next->data);
		}
		else//��֮��ֱ�ӵ��������ĺ� 
		{
			a1->data = sum;
		}
	}
	a.reverse();//����ӵĽ��ת�� 
}
void calculate::D_sub()//ʮ���Ƽ��� 
{
	if(compare()==0)//��������������ȣ���a��������գ�����ֵΪ0 
	{
		a.p=a.clear();
		a.p=a.app(0);
	}
	else{
		int flag=1;
		if(compare()==-1)//������ȣ������жϷ��ţ���a<b,��flagΪ-1���ҽ�a��b���� 
		{
			node *t;
			t=a.p;
			a.p=b.p;
			b.p=t;
			flag=-1;
		}//�Ǵ����Ϊa��С����Ϊb
		 a.reverse() ;//����ת�� 
		 b.reverse() ;
		 node*b1=b.p;
		node*a1=a.p;
		for (;b1!=NULL;a1=a1->next,b1= b1->next)//���������ͷ��ʼ���� 
		{	
			if(a1->data>=b1->data)//���ͬһλ�ϣ�a����ֵ���ڵ���b����ֵ 
			{
				a1->data=a1->data-b1->data;//��λ�Ľ����Ϊ������� 
			}
			else//��֮ 
			{
				a1->data=a1->data+10-b1->data;//��λ��10����� 
				((a1->next)->data)--;//��һλ��1 
			}
		}
		a.reverse();//������ת�� 
		a.delt_0();//ɾ��ͷ����Ч��0 
		if(flag==-1)//�����Ӧ��Ϊ���� 
		a.changefirst_to_neg() ;//������ı�ͷԪ�ر�Ϊ�෴�� 
		}	
}

void calculate::D_multi()//ʮ���Ƴ˷� 
{
	if((a.length()==0&&a.lastdata()==0)||(b.length()==0&&b.lastdata()==0))//���a��b����0 
	{
		a.p=a.clear();//��a�е�������� 
		a.p=a.app(0); //��a��Ϊ0 
	}
	else
	{
		list pa;//��������list���� 
		list pb;
		pa.p=a.copy();//paΪa�Ŀ��� 
		pb.p=b.copy();//pbΪb�Ŀ��� 
		pa.reverse() ;//��pa��pbת�� 
		pb.reverse() ;
		node*b1=pb.p;	
		a.p=a.clear();
		a.p=a.app(0); //��a�е������Ϊ0 
		for(int i=0;b1!=NULL;i++,b1=b1->next)//��������pb 
		{
			list paa;
			paa.p=pa.copy();//��������paaΪpa�Ŀ��� 
			node*a1=paa.p;
			list q;//����list����q�����ڴ��b�е�ÿһλ��a��˵Ľ�� 
			int flag=0;//������¼ǰһλ�Ľ�λ�� 
			for(;a1!=NULL;a1=a1->next)//��������paa 
			{
				int sum=(a1->data)*(b1->data);//��λ��� 
				sum=sum+flag;
				flag=0;//�����󣬽�λ����0 
				q.p=q.app(sum%10);//������qβ��׷�Ӹ�λ���� 
				flag+=(sum/10);//�ٴμ�¼��λ�� 
			}
			q.p=q.app(flag);//�������ֽ�λ��û�н��꣬��ô������һλ������ý�λ�� 
			b.p=q.copy();//bΪq�Ŀ��� 
			q.p=q.clear();//�ٽ�q��գ����������һλ�������� 
			b.reverse() ;//��bת�� 
			for(int j=0;j<i;j++)//��ĩβ���0���Ա�֤λ����ȷ 
			{
				b.p=b.app(0); 
			}
			D_add();//����a������b��� 
		}

	}//�����Ϊ����a��ֵ 

}
void calculate::D_divide()//ʮ���Ƴ��� 
{
	if(b.eaquls_0() ==1)
	{
		cout<<"����Ϊ0�޷�����"<<endl;
		exit(1); 
	 } 		 
	
	else if(compare()==-1)//���������С�ڳ�������ô��Ϊ0��������Ϊ���� 
	{
		a.p=a.clear();
		a.p=a.app(0);
	}
	else if(compare()==0)//���������ȣ���Ϊ1������Ϊ0 
	{
		a.p=a.clear();
		a.p=a.app(1);
		b.p=b.clear();
		b.p=b.app(0);
	 }
	 else
	 {//pa��ʼ��Ϊa����b�ĳ�ʼֵ�� 
	 	list remainder;//����
		list pb,pbb;
		pb.p=b.copy();
		int n=a.length()-b.length();//nΪ��������������֮�� 
		list res;//����list���͵Ķ��󣬴���� 
		for(;n>=0;n--)//�Ȱѳ�������10^n�� 
		{
			int i=0;
			pbb.p=pb.copy();
			for(int j=0;j<n;j++)
			{
				pbb.p=pbb.app(0);
			}
			while(1)//�����ֱ��������С�ڳ��� 
			{
				b.p=pbb.copy();
				a.p=a.delt_0() ;
				if(compare()==-1)break;
				i++;
				D_sub();
			}
			res.p=res.app(i);//ÿ��ѭ�������������ĳ����ĸ�����ŵ����� 
			remainder.p=a.copy();//ʣ��ı��������Ϊ���� 
		}
		a.p=res.copy();//���̴�ŵ�a�� 
		b.p=remainder.copy();//��������ŵ�b�� 
	 } 
}
void calculate::D_exp()//ʮ���Ƶĳ˷� 
{
	if(b.eaquls_0() ==1)//���ָ��Ϊ0�����Ϊ1 
	{
		a.p=a.clear();
		a.p=a.app(1);
	 } 
	 else{	
	 list exp;
	exp.p=b.copy();//����һ��list����Ϊָ���Ŀ��� 
	list pa;
	pa.p=a.copy();//����һ��pa����Ϊ�����Ŀ��� 
	exp.p=exp.D_decre_1();//�Ƚ�ָ��-1 
	while(exp.eaquls_0() !=1)//��ָ����Ϊ0ʱ��ִ�д�ѭ�� 
	{
		b.p=pa.copy();//bΪpa�Ŀ��� 
		D_multi();//��a��b��� 
		exp.p=exp.D_decre_1();//ָ����һ 
	}
	 }
}

void calculate::D_jiechen() 
{
	list pa;
	pa.p = a.copy();//����һ��pa����Ϊ�����Ŀ��� 
	while (pa.eaquls_0() != 1)//��ָ����Ϊ0ʱ��ִ�д�ѭ�� 
	{
		pa.p = pa.D_decre_1();//ָ����һ 
		if (pa.eaquls_0() != 1)
		{
			b.p = pa.copy();//bΪpa�Ŀ��� 
			D_multi();//��a��b��� 		
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
		}//�Ǵ����Ϊa��С����Ϊb
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
		pb.p=b.copy();//����ĸ��� 
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
		cout<<"����Ϊ0�޷�����"<<endl;
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
	 {//pa��ʼ��Ϊa����b�ĳ�ʼֵ�� 
	 	list remainder;//����
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
