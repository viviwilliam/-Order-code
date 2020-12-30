#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//车次 
typedef struct train {
	int stationId;     //车次号
	char from[20];      //起点
	char to[20];        //目的地
	char stime[20];     //出发时间
	char rtime[20];     //到达时间
	int money;   //票价
	int ticket;  //票数
} Train;

//用户 
typedef struct user {
	char name[10];
	char id[30];  //身份证号
	char tele_num[20];   //电话号
	int t_id;   //用户所购车次号
	int money;  //票价
	int ticket; //票数
} User;

typedef struct node {         //定义列车节点
	Train data;
	struct node *next;
} Node,*link;

typedef struct unode {  //定义用户链表
	User data;
	struct unode *next;
} uNode,*ulink;              //24至31行试验报告描述！


void menu();
void luru(link l);  //文件信息录入
void search_t_from(link l);  //按起点查询车次
void search_t_to(link l);   //按终点站查询车次
void search_t_id(link l);  //按车次号查询
void search_t_(link l);  //列车信息查询
void save(link l);             //文件保存
void orderTicket(link l,ulink u);  //订票
void returnTicket(link l,ulink u);
void updateInfo(link l);  //列车信息修改
void Info(Node *p);  //列车信息显示
void Judge_ticket(Node *p);  //票数非负数判断
void Judge_money(Node *p);  //票价非负判断

void all_show(link l);  //查询全部用户
void all_user(ulink u); //用户信息查询
void load(link l);  //文件数据载入
void uInfo(uNode *p);  //用户信息

void menu() {
	system("cls");
	printf("\n\t-----------------------欢迎来到高铁订票系统--------------------\n");
	printf("\n\t***********************\n");
	printf("\t1.录入列车信息\n\t2.查询列车信息\n\t3.修改列车信息\n\t4.订票\n\t5.退票服务\n\t6.保存已录入的信息\n\t7.读取已有列车信息\n\t8.退出系统\n");
	printf("\n\t***********************\n\t");
	printf("输入您要选择的功能（1-8）:");
}

void Judge_ticket(Node *p) {  // 票数有效值判断
	if(p->data.ticket<0) {
		printf("\t票数输入有误，请重新输入:");
		scanf("%d",&p->data.ticket);
		Judge_ticket(p);
	}
}

void Judge_money(Node *p) {       //票价有效值判断
	if(p->data.money<0) {
		printf("\t票价输入有误，请重新输入:");
		scanf("%d",&p->data.money);
		Judge_money(p);
	}
}

void luru(link l) { //1.列车信息录入
	Node *p,*q;
	while(1) {  //控制无限循环
		q=l;
		while(q->next!=NULL) {
			q=q->next;
		}
		p=(Node *)malloc(sizeof(Node));
		printf("\n\t-------------------------列车信息录入--------------------------\n");
		if(!p) {
			printf("\t录入出差错");
			exit(0);
		}
		printf("\t1.请输入列车号:\t");
		scanf("%d",&p->data.stationId);
		printf("\t2.请输入起点站名称:");
		scanf("%s",&p->data.from);
		printf("\t3.请输入终点站名称:");
		scanf("%s",&p->data.to);
		printf("\t4.请输入列车出发时间:") ;
		scanf("%s",&p->data.stime);
		printf("\t5.请输入列车到达时间:");
		scanf("%s",&p->data.rtime);
		printf("\t6.请输入票价:");
		scanf("%d",&p->data.money);
		Judge_money(p);
		printf("\t7.请输入票数:");
		scanf("%d",&p->data.ticket);
		Judge_ticket(p);
		p->next=NULL;
		q->next=p;
		q=p;
		printf("\t录入成功\t");
		
		break;
	}
	
		char is;
		printf("\n\t请按任意键退出:");
		getchar();
		scanf("%c",&is);
		return;
}

void save(link l) {        //信息保存至文件
	Node *p;
	FILE *fp = NULL;
	p=l->next;

	if((fp=fopen("test30","wb"))==NULL) {
		printf("\t********文件打开失败**********");
		exit(0);
	} else
		printf("\t*********文件保存成功***********");


	fwrite(p,sizeof(Node),1,fp);
	while(p) {
		fwrite(p,sizeof(Node),1,fp);
		p=p->next;
	}
	fclose(fp);
	char is;
	printf("\n\t请按任意键退出:");
	getchar();
	scanf("%c",&is);
	return;
}

void load(link l) {      //文件数据载入程序
	Node *p,*r;
	FILE *fp;
	l->next=NULL;
	r=l;
	if((fp=fopen("test30","rb"))==NULL) {
		printf("\n\t*********文件打开失败***********");

	} else {
		printf("\n\t***********文件数据导入成功*********");
		int i =0;
		while(!feof(fp)) {
			
			p=(Node *)malloc(sizeof(Node));
			if(fread(p,sizeof(Node),1,fp)!=1) break;
			else {
				//解决feof多读一次的问题 
			if(i==0){
				i++;
				continue;
			}
				p->next=NULL;
				r->next=p;
				r=p;                    //实验报告描述点！
			}
		}
	}
	char is;
	printf("\n\t请按任意键退出:");
	getchar();
	scanf("%c",&is);
	return;
}

void orderTicket(link l,ulink u) {            //4.订票
	Node *p;
	uNode *r,*q;
	int n;
	p=l;
	int t_id;
	printf("\n\t-------------------高铁票订单填写---------------------\n");
	printf("\t请输入您需要预定的列车号:");
	scanf("%d",&t_id);
	while(p!=NULL&&p->data.stationId!=t_id) {
		p=p->next;
	}
	if(p==NULL) {
		printf("\t**暂无相关车票可供预定！**");
	} else if(p->data.stationId==t_id){
		if(p->data.ticket<=0)
			printf("\t**该车车票已售罄**");
		else {
			while(1) {
				q=u;
				while(q->next!=NULL) {
					q=q->next;
				}
				r=(uNode *)malloc(sizeof(uNode));
				printf("\n\t#####请按提示输入您的个人信息######\n");
				printf("\t请输入您的姓名:");
				scanf("%s",&r->data.name);
				printf("\t请输入您的身份证号码:");
				scanf("%s",&r->data.id);
				printf("\t请输入你的手机号码:");
				scanf("%s",&r->data.tele_num);
				r->data.t_id=t_id;              //确认信息      //实验报告描述点！
				p->data.ticket=p->data.ticket-1;    //票数减少
				printf("\t您已成功预定一张列车车号为%d的车票！\n",r->data.t_id);
				r->next=NULL;
				q->next=r;
				q=r;
				break;
			}
		}
	}
		char is;
		printf("\n\t请按任意键退出:");
		getchar();
		scanf("%c",&is);
		return;
}

void updateInfo(link l) {  //修改列车信息
	int num,n;
	Node *p;
	p=l;
	if(p==NULL)
		printf("\t**暂时没有可以修改的列车信息**\n");
	else {
		printf("\t请输入需要修改列车信息的列车号:");
		scanf("%d",&num);
		while(p->data.stationId!=num) {
			p=p->next;
			if(p==NULL) {
				printf("\t找不到该列车信息!");
				break;
			}
		}
		if(p!=NULL) {
			printf("\n\t-----------列车信息修改-----------\n");
			printf("\t1.列车号\n\t2.起始站\n\t3.终点站\n\t4.出发时间\n\t5.到达时间\n\t6.票价\n\t7.票数\n");
			printf("----------------___________--------------------\n");
			printf("\t请输入您要修改的信息编号:");
			scanf("%d",&n);
			switch(n) {
				case 1:
					printf("\t请输入变更后的列车车号:");
					scanf("%d",&p->data.stationId);
					break;
				case 2:
					printf("\t请输入变更后的起始站:");
					scanf("%s",&p->data.from);
					break;
				case 3:
					printf("\t请输入变更后的终点站:");
					scanf("%s",&p->data.to);
					break;
				case 4:
					printf("\t请输入变更后的出发时间:");
					scanf("%s",&p->data.stime);
					break;
				case 5:
					printf("\t请输入变更后的到达时间:");
					scanf("%s",&p->data.rtime);
					break;
				case 6:
					printf("\t请输入变更后的票价:");
					scanf("%s",&p->data.money);
					Judge_money(p);
					break;
				case 7:
					printf("\t请输入变更后的票数:");
					scanf("%d",&p->data.ticket);
					Judge_ticket(p);
					break;
				default:
					printf("\t输入错误！");
					system("pause");      //按任意键继续
			}
			if(n>=1&&n<=7)
				printf("\t**修改成功**");
		}
	}
		char is;
		printf("\n\t请按任意键退出:");
		getchar();
		scanf("%c",&is);
		return;
}

void returnTicket(link l,ulink u) {   //退票
	Node *p,*m;
	uNode *q,*r;
	char id[30];
	int ord;
	q=(uNode *)malloc(sizeof(uNode));
	p=l;
	r=u;
	char s;
	int input_t_id;
	printf("\n\t------------------车票退票界面----------------\n");
	printf("\t请输入您要退票的列车号:");
	scanf("%d",&input_t_id);
	printf("\t请输入您的身份证号：");
	scanf("%s",&id);
	while(r!=NULL) {
		if(strcmp(r->data.id,id)==0&&input_t_id==r->data.t_id) {

			printf("\t您当前的订票信息如下:\n");
			printf("\t名字:%s\n",r->data.name);
			printf("\t电话号码:%s\n",r->data.tele_num);
			printf("\t列车号为:%d\n",r->data.t_id);
			break;
		} else if(r==NULL) {
			printf("\t没有查询到您的订单信息");
		} else {
			r=r->next;     //报告中描述点 ！
		}
	}
	if(r==NULL) {
		printf("\t**没有查询到您的订单信息**");
	} else {
		printf("\t您确定要退票吗？(Y/N)");
		fflush(stdin);
		scanf("%c",&s);
		if(s=='Y') {
			while(p!=NULL&&p->data.stationId!=input_t_id) {
				p=p->next;
			}
			if(p==NULL) {
				printf("\t查询不到该车票信息");
			} else {
				p->data.ticket+=1;
				q=r;
				r->next=q->next;
				free(r);
			}
			printf("\t**退票成功，感谢使用！**\n");
		} else
			printf("\n\t**您已取消退票**\n");
	}
		char is;
		printf("\n\t请按任意键退出:");
		getchar();
		scanf("%c",&is);
		return;
}

void search_t_id(link l) {  //2.查询列车信息
	int num_c;
	Node *p;
	p=l;
	printf("\t请输入您要查找的列车信息的列车号:");
	scanf("%d",&num_c);
	printf("\n\t\t\t\t***********查询结果***********\n");
	printf("\t列车号\t发车站\t到达站\t发车时间\t到达时间\t票价（元）\t票数（张）\n");
	while(p) {
		if(p->data.stationId==num_c) {
			Info(p);            //实验报告描述点！（是什么 怎样实现输出信息）
			break;
		}
		p=p->next;
	}
	if(!p) {
		printf("\t未找到该列车号信息\n");
	}
	
		char is;
		printf("\n\t请按任意键退出:");
		getchar();
		scanf("%c",&is);
		return;
}

void search_t_from(link l) {        //按发车站查询
	Node *p;
	char tstation[20];
	p=l->next;          //比较 按起始站查询 p=l; 分析为什么
	int count=0;
	printf("\t输入您要查询的起始站:");
	scanf("%s",&tstation);
	printf("\n\t\t\t\t**********查询结果***********\n");
	printf("\t列车号\t发车站\t终点站\t发车时间\t到达时间\t票数（张）\t票价（元）\n");
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
		printf("\t未找到该列车信息");
	}
	char is;
	printf("\n\t请按任意键退出:");
	getchar();
	scanf("%c",&is);
	return;
}

void search_t_to(link l) {       //按终点站查询
	Node *p;
	char tstation[20];
	p=l->next;          //比较 按起始站查询 p=l; 分析为什么
	int count=0;
	printf("\t输入您要查询的终点站:");
	scanf("%s",&tstation);
	printf("\n\t\t\t\t**********查询结果***********\n");
	printf("\t列车号\t发车站\t终点站\t发车时间\t到达时间\t票数（张）\t票价（元）\n");
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
		printf("\t未找到该列车信息");
	}
	char is;
	printf("\n\t请按任意键退出:");
	getchar();
	scanf("%c",&is);
	return;
}

void Info(Node *p) {      //列车信息查询
	printf("\t%5d",p->data.stationId);
	printf("%10s",p->data.from);
	printf("%10s",p->data.to);
	printf("%10s",p->data.stime);
	printf("%10s",p->data.rtime);
	printf("%10d",p->data.ticket);
	printf("%10d\n",p->data.money);
}

void all_show(link l) {           //查询全部
	Node *p;
	p=l->next;
	printf("\n\t\t\t\t*************查询结果************\n");
	printf("\t列车号\t始发站\t终点站\t发车时间\t到达时间\t票数（张）\t票价（元）\n");
	if(p==NULL) {
		printf("\t未查询到任何列车信息！\n");
	}
	while(p!=NULL) {
		Info(p);
		p=p->next;
	}
	char is;
	printf("\n\t请按任意键退出:");
	getchar();
	scanf("%c",&is);
	return;
}

void search(link l) {                         //列车信息查询
	int num;
	printf("\n\t-----------------列车信息查询------------------\n");
	printf("\t1.按列车号查询\n\t2.按始发站查询\n\t3.按终点站查询\n\t4.查询所有列车信息\n\n");
	printf("\t请输入您要查询的方式");
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
			printf("\t输入错误");
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
