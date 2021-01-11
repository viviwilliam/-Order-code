#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -1

typedef struct DulNode{//双向链表存储结构 
	struct DulNode* prior;//前指针 
	struct DulNode* next;//后指针 
	int data;//节点数据 
}DulNode,* DuList;


typedef struct node //定义一个节点类型 
{
	int data;//存放数据 
	struct node *next;//存放下一个节点的位置 
}node;
//----------------------------------------------------------------------------------------

int length(node* p)// 得到链表的长度-1 
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

node *delt_0(node *p)//删除整数前面的无效的0 
{
	node *head=p;
	while(head->data==0&&length(p)!=0)
		head=head->next;//如果链表的第一位为1，且链表的长度不为1，那么删除链表的头结点，即头指针后一位 
	node* new_head=head;//定义一个新的头结点 ,把从不为0开始节点赋值给他 
	return new_head;//	返回新的头节点 
 } 


node * display(node*p){
	p = delt_0(p);
	node*head=p;//将头结点赋值给head。避免在后续操作中头结点丢失 
	while (head != NULL)//判断循环是否执行到最后了 
	{
		printf("%d",head->data);//如果没有执行得到最后，那么输出当前节点的数据 
		head = head->next;//head指向下一个节点 
	}
	return p;
}

node* app(node* p,int num)//在链表尾部追加指定数据 
{
	
	node*head=p;//把链表的头结点赋值给head 
	node *p1=(node*)malloc(sizeof(node));//给添加的节点分配动态内存空间 
	p1->data =num;//把该节点的data部分赋值为num 
	if(head==NULL) {
		head=p1;
		head->next=NULL;
		p=head;
		return p;
	}//若head为空，那么说明该链表为空，添加的该节点为头结点，                                                  //把p1赋值给head，head的next指向空 ，再把head返还给p，返回头结点 
	else//否则，添加的节点仅为该链表的尾节点 
	{
		while(head->next!=NULL) 
			head=head->next;//将指针遍历链表，直到指针指向链表的最后一个节点	
		head->next=p1;//把尾节点的next指向p1 
		p1->next =NULL;	//p1的next指向null，这是p1即为该链表的尾节点 
	return p;//返回头结点p 
	}
	
}

node* reverse(node *p)//大整数的逆向存储，因为运算时需要从个位开始运算
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

node * copy(node* p)//链表的无连接复制 
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

node* clear(node* p)//链表的清空 
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
//--------------------------------------test-----------------------
void delt(node* p)//删除链表最后一个节点 
{
	node* current=p;//地址的引用 
	if(current==NULL)
		return;//如果链表本身为空，则无法操作 
	node*ne=current->next;
	if(ne==NULL){
		current=NULL;
		p=NULL;
		return;
	}//如果链表只有一个节点，那么清楚头结点，链表返回空 
	while(ne->next!=NULL) //若以上情况都不是 
	{
		current=ne;	
		ne=ne->next;		//遍历链表，将current指向链表的倒数第二个节点，ne指向链表的最后一个节点 
	}
	current->next=NULL;//最后一个节点赋值为空 
}


int lastdata(node *p)//得到链表最后一个节点的数值 
{
	node*head=p;
	while(head->next!=NULL)//遍历到链表最后一个节点 
	head=head->next;
	return head->data;//返回最后一个节点的数值 
}

void changefirst_to_neg(node *p)//把链表的表头变为负数 
{
	node *head=p;
	head->data=head->data*(-1);//返回表头data的负数 
}

node* D_decre_1(node *p)//十进制大整数的数值自减1
{

	p = reverse(p);
	node*head=p;
	head->data--;
	while(head->data<0)//当末尾为连续的0时，要连续向前借位 
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
node*B_decre_1()//二进制大整数的数值自减1，原理和十进制一样 
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
}*/

 int eaquls_0(node *p)//判断大整数是否为0,为0则返回1，否则返回0； 
 {
 	p=delt_0(p);//先把大整数前面的无效0删除 
 	node*head=p;
 	if(head->data==0)
		return 1;//如果头节点为0，且不为无效0，那么该大整数即为0，返回1 
 	else 
		return 0;//反之返回0 
 }



node * list(node *p,char str[]){
	int i;
	node *p1;
	node *p2;
	p = NULL;
	p1 = (node*)malloc(sizeof(node));//给p1分配动态空间 
	p1->data = str[0]-48;//把字符串的第一个字符存入p1的data中 ，数字字符的ASCII值-48为数字本身
//	printf("%d",p1->data);
	p= p1;//把p1赋值给头结点 
	for(i=1;str[i]!='\0';i++)//for循环将字符串的每个字符逐个存进链表中 
	{
		p2 = (node*)malloc(sizeof(node));//给p2分配动态内存空间 
		p2->data=str[i]-48;//给p2的data赋值 
		//printf("%d",p2->data);
		p1->next = p2;//循环使用p1和p2给链表添加节点 
		p1 = p2;
	}
	p1->next=NULL;//尾节点的next为空 
	
	return p;
}

int compare(node*a,node*b)//两个大整数大小的比较 
{
	node *head1=a;
	node *head2=b;
	if(length(a)<length(b))
	  return -1;//如果a的长度小于b的长度，那么一定b大，则返回-1 
	else if(length(a)>length(b))
	  return 1;// 如果b的长度小于a的长度，那么一定a大，则返回1 
	else//长度相同的情况 
	{
		while(head1!=NULL)//逐位比较 
		{
			if(head1->data<head2->data)
			   return -1; 
			if(head1->data>head2->data)
			   return 1;
			head1=head1->next;
			head2=head2->next;
		}
		return 0;//知道最后一位都相同，那么两个大整数相同，返回0 
	}
}




//加到a里面 
node* D_add(node *a,node *b)//十进制加法 
{

	if(compare(a,b)==-1)//比较两个大整数，大的为a，小的为b 
	{
		node *t;
		t=a;
		a=b;
		b=t;
	}
	a = reverse(a);//链表的转置 
	b = reverse(b);
	
	
	node*b1=b;
	node*a1=a;
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
	a = reverse(a);//将相加的结果转置 
	return a;
}



node* D_sub(node*a,node*b)//十进制减法 
{
	if(compare(a,b)==0)//若两个大整数相等，则将a的链表清空，并赋值为0 
	{
		a=clear(a);
		a=app(a,0);
	}
	else{
		int flag=1;
		if(compare(a,b)==-1)//若不相等，则先判断符号，若a<b,则flag为-1，且将a和b交换 
		{
			node *t;
			t=a;
			a=b;
			b=t;
			flag=-1;
		}//是大的数为a，小的数为b
		 a = reverse(a) ;//链表转置 
		 b = reverse(b) ;
		 node*b1=b;
		node*a1=a;
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
		a =reverse(a);//将链表转置 
		a = delt_0(a);//删除头上无效的0 
		if(flag==-1)//若结果应该为负数 
		//--------------------------------------------------------------test---------------------------
		changefirst_to_neg(a) ;//则将链表的表头元素变为相反数 
		}	
	return a;
}


node* D_multi(node* a,node* b)//十进制乘法 
{
	
	int i;
	int j;
	if((length(a)==0&&lastdata(a)==0)||(length(b)==0&&lastdata(b)==0))//如果a或b等于0 
	{
		
		a=clear(a);//将a中的链表清空 
		a=app(a,0); //将a变为0 
	}
	else
	{
		
		node * pa;//定义两个list对象 
		node * pb;
		pa=copy(a);//pa为a的拷贝 
		pb=copy(b);//pb为b的拷贝 
		pa = reverse(pa) ;//将pa和pb转置 
		pb = reverse(pb) ;
		
		node*b1 = pb;	
		a=clear(a);
		a=app(a,0); //将a中的链表变为0 
		
		for(i=0;b1!=NULL;i++,b1=b1->next)//遍历链表pb 
		{
			
			node* paa;
			paa=copy(pa);//定义链表paa为pa的拷贝 
			node*a1 = paa;
			node* q = NULL;//定义list对象q，用于存放b中的每一位与a相乘的结果 
			int flag=0;//用来记录前一位的进位数 
			while(a1!=NULL)//遍历链表paa 
			{
			
				int sum=(a1->data)*(b1->data);//逐位相乘 
				sum=sum+flag;
				flag=0;//相加完后，进位数清0 
				q=app(q,sum%10);//在链表q尾部追加该位的数 
				
				flag+=(sum/10);//再次记录进位数 
				a1=a1->next;
			}
			q=app(q,flag);//如果最后又进位数没有进完，那么再增加一位来保存该进位数 
			b=copy(q);//b为q的拷贝 
			q=clear(q);//再将q清空，继续存放下一位的运算结果 
			b = reverse(b) ;//将b转置 
			for(j=0;j<i;j++)//在末尾添加0，以保证位数正确 
			{
				b=app(b,0); 
			}
			a = D_add(a,b);//链表a和链表b相加 
		}

	}//最后结果为链表a的值 
	
	return a;
}

void display3(node *a)//输出结果 
{
	display(a);
	printf("(%d位)",length(a)+1);
	printf(" ! ");
	printf(" = ");
}


void display2(node *a,node *b,char optor)//输出结果 
{
	a = display(a);
	printf("(%d位)",length(a)+1);
	if(optor=='/')//如果为除法，那么既要输出商，又要输出余数 
	{
		printf(".......");
		display(b);
		printf("(%d位)",length(b)+1);
	}
	printf("\n"); 
} 

void display1(node *a,node *b,char optor)//输出式子； 
{
	display(a) ;
	printf("(%d位)",length(a)+1);
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
	printf("(%d位)",length(b)+1);
	printf(" = ");
}



//-----------------------------------------------------test-----------------------------
void D_divide(node *a,node *b)//十进制除法 
{
	int j;
	if(eaquls_0(b) ==1)
	{
		printf("除数为0无法计算");
		exit(1); 
	 } 		 
	
	else if(compare(a,b)==-1)//如果被除数小于除数，那么商为0，余数即为除数 
	{
		a=clear(a);
		a=app(a,0);
	}
	else if(compare(a,b)==0)//如果两数相等，商为1，余数为0 
	{
		a=clear(a);
		a=app(a,1);
		b=clear(b);
		b=app(b,0);
	 }
	 else
	 {//pa是始终为a、和b的初始值； 
	 	node * remainder;//余数
		node * pb;
		node * pbb;
		pb=copy(b);
		int n=length(a)-length(b);//n为两个大整数长度之差 
		node * res =NULL;//定义list类型的对象，存放商 
		for(;n>=0;n--)//先把除数扩大到10^n倍 
		{
			int i=0;
			pbb=copy(pb);
			for(j=0;j<n;j++)
			{
				pbb=app(pbb,0);
			}
			while(1)//相减，直到被除数小于除数 
			{
				b=copy(pbb);
				a=delt_0(a) ;
				if(compare(a,b)==-1)
				   break;
				i++;
				a = D_sub(a,b);
			}
			res=app(res,i);//每次循环结束将减掉的除数的个数存放到商中 
			remainder=copy(a);//剩余的被除数则变为余数 
		}
		a=copy(res);//将商存放到a中 
		b=copy(remainder);//将余数存放到b中 
	 }
	 
	 
	 display2(a,b,'/'); 
}


node* D_exp(node *a,node *b)//十进制的乘方 
{
	if(eaquls_0(b) ==1)//如果指数为0，则答案为1 
	{
		a=clear(a);
		a=app(a,1);
	 } 
	 else{	
	 node * exp;
	exp=copy(b);//定义一个list对象，为指数的拷贝 
	node* pa;
	pa=copy(a);//定义一个pa对象，为底数的拷贝 
	exp=D_decre_1(exp);//先将指数-1 
	while(eaquls_0(exp) !=1)//当指数不为0时，执行此循环 
	{
		b=copy(pa);//b为pa的拷贝 
		a = D_multi(a,b);//将a，b相乘 
		exp=D_decre_1(exp);//指数减一 
	}
	 }
	 
	 return a;
}


node* D_jiechen(node* a,node*b) 
{
	node * pa;
	pa= copy(a);//定义一个pa对象，为底数的拷贝 
	while (eaquls_0(pa) != 1)//当指数不为0时，执行此循环 
	{
		pa = D_decre_1(pa);//指数减一 
		if (eaquls_0(pa) != 1)
		{
			b = copy(pa);//b为pa的拷贝 
			a = D_multi(a,b);//将a，b相乘 		
		}

	}
	return a;
}









//----------------------------------------------------------------------------------------
DulNode * InistList(DulNode *L, char fh)//创建空链表，并初始化,fh为符号标识符
{
	L = (DulNode* )malloc(sizeof(DulNode));//动态分配存储空间
	if (fh == '-') 
		L->data = 1;//L->data存放符号节点，如果是‘-’则为1，否则为0
	else 
		L->data = 0;
	L->prior = L;
	L->next = L;
	return L;
}

DulNode *  DestroyList(DulNode*  L)
{
	DulNode*  p; 
	DulNode*  q;//定义两个结构体指针
	if (!L)
		return ERROR;//链表不存在
	p = L->prior;//p指向链表头节点的前驱
	while (p != L)//删除节点节点p
	{
		q = p->prior;
		free(p);//释放节点p的空间
		p = q;
	}
	free(L);//释放链表L的存储空间
	return L;
}

DulNode *  Insfirst(DulNode*  L, int e)//在头结点后插入新节点p
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

DulNode* Inslast(DulNode* L, int e)//在链表最后插入新节点
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

int CountNode(DulNode*  L)//计算链表的节点数
{
	DulNode*  p;
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

DulNode *  Dzero(DulNode*   L)//去掉无效0函数
{
	DulNode*  p;
	if (CountNode(L) <= 1)
		return ERROR;//链表节点为空
	p = L->next;
	while (!p->data)
	  p = p->next;
	L->next = p;
	p->prior = L;
	return L;
}

int CountB(DulNode*  L)//计算长整数位数函数
{
	if (L->next == L)
		return 0;//空链表
	L = Dzero(L);//删除0
	int i;
	i = Count(L->next->data) + (CountNode(L) - 1) * 4;//头节点数据的位数加上节点个数*4，每个节点有四位数
	return i;
}

int ConversionD(char** p, int i, int m,int  e)//将字符转化为数字
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



DulNode* Creat(DulNode *L, char ** p)//通过相应的字符串建立链表
{
	char s[99999];
	strcpy(s,p); 
	int m = 0;
	int i = 0;
	int e;
	L = InistList(L, s[m]);
	//printf("%d",L->data);
	if (s[m] == '-')
	   m++;//长整数为负数
	while (s[m] != '\0')//每个节点最多存放四位数，当i=‘，’时，i又从零开始加起，把‘，’插入到结尾链表结尾
	{
		if (s[m] == ',')
		{
			//读四个数之后 
			e = ConversionD(&s, i,m, e);
			L = Inslast(L, e);
			i = -1;
		}
		i++;
		m++;
	}
	e = ConversionD(&s, i, m,e);//不是‘，’则直接插入到链表结尾中
	L = Inslast(L, e);
	return L;
}


int Cmp(DulNode*  L, DulNode*  K)//结点相同时的比较两数大小函数
{
	DulNode*  p;
	DulNode*  q;
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


int print(DulNode*  L)//输出链表函数
{
	int i;
	DulNode*  p;
	if (L->data == 1 && L->next->data == 0)//如果结果是-0则符号标识清0，输出0
		L->data = 0;
	if (L->data == 1 && L->next->data != 0)
		printf("-");//输出符号
	p = L->next;
	while (p->data == 0 && p->next != L)//跳过无效零
		p = p->next;
	if (p == L)      //输出0
	{
		printf("0");
		return OK;
	}
	if (p->next == L)     //p是最后一个节点，输出最后一个结点的数值
	{
		printf("%d",p->data);
		return OK;
	}
	if (p->next != L)//p不是最后一个节点，输出数值并且输出‘，’作为分隔符
		printf("%d,",p->data);
	p = p->next;
	while (p->next != L)    //循环输出不是最后结点的数
	{
		if (p->data == 0)
		   printf("0000,"); 
		else
		{
			for (i = 1; i < Count(p->data); i++)//节点上如果某一位为0，则输出0，否则输出数值
				printf("0");
			printf("%d,",p->data);
		}
		p = p->next;
	}
	if (p->data == 0) 
	printf("0000");//输出最后一个节点的数值
	else
	{
		for (i = 1; i < Count(p->data); i++)
			printf("0");
		printf("%d,",p->data);
	}
	return OK;
}

DulNode*  add(DulNode*  L, DulNode*  K, char fh)//无符号加法,fh为符号标识符
{
	int temp, cf = 0;
	DulNode *  p;
	DulNode*   q;
	DulNode*  R;
	R = InistList(R, fh);
	p = L->prior;
	q = K->prior;
	while (p != L && q != K)        //从最后一个节点开始进行加法，进制10000
	{
		temp = p->data + q->data + cf;
		if (temp >= 10000)//两数相加的和大于10000，temp=temp-10000且进位标识为1
		{
			R = Insfirst(R, temp - temp / 10000 * 10000);
			cf = 1;
		}
		else
		{
			R = Insfirst(R, temp);//无进位
			cf = 0;
		}
		p = p->prior;//p向前搜索
		q = q->prior;//q向前搜索
	}
	while (p != L)//K加完，L还有没加的，p加上进位
	{
		temp = p->data + cf;
		cf = temp / 10000;
		R = Insfirst(R, temp - temp / 10000 * 10000);
		p = p->prior;
	}
	while (q != K)//L加完，K还有没加的，q加进位
	{
		temp = q->data + cf;
		cf = temp / 10000;
		R = Insfirst(R, temp - temp / 10000 * 10000);
		q = q->prior;
	}
	if (cf != 0) 
	   R = Insfirst(R, cf);//最后判断是否还有进位，如果有在链表表头新增一个节点，数据为进位
	return R;
}

DulNode*  sub(DulNode*  L, DulNode* K, char fh)//无符号减法函数,fh为符号标识位
{
	DulNode*  p;
	DulNode* q;
	DulNode*  R;
	int temp, cf = 0;
	R = InistList(R, fh);
	p = L->prior;
	q = K->prior;
	while (p != L && q != K)//进行减法，不够减就借位
	{
		temp = p->data - q->data - cf;//两数相减并减去借位
		if (temp < 0)//有借位
		{
			temp = temp + 10000;
			R = Insfirst(R, temp);
			cf = 1;//有借位
		}
		else
		{
			R = Insfirst(R, temp);//无借位
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
	while (p != L)//把L剩下的都复制过结果链表
	{
		R = Insfirst(R, p->data);
		p = p->prior;
	}
	return R;
}

DulNode*  Computing(DulNode*  L, DulNode*  K, char ys)//四则运算控制函数
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
	else//被加数是负数，加数是正数
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




int PanGS(char** p)//判断输入格式
{
	char s[99999];
	strcpy(s,p); 
	
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

int InputS(char **cz,char **cz1){
	printf("请输入长整数！\n");
	printf("长整数1:");
	scanf("%s",&*cz);
	getchar();
	while(!PanGS(&*cz))//判断输入格式是否正确 
	{
		printf("输入格式错误，请重新输入！\n");
		printf("长整数的输入格式为：XXXX，XXXX，XXXX……，XXXX;\n");
		printf("长整数1:");
		scanf("%s",&*cz);
		getchar();
	}
	printf("长整数2:");
	scanf("%s",&*cz1);
	getchar();
	while(!PanGS(&*cz1))//判断输入格式是否正确 
	{
		printf("输入格式错误，请重新输入！\n");
		printf("长整数的输入格式为：XXXX，XXXX，XXXX……，XXXX;\n");
		printf("长整数2:");
		scanf("%s",&*cz1);
		getchar();
	}
	return OK;
}


int main(){
	int optor2; //定义一个字符变量
	while(1){
	system("cls");
	printf("请输入需要进行的运算\n"); 
	printf("1.加减乘除乘方阶乘\n");
	printf("2.长整数加减\n");
	scanf("%d",&optor2);
	if(optor2==2){
		//长整型加法的数据 
		char cz[99999];
		char cz1[99999];

		DulNode* L1;
		DulNode* L2;
		DulNode* R;
		int flag = 1;
		char xz;
		printf("************************************\n");
		printf("******欢迎使用长整型加法运算器******\n");
		printf("************************************\n");
		printf("长整数的输入格式为：XXXX，XXXX，XXXX……，XXXX;");
		while(1){//判断键入的是否为无效命令
			InputS(&cz,&cz1); 
		    L1 = Creat(L1, &cz);//把长整数字符串转换为循环链表的储存结构
			L2 = Creat(L2, &cz1);
			
			R = Computing(L1, L2, '+');
			printf("运算结果:");
			print(R);//结果以长整数标准形式输出
			printf("\n");
			L1 = DestroyList(L1);//销毁函数，以释放空间
			L2 = DestroyList(L2);
			R = DestroyList(R);
			printf("1.继续运算\n");
			printf("2.退出程序\n");
			printf("请输入1或2\n");
			int key3;
			scanf("%d",&key3);
			if (key3 == 2)
			break;
		} 
		
	} 
	if(optor2==1){
		clock_t start, finish;//定义计时器 
		while (1) {
			char optor1;//定义一个字符变量 
			printf("请输入要进行的运算：\n");
			getchar();
			scanf("%c",&optor1);//用户从键盘输入输入运算符 
			if (optor1 == '+')
			{
				printf("请输入第一个十进制大整数：\n");
				char str1[99999], str2[99999];    //定义两个字符串 
				scanf("%s",&str1);//输入第一个字符串 
				printf("请输入第二个十进制大整数：\n");
				scanf("%s",&str2);//输入第二个字符串 
				start = clock();//开始计时 
				node *p;//链表头节点
				node *p2;//链表头节点
				p =  list(p,str1);
				p2 = list(p2,str2);

				display1(p,p2,optor1);//输出运算的式子 
				p = D_add(p,p2);
				display2(p,p2,optor1);//输出运算结果 
				
			}//进行加法运算 
			if (optor1 == '-')
			{
				printf("请输入第一个十进制大整数：\n");
				char str1[99999], str2[99999];    //定义两个字符串 
				scanf("%s",&str1);//输入第一个字符串 
				printf("请输入第二个十进制大整数：\n");
				scanf("%s",&str2);//输入第二个字符串 
				start = clock();//开始计时 
				node *p;//链表头节点
				node *p2;//链表头节点
				
				p =  list(p,str1);
				p2 = list(p2,str2);
				
				//calculate val1(A, B, optor1);//定义一个calculate对象	
				display1(p,p2,optor1);//输出运算的式子 
				p = D_sub(p,p2);
				
				
				
				display2(p,p2,optor1);//输出运算结果 
			}//进行减法运算 
			if (optor1 == '*')
			{
				printf("请输入第一个十进制大整数：\n");
				char str1[99999], str2[99999];    //定义两个字符串 
				scanf("%s",&str1);//输入第一个字符串 
				printf("请输入第二个十进制大整数：\n");
				scanf("%s",&str2);//输入第二个字符串 
				start = clock();//开始计时 
				node *p;//链表头节点
				node *p2;//链表头节点
				
				p =  list(p,str1);
				p2 = list(p2,str2);
				
				//calculate val1(A, B, optor1);//定义一个calculate对象	
				display1(p,p2,optor1);//输出运算的式子 
				p =D_multi(p,p2);
				display2(p,p2,optor1);//输出运算结果 
			}//进行乘法运算 
			if (optor1 == '/')
			{
				printf("请输入第一个十进制大整数：\n");
				char str1[99999], str2[99999];    //定义两个字符串 
				scanf("%s",&str1);//输入第一个字符串 
				printf("请输入第二个十进制大整数：\n");
				scanf("%s",&str2);//输入第二个字符串 
				start = clock();//开始计时 
				node *p;//链表头节点
				node *p2;//链表头节点
				
				p =  list(p,str1);
				p2 = list(p2,str2);
				
				//calculate val1(A, B, optor1);//定义一个calculate对象	
				display1(p,p2,optor1);//输出运算的式子 
				
				D_divide(p,p2);
			}//进行除法运算 
			if (optor1 == '^')
			{
				printf("请输入第一个十进制大整数：\n");
				char str1[99999], str2[99999];    //定义两个字符串 
				scanf("%s",&str1);//输入第一个字符串 
				printf("请输入第二个十进制大整数：\n");
				scanf("%s",&str2);//输入第二个字符串 
				start = clock();//开始计时 
				node *p;//链表头节点
				node *p2;//链表头节点
				
				p =  list(p,str1);
				p2 = list(p2,str2);
				
				//calculate val1(A, B, optor1);//定义一个calculate对象	
				display1(p,p2,optor1);//输出运算的式子 
				
				p =D_exp(p,p2);
				display2(p,p2,optor1);//输出运算结果 
			}//进行乘方运算 
			if (optor1 == '!')
			{
				printf("请输入第一个十进制大整数：\n");
				char str1[99999];    //定义两个字符串 
				scanf("%s",&str1);//输入第一个字符串 
			
				start = clock();//开始计时 
				node *p;//链表头节点
				node *p2;//链表头节点
				
				p =  list(p,str1);
				p2 = list(p2,"1");
				
				//calculate val1(A, B, optor1);//定义一个calculate对象	
					
				display3(p);//输出运算的式子 
				p = D_jiechen(p,p2);
				display2(p,p2,optor1);//输出运算结果 
			}
			finish = clock();//计时结束 

			printf("程序运行时间是：%d/1000(s)\n",finish - start);//输出运算时间
			printf("1.继续运算\n");
			printf("2.退出程序\n");
			printf("请输入1或2\n");
			int key3;
			scanf("%d",&key3);
			if (key3 == 2)
			exit(1);
		}
	}
	
	
	}
	
}
