#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//���� 
typedef struct train {
	int stationId;     //���κ�
	char from[20];      //���
	char to[20];        //Ŀ�ĵ�
	char stime[20];     //����ʱ��
	char rtime[20];     //����ʱ��
	int money;   //Ʊ��
	int ticket;  //Ʊ��
} Train;

//�û� 
typedef struct user {
	char name[10];
	char id[30];  //���֤��
	char tele_num[20];   //�绰��
	int t_id;   //�û��������κ�
	int money;  //Ʊ��
	int ticket; //Ʊ��
} User;

typedef struct node {         //�����г��ڵ�
	Train data;
	struct node *next;
} Node,*link;

typedef struct unode {  //�����û�����
	User data;
	struct unode *next;
} uNode,*ulink;              //24��31�����鱨��������


void menu();
void luru(link l);  //�ļ���Ϣ¼��
void search_t_from(link l);  //������ѯ����
void search_t_to(link l);   //���յ�վ��ѯ����
void search_t_id(link l);  //�����κŲ�ѯ
void search_t_(link l);  //�г���Ϣ��ѯ
void save(link l);             //�ļ�����
void orderTicket(link l,ulink u);  //��Ʊ
void returnTicket(link l,ulink u);
void updateInfo(link l);  //�г���Ϣ�޸�
void Info(Node *p);  //�г���Ϣ��ʾ
void Judge_ticket(Node *p);  //Ʊ���Ǹ����ж�
void Judge_money(Node *p);  //Ʊ�۷Ǹ��ж�

void all_show(link l);  //��ѯȫ���û�
void all_user(ulink u); //�û���Ϣ��ѯ
void load(link l);  //�ļ���������
void uInfo(uNode *p);  //�û���Ϣ

void menu() {
	system("cls");
	printf("\n\t-----------------------��ӭ����������Ʊϵͳ--------------------\n");
	printf("\n\t***********************\n");
	printf("\t1.¼���г���Ϣ\n\t2.��ѯ�г���Ϣ\n\t3.�޸��г���Ϣ\n\t4.��Ʊ\n\t5.��Ʊ����\n\t6.������¼�����Ϣ\n\t7.��ȡ�����г���Ϣ\n\t8.�˳�ϵͳ\n");
	printf("\n\t***********************\n\t");
	printf("������Ҫѡ��Ĺ��ܣ�1-8��:");
}

void Judge_ticket(Node *p) {  // Ʊ����Чֵ�ж�
	if(p->data.ticket<0) {
		printf("\tƱ��������������������:");
		scanf("%d",&p->data.ticket);
		Judge_ticket(p);
	}
}

void Judge_money(Node *p) {       //Ʊ����Чֵ�ж�
	if(p->data.money<0) {
		printf("\tƱ��������������������:");
		scanf("%d",&p->data.money);
		Judge_money(p);
	}
}

void luru(link l) { //1.�г���Ϣ¼��
	Node *p,*q;
	while(1) {  //��������ѭ��
		q=l;
		while(q->next!=NULL) {
			q=q->next;
		}
		p=(Node *)malloc(sizeof(Node));
		printf("\n\t-------------------------�г���Ϣ¼��--------------------------\n");
		if(!p) {
			printf("\t¼������");
			exit(0);
		}
		printf("\t1.�������г���:\t");
		scanf("%d",&p->data.stationId);
		printf("\t2.���������վ����:");
		scanf("%s",&p->data.from);
		printf("\t3.�������յ�վ����:");
		scanf("%s",&p->data.to);
		printf("\t4.�������г�����ʱ��:") ;
		scanf("%s",&p->data.stime);
		printf("\t5.�������г�����ʱ��:");
		scanf("%s",&p->data.rtime);
		printf("\t6.������Ʊ��:");
		scanf("%d",&p->data.money);
		Judge_money(p);
		printf("\t7.������Ʊ��:");
		scanf("%d",&p->data.ticket);
		Judge_ticket(p);
		p->next=NULL;
		q->next=p;
		q=p;
		printf("\t¼��ɹ�\t");
		
		break;
	}
	
		char is;
		printf("\n\t�밴������˳�:");
		getchar();
		scanf("%c",&is);
		return;
}

void save(link l) {        //��Ϣ�������ļ�
	Node *p;
	FILE *fp = NULL;
	p=l->next;

	if((fp=fopen("test30","wb"))==NULL) {
		printf("\t********�ļ���ʧ��**********");
		exit(0);
	} else
		printf("\t*********�ļ�����ɹ�***********");


	fwrite(p,sizeof(Node),1,fp);
	while(p) {
		fwrite(p,sizeof(Node),1,fp);
		p=p->next;
	}
	fclose(fp);
	char is;
	printf("\n\t�밴������˳�:");
	getchar();
	scanf("%c",&is);
	return;
}

void load(link l) {      //�ļ������������
	Node *p,*r;
	FILE *fp;
	l->next=NULL;
	r=l;
	if((fp=fopen("test30","rb"))==NULL) {
		printf("\n\t*********�ļ���ʧ��***********");

	} else {
		printf("\n\t***********�ļ����ݵ���ɹ�*********");
		int i =0;
		while(!feof(fp)) {
			
			p=(Node *)malloc(sizeof(Node));
			if(fread(p,sizeof(Node),1,fp)!=1) break;
			else {
				//���feof���һ�ε����� 
			if(i==0){
				i++;
				continue;
			}
				p->next=NULL;
				r->next=p;
				r=p;                    //ʵ�鱨�������㣡
			}
		}
	}
	char is;
	printf("\n\t�밴������˳�:");
	getchar();
	scanf("%c",&is);
	return;
}

void orderTicket(link l,ulink u) {            //4.��Ʊ
	Node *p;
	uNode *r,*q;
	int n;
	p=l;
	int t_id;
	printf("\n\t-------------------����Ʊ������д---------------------\n");
	printf("\t����������ҪԤ�����г���:");
	scanf("%d",&t_id);
	while(p!=NULL&&p->data.stationId!=t_id) {
		p=p->next;
	}
	if(p==NULL) {
		printf("\t**������س�Ʊ�ɹ�Ԥ����**");
	} else if(p->data.stationId==t_id){
		if(p->data.ticket<=0)
			printf("\t**�ó���Ʊ������**");
		else {
			while(1) {
				q=u;
				while(q->next!=NULL) {
					q=q->next;
				}
				r=(uNode *)malloc(sizeof(uNode));
				printf("\n\t#####�밴��ʾ�������ĸ�����Ϣ######\n");
				printf("\t��������������:");
				scanf("%s",&r->data.name);
				printf("\t�������������֤����:");
				scanf("%s",&r->data.id);
				printf("\t����������ֻ�����:");
				scanf("%s",&r->data.tele_num);
				r->data.t_id=t_id;              //ȷ����Ϣ      //ʵ�鱨�������㣡
				p->data.ticket=p->data.ticket-1;    //Ʊ������
				printf("\t���ѳɹ�Ԥ��һ���г�����Ϊ%d�ĳ�Ʊ��\n",r->data.t_id);
				r->next=NULL;
				q->next=r;
				q=r;
				break;
			}
		}
	}
		char is;
		printf("\n\t�밴������˳�:");
		getchar();
		scanf("%c",&is);
		return;
}

void updateInfo(link l) {  //�޸��г���Ϣ
	int num,n;
	Node *p;
	p=l;
	if(p==NULL)
		printf("\t**��ʱû�п����޸ĵ��г���Ϣ**\n");
	else {
		printf("\t��������Ҫ�޸��г���Ϣ���г���:");
		scanf("%d",&num);
		while(p->data.stationId!=num) {
			p=p->next;
			if(p==NULL) {
				printf("\t�Ҳ������г���Ϣ!");
				break;
			}
		}
		if(p!=NULL) {
			printf("\n\t-----------�г���Ϣ�޸�-----------\n");
			printf("\t1.�г���\n\t2.��ʼվ\n\t3.�յ�վ\n\t4.����ʱ��\n\t5.����ʱ��\n\t6.Ʊ��\n\t7.Ʊ��\n");
			printf("----------------___________--------------------\n");
			printf("\t��������Ҫ�޸ĵ���Ϣ���:");
			scanf("%d",&n);
			switch(n) {
				case 1:
					printf("\t������������г�����:");
					scanf("%d",&p->data.stationId);
					break;
				case 2:
					printf("\t�������������ʼվ:");
					scanf("%s",&p->data.from);
					break;
				case 3:
					printf("\t������������յ�վ:");
					scanf("%s",&p->data.to);
					break;
				case 4:
					printf("\t����������ĳ���ʱ��:");
					scanf("%s",&p->data.stime);
					break;
				case 5:
					printf("\t����������ĵ���ʱ��:");
					scanf("%s",&p->data.rtime);
					break;
				case 6:
					printf("\t�����������Ʊ��:");
					scanf("%s",&p->data.money);
					Judge_money(p);
					break;
				case 7:
					printf("\t�����������Ʊ��:");
					scanf("%d",&p->data.ticket);
					Judge_ticket(p);
					break;
				default:
					printf("\t�������");
					system("pause");      //�����������
			}
			if(n>=1&&n<=7)
				printf("\t**�޸ĳɹ�**");
		}
	}
		char is;
		printf("\n\t�밴������˳�:");
		getchar();
		scanf("%c",&is);
		return;
}

void returnTicket(link l,ulink u) {   //��Ʊ
	Node *p,*m;
	uNode *q,*r;
	char id[30];
	int ord;
	q=(uNode *)malloc(sizeof(uNode));
	p=l;
	r=u;
	char s;
	int input_t_id;
	printf("\n\t------------------��Ʊ��Ʊ����----------------\n");
	printf("\t��������Ҫ��Ʊ���г���:");
	scanf("%d",&input_t_id);
	printf("\t�������������֤�ţ�");
	scanf("%s",&id);
	while(r!=NULL) {
		if(strcmp(r->data.id,id)==0&&input_t_id==r->data.t_id) {

			printf("\t����ǰ�Ķ�Ʊ��Ϣ����:\n");
			printf("\t����:%s\n",r->data.name);
			printf("\t�绰����:%s\n",r->data.tele_num);
			printf("\t�г���Ϊ:%d\n",r->data.t_id);
			break;
		} else if(r==NULL) {
			printf("\tû�в�ѯ�����Ķ�����Ϣ");
		} else {
			r=r->next;     //������������ ��
		}
	}
	if(r==NULL) {
		printf("\t**û�в�ѯ�����Ķ�����Ϣ**");
	} else {
		printf("\t��ȷ��Ҫ��Ʊ��(Y/N)");
		fflush(stdin);
		scanf("%c",&s);
		if(s=='Y') {
			while(p!=NULL&&p->data.stationId!=input_t_id) {
				p=p->next;
			}
			if(p==NULL) {
				printf("\t��ѯ�����ó�Ʊ��Ϣ");
			} else {
				p->data.ticket+=1;
				q=r;
				r->next=q->next;
				free(r);
			}
			printf("\t**��Ʊ�ɹ�����лʹ�ã�**\n");
		} else
			printf("\n\t**����ȡ����Ʊ**\n");
	}
		char is;
		printf("\n\t�밴������˳�:");
		getchar();
		scanf("%c",&is);
		return;
}

void search_t_id(link l) {  //2.��ѯ�г���Ϣ
	int num_c;
	Node *p;
	p=l;
	printf("\t��������Ҫ���ҵ��г���Ϣ���г���:");
	scanf("%d",&num_c);
	printf("\n\t\t\t\t***********��ѯ���***********\n");
	printf("\t�г���\t����վ\t����վ\t����ʱ��\t����ʱ��\tƱ�ۣ�Ԫ��\tƱ�����ţ�\n");
	while(p) {
		if(p->data.stationId==num_c) {
			Info(p);            //ʵ�鱨�������㣡����ʲô ����ʵ�������Ϣ��
			break;
		}
		p=p->next;
	}
	if(!p) {
		printf("\tδ�ҵ����г�����Ϣ\n");
	}
	
		char is;
		printf("\n\t�밴������˳�:");
		getchar();
		scanf("%c",&is);
		return;
}

void search_t_from(link l) {        //������վ��ѯ
	Node *p;
	char tstation[20];
	p=l->next;          //�Ƚ� ����ʼվ��ѯ p=l; ����Ϊʲô
	int count=0;
	printf("\t������Ҫ��ѯ����ʼվ:");
	scanf("%s",&tstation);
	printf("\n\t\t\t\t**********��ѯ���***********\n");
	printf("\t�г���\t����վ\t�յ�վ\t����ʱ��\t����ʱ��\tƱ�����ţ�\tƱ�ۣ�Ԫ��\n");
	while(p) {
		if(strcmp(p->data.from,tstation)==0) {
			Info(p);
			count++;
		}
		if(p->next==NULL) break;
		else
			p=p->next;
	}
	if(!p||count==0) {
		printf("\tδ�ҵ����г���Ϣ");
	}
	char is;
	printf("\n\t�밴������˳�:");
	getchar();
	scanf("%c",&is);
	return;
}

void search_t_to(link l) {       //���յ�վ��ѯ
	Node *p;
	char tstation[20];
	p=l->next;          //�Ƚ� ����ʼվ��ѯ p=l; ����Ϊʲô
	int count=0;
	printf("\t������Ҫ��ѯ���յ�վ:");
	scanf("%s",&tstation);
	printf("\n\t\t\t\t**********��ѯ���***********\n");
	printf("\t�г���\t����վ\t�յ�վ\t����ʱ��\t����ʱ��\tƱ�����ţ�\tƱ�ۣ�Ԫ��\n");
	while(p) {
		if(strcmp(p->data.to,tstation)==0) {
			Info(p);
			count++;
		}
		if(p->next==NULL) break;
		else
			p=p->next;
	}
	if(!p||count==0) {
		printf("\tδ�ҵ����г���Ϣ");
	}
	char is;
	printf("\n\t�밴������˳�:");
	getchar();
	scanf("%c",&is);
	return;
}

void Info(Node *p) {      //�г���Ϣ��ѯ
	printf("\t%5d",p->data.stationId);
	printf("%10s",p->data.from);
	printf("%10s",p->data.to);
	printf("%10s",p->data.stime);
	printf("%10s",p->data.rtime);
	printf("%10d",p->data.ticket);
	printf("%10d\n",p->data.money);
}

void all_show(link l) {           //��ѯȫ��
	Node *p;
	p=l->next;
	printf("\n\t\t\t\t*************��ѯ���************\n");
	printf("\t�г���\tʼ��վ\t�յ�վ\t����ʱ��\t����ʱ��\tƱ�����ţ�\tƱ�ۣ�Ԫ��\n");
	if(p==NULL) {
		printf("\tδ��ѯ���κ��г���Ϣ��\n");
	}
	while(p!=NULL) {
		Info(p);
		p=p->next;
	}
	char is;
	printf("\n\t�밴������˳�:");
	getchar();
	scanf("%c",&is);
	return;
}

void search(link l) {                         //�г���Ϣ��ѯ
	int num;
	printf("\n\t-----------------�г���Ϣ��ѯ------------------\n");
	printf("\t1.���г��Ų�ѯ\n\t2.��ʼ��վ��ѯ\n\t3.���յ�վ��ѯ\n\t4.��ѯ�����г���Ϣ\n\n");
	printf("\t��������Ҫ��ѯ�ķ�ʽ");
	scanf("%d",&num);
	printf("\n\t-----------------____________------------------\n");
	switch(num) {
		case 1:
			search_t_id(l);
			break;
		case 2:
			search_t_from(l);
			break;
		case 3:
			search_t_to(l);
			break;
		case 4:
			all_show(l);
			break;
		default :
			printf("\t�������");
	}
}

int main() {
	link l;
	int num;
	ulink u;
	l=(Node *)malloc(sizeof(Node));
	u=(uNode *)malloc(sizeof(uNode));
	l->next=NULL;
	u->next=NULL;
	do {
		//system("date 2020/12/27");
		menu();
		scanf("%d",&num);
		switch(num) {
			case 1:
				luru(l);
				break;
			case 2:
				search(l);
				break;
			case 3:
				updateInfo(l);
				break;
			case 4:
				orderTicket(l,u);
				break;
			case 5:
				returnTicket(l,u);
				break;
			case 6:
				save(l);
				break;
			case 7:
				load(l);
				break;
			case 8:
				exit(1);
				break;
			default:
				continue;

		}
	} while(1);
	return 0;
}
