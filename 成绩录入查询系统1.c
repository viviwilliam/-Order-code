#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>

//学生每个人的信息 
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
//录入的总人数 



//编号排序 
int no[1000];
int num;

//通过姓名进行搜索
void SearchByName(){
	system("cls");
	char serch[30];
	int a=1;
	int i;
	int j;
	//展示界面 
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------学生信息管理------------------------------------\n"); 
	printf("--------------------------------------按姓名搜索-------------------------------------\n"); 
	printf("输入要搜索的姓名：\n");
	getchar();
	scanf("%s",&serch);
	
	for(i=0;i<num;i++){
		if(strcmp(serch, students[i].name)){
		printf("学号\t姓名\t\t数学\t英语\t物理\t总分\t平均分\n");
		printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",students[i].ID,students[i].name,students[i].math,students[i].english,students[i].physical,students[i].sum,students[i].ave);
			break;
		}
	}
	
	printf("\n\n是否继续（1/0）：");
	scanf("%d",&a);
	if(a == 0){
		main();
	}
	if(a == 1){
		SearchByName();
	}
} 



//通过编号进行搜索
void SearchByNo(){
	system("cls");
	int serch;
	int a=1;
	int i;
	int j;
	//展示界面 
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------学生信息管理------------------------------------\n"); 
	printf("--------------------------------------按编号搜索-------------------------------------\n"); 
	printf("输入要搜索的编号："); 
	scanf("%d",&serch);
	
	for(i=0;i<num;i++){
		if(students[i].No==serch){
		printf("学号\t姓名\t\t数学\t英语\t物理\t总分\t平均分\n");
		printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",students[i].ID,students[i].name,students[i].math,students[i].english,students[i].physical,students[i].sum,students[i].ave);
			break;
		}
	}
	
	printf("\n\n是否继续（1/0）：");
	scanf("%d",&a);
	if(a == 0){
		main();
	}
	if(a == 1){
		SearchByNo();
	}
} 



//名字升序 
void SortByName(){
	system("cls");
	int mid;
	int a=1;
	int i;
	int j;
	//冒泡排序 
	for(i=0;i<num-1;i++){
		for(j=i+1;j<num;j++){
			if(students[no[i]].name[0]>students[no[j]].name[0]){
				mid = no[i];
				no[i] = no[j];
				no[j] = mid;
			}
		}
	}
	//展示界面 
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------学生信息管理------------------------------------\n"); 
	printf("---------------------------------------姓名排序--------------------------------------\n"); 
	printf("学号\t姓名\t\t数学\t英语\t物理\t总分\t平均分\t排名\n");
	for(i=0;i<num;i++){
		printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",students[no[i]].ID,students[no[i]].name,students[no[i]].math,students[no[i]].english,students[no[i]].physical,students[no[i]].sum,students[no[i]].ave,i+1);
	}
	
	printf("\n\n按0退出：");
	scanf("%d",&a);
	if(a == 0){
		main();
	}
}
 
 
 //输出总分最高和最低二人 
void outputSum(){
	system("cls");
	int mid;
	int a=1;
	int i;
	int j;
	//冒泡排序 
	for(i=0;i<num-1;i++){
		for(j=i+1;j<num;j++){
			if(students[no[i]].sum<students[no[j]].sum){
				mid = no[i];
				no[i] = no[j];
				no[j] = mid;
			}
		}
	}
	//展示界面 
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------学生信息管理------------------------------------\n"); 
	printf("------------------------------------总分最高和最低-----------------------------------\n"); 
	printf("学号\t姓名\t\t数学\t英语\t物理\t总分\t平均分\t排名\n");

	printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",students[no[0]].ID,students[no[0]].name,students[no[0]].math,students[no[0]].english,students[no[0]].physical,students[no[0]].sum,students[no[0]].ave,0+1);
	printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",students[no[num-1]].ID,students[no[num-1]].name,students[no[num-1]].math,students[no[num-1]].english,students[no[num-1]].physical,students[no[num-1]].sum,students[no[num-1]].ave,num);

	
	printf("\n\n按0退出：");
	scanf("%d",&a);
	if(a == 0){
		main();
	}
} 
 
 
 
 
//总分排名 
void SortBySum(){
	system("cls");
	int mid;
	int a=1;
	int i;
	int j;
	//冒泡排序 
	for(i=0;i<num-1;i++){
		for(j=i+1;j<num;j++){
			if(students[no[i]].sum<students[no[j]].sum){
				mid = no[i];
				no[i] = no[j];
				no[j] = mid;
			}
		}
	}
	//展示界面 
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------学生信息管理------------------------------------\n"); 
	printf("---------------------------------------总分排序--------------------------------------\n"); 
	printf("学号\t姓名\t\t数学\t英语\t物理\t总分\t平均分\t排名\n");
	for(i=0;i<num;i++){
		printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",students[no[i]].ID,students[no[i]].name,students[no[i]].math,students[no[i]].english,students[no[i]].physical,students[no[i]].sum,students[no[i]].ave,i+1);
	}
	
	printf("\n\n按0退出：");
	scanf("%d",&a);
	if(a == 0){
		main();
	}
}
 

 
//no排序的展示界面 
void SortByNo(){

	system("cls");
	int mid;
	int a=1;
	int i;
	int j;
	//冒泡排序 
	for(i=0;i<num-1;i++){
		for(j=i+1;j<num;j++){
			if(students[no[i]].No>students[no[j]].No){
				mid = no[i];
				no[i] = no[j];
				no[j] = mid;
			}
		}
	}
	//展示界面 
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------学生信息管理------------------------------------\n"); 
	printf("---------------------------------------编号排序--------------------------------------\n"); 
	printf("学号\t姓名\t\t数学\t英语\t物理\t总分\t平均分\t排名\n");
	for(i=0;i<num;i++){
		printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",students[no[i]].ID,students[no[i]].name,students[no[i]].math,students[no[i]].english,students[no[i]].physical,students[no[i]].sum,students[no[i]].ave,i+1);
	}
	
	printf("\n\n按0退出：");
	scanf("%d",&a);
	if(a == 0){
		main();
	}
} 

//录入信息界面
void inputRecords(){
	//清屏 
	
	system("cls");
	
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------学生信息管理------------------------------------\n"); 
	printf("---------------------------------------录入信息--------------------------------------\n"); 
	printf("请输入要录入的人数："); 
	scanf("%d",&num);
	if(num>40){
		printf("超出上限,即将返回。。。");
		sleep(1);
		inputRecords();
	} 
	int i=0;
	for(i=0;i<num;i++){
		printf("请输入学生姓名：\n");
		getchar();
		gets(students[i].name);
		printf("请输入学生的信息（依次为学号，数学成绩，英语成绩，物理成绩）：\n");
		scanf("%s%d%d%d",&students[i].ID,&students[i].math,&students[i].english,&students[i].physical);
		no[i] = i;
		students[i].No = atoi(students[i].ID);
		students[i].sum = students[i].math+students[i].english+students[i].physical;
		students[i].ave = students[i].sum/3;
	}
	printf("录入成功！即将返回...");
	sleep(1);
	main();
} 

//主界面 
int main(){
	system("cls");
	int input;
	printf("-------------------------------------------------------------------------------------\n"); 
	printf("-------------------------------------学生信息管理------------------------------------\n"); 
	printf("-----------------------------------------功能----------------------------------------\n"); 
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
	//录入信息 
	if(input == 1){
		inputRecords();
	}
	
	//输出信息顺序为：学号、姓名、数学成绩、英语成绩、物理成绩、总分、平均分、排名。
	// 按编号升序排列并输出记录
	if(input == 2){
		SortByNo(); 
	}
	// 按总分降序排列并输出记录
	if(input == 3){
		SortBySum();
	}
	
	// 按姓名升序排序并输出记录
	if(input == 4){
		SortByName();
	}
	
	// 按编号搜索并输出记录
	if(input == 5){
		SearchByNo();
	}
	// 按姓名搜索并输出记录
	if(input == 6){
		SearchByName();
	}
	
	//输出总成绩最高和最低学生记录 
	if(input ==7){
		outputSum();
	}
	
	if(input ==0){
		return 0;
	}
		 
}
