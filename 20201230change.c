#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>




//书本结构体
typedef struct informations {
	int bnum;//编号
	char bname[50];//书名
	char writer[30];//作者 
	int able;//可借数 
	int borrow;//借阅数 
	int store;//馆藏数 
}information;

information b[50]={0};



//-----------------public------------------------------------------
int readingstore()//读取馆藏书本书目的函数
{
	information bookt;
	int i,j=0;
	FILE *fp = NULL;
	
	if((fp = fopen("d:\\bookinformation.txt","r"))==NULL){
		printf("文件打开失败");
		return;
	}


	else{
	
	    while(!feof(fp)){
			fscanf(fp,"%d",&bookt.bnum);
			fscanf(fp , "\n");
			fscanf(fp,"%s",bookt.bname);
			fscanf(fp , "\n");	
			fscanf(fp,"%s",bookt.writer);
			fscanf(fp , "\n");
			fscanf(fp,"%d",&bookt.able);
			fscanf(fp , "\n");
			fscanf(fp,"%d",&bookt.borrow);
			fscanf(fp , "\n");
			fscanf(fp,"%d",&bookt.store);
			fscanf(fp , "\n");
			
			b[j].bnum = bookt.bnum;
			for(i=0;i<50;i++)
			b[j].bname[i] = bookt.bname[i];
			for(i=0;i<30;i++)
			b[j].writer[i] = bookt.writer[i];
			b[j].able = bookt.able;
			b[j].borrow = bookt.borrow;
			b[j].store = bookt.store;
			
			j++;		
	}
	
	}
	

		fclose(fp);
return j;
}

//将删减过的的书本信息重新存入馆藏信息库并覆盖之前的馆藏信息的函数
void outreadings(int cishu)
{
	int i;
	FILE *fp = NULL;
	if((fp = fopen("d:\\bookinformation.txt","w+"))==NULL){
		printf("文件打开失败");
		return;
	}


	else{
	
	    for (i = 0; i < cishu-1; i++) {
	    	
	    	
	    	char s[1100];
    		//将int转换成char[] 
    		itoa(b[i].bnum,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");
			
			fprintf(fp,b[i].bname);
			fprintf(fp , "\n");	
			
			fprintf(fp,b[i].writer);
			fprintf(fp , "\n");
			
			itoa(b[i].able,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");
			
			itoa(b[i].borrow,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");
			
			itoa(b[i].store,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");		
	}
	
	}
		fclose(fp);
}



//信息更新到文件 
void outreading(int N){
	int i;
		FILE *fp = NULL;
	
	if((fp = fopen("d:\\bookinformation.txt","w+"))==NULL){
		printf("文件打开失败");
		return;
	}


	else{
	
	    for (i = 0; i < N; i++) {
	    	
	    	
	    	char s[1100];
    		//将int转换成char[] 
    		itoa(b[i].bnum,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");
			
			fprintf(fp,b[i].bname);
			fprintf(fp , "\n");	
			
			fprintf(fp,b[i].writer);
			fprintf(fp , "\n");
			
			itoa(b[i].able,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");
			
			itoa(b[i].borrow,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");
			
			itoa(b[i].store,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");		
	}
	
	}
		fclose(fp);
}

//推荐 
void recommend() {
	int num=readingstore();
	printf("书号|书名|作者|可借数|借出数|馆藏数\n");	
	int N;
	int i;
	int j, k;
	information mid ;

	for (j = 0; j < num-1; j++) {
		for (k = j+1; k <num; k++) {
			if (b[k].borrow > b[j].borrow) {
				mid = b[k];
				b[k] = b[j];
				b[j] = mid;
			}
		}
	}for (i = 0; i < 5; i++) {
		printf("%d|%s|%s|%d|%d|%d\n",b[i].bnum,
			b[i].bname,
			b[i].writer,
			b[i].able,
			b[i].borrow,
			b[i].store);
	}
}
//---------------------------------------------------------


//打印排序后书目的函数
void output(int cishu)
{
	int i ;
	printf("尊敬的管理员，馆藏信息如下，供您参考：\n" );
	printf("书号|书名|作者|可借数|借阅数|馆藏数\n" );
	for (i = 0; i < cishu; i++)
	{
		printf("%d|%s|%s|%d|%d|%d\n",b[i].bnum, b[i].bname ,b[i].writer, b[i].able,b[i].borrow ,b[i].store);
	}
}







//馆藏书目按照书名排序
void sort(int cishu)//馆藏书目按照书名排序
{
	int i, j;
	for (i = 0; i < cishu; i++)
	{
		for (j = 0; j < cishu - 1 - i; j++)
		{
			if (b[j].bname[0] - b[j + 1].bname[0] > 0)
			{
				information temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
			else if (b[j].bname[0] - b[j + 1].bname[0] == 0)
			{
				int k = 0;
				while (b[j].bname[k] - b[j + 1].bname[k] == 0)
				{
					k++;
				}
				if (b[j].bname[k] - b[j + 1].bname[k] > 0)
				{
					information temp = b[j];
					b[j] = b[j + 1];
					b[j + 1] = temp;
				}

			}
		}
	}
}

//准入函数（密码登录）
void enter()//准入函数（密码登录）
{
	FILE *fp = NULL;
	char code[20], t;
	if((fp = fopen("d:\\coding.txt","r"))==NULL){
		printf("读取系统密码失败！");
		return;
	}
	else{
		fscanf(fp,"%s",code);
	}
	fclose(fp);

	printf("请输入管理员密码：\n");
	while (1)
	{
		char coding[20];
		char ch;
		ch = _getch();
		int i=0;
		while (ch != '\n' && ch != '\r' && ch != '\b')
		{
			_putch('*');
			coding[i] = ch;
			i++;
			ch = _getch();
		}
		if (strcmp(coding,code)==0)
		{
			printf("成功登录！\n");
			break;
		}
		else
		{
			system("cls");
			printf("密码错误请重新输入！\n");
			enter();
		}
		break;
	}
}


//输出提示菜单
int menuchoosing()
{
	int t;
	printf("        \n");
	printf("请您根据菜单提示选择管理功能：\n");
	printf("        \n");
	printf("添加书目请按1\n");
	printf("        \n");
	printf("删除馆藏为零的书目请按2\n");
	printf("              \n");
	printf("修改密码请按3\n");
	printf("              \n");
	printf("直接退出请按4\n");
	scanf("%d",&t);
	return t;
}


//打印馆藏书本书目已用书号的函数
void printbooknum(int N)//打印馆藏书本书目已用书号的函数
{
	int h;
	//int N = readingstore();
	printf("已经被使用的书号如下，请不要使用重复的书号!\n");
		for ( h = 0; h <N; h++)
		{
			printf("%d  ",b[h].bnum);
		}
}






//添加书本信息的函数
information plusing()//添加书本信息的函数
{
	int N = readingstore();
	output(N);
	int t;

	printbooknum(N);
	information plusbook;
	printf("请您添加书目！\n");

	while (1)
	{
		printf("请输入书号：\n");
		scanf("%d",&t);

		int flag = 1;
		int i; 
		for (i = 0; i < N; i++)
		{
			if (t == b[i].bnum)
			{
				printf("书号%d已经被使用，请换一个书号定义。\n",t);
				flag = 0;

			}
		}

		if (flag)
		{
			break;
		}

	}
	plusbook.bnum = t;
	printf("请输入书名：\n");
	scanf("%s",&plusbook.bname);
	
	printf("请输入书的作者：\n");
	scanf("%s",&plusbook.writer);
	
	printf("请输入可借数：\n");
	scanf("%d",&plusbook.able);
	
	printf("请输入借阅数：\n");
	scanf("%d",&plusbook.borrow);
	
	printf("请输入馆藏数：\n");
	scanf("%d",&plusbook.store);


	return plusbook;
}




//删减图书模块
void deleting(int cishu)
{
	char sign = '0';
	while(1)
	{
		system("cls");
		output(cishu);//输出排序后馆藏信息


		int finding;
		printf("请根据菜单输入您需要删除的书的书号：（只删除馆藏为零的书目信息）\n");
		scanf("%d",&finding);
		int deleting;
		int y;
		for ( y = 0; y < cishu; y++)
		{
			if (b[y].bnum == finding)
			{
				deleting = y;
				break;
			}
		}
		if (b[deleting].store != 0)//第deleting本书在数组中是第deleting-1个元素
		{
			system("cls");
			printf("无法删除此书因为图书馆尚有馆藏！\n" );
			break;
		}

		printf("确认删除？\n" );
		printf("              \n" );
		printf("确认删除请按1\n" );
		printf("              \n" );
		printf("取消删除请按2\n" );
		int t;
		int x;
		scanf("%d",&t);
		switch (t)
		{
		case 1:
			
			for ( x = deleting; x < cishu; x++)//从选定的书号开始，用下一个值覆盖上一个值，最后一个值不录入
			{
				if (x == cishu)
				{
					cishu--;
				}
				b[x] = b[x + 1];
			}

			outreadings(cishu); //将删改过的的书本信息重新存入馆藏信息库并覆盖之前的馆藏信息
			cishu--;

			printf("是否继续删除书目，按任意键继续删除书目，按ESC键退出\n");
			sign =getch();
						if(!(sign==0x1B)){
						
							system("cls");
							continue;
						}
						system("cls");
						break;

		case 2:
			printf("是否继续删除书目，按任意键继续删除书目，按ESC键退出\n");
			sign =getch();
						if(!(sign==0x1B)){
						
							system("cls");
							continue;
						}
						system("cls");
						break;
		}
	}

}


//修改密码的函数
void changingcode()
{
	printf("请先验证管理员身份！\n" );
	enter();
	char sign;
	sign = '0';
	char newcoding[20];
	char newcode[20];
	char t[20];
	FILE *fp = NULL;
	if((fp = fopen("d:\\coding.txt","r"))==NULL){
		printf("读取系统密码失败！");
		return;
	}
	else{
		fscanf(fp,"%s",newcoding);
	}
	fclose(fp);

	while(1)
	{
		printf("现在进入修改密码！\n");
		printf(" \n");
		printf("确认进入请按1\n");
		printf(" \n");
		printf("退出修改请按2\n");

		int choosing1;
		scanf("%d",&choosing1);
		if (choosing1 == 2)
		{
			break;
		}
		
		while (1)
		{
			printf("请输入新的密码：\n");
			char ch;
			ch = getch();
			int i=0;
			while (ch != '\n' && ch != '\r' && ch != '\b')
			{
				_putch('*');
				newcode[i] = ch;
				i++;
				ch = _getch();
			}

			char newcode1[20];
			printf("请再次确认密码：\n");
			char ch1;
			ch1 = _getch();
			i = 0;
			while (ch1 != '\n' && ch1 != '\r' && ch1 != '\b')
			{
				_putch('*');
				newcode1[i] = ch1;
				i++;
				ch1 = _getch();
			}

			if (strcmp(newcode,newcode1) == 0)
			{
				system("cls");
				printf("密码修改成功！\n");
				//newcoding = newcode;
				break;
			}

			else
			{
				system("cls");
				printf("两次密码不一致，下面请您重新修改密码：\n");
			}
		}
		printf("确认修改？按任意键重新修改，按ESC键确认修改\n" );
		sign =getch();
		if(!(sign==0x1B)){
		
			system("cls");
			continue;
		}
		system("cls");
		break;
	}

	if((fp = fopen("d:\\coding.txt","w+"))==NULL){
		printf("保存系统密码失败！\n");
		return;
	}
	else{
		fprintf(fp,newcode);
	}
	fclose(fp);
}






//管理模块主要部分：
void management()
{
//	准入模块
	printf("进入管理功能之前请输入管理员密码：\n" );
	enter();

	//功能模块
	char sign;
	sign = '0';
	for (; sign != 27;)
	{
		system("cls");
		printf("               \n" );
		printf("****欢迎进入管理功能****\n" );



		//读取馆藏书目
		int N = readingstore();     //1、首先读取馆藏书本数量

		sort(N);//馆藏信息排序

		output(N);//输出排序后馆藏信息


		//系统管理模块
		int choose = menuchoosing();//选取添加或删除或修改密码或直接退出功能
		switch (choose)
		{

		case(1)://添加书目模块
			while(1){
				system("cls");

				N = N + 1;//馆藏数量添加一本

				b[N - 1] = plusing();//添加后数量多一本，但是在数组中序号还是要减一,此处输入第N+1本书的信息
				printf("确认添加图书？\n");
				printf("              \n");
				printf("确认添加请按1\n");
				printf("              \n");
				printf("取消添加请按2\n");
			
				int ts;
				scanf("%d",&ts);
				switch (ts)
				{
				case 1:
					sort(N);//添加后排序
					outreading(N); //将增加过的的书本信息重新存入馆藏信息库并覆盖之前的馆藏信息

					printf("是否继续添加书目，按任意键继续添加书目，按ESC键退出\n" );
					sign =getch();
						if(!(sign==0x1B)){
						
							system("cls");
							continue;
						}
						system("cls");
						break;
				case 2:
					N = N - 1;
					printf("是否继续添加书目，按任意键继续添加书目，按ESC键退出\n" );
					sign =getch();
						if(!(sign==0x1B)){
						
							system("cls");
							continue;
						}
						system("cls");
						break;
				}
				break;
			}
			printf("是否继续管理，按任意键继续管理，按ESC键退出\n" );
					sign =getch();
						if(!(sign==0x1B)){
						
							system("cls");
							continue;
						}
						system("cls");
						break;


		case(2)://删除书目模块


			deleting(N);

			printf("是否继续管理，按任意键继续管理，按ESC键退出\n" );
					sign =getch();
						if(!(sign==0x1B)){
						
							system("cls");
							continue;
						}
						system("cls");
						break;


		case 3:
			system("cls");
			changingcode();
			printf("是否继续管理，按任意键继续管理，按ESC键退出\n" );
					sign =getch();
						if(!(sign==0x1B)){
						
							system("cls");
							continue;
						}
						system("cls");
						break;


		case(4):
			printf("是否继续管理，按任意键继续管理，按ESC键退出\n" );
					sign =getch();
						if(!(sign==0x1B)){
						
							system("cls");
							continue;
						}
						system("cls");
						break;

		}

	}
}











 
//还书 
void ret() {
	int N;
	
	char sign;
	sign = '0';
	while(1){
		N = readingstore(); //1、首先读取馆藏书本数量
		printf("****欢迎进入归还功能****\n");
		printf("请输入您要还的书的书名\n");
		char myname[50];
		scanf("%s",&myname);
		int count = 0;
		int i ;
		for (i = 0; i < N; i++) {
			if (strcmp(b[i].bname,myname)==0) {
				b[i].able = b[i].able + 1;
				b[i].borrow = b[i].borrow - 1;
				count = 1;
			}
		} if (count == 1) printf("还书成功\n");
		else printf("本馆无此书，还书失败\n");
			FILE *fp = NULL;
	
	if((fp = fopen("d:\\bookinformation.txt","w+"))==NULL){
		printf("文件打开失败");
		return;
	}


	else{
	
	    for (i = 0; i < N; i++) {
	    	
	    	
	    	char s[1100];
    		//将int转换成char[] 
    		itoa(b[i].bnum,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");
			
			fprintf(fp,b[i].bname);
			fprintf(fp , "\n");	
			
			fprintf(fp,b[i].writer);
			fprintf(fp , "\n");
			
			itoa(b[i].able,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");
			
			itoa(b[i].borrow,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");
			
			itoa(b[i].store,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");		
	}
	
	}
		fclose(fp);
		printf("是否继续还书，按任意键继续还书，按ESC键退出");
		sign =getch();
			if(!(sign==0x1B)){
			
				system("cls");
				continue;
			}
			system("cls");
			break;
	}
}





//借书 
void book() {
	int N;

	char sign;
	sign = '0';
	int counter = 0;
	while(1) {
		N = readingstore(); //1、首先读取馆藏书本数量
		printf("****欢迎进入借书功能****\n");

		printf("                             \n");
		printf("以下是根据借阅量给您推荐的书目：\n");
		recommend();
		printf("请输入您要借的书的书名\n");

		char myname[50];
		scanf("%s",&myname);
		int i;
		for ( i = 0; i < N; i++) {
			if (strcmp(b[i].bname,myname)==0) {
				counter = 1;
				if (b[i].able > 0) {
					printf("是否确定借书？\n");
					printf("Y\tN\n");
					char sign;
					sign = getch();
					if (sign == 'y' || sign == 'Y') {
						printf("借书成功\n");
						b[i].able = b[i].able - 1;
						b[i].borrow = b[i].borrow + 1;
					}

				}
				else printf("本书不可借\n");

			}
		}if (counter == 0) {
		    printf("无此书\n");
		}
		counter = 0;
	FILE *fp = NULL;
	
	if((fp = fopen("d:\\bookinformation.txt","w+"))==NULL){
		printf("文件打开失败");
		return;
	}


	else{
	
	    for (i = 0; i < N; i++) {
	    	
	    	
	    	char s[1100];
    		//将int转换成char[] 
    		itoa(b[i].bnum,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");
			
			fprintf(fp,b[i].bname);
			fprintf(fp , "\n");	
			
			fprintf(fp,b[i].writer);
			fprintf(fp , "\n");
			
			itoa(b[i].able,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");
			
			itoa(b[i].borrow,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");
			
			itoa(b[i].store,s,10);
			fprintf(fp,s);
			fprintf(fp , "\n");		
	}
	
	}
		fclose(fp);
		printf("是否继续借阅，按任意键继续借阅，按ESC键退出");
		sign =getch();
			if(!(sign==0x1B)){
			
				system("cls");
				continue;
			}
			system("cls");
			break;
	}

}










//按书名查询的函数
//按书名查询的函数
void name(information n, char* in, int* con) {
	char sign;
	int i = 0;
	int count = 0;
	while (n.bname[i] == in[i]) {
		*con = 1;
		count = 1;
		i++;
	}if (count == 1) {
		printf("%d|%s|%s|%d|%d|%d\n",n.bnum,
			n.bname,
			n.writer,
			n.able,
			n.borrow,
			n.store);

	}

}

void writer(information n, char * in, int* con) {
	int i = 0;
	int count = 0;
	while (n.writer[i] == in[i]) {
		*con = 1;
		count = 1;
		i++;
	}if (count == 1) {
			printf("%d|%s|%s|%d|%d|%d\n",n.bnum,
			n.bname,
			n.writer,
			n.able,
			n.borrow,
			n.store);
	}

}









//搜索
void search() {
	int num=readingstore();
	char sign;
	char input[50];
	int counter = 0;
	int i = 0;
	int j = 0;
		while(1){
			printf("****欢迎进入查询功能****\n");
			printf( "      \n");
			printf( "这是根据借阅量给您推荐的书及其相应的信息\n");
			recommend();
			printf( "请选择查询方式（支持模糊查询）\n");
			printf( "            \n");
			printf( "A\t按书名查询\n");
			printf( "             \n");
			printf( "B\t按作者名查询\n");
			scanf("%s",&sign);


			switch (sign) {
				case'A':case'a':printf( "请输入书名:\n"); 
					scanf("%s",&input);
					system("cls");
					printf("书号|书名|作者|可借数|借出数|馆藏数\n");
					for (i = 0; i < num; i++)
						name(b[i], input, &counter);
					break;
				case'B':case'b':printf( "请输入作者名:\n"); 
					scanf("%s",&input);
					system("cls");
					printf("书号|书名|作者|可借数|借出数|馆藏数\n");
	
					for (i = 0; i < num; i++)
						writer(b[i], input, &counter);
					break;
				default:counter = 1;
					printf("请输入相应字母\n");
			}
			if (counter == 0)
			{
				system("cls");
				printf("本图书馆无该藏书\n");
			}
			else {
				counter = 0;
			}
			printf("是否继续查询，按任意键继续查询，按ESC键退出");
			sign =getch();
			if(!(sign==0x1B)){
			
				system("cls");
				continue;
			}
			system("cls");
			break;
		}
}







//------------------------------------------------------



//菜单
void menu() {
	printf("***********************************\n");
	printf("*  欢 迎 进 入 图 书 管 理 系 统  *\n");
	printf("***********************************\n");
	printf(" s 查询 \n");
	printf("        \n");
	printf(" b 借书 \n");
	printf("        \n");
	printf(" r 还书 \n");
	printf("        \n");
	printf(" m 管理 \n");
	printf("        \n");
	printf(" q 退出 \n");
	printf("        \n");
	printf("请输入符号（大小写均可）:\n");
}



//主函数
int main()
{

	while(1) {
		char fundation;
		menu();
		scanf("%s",&fundation);
		if (fundation == 'q' || fundation == 'Q') {
			printf("使用结束");
			system("cls");
			break;
		}
		system("cls");
		switch (fundation) {
		case's':case'S': search(); break;
		case'b':case'B':book(); break;
		case'r':case'R':ret(); break;
		case'm':case'M': management(); break;
		}
	}
}



