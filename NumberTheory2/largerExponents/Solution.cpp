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
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	long long int a,b;
	int m;
	cin>>a>>b>>m;
	cout<<largePower(a,b,m)<<"\n";
	return 0;
}