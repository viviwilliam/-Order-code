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
typedef struct DulNode {//˫������洢�ṹ
	struct DulNode* prior;//ǰָ��
	struct DulNode* next;//��ָ��
	int data;//�ڵ�����
}DulNode, * DuList;

int InistList(DuList& L, char fh)//��������������ʼ��,fhΪ���ű�ʶ��
{
	L = (DuList)malloc(sizeof(DulNode));//��̬����洢�ռ�
	if (fh == '-') L->data = 1;//L->data��ŷ��Žڵ㣬����ǡ�-����Ϊ1������Ϊ0
	else L->data = 0;
	L->prior = L;
	L->next = L;
	return OK;
}

int DestroyList(DuList & L)
{
	DuList p, q;//���������ṹ��ָ��
	if (!L)return ERROR;//��������
	p = L->prior;//pָ������ͷ�ڵ��ǰ��
	while (p != L)//ɾ���ڵ�ڵ�p
	{
		q = p->prior;
		free(p);//�ͷŽڵ�p�Ŀռ�
		p = q;
	}
	free(L);//�ͷ�����L�Ĵ洢�ռ�
	return OK;
}

int Insfirst(DuList & L, int e)//��ͷ��������½ڵ�p
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

int Inslast(DuList & L, int e)//�������������½ڵ�
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

int CountNode(DuList L)//��������Ľڵ���
{
	DuList p;
	p = L;
	int i;
	for (i = 0; p->next != L; i++, p = p->next);
	return i;
}

int Count(int e)//����ڵ�Ԫ��e��λ��
{
	int i, k;
	for (i = 1, k = 1000; e / k <= 0; i++, k = k / 10);
	return i;
}

int Dzero(DuList & L)//ȥ����Ч0����
{
	DuList p;
	if (CountNode(L) <= 1)return ERROR;//����ڵ�Ϊ��
	p = L->next;
	while (!p->data)p = p->next;
	L->next = p;
	p->prior = L;
	return OK;
}

int CountB(DuList L)//���㳤����λ������
{
	if (L->next == L)return 0;//������
	Dzero(L);//ɾ��0
	int i;
	i = Count(L->next->data) + (CountNode(L) - 1) * 4;//ͷ�ڵ����ݵ�λ�����Ͻڵ����*4��ÿ���ڵ�����λ��
	return i;
}

int ConversionD(char* s, int i, int& e)//���ַ�ת��Ϊ����
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

int Creat(DuList & L, char* s)//ͨ����Ӧ���ַ�����������
{
	int i = 0;
	int e;
	InistList(L, s[0]);
	if (*s == '-')
		s++;//������Ϊ����
	while (*s != '\0')//ÿ���ڵ��������λ������i=������ʱ��i�ִ��㿪ʼ���𣬰ѡ��������뵽��β�����β
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
	ConversionD(s, i, e);//���ǡ�������ֱ�Ӳ��뵽�����β��
	Inslast(L, e);


	return OK;
}

int Cmp(DuList L, DuList K)//�����ͬʱ�ıȽ�������С����
{
	DuList p, q;
	p = L->next;
	q = K->next;
	while (p != L && q != K)//��������û����
	{
		if (p->data > q->data) return 1;//p����ֵ>q��ֵ
		if (p->data < q->data) return -1;//p����ֵ<q��ֵ
		p = p->next;
		q = q->next;
	}
	return 0;
}


int print(DuList L)//���������
{
	int i;
	DuList p;
	if (L->data == 1 && L->next->data == 0)//��������-0����ű�ʶ��0�����0
		L->data = 0;
	if (L->data == 1 && L->next->data != 0)
		cout << "-";//�������
	p = L->next;
	while (p->data == 0 && p->next != L)//������Ч��
		p = p->next;
	if (p == L)      //���0
	{
		cout << 0;
		return OK;
	}
	if (p->next == L)     //p�����һ���ڵ㣬������һ��������ֵ
	{
		cout << p->data;
		return OK;
	}
	if (p->next != L)//p�������һ���ڵ㣬�����ֵ���������������Ϊ�ָ���
		cout << p->data << ',';
	p = p->next;
	while (p->next != L)    //ѭ�����������������
	{
		if (p->data == 0) cout << "0000" << ",";
		else
		{
			for (i = 1; i < Count(p->data); i++)//�ڵ������ĳһλΪ0�������0�����������ֵ
				cout << '0';
			cout << p->data << ",";
		}
		p = p->next;
	}
	if (p->data == 0) cout << "0000";//������һ���ڵ����ֵ
	else
	{
		for (i = 1; i < Count(p->data); i++)
			cout << '0';
		cout << p->data;
	}
	return OK;
}
DuList add(DuList L, DuList K, char fh)//�޷��żӷ�,fhΪ���ű�ʶ��
{
	int temp, cf = 0;
	DuList p, q, R;
	InistList(R, fh);
	p = L->prior;
	q = K->prior;
	while (p != L && q != K)        //�����һ���ڵ㿪ʼ���мӷ�������10000
	{
		temp = p->data + q->data + cf;
		if (temp >= 10000)//������ӵĺʹ���10000��temp=temp-10000�ҽ�λ��ʶΪ1
		{
			Insfirst(R, temp - temp / 10000 * 10000);
			cf = 1;
		}
		else
		{
			Insfirst(R, temp);//�޽�λ
			cf = 0;
		}
		p = p->prior;//p��ǰ����
		q = q->prior;//q��ǰ����
	}
	while (p != L)//K���꣬L����û�ӵģ�p���Ͻ�λ
	{
		temp = p->data + cf;
		cf = temp / 10000;
		Insfirst(R, temp - temp / 10000 * 10000);
		p = p->prior;
	}
	while (q != K)//L���꣬K����û�ӵģ�q�ӽ�λ
	{
		temp = q->data + cf;
		cf = temp / 10000;
		Insfirst(R, temp - temp / 10000 * 10000);
		q = q->prior;
	}
	if (cf != 0) Insfirst(R, cf);//����ж��Ƿ��н�λ��������������ͷ����һ���ڵ㣬����Ϊ��λ
	return R;
}

DuList sub(DuList L, DuList K, char fh)//�޷��ż�������,fhΪ���ű�ʶλ
{
	DuList p, q, R;
	int temp, cf = 0;
	InistList(R, fh);
	p = L->prior;
	q = K->prior;
	while (p != L && q != K)//���м������������ͽ�λ
	{
		temp = p->data - q->data - cf;//�����������ȥ��λ
		if (temp < 0)//�н�λ
		{
			temp = temp + 10000;
			Insfirst(R, temp);
			cf = 1;//�н�λ
		}
		else
		{
			Insfirst(R, temp);//�޽�λ
			cf = 0;
		}
		p = p->prior;
		q = q->prior;
	}
	while (p != L && cf)//���꣬���н�λ
	{
		if (p->data - cf == 0 && p->prior == L)//��ȥ��λ 
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
	while (p != L)//��Lʣ�µĶ����ƹ��������
	{
		Insfirst(R, p->data);
		p = p->prior;
	}
	return R;
}

DuList Computing(DuList L, DuList K, char ys)//����������ƺ���
{
	DuList R;
	char fh = 'h';
	InistList(R, fh);
	Dzero(L);//ɾȥL��K��Ч0
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
	else//�������Ǹ���������������
	{
		if (CountNode(L) > CountNode(K)) R = sub(L, K, '-');
		else if (CountNode(L) < CountNode(K)) R = sub(K, L, '+');			       else if (Cmp(L, K) == 1 || Cmp(L, K) == 0) R = sub(L, K, '-');
		else if (Cmp(L, K) == -1) R = sub(K, L, '+');
	}
	return R;
}

int PanGS(char* s)//�ж������ʽ
{
	int k, i = 1;
	if (*s < 48 && *s != '-' || *s>57) return ERROR;//����Ĳ�������Ҳ���ǡ�-��������
	if (*s == '-') k = 0;//�������Ų�����ڵ�λ��
	else k = 1;
	while (*(s + i) != ',' && *(s + i) != '\0')//������ַ�����','��'\0'���������
	{
		if (*(s + i) < 48 || *(s + i) > 57)
			return ERROR;
		k++;
		i++;
	}
	if (k > 4) return ERROR;//ÿ���ڵ�������ַ�����4�����������
	if (*(s + i) == '\0')
		return OK;//�������
	k = 4;
	while (*(s + i) != '\0')//����Ĳ��ǡ�\0�����Ҳ��ǡ��������������
	{
		if (*(s + i) < '0' && *(s + i) != ',' || *(s + i) > '9')
			return ERROR;
		if (*(s + i) == ',')//���������������k��-1��ʼ�㱣֤ÿ���ڵ�λ������λ
		{
			if (k != 4)//�м�ڵ��λ��������λ���������
				return ERROR;
			k = -1;
		}
		k++;//���������������k���㿪ʼ
		i++;
	}
	if (k != 4)
		return ERROR;
	return OK;
}

int InputS(char* cz, char* cz1)//�Ӽ�����������������
{
	cout << "�����볤����!" << endl;
	cout << "������1:";
	cin >> cz;
	while (!PanGS(cz))//�ж������ʽ�Ƿ���ȷ 
	{
		cout << "�����ʽ����,����������!" << endl
			<< "�����ʽӦΪ��XXXX��XXXX��XXXX������XXXX(X������)" << endl << "������1:";
		cin >> cz;//���������������
	}
	cout << "������2:";
	cin >> cz1;
	while (!PanGS(cz1))//�ж������ʽ�Ƿ���ȷ
	{
		cout << "�����ʽ����,����������!" << endl
			<< "�����ʽӦΪ��XXXX��XXXX��XXXX������XXXX(X������)" << endl << "������2:";
		cin >> cz1;//���������������
	}
	return OK;
}

int main()
{
	int optor2;//����һ���ַ����� 
	cout << "��������Ҫ����Ҫ���е�����   1���Ӽ��˳��˷��׳�   2���������Ӽ�";
	cin >> optor2;//�û��Ӽ���������������� 
	if (optor2 == 1)
	{
		//ofstream outfile2("f2.txt", ios::app);
		clock_t start, finish;//�����ʱ�� 
		while (1) {
			char optor1;//����һ���ַ����� 
			cout << "������Ҫ���е����㣺";
			cin >> optor1;//�û��Ӽ���������������� 
			if (optor1 == '+')
			{
				cout << "�������һ��ʮ���ƴ�������";
				string str1, str2;    //���������ַ��� 
				cin >> str1;//�����һ���ַ��� 
				cout << "������ڶ���ʮ���ƴ�������";
				cin >> str2;//����ڶ����ַ��� 
				start = clock();//��ʼ��ʱ 
				list A(str1);//����һ����str1Ϊ������list���� 
				list B(str2);//����һ����str2Ϊ������list���� 
				calculate val1(A, B, optor1);//����һ��calculate����	
				val1.display1();//��������ʽ�� 
				val1.D_add();
				val1.display2();//��������� 
			}//���мӷ����� 
			if (optor1 == '-')
			{
				cout << "�������һ��ʮ���ƴ�������";
				string str1, str2;    //���������ַ��� 
				cin >> str1;//�����һ���ַ��� 
				cout << "������ڶ���ʮ���ƴ�������";
				cin >> str2;//����ڶ����ַ��� 
				start = clock();//��ʼ��ʱ 
				list A(str1);//����һ����str1Ϊ������list���� 
				list B(str2);//����һ����str2Ϊ������list���� 
				calculate val1(A, B, optor1);//����һ��calculate����	
				val1.display1();//��������ʽ�� 
				val1.D_sub();
				val1.display2();//��������� 
			}//���м������� 
			if (optor1 == '*')
			{
				cout << "�������һ��ʮ���ƴ�������";
				string str1, str2;    //���������ַ��� 
				cin >> str1;//�����һ���ַ��� 
				cout << "������ڶ���ʮ���ƴ�������";
				cin >> str2;//����ڶ����ַ��� 
				start = clock();//��ʼ��ʱ 
				list A(str1);//����һ����str1Ϊ������list���� 
				list B(str2);//����һ����str2Ϊ������list���� 
				calculate val1(A, B, optor1);//����һ��calculate����	
				val1.display1();//��������ʽ�� 
				val1.D_multi();
				val1.display2();//��������� 
			}//���г˷����� 
			if (optor1 == '/')
			{
				cout << "�������һ��ʮ���ƴ�������";
				string str1, str2;    //���������ַ��� 
				cin >> str1;//�����һ���ַ��� 
				cout << "������ڶ���ʮ���ƴ�������";
				cin >> str2;//����ڶ����ַ��� 
				start = clock();//��ʼ��ʱ 
				list A(str1);//����һ����str1Ϊ������list���� 
				list B(str2);//����һ����str2Ϊ������list���� 
				calculate val1(A, B, optor1);//����һ��calculate����	
				val1.display1();//��������ʽ�� 
				val1.D_divide();
				val1.display2();//��������� 
			}//���г������� 
			if (optor1 == '^')
			{
				cout << "�������һ��ʮ���ƴ�������";
				string str1, str2;    //���������ַ��� 
				cin >> str1;//�����һ���ַ��� 
				cout << "������ڶ���ʮ���ƴ�������";
				cin >> str2;//����ڶ����ַ��� 
				start = clock();//��ʼ��ʱ 
				list A(str1);//����һ����str1Ϊ������list���� 
				list B(str2);//����һ����str2Ϊ������list���� 
				calculate val1(A, B, optor1);//����һ��calculate����	
				val1.display1();//��������ʽ�� 
				val1.D_exp();
				val1.display2();//��������� 
			}//���г˷����� 
			if (optor1 == '!')
			{
				cout << "�������һ��ʮ���ƴ�������";
				string str1, str2;    //���������ַ��� 
				cin >> str1;//�����һ���ַ��� 
				str2 = "1";//����ڶ����ַ��� 
				start = clock();//��ʼ��ʱ 
				list A(str1);//����һ����str1Ϊ������list���� 
				list B(str2);//����һ����str2Ϊ������list���� 
				calculate val1(A, B, optor1);//����һ��calculate����	
				val1.display3();//��������ʽ�� 
				val1.D_jiechen();
				val1.display2();//��������� 
			}
			finish = clock();//��ʱ���� 

			cout << "��������ʱ���ǣ�" << finish - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;//�������ʱ��
			cout << "1.��������" << endl;
			cout << "2.�˳�����" << endl;
			cout << "������1��2" << endl;
			int key3;
			cin >> key3;
			if (key3 == 2)exit(1);
		}
	}
	else
	{
	char cz[99999];      //�����ַ������飬���ﱣ��Ӽ�������ĳ�����
	char cz1[99999];
	DuList L1, L2, R;
	int flag = 1;
	char xz;
	cout << "*************************************************************" << endl
		<< "                   ��ӭʹ�ó������ӷ�������!" << endl
		<< "*************************************************************"
		<< endl
		<< "�������������ʽΪ��XXXX��XXXX��XXXX������XXXX;" << endl;
	while (1)//�жϼ�����Ƿ�Ϊ��Ч����
	{
		InputS(cz, cz1);//�Ӽ������볤������ʽ���ַ�����ͬʱ�б������ʽ 
		Creat(L1, cz);//�ѳ������ַ���ת��Ϊѭ������Ĵ���ṹ
		Creat(L2, cz1);
		R = Computing(L1, L2, '+');
		cout << "������:";
		print(R);//����Գ�������׼��ʽ���
		cout << endl;
		DestroyList(L1);//���ٺ��������ͷſռ�
		DestroyList(L2);
		DestroyList(R);
	}
	}

	return 0;
}
