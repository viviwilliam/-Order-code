//字符数组的函数调用，函数之函数调用
//字符数组元素通过函数调用的比较 

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void teststr(char **p){
	char buf[99999];
	strcpy(buf,p); 
	
	if(buf[0] =='1')
		printf("%c",p[0]);

	
}


void chartest(char **p){
	scanf("%s",&*p);
	char buf[99999];
	strcpy(buf,p); 
	
	if(buf[0] =='1')
		printf("%c",p[0]);
	teststr(&*p);
}

void func(char** dst)
{
		
        char* buf = (char*)malloc(20);
        memset(buf, 0, 20);
        strcpy(buf, "hello world!");
        *dst = buf;
        
        //puts(dst);
}


int main(){
	char p[10];
	
	chartest(&p);
	if(p[0]=='1')
	printf("%s",p);
	
	return 0;
}
