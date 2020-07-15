#include <stdio.h>

char tie[1000][1000]={"*"};
int visit[1000][1000] = {0};

void dfs(int i,int j){
	//下 
	if(tie[i+1][j]=='#'&&visit[i+1][j]==0){
		visit[i+1][j]=1;
		dfs(i+1,j);
	}
	//右 
	if(tie[i][j+1]=='#'&&visit[i][j+1]==0){
		visit[i][j+1]=1;
		dfs(i,j+1);
	}
	//斜右 
	if(tie[i+1][j+1]=='#'&&visit[i+1][j+1]==0){
		visit[i+1][j+1]=1;
		dfs(i+1,j+1);
	}
	//斜左 
	if(tie[i+1][j-1]=='#'&&visit[i+1][j-1]==0){
		visit[i+1][j-1]=1;
		dfs(i+1,j-1);
	}
	//左 
	if(tie[i][j-1]=='#'&&visit[i][j-1]==0){
		visit[i][j-1]=1;
		dfs(i,j-1);
	}
	//上
	 if(tie[i-1][j]=='#'&&visit[i-1][j]==0){
		visit[i-1][j]=1;
		dfs(i-1,j);
	}
	//上左
	 if(tie[i-1][j-1]=='#'&&visit[i-1][j-1]==0){
		visit[i-1][j-1]=1;
		dfs(i-1,j-1);
	}
	
	//上右
	 if(tie[i-1][j+1]=='#'&&visit[i-1][j+1]==0){
		visit[i-1][j+1]=1;
		dfs(i-1,j+1);
	} 
	 
}



int main(){
	int x,i,j;
	int sum = 0;
	scanf("%d",&x);
	for(i=1;i<x+1;i++){
		getchar();
		for(j=1;j<x+1;j++){
			scanf("%c",&tie[i][j]);
		}
	}
	for(i=1;i<=x;i++){
		for(j=1;j<=x;j++){
			if(tie[i][j]=='#'&&visit[i][j]==0){
				sum++;
				visit[i][j]=1;
				dfs(i,j);
			}
		}
	} 
	printf("%d",sum);
	return 0;
}


//int waysToStep(int n){
//    if (n < 4) {
//        return n == 3 ? 4 : n;
//    }
//
//    int a = 1, b = 2, c = 4;
//    int i;
//    for (i = 4; i <= n; ++i) {
//        int temp = (a + b) % 1000000007 + c;
//        a = b;
//        b = c;
//        c = temp % 1000000007;
//    }
//    return c;
//}
//int main(){
//	int m;
//	scanf("%d",&m);
//	printf("%d",waysToStep(m));
//	return 0;
//}
//

//long long fun(long long n)
//{
// if (n == 0)
//  return 1;
//
// else if (n == 1)
//  return 0;
//
// else if (n % 2 == 1)
//  return 2 * fun((n - 1) / 2);
//
// else if (n % 2 == 0)
//  return 2 * fun(n / 2) + 1;
//
// else
//  return 0;
//}
//
//int main()
//{
// long long n;
// scanf("%lld",&n);
// printf("%lld",fun(n));
// return 0;
//}



//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//
//double a,b,c,d;
//int main()
//{
//    double x;
//    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
//    for (x=-100;x<=100;x+=0.01)
//    {
//        if (fabs(a*x*x*x+b*x*x+c*x+d)<=0.00001)
//            printf("%.2f ",x);
//    }
//} 
//
//
//


//#include <stdio.h>
//
//
//#define ll long long
//const int N=1e5+7;
//int a[10000],c,n,t;
//
//
//int main()
//{
//   scanf("%d",&t);
//   while(t--)
//   {
//       scanf("%d",&n);
//       c=0;
//       int i;
//       for(i=2;i<=n;i++){
//        while(n%i==0){
//            a[c++]=i;
//            n/=i;
//        }
//       }
//       if(c==2) puts("YES");
//       else puts("NO");
//   }
//}
//
//




//#include<stdio.h>
//
//int main(){
//	char str[10000];
//	int aum[10000]={0};
//	int n;
//	scanf("%d",&n);
//	int i;
//	for(i=0;i<n;i++){
//		scanf("%s",&str);
//		int sum =0;
//		int j;
//		for(j=0;str[j+1]!='\0';j++){
//			if(str[j]=='A'&&str[j+1]=='K'){
//				sum++;
//			}
//		}
//		aum[i] = sum;
//	}
//	for(i=0;i<n;i++){
//		printf("%d\n",aum[i]);
//	}
//	
//	return 0;
//}
//

//int sign,a[10][10];
//
//void calc(int x)
//{
//int s1=0,s2=0,s3=0,i,j;
//for(i=x;i<=x+2;i++)
//{
//for(j=1;j<=3;j++) s1+=a[i][j];
//for(j=4;j<=6;j++) s2+=a[i][j];
//for(j=7;j<=9;j++) s3+=a[i][j];
//}
//if((s1!=45)||(s2!=45)||(s3!=45)) sign=0;
//}
//
//int main()
//{
//int i,j,n,sum;
//scanf("%d",&n);
//while(n--)
//{
//sign=1;
//for(i=1;i<=9;i++)
//{
//for(j=1;j<=9;j++)
//{
//scanf("%d",&a[i][j]);
//}
//}
//for(i=1;i<=9;i++)
//{
//sum=0;
//for(j=1;j<=9;j++)
//{
//if(a[i][j]==5) sum++;
//}
//if (sum>1)
//{
//sign=0;
//break;
//}
//}
//if(sign)
//{
//for(i=1;i<=9;i++)
//{
//sum=0;
//for(j=1;j<=9;j++) sum+=a[i][j];
//if(sum!=45)
//{
//sign=0;
//break;
//}
//}
//}
//if(sign)
//{
//for(j=1;j<=9;j++)
//{
//sum=0;
//for(i=1;i<=9;i++) sum+=a[i][j];
//if(sum!=45)
//{
//sign=0;
//break;
//}
//}
//}
//if(sign) calc(1);
//if(sign) calc(4);
//if(sign) calc(7);
//if(sign) printf("Right\n");
//else printf("Wrong\n");
//scanf("");
//}
//
//return 0;
//}


//#include<stdio.h>
//
//
//double number,circle[1000];
//int check_print(int i)                          			//检查是否出现循环节或者循环点
//{
//    int j;
//    for(j=0;j<i;j++)
//    {
//        if(circle[j]==circle[i])
//            break;
//    }
//    if(j==i) return 0;                                      
//    else
//    {
//        for(;j<i;j++)
//        {
//            printf("%.0lf ",circle[j]);         			 //直接输出循环节
//        }
//        printf("\n");
//        return 1;
//    }
//    
//}
//double pow1(int n)					      //数组下标是几就返回10的几次方
//{
//    if(n==0)
//        return 1;
//    else
//        return pow1(n-1)*10;
//}
//double confuse(double number)			              //求最大值最小值相减构成递归
//{
//    char ch[150];
//    int temp;
//    double max=0,min=0;
//    sprintf(ch,"%.0f",number);                                   //初始化ch数组
//    int i,j;
//    for(i=0;i<strlen(ch);i++)
//    {
//        for(j=0;j<strlen(ch)-i-1;j++)
//            if(ch[j]>ch[j+1])
//            {
//                temp=ch[j];
//                ch[j]=ch[j+1];
//                ch[j+1]=temp;
//            }
//    }
//    for(i=0;i<strlen(ch);i++)
//    {
//        max+=pow1(i)*(ch[i]-'0');
//        min+=pow1(strlen(ch)-i-1)*(ch[i]-'0');
//    }
//    return max-min;
//    
//}
//void femain(double number)
//{
//    int i=0;
//    for(i=0;;i++)
//    {
//        circle[i]=number;
//        if(check_print(i)==1) break;
//        else
//        {
//            number = confuse(number);
//        }
//    }   
//}
// 
//int main()
//{
//    while(1)
//    {
//        if(scanf("%lf",&number)==-1)break;
//        else
//        {
//            femain(number);
//        }
//    }
//    return 0;
//}

//int sum(int n){
//	int sum = 0;
//	while(n>0){
//		sum+=n%10;
//		n = n/10; 
//	}
//	return sum;
//}
//
//
//
//
////4
//int main(){
//	int n,k;
//	int o = 0;
//	scanf("%d%d",&n,&k);
//	int time =0;
//	int i;
//	for(i=1;i<n+1;i++){
//		if(sum(i)==k){
//			int u=0;
//			int j;
//			for(j=2;j<i;j++){
//				if(i%j==0){
//					u++;
//					break;
//				}
//			}
//			if(u==0){
//				o++;
//			//	cout<<i<<endl;
//			}
//		}
//	}
//	printf("%d",o);
//	return 0;
//}

