#include <iostream>
#include <math.h>
using namespace std;
int gcd(int a,long long b){
if(a<b){
	return gcd(b,a);
}
if(b==0){
	return a;
}
return gcd(b,a%b);
}
void func(long long n){
	long long int ans=n;
	long long int sum=0;
	for(int i=1;i<=n;i++){
		long long int d= i/gcd(i,n);
		sum= sum+d;

	}
	ans= ans*sum;
	cout<<ans<<"\n";
	return;
}

int main(){
	long long n;
	cin>>n;
	func(n);
	return 0;
}