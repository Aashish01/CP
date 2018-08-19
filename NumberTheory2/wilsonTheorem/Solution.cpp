#include <iostream>
using namespace std;
long long int largePower(long long int a, long long int b, int m){
	if(b==0){
		return 1;
	}
	if(b%2==0){
		return largePower((a*a)%m,b/2,m);
	}
	return (a%m)*largePower((a*a)%m,b/2,m)%m;
}
long long int fermit(int a, int m){
	return largePower(a,m-2,m);
}
long long int wilson(int n,int p){
	if(n>=p){
		return 0;
	}
	long long int ans=-1;
	for(int i=n+1;i<=p-1;i++){
		ans= ((ans%p)*(fermit(i,p)%p))%p;
	}
	ans=ans+p;
	return ans;
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int n,p;
	cin>>n>>p;
	cout<<wilson(n,p)<<endl;
	return 0;
}