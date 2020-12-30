#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
//���� 
int num;
//���� 
int PaiMing[40];

//�����е�һ���ڵ� 
//ѧ����Ϣ 
typedef struct student{
	int num;//ѧ�� 
	char name[20];//���� 
	int  chinese;
	int  math;
	int  english; 
	char  classno[20];   //�༶ 
	
	struct student  *link;//ָ���� 
}students;

//��ʼ��һ������
students *list_init() {
	//�������ڵ�
	students *head = (students *) malloc(sizeof(students));
	if(NULL == head){
		printf("���������ڴ�ʧ�ܣ������ڵ�ʧ��\n");
		exit(1); 
	}
	head->link = NULL;
	return head;
}


void saveFile(students *head) {        //��Ϣ�������ļ�
	students *p;
	FILE *fp = NULL;
	p=head->link;

	if((fp=fopen("test30","wb"))==NULL) {
		printf("\t********�ļ���ʧ��**********");
		exit(0);
	} else
		printf("\t*********�ļ�����ɹ�***********");


	fwrite(p,sizeof(students),1,fp);
	while(p) {
		fwrite(p,sizeof(students),1,fp);
		p=p->link;
	}
	fclose(fp);
	char is;
	printf("\n\t�밴������˳�:");
	getchar();
	scanf("%c",&is);
	return;
}

void read(students *head){      //�ļ������������
	students *p,*r;
	FILE *fp;
	head->link=NULL;
	r=head;
	if((fp=fopen("test30","rb"))==NULL) {
		printf("\n\t*********�ļ���ʧ��***********");

	} else {
		printf("\n\t***********�ļ����ݵ���ɹ�*********");
		int i =0;
		while(!feof(fp)) {
			
			p=(students *)malloc(sizeof(students));
			if(fread(p,sizeof(students),1,fp)!=1) break;
			else {
				//���feof���һ�ε����� 
			if(i==0){
				i++;
				continue;
			}
				p->link=NULL;
				r->link=p;
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

//ѧ��ƽ���ֺͼ�����
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
	printf("ѧ��|ƽ����|������\n"); 
	printf("����|%d|%f\n",sum1/sum,c6/sum); 
	printf("��ѧ|%d|%f\n",sum2/sum,m6/sum); 
	printf("Ӣ��|%d|%f\n",sum3/sum,e6/sum); 
	
	char is;
	printf("\n�Ƿ��˳���y/n��:");
	getchar();
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		subjects(head);
	}
} 



//��ʾ������Ϣ

void show(students *head){
	int i;
	int ave;
	printf("ѧ��|����|����|��ѧ|Ӣ��|ƽ����|�༶\n");
	head = head->link;
	while(NULL != head){
		ave = (head->chinese+head->math+head->english)/3;
		printf("%d|%s|%d|%d|%d|%d|%s\n",head->num,head->name,head->chinese,head->math,head->english,ave,head->classno);
					
		head = head->link;
	}
	char is;
	printf("\n�Ƿ��˳���y/n��:");
	getchar();
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		show(head);
	}
} 


//��ѯָ������Ϣ
void find(students *head){
		char chaxun[20];
		char is;
		printf("����Ҫ��ѯ��ѧ��������"); 
		scanf("%s",&chaxun);
		
		
		while(NULL!= head){
			if(strcmp(chaxun, head->name)==0){
				printf("ѧ��|����|����|��ѧ|Ӣ��|�༶\n");
				printf("%d|%s|%d|%d|%d|%s\n",head->num,head->name,head->chinese,head->math,head->english,head->classno);				
	
			}
			head = head->link; 
			
		} 
		printf("\n�Ƿ��˳���y/n����");
			getchar();
			scanf("%c",&is);
			if(is == 'y'){
				return ;
			}
			else{
				find(head);
			}
	
}


//�޸�ָ����Ϣ
void change(students *head){
		char chaxun[20];
		char is;
		printf("����Ҫ�޸���Ϣ��ѧ��������"); 
		scanf("%s",&chaxun);
		
		
		while(NULL!= head){
			if(strcmp(chaxun, head->name)==0){
				printf("������ѧ��������\n");
				getchar();
				gets(head->name);
				printf("������ѧ����ѧ�ţ�\n");
				scanf("%d",&head->num);
				printf("������ѧ�������ĳɼ���\n");
				scanf("%d",&head->chinese);
			
				printf("������ѧ������ѧ�ɼ���\n");
				scanf("%d",&head->math);
				printf("������ѧ����Ӣ��ɼ���\n");
				scanf("%d",&head->english);
				printf("������ѧ���İ༶��\n");
				scanf("%s",&head->classno);
				break;
			}
			head = head->link; 
			
		} 
		printf("\n�Ƿ��˳���y/n����");
			getchar();
			scanf("%c",&is);
			if(is == 'y'){
				return ;
			}
			else{
				find(head);
			}
	
}
 



//ɾ��ָ������Ϣ
students * dele(students *head){
		char chaxun[20];
		char is;
		printf("����Ҫɾ����ѧ��������"); 
		scanf("%s",&chaxun);
		
		students * temp = NULL;
		students * head_temp = head;
		
		while(NULL!= head){
			if(strcmp(chaxun, head->name)==0){
				temp->link = head->link;
				free(head);
				printf("ɾ���ɹ���\n");
				break;
			}
			temp = head;
			head = head->link;
		} 
		printf("\n�Ƿ��˳���y/n����");
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






 //β�巨 
void input(students *head){
	int i=0;
	char isorno;
	while(1){
		students *new_student = (students *)malloc(sizeof(students));
		//�ҵ������ӵ����� 
		while(head->link) {
			head = head->link;
		}
		 
		printf("������ѧ��������\n");
		getchar();
		gets(new_student->name);
		printf("������ѧ����ѧ�ţ�\n");
		scanf("%d",&new_student->num);
		printf("������ѧ�������ĳɼ���\n");
		scanf("%d",&new_student->chinese);
		printf("������ѧ������ѧ�ɼ���\n");
		scanf("%d",&new_student->math);
		printf("������ѧ����Ӣ��ɼ���\n");
		scanf("%d",&new_student->english);
		printf("������ѧ���İ༶��\n");
		scanf("%s",&new_student->classno);
	
		new_student->link = NULL;
		head->link = new_student;
		printf("¼��ɹ����Ƿ����(y/n)��\n");
		
		getchar();
		scanf("%c",&isorno);
		if(isorno=='n'){
			return;
		}	
	}

} 
 



 
//������ 
int main(){
	//����ͷ�ڵ�
	students *head; 
	head = list_init(); 
	int a;
	
	while(1){
	system("cls"); 
	printf(">>>  ѧ����Ϣ����ϵͳ  <<<\n\n"); 
	printf("����ѡ��\n"); 
	printf("�������ּ�ѡ�����\n"); 
	printf("1.¼��ѧ��������Ϣ\n"); 
	printf("2.ɾ��ѧ��������Ϣ\n"); 
	printf("3.��ѧ��������Ϣ¼���ļ�\n"); 
	printf("4.��ѯѧ��������Ϣ\n"); 
	printf("5.�޸�ѧ��������Ϣ\n"); 
	printf("6.��ȡѧ��������Ϣ\n"); 
	printf("7.�鿴ѧ��ƽ���ɼ���������\n"); 
	printf("8.��ʾ����ѧ��������Ϣ����ѧ������\n"); 
	printf("0.�˳�\n"); 
	scanf("%d",&a);
	switch(a){
		//����ѧ����Ϣ
		case 1:
			input(head);
			break;
		//ɾ��ѧ��������Ϣ
		case 2:
			head = dele(head);
			break;
		//��ѧ��������Ϣ¼���ļ� 
		case 3:
			saveFile(head);
			break;
		//��ѯѧ��������Ϣ
		case 4:
			find(head);
			break;
		//�޸�ѧ����Ϣ 
		case 5:
			change(head);
			break;
		//��ʾ������Ϣ 
		case 6:
			read(head);
			break;
		//��ʾѧ��ƽ���ֺͼ����� 
		case 7:
			subjects(head);
			break;
		case 8:
			ordering(head); 
			show(head);
			break;

		//�˳�	
		case 0:
			exit(0);
	}
	}
	return 0;	 
}
