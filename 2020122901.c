#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
//人数 
int num;
//名次 
int PaiMing[40];

//链表中的一个节点 
//学生信息 
typedef struct student{
	int num;//学号 
	char name[20];//姓名 
	int  chinese;
	int  math;
	int  english; 
	char  classno[20];   //班级 
	
	struct student  *link;//指针域 
}students;

//初始化一个链表
students *list_init() {
	//创建根节点
	students *head = (students *) malloc(sizeof(students));
	if(NULL == head){
		printf("错误。申请内存失败，创建节点失败\n");
		exit(1); 
	}
	head->link = NULL;
	return head;
}


void saveFile(students *head) {        //信息保存至文件
	students *p;
	FILE *fp = NULL;
	p=head->link;

	if((fp=fopen("test30","wb"))==NULL) {
		printf("\t********文件打开失败**********");
		exit(0);
	} else
		printf("\t*********文件保存成功***********");


	fwrite(p,sizeof(students),1,fp);
	while(p) {
		fwrite(p,sizeof(students),1,fp);
		p=p->link;
	}
	fclose(fp);
	char is;
	printf("\n\t请按任意键退出:");
	getchar();
	scanf("%c",&is);
	return;
}

void read(students *head){      //文件数据载入程序
	students *p,*r;
	FILE *fp;
	head->link=NULL;
	r=head;
	if((fp=fopen("test30","rb"))==NULL) {
		printf("\n\t*********文件打开失败***********");

	} else {
		printf("\n\t***********文件数据导入成功*********");
		int i =0;
		while(!feof(fp)) {
			
			p=(students *)malloc(sizeof(students));
			if(fread(p,sizeof(students),1,fp)!=1) break;
			else {
				//解决feof多读一次的问题 
			if(i==0){
				i++;
				continue;
			}
				p->link=NULL;
				r->link=p;
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




void ordering(students* head)
{
	students *pi, *pj, *pt, t;
		for (pi = head->link; pi;pi=pi->link)
			for (pj = pi->link; pj; pj = pj->link)
				if (pi->num > pj->num)
				{
					t = *pi;
					*pi = *pj;
					*pj = t;
			 
					pt = pi->link;
					pi->link = pj->link;
					pj->link = pt;
				}
	
	
}

//学科平均分和及格率
void subjects(students *head){
	double c6,e6,m6;
	c6=e6=m6=0.0;
	int sum1=0,sum2=0,sum3=0,sum=0;
	head = head->link;
	while(NULL!=head){
		sum1+=head->chinese;
		sum2+=head->math;
		sum3+=head->english;
		if(head->chinese>=60){
			c6+=1;
		}
		if(head->math>=60){
			m6+=1;
		}
		if(head->english>=60){
			e6+=1;
		}
		sum++;
		head = head->link;
	}
	printf("学科|平均分|及格率\n"); 
	printf("语文|%d|%f\n",sum1/sum,c6/sum); 
	printf("数学|%d|%f\n",sum2/sum,m6/sum); 
	printf("英语|%d|%f\n",sum3/sum,e6/sum); 
	
	char is;
	printf("\n是否退出（y/n）:");
	getchar();
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		subjects(head);
	}
} 



//显示所有信息

void show(students *head){
	int i;
	int ave;
	printf("学号|姓名|语文|数学|英语|平均分|班级\n");
	head = head->link;
	while(NULL != head){
		ave = (head->chinese+head->math+head->english)/3;
		printf("%d|%s|%d|%d|%d|%d|%s\n",head->num,head->name,head->chinese,head->math,head->english,ave,head->classno);
					
		head = head->link;
	}
	char is;
	printf("\n是否退出（y/n）:");
	getchar();
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		show(head);
	}
} 


//查询指定的信息
void find(students *head){
		char chaxun[20];
		char is;
		printf("输入要查询的学生姓名："); 
		scanf("%s",&chaxun);
		
		
		while(NULL!= head){
			if(strcmp(chaxun, head->name)==0){
				printf("学号|姓名|语文|数学|英语|班级\n");
				printf("%d|%s|%d|%d|%d|%s\n",head->num,head->name,head->chinese,head->math,head->english,head->classno);				
	
			}
			head = head->link; 
			
		} 
		printf("\n是否退出（y/n）：");
			getchar();
			scanf("%c",&is);
			if(is == 'y'){
				return ;
			}
			else{
				find(head);
			}
	
}


//修改指定信息
void change(students *head){
		char chaxun[20];
		char is;
		printf("输入要修改信息的学生姓名："); 
		scanf("%s",&chaxun);
		
		
		while(NULL!= head){
			if(strcmp(chaxun, head->name)==0){
				printf("请输入学生姓名：\n");
				getchar();
				gets(head->name);
				printf("请输入学生的学号：\n");
				scanf("%d",&head->num);
				printf("请输入学生的语文成绩：\n");
				scanf("%d",&head->chinese);
			
				printf("请输入学生的数学成绩：\n");
				scanf("%d",&head->math);
				printf("请输入学生的英语成绩：\n");
				scanf("%d",&head->english);
				printf("请输入学生的班级：\n");
				scanf("%s",&head->classno);
				break;
			}
			head = head->link; 
			
		} 
		printf("\n是否退出（y/n）：");
			getchar();
			scanf("%c",&is);
			if(is == 'y'){
				return ;
			}
			else{
				find(head);
			}
	
}
 



//删除指定的信息
students * dele(students *head){
		char chaxun[20];
		char is;
		printf("输入要删除的学生姓名："); 
		scanf("%s",&chaxun);
		
		students * temp = NULL;
		students * head_temp = head;
		
		while(NULL!= head){
			if(strcmp(chaxun, head->name)==0){
				temp->link = head->link;
				free(head);
				printf("删除成功！\n");
				break;
			}
			temp = head;
			head = head->link;
		} 
		printf("\n是否退出（y/n）：");
			getchar();
			scanf("%c",&is);
			if(is == 'y'){
				return head_temp;
			}
			else{
				head_temp = dele(head_temp);
			}
	return head_temp;	
}






 //尾插法 
void input(students *head){
	int i=0;
	char isorno;
	while(1){
		students *new_student = (students *)malloc(sizeof(students));
		//找到最近添加的数据 
		while(head->link) {
			head = head->link;
		}
		 
		printf("请输入学生姓名：\n");
		getchar();
		gets(new_student->name);
		printf("请输入学生的学号：\n");
		scanf("%d",&new_student->num);
		printf("请输入学生的语文成绩：\n");
		scanf("%d",&new_student->chinese);
		printf("请输入学生的数学成绩：\n");
		scanf("%d",&new_student->math);
		printf("请输入学生的英语成绩：\n");
		scanf("%d",&new_student->english);
		printf("请输入学生的班级：\n");
		scanf("%s",&new_student->classno);
	
		new_student->link = NULL;
		head->link = new_student;
		printf("录入成功！是否继续(y/n)：\n");
		
		getchar();
		scanf("%c",&isorno);
		if(isorno=='n'){
			return;
		}	
	}

} 
 



 
//主界面 
int main(){
	//创建头节点
	students *head; 
	head = list_init(); 
	int a;
	
	while(1){
	system("cls"); 
	printf(">>>  学生信息管理系统  <<<\n\n"); 
	printf("操作选单\n"); 
	printf("请用数字键选择操作\n"); 
	printf("1.录入学生基本信息\n"); 
	printf("2.删除学生基本信息\n"); 
	printf("3.将学生基本信息录入文件\n"); 
	printf("4.查询学生基本信息\n"); 
	printf("5.修改学生基本信息\n"); 
	printf("6.读取学生基本信息\n"); 
	printf("7.查看学科平均成绩及及格率\n"); 
	printf("8.显示所有学生基本信息（按学号排序）\n"); 
	printf("0.退出\n"); 
	scanf("%d",&a);
	switch(a){
		//输入学生信息
		case 1:
			input(head);
			break;
		//删除学生基本信息
		case 2:
			head = dele(head);
			break;
		//将学生基本信息录入文件 
		case 3:
			saveFile(head);
			break;
		//查询学生基本信息
		case 4:
			find(head);
			break;
		//修改学生信息 
		case 5:
			change(head);
			break;
		//显示所有信息 
		case 6:
			read(head);
			break;
		//显示学科平均分和及格率 
		case 7:
			subjects(head);
			break;
		case 8:
			ordering(head); 
			show(head);
			break;

		//退出	
		case 0:
			exit(0);
	}
	}
	return 0;	 
}
