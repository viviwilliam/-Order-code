#include<stdio.h>
struct staff
{
	int num;        //序号 
	char name[20];      //姓名
	int year;           //入校年份 
	char pos[50];          //在校身份 
	char position[50];       //研究领域 
	char gx[3][50];       //主要成就 
}stf[50];

int showID[50];

int sum = 0;

void Delete(){
	int id;
	int i;
	printf("请输入你要删除的校友序号\n");
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
	printf("删除成功！\n");
	getchar();
	char is;
	printf("是否退出（y/n）：\n");
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
	printf("请输入你要查找的校友姓名\n");
	scanf("%s",id);
	for(i=0;i<sum;i++){
		if(strcmp(stf[i].name,id)==0){
		printf("序号|姓名|入校年份|在校身份|研究领域|主要成就1|主要成就2|主要成就3\n");
		printf("%d|%s|%d|%s|%s|%s|%s|%s\n",stf[i].num,stf[i].name,stf[i].year,stf[i].pos,stf[i].position,stf[i].gx[0],stf[i].gx[1],stf[i].gx[2]);
		break;
		}
		
	}
	if(i==sum){
		printf("无此校友\n");
	}
	getchar();
	char is;
	printf("是否退出（y/n）：\n");
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
	printf("请输入你要查找的校友序号\n");
	scanf("%d",&id);
	for(i=0;i<sum;i++){
		if(stf[i].num==id){
			printf("序号|姓名|入校年份|在校身份|研究领域|主要成就1|主要成就2|主要成就3\n");
			printf("%d|%s|%d|%s|%s|%s|%s|%s\n",stf[i].num,stf[i].name,stf[i].year,stf[i].pos,stf[i].position,stf[i].gx[0],stf[i].gx[1],stf[i].gx[2]);
		break;
		}
		
	}
	if(i==sum){
		printf("无此校友\n");
	}
	getchar();
	char is;
	printf("是否退出（y/n）：\n");
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
	printf("序号|姓名|入校年份|在校身份|研究领域|主要成就1|主要成就2|主要成就3\n");
	for(i=0;i<sum;i++){
		
		printf("%d|%s|%d|%s|%s|%s|%s|%s\n",stf[showID[i]].num,stf[showID[i]].name,stf[showID[i]].year,stf[showID[i]].pos,stf[showID[i]].position,stf[showID[i]].gx[0],stf[showID[i]].gx[1],stf[showID[i]].gx[2]);
	}
	getchar();
	char is;
	printf("是否退出（y/n）：\n");
	scanf("%c",&is);
	if(is == 'n'){
		show();
	}
	else{
		return;
	}
} 


//查询
void check(){
	char a, b, c, d, Choice;
		
	while(1){
	system("cls");
	printf("请选择功能\n");
	printf("a.根据序号查找。\n");
	printf("b.根据姓名查找。\n");
	printf("c.显示校友数据（按序号排序）\n");
	printf("d.退出。\n");
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
	

//文件存储
void writeArray()
{
    FILE *fd;  // filename 的文件描述符
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



//修改
void change(){
	int id;
	int i;
	printf("请输入你要修改的校友序号\n");
	scanf("%d",&id);
	for(i=0;i<sum;i++){
		if(stf[i].num==id){
		printf("请输入序号：\n");
		scanf("%d",&stf[i].num);
		printf("请输入姓名：\n");
		scanf("%s",stf[i].name);
		getchar();
		printf("请输入入校年份：\n");
		scanf("%d",&stf[i].year);
		printf("请输入在校身份：\n");
		scanf("%s",&stf[i].pos);
		getchar();
		printf("请输入研究领域：\n");
		scanf("%s",stf[i].position);
		getchar();
		
		int j;
		for(j=0;j<3;j++) {
			printf("请输入第%d主要成就：\n",j+1);
			scanf("%s",&stf[i].gx[j]);
			getchar();
		}
		printf("修改成功\n");
		break;
		}
		
	}

	char is;
	getchar();
	printf("是否退出（y/n）：\n");
	scanf("%c",&is);
	if(is == 'n'){
		change();
	}
	else{
		return;
	}
}








//输入 
void input(){
	printf("请输入序号：\n");
	scanf("%d",&stf[sum].num);
	printf("请输入姓名：\n");
	scanf("%s",stf[sum].name);
	getchar();
	printf("请输入入校年份：\n");
	scanf("%d",&stf[sum].year);
	printf("请输入在校身份：\n");
	scanf("%s",&stf[sum].pos);
	getchar();
	printf("请输入研究领域：\n");
	scanf("%s",stf[sum].position);
	getchar();
	
	int i;
	for(i=0;i<3;i++) {
		printf("请输入第%d主要成就：\n",i+1);
		scanf("%s",&stf[sum].gx[i]);
		getchar();
	}
	
	sum++;
	char is;
	printf("是否退出（y/n）：\n");
	getchar();
	scanf("%c",&is);
	if(is == 'n'){
		input();
	}
	else{
		return;
	}
	
}
//读取数据 
void readArray()
{
    FILE *fd;  // filename 的文件描述符
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
	printf("校友录管理系统\n");
	printf("请选择功能\n");
	printf("a.添加校友信息。\n");
	printf("b.修改校友数据。\n");
	printf("c.查找校友。\n");
	printf("d.删除校友数据。\n");
	printf("f.保存数据至文件。\n");
	printf("g.读取文件数据。\n");
	
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
