#include<stdio.h>
struct staff
{
	int num;        //��� 
	char name[20];      //����
	int year;           //��У��� 
	char pos[50];          //��У��� 
	char position[50];       //�о����� 
	char gx[3][50];       //��Ҫ�ɾ� 
}stf[50];

int showID[50];

int sum = 0;

void Delete(){
	int id;
	int i;
	printf("��������Ҫɾ����У�����\n");
	scanf("%d",&id);
	for(i=0;i<sum-1;i++){
		if(id==stf[i].num){
			int j;
	      for(j=i;j<sum-1;j++){
	      	stf[j].year = stf[j+1].year; 
	      	int m;
	      	for(m =0;m<20;m++)
	      	stf[j].name[m] = stf[j+1].name[m]; 
	      	for(m =0;m<50;m++)
	      	stf[j].position[i] = stf[j+1].position[i]; 
	      	for(m =0;m<50;m++)
	      	stf[j].pos[m] = stf[j+1].pos[m];
			for(m =0;m<50;m++)
	      	stf[j].gx[0][m] = stf[j+1].gx[0][m];
	      	for(m =0;m<50;m++)
	      	stf[j].gx[1][m] = stf[j+1].gx[1][m];
	      	for(m =0;m<50;m++)
	      	stf[j].gx[2][m] = stf[j+1].gx[2][m];
		  }
		break;
		}
		
	}
	sum--;
	printf("ɾ���ɹ���\n");
	getchar();
	char is;
	printf("�Ƿ��˳���y/n����\n");
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		Delete();
	}
	
}

void searchByName(){
	char id[20];
	int i;
	printf("��������Ҫ���ҵ�У������\n");
	scanf("%s",id);
	for(i=0;i<sum;i++){
		if(strcmp(stf[i].name,id)==0){
		printf("���|����|��У���|��У���|�о�����|��Ҫ�ɾ�1|��Ҫ�ɾ�2|��Ҫ�ɾ�3\n");
		printf("%d|%s|%d|%s|%s|%s|%s|%s\n",stf[i].num,stf[i].name,stf[i].year,stf[i].pos,stf[i].position,stf[i].gx[0],stf[i].gx[1],stf[i].gx[2]);
		break;
		}
		
	}
	if(i==sum){
		printf("�޴�У��\n");
	}
	getchar();
	char is;
	printf("�Ƿ��˳���y/n����\n");
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		searchByName();
	}
} 




void searchById(){
	int id;
	int i;
	printf("��������Ҫ���ҵ�У�����\n");
	scanf("%d",&id);
	for(i=0;i<sum;i++){
		if(stf[i].num==id){
			printf("���|����|��У���|��У���|�о�����|��Ҫ�ɾ�1|��Ҫ�ɾ�2|��Ҫ�ɾ�3\n");
			printf("%d|%s|%d|%s|%s|%s|%s|%s\n",stf[i].num,stf[i].name,stf[i].year,stf[i].pos,stf[i].position,stf[i].gx[0],stf[i].gx[1],stf[i].gx[2]);
		break;
		}
		
	}
	if(i==sum){
		printf("�޴�У��\n");
	}
	getchar();
	char is;
	printf("�Ƿ��˳���y/n����\n");
	scanf("%c",&is);
	if(is == 'y'){
		return;
	}
	else{
		searchById();
	}
} 


void paixu(){
	int i;
	for(i = 0;i<sum;i++){
		showID[i]=i;
	}
	int a,j;
	for( i = 0;i<sum-1;i++){
		for(j=i+1;j<sum;j++){
			if(stf[i].num>stf[j].num){
				a = showID[i];
				showID[i] = showID[j];
				showID[j] = a;
			}
		}
	}
} 


 
void show(){
	int i;
	paixu();
	printf("���|����|��У���|��У���|�о�����|��Ҫ�ɾ�1|��Ҫ�ɾ�2|��Ҫ�ɾ�3\n");
	for(i=0;i<sum;i++){
		
		printf("%d|%s|%d|%s|%s|%s|%s|%s\n",stf[showID[i]].num,stf[showID[i]].name,stf[showID[i]].year,stf[showID[i]].pos,stf[showID[i]].position,stf[showID[i]].gx[0],stf[showID[i]].gx[1],stf[showID[i]].gx[2]);
	}
	getchar();
	char is;
	printf("�Ƿ��˳���y/n����\n");
	scanf("%c",&is);
	if(is == 'n'){
		show();
	}
	else{
		return;
	}
} 


//��ѯ
void check(){
	char a, b, c, d, Choice;
		
	while(1){
	system("cls");
	printf("��ѡ����\n");
	printf("a.������Ų��ҡ�\n");
	printf("b.�����������ҡ�\n");
	printf("c.��ʾУ�����ݣ����������\n");
	printf("d.�˳���\n");
	scanf("%c", &Choice);

	if (Choice == 'a')
	{
		searchById();
	}
	else if (Choice == 'b')
	{
		searchByName();
	}
	else if (Choice == 'c')
	{
		show();
	}
	else if (Choice == 'd')
	{
		break;
	}
	
}
} 
	

//�ļ��洢
void writeArray()
{
    FILE *fd;  // filename ���ļ�������
    int i;
    int a;
    if((fd=fopen("schoolData.txt","w+"))==NULL){
        perror("fopen");
        exit(1);
    }
    for (i=0;i<sum;i++){
        fprintf(fd,"%d %s %d %s %s %s %s %s\n",stf[i].num,stf[i].name,stf[i].year,stf[i].pos,stf[i].position,stf[i].gx[0],stf[i].gx[1],stf[i].gx[2]);
    }
    fclose(fd);
}



//�޸�
void change(){
	int id;
	int i;
	printf("��������Ҫ�޸ĵ�У�����\n");
	scanf("%d",&id);
	for(i=0;i<sum;i++){
		if(stf[i].num==id){
		printf("��������ţ�\n");
		scanf("%d",&stf[i].num);
		printf("������������\n");
		scanf("%s",stf[i].name);
		getchar();
		printf("��������У��ݣ�\n");
		scanf("%d",&stf[i].year);
		printf("��������У��ݣ�\n");
		scanf("%s",&stf[i].pos);
		getchar();
		printf("�������о�����\n");
		scanf("%s",stf[i].position);
		getchar();
		
		int j;
		for(j=0;j<3;j++) {
			printf("�������%d��Ҫ�ɾͣ�\n",j+1);
			scanf("%s",&stf[i].gx[j]);
			getchar();
		}
		printf("�޸ĳɹ�\n");
		break;
		}
		
	}

	char is;
	getchar();
	printf("�Ƿ��˳���y/n����\n");
	scanf("%c",&is);
	if(is == 'n'){
		change();
	}
	else{
		return;
	}
}








//���� 
void input(){
	printf("��������ţ�\n");
	scanf("%d",&stf[sum].num);
	printf("������������\n");
	scanf("%s",stf[sum].name);
	getchar();
	printf("��������У��ݣ�\n");
	scanf("%d",&stf[sum].year);
	printf("��������У��ݣ�\n");
	scanf("%s",&stf[sum].pos);
	getchar();
	printf("�������о�����\n");
	scanf("%s",stf[sum].position);
	getchar();
	
	int i;
	for(i=0;i<3;i++) {
		printf("�������%d��Ҫ�ɾͣ�\n",i+1);
		scanf("%s",&stf[sum].gx[i]);
		getchar();
	}
	
	sum++;
	char is;
	printf("�Ƿ��˳���y/n����\n");
	getchar();
	scanf("%c",&is);
	if(is == 'n'){
		input();
	}
	else{
		return;
	}
	
}
//��ȡ���� 
void readArray()
{
    FILE *fd;  // filename ���ļ�������
    int i=0;
   
    if((fd=fopen("schoolData.txt","r+"))==NULL){
        perror("fopen");
        exit(1);
    }
    while(fscanf(fd,"%d %s %d %s %s %s %s %s", &stf[i].num,stf[i].name,&stf[i].year,stf[i].pos,stf[i].position,stf[i].gx[0],stf[i].gx[1],stf[i].gx[2])!=EOF){
        i++;
    }
    sum = i;
    fclose(fd);

}







int main()
{
	char a, b, c, d, Choice;
	while(1){
	system("cls");
	printf("У��¼����ϵͳ\n");
	printf("��ѡ����\n");
	printf("a.���У����Ϣ��\n");
	printf("b.�޸�У�����ݡ�\n");
	printf("c.����У�ѡ�\n");
	printf("d.ɾ��У�����ݡ�\n");
	printf("f.�����������ļ���\n");
	printf("g.��ȡ�ļ����ݡ�\n");
	
	scanf("%c", &Choice);

	if (Choice == 'a')
	{
		input();
	}
	else if (Choice == 'b')
	{
		change();
	}
	else if (Choice == 'c')
	{
		check();
	}
	else if (Choice == 'd')
	{
		Delete();
	}
	else if (Choice == 'e')
	{
		Delete();
	}
	else if (Choice == 'f')
	{
		writeArray();
	}
	else if (Choice == 'g')
	{
		readArray();
	}
	
	}
	
	return 0;
}
