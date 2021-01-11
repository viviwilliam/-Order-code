#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -1

typedef struct DulNode{//˫������洢�ṹ 
	struct DulNode* prior;//ǰָ�� 
	struct DulNode* next;//��ָ�� 
	int data;//�ڵ����� 
}DulNode,* DuList;


typedef struct node //����һ���ڵ����� 
{
	int data;//������� 
	struct node *next;//�����һ���ڵ��λ�� 
}node;
//----------------------------------------------------------------------------------------

int length(node* p)// �õ�����ĳ���-1 
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

node *delt_0(node *p)//ɾ������ǰ�����Ч��0 
{
	node *head=p;
	while(head->data==0&&length(p)!=0)
		head=head->next;//�������ĵ�һλΪ1��������ĳ��Ȳ�Ϊ1����ôɾ�������ͷ��㣬��ͷָ���һλ 
	node* new_head=head;//����һ���µ�ͷ��� ,�ѴӲ�Ϊ0��ʼ�ڵ㸳ֵ���� 
	return new_head;//	�����µ�ͷ�ڵ� 
 } 


node * display(node*p){
	p = delt_0(p);
	node*head=p;//��ͷ��㸳ֵ��head�������ں���������ͷ��㶪ʧ 
	while (head != NULL)//�ж�ѭ���Ƿ�ִ�е������ 
	{
		printf("%d",head->data);//���û��ִ�еõ������ô�����ǰ�ڵ������ 
		head = head->next;//headָ����һ���ڵ� 
	}
	return p;
}

node* app(node* p,int num)//������β��׷��ָ������ 
{
	
	node*head=p;//�������ͷ��㸳ֵ��head 
	node *p1=(node*)malloc(sizeof(node));//����ӵĽڵ���䶯̬�ڴ�ռ� 
	p1->data =num;//�Ѹýڵ��data���ָ�ֵΪnum 
	if(head==NULL) {
		head=p1;
		head->next=NULL;
		p=head;
		return p;
	}//��headΪ�գ���ô˵��������Ϊ�գ���ӵĸýڵ�Ϊͷ��㣬                                                  //��p1��ֵ��head��head��nextָ��� ���ٰ�head������p������ͷ��� 
	else//������ӵĽڵ��Ϊ�������β�ڵ� 
	{
		while(head->next!=NULL) 
			head=head->next;//��ָ���������ֱ��ָ��ָ����������һ���ڵ�	
		head->next=p1;//��β�ڵ��nextָ��p1 
		p1->next =NULL;	//p1��nextָ��null������p1��Ϊ�������β�ڵ� 
	return p;//����ͷ���p 
	}
	
}

node* reverse(node *p)//������������洢����Ϊ����ʱ��Ҫ�Ӹ�λ��ʼ����
{
	node*head = p;
	node *pre;
	node *cur;
    node *nex;
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
	return p;
}

node * copy(node* p)//����������Ӹ��� 
{
	node*head=p; 
	node*pp=NULL;
	node *p1;
	node *p2;
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

node* clear(node* p)//�������� 
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
//--------------------------------------test-----------------------
void delt(node* p)//ɾ���������һ���ڵ� 
{
	node* current=p;//��ַ������ 
	if(current==NULL)
		return;//���������Ϊ�գ����޷����� 
	node*ne=current->next;
	if(ne==NULL){
		current=NULL;
		p=NULL;
		return;
	}//�������ֻ��һ���ڵ㣬��ô���ͷ��㣬�����ؿ� 
	while(ne->next!=NULL) //��������������� 
	{
		current=ne;	
		ne=ne->next;		//����������currentָ������ĵ����ڶ����ڵ㣬neָ����������һ���ڵ� 
	}
	current->next=NULL;//���һ���ڵ㸳ֵΪ�� 
}


int lastdata(node *p)//�õ��������һ���ڵ����ֵ 
{
	node*head=p;
	while(head->next!=NULL)//�������������һ���ڵ� 
	head=head->next;
	return head->data;//�������һ���ڵ����ֵ 
}

void changefirst_to_neg(node *p)//������ı�ͷ��Ϊ���� 
{
	node *head=p;
	head->data=head->data*(-1);//���ر�ͷdata�ĸ��� 
}

node* D_decre_1(node *p)//ʮ���ƴ���������ֵ�Լ�1
{

	p = reverse(p);
	node*head=p;
	head->data--;
	while(head->data<0)//��ĩβΪ������0ʱ��Ҫ������ǰ��λ 
	{
		head->data=9;
		(head->next->data)--;
		head=head->next;
	}
	p = reverse(p);
	p=delt_0(p);
	return p;

}
/*
node*B_decre_1()//�����ƴ���������ֵ�Լ�1��ԭ���ʮ����һ�� 
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
}*/

 int eaquls_0(node *p)//�жϴ������Ƿ�Ϊ0,Ϊ0�򷵻�1�����򷵻�0�� 
 {
 	p=delt_0(p);//�ȰѴ�����ǰ�����Ч0ɾ�� 
 	node*head=p;
 	if(head->data==0)
		return 1;//���ͷ�ڵ�Ϊ0���Ҳ�Ϊ��Ч0����ô�ô�������Ϊ0������1 
 	else 
		return 0;//��֮����0 
 }



node * list(node *p,char str[]){
	int i;
	node *p1;
	node *p2;
	p = NULL;
	p1 = (node*)malloc(sizeof(node));//��p1���䶯̬�ռ� 
	p1->data = str[0]-48;//���ַ����ĵ�һ���ַ�����p1��data�� �������ַ���ASCIIֵ-48Ϊ���ֱ���
//	printf("%d",p1->data);
	p= p1;//��p1��ֵ��ͷ��� 
	for(i=1;str[i]!='\0';i++)//forѭ�����ַ�����ÿ���ַ������������� 
	{
		p2 = (node*)malloc(sizeof(node));//��p2���䶯̬�ڴ�ռ� 
		p2->data=str[i]-48;//��p2��data��ֵ 
		//printf("%d",p2->data);
		p1->next = p2;//ѭ��ʹ��p1��p2��������ӽڵ� 
		p1 = p2;
	}
	p1->next=NULL;//β�ڵ��nextΪ�� 
	
	return p;
}

int compare(node*a,node*b)//������������С�ıȽ� 
{
	node *head1=a;
	node *head2=b;
	if(length(a)<length(b))
	  return -1;//���a�ĳ���С��b�ĳ��ȣ���ôһ��b���򷵻�-1 
	else if(length(a)>length(b))
	  return 1;// ���b�ĳ���С��a�ĳ��ȣ���ôһ��a���򷵻�1 
	else//������ͬ����� 
	{
		while(head1!=NULL)//��λ�Ƚ� 
		{
			if(head1->data<head2->data)
			   return -1; 
			if(head1->data>head2->data)
			   return 1;
			head1=head1->next;
			head2=head2->next;
		}
		return 0;//֪�����һλ����ͬ����ô������������ͬ������0 
	}
}




//�ӵ�a���� 
node* D_add(node *a,node *b)//ʮ���Ƽӷ� 
{

	if(compare(a,b)==-1)//�Ƚ����������������Ϊa��С��Ϊb 
	{
		node *t;
		t=a;
		a=b;
		b=t;
	}
	a = reverse(a);//�����ת�� 
	b = reverse(b);
	
	
	node*b1=b;
	node*a1=a;
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
	a = reverse(a);//����ӵĽ��ת�� 
	return a;
}



node* D_sub(node*a,node*b)//ʮ���Ƽ��� 
{
	if(compare(a,b)==0)//��������������ȣ���a��������գ�����ֵΪ0 
	{
		a=clear(a);
		a=app(a,0);
	}
	else{
		int flag=1;
		if(compare(a,b)==-1)//������ȣ������жϷ��ţ���a<b,��flagΪ-1���ҽ�a��b���� 
		{
			node *t;
			t=a;
			a=b;
			b=t;
			flag=-1;
		}//�Ǵ����Ϊa��С����Ϊb
		 a = reverse(a) ;//����ת�� 
		 b = reverse(b) ;
		 node*b1=b;
		node*a1=a;
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
		a =reverse(a);//������ת�� 
		a = delt_0(a);//ɾ��ͷ����Ч��0 
		if(flag==-1)//�����Ӧ��Ϊ���� 
		//--------------------------------------------------------------test---------------------------
		changefirst_to_neg(a) ;//������ı�ͷԪ�ر�Ϊ�෴�� 
		}	
	return a;
}


node* D_multi(node* a,node* b)//ʮ���Ƴ˷� 
{
	
	int i;
	int j;
	if((length(a)==0&&lastdata(a)==0)||(length(b)==0&&lastdata(b)==0))//���a��b����0 
	{
		
		a=clear(a);//��a�е�������� 
		a=app(a,0); //��a��Ϊ0 
	}
	else
	{
		
		node * pa;//��������list���� 
		node * pb;
		pa=copy(a);//paΪa�Ŀ��� 
		pb=copy(b);//pbΪb�Ŀ��� 
		pa = reverse(pa) ;//��pa��pbת�� 
		pb = reverse(pb) ;
		
		node*b1 = pb;	
		a=clear(a);
		a=app(a,0); //��a�е������Ϊ0 
		
		for(i=0;b1!=NULL;i++,b1=b1->next)//��������pb 
		{
			
			node* paa;
			paa=copy(pa);//��������paaΪpa�Ŀ��� 
			node*a1 = paa;
			node* q = NULL;//����list����q�����ڴ��b�е�ÿһλ��a��˵Ľ�� 
			int flag=0;//������¼ǰһλ�Ľ�λ�� 
			while(a1!=NULL)//��������paa 
			{
			
				int sum=(a1->data)*(b1->data);//��λ��� 
				sum=sum+flag;
				flag=0;//�����󣬽�λ����0 
				q=app(q,sum%10);//������qβ��׷�Ӹ�λ���� 
				
				flag+=(sum/10);//�ٴμ�¼��λ�� 
				a1=a1->next;
			}
			q=app(q,flag);//�������ֽ�λ��û�н��꣬��ô������һλ������ý�λ�� 
			b=copy(q);//bΪq�Ŀ��� 
			q=clear(q);//�ٽ�q��գ����������һλ�������� 
			b = reverse(b) ;//��bת�� 
			for(j=0;j<i;j++)//��ĩβ���0���Ա�֤λ����ȷ 
			{
				b=app(b,0); 
			}
			a = D_add(a,b);//����a������b��� 
		}

	}//�����Ϊ����a��ֵ 
	
	return a;
}

void display3(node *a)//������ 
{
	display(a);
	printf("(%dλ)",length(a)+1);
	printf(" ! ");
	printf(" = ");
}


void display2(node *a,node *b,char optor)//������ 
{
	a = display(a);
	printf("(%dλ)",length(a)+1);
	if(optor=='/')//���Ϊ��������ô��Ҫ����̣���Ҫ������� 
	{
		printf(".......");
		display(b);
		printf("(%dλ)",length(b)+1);
	}
	printf("\n"); 
} 

void display1(node *a,node *b,char optor)//���ʽ�ӣ� 
{
	display(a) ;
	printf("(%dλ)",length(a)+1);
	if(optor=='+')
		printf(" + ");
	else if(optor=='-')
		printf(" - ");
	else if(optor=='*')
		printf(" * ");
	else if(optor=='/')
		printf(" / ");
	else if(optor=='^')
		printf(" ^ ");
	display(b);
	printf("(%dλ)",length(b)+1);
	printf(" = ");
}



//-----------------------------------------------------test-----------------------------
void D_divide(node *a,node *b)//ʮ���Ƴ��� 
{
	int j;
	if(eaquls_0(b) ==1)
	{
		printf("����Ϊ0�޷�����");
		exit(1); 
	 } 		 
	
	else if(compare(a,b)==-1)//���������С�ڳ�������ô��Ϊ0��������Ϊ���� 
	{
		a=clear(a);
		a=app(a,0);
	}
	else if(compare(a,b)==0)//���������ȣ���Ϊ1������Ϊ0 
	{
		a=clear(a);
		a=app(a,1);
		b=clear(b);
		b=app(b,0);
	 }
	 else
	 {//pa��ʼ��Ϊa����b�ĳ�ʼֵ�� 
	 	node * remainder;//����
		node * pb;
		node * pbb;
		pb=copy(b);
		int n=length(a)-length(b);//nΪ��������������֮�� 
		node * res =NULL;//����list���͵Ķ��󣬴���� 
		for(;n>=0;n--)//�Ȱѳ�������10^n�� 
		{
			int i=0;
			pbb=copy(pb);
			for(j=0;j<n;j++)
			{
				pbb=app(pbb,0);
			}
			while(1)//�����ֱ��������С�ڳ��� 
			{
				b=copy(pbb);
				a=delt_0(a) ;
				if(compare(a,b)==-1)
				   break;
				i++;
				a = D_sub(a,b);
			}
			res=app(res,i);//ÿ��ѭ�������������ĳ����ĸ�����ŵ����� 
			remainder=copy(a);//ʣ��ı��������Ϊ���� 
		}
		a=copy(res);//���̴�ŵ�a�� 
		b=copy(remainder);//��������ŵ�b�� 
	 }
	 
	 
	 display2(a,b,'/'); 
}


node* D_exp(node *a,node *b)//ʮ���Ƶĳ˷� 
{
	if(eaquls_0(b) ==1)//���ָ��Ϊ0�����Ϊ1 
	{
		a=clear(a);
		a=app(a,1);
	 } 
	 else{	
	 node * exp;
	exp=copy(b);//����һ��list����Ϊָ���Ŀ��� 
	node* pa;
	pa=copy(a);//����һ��pa����Ϊ�����Ŀ��� 
	exp=D_decre_1(exp);//�Ƚ�ָ��-1 
	while(eaquls_0(exp) !=1)//��ָ����Ϊ0ʱ��ִ�д�ѭ�� 
	{
		b=copy(pa);//bΪpa�Ŀ��� 
		a = D_multi(a,b);//��a��b��� 
		exp=D_decre_1(exp);//ָ����һ 
	}
	 }
	 
	 return a;
}


node* D_jiechen(node* a,node*b) 
{
	node * pa;
	pa= copy(a);//����һ��pa����Ϊ�����Ŀ��� 
	while (eaquls_0(pa) != 1)//��ָ����Ϊ0ʱ��ִ�д�ѭ�� 
	{
		pa = D_decre_1(pa);//ָ����һ 
		if (eaquls_0(pa) != 1)
		{
			b = copy(pa);//bΪpa�Ŀ��� 
			a = D_multi(a,b);//��a��b��� 		
		}

	}
	return a;
}









//----------------------------------------------------------------------------------------
DulNode * InistList(DulNode *L, char fh)//��������������ʼ��,fhΪ���ű�ʶ��
{
	L = (DulNode* )malloc(sizeof(DulNode));//��̬����洢�ռ�
	if (fh == '-') 
		L->data = 1;//L->data��ŷ��Žڵ㣬����ǡ�-����Ϊ1������Ϊ0
	else 
		L->data = 0;
	L->prior = L;
	L->next = L;
	return L;
}

DulNode *  DestroyList(DulNode*  L)
{
	DulNode*  p; 
	DulNode*  q;//���������ṹ��ָ��
	if (!L)
		return ERROR;//��������
	p = L->prior;//pָ������ͷ�ڵ��ǰ��
	while (p != L)//ɾ���ڵ�ڵ�p
	{
		q = p->prior;
		free(p);//�ͷŽڵ�p�Ŀռ�
		p = q;
	}
	free(L);//�ͷ�����L�Ĵ洢�ռ�
	return L;
}

DulNode *  Insfirst(DulNode*  L, int e)//��ͷ��������½ڵ�p
{
	DulNode*  p;
	DulNode*  q;
	p = (DulNode* )malloc(sizeof(DulNode));
	p->data = e;
	q = L->next;
	L->next = p;
	p->prior = L;
	p->next = q;
	q->prior = p;
	return L;
}

DulNode* Inslast(DulNode* L, int e)//�������������½ڵ�
{
	DulNode*  p;
	DulNode*  q;
	p = (DulNode* )malloc(sizeof(DulNode));
	p->data = e;
	q = L->prior;
	q->next = p;
	p->prior = q;
	p->next = L;
	L->prior = p;
	return L;
}

int CountNode(DulNode*  L)//��������Ľڵ���
{
	DulNode*  p;
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

DulNode *  Dzero(DulNode*   L)//ȥ����Ч0����
{
	DulNode*  p;
	if (CountNode(L) <= 1)
		return ERROR;//����ڵ�Ϊ��
	p = L->next;
	while (!p->data)
	  p = p->next;
	L->next = p;
	p->prior = L;
	return L;
}

int CountB(DulNode*  L)//���㳤����λ������
{
	if (L->next == L)
		return 0;//������
	L = Dzero(L);//ɾ��0
	int i;
	i = Count(L->next->data) + (CountNode(L) - 1) * 4;//ͷ�ڵ����ݵ�λ�����Ͻڵ����*4��ÿ���ڵ�����λ��
	return i;
}

int ConversionD(char** p, int i, int m,int  e)//���ַ�ת��Ϊ����
{
	char s[99999];
	strcpy(s,p); 
	
	int k, g, x, sum = 0;
	for (k = 1, g = 1; k <= i; k++, g = g * 10)
	{
		x = s[m-k] - 48;
		sum = sum + x * g;
	}
	e = sum;
	return e;
}



DulNode* Creat(DulNode *L, char ** p)//ͨ����Ӧ���ַ�����������
{
	char s[99999];
	strcpy(s,p); 
	int m = 0;
	int i = 0;
	int e;
	L = InistList(L, s[m]);
	//printf("%d",L->data);
	if (s[m] == '-')
	   m++;//������Ϊ����
	while (s[m] != '\0')//ÿ���ڵ��������λ������i=������ʱ��i�ִ��㿪ʼ���𣬰ѡ��������뵽��β�����β
	{
		if (s[m] == ',')
		{
			//���ĸ���֮�� 
			e = ConversionD(&s, i,m, e);
			L = Inslast(L, e);
			i = -1;
		}
		i++;
		m++;
	}
	e = ConversionD(&s, i, m,e);//���ǡ�������ֱ�Ӳ��뵽�����β��
	L = Inslast(L, e);
	return L;
}


int Cmp(DulNode*  L, DulNode*  K)//�����ͬʱ�ıȽ�������С����
{
	DulNode*  p;
	DulNode*  q;
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


int print(DulNode*  L)//���������
{
	int i;
	DulNode*  p;
	if (L->data == 1 && L->next->data == 0)//��������-0����ű�ʶ��0�����0
		L->data = 0;
	if (L->data == 1 && L->next->data != 0)
		printf("-");//�������
	p = L->next;
	while (p->data == 0 && p->next != L)//������Ч��
		p = p->next;
	if (p == L)      //���0
	{
		printf("0");
		return OK;
	}
	if (p->next == L)     //p�����һ���ڵ㣬������һ��������ֵ
	{
		printf("%d",p->data);
		return OK;
	}
	if (p->next != L)//p�������һ���ڵ㣬�����ֵ���������������Ϊ�ָ���
		printf("%d,",p->data);
	p = p->next;
	while (p->next != L)    //ѭ�����������������
	{
		if (p->data == 0)
		   printf("0000,"); 
		else
		{
			for (i = 1; i < Count(p->data); i++)//�ڵ������ĳһλΪ0�������0�����������ֵ
				printf("0");
			printf("%d,",p->data);
		}
		p = p->next;
	}
	if (p->data == 0) 
	printf("0000");//������һ���ڵ����ֵ
	else
	{
		for (i = 1; i < Count(p->data); i++)
			printf("0");
		printf("%d,",p->data);
	}
	return OK;
}

DulNode*  add(DulNode*  L, DulNode*  K, char fh)//�޷��żӷ�,fhΪ���ű�ʶ��
{
	int temp, cf = 0;
	DulNode *  p;
	DulNode*   q;
	DulNode*  R;
	R = InistList(R, fh);
	p = L->prior;
	q = K->prior;
	while (p != L && q != K)        //�����һ���ڵ㿪ʼ���мӷ�������10000
	{
		temp = p->data + q->data + cf;
		if (temp >= 10000)//������ӵĺʹ���10000��temp=temp-10000�ҽ�λ��ʶΪ1
		{
			R = Insfirst(R, temp - temp / 10000 * 10000);
			cf = 1;
		}
		else
		{
			R = Insfirst(R, temp);//�޽�λ
			cf = 0;
		}
		p = p->prior;//p��ǰ����
		q = q->prior;//q��ǰ����
	}
	while (p != L)//K���꣬L����û�ӵģ�p���Ͻ�λ
	{
		temp = p->data + cf;
		cf = temp / 10000;
		R = Insfirst(R, temp - temp / 10000 * 10000);
		p = p->prior;
	}
	while (q != K)//L���꣬K����û�ӵģ�q�ӽ�λ
	{
		temp = q->data + cf;
		cf = temp / 10000;
		R = Insfirst(R, temp - temp / 10000 * 10000);
		q = q->prior;
	}
	if (cf != 0) 
	   R = Insfirst(R, cf);//����ж��Ƿ��н�λ��������������ͷ����һ���ڵ㣬����Ϊ��λ
	return R;
}

DulNode*  sub(DulNode*  L, DulNode* K, char fh)//�޷��ż�������,fhΪ���ű�ʶλ
{
	DulNode*  p;
	DulNode* q;
	DulNode*  R;
	int temp, cf = 0;
	R = InistList(R, fh);
	p = L->prior;
	q = K->prior;
	while (p != L && q != K)//���м������������ͽ�λ
	{
		temp = p->data - q->data - cf;//�����������ȥ��λ
		if (temp < 0)//�н�λ
		{
			temp = temp + 10000;
			R = Insfirst(R, temp);
			cf = 1;//�н�λ
		}
		else
		{
			R = Insfirst(R, temp);//�޽�λ
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
			R = Insfirst(R, temp);
			p = p->prior;
			break;
		}
		else
		{
			R = Insfirst(R, temp + 10000);
			cf = 1;
		}
		p = p->prior;
	}
	while (p != L)//��Lʣ�µĶ����ƹ��������
	{
		R = Insfirst(R, p->data);
		p = p->prior;
	}
	return R;
}

DulNode*  Computing(DulNode*  L, DulNode*  K, char ys)//����������ƺ���
{
	DulNode *  R;
	char fh = 'h';
	R = InistList(R, fh);

	if (!L->data && !K->data) {
	    R = add(L, K, '+');
		
	}
	else if (L->data && K->data){
	    R = add(L, K, '-');
	    
	} 
	else if (!L->data && K->data)
	{
		if (CountNode(L) > CountNode(K)) 
		    R = sub(L, K, '+');
		else if (CountNode(L) < CountNode(K)) 
		    R = sub(K, L, '-');
		else if (Cmp(L, K) == 1 || Cmp(L, K) == 0) 
		    R = sub(L, K, '+');
		else if (Cmp(L, K) == -1) 
		    R = sub(K, L, '-');
		    
	}
	else//�������Ǹ���������������
	{
		
		if (CountNode(L) > CountNode(K)) 
		    R = sub(L, K, '-');
		else if (CountNode(L) < CountNode(K)) 
		    R = sub(K, L, '+');			       
		else if (Cmp(L, K) == 1 || Cmp(L, K) == 0) 
		    R = sub(L, K, '-');
		else if (Cmp(L, K) == -1) 
		    R = sub(K, L, '+');
	}
	return R;
}




int PanGS(char** p)//�ж������ʽ
{
	char s[99999];
	strcpy(s,p); 
	
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

int InputS(char **cz,char **cz1){
	printf("�����볤������\n");
	printf("������1:");
	scanf("%s",&*cz);
	getchar();
	while(!PanGS(&*cz))//�ж������ʽ�Ƿ���ȷ 
	{
		printf("�����ʽ�������������룡\n");
		printf("�������������ʽΪ��XXXX��XXXX��XXXX������XXXX;\n");
		printf("������1:");
		scanf("%s",&*cz);
		getchar();
	}
	printf("������2:");
	scanf("%s",&*cz1);
	getchar();
	while(!PanGS(&*cz1))//�ж������ʽ�Ƿ���ȷ 
	{
		printf("�����ʽ�������������룡\n");
		printf("�������������ʽΪ��XXXX��XXXX��XXXX������XXXX;\n");
		printf("������2:");
		scanf("%s",&*cz1);
		getchar();
	}
	return OK;
}


int main(){
	int optor2; //����һ���ַ�����
	while(1){
	system("cls");
	printf("��������Ҫ���е�����\n"); 
	printf("1.�Ӽ��˳��˷��׳�\n");
	printf("2.�������Ӽ�\n");
	scanf("%d",&optor2);
	if(optor2==2){
		//�����ͼӷ������� 
		char cz[99999];
		char cz1[99999];

		DulNode* L1;
		DulNode* L2;
		DulNode* R;
		int flag = 1;
		char xz;
		printf("************************************\n");
		printf("******��ӭʹ�ó����ͼӷ�������******\n");
		printf("************************************\n");
		printf("�������������ʽΪ��XXXX��XXXX��XXXX������XXXX;");
		while(1){//�жϼ�����Ƿ�Ϊ��Ч����
			InputS(&cz,&cz1); 
		    L1 = Creat(L1, &cz);//�ѳ������ַ���ת��Ϊѭ������Ĵ���ṹ
			L2 = Creat(L2, &cz1);
			
			R = Computing(L1, L2, '+');
			printf("������:");
			print(R);//����Գ�������׼��ʽ���
			printf("\n");
			L1 = DestroyList(L1);//���ٺ��������ͷſռ�
			L2 = DestroyList(L2);
			R = DestroyList(R);
			printf("1.��������\n");
			printf("2.�˳�����\n");
			printf("������1��2\n");
			int key3;
			scanf("%d",&key3);
			if (key3 == 2)
			break;
		} 
		
	} 
	if(optor2==1){
		clock_t start, finish;//�����ʱ�� 
		while (1) {
			char optor1;//����һ���ַ����� 
			printf("������Ҫ���е����㣺\n");
			getchar();
			scanf("%c",&optor1);//�û��Ӽ���������������� 
			if (optor1 == '+')
			{
				printf("�������һ��ʮ���ƴ�������\n");
				char str1[99999], str2[99999];    //���������ַ��� 
				scanf("%s",&str1);//�����һ���ַ��� 
				printf("������ڶ���ʮ���ƴ�������\n");
				scanf("%s",&str2);//����ڶ����ַ��� 
				start = clock();//��ʼ��ʱ 
				node *p;//����ͷ�ڵ�
				node *p2;//����ͷ�ڵ�
				p =  list(p,str1);
				p2 = list(p2,str2);

				display1(p,p2,optor1);//��������ʽ�� 
				p = D_add(p,p2);
				display2(p,p2,optor1);//��������� 
				
			}//���мӷ����� 
			if (optor1 == '-')
			{
				printf("�������һ��ʮ���ƴ�������\n");
				char str1[99999], str2[99999];    //���������ַ��� 
				scanf("%s",&str1);//�����һ���ַ��� 
				printf("������ڶ���ʮ���ƴ�������\n");
				scanf("%s",&str2);//����ڶ����ַ��� 
				start = clock();//��ʼ��ʱ 
				node *p;//����ͷ�ڵ�
				node *p2;//����ͷ�ڵ�
				
				p =  list(p,str1);
				p2 = list(p2,str2);
				
				//calculate val1(A, B, optor1);//����һ��calculate����	
				display1(p,p2,optor1);//��������ʽ�� 
				p = D_sub(p,p2);
				
				
				
				display2(p,p2,optor1);//��������� 
			}//���м������� 
			if (optor1 == '*')
			{
				printf("�������һ��ʮ���ƴ�������\n");
				char str1[99999], str2[99999];    //���������ַ��� 
				scanf("%s",&str1);//�����һ���ַ��� 
				printf("������ڶ���ʮ���ƴ�������\n");
				scanf("%s",&str2);//����ڶ����ַ��� 
				start = clock();//��ʼ��ʱ 
				node *p;//����ͷ�ڵ�
				node *p2;//����ͷ�ڵ�
				
				p =  list(p,str1);
				p2 = list(p2,str2);
				
				//calculate val1(A, B, optor1);//����һ��calculate����	
				display1(p,p2,optor1);//��������ʽ�� 
				p =D_multi(p,p2);
				display2(p,p2,optor1);//��������� 
			}//���г˷����� 
			if (optor1 == '/')
			{
				printf("�������һ��ʮ���ƴ�������\n");
				char str1[99999], str2[99999];    //���������ַ��� 
				scanf("%s",&str1);//�����һ���ַ��� 
				printf("������ڶ���ʮ���ƴ�������\n");
				scanf("%s",&str2);//����ڶ����ַ��� 
				start = clock();//��ʼ��ʱ 
				node *p;//����ͷ�ڵ�
				node *p2;//����ͷ�ڵ�
				
				p =  list(p,str1);
				p2 = list(p2,str2);
				
				//calculate val1(A, B, optor1);//����һ��calculate����	
				display1(p,p2,optor1);//��������ʽ�� 
				
				D_divide(p,p2);
			}//���г������� 
			if (optor1 == '^')
			{
				printf("�������һ��ʮ���ƴ�������\n");
				char str1[99999], str2[99999];    //���������ַ��� 
				scanf("%s",&str1);//�����һ���ַ��� 
				printf("������ڶ���ʮ���ƴ�������\n");
				scanf("%s",&str2);//����ڶ����ַ��� 
				start = clock();//��ʼ��ʱ 
				node *p;//����ͷ�ڵ�
				node *p2;//����ͷ�ڵ�
				
				p =  list(p,str1);
				p2 = list(p2,str2);
				
				//calculate val1(A, B, optor1);//����һ��calculate����	
				display1(p,p2,optor1);//��������ʽ�� 
				
				p =D_exp(p,p2);
				display2(p,p2,optor1);//��������� 
			}//���г˷����� 
			if (optor1 == '!')
			{
				printf("�������һ��ʮ���ƴ�������\n");
				char str1[99999];    //���������ַ��� 
				scanf("%s",&str1);//�����һ���ַ��� 
			
				start = clock();//��ʼ��ʱ 
				node *p;//����ͷ�ڵ�
				node *p2;//����ͷ�ڵ�
				
				p =  list(p,str1);
				p2 = list(p2,"1");
				
				//calculate val1(A, B, optor1);//����һ��calculate����	
					
				display3(p);//��������ʽ�� 
				p = D_jiechen(p,p2);
				display2(p,p2,optor1);//��������� 
			}
			finish = clock();//��ʱ���� 

			printf("��������ʱ���ǣ�%d/1000(s)\n",finish - start);//�������ʱ��
			printf("1.��������\n");
			printf("2.�˳�����\n");
			printf("������1��2\n");
			int key3;
			scanf("%d",&key3);
			if (key3 == 2)
			exit(1);
		}
	}
	
	
	}
	
}
