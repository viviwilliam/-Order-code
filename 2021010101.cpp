#include<iostream>
#include<fstream>
using namespace std; 




//��ɾ�Ĳ����� 
class shuju{
	
	public:
	//�� 
		virtual void add() = 0;
	//ɾ
	    virtual void dele()= 0;
	//��
	    virtual void change() = 0; 
	//�� 
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
	//�� 
		void add(){
			cout<<"������ѧ������"<<endl;
			string s;
			cin>>s;
			people[num].setname(s);
			int data; 
			cout<<"������ѧ��ѧ��"<<endl;
			cin>>data;
			people[num].setno(data);
			cout<<"������ѧ����ѧ�ɼ�"<<endl;
			cin>>data;
			people[num].setmath(data);
			cout<<"������ѧ��Ӣ��ɼ�"<<endl;
			cin>>data;
			people[num].setenglish(data);
			num++;
			
			char is;
			cout<<"�Ƿ��˳���y/n����"<<endl;
			cin>>is;
			if(is == 'y'){
				return;
			}
			else{
				add();
			}
		}
	//ɾ
	    void dele(){
	    	int id;
	    	cout<<"������Ҫɾ����ѧ��ѧ��"<<endl; 
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
			cout<<"�Ƿ��˳���y/n����"<<endl;
			cin>>is;
			if(is == 'y'){
				return;
			}
			else{
				dele();
			}
		}
	//��
		void change(){
	    	int id;
	    	cout<<"������Ҫ�޸ĵ�ѧ��ѧ��"<<endl; 
	    	cin>>id;
	    	for(int i = 0;i<num;i++){
	    		if(people[i].getno() == id){
	    			cout<<"�������޸ĺ��ѧ������"<<endl;
					string s;
					cin>>s;
					people[i].setname(s);
					int data; 
					cout<<"�������޸ĺ��ѧ��ѧ��"<<endl;
					cin>>data;
					people[i].setno(data);
					cout<<"�������޸ĺ��ѧ����ѧ�ɼ�"<<endl;
					cin>>data;
					people[i].setmath(data);
					cout<<"�������޸ĺ��ѧ��Ӣ��ɼ�"<<endl;
					cin>>data;
					people[i].setenglish(data);
					break; 
				}
			}
			char is;
			cout<<"�Ƿ��˳���y/n����"<<endl;
			cin>>is;
			if(is == 'y'){
				return;
			}
			else{
				change();
			}
	    	
		}
	//�� 
	    void search(){
	   		int id;
	    	cout<<"������Ҫ��ѯ��ѧ��ѧ��"<<endl; 
	    	cin>>id;
	    	for(int i = 0;i<num;i++){
	    		if(people[i].getno() == id){
	    			cout<<"ѧ��|����|��ѧ�ɼ�|Ӣ��ɼ�"<<endl;
	    			cout<<people[i].getno()<<"|"<<people[i].getname()<<"|"<<people[i].getmath()<<"|"<<people[i].getenglish()<<endl;
					break; 
				}
			}
			
			char is;
			cout<<"�Ƿ��˳���y/n����"<<endl;
			cin>>is;
			if(is == 'y'){
				return;
			}
			else{
				search();
			}
	    	
	    	
	   } 
	   
	   void show(){
	   cout<<"ѧ��|����|��ѧ�ɼ�|Ӣ��ɼ�"<<endl;
	   	for(int i = 0;i<num;i++){
	    		cout<<people[i].getno()<<"|"<<people[i].getname()<<"|"<<people[i].getmath()<<"|"<<people[i].getenglish()<<endl;
		}
		
		char is;
			cout<<"�Ƿ��˳���y/n����"<<endl;
			cin>>is;
			if(is == 'y'){
				return;
			}
			else{
				show();
			}
	}
	    
	
}; 

students load(students l)//��ȡ�ݲ��鱾��Ŀ�ĺ���
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








//��Ϣ���µ��ļ� 
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
		cout<<"ѧ����Ϣ����ϵͳ"<<endl; 
		cout<<"����������еĲ���"<<endl; 
		cout<<"1 ѧ����Ϣ¼��"<<endl; 
		cout<<"2 �޸�ѧ����Ϣ"<<endl; 
		cout<<"3 ɾ��ѧ����Ϣ"<<endl; 
		cout<<"4 ��ѯѧ����Ϣ"<<endl; 
		cout<<"5 �ļ���ȡѧ����Ϣ"<<endl; 
		cout<<"6 �ļ�����ѧ����Ϣ"<<endl; 
		cout<<"7 ��ʾ����ѧ����Ϣ"<<endl; 
		cout<<"0 �˳�"<<endl;
		cin>>input;
		switch(input){
		//¼��ѧ���ɼ�
		case 1:
			newstudent.add();
			break;
		//�޸�ѧ����Ϣ 
		case 2:
			newstudent.change();
			break;
		//�޸�ѧ���ɼ�
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
		//�˳�	
		case 0:
			exit(0);
	}
	}
	
	return 0;
}

/*


����Ҫ��
    1. ʵ��һ�����ݿ���, ����ʵ�����ݵ���ɾ�Ĳ鹦��
    2. ʵ��һ��ѧ����Ϣ��, ������ѧ����ѧ��, ����, �ɼ�����Ϣ, �ṩ�޸���Ϣ����
    3. ʵ��һ��ѧ����Ϣ������, �̳������ݿ���, ����Ϊѧ����Ϣ��
        1) ѧ����Ϣ��������Դ�Ŵ���ѧ����Ϣ(����)
        2) ���Զ�ѧ������Ϣ¼��, ɾ��, �޸�ĳ�����ݵ�

����Ҫ�� 
    1. �������ʹ���������
    2. ʹ���ļ�������������, �ڳ�������ʱ���ȡ�ļ��д�ŵ�����
    3. �Ѻõ��ն˽�������




*/
