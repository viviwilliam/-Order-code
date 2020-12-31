#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>




//�鱾�ṹ��
typedef struct informations {
	int bnum;//���
	char bname[50];//����
	char writer[30];//���� 
	int able;//�ɽ��� 
	int borrow;//������ 
	int store;//�ݲ��� 
}information;

information b[50]={0};



//-----------------public------------------------------------------
int readingstore()//��ȡ�ݲ��鱾��Ŀ�ĺ���
{
	information bookt;
	int i,j=0;
	FILE *fp = NULL;
	
	if((fp = fopen("d:\\bookinformation.txt","r"))==NULL){
		printf("�ļ���ʧ��");
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

//��ɾ�����ĵ��鱾��Ϣ���´���ݲ���Ϣ�Ⲣ����֮ǰ�Ĺݲ���Ϣ�ĺ���
void outreadings(int cishu)
{
	int i;
	FILE *fp = NULL;
	if((fp = fopen("d:\\bookinformation.txt","w+"))==NULL){
		printf("�ļ���ʧ��");
		return;
	}


	else{
	
	    for (i = 0; i < cishu-1; i++) {
	    	
	    	
	    	char s[1100];
    		//��intת����char[] 
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



//��Ϣ���µ��ļ� 
void outreading(int N){
	int i;
		FILE *fp = NULL;
	
	if((fp = fopen("d:\\bookinformation.txt","w+"))==NULL){
		printf("�ļ���ʧ��");
		return;
	}


	else{
	
	    for (i = 0; i < N; i++) {
	    	
	    	
	    	char s[1100];
    		//��intת����char[] 
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

//�Ƽ� 
void recommend() {
	int num=readingstore();
	printf("���|����|����|�ɽ���|�����|�ݲ���\n");	
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


//��ӡ�������Ŀ�ĺ���
void output(int cishu)
{
	int i ;
	printf("�𾴵Ĺ���Ա���ݲ���Ϣ���£������ο���\n" );
	printf("���|����|����|�ɽ���|������|�ݲ���\n" );
	for (i = 0; i < cishu; i++)
	{
		printf("%d|%s|%s|%d|%d|%d\n",b[i].bnum, b[i].bname ,b[i].writer, b[i].able,b[i].borrow ,b[i].store);
	}
}







//�ݲ���Ŀ������������
void sort(int cishu)//�ݲ���Ŀ������������
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

//׼�뺯���������¼��
void enter()//׼�뺯���������¼��
{
	FILE *fp = NULL;
	char code[20], t;
	if((fp = fopen("d:\\coding.txt","r"))==NULL){
		printf("��ȡϵͳ����ʧ�ܣ�");
		return;
	}
	else{
		fscanf(fp,"%s",code);
	}
	fclose(fp);

	printf("���������Ա���룺\n");
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
			printf("�ɹ���¼��\n");
			break;
		}
		else
		{
			system("cls");
			printf("����������������룡\n");
			enter();
		}
		break;
	}
}


//�����ʾ�˵�
int menuchoosing()
{
	int t;
	printf("        \n");
	printf("�������ݲ˵���ʾѡ������ܣ�\n");
	printf("        \n");
	printf("�����Ŀ�밴1\n");
	printf("        \n");
	printf("ɾ���ݲ�Ϊ�����Ŀ�밴2\n");
	printf("              \n");
	printf("�޸������밴3\n");
	printf("              \n");
	printf("ֱ���˳��밴4\n");
	scanf("%d",&t);
	return t;
}


//��ӡ�ݲ��鱾��Ŀ������ŵĺ���
void printbooknum(int N)//��ӡ�ݲ��鱾��Ŀ������ŵĺ���
{
	int h;
	//int N = readingstore();
	printf("�Ѿ���ʹ�õ�������£��벻Ҫʹ���ظ������!\n");
		for ( h = 0; h <N; h++)
		{
			printf("%d  ",b[h].bnum);
		}
}






//����鱾��Ϣ�ĺ���
information plusing()//����鱾��Ϣ�ĺ���
{
	int N = readingstore();
	output(N);
	int t;

	printbooknum(N);
	information plusbook;
	printf("���������Ŀ��\n");

	while (1)
	{
		printf("��������ţ�\n");
		scanf("%d",&t);

		int flag = 1;
		int i; 
		for (i = 0; i < N; i++)
		{
			if (t == b[i].bnum)
			{
				printf("���%d�Ѿ���ʹ�ã��뻻һ����Ŷ��塣\n",t);
				flag = 0;

			}
		}

		if (flag)
		{
			break;
		}

	}
	plusbook.bnum = t;
	printf("������������\n");
	scanf("%s",&plusbook.bname);
	
	printf("������������ߣ�\n");
	scanf("%s",&plusbook.writer);
	
	printf("������ɽ�����\n");
	scanf("%d",&plusbook.able);
	
	printf("�������������\n");
	scanf("%d",&plusbook.borrow);
	
	printf("������ݲ�����\n");
	scanf("%d",&plusbook.store);


	return plusbook;
}




//ɾ��ͼ��ģ��
void deleting(int cishu)
{
	char sign = '0';
	while(1)
	{
		system("cls");
		output(cishu);//��������ݲ���Ϣ


		int finding;
		printf("����ݲ˵���������Ҫɾ���������ţ���ֻɾ���ݲ�Ϊ�����Ŀ��Ϣ��\n");
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
		if (b[deleting].store != 0)//��deleting�������������ǵ�deleting-1��Ԫ��
		{
			system("cls");
			printf("�޷�ɾ��������Ϊͼ������йݲأ�\n" );
			break;
		}

		printf("ȷ��ɾ����\n" );
		printf("              \n" );
		printf("ȷ��ɾ���밴1\n" );
		printf("              \n" );
		printf("ȡ��ɾ���밴2\n" );
		int t;
		int x;
		scanf("%d",&t);
		switch (t)
		{
		case 1:
			
			for ( x = deleting; x < cishu; x++)//��ѡ������ſ�ʼ������һ��ֵ������һ��ֵ�����һ��ֵ��¼��
			{
				if (x == cishu)
				{
					cishu--;
				}
				b[x] = b[x + 1];
			}

			outreadings(cishu); //��ɾ�Ĺ��ĵ��鱾��Ϣ���´���ݲ���Ϣ�Ⲣ����֮ǰ�Ĺݲ���Ϣ
			cishu--;

			printf("�Ƿ����ɾ����Ŀ�������������ɾ����Ŀ����ESC���˳�\n");
			sign =getch();
						if(!(sign==0x1B)){
						
							system("cls");
							continue;
						}
						system("cls");
						break;

		case 2:
			printf("�Ƿ����ɾ����Ŀ�������������ɾ����Ŀ����ESC���˳�\n");
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


//�޸�����ĺ���
void changingcode()
{
	printf("������֤����Ա��ݣ�\n" );
	enter();
	char sign;
	sign = '0';
	char newcoding[20];
	char newcode[20];
	char t[20];
	FILE *fp = NULL;
	if((fp = fopen("d:\\coding.txt","r"))==NULL){
		printf("��ȡϵͳ����ʧ�ܣ�");
		return;
	}
	else{
		fscanf(fp,"%s",newcoding);
	}
	fclose(fp);

	while(1)
	{
		printf("���ڽ����޸����룡\n");
		printf(" \n");
		printf("ȷ�Ͻ����밴1\n");
		printf(" \n");
		printf("�˳��޸��밴2\n");

		int choosing1;
		scanf("%d",&choosing1);
		if (choosing1 == 2)
		{
			break;
		}
		
		while (1)
		{
			printf("�������µ����룺\n");
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
			printf("���ٴ�ȷ�����룺\n");
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
				printf("�����޸ĳɹ���\n");
				//newcoding = newcode;
				break;
			}

			else
			{
				system("cls");
				printf("�������벻һ�£��������������޸����룺\n");
			}
		}
		printf("ȷ���޸ģ�������������޸ģ���ESC��ȷ���޸�\n" );
		sign =getch();
		if(!(sign==0x1B)){
		
			system("cls");
			continue;
		}
		system("cls");
		break;
	}

	if((fp = fopen("d:\\coding.txt","w+"))==NULL){
		printf("����ϵͳ����ʧ�ܣ�\n");
		return;
	}
	else{
		fprintf(fp,newcode);
	}
	fclose(fp);
}






//����ģ����Ҫ���֣�
void management()
{
//	׼��ģ��
	printf("���������֮ǰ���������Ա���룺\n" );
	enter();

	//����ģ��
	char sign;
	sign = '0';
	for (; sign != 27;)
	{
		system("cls");
		printf("               \n" );
		printf("****��ӭ���������****\n" );



		//��ȡ�ݲ���Ŀ
		int N = readingstore();     //1�����ȶ�ȡ�ݲ��鱾����

		sort(N);//�ݲ���Ϣ����

		output(N);//��������ݲ���Ϣ


		//ϵͳ����ģ��
		int choose = menuchoosing();//ѡȡ��ӻ�ɾ�����޸������ֱ���˳�����
		switch (choose)
		{

		case(1)://�����Ŀģ��
			while(1){
				system("cls");

				N = N + 1;//�ݲ��������һ��

				b[N - 1] = plusing();//��Ӻ�������һ������������������Ż���Ҫ��һ,�˴������N+1�������Ϣ
				printf("ȷ�����ͼ�飿\n");
				printf("              \n");
				printf("ȷ������밴1\n");
				printf("              \n");
				printf("ȡ������밴2\n");
			
				int ts;
				scanf("%d",&ts);
				switch (ts)
				{
				case 1:
					sort(N);//��Ӻ�����
					outreading(N); //�����ӹ��ĵ��鱾��Ϣ���´���ݲ���Ϣ�Ⲣ����֮ǰ�Ĺݲ���Ϣ

					printf("�Ƿ���������Ŀ������������������Ŀ����ESC���˳�\n" );
					sign =getch();
						if(!(sign==0x1B)){
						
							system("cls");
							continue;
						}
						system("cls");
						break;
				case 2:
					N = N - 1;
					printf("�Ƿ���������Ŀ������������������Ŀ����ESC���˳�\n" );
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
			printf("�Ƿ�������������������������ESC���˳�\n" );
					sign =getch();
						if(!(sign==0x1B)){
						
							system("cls");
							continue;
						}
						system("cls");
						break;


		case(2)://ɾ����Ŀģ��


			deleting(N);

			printf("�Ƿ�������������������������ESC���˳�\n" );
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
			printf("�Ƿ�������������������������ESC���˳�\n" );
					sign =getch();
						if(!(sign==0x1B)){
						
							system("cls");
							continue;
						}
						system("cls");
						break;


		case(4):
			printf("�Ƿ�������������������������ESC���˳�\n" );
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











 
//���� 
void ret() {
	int N;
	
	char sign;
	sign = '0';
	while(1){
		N = readingstore(); //1�����ȶ�ȡ�ݲ��鱾����
		printf("****��ӭ����黹����****\n");
		printf("��������Ҫ�����������\n");
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
		} if (count == 1) printf("����ɹ�\n");
		else printf("�����޴��飬����ʧ��\n");
			FILE *fp = NULL;
	
	if((fp = fopen("d:\\bookinformation.txt","w+"))==NULL){
		printf("�ļ���ʧ��");
		return;
	}


	else{
	
	    for (i = 0; i < N; i++) {
	    	
	    	
	    	char s[1100];
    		//��intת����char[] 
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
		printf("�Ƿ�������飬��������������飬��ESC���˳�");
		sign =getch();
			if(!(sign==0x1B)){
			
				system("cls");
				continue;
			}
			system("cls");
			break;
	}
}





//���� 
void book() {
	int N;

	char sign;
	sign = '0';
	int counter = 0;
	while(1) {
		N = readingstore(); //1�����ȶ�ȡ�ݲ��鱾����
		printf("****��ӭ������鹦��****\n");

		printf("                             \n");
		printf("�����Ǹ��ݽ����������Ƽ�����Ŀ��\n");
		recommend();
		printf("��������Ҫ����������\n");

		char myname[50];
		scanf("%s",&myname);
		int i;
		for ( i = 0; i < N; i++) {
			if (strcmp(b[i].bname,myname)==0) {
				counter = 1;
				if (b[i].able > 0) {
					printf("�Ƿ�ȷ�����飿\n");
					printf("Y\tN\n");
					char sign;
					sign = getch();
					if (sign == 'y' || sign == 'Y') {
						printf("����ɹ�\n");
						b[i].able = b[i].able - 1;
						b[i].borrow = b[i].borrow + 1;
					}

				}
				else printf("���鲻�ɽ�\n");

			}
		}if (counter == 0) {
		    printf("�޴���\n");
		}
		counter = 0;
	FILE *fp = NULL;
	
	if((fp = fopen("d:\\bookinformation.txt","w+"))==NULL){
		printf("�ļ���ʧ��");
		return;
	}


	else{
	
	    for (i = 0; i < N; i++) {
	    	
	    	
	    	char s[1100];
    		//��intת����char[] 
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
		printf("�Ƿ�������ģ���������������ģ���ESC���˳�");
		sign =getch();
			if(!(sign==0x1B)){
			
				system("cls");
				continue;
			}
			system("cls");
			break;
	}

}










//��������ѯ�ĺ���
//��������ѯ�ĺ���
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









//����
void search() {
	int num=readingstore();
	char sign;
	char input[50];
	int counter = 0;
	int i = 0;
	int j = 0;
		while(1){
			printf("****��ӭ�����ѯ����****\n");
			printf( "      \n");
			printf( "���Ǹ��ݽ����������Ƽ����鼰����Ӧ����Ϣ\n");
			recommend();
			printf( "��ѡ���ѯ��ʽ��֧��ģ����ѯ��\n");
			printf( "            \n");
			printf( "A\t��������ѯ\n");
			printf( "             \n");
			printf( "B\t����������ѯ\n");
			scanf("%s",&sign);


			switch (sign) {
				case'A':case'a':printf( "����������:\n"); 
					scanf("%s",&input);
					system("cls");
					printf("���|����|����|�ɽ���|�����|�ݲ���\n");
					for (i = 0; i < num; i++)
						name(b[i], input, &counter);
					break;
				case'B':case'b':printf( "������������:\n"); 
					scanf("%s",&input);
					system("cls");
					printf("���|����|����|�ɽ���|�����|�ݲ���\n");
	
					for (i = 0; i < num; i++)
						writer(b[i], input, &counter);
					break;
				default:counter = 1;
					printf("��������Ӧ��ĸ\n");
			}
			if (counter == 0)
			{
				system("cls");
				printf("��ͼ����޸ò���\n");
			}
			else {
				counter = 0;
			}
			printf("�Ƿ������ѯ���������������ѯ����ESC���˳�");
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



//�˵�
void menu() {
	printf("***********************************\n");
	printf("*  �� ӭ �� �� ͼ �� �� �� ϵ ͳ  *\n");
	printf("***********************************\n");
	printf(" s ��ѯ \n");
	printf("        \n");
	printf(" b ���� \n");
	printf("        \n");
	printf(" r ���� \n");
	printf("        \n");
	printf(" m ���� \n");
	printf("        \n");
	printf(" q �˳� \n");
	printf("        \n");
	printf("��������ţ���Сд���ɣ�:\n");
}



//������
int main()
{

	while(1) {
		char fundation;
		menu();
		scanf("%s",&fundation);
		if (fundation == 'q' || fundation == 'Q') {
			printf("ʹ�ý���");
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



