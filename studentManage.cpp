#include<iostream>
#include<iomanip> 
#include<fstream>
#include<string.h>
using namespace std;


//ѧ��ÿ���˵���Ϣ 
struct student{
	//ѧ�� 
	string ID;
	string name;
	int math;
	int english;
	int computer;
	int sum;
	int ave;
}students[1000];
//¼��������� 



//������� 
int no[1000];
//������ 
int num =0;

//�ܷ����� 
void SortBySum(){

	int mid;
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

	cout<<"�ܷ�����"<<endl; 
	cout<<"ѧ��|����|��ѧ|Ӣ��|�����|�ܷ�|ƽ����|����"<<endl;
	for(i=0;i<num;i++){
	cout<<students[no[i]].ID<<"|"<<students[no[i]].name<<"|"<<students[no[i]].math<<"|"<<students[no[i]].english<<"|"<<students[no[i]].computer<<"|"<<students[no[i]].sum<<"|"<<students[no[i]].ave<<"|"<<i+1<<endl;
	}
	
}

//���ÿ�ſ���߷���ͷ� 
void outputMaxMin(){
	int mid;


	cout<<"ÿ�ſ���߷���ͷ�"<<endl; 
	cout<<"�γ�|��߷�|��ͷ�"<<endl;
	//����ѧ�ɼ����������� 
	for(int i=0;i<num-1;i++){
		for(int j=i+1;j<num;j++){
			if(students[no[i]].math<students[no[j]].math){
				mid = no[i];
				no[i] = no[j];
				no[j] = mid;
			}
		}
	}
	cout<<"��ѧ"<<"|"<<students[no[0]].math<<"|"<<students[no[num-1]].math<<endl;
	//��Ӣ��ɼ��������� 
	for(int i=0;i<num-1;i++){
		for(int j=i+1;j<num;j++){
			if(students[no[i]].english<students[no[j]].english){
				mid = no[i];
				no[i] = no[j];
				no[j] = mid;
			}
		}
	}
	cout<<"Ӣ��"<<"|"<<students[no[0]].english<<"|"<<students[no[num-1]].english<<endl;
	//��������ɼ��������� 
	for(int i=0;i<num-1;i++){
		for(int j=i+1;j<num;j++){
			if(students[no[i]].computer<students[no[j]].computer){
				mid = no[i];
				no[i] = no[j];
				no[j] = mid;
			}
		}
	}
	cout<<"�����"<<"|"<<students[no[0]].computer<<"|"<<students[no[num-1]].computer<<endl;
	//�ܷ�����
	SortBySum();

}



//���ÿ�ſγ�ƽ���ֽ���
void outputaves(){
	int sum[3]={0};

	cout<<"�γ�ƽ����"<<endl; 
	cout<<"�γ�|ƽ����"<<endl;
	for(int i=0;i<num;i++){
		sum[0]+=students[i].math;
		sum[1]+=students[i].english;
		sum[2]+=students[i].computer;
	}
	cout<<"��ѧ"<<"|"<<sum[0]/num<<endl;
	cout<<"Ӣ��"<<"|"<<sum[1]/num<<endl;
	cout<<"�����"<<"|"<<sum[2]/num<<endl;
	//���ÿ�ſ���߷���ͷ�
	outputMaxMin(); 
}





//���ƽ����
void outputStudentAves(){


 
	cout<<"ѧ��ƽ����"<<endl; 
	cout<<"ѧ��|����|ƽ����"<<endl;
	for(int i=0;i<num;i++){
	cout<<students[i].ID<<"|"<<students[i].name<<"|"<<students[i].ave<<endl;
	}

//���ÿ�ſγ�ƽ���ֽ���
	outputaves();
}





//�����Ϣ
void outputRecords(){

	//չʾ���� 

	cout<<"�����Ϣ"<<endl; 
	cout<<"ѧ��|����|��ѧ|Ӣ��|�����"<<endl;
	for(int i=0;i<num;i++){
	cout<<students[i].ID<<"|"<<students[i].name<<"|"<<students[i].math<<"|"<<students[i].english<<"|"<<students[i].computer<<endl;
	}
	//�������ƽ����
	outputStudentAves();

}
 

 
//¼����Ϣ
void inputRecords(){
	int i=0;
	char a;
	string read;
	fstream  myfile("d:/grade.txt");
	
	while(getline(myfile,read)){
		students[i].ID = read;//����id
		getline(myfile,read);
		students[i].name = read;//����name
		getline(myfile,read);
		students[i].math = stoi(read);//����math
		getline(myfile,read);
		students[i].english = stoi(read);//����english
		getline(myfile,read);
		students[i].computer = stoi(read);//����computer
		students[i].sum = students[i].math+students[i].english+students[i].computer;//�ּܷ��� 
		students[i].ave = students[i].sum/3;//ƽ���� 
		no[i] = i;
		i++;
		num++;
	}
	//���������Ϣ 
	outputRecords();

} 

//������ 
int main(){
	
	//¼����Ϣ 
	inputRecords();
	
	return 0;

		 
}
