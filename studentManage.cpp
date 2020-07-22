#include<iostream>
#include<iomanip> 
#include<fstream>
#include<string.h>
using namespace std;


//学生每个人的信息 
struct student{
	//学号 
	string ID;
	string name;
	int math;
	int english;
	int computer;
	int sum;
	int ave;
}students[1000];
//录入的总人数 



//编号排序 
int no[1000];
//总人数 
int num =0;

//总分排名 
void SortBySum(){

	int mid;
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

	cout<<"总分排序"<<endl; 
	cout<<"学号|姓名|数学|英语|计算机|总分|平均分|排名"<<endl;
	for(i=0;i<num;i++){
	cout<<students[no[i]].ID<<"|"<<students[no[i]].name<<"|"<<students[no[i]].math<<"|"<<students[no[i]].english<<"|"<<students[no[i]].computer<<"|"<<students[no[i]].sum<<"|"<<students[no[i]].ave<<"|"<<i+1<<endl;
	}
	
}

//输出每门课最高分最低分 
void outputMaxMin(){
	int mid;


	cout<<"每门课最高分最低分"<<endl; 
	cout<<"课程|最高分|最低分"<<endl;
	//将数学成绩将进行排序 
	for(int i=0;i<num-1;i++){
		for(int j=i+1;j<num;j++){
			if(students[no[i]].math<students[no[j]].math){
				mid = no[i];
				no[i] = no[j];
				no[j] = mid;
			}
		}
	}
	cout<<"数学"<<"|"<<students[no[0]].math<<"|"<<students[no[num-1]].math<<endl;
	//将英语成绩进行排序 
	for(int i=0;i<num-1;i++){
		for(int j=i+1;j<num;j++){
			if(students[no[i]].english<students[no[j]].english){
				mid = no[i];
				no[i] = no[j];
				no[j] = mid;
			}
		}
	}
	cout<<"英语"<<"|"<<students[no[0]].english<<"|"<<students[no[num-1]].english<<endl;
	//将计算机成绩进行排序 
	for(int i=0;i<num-1;i++){
		for(int j=i+1;j<num;j++){
			if(students[no[i]].computer<students[no[j]].computer){
				mid = no[i];
				no[i] = no[j];
				no[j] = mid;
			}
		}
	}
	cout<<"计算机"<<"|"<<students[no[0]].computer<<"|"<<students[no[num-1]].computer<<endl;
	//总分排名
	SortBySum();

}



//输出每门课程平均分界面
void outputaves(){
	int sum[3]={0};

	cout<<"课程平均分"<<endl; 
	cout<<"课程|平均分"<<endl;
	for(int i=0;i<num;i++){
		sum[0]+=students[i].math;
		sum[1]+=students[i].english;
		sum[2]+=students[i].computer;
	}
	cout<<"数学"<<"|"<<sum[0]/num<<endl;
	cout<<"英语"<<"|"<<sum[1]/num<<endl;
	cout<<"计算机"<<"|"<<sum[2]/num<<endl;
	//输出每门课最高分最低分
	outputMaxMin(); 
}





//输出平均分
void outputStudentAves(){


 
	cout<<"学生平均分"<<endl; 
	cout<<"学号|姓名|平均分"<<endl;
	for(int i=0;i<num;i++){
	cout<<students[i].ID<<"|"<<students[i].name<<"|"<<students[i].ave<<endl;
	}

//输出每门课程平均分界面
	outputaves();
}





//输出信息
void outputRecords(){

	//展示界面 

	cout<<"输出信息"<<endl; 
	cout<<"学号|姓名|数学|英语|计算机"<<endl;
	for(int i=0;i<num;i++){
	cout<<students[i].ID<<"|"<<students[i].name<<"|"<<students[i].math<<"|"<<students[i].english<<"|"<<students[i].computer<<endl;
	}
	//调用输出平均分
	outputStudentAves();

}
 

 
//录入信息
void inputRecords(){
	int i=0;
	char a;
	string read;
	fstream  myfile("d:/grade.txt");
	
	while(getline(myfile,read)){
		students[i].ID = read;//读入id
		getline(myfile,read);
		students[i].name = read;//读入name
		getline(myfile,read);
		students[i].math = stoi(read);//读入math
		getline(myfile,read);
		students[i].english = stoi(read);//读入english
		getline(myfile,read);
		students[i].computer = stoi(read);//读入computer
		students[i].sum = students[i].math+students[i].english+students[i].computer;//总分计算 
		students[i].ave = students[i].sum/3;//平均分 
		no[i] = i;
		i++;
		num++;
	}
	//调用输出信息 
	outputRecords();

} 

//主界面 
int main(){
	
	//录入信息 
	inputRecords();
	
	return 0;

		 
}
