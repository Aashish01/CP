#include <iostream>
#include <math.h>
using namespace std;
long long int gcd(long long int a,long long int b){
	if(a<b){
		return gcd(b,a);
	}
if(b==0){
	return a;
}
return gcd(b, a%b);
}
int main(){
ios_base:: sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
for(int l=0;l<t;l++){
	int a;
	cin>>a;
	string str;
cin>>str;
  if(a!=0){ //since divide or modulo by 0 gives segmentation fault.
    long long int num=0;
int m= a;
for(int i=0;i<str.length();i++){
	char ch= str.at(i);
	int j=(int)ch -48;
	num =(((num%m )* (10%m))%m + j%m )%m;
}
cout<<gcd(a,num%a)<<"\n";
}else{
        long long int num=0;
int m= pow(10,9)+7;
for(int i=0;i<str.length();i++){
	char ch= str.at(i);
	int j=(int)ch -48;
	num =(((num%m )* (10%m))%m + j%m )%m;
}
cout<<num<<"\n";
  }
}  
return 0;
}

