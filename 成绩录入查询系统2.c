#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
//人数 
int num;
//名次 
int PaiMing[40];

//学生信息 
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

		printf("请输入学生姓名：\n");
		getchar();
		gets(students[i].name);
		printf("请输入学生的学号：\n");
		scanf("%s",&students[i].num);
		printf("请输入学生的数学成绩：\n");
		scanf("%d",&students[i].MT);
		printf("请输入学生的英语成绩：\n");
		scanf("%d",&students[i].EN);
		printf("请输入学生的物理成绩：\n");
		scanf("%d",&students[i].PH);
		PaiMing[i] = i;
		i++; 
		num++;
		printf("录入成功！是否继续(y/n)：\n");
		
		getchar();
		scanf("%c",&isorno);
		if(i==40){
			printf("即将超出上限，不再继续！");
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
	//排序 
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
	
	printf("学号|姓名|数学|英语|物理|总分|平均分|排名\n");
	for(i=0;i<num;i++){
		printf("%s|%s|%d|%d|%d|%lf|%lf|%d\n",students[PaiMing[i]].num,students[PaiMing[i]].name,students[PaiMing[i]].MT,
		students[PaiMing[i]].EN,students[PaiMing[i]].PH,students[PaiMing[i]].Zong,students[PaiMing[i]].Ping,i+1);
	}
	
	printf("\n是否退出（y/n）：");
	getchar();
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		ZongSort();
	}
} 

//输出总分最高和最低
void grade(){
	int a,b,c; 
	char is;
	int i;

	ZongPaixu();
	printf("最高：\n");
	printf("学号|姓名|数学|英语|物理|总分|平均分|排名\n");
	
		printf("%s|%s|%d|%d|%d|%lf|%lf|1\n",students[PaiMing[0]].num,students[PaiMing[0]].name,students[PaiMing[0]].MT,
		students[PaiMing[0]].EN,students[PaiMing[0]].PH,students[PaiMing[0]].Zong,students[PaiMing[0]].Ping);
	printf("最低：\n");
	printf("学号|姓名|数学|英语|物理|总分|平均分|排名\n");
		printf("%s|%s|%d|%d|%d|%lf|%lf|%d\n",students[PaiMing[num-1]].num,students[PaiMing[num-1]].name,students[PaiMing[num-1]].MT,
		students[PaiMing[0]].EN,students[PaiMing[num-1]].PH,students[PaiMing[num-1]].Zong,students[PaiMing[num-1]].Ping,num);
	
	printf("\n是否退出（y/n）：");
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
	
	
	//排序 
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

	printf("学号|姓名|数学|英语|物理|总分|平均分|排名\n");
	for(i=0;i<num;i++){
		printf("%s|%s|%d|%d|%d|%lf|%lf|%d\n",students[PaiMing[i]].num,students[PaiMing[i]].name,students[PaiMing[i]].MT,
		students[PaiMing[i]].EN,students[PaiMing[i]].PH,students[PaiMing[i]].Zong,students[PaiMing[i]].Ping,i+1);
	}
	
	printf("\n是否退出（y/n）：");
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
	
	//排序 
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

	printf("学号|姓名|数学|英语|物理|总分|平均分|排名\n");
	for(i=0;i<num;i++){
		printf("%s|%s|%d|%d|%d|%lf|%lf|%d\n",students[PaiMing[i]].num,students[PaiMing[i]].name,students[PaiMing[i]].MT,
		students[PaiMing[i]].EN,students[PaiMing[i]].PH,students[PaiMing[i]].Zong,students[PaiMing[i]].Ping,i+1);
	}
	
	printf("\n是否退出（y/n）：");
	getchar();
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		NameSort();	
	}
} 

//编号查询 
void NumSearch(){
	char chaxun[20];
	char is;
	int i;
	int j;
	printf("输入要查询的编号："); 
	scanf("%s",&chaxun);
	
	for(i=0;i<num;i++){
		if(strcmp(chaxun, students[i].num)==0){
		printf("学号|姓名|数学|英语|物理|总分|平均分\n");
		printf("%s|%s|%d|%d|%d|%lf|%lf\n",students[i].num,students[i].name,students[i].MT,
		students[i].EN,students[i].PH,students[i].Zong,students[i].Ping);			
		break;
		}
	}
	
	printf("\n是否退出（y/n）：");
	getchar();
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		NumSearch();
	}
} 

//名字查询 
void NameSearch(){
	char chaxun[20];
	char is;
	int i;
	int j;
	printf("输入要查询的名字：\n"); 
	getchar();
	gets(chaxun);
	
	for(i=0;i<num;i++){
		if(strcmp(chaxun, students[i].name)==0){
		printf("学号|姓名|数学|英语|物理|总分|平均分\n");
		printf("%s|%s|%d|%d|%d|%lf|%lf\n",students[i].num,students[i].name,students[i].MT,
		students[i].EN,students[i].PH,students[i].Zong,students[i].Ping);			
		break;
		}
	}
	
	printf("\n是否退出（y/n）:");
	getchar();
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		NameSearch();
	}
} 

 
//主界面 
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
		//输入学生信息
		case 1:
			input();
			break;
		//编号升序
		case 2:
			NumSort();
			break;
		//总分排序 
		case 3:
			ZongSort();
			break;
		//姓名排名
		case 4:
			NameSort();
			break;
		//编号查询 
		case 5:
			NumSearch();
			break;
		//名字查询 
		case 6:
			NameSearch();
			break;
		//最高最低成绩 
		case 7:
			grade();
			break;
		//退出	
		case 0:
			return;
	}
	}	 
}
