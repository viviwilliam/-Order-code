//#include <iostream>
//using namespace std;
//int huiwen(string s)
//{
//    int i, j;
//    string s2 = s;
//    for (i = 0, j = s2.length() - 1; i < s.length(); i++, j--)
//        if (s[i] != s2[j])
//            return 0;
//    return 1;
//}
//
//string int_string(int n)
//{
//    char cs[100];
//    sprintf(cs, "%d", n);
//    return string(cs);
//}
//
//int main()
//{
//    string s;
//    int x, y, z, k, i, j, ans = 0;
//    cin >> x >> y >> z;
//    for (i = 1; i < x; i++)
//    {
//        for (j = 1; j <= 12; j++)
//        {
//            for (k = 1; k <= 31; k++)
//            {
//                if (k == 31 && (j == 4 || j == 6 || j == 9 || j == 11))
//                    continue;
//                if (j == 2 && (k == 30 || k > 28 && !((i % 4 == 0 && (i % 100)) || (i % 400 == 0))))
//                    break;
//                s = int_string(i) + int_string(j) + int_string(k);
//                if (huiwen(s))
//                    ans++;
//            }
//        }
//    }
//    for (i = x, j = 1; j < y; j++)
//    {
//        for (k = 1; k <= 31; k++)
//        {
//            if (k == 31 && (j == 4 || j == 6 || j == 9 || j == 11))
//                continue;
//            if (j == 2 && (k == 30 || k > 28 && !((i % 4 == 0 && (i % 100)) || (i % 400 == 0))))
//                break;
//            s = int_string(i) + int_string(j) + int_string(k);
//            if (huiwen(s))
//                ans++;
//        }
//    }
//    for (i = x, j = y, k = 1; k <= z; k++)
//    {
//        if (k == 31 && (j == 4 || j == 6 || j == 9 || j == 11))
//            continue;
//        if (j == 2 && (k == 30 || k > 28 && !((i % 4 == 0 && (i % 100)) || (i % 400 == 0))))
//            break;
//        s = int_string(i) + int_string(j) + int_string(k);
//        if (huiwen(s))
//            ans++;
//    }
//    cout << ans << endl;
//    return 0;
//}

//#include<iostream>
//#include <string>
//using namespace std;
//
//int sum(int n){
//	int sum = 0;
//	while(n>0){
//		sum+=n%10;
//		if(n%10==0){
//			n = n-10;
//		}
//		else{
//			n = n/10; 
//		}
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
//	cin>>n>>k;
//	int time =0;
//	for(int i=1;i<n+1;i++){
//		if(sum(i)==k){
//			int u=0;
//			for(int j=2;j<i;j++){
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
//	cout<<o<<endl;
//	return 0;
//}
//



//3
//int main(){
//	string str;
//	getline(cin,str);
//	int index = 0;
//	if( !str.empty())
//	{
//	 while( (index = str.find(' ',index)) != string::npos)
//	{
// 	str.erase(index,1);
//	}
//}
//
//	for(int i=0;i<str.length()-1;i++){
//		cout<<str[i]<<" ";
//	}
//	cout<<str[str.length()-1];
//	
//	return 0;
//} 





//2
//int main(){
//	long long n,m,a;
//	cin>>n;
//	long long sum[n]={0};
//	for(int i=0;i<n;i++){
//		cin>>m;
//		for(int j=0;j<m;j++){
//			cin>>a;
//			sum[i]+=a;
//		}
//	}
//	
//	for(int i=0;i<n-1;i++){
//		cout<<sum[i]<<"\n"<<endl;
//	}
//	cout<<sum[n-1]<<endl;
//}
