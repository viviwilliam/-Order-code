#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
//���� 
int num;
//���� 
int PaiMing[40];

//ѧ����Ϣ 
struct student{
	char num[20];
	char name[20];
	int MT;
	int EN;
	int PH;
	double Zong;
	double Ping; 
}students[40];




void input(){
	int i=0;
	char isorno;
	while(1){

		printf("������ѧ��������\n");
		getchar();
		gets(students[i].name);
		printf("������ѧ����ѧ�ţ�\n");
		scanf("%s",&students[i].num);
		printf("������ѧ������ѧ�ɼ���\n");
		scanf("%d",&students[i].MT);
		printf("������ѧ����Ӣ��ɼ���\n");
		scanf("%d",&students[i].EN);
		printf("������ѧ��������ɼ���\n");
		scanf("%d",&students[i].PH);
		PaiMing[i] = i;
		i++; 
		num++;
		printf("¼��ɹ����Ƿ����(y/n)��\n");
		
		getchar();
		scanf("%c",&isorno);
		if(i==40){
			printf("�����������ޣ����ټ�����");
			return; 
		}
		if(isorno=='n'){
			return;
		}	
	}

} 

void ZongPaixu(){
	int i;
	int j;
	int c;
	//���� 
	for(i=0;i<num-1;i++){
		for(j=i+1;j<num;j++){
			
			if(students[PaiMing[i]].Zong<students[PaiMing[j]].Zong){
				c = PaiMing[i];
				PaiMing[i] = PaiMing[j];
				PaiMing[j] = c;
			}
		}
	}
}

 
void ZongSort(){

	int a,b,c; 
	char is;
	int i;

	ZongPaixu();
	
	printf("ѧ��|����|��ѧ|Ӣ��|����|�ܷ�|ƽ����|����\n");
	for(i=0;i<num;i++){
		printf("%s|%s|%d|%d|%d|%lf|%lf|%d\n",students[PaiMing[i]].num,students[PaiMing[i]].name,students[PaiMing[i]].MT,
		students[PaiMing[i]].EN,students[PaiMing[i]].PH,students[PaiMing[i]].Zong,students[PaiMing[i]].Ping,i+1);
	}
	
	printf("\n�Ƿ��˳���y/n����");
	getchar();
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		ZongSort();
	}
} 

//����ܷ���ߺ����
void grade(){
	int a,b,c; 
	char is;
	int i;

	ZongPaixu();
	printf("��ߣ�\n");
	printf("ѧ��|����|��ѧ|Ӣ��|����|�ܷ�|ƽ����|����\n");
	
		printf("%s|%s|%d|%d|%d|%lf|%lf|1\n",students[PaiMing[0]].num,students[PaiMing[0]].name,students[PaiMing[0]].MT,
		students[PaiMing[0]].EN,students[PaiMing[0]].PH,students[PaiMing[0]].Zong,students[PaiMing[0]].Ping);
	printf("��ͣ�\n");
	printf("ѧ��|����|��ѧ|Ӣ��|����|�ܷ�|ƽ����|����\n");
		printf("%s|%s|%d|%d|%d|%lf|%lf|%d\n",students[PaiMing[num-1]].num,students[PaiMing[num-1]].name,students[PaiMing[num-1]].MT,
		students[PaiMing[0]].EN,students[PaiMing[num-1]].PH,students[PaiMing[num-1]].Zong,students[PaiMing[num-1]].Ping,num);
	
	printf("\n�Ƿ��˳���y/n����");
	getchar();
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		grade();
	}
} 

void NumSort(){

	int a,b,c; 
	char is;
	int i;
	int j;
	for(i =0;i<num;i++){
		students[i].Zong = students[i].MT+students[i].EN+students[i].PH;
		students[i].Ping = students[i].Zong/3;
	}
	
	
	//���� 
	for(i=0;i<num-1;i++){
		for(j=i+1;j<num;j++){
			
			a = atoi(students[PaiMing[i]].num);
			b = atoi(students[PaiMing[j]].num);
			if(a>b){
				c = PaiMing[i];
				PaiMing[i] = PaiMing[j];
				PaiMing[j] = c;
			}
		}
	}

	printf("ѧ��|����|��ѧ|Ӣ��|����|�ܷ�|ƽ����|����\n");
	for(i=0;i<num;i++){
		printf("%s|%s|%d|%d|%d|%lf|%lf|%d\n",students[PaiMing[i]].num,students[PaiMing[i]].name,students[PaiMing[i]].MT,
		students[PaiMing[i]].EN,students[PaiMing[i]].PH,students[PaiMing[i]].Zong,students[PaiMing[i]].Ping,i+1);
	}
	
	printf("\n�Ƿ��˳���y/n����");
	getchar();
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		NumSort();	
	}
} 

void NameSort(){

	int a,b,c; 
	char is;
	int i;
	int j;
	
	//���� 
	for(i=0;i<num-1;i++){
		for(j=i+1;j<num;j++){
			int m;
			for(m =0;m<20;m++){
				if(students[PaiMing[i]].name[0]==students[PaiMing[j]].name[0])
					continue;
				else if(students[PaiMing[i]].name[0]>students[PaiMing[j]].name[0]){
					c = PaiMing[i];
					PaiMing[i] = PaiMing[j];
					PaiMing[j] = c;
					break;
				}
				else{
					break;
				}
			}
			
		}
	}

	printf("ѧ��|����|��ѧ|Ӣ��|����|�ܷ�|ƽ����|����\n");
	for(i=0;i<num;i++){
		printf("%s|%s|%d|%d|%d|%lf|%lf|%d\n",students[PaiMing[i]].num,students[PaiMing[i]].name,students[PaiMing[i]].MT,
		students[PaiMing[i]].EN,students[PaiMing[i]].PH,students[PaiMing[i]].Zong,students[PaiMing[i]].Ping,i+1);
	}
	
	printf("\n�Ƿ��˳���y/n����");
	getchar();
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		NameSort();	
	}
} 

//��Ų�ѯ 
void NumSearch(){
	char chaxun[20];
	char is;
	int i;
	int j;
	printf("����Ҫ��ѯ�ı�ţ�"); 
	scanf("%s",&chaxun);
	
	for(i=0;i<num;i++){
		if(strcmp(chaxun, students[i].num)==0){
		printf("ѧ��|����|��ѧ|Ӣ��|����|�ܷ�|ƽ����\n");
		printf("%s|%s|%d|%d|%d|%lf|%lf\n",students[i].num,students[i].name,students[i].MT,
		students[i].EN,students[i].PH,students[i].Zong,students[i].Ping);			
		break;
		}
	}
	
	printf("\n�Ƿ��˳���y/n����");
	getchar();
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		NumSearch();
	}
} 

//���ֲ�ѯ 
void NameSearch(){
	char chaxun[20];
	char is;
	int i;
	int j;
	printf("����Ҫ��ѯ�����֣�\n"); 
	getchar();
	gets(chaxun);
	
	for(i=0;i<num;i++){
		if(strcmp(chaxun, students[i].name)==0){
		printf("ѧ��|����|��ѧ|Ӣ��|����|�ܷ�|ƽ����\n");
		printf("%s|%s|%d|%d|%d|%lf|%lf\n",students[i].num,students[i].name,students[i].MT,
		students[i].EN,students[i].PH,students[i].Zong,students[i].Ping);			
		break;
		}
	}
	
	printf("\n�Ƿ��˳���y/n��:");
	getchar();
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		NameSearch();
	}
} 

 
//������ 
int main(){
	while(1){
	system("cls"); 
	printf("1.Input records.\n"); 
	printf("2.Sort in ascending order by number and output records.\n"); 
	printf("3.Sort in descending order by total score and output records.\n"); 
	printf("4.Sort in ascending order by name and output records.\n"); 
	printf("5.Search by number and output the record.\n"); 
	printf("6.Search by name and output the record.\n"); 
	printf("7.Output the highest and lowest student records\n"); 
	printf("0.Exit.\n"); 
	printf("Please enter your choice:\n");
	
	
	int a; 
	scanf("%d",&a);
	
	switch(a){
		//����ѧ����Ϣ
		case 1:
			input();
			break;
		//�������
		case 2:
			NumSort();
			break;
		//�ܷ����� 
		case 3:
			ZongSort();
			break;
		//��������
		case 4:
			NameSort();
			break;
		//��Ų�ѯ 
		case 5:
			NumSearch();
			break;
		//���ֲ�ѯ 
		case 6:
			NameSearch();
			break;
		//�����ͳɼ� 
		case 7:
			grade();
			break;
		//�˳�	
		case 0:
			return;
	}
	}	 
}
