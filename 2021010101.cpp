#include<iostream>
#include<fstream>
using namespace std; 




//增删改查数据 
class shuju{
	
	public:
	//增 
		virtual void add() = 0;
	//删
	    virtual void dele()= 0;
	//改
	    virtual void change() = 0; 
	//查 
	    virtual void search() = 0;
};


class student{
	
	public:
		void setname(string s){
			name = s;
		}
		string getname(){
			return name;
		}
		
		void setno(int n){
			no = n;
		}
		int getno(){
			return no;
		}
		
		void setmath(int n){
			math = n;
		}
		int getmath(){
			return math;
		}
		
		void setenglish(int n){
			english = n;
		}
		int getenglish(){
			return english;
		}
	
	
	
	private:
		string name;
		int    no;
		int    math;
		int    english;
	
};

class students: public shuju{
		
	public:
		student people[100];
		int num=0;
	//增 
		void add(){
			cout<<"请输入学生姓名"<<endl;
			string s;
			cin>>s;
			people[num].setname(s);
			int data; 
			cout<<"请输入学生学号"<<endl;
			cin>>data;
			people[num].setno(data);
			cout<<"请输入学生数学成绩"<<endl;
			cin>>data;
			people[num].setmath(data);
			cout<<"请输入学生英语成绩"<<endl;
			cin>>data;
			people[num].setenglish(data);
			num++;
			
			char is;
			cout<<"是否退出（y/n）："<<endl;
			cin>>is;
			if(is == 'y'){
				return;
			}
			else{
				add();
			}
		}
	//删
	    void dele(){
	    	int id;
	    	cout<<"请输入要删除的学生学号"<<endl; 
	    	cin>>id;
	    	for(int i = 0;i<num;i++){
	    		
	    		if(people[i].getno() == id&&i<(num-1)){
	    			for(int j = i;j<num-1;j++){
	    				people[j].setname(people[j+1].getname());
	    				people[j].setno(people[j+1].getno());
	    				people[j].setmath(people[j+1].getmath());
	    				people[j].setenglish(people[j+1].getenglish());
					}
					break;
				}
				if(people[i].getno() == id&&i==(num-1)){
					people[i].setno(0);
					people[i].setmath(0);
	    			people[i].setenglish(0);
	    			people[i].setname("0");
					break;
				}
			}
			num--;
	    	char is;
			cout<<"是否退出（y/n）："<<endl;
			cin>>is;
			if(is == 'y'){
				return;
			}
			else{
				dele();
			}
		}
	//改
		void change(){
	    	int id;
	    	cout<<"请输入要修改的学生学号"<<endl; 
	    	cin>>id;
	    	for(int i = 0;i<num;i++){
	    		if(people[i].getno() == id){
	    			cout<<"请输入修改后的学生姓名"<<endl;
					string s;
					cin>>s;
					people[i].setname(s);
					int data; 
					cout<<"请输入修改后的学生学号"<<endl;
					cin>>data;
					people[i].setno(data);
					cout<<"请输入修改后的学生数学成绩"<<endl;
					cin>>data;
					people[i].setmath(data);
					cout<<"请输入修改后的学生英语成绩"<<endl;
					cin>>data;
					people[i].setenglish(data);
					break; 
				}
			}
			char is;
			cout<<"是否退出（y/n）："<<endl;
			cin>>is;
			if(is == 'y'){
				return;
			}
			else{
				change();
			}
	    	
		}
	//查 
	    void search(){
	   		int id;
	    	cout<<"请输入要查询的学生学号"<<endl; 
	    	cin>>id;
	    	for(int i = 0;i<num;i++){
	    		if(people[i].getno() == id){
	    			cout<<"学号|姓名|数学成绩|英语成绩"<<endl;
	    			cout<<people[i].getno()<<"|"<<people[i].getname()<<"|"<<people[i].getmath()<<"|"<<people[i].getenglish()<<endl;
					break; 
				}
			}
			
			char is;
			cout<<"是否退出（y/n）："<<endl;
			cin>>is;
			if(is == 'y'){
				return;
			}
			else{
				search();
			}
	    	
	    	
	   } 
	   
	   void show(){
	   cout<<"学号|姓名|数学成绩|英语成绩"<<endl;
	   	for(int i = 0;i<num;i++){
	    		cout<<people[i].getno()<<"|"<<people[i].getname()<<"|"<<people[i].getmath()<<"|"<<people[i].getenglish()<<endl;
		}
		
		char is;
			cout<<"是否退出（y/n）："<<endl;
			cin>>is;
			if(is == 'y'){
				return;
			}
			else{
				show();
			}
	}
	    
	
}; 

students load(students l)//读取馆藏书本书目的函数
{
	int data;
	int i = 0;
	string s;
	ifstream infile; 
    infile.open("afile.dat"); 
	infile>>data;
	while(!infile.eof()){
		infile>>data;
		l.people[i].setno(data);
		infile>>s;
		l.people[i].setname(s);
		infile>>data;
		l.people[i].setmath(data);
		infile>>data;
		l.people[i].setenglish(data);
		i++;
	}
    l.num = i;
    infile.close();
    
    cout<<l.num<<endl;
    cout<<l.people[0].getno();
	return l;
}








//信息更新到文件 
void save(students l){
	ofstream outfile;
	outfile.open("afile.dat");
	
	for (int i = 0; i < l.num; i++) {
	    	
	    	outfile<<l.people[i].getno()<<endl;
	    	outfile<<l.people[i].getname()<<endl;
	    	outfile<<l.people[i].getmath()<<endl;
	    	outfile<<l.people[i].getenglish()<<endl;	
	}
	
	
	outfile.close();
}


int main(){
	students newstudent;
	int input; 
	while(1){
		system("cls");
		cout<<"学生信息管理系统"<<endl; 
		cout<<"请输入想进行的操作"<<endl; 
		cout<<"1 学生信息录入"<<endl; 
		cout<<"2 修改学生信息"<<endl; 
		cout<<"3 删除学生信息"<<endl; 
		cout<<"4 查询学生信息"<<endl; 
		cout<<"5 文件读取学生信息"<<endl; 
		cout<<"6 文件保存学生信息"<<endl; 
		cout<<"7 显示所有学生信息"<<endl; 
		cout<<"0 退出"<<endl;
		cin>>input;
		switch(input){
		//录入学生成绩
		case 1:
			newstudent.add();
			break;
		//修改学生信息 
		case 2:
			newstudent.change();
			break;
		//修改学生成绩
		case 3:
			newstudent.dele();
			break;
		case 4:
			newstudent.search();
			break;
		case 5:
			newstudent = load(newstudent);
			break;
		case 6:
			save(newstudent);
			break;
		case 7:
			newstudent.show();
			break;
		//退出	
		case 0:
			exit(0);
	}
	}
	
	return 0;
}

/*


基础要求
    1. 实现一个数据库类, 可以实现数据的增删改查功能
    2. 实现一个学生信息类, 包含有学生的学号, 姓名, 成绩等信息, 提供修改信息功能
    3. 实现一个学生信息管理类, 继承于数据库类, 数据为学生信息类
        1) 学生信息管理类可以存放大量学生信息(数组)
        2) 可以对学生的信息录入, 删除, 修改某个数据等

进阶要求 
    1. 存放数据使用容器存放
    2. 使用文件流来保存数据, 在程序运行时会读取文件中存放的数据
    3. 友好的终端交互界面




*/
