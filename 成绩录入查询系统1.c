#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>

//ѧ��ÿ���˵���Ϣ 
struct student{
	int No;
	char ID[20];
	char name[30];
	int math;
	int english;
	int physical;
	int sum;
	int ave;
	int weigh; 
}students[40];
//¼��������� 



//������� 
int no[1000];
int num;

//ͨ��������������
void SearchByName(){
	system("cls");
	char serch[30];
	int a=1;
	int i;
	int j;
	//չʾ���� 
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------ѧ����Ϣ����------------------------------------\n"); 
	printf("--------------------------------------����������-------------------------------------\n"); 
	printf("����Ҫ������������\n");
	getchar();
	scanf("%s",&serch);
	
	for(i=0;i<num;i++){
		if(strcmp(serch, students[i].name)){
		printf("ѧ��\t����\t\t��ѧ\tӢ��\t����\t�ܷ�\tƽ����\n");
		printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",students[i].ID,students[i].name,students[i].math,students[i].english,students[i].physical,students[i].sum,students[i].ave);
			break;
		}
	}
	
	printf("\n\n�Ƿ������1/0����");
	scanf("%d",&a);
	if(a == 0){
		main();
	}
	if(a == 1){
		SearchByName();
	}
} 



//ͨ����Ž�������
void SearchByNo(){
	system("cls");
	int serch;
	int a=1;
	int i;
	int j;
	//չʾ���� 
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------ѧ����Ϣ����------------------------------------\n"); 
	printf("--------------------------------------���������-------------------------------------\n"); 
	printf("����Ҫ�����ı�ţ�"); 
	scanf("%d",&serch);
	
	for(i=0;i<num;i++){
		if(students[i].No==serch){
		printf("ѧ��\t����\t\t��ѧ\tӢ��\t����\t�ܷ�\tƽ����\n");
		printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",students[i].ID,students[i].name,students[i].math,students[i].english,students[i].physical,students[i].sum,students[i].ave);
			break;
		}
	}
	
	printf("\n\n�Ƿ������1/0����");
	scanf("%d",&a);
	if(a == 0){
		main();
	}
	if(a == 1){
		SearchByNo();
	}
} 



//�������� 
void SortByName(){
	system("cls");
	int mid;
	int a=1;
	int i;
	int j;
	//ð������ 
	for(i=0;i<num-1;i++){
		for(j=i+1;j<num;j++){
			if(students[no[i]].name[0]>students[no[j]].name[0]){
				mid = no[i];
				no[i] = no[j];
				no[j] = mid;
			}
		}
	}
	//չʾ���� 
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------ѧ����Ϣ����------------------------------------\n"); 
	printf("---------------------------------------��������--------------------------------------\n"); 
	printf("ѧ��\t����\t\t��ѧ\tӢ��\t����\t�ܷ�\tƽ����\t����\n");
	for(i=0;i<num;i++){
		printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",students[no[i]].ID,students[no[i]].name,students[no[i]].math,students[no[i]].english,students[no[i]].physical,students[no[i]].sum,students[no[i]].ave,i+1);
	}
	
	printf("\n\n��0�˳���");
	scanf("%d",&a);
	if(a == 0){
		main();
	}
}
 
 
 //����ܷ���ߺ���Ͷ��� 
void outputSum(){
	system("cls");
	int mid;
	int a=1;
	int i;
	int j;
	//ð������ 
	for(i=0;i<num-1;i++){
		for(j=i+1;j<num;j++){
			if(students[no[i]].sum<students[no[j]].sum){
				mid = no[i];
				no[i] = no[j];
				no[j] = mid;
			}
		}
	}
	//չʾ���� 
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------ѧ����Ϣ����------------------------------------\n"); 
	printf("------------------------------------�ܷ���ߺ����-----------------------------------\n"); 
	printf("ѧ��\t����\t\t��ѧ\tӢ��\t����\t�ܷ�\tƽ����\t����\n");

	printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",students[no[0]].ID,students[no[0]].name,students[no[0]].math,students[no[0]].english,students[no[0]].physical,students[no[0]].sum,students[no[0]].ave,0+1);
	printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",students[no[num-1]].ID,students[no[num-1]].name,students[no[num-1]].math,students[no[num-1]].english,students[no[num-1]].physical,students[no[num-1]].sum,students[no[num-1]].ave,num);

	
	printf("\n\n��0�˳���");
	scanf("%d",&a);
	if(a == 0){
		main();
	}
} 
 
 
 
 
//�ܷ����� 
void SortBySum(){
	system("cls");
	int mid;
	int a=1;
	int i;
	int j;
	//ð������ 
	for(i=0;i<num-1;i++){
		for(j=i+1;j<num;j++){
			if(students[no[i]].sum<students[no[j]].sum){
				mid = no[i];
				no[i] = no[j];
				no[j] = mid;
			}
		}
	}
	//չʾ���� 
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------ѧ����Ϣ����------------------------------------\n"); 
	printf("---------------------------------------�ܷ�����--------------------------------------\n"); 
	printf("ѧ��\t����\t\t��ѧ\tӢ��\t����\t�ܷ�\tƽ����\t����\n");
	for(i=0;i<num;i++){
		printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",students[no[i]].ID,students[no[i]].name,students[no[i]].math,students[no[i]].english,students[no[i]].physical,students[no[i]].sum,students[no[i]].ave,i+1);
	}
	
	printf("\n\n��0�˳���");
	scanf("%d",&a);
	if(a == 0){
		main();
	}
}
 

 
//no�����չʾ���� 
void SortByNo(){

	system("cls");
	int mid;
	int a=1;
	int i;
	int j;
	//ð������ 
	for(i=0;i<num-1;i++){
		for(j=i+1;j<num;j++){
			if(students[no[i]].No>students[no[j]].No){
				mid = no[i];
				no[i] = no[j];
				no[j] = mid;
			}
		}
	}
	//չʾ���� 
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------ѧ����Ϣ����------------------------------------\n"); 
	printf("---------------------------------------�������--------------------------------------\n"); 
	printf("ѧ��\t����\t\t��ѧ\tӢ��\t����\t�ܷ�\tƽ����\t����\n");
	for(i=0;i<num;i++){
		printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",students[no[i]].ID,students[no[i]].name,students[no[i]].math,students[no[i]].english,students[no[i]].physical,students[no[i]].sum,students[no[i]].ave,i+1);
	}
	
	printf("\n\n��0�˳���");
	scanf("%d",&a);
	if(a == 0){
		main();
	}
} 

//¼����Ϣ����
void inputRecords(){
	//���� 
	
	system("cls");
	
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------ѧ����Ϣ����------------------------------------\n"); 
	printf("---------------------------------------¼����Ϣ--------------------------------------\n"); 
	printf("������Ҫ¼���������"); 
	scanf("%d",&num);
	if(num>40){
		printf("��������,�������ء�����");
		sleep(1);
		inputRecords();
	} 
	int i=0;
	for(i=0;i<num;i++){
		printf("������ѧ��������\n");
		getchar();
		gets(students[i].name);
		printf("������ѧ������Ϣ������Ϊѧ�ţ���ѧ�ɼ���Ӣ��ɼ�������ɼ�����\n");
		scanf("%s%d%d%d",&students[i].ID,&students[i].math,&students[i].english,&students[i].physical);
		no[i] = i;
		students[i].No = atoi(students[i].ID);
		students[i].sum = students[i].math+students[i].english+students[i].physical;
		students[i].ave = students[i].sum/3;
	}
	printf("¼��ɹ�����������...");
	sleep(1);
	main();
} 

//������ 
int main(){
	system("cls");
	int input;
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------ѧ����Ϣ����------------------------------------\n"); 
	printf("-----------------------------------------����----------------------------------------\n"); 
	printf("1.Input records.\n"); 
	printf("2.Sort in ascending order by number and output records.\n"); 
	printf("3.Sort in descending order by total score and output records.\n"); 
	printf("4.Sort in ascending order by name and output records.\n"); 
	printf("5.Search by number and output the record.\n"); 
	printf("6.Search by name and output the record.\n"); 
	printf("7.Output the highest and lowest student records\n"); 
	printf("0.Exit.\n"); 
	printf("Please enter your choice:\n");
	
	scanf("%d",&input);
	//¼����Ϣ 
	if(input == 1){
		inputRecords();
	}
	
	//�����Ϣ˳��Ϊ��ѧ�š���������ѧ�ɼ���Ӣ��ɼ�������ɼ����ܷ֡�ƽ���֡�������
	// ������������в������¼
	if(input == 2){
		SortByNo(); 
	}
	// ���ֽܷ������в������¼
	if(input == 3){
		SortBySum();
	}
	
	// �������������������¼
	if(input == 4){
		SortByName();
	}
	
	// ����������������¼
	if(input == 5){
		SearchByNo();
	}
	// �����������������¼
	if(input == 6){
		SearchByName();
	}
	
	//����ܳɼ���ߺ����ѧ����¼ 
	if(input ==7){
		outputSum();
	}
	
	if(input ==0){
		return 0;
	}
		 
}
